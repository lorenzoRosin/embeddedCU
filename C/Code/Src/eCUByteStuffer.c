/**
 * @file eCUByteStuffer.c
 *
 */

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteStuffer.h"



/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t isBSStatusStillCoherent(const e_eCU_BStuffCtx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_Res bStuffer_initCtx(e_eCU_BStuffCtx* const ctx, uint8_t* const memArea, const uint32_t memAreaSize)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == memArea ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
        /* Check data validity */
        if( memAreaSize <= 0u )
        {
            result = ECU_RES_BADPARAM;
        }
        else
        {
            /* Initialize internal status */
            ctx->isInit = true;
            ctx->memArea = memArea;
            ctx->memAreaSize = memAreaSize;
            ctx->memAreaCntr = 0u;
            ctx->precedentToCheck = false;
            ctx->needSof = true;
            ctx->needEof = true;
            result = ECU_RES_OK;
        }
	}

	return result;
}

e_eCU_Res bStuffer_reset(e_eCU_BStuffCtx* const ctx)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
			/* Update index */
			ctx->memAreaCntr = 0u;
            ctx->precedentToCheck = false;
            ctx->needSof = true;
            ctx->needEof = true;
			result = ECU_RES_OK;
		}
	}

	return result;
}

e_eCU_Res bStuffer_getDataSize(e_eCU_BStuffCtx* const ctx, uint32_t* const retrivedLen)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == retrivedLen ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBSStatusStillCoherent(ctx) )
            {
                result = ECU_RES_BADPARAM;
            }
            else
            {
                if( false == ctx->precedentToCheck )
                {
                    *retrivedLen = ctx->memAreaSize - ctx->memAreaCntr;
                }
                else
                {
                    *retrivedLen = ctx->memAreaSize - ctx->memAreaCntr + 1u;
                }

                result = ECU_RES_OK;
            }
		}
	}

	return result;
}

e_eCU_Res bStuffer_retiveElabData(e_eCU_BStuffCtx* const ctx, uint8_t* const stuffedDest, const uint32_t maxDestLen,
                                  uint32_t* const filledLen)
{
	/* Local variable */
	e_eCU_Res result;
    uint32_t nExamByte;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == stuffedDest ) || ( NULL == filledLen ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
            if(maxDestLen <= 0u)
            {
                result = ECU_RES_BADPARAM;
            }
            else
            {
                /* Check internal status validity */
                if( false == isBSStatusStillCoherent(ctx) )
                {
                    result = ECU_RES_BADPARAM;
                }
                else
                {
                    /* Init counter */
                    nExamByte = 0u;

                    /* Check for and old elabData leftover */
                    if( true == ctx->precedentToCheck )
                    {
                        /* Before continuing we need to parse the old data */
                        stuffedDest[nExamByte] = ~( ctx->memArea[ctx->memAreaCntr - 1u] );
                        ctx->precedentToCheck = false;
                        nExamByte++;
                    }

                    /* Execute parsing cycle */
                    while( ( nExamByte < maxDestLen ) && ( ctx->memAreaCntr < ctx->memAreaSize ) )
                    {
                        /* Check for and old elabData leftover */
                        if( true == ctx->precedentToCheck )
                        {
                            /* Before continuing we need to parse the old data */
                            stuffedDest[nExamByte] = ~( ctx->memArea[ctx->memAreaCntr - 1u] );
                            ctx->precedentToCheck = false;
                        }
                        else
                        {
                            if( 0 == ctx->memAreaCntr )
                            {
                                /* First frame */
                                stuffedDest[nExamByte] = ECU_SOF;
                            }
                            else if( ctx->memAreaCntr == ctx->memAreaCntr )
                            {
                                /* End of frame */
                                stuffedDest[nExamByte] = ECU_EOF;
                            }
                            else
                            {
                                if( ECU_SOF == ctx->memArea[ctx->memAreaCntr] )
                                {
                                    stuffedDest[nExamByte] = ECU_NSOF;
                                    ctx->precedentToCheck = true;
                                }
                                else if( ECU_EOF == ctx->memArea[ctx->memAreaCntr] )
                                {
                                    stuffedDest[nExamByte] = ECU_NEOF;
                                    ctx->precedentToCheck = true;
                                }
                                else if( ECU_ESC == ctx->memArea[ctx->memAreaCntr] )
                                {
                                    stuffedDest[nExamByte] = ECU_NESC;
                                    ctx->precedentToCheck = true;
                                }
                                else
                                {
                                    stuffedDest[nExamByte] = ctx->memArea[ctx->memAreaCntr];
                                }
                            }
                        }

                        /* Increment counter */
                        nExamByte++;
                    }

                    /* Save counter */
                    *filledLen = nExamByte;

                    /* result? */
                    if( 0u == nExamByte )
                    {
                        /* Nothing more */
                        result = ECU_RES_OUTOFMEM;
                    }
                    else
                    {
                        result = ECU_RES_OK;
                    }
                }
            }
		}
	}

	return result;
}

/***********************************************************************************************************************
 *  PRIVATE FUNCTION
 **********************************************************************************************************************/
bool_t isBSStatusStillCoherent(const e_eCU_BStuffCtx* ctx)
{
    bool_t result;
    uint8_t precedentByte;

	/* Check context validity */
	if( ( ctx->memAreaSize <= 0u ) || ( NULL == ctx->memArea ) || ( ctx->memAreaCntr > ctx->memAreaSize ) )
	{
		result = false;
	}
	else
	{
		/* Check data coherence */
		if( ( ( true == ctx->needSof ) && ( false == ctx->needEof ) ) ||
            ( ( false == ctx->needSof ) && ( false == ctx->needEof ) && ( ctx->memAreaCntr != ctx->memAreaSize ) ) ||
            ( ( true == ctx->needSof ) && ( true == ctx->precedentToCheck ) ) ||
            ( ( false == ctx->needEof ) && ( true == ctx->precedentToCheck ) ) )
		{
            result = false;
		}
		else
		{
            if( ( 0u == ctx->memAreaCntr ) && ( true == ctx->precedentToCheck ) )
            {
                result = false;
            }
            else
            {
                if( true == ctx->precedentToCheck )
                {
                    precedentByte = ctx->memArea[ctx->memAreaCntr - 1u];
                    if( (ECU_ESC != precedentByte) && (ECU_EOF != precedentByte) && (ECU_SOF != precedentByte) )
                    {
                        result = false;
                    }
                    else
                    {
                        result = true;
                    }
                }
                else
                {
                    result = true;
                }
            }
		}
	}

    return result;
}

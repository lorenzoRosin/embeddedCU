/**
 * @file eCUByteUnStuffer.c
 *
 */

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteUnStuffer.h"
#include "eCUByteStuffer.h"


/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t isBUSStatusStillCoherent(const e_eCU_BUStuffCtx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_Res bUStufferInitCtx(e_eCU_BUStuffCtx* const ctx, uint8_t* const memArea, const uint32_t memAreaSize)
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
            ctx->precedentWasEsc = false;
            ctx->needSof = true;
            ctx->needEof = true;
            result = ECU_RES_OK;
        }
	}

	return result;
}

e_eCU_Res bUStufferReset(e_eCU_BUStuffCtx* const ctx)
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
            ctx->precedentWasEsc = false;
            ctx->needSof = true;
            ctx->needEof = true;
			result = ECU_RES_OK;
		}
	}

	return result;
}

e_eCU_Res bUStufferGetNUnstuf(e_eCU_BUStuffCtx* const ctx, uint32_t* const retrivedLen)
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
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = ECU_RES_BADPARAM;
            }
            else
            {
                *retrivedLen =  ctx->memAreaCntr;
                result = ECU_RES_OK;
            }
		}
	}

	return result;
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-17.4_b"
    /* Suppressed for code clarity */
#endif

e_eCU_Res bUStufferInsStufChunk(e_eCU_BUStuffCtx* const ctx, uint8_t* const stuffedArea, const uint32_t stuffLen,
                                  uint32_t* const consumedStuffData, bool_t* anotherSofRec, bool_t* eofRec)
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
                if( false == isBUSStatusStillCoherent(ctx) )
                {
                    result = ECU_RES_BADPARAM;
                }
                else
                {
                    /* Init counter */
                    nExamByte = 0u;

                    /* Detect start of frame here to maximize efficency */
                    if( true == ctx->needSof )
                    {
                        /* Start of frame */
                        stuffedDest[nExamByte] = ECU_SOF;
                        nExamByte++;
                        ctx->needSof = false;
                    }

                    /* Execute parsing cycle */
                    while( ( nExamByte < maxDestLen ) && ( true == ctx->needEof ) )
                    {
                        if( true == ctx->precedentWasEsc )
                        {
                            /* Something from an old iteration  */
                            stuffedDest[nExamByte] = ~( ctx->memArea[ctx->memAreaCntr - 1u] );
                            ctx->precedentWasEsc = false;
                            nExamByte++;
                        }
                        else if( ctx->memAreaCntr == ctx->memAreaSize )
                        {
                            /* End of frame */
                            stuffedDest[nExamByte] = ECU_EOF;
                            ctx->needEof = false;
                            nExamByte++;
                        }
                        else
                        {
                            /* Current iteration */
                            if( ECU_SOF == ctx->memArea[ctx->memAreaCntr] )
                            {
                                /* Stuff with escape */
                                stuffedDest[nExamByte] = ECU_ESC;
                                ctx->precedentWasEsc = true;
                                nExamByte++;
                                ctx->memAreaCntr++;
                            }
                            else if( ECU_EOF == ctx->memArea[ctx->memAreaCntr] )
                            {
                                /* Stuff with escape */
                                stuffedDest[nExamByte] = ECU_ESC;
                                ctx->precedentWasEsc = true;
                                nExamByte++;
                                ctx->memAreaCntr++;
                            }
                            else if( ECU_ESC == ctx->memArea[ctx->memAreaCntr] )
                            {
                                /* Stuff with escape */
                                stuffedDest[nExamByte] = ECU_ESC;
                                ctx->precedentWasEsc = true;
                                nExamByte++;
                                ctx->memAreaCntr++;
                            }
                            else
                            {
                                /* Can insert data */
                                stuffedDest[nExamByte] = ctx->memArea[ctx->memAreaCntr];
                                nExamByte++;
                                ctx->memAreaCntr++;
                            }
                        }
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
bool_t isBUSStatusStillCoherent(const e_eCU_BUStuffCtx* ctx)
{
    bool_t result;

	/* Check context validity */
	if( ( ctx->memAreaSize <= 0u ) || ( NULL == ctx->memArea ) || ( ctx->memAreaCntr > ctx->memAreaSize ) )
	{
		result = false;
	}
	else
	{
		/* Check data coherence */
		if( ( ( true == ctx->needSof ) && ( false == ctx->needEof ) ) ||
            ( ( true == ctx->needSof ) && ( true == ctx->precedentWasEsc ) ) ||
            ( ( false == ctx->needEof ) && ( true == ctx->precedentWasEsc ) ) )
		{
            result = false;
		}
		else
		{
            if( ( true == ctx->needSof ) && ( 0u != ctx->memAreaCntr ) )
            {
                result = false;
            }
            else
            {
                result = true;
            }
		}
	}

    return result;
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-17.4_b"
#endif


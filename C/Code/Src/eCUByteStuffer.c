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
e_eCU_dBStf_Res bStufferInitCtx(e_eCU_BStuffCtx* const ctx, uint8_t* const memArea, const uint32_t memAreaSize)
{
	/* Local variable */
	e_eCU_dBStf_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == memArea ) )
	{
		result = DBSTF_RES_BADPOINTER;
	}
	else
	{
        /* Check data validity */
        if( memAreaSize <= 0u )
        {
            result = DBSTF_RES_BADPARAM;
        }
        else
        {
            /* Initialize internal status */
            ctx->isInit = true;
            ctx->memArea = memArea;
            ctx->memAreaSize = memAreaSize;
            ctx->memAreaFrameSize = 0u;
            ctx->memAreaCntr = 0u;
            ctx->precedentToCheck = false;
            ctx->needSof = true;
            ctx->needEof = true;
            result = DBSTF_RES_OK;
        }
	}

	return result;
}

e_eCU_dBStf_Res bStufferStartNewFrame(e_eCU_BStuffCtx* const ctx, const uint32_t frameLen)
{
	/* Local variable */
	e_eCU_dBStf_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = DBSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBSStatusStillCoherent(ctx) )
            {
                result = DBSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Check internal status validity */
                if( ( frameLen <= 0u ) || ( frameLen > ctx->memAreaSize ) )
                {
                    result = DBSTF_RES_BADPARAM;
                }
                else
                {
                    /* Update index */
                    ctx->memAreaFrameSize = frameLen;

                    result = bStufferRestartCurrentFrame(ctx);
                }
            }
		}
	}

	return result;
}

e_eCU_dBStf_Res bStufferRestartCurrentFrame(e_eCU_BStuffCtx* const ctx)
{
	/* Local variable */
	e_eCU_dBStf_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = DBSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check Init */
            if( 0u == ctx->memAreaFrameSize )
            {
                result = DBSTF_RES_NOINITFRAME;
            }
            else
            {
                /* Check internal status validity */
                if( false == isBSStatusStillCoherent(ctx) )
                {
                    result = DBSTF_RES_CORRUPTCTX;
                }
                else
                {
                    /* Update index */
                    ctx->memAreaCntr = 0u;
                    ctx->precedentToCheck = false;
                    ctx->needSof = true;
                    ctx->needEof = true;
                    result = DBSTF_RES_OK;
                }
            }
		}
	}

	return result;
}

e_eCU_dBStf_Res bStufferGetUnStufDataLocation(e_eCU_BStuffCtx* const ctx, uint8_t** dataP)
{
	/* Local variable */
	e_eCU_dBStf_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataP ) )
	{
		result = DBSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBSStatusStillCoherent(ctx) )
            {
                result = DBSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Update index */
                *dataP = ctx->memArea;
                result = DBSTF_RES_OK;
            }
		}
	}

	return result;
}

e_eCU_dBStf_Res bStufferGetRemToRetrive(e_eCU_BStuffCtx* const ctx, uint32_t* const retrivedLen)
{
	/* Local variable */
	e_eCU_dBStf_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == retrivedLen ) )
	{
		result = DBSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check Init */
            if( 0u == ctx->memAreaFrameSize )
            {
                result = DBSTF_RES_NOINITFRAME;
            }
            else
            {
                /* Check internal status validity */
                if( false == isBSStatusStillCoherent(ctx) )
                {
                    result = DBSTF_RES_CORRUPTCTX;
                }
                else
                {
                    *retrivedLen = 0u;

                    if( true == ctx->needSof )
                    {
                        *retrivedLen = *retrivedLen + 1u;
                    }

                    if( true == ctx->needEof )
                    {
                        *retrivedLen = *retrivedLen + 1u;
                    }

                    if( true == ctx->precedentToCheck )
                    {
                        *retrivedLen = *retrivedLen + 1u;
                    }

                    for( uint32_t indx = ctx->memAreaCntr; indx < ctx->memAreaFrameSize; indx++ )
                    {
                        if( ECU_SOF == ctx->memArea[indx] )
                        {
                            /* Stuff with escape */
                            *retrivedLen = *retrivedLen + 2u;
                        }
                        else if( ECU_EOF == ctx->memArea[indx] )
                        {
                            /* Stuff with escape */
                            *retrivedLen = *retrivedLen + 2u;
                        }
                        else if( ECU_ESC == ctx->memArea[indx] )
                        {
                            /* Stuff with escape */
                            *retrivedLen = *retrivedLen + 2u;
                        }
                        else
                        {
                            *retrivedLen = *retrivedLen + 1u;
                        }
                    }

                    result = DBSTF_RES_OK;
                }
            }
		}
	}

	return result;
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-17.4_b"
    /* Suppressed for code clarity */
#endif

e_eCU_dBStf_Res bStufferRetriStufChunk(e_eCU_BStuffCtx* const ctx, uint8_t* const stuffedDest,
									   const uint32_t maxDestLen, uint32_t* const filledLen)
{
	/* Local variable */
	e_eCU_dBStf_Res result;
    uint32_t nExamByte;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == stuffedDest ) || ( NULL == filledLen ) )
	{
		result = DBSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check Init */
            if( 0u == ctx->memAreaFrameSize )
            {
                result = DBSTF_RES_NOINITFRAME;
            }
            else
            {
                if(maxDestLen <= 0u)
                {
                    result = DBSTF_RES_BADPARAM;
                }
                else
                {
                    /* Check internal status validity */
                    if( false == isBSStatusStillCoherent(ctx) )
                    {
                        result = DBSTF_RES_CORRUPTCTX;
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
                            if( true == ctx->precedentToCheck )
                            {
                                /* Something from an old iteration  */
                                stuffedDest[nExamByte] = ( (uint8_t) ~( ctx->memArea[ctx->memAreaCntr - 1u] ) );
                                ctx->precedentToCheck = false;
                                nExamByte++;
                            }
                            else if( ctx->memAreaCntr == ctx->memAreaFrameSize )
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
                                    ctx->precedentToCheck = true;
                                    nExamByte++;
                                    ctx->memAreaCntr++;
                                }
                                else if( ECU_EOF == ctx->memArea[ctx->memAreaCntr] )
                                {
                                    /* Stuff with escape */
                                    stuffedDest[nExamByte] = ECU_ESC;
                                    ctx->precedentToCheck = true;
                                    nExamByte++;
                                    ctx->memAreaCntr++;
                                }
                                else if( ECU_ESC == ctx->memArea[ctx->memAreaCntr] )
                                {
                                    /* Stuff with escape */
                                    stuffedDest[nExamByte] = ECU_ESC;
                                    ctx->precedentToCheck = true;
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
                        if( false == ctx->needEof )
                        {
                            /* Nothing more */
                            result = DBSTF_RES_FRAMEENDED;
                        }
                        else
                        {
                            result = DBSTF_RES_OK;
                        }
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
	if( ( ctx->memAreaSize <= 0u ) || ( NULL == ctx->memArea ) || ( ctx->memAreaCntr > ctx->memAreaFrameSize ) ||
        ( ctx->memAreaFrameSize > ctx->memAreaSize ) )
	{
		result = false;
	}
	else
	{
		/* Check data coherence */
		if( ( ( true == ctx->needSof ) && ( false == ctx->needEof ) ) ||
            ( ( false == ctx->needSof ) && ( false == ctx->needEof ) && ( ctx->memAreaCntr != ctx->memAreaFrameSize )
            ) ||
            ( ( true == ctx->needSof ) && ( true == ctx->precedentToCheck ) ) ||
            ( ( false == ctx->needEof ) && ( true == ctx->precedentToCheck ) ) ||
            ( ( true == ctx->needSof ) && ( 0u != ctx->memAreaCntr ) ) )
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

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-17.4_b"
#endif


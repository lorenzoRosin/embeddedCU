/**
 * @file       eCUByteStuffer.c
 *
 * @brief      Byte stuffer utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteStuffer.h"



/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t isBSStatusStillCoherent(const s_eCU_BStuffCtx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_dBStf_Res bStufferInitCtx(s_eCU_BStuffCtx* const ctx, uint8_t* const memArea, const uint32_t memAreaSize)
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
            ctx->stuffState = DBSTF_ST_PRV_NEEDSOF;

            result = DBSTF_RES_OK;
        }
	}

	return result;
}

e_eCU_dBStf_Res bStufferStartNewFrame(s_eCU_BStuffCtx* const ctx, const uint32_t frameLen)
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
                /* Check param validity */
                if( ( frameLen <= 0u ) || ( frameLen > ctx->memAreaSize ) )
                {
                    result = DBSTF_RES_BADPARAM;
                }
                else
                {
                    /* Update data */
                    ctx->memAreaFrameSize = frameLen;
                    ctx->memAreaCntr = 0u;
                    ctx->stuffState = DBSTF_ST_PRV_NEEDSOF;

                    result = DBSTF_RES_OK;
                }
            }
		}
	}

	return result;
}

e_eCU_dBStf_Res bStufferGetUnStufDataLocation(s_eCU_BStuffCtx* const ctx, uint8_t** dataP, uint32_t* const maxDataSize)
{
	/* Local variable */
	e_eCU_dBStf_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataP ) || ( NULL == maxDataSize ) )
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
                /* return data */
                *dataP = ctx->memArea;
                *maxDataSize = ctx->memAreaSize;
                result = DBSTF_RES_OK;
            }
		}
	}

	return result;
}

e_eCU_dBStf_Res bStufferRestartCurrentFrame(s_eCU_BStuffCtx* const ctx)
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
                    ctx->stuffState = DBSTF_ST_PRV_NEEDSOF;

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

e_eCU_dBStf_Res bStufferGetRemToRetrive(s_eCU_BStuffCtx* const ctx, uint32_t* const retrivedLen)
{
	/* Local variable */
	e_eCU_dBStf_Res result;
    uint32_t calLen;

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
                    /* Analyze the current state of the state machine */
                    if( DBSTF_ST_PRV_NEEDSOF == ctx->stuffState )
                    {
                        calLen = 2u;
                    }
                    else if( DBSTF_ST_PRV_NEEDEOF == ctx->stuffState )
                    {
                        calLen = 1u;
                    }
                    else if( DBSTF_ST_PRV_NEEDNEGATEPRECDATA == ctx->stuffState )
                    {
                        /* If a precedent byte of the payload was an SOF, EOF or ESC character, this means that the
                        * ESC char is already inserted in the unstuffed data, but that we need to add the negation of
                        * the payload */
                        calLen = 1u;
                    }
                    else
                    {
                        calLen = 0u;
                    }

                    /* Calculate the remaining byte from the current counter of course */
                    for( uint32_t indx = ctx->memAreaCntr; indx < ctx->memAreaFrameSize; indx++ )
                    {
                        if( ECU_SOF == ctx->memArea[indx] )
                        {
                            /* Stuff with escape */
                            calLen = calLen + 2u;
                        }
                        else if( ECU_EOF == ctx->memArea[indx] )
                        {
                            /* Stuff with escape */
                            calLen = calLen + 2u;
                        }
                        else if( ECU_ESC == ctx->memArea[indx] )
                        {
                            /* Stuff with escape */
                            calLen = calLen + 2u;
                        }
                        else
                        {
                            calLen = calLen + 1u;
                        }
                    }

                    /* Copy calc value */
                    *retrivedLen = calLen;

                    result = DBSTF_RES_OK;
                }
            }
		}
	}

	return result;
}

e_eCU_dBStf_Res bStufferRetriStufChunk(s_eCU_BStuffCtx* const ctx, uint8_t* const stuffedDest,
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

                        /* Execute parsing cycle */
                        while( ( nExamByte < maxDestLen ) && ( DBSTF_ST_PRV_STUFFEND != ctx->stuffState ) )
                        {
                            if( DBSTF_ST_PRV_NEEDRAWDATA == ctx->stuffState )
                            {
                                /* Parse data from the frame now */
                                if( ECU_SOF == ctx->memArea[ctx->memAreaCntr] )
                                {
                                    /* Stuff with escape */
                                    stuffedDest[nExamByte] = ECU_ESC;
                                    ctx->stuffState = DBSTF_ST_PRV_NEEDNEGATEPRECDATA;
                                    nExamByte++;
                                    ctx->memAreaCntr++;
                                }
                                else if( ECU_EOF == ctx->memArea[ctx->memAreaCntr] )
                                {
                                    /* Stuff with escape */
                                    stuffedDest[nExamByte] = ECU_ESC;
                                    ctx->stuffState = DBSTF_ST_PRV_NEEDNEGATEPRECDATA;
                                    nExamByte++;
                                    ctx->memAreaCntr++;
                                }
                                else if( ECU_ESC == ctx->memArea[ctx->memAreaCntr] )
                                {
                                    /* Stuff with escape */
                                    stuffedDest[nExamByte] = ECU_ESC;
                                    ctx->stuffState = DBSTF_ST_PRV_NEEDNEGATEPRECDATA;
                                    nExamByte++;
                                    ctx->memAreaCntr++;
                                }
                                else
                                {
                                    /* Can insert data */
                                    stuffedDest[nExamByte] = ctx->memArea[ctx->memAreaCntr];
                                    nExamByte++;
                                    ctx->memAreaCntr++;

                                    if( ctx->memAreaCntr == ctx->memAreaFrameSize )
                                    {
                                        /* End of frame needed */
                                        ctx->stuffState = DBSTF_ST_PRV_NEEDEOF;
                                    }
                                }
                            }
                            else if( DBSTF_ST_PRV_NEEDNEGATEPRECDATA == ctx->stuffState )
                            {
                                /* Something from an old iteration  */
                                stuffedDest[nExamByte] = ( (uint8_t) ~( ctx->memArea[ctx->memAreaCntr - 1u] ) );
                                nExamByte++;

                                if( ctx->memAreaCntr == ctx->memAreaFrameSize )
                                {
                                    /* End of frame needed */
                                    ctx->stuffState = DBSTF_ST_PRV_NEEDEOF;
                                }
                                else
                                {
                                    ctx->stuffState = DBSTF_ST_PRV_NEEDRAWDATA;
                                }
                            }
                            else if( DBSTF_ST_PRV_NEEDEOF == ctx->stuffState )
                            {
                                /* End of frame */
                                stuffedDest[nExamByte] = ECU_EOF;
                                ctx->stuffState = DBSTF_ST_PRV_STUFFEND;
                                nExamByte++;
                            }
                            else if( DBSTF_ST_PRV_NEEDSOF == ctx->stuffState )
                            {
                                /* Start of frame */
                                stuffedDest[nExamByte] = ECU_SOF;
                                nExamByte++;
                                ctx->stuffState = DBSTF_ST_PRV_NEEDRAWDATA;
                            }
                        }

                        /* Save counter */
                        *filledLen = nExamByte;

                        /* result? */
                        if( DBSTF_ST_PRV_STUFFEND == ctx->stuffState )
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
bool_t isBSStatusStillCoherent(const s_eCU_BStuffCtx* ctx)
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
		if( ( ( DBSTF_ST_PRV_STUFFEND == ctx->stuffState ) && ( ctx->memAreaCntr != ctx->memAreaFrameSize ) ) ||
            ( ( DBSTF_ST_PRV_NEEDSOF  == ctx->stuffState ) && ( 0u != ctx->memAreaCntr ) ) )
		{
            result = false;
		}
		else
		{
            if( DBSTF_ST_PRV_NEEDNEGATEPRECDATA == ctx->stuffState )
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

    return result;
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-17.4_b"
#endif


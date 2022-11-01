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
e_eCU_dBStf_Res bStufferInitCtx(s_eCU_BStuffCtx* const ctx, uint8_t memArea[], const uint32_t memAreaSize)
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
            ctx->stuffState = DBSTF_SM_PRV_NEEDSOF;

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
                    ctx->stuffState = DBSTF_SM_PRV_NEEDSOF;

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
            if( ctx->memAreaFrameSize <= 0u )
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
                    ctx->stuffState = DBSTF_SM_PRV_NEEDSOF;

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
	uint32_t indx;

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
            if( 0u >= ctx->memAreaFrameSize )
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
                    if( DBSTF_SM_PRV_NEEDSOF == ctx->stuffState )
                    {
                        /* SOF + Data + EOF */
                        calLen = 2u;
                    }
                    else if( DBSTF_SM_PRV_NEEDEOF == ctx->stuffState )
                    {
                        /* EOF */
                        calLen = 1u;
                    }
                    else if( DBSTF_SM_PRV_NEEDNEGATEPRECDATA == ctx->stuffState )
                    {
                        /* If a precedent byte of the payload was an SOF, EOF or ESC character, this means that the
                        * ESC char is already inserted in the unstuffed data, but that we need to add the negation of
                        * the payload + the EOF */
                        calLen = 2u;
                    }
                    else if( DBSTF_SM_PRV_STUFFEND == ctx->stuffState )
                    {
                        /* Stuffend ended, no data to wait */
                        calLen = 0u;
                    }
                    else
                    {
                        /* data + EOF */
                        calLen = 1u;
                    }

                    /* Calculate the remaining byte from the current counter of course */
					indx = ctx->memAreaCntr;
                    while( ( indx < ctx->memAreaFrameSize) && (calLen < 0xFFFFFFFFu) )
                    {
                        if( ECU_SOF == ctx->memArea[indx] )
                        {
							/* Try to avoid overflow. Resonable limit for HW */
							if( calLen <= 0xFFFFFFFDu )
							{
								/* Stuff with escape */
								calLen = calLen + 2u;
							}
							else
							{
								calLen = 0xFFFFFFFFu;
							}
                        }
                        else if( ECU_EOF == ctx->memArea[indx] )
                        {
							/* Try to avoid overflow. Resonable limit for HW */
							if( calLen <= 0xFFFFFFFDu )
							{
								/* Stuff with escape */
								calLen = calLen + 2u;
							}
							else
							{
								calLen = 0xFFFFFFFFu;
							}
                        }
                        else if( ECU_ESC == ctx->memArea[indx] )
                        {
							/* Try to avoid overflow. Resonable limit for HW */
							if( calLen <= 0xFFFFFFFDu )
							{
								/* Stuff with escape */
								calLen = calLen + 2u;
							}
							else
							{
								calLen = 0xFFFFFFFFu;
							}
                        }
                        else
                        {
                            calLen = calLen + 1u;
                        }

						indx++;
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

e_eCU_dBStf_Res bStufferRetriStufChunk(s_eCU_BStuffCtx* const ctx, uint8_t stuffedDest[], const uint32_t maxDestLen,
                                       uint32_t* const filledLen)
{
	/* Local variable */
	e_eCU_dBStf_Res result;
    uint32_t nFillByte;

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
            if( 0u >= ctx->memAreaFrameSize )
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
                        nFillByte = 0u;
						result = DBSTF_RES_OK;

                        /* Execute parsing cycle */
                        while( ( nFillByte < maxDestLen ) &&
						       ( DBSTF_SM_PRV_STUFFEND != ctx->stuffState ) &&
							   ( DBSTF_RES_OK == result ) )
                        {
                            switch( ctx->stuffState )
                            {
                                case DBSTF_SM_PRV_NEEDRAWDATA :
                                {
                                    /* Parse data from the frame now */
                                    if( ECU_SOF == ctx->memArea[ctx->memAreaCntr] )
                                    {
                                        /* Stuff with escape */
                                        stuffedDest[nFillByte] = ECU_ESC;
                                        ctx->stuffState = DBSTF_SM_PRV_NEEDNEGATEPRECDATA;
                                        nFillByte++;
                                        ctx->memAreaCntr++;
                                    }
                                    else if( ECU_EOF == ctx->memArea[ctx->memAreaCntr] )
                                    {
                                        /* Stuff with escape */
                                        stuffedDest[nFillByte] = ECU_ESC;
                                        ctx->stuffState = DBSTF_SM_PRV_NEEDNEGATEPRECDATA;
                                        nFillByte++;
                                        ctx->memAreaCntr++;
                                    }
                                    else if( ECU_ESC == ctx->memArea[ctx->memAreaCntr] )
                                    {
                                        /* Stuff with escape */
                                        stuffedDest[nFillByte] = ECU_ESC;
                                        ctx->stuffState = DBSTF_SM_PRV_NEEDNEGATEPRECDATA;
                                        nFillByte++;
                                        ctx->memAreaCntr++;
                                    }
                                    else
                                    {
                                        /* Can insert data */
                                        stuffedDest[nFillByte] = ctx->memArea[ctx->memAreaCntr];
                                        nFillByte++;
                                        ctx->memAreaCntr++;

                                        if( ctx->memAreaCntr >= ctx->memAreaFrameSize )
                                        {
                                            /* End of frame needed */
                                            ctx->stuffState = DBSTF_SM_PRV_NEEDEOF;
                                        }
                                    }

                                    break;
                                }

                                case DBSTF_SM_PRV_NEEDNEGATEPRECDATA :
                                {
                                    /* Something from an old iteration  */
                                    stuffedDest[nFillByte] = ( (uint8_t) ~( ctx->memArea[ctx->memAreaCntr - 1u] ) );
                                    nFillByte++;

                                    if( ctx->memAreaCntr >= ctx->memAreaFrameSize )
                                    {
                                        /* End of frame needed */
                                        ctx->stuffState = DBSTF_SM_PRV_NEEDEOF;
                                    }
                                    else
                                    {
                                        ctx->stuffState = DBSTF_SM_PRV_NEEDRAWDATA;
                                    }

                                    break;
                                }

                                case DBSTF_SM_PRV_NEEDEOF :
                                {
                                    /* End of frame */
                                    stuffedDest[nFillByte] = ECU_EOF;
                                    ctx->stuffState = DBSTF_SM_PRV_STUFFEND;
                                    nFillByte++;

                                    break;
                                }

                                case DBSTF_SM_PRV_NEEDSOF :
                                {
                                    /* Start of frame */
                                    stuffedDest[nFillByte] = ECU_SOF;
                                    nFillByte++;
                                    ctx->stuffState = DBSTF_SM_PRV_NEEDRAWDATA;

                                    break;
                                }

                               default:
                               {
                                   /* Impossible end here, and if so something horrible happened */
									result = DBSTF_RES_CORRUPTCTX;
                                   break;
                               }
                            }
                        }

						if( DBSTF_RES_OK == result )
						{
							/* Save counter */
							*filledLen = nFillByte;

							/* result? */
							if( DBSTF_SM_PRV_STUFFEND == ctx->stuffState )
							{
								/* Nothing more */
								result = DBSTF_RES_FRAMEENDED;
							}
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
    uint8_t preceByte;

	/* Check basic context validity */
	if( ( ctx->memAreaSize <= 0u ) || ( NULL == ctx->memArea ) )
	{
		result = false;
	}
	else
	{
        /* Check context limit validity */
        if( ( ctx->memAreaFrameSize > ctx->memAreaSize ) || ( ctx->memAreaCntr > ctx->memAreaFrameSize ) )
        {
            result = false;
        }
        else
        {
            /* Check data coherence on SOF */
            if( ( DBSTF_SM_PRV_NEEDSOF  == ctx->stuffState ) && ( 0u != ctx->memAreaCntr ) )
            {
                result = false;
            }
            else
            {
                /* Check data coherence on SOF */
                if( ( 0u == ctx->memAreaCntr ) && ( DBSTF_SM_PRV_NEEDSOF != ctx->stuffState ) &&
                    ( DBSTF_SM_PRV_NEEDRAWDATA != ctx->stuffState ) )
                {
                    result = false;
                }
                else
                {
                    /* Check data coherence on EOF */
                    if( ( DBSTF_SM_PRV_STUFFEND == ctx->stuffState ) && ( ctx->memAreaCntr != ctx->memAreaFrameSize ) )
                    {
                        result = false;
                    }
                    else
                    {
                        /* Check data coherence on precedent data */
                        if( DBSTF_SM_PRV_NEEDNEGATEPRECDATA == ctx->stuffState )
                        {
                            preceByte = ctx->memArea[ctx->memAreaCntr - 1u];
                            if( ( ECU_ESC != preceByte ) && ( ECU_EOF != preceByte ) && ( ECU_SOF != preceByte ) )
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
        }
	}

    return result;
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-17.4_b"
#endif
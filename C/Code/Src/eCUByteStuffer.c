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
static bool_t eCU_BSTF_isStatusStillCoherent(const s_eCU_BSTF_Ctx* p_ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_BSTF_Res eCU_BSTF_InitCtx(s_eCU_BSTF_Ctx* const p_ctx, uint8_t a_memArea[], const uint32_t memAreaSize)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == a_memArea ) )
	{
		l_result = BSTF_RES_BADPOINTER;
	}
	else
	{
        /* Check data validity */
        if( memAreaSize <= 0u )
        {
            l_result = BSTF_RES_BADPARAM;
        }
        else
        {
            /* Initialize internal status */
            p_ctx->isInit = true;
            p_ctx->p_memA = a_memArea;
            p_ctx->memASize = memAreaSize;
            p_ctx->memAFrameSize = 0u;
            p_ctx->memACtr = 0u;
            p_ctx->stuffState = BSTF_SM_PRV_NEEDSOF;

            l_result = BSTF_RES_OK;
        }
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_IsInit(s_eCU_BSTF_Ctx* const p_ctx, bool_t* p_isInit)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isInit ) )
	{
		l_result = BSTF_RES_BADPOINTER;
	}
	else
	{
        *p_isInit = p_ctx->isInit;
        l_result = BSTF_RES_OK;
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_NewFrame(s_eCU_BSTF_Ctx* const p_ctx, const uint32_t frameLen)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = BSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = BSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = BSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Check param validity */
                if( ( frameLen <= 0u ) || ( frameLen > p_ctx->memASize ) )
                {
                    l_result = BSTF_RES_BADPARAM;
                }
                else
                {
                    /* Update data */
                    p_ctx->memAFrameSize = frameLen;
                    p_ctx->memACtr = 0u;
                    p_ctx->stuffState = BSTF_SM_PRV_NEEDSOF;

                    l_result = BSTF_RES_OK;
                }
            }
		}
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_GetWherePutData(s_eCU_BSTF_Ctx* const p_ctx, uint8_t** pp_data, uint32_t* const p_maxDataSize)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == pp_data ) || ( NULL == p_maxDataSize ) )
	{
		l_result = BSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = BSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = BSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* return data */
                *pp_data = p_ctx->p_memA;
                *p_maxDataSize = p_ctx->memASize;
                l_result = BSTF_RES_OK;
            }
		}
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_RestartFrame(s_eCU_BSTF_Ctx* const p_ctx)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = BSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = BSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = BSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Param */
                if( p_ctx->memAFrameSize <= 0u )
                {
                    l_result = BSTF_RES_NOINITFRAME;
                }
                else
                {
                    /* Update index */
                    p_ctx->memACtr = 0u;
                    p_ctx->stuffState = BSTF_SM_PRV_NEEDSOF;

                    l_result = BSTF_RES_OK;
                }
            }
		}
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_GetRemByteToGet(s_eCU_BSTF_Ctx* const p_ctx, uint32_t* const p_retrivedLen)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;
    uint32_t l_calLen;
	uint32_t l_indx;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_retrivedLen ) )
	{
		l_result = BSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = BSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = BSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Check param */
                if( p_ctx->memAFrameSize <= 0u )
                {
                    l_result = BSTF_RES_NOINITFRAME;
                }
                else
                {
                    /* Analyze the current state of the state machine */
                    if( BSTF_SM_PRV_NEEDSOF == p_ctx->stuffState )
                    {
                        /* SOF + Data + EOF */
                        l_calLen = 2u;
                    }
                    else if( BSTF_SM_PRV_NEEDNEGATEPRECDATA == p_ctx->stuffState )
                    {
                        /* If a precedent byte of the payload was an SOF, EOF or ESC character, this means that the
                        * ESC char is already inserted in the unstuffed data, but that we need to add the negation of
                        * the payload + the EOF */
                        l_calLen = 2u;
                    }
                    else if( BSTF_SM_PRV_STUFFEND == p_ctx->stuffState )
                    {
                        /* Stuffend ended, no data to wait */
                        l_calLen = 0u;
                    }
                    else
                    {
                        /* data + EOF. With the current state machine is not possible to have a single call that
                         * leave the system in the state: BSTF_SM_PRV_NEEDEOF */
                        l_calLen = 1u;
                    }

                    /* Calculate the remaining byte from the current counter of course */
					l_indx = p_ctx->memACtr;
                    while( ( l_indx < p_ctx->memAFrameSize ) && ( l_calLen < 0xFFFFFFFFu ) )
                    {
                        if( ECU_SOF == p_ctx->p_memA[l_indx] )
                        {
							/* Try to avoid overflow. Resonable limit for HW */
							if( l_calLen <= 0xFFFFFFFDu )
							{
								/* Stuff with escape */
								l_calLen += 2u;
							}
							else
							{
								l_calLen = 0xFFFFFFFFu;
							}
                        }
                        else if( ECU_EOF == p_ctx->p_memA[l_indx] )
                        {
							/* Try to avoid overflow. Resonable limit for HW */
							if( l_calLen <= 0xFFFFFFFDu )
							{
								/* Stuff with escape */
								l_calLen += 2u;
							}
							else
							{
								l_calLen = 0xFFFFFFFFu;
							}
                        }
                        else if( ECU_ESC == p_ctx->p_memA[l_indx] )
                        {
							/* Try to avoid overflow. Resonable limit for HW */
							if( l_calLen <= 0xFFFFFFFDu )
							{
								/* Stuff with escape */
								l_calLen += 2u;
							}
							else
							{
								l_calLen = 0xFFFFFFFFu;
							}
                        }
                        else
                        {
                            /* Stuff with escape */
                            l_calLen += 1u;
                        }

						l_indx++;
                    }

                    /* Copy calc value */
                    *p_retrivedLen = l_calLen;

                    l_result = BSTF_RES_OK;
                }
            }
		}
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_GetStufChunk(s_eCU_BSTF_Ctx* const p_ctx, uint8_t a_stuffedDest[], const uint32_t maxDestLen,
                                     uint32_t* const p_filledLen)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;
    uint32_t l_nFillByte;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == a_stuffedDest ) || ( NULL == p_filledLen ) )
	{
		l_result = BSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = BSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = BSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Check param */
                if( p_ctx->memAFrameSize <= 0u )
                {
                    l_result = BSTF_RES_NOINITFRAME;
                }
                else
                {
                    /* Check param */
                    if( maxDestLen <= 0u )
                    {
                        l_result = BSTF_RES_BADPARAM;
                    }
                    else
                    {
                        /* Init counter */
                        l_nFillByte = 0u;
						l_result = BSTF_RES_OK;

                        /* Execute parsing cycle */
                        while( ( l_nFillByte < maxDestLen ) &&
						       ( BSTF_SM_PRV_STUFFEND != p_ctx->stuffState ) &&
							   ( BSTF_RES_OK == l_result ) )
                        {
                            switch( p_ctx->stuffState )
                            {
                                case BSTF_SM_PRV_NEEDSOF :
                                {
                                    /* Start of frame */
                                    a_stuffedDest[l_nFillByte] = ECU_SOF;
                                    l_nFillByte++;
                                    p_ctx->stuffState = BSTF_SM_PRV_NEEDRAWDATA;

                                    break;
                                }

                                case BSTF_SM_PRV_NEEDRAWDATA :
                                {
                                    if( p_ctx->memACtr >= p_ctx->memAFrameSize )
                                    {
                                        /* End of frame needed */
                                        p_ctx->stuffState = BSTF_SM_PRV_NEEDEOF;
                                    }
                                    else
                                    {
                                        /* Parse data from the frame now */
                                        if( ECU_SOF == p_ctx->p_memA[p_ctx->memACtr] )
                                        {
                                            /* Stuff with escape */
                                            a_stuffedDest[l_nFillByte] = ECU_ESC;
                                            p_ctx->stuffState = BSTF_SM_PRV_NEEDNEGATEPRECDATA;
                                            l_nFillByte++;
                                            p_ctx->memACtr++;
                                        }
                                        else if( ECU_EOF == p_ctx->p_memA[p_ctx->memACtr] )
                                        {
                                            /* Stuff with escape */
                                            a_stuffedDest[l_nFillByte] = ECU_ESC;
                                            p_ctx->stuffState = BSTF_SM_PRV_NEEDNEGATEPRECDATA;
                                            l_nFillByte++;
                                            p_ctx->memACtr++;
                                        }
                                        else if( ECU_ESC == p_ctx->p_memA[p_ctx->memACtr] )
                                        {
                                            /* Stuff with escape */
                                            a_stuffedDest[l_nFillByte] = ECU_ESC;
                                            p_ctx->stuffState = BSTF_SM_PRV_NEEDNEGATEPRECDATA;
                                            l_nFillByte++;
                                            p_ctx->memACtr++;
                                        }
                                        else
                                        {
                                            /* Can insert data and continue parsing other raw data */
                                            a_stuffedDest[l_nFillByte] = p_ctx->p_memA[p_ctx->memACtr];
                                            l_nFillByte++;
                                            p_ctx->memACtr++;
                                        }
                                    }

                                    break;
                                }

                                case BSTF_SM_PRV_NEEDNEGATEPRECDATA :
                                {
                                    /* Something from an old iteration  */
                                    a_stuffedDest[l_nFillByte] = ( (uint8_t) ~( p_ctx->p_memA[p_ctx->memACtr - 1u] ) );
                                    l_nFillByte++;

                                    /* After this we can continue parsing raw data */
                                    p_ctx->stuffState = BSTF_SM_PRV_NEEDRAWDATA;

                                    break;
                                }

                                case BSTF_SM_PRV_NEEDEOF :
                                {
                                    /* End of frame */
                                    a_stuffedDest[l_nFillByte] = ECU_EOF;
                                    p_ctx->stuffState = BSTF_SM_PRV_STUFFEND;
                                    l_nFillByte++;

                                    break;
                                }

                               default:
                               {
                                   /* Impossible end here, and if so something horrible happened (memory corruption) */
									l_result = BSTF_RES_CORRUPTCTX;
                                   break;
                               }
                            }
                        }

						/* Save counter */
						*p_filledLen = l_nFillByte;

						if( BSTF_RES_OK == l_result )
						{
							/* l_result? */
							if( BSTF_SM_PRV_STUFFEND == p_ctx->stuffState )
							{
								/* Nothing more */
								l_result = BSTF_RES_FRAMEENDED;
							}
						}
                    }
                }
            }
		}
	}

	return l_result;
}



/***********************************************************************************************************************
 *  PRIVATE FUNCTION
 **********************************************************************************************************************/
static bool_t eCU_BSTF_isStatusStillCoherent(const s_eCU_BSTF_Ctx* p_ctx)
{
    bool_t l_result;
    uint8_t l_preceByte;

	/* Check basic context validity */
	if( ( p_ctx->memASize <= 0u ) || ( NULL == p_ctx->p_memA ) )
	{
		l_result = false;
	}
	else
	{
        /* Check context limit validity */
        if( ( p_ctx->memAFrameSize > p_ctx->memASize ) || ( p_ctx->memACtr > p_ctx->memAFrameSize ) )
        {
            l_result = false;
        }
        else
        {
            /* Check data coherence on SOF */
            if( ( BSTF_SM_PRV_NEEDSOF  == p_ctx->stuffState ) && ( 0u != p_ctx->memACtr ) )
            {
                l_result = false;
            }
            else
            {
                /* Check data coherence on SOF */
                if( ( 0u == p_ctx->memACtr ) && ( BSTF_SM_PRV_NEEDSOF != p_ctx->stuffState ) &&
                    ( BSTF_SM_PRV_NEEDRAWDATA != p_ctx->stuffState ) )
                {
                    l_result = false;
                }
                else
                {
                    /* Check data coherence on EOF */
                    if( ( BSTF_SM_PRV_STUFFEND == p_ctx->stuffState ) && ( p_ctx->memACtr != p_ctx->memAFrameSize ) )
                    {
                        l_result = false;
                    }
                    else
                    {
                        /* Check data coherence on precedent data */
                        if( BSTF_SM_PRV_NEEDNEGATEPRECDATA == p_ctx->stuffState )
                        {
                            l_preceByte = p_ctx->p_memA[p_ctx->memACtr - 1u];
                            if( ( ECU_ESC != l_preceByte ) && ( ECU_EOF != l_preceByte ) && ( ECU_SOF != l_preceByte ) )
                            {
                                l_result = false;
                            }
                            else
                            {
                                l_result = true;
                            }
                        }
                        else
                        {
                            l_result = true;
                        }
                    }
                }
            }
        }
	}

    return l_result;
}
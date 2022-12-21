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
static bool_t eCU_BSTF_isStatusStillCoherent(const t_eCU_BSTF_Ctx* p_ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_BSTF_Res eCU_BSTF_InitCtx(t_eCU_BSTF_Ctx* const p_ctx, uint8_t* p_memArea, const uint32_t memAreaSize)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_memArea ) )
	{
		l_result = e_eCU_BSTF_RES_BADPOINTER;
	}
	else
	{
        /* Check data validity */
        if( memAreaSize <= 0u )
        {
            l_result = e_eCU_BSTF_RES_BADPARAM;
        }
        else
        {
            /* Initialize internal status */
            p_ctx->bIsInit = true;
            p_ctx->puBuff = p_memArea;
            p_ctx->uBuffL = memAreaSize;
            p_ctx->uFrameL = 0u;
            p_ctx->uFrameCtr = 0u;
            p_ctx->eSM = e_eCU_BSTFPRV_SM_NEEDSOF;

            l_result = e_eCU_BSTF_RES_OK;
        }
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_IsInit(t_eCU_BSTF_Ctx* const p_ctx, bool_t* p_isInit)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isInit ) )
	{
		l_result = e_eCU_BSTF_RES_BADPOINTER;
	}
	else
	{
        *p_isInit = p_ctx->bIsInit;
        l_result = e_eCU_BSTF_RES_OK;
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_GetWherePutData(t_eCU_BSTF_Ctx* const p_ctx, uint8_t** pp_data, uint32_t* const p_maxDataSize)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == pp_data ) || ( NULL == p_maxDataSize ) )
	{
		l_result = e_eCU_BSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* return data */
                *pp_data = p_ctx->puBuff;
                *p_maxDataSize = p_ctx->uBuffL;
                l_result = e_eCU_BSTF_RES_OK;
            }
		}
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_NewFrame(t_eCU_BSTF_Ctx* const p_ctx, const uint32_t frameLen)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = e_eCU_BSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Check param validity */
                if( ( frameLen <= 0u ) || ( frameLen > p_ctx->uBuffL ) )
                {
                    l_result = e_eCU_BSTF_RES_BADPARAM;
                }
                else
                {
                    /* Update data */
                    p_ctx->uFrameL = frameLen;
                    p_ctx->uFrameCtr = 0u;
                    p_ctx->eSM = e_eCU_BSTFPRV_SM_NEEDSOF;

                    l_result = e_eCU_BSTF_RES_OK;
                }
            }
		}
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_RestartFrame(t_eCU_BSTF_Ctx* const p_ctx)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = e_eCU_BSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Param */
                if( p_ctx->uFrameL <= 0u )
                {
                    l_result = e_eCU_BSTF_RES_NOINITFRAME;
                }
                else
                {
                    /* Update index */
                    p_ctx->uFrameCtr = 0u;
                    p_ctx->eSM = e_eCU_BSTFPRV_SM_NEEDSOF;

                    l_result = e_eCU_BSTF_RES_OK;
                }
            }
		}
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_GetRemByteToGet(t_eCU_BSTF_Ctx* const p_ctx, uint32_t* const p_retrivedLen)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;
    uint32_t l_calLen;
	uint32_t l_indx;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_retrivedLen ) )
	{
		l_result = e_eCU_BSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Check param */
                if( p_ctx->uFrameL <= 0u )
                {
                    l_result = e_eCU_BSTF_RES_NOINITFRAME;
                }
                else
                {
                    /* Analyze the current state of the state machine */
                    if( e_eCU_BSTFPRV_SM_NEEDSOF == p_ctx->eSM )
                    {
                        /* SOF + Data + EOF */
                        l_calLen = 2u;
                    }
                    else if( e_eCU_BSTFPRV_SM_NEEDNEGATEPRECDATA == p_ctx->eSM )
                    {
                        /* If a precedent byte of the payload was an SOF, EOF or ESC character, this means that the
                        * ESC char is already inserted in the unstuffed data, but that we need to add the negation of
                        * the payload + the EOF */
                        l_calLen = 2u;
                    }
                    else if( e_eCU_BSTFPRV_SM_STUFFEND == p_ctx->eSM )
                    {
                        /* Stuffend ended, no data to wait */
                        l_calLen = 0u;
                    }
                    else
                    {
                        /* data + EOF. With the current state machine is not possible to have a single call that
                         * leave the system in the state: e_eCU_BSTFPRV_SM_NEEDEOF */
                        l_calLen = 1u;
                    }

                    /* Calculate the remaining byte from the current counter of course */
					l_indx = p_ctx->uFrameCtr;
                    while( ( l_indx < p_ctx->uFrameL ) && ( l_calLen < 0xFFFFFFFFu ) )
                    {
                        if( ECU_SOF == p_ctx->puBuff[l_indx] )
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
                        else if( ECU_EOF == p_ctx->puBuff[l_indx] )
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
                        else if( ECU_ESC == p_ctx->puBuff[l_indx] )
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

                    l_result = e_eCU_BSTF_RES_OK;
                }
            }
		}
	}

	return l_result;
}

e_eCU_BSTF_Res eCU_BSTF_GetStufChunk(t_eCU_BSTF_Ctx* const p_ctx, uint8_t* p_stuffedDest, const uint32_t maxDestLen,
                                     uint32_t* const p_filledLen)
{
	/* Local variable */
	e_eCU_BSTF_Res l_result;
    uint32_t l_nFillByte;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_stuffedDest ) || ( NULL == p_filledLen ) )
	{
		l_result = e_eCU_BSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Check param */
                if( p_ctx->uFrameL <= 0u )
                {
                    l_result = e_eCU_BSTF_RES_NOINITFRAME;
                }
                else
                {
                    /* Check param */
                    if( maxDestLen <= 0u )
                    {
                        l_result = e_eCU_BSTF_RES_BADPARAM;
                    }
                    else
                    {
                        /* Init counter */
                        l_nFillByte = 0u;
						l_result = e_eCU_BSTF_RES_OK;

                        /* Execute parsing cycle */
                        while( ( l_nFillByte < maxDestLen ) &&
						       ( e_eCU_BSTFPRV_SM_STUFFEND != p_ctx->eSM ) &&
							   ( e_eCU_BSTF_RES_OK == l_result ) )
                        {
                            switch( p_ctx->eSM )
                            {
                                case e_eCU_BSTFPRV_SM_NEEDSOF :
                                {
                                    /* Start of frame */
                                    p_stuffedDest[l_nFillByte] = ECU_SOF;
                                    l_nFillByte++;
                                    p_ctx->eSM = e_eCU_BSTFPRV_SM_NEEDRAWDATA;

                                    break;
                                }

                                case e_eCU_BSTFPRV_SM_NEEDRAWDATA :
                                {
                                    if( p_ctx->uFrameCtr >= p_ctx->uFrameL )
                                    {
                                        /* End of frame needed */
                                        p_ctx->eSM = e_eCU_BSTFPRV_SM_NEEDEOF;
                                    }
                                    else
                                    {
                                        /* Parse data from the frame now */
                                        if( ECU_SOF == p_ctx->puBuff[p_ctx->uFrameCtr] )
                                        {
                                            /* Stuff with escape */
                                            p_stuffedDest[l_nFillByte] = ECU_ESC;
                                            p_ctx->eSM = e_eCU_BSTFPRV_SM_NEEDNEGATEPRECDATA;
                                            l_nFillByte++;
                                            p_ctx->uFrameCtr++;
                                        }
                                        else if( ECU_EOF == p_ctx->puBuff[p_ctx->uFrameCtr] )
                                        {
                                            /* Stuff with escape */
                                            p_stuffedDest[l_nFillByte] = ECU_ESC;
                                            p_ctx->eSM = e_eCU_BSTFPRV_SM_NEEDNEGATEPRECDATA;
                                            l_nFillByte++;
                                            p_ctx->uFrameCtr++;
                                        }
                                        else if( ECU_ESC == p_ctx->puBuff[p_ctx->uFrameCtr] )
                                        {
                                            /* Stuff with escape */
                                            p_stuffedDest[l_nFillByte] = ECU_ESC;
                                            p_ctx->eSM = e_eCU_BSTFPRV_SM_NEEDNEGATEPRECDATA;
                                            l_nFillByte++;
                                            p_ctx->uFrameCtr++;
                                        }
                                        else
                                        {
                                            /* Can insert data and continue parsing other raw data */
                                            p_stuffedDest[l_nFillByte] = p_ctx->puBuff[p_ctx->uFrameCtr];
                                            l_nFillByte++;
                                            p_ctx->uFrameCtr++;
                                        }
                                    }

                                    break;
                                }

                                case e_eCU_BSTFPRV_SM_NEEDNEGATEPRECDATA :
                                {
                                    /* Something from an old iteration  */
                                    p_stuffedDest[l_nFillByte] = ( (uint8_t) ~( p_ctx->puBuff[p_ctx->uFrameCtr - 1u] ) );
                                    l_nFillByte++;

                                    /* After this we can continue parsing raw data */
                                    p_ctx->eSM = e_eCU_BSTFPRV_SM_NEEDRAWDATA;

                                    break;
                                }

                                case e_eCU_BSTFPRV_SM_NEEDEOF :
                                {
                                    /* End of frame */
                                    p_stuffedDest[l_nFillByte] = ECU_EOF;
                                    p_ctx->eSM = e_eCU_BSTFPRV_SM_STUFFEND;
                                    l_nFillByte++;

                                    break;
                                }

                               default:
                               {
                                   /* Impossible end here, and if so something horrible happened (memory corruption) */
									l_result = e_eCU_BSTF_RES_CORRUPTCTX;
                                   break;
                               }
                            }
                        }

						/* Save counter */
						*p_filledLen = l_nFillByte;

						if( e_eCU_BSTF_RES_OK == l_result )
						{
							/* l_result? */
							if( e_eCU_BSTFPRV_SM_STUFFEND == p_ctx->eSM )
							{
								/* Nothing more */
								l_result = e_eCU_BSTF_RES_FRAMEENDED;
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
static bool_t eCU_BSTF_isStatusStillCoherent(const t_eCU_BSTF_Ctx* p_ctx)
{
    bool_t l_result;
    uint8_t l_preceByte;

	/* Check basic context validity */
	if( ( p_ctx->uBuffL <= 0u ) || ( NULL == p_ctx->puBuff ) )
	{
		l_result = false;
	}
	else
	{
        /* Check context limit validity */
        if( ( p_ctx->uFrameL > p_ctx->uBuffL ) || ( p_ctx->uFrameCtr > p_ctx->uFrameL ) )
        {
            l_result = false;
        }
        else
        {
            /* Check data coherence on SOF */
            if( ( e_eCU_BSTFPRV_SM_NEEDSOF  == p_ctx->eSM ) && ( 0u != p_ctx->uFrameCtr ) )
            {
                l_result = false;
            }
            else
            {
                /* Check data coherence on SOF */
                if( ( 0u == p_ctx->uFrameCtr ) && ( e_eCU_BSTFPRV_SM_NEEDSOF != p_ctx->eSM ) &&
                    ( e_eCU_BSTFPRV_SM_NEEDRAWDATA != p_ctx->eSM ) )
                {
                    l_result = false;
                }
                else
                {
                    /* Check data coherence on EOF */
                    if( ( e_eCU_BSTFPRV_SM_STUFFEND == p_ctx->eSM ) && ( p_ctx->uFrameCtr != p_ctx->uFrameL ) )
                    {
                        l_result = false;
                    }
                    else
                    {
                        /* Check data coherence on precedent data */
                        if( e_eCU_BSTFPRV_SM_NEEDNEGATEPRECDATA == p_ctx->eSM )
                        {
                            l_preceByte = p_ctx->puBuff[p_ctx->uFrameCtr - 1u];
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
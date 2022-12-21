/**
 * @file       eCUByteUnStuffer.c
 *
 * @brief      Byte unstuffer utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteUnStuffer.h"



/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t eCU_BUNSTF_isStatusStillCoherent(const t_eCU_BUNSTF_Ctx* p_ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_BUNSTF_RES eCU_BUNSTF_InitCtx(t_eCU_BUNSTF_Ctx* const p_ctx, uint8_t* p_memArea, const uint32_t memAreaSize)
{
	/* Local variable */
	e_eCU_BUNSTF_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_memArea ) )
	{
		l_result = e_eCU_BUNSTF_RES_BADPOINTER;
	}
	else
	{
        /* Check data validity */
        if( memAreaSize <= 0u )
        {
            l_result = e_eCU_BUNSTF_RES_BADPARAM;
        }
        else
        {
            /* Initialize internal status */
            p_ctx->bIsInit = true;
            p_ctx->puBuff = p_memArea;
            p_ctx->uBuffL = memAreaSize;
            p_ctx->uFrameCtr = 0u;
            p_ctx->eSM = e_eCU_BUNSTFPRV_SM_NEEDSOF;
            l_result = e_eCU_BUNSTF_RES_OK;
        }
	}

	return l_result;
}

e_eCU_BUNSTF_RES eCU_BUNSTF_IsInit(t_eCU_BUNSTF_Ctx* const p_ctx, bool_t* p_isInit)
{
	/* Local variable */
	e_eCU_BUNSTF_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isInit ) )
	{
		l_result = e_eCU_BUNSTF_RES_BADPOINTER;
	}
	else
	{
        *p_isInit = p_ctx->bIsInit;
        l_result = e_eCU_BUNSTF_RES_OK;
	}

	return l_result;
}

e_eCU_BUNSTF_RES eCU_BUNSTF_NewFrame(t_eCU_BUNSTF_Ctx* const p_ctx)
{
	/* Local variable */
	e_eCU_BUNSTF_RES l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = e_eCU_BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BUNSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Update index */
                p_ctx->uFrameCtr = 0u;
				p_ctx->eSM = e_eCU_BUNSTFPRV_SM_NEEDSOF;
                l_result = e_eCU_BUNSTF_RES_OK;
            }
		}
	}

	return l_result;
}

e_eCU_BUNSTF_RES eCU_BUNSTF_GetUnstufData(t_eCU_BUNSTF_Ctx* const p_ctx, uint8_t** pp_data, uint32_t* const p_Len)
{
	/* Local variable */
	e_eCU_BUNSTF_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == pp_data ) || ( NULL == p_Len ) )
	{
		l_result = e_eCU_BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BUNSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                *pp_data = p_ctx->puBuff;
                *p_Len =  p_ctx->uFrameCtr;
                l_result = e_eCU_BUNSTF_RES_OK;
            }
		}
	}

	return l_result;
}

e_eCU_BUNSTF_RES eCU_BUNSTF_GetUnstufLen(t_eCU_BUNSTF_Ctx* const p_ctx, uint32_t* const p_Len)
{
	/* Local variable */
	e_eCU_BUNSTF_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_Len ) )
	{
		l_result = e_eCU_BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BUNSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                *p_Len =  p_ctx->uFrameCtr;
                l_result = e_eCU_BUNSTF_RES_OK;
            }
		}
	}

	return l_result;
}

e_eCU_BUNSTF_RES eCU_BUNSTF_IsWaitingSof(const t_eCU_BUNSTF_Ctx* p_ctx, bool_t* const p_isWaitingSof)
{
	/* Local variable */
	e_eCU_BUNSTF_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isWaitingSof ) )
	{
		l_result = e_eCU_BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BUNSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                if( e_eCU_BUNSTFPRV_SM_NEEDSOF == p_ctx->eSM )
                {
                    *p_isWaitingSof = true;
                }
                else
                {
                    *p_isWaitingSof = false;
                }

                l_result = e_eCU_BUNSTF_RES_OK;
            }
		}
	}

	return l_result;
}

e_eCU_BUNSTF_RES eCU_BUNSTF_IsAFullFrameUnstuff(const t_eCU_BUNSTF_Ctx* p_ctx, bool_t* const p_isFrameUnstuff)
{
	/* Local variable */
	e_eCU_BUNSTF_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isFrameUnstuff ) )
	{
		l_result = e_eCU_BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BUNSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                if( e_eCU_BUNSTFPRV_SM_UNSTUFFEND == p_ctx->eSM )
                {
                    *p_isFrameUnstuff = true;
                }
                else
                {
                    *p_isFrameUnstuff = false;
                }
                l_result = e_eCU_BUNSTF_RES_OK;
            }
		}
	}

	return l_result;
}

e_eCU_BUNSTF_RES eCU_BUNSTF_IsFrameBad(const t_eCU_BUNSTF_Ctx* p_ctx, bool_t* const p_isFrameBad)
{
	/* Local variable */
	e_eCU_BUNSTF_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isFrameBad ) )
	{
		l_result = e_eCU_BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BUNSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                if( e_eCU_BUNSTFPRV_SM_UNSTUFFFAIL == p_ctx->eSM )
                {
                    *p_isFrameBad = true;
                }
                else
                {
                    *p_isFrameBad = false;
                }
                l_result = e_eCU_BUNSTF_RES_OK;
            }
		}
	}

	return l_result;
}



e_eCU_BUNSTF_RES eCU_BUNSTF_InsStufChunk(t_eCU_BUNSTF_Ctx* const p_ctx, const uint8_t* p_stuffArea,
                                         const uint32_t stuffLen, uint32_t* const p_consumedStuffData)
{
	/* Local variable */
	e_eCU_BUNSTF_RES l_result;
    uint32_t l_nExamByte;
    uint8_t l_currentByte;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_stuffArea ) || ( NULL == p_consumedStuffData ) )
	{
		l_result = e_eCU_BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_BUNSTF_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Check param */
                if( stuffLen <= 0u )
                {
                    l_result = e_eCU_BUNSTF_RES_BADPARAM;
                }
                else
                {
                    /* Init counter */
                    l_nExamByte = 0u;

                    /* Init l_result */
                    l_result = e_eCU_BUNSTF_RES_OK;

                    /* Elab all data */
                    while( ( l_nExamByte < stuffLen ) && ( e_eCU_BUNSTF_RES_OK == l_result ) &&
					       ( e_eCU_BUNSTFPRV_SM_UNSTUFFEND != p_ctx->eSM ) &&
                           ( e_eCU_BUNSTFPRV_SM_UNSTUFFFAIL != p_ctx->eSM ) )
                    {
                        /* Read current byte */
                        l_currentByte = p_stuffArea[l_nExamByte];

                        /* Decide what to do */
						switch( p_ctx->eSM )
						{
							case e_eCU_BUNSTFPRV_SM_NEEDSOF:
							{
								/* Wait SOF, discharge others */
								if( ECU_SOF == l_currentByte )
								{
									/* Found start */
									p_ctx->uFrameCtr = 0u;
									p_ctx->eSM = e_eCU_BUNSTFPRV_SM_NEEDRAWDATA;
								}
								else
								{
									/* Waiting for start, no other bytes */
                                    p_ctx->uFrameCtr = 0u;
                                    p_ctx->eSM = e_eCU_BUNSTFPRV_SM_UNSTUFFFAIL;
								}
								l_nExamByte++;
								break;
							}

							case e_eCU_BUNSTFPRV_SM_NEEDRAWDATA:
							{
								if( ECU_SOF == l_currentByte )
								{
									/* Found start, but wasn't expected */
									p_ctx->uFrameCtr = 0u;
                                    p_ctx->eSM = e_eCU_BUNSTFPRV_SM_NEEDRAWDATA;
                                    l_result = e_eCU_BUNSTF_RES_FRAMERESTART;
									l_nExamByte++;
								}
								else if( ECU_EOF == l_currentByte )
								{
									if( p_ctx->uFrameCtr <= 0u )
									{
										/* Found end, but no data received..  */
                                        p_ctx->eSM = e_eCU_BUNSTFPRV_SM_UNSTUFFFAIL;
									}
									else
									{
										/* Can close the frame, yey */
										p_ctx->eSM = e_eCU_BUNSTFPRV_SM_UNSTUFFEND;
									}

									l_nExamByte++;
								}
								else if( ECU_ESC == l_currentByte )
								{
									/* Next data will be negated data */
									p_ctx->eSM = e_eCU_BUNSTFPRV_SM_NEEDNEGATEDATA;
									l_nExamByte++;
								}
								else
								{
									/* Received good raw data */
									if( p_ctx->uFrameCtr >= p_ctx->uBuffL )
									{
										/* No more data avaiable to save that thing */
										l_result = e_eCU_BUNSTF_RES_OUTOFMEM;
									}
									else
									{
										/* Only raw data */
										p_ctx->puBuff[p_ctx->uFrameCtr] = l_currentByte;
										p_ctx->uFrameCtr++;
										l_nExamByte++;
									}
								}
								break;
							}

							case e_eCU_BUNSTFPRV_SM_NEEDNEGATEDATA:
							{
								if( ECU_SOF == l_currentByte )
								{
									/* Found start, but wasn't expected */
									p_ctx->uFrameCtr = 0u;
                                    p_ctx->eSM = e_eCU_BUNSTFPRV_SM_NEEDRAWDATA;
                                    l_result = e_eCU_BUNSTF_RES_FRAMERESTART;
									l_nExamByte++;
								}
								else if( ( ECU_EOF == l_currentByte ) ||
								         ( ECU_ESC == l_currentByte ) )
								{
									/* Found and error, we were expecting raw negated data here.  */
                                    p_ctx->eSM = e_eCU_BUNSTFPRV_SM_UNSTUFFFAIL;
									l_nExamByte++;
								}
								else
								{
									/* Received negated data */
									if( p_ctx->uFrameCtr >= p_ctx->uBuffL )
									{
										/* No more data avaiable to save that thing */
										l_result = e_eCU_BUNSTF_RES_OUTOFMEM;
									}
									else
									{
										/* Is it true that negate data is present ? */
										if( ( ECU_SOF == ( ( uint8_t ) ~l_currentByte ) ) ||
											( ECU_EOF == ( ( uint8_t ) ~l_currentByte ) ) ||
											( ECU_ESC == ( ( uint8_t ) ~l_currentByte ) ) )
										{
											/* current data is neg */
											p_ctx->puBuff[p_ctx->uFrameCtr] = ( uint8_t ) ( ~l_currentByte );
											p_ctx->eSM = e_eCU_BUNSTFPRV_SM_NEEDRAWDATA;
											p_ctx->uFrameCtr++;
											l_nExamByte++;
										}
										else
										{
											/* Impossible receive a data after esc that is not SOF EOF or ESC neg */
                                            p_ctx->eSM = e_eCU_BUNSTFPRV_SM_UNSTUFFFAIL;
											l_nExamByte++;
										}
									}
								}
								break;
							}

							default:
							{
								/* Impossible end here, and if so something horrible happened ( memory corruption ) */
								l_result = e_eCU_BUNSTF_RES_CORRUPTCTX;
								break;
							}
						}
                    }

					/* Save the l_result */
					*p_consumedStuffData = l_nExamByte;

					if( e_eCU_BUNSTF_RES_OK == l_result )
					{
						if( e_eCU_BUNSTFPRV_SM_UNSTUFFEND == p_ctx->eSM )
						{
							l_result = e_eCU_BUNSTF_RES_FRAMEENDED;
						}
                        else if( e_eCU_BUNSTFPRV_SM_UNSTUFFFAIL == p_ctx->eSM )
                        {
                           l_result = e_eCU_BUNSTF_RES_BADFRAME;
                        }
                        else
                        {
                            /* No error but have other data to unstuff */
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
static bool_t eCU_BUNSTF_isStatusStillCoherent(const t_eCU_BUNSTF_Ctx* p_ctx)
{
    bool_t l_result;

	/* Check basic context validity */
	if( ( p_ctx->uBuffL <= 0u ) || ( NULL == p_ctx->puBuff ) )
	{
		l_result = false;
	}
	else
	{
        /* Check size validity */
        if( p_ctx->uFrameCtr > p_ctx->uBuffL )
        {
            l_result = false;
        }
        else
        {
            /* Check status coherence */
            if( ( e_eCU_BUNSTFPRV_SM_NEEDSOF == p_ctx->eSM ) && ( 0u != p_ctx->uFrameCtr ) )
            {
                l_result = false;
            }
            else
            {
                /* Check status coherence */
                if( ( e_eCU_BUNSTFPRV_SM_UNSTUFFEND == p_ctx->eSM ) && ( p_ctx->uFrameCtr <= 0u ) )
                {
                    l_result = false;
                }
                else
                {
                    l_result = true;
                }
            }

        }
	}

    return l_result;
}
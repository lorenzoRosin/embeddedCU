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
static bool_t isBUSStatusStillCoherent(const s_eCU_BUNSTF_Ctx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
s_eCU_BUNSTF_Res BUNSTF_InitCtx(s_eCU_BUNSTF_Ctx* const ctx, uint8_t memArea[], const uint32_t memAreaSize)
{
	/* Local variable */
	s_eCU_BUNSTF_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == memArea ) )
	{
		result = BUNSTF_RES_BADPOINTER;
	}
	else
	{
        /* Check data validity */
        if( memAreaSize <= 0u )
        {
            result = BUNSTF_RES_BADPARAM;
        }
        else
        {
            /* Initialize internal status */
            ctx->isInit = true;
            ctx->memArea = memArea;
            ctx->memAreaSize = memAreaSize;
            ctx->memAreaCntr = 0u;
            ctx->unStuffState = BUNSTF_SM_PRV_NEEDSOF;
            result = BUNSTF_RES_OK;
        }
	}

	return result;
}

s_eCU_BUNSTF_Res BUNSTF_StartNewFrame(s_eCU_BUNSTF_Ctx* const ctx)
{
	/* Local variable */
	s_eCU_BUNSTF_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Update index */
                ctx->memAreaCntr = 0u;
				ctx->unStuffState = BUNSTF_SM_PRV_NEEDSOF;
                result = BUNSTF_RES_OK;
            }
		}
	}

	return result;
}

s_eCU_BUNSTF_Res BUNSTF_GetUnstufData(s_eCU_BUNSTF_Ctx* const ctx, uint8_t** dataP, uint32_t* const retrivedLen)
{
	/* Local variable */
	s_eCU_BUNSTF_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataP ) || ( NULL == retrivedLen ) )
	{
		result = BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                *dataP = ctx->memArea;
                *retrivedLen =  ctx->memAreaCntr;
                result = BUNSTF_RES_OK;
            }
		}
	}

	return result;
}

s_eCU_BUNSTF_Res BUNSTF_GetUnstufLen(s_eCU_BUNSTF_Ctx* const ctx, uint32_t* const retrivedLen)
{
	/* Local variable */
	s_eCU_BUNSTF_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == retrivedLen ) )
	{
		result = BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                *retrivedLen =  ctx->memAreaCntr;
                result = BUNSTF_RES_OK;
            }
		}
	}

	return result;
}

s_eCU_BUNSTF_Res BUNSTF_IsWaitingSof(const s_eCU_BUNSTF_Ctx* ctx, bool_t* const isWaitingSof)
{
	/* Local variable */
	s_eCU_BUNSTF_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == isWaitingSof ) )
	{
		result = BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                if( BUNSTF_SM_PRV_NEEDSOF == ctx->unStuffState )
                {
                    *isWaitingSof = true;
                }
                else
                {
                    *isWaitingSof = false;
                }

                result = BUNSTF_RES_OK;
            }
		}
	}

	return result;
}

s_eCU_BUNSTF_Res BUNSTF_IsAFullFrameUnstuff(const s_eCU_BUNSTF_Ctx* ctx, bool_t* const isFrameUnstuff)
{
	/* Local variable */
	s_eCU_BUNSTF_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == isFrameUnstuff ) )
	{
		result = BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = BUNSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = BUNSTF_RES_CORRUPTCTX;
            }
            else
            {
                if( BUNSTF_SM_PRV_UNSTUFFEND == ctx->unStuffState )
                {
                    *isFrameUnstuff = true;
                }
                else
                {
                    *isFrameUnstuff = false;
                }
                result = BUNSTF_RES_OK;
            }
		}
	}

	return result;
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "CERT-INT30-C_b"
    /* Suppressed for code clarity */
#endif

s_eCU_BUNSTF_Res BUNSTF_InsStufChunk(s_eCU_BUNSTF_Ctx* const ctx, const uint8_t stuffArea[], const uint32_t stuffLen,
                                       uint32_t* const consumedStuffData)
{
	/* Local variable */
	s_eCU_BUNSTF_Res result;
    uint32_t nExamByte;
    uint8_t currentByte;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == stuffArea ) || ( NULL == consumedStuffData ) )
	{
		result = BUNSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = BUNSTF_RES_NOINITLIB;
		}
		else
		{
            if( stuffLen <= 0u )
            {
                result = BUNSTF_RES_BADPARAM;
            }
            else
            {
                /* Check internal status validity */
                if( false == isBUSStatusStillCoherent(ctx) )
                {
                    result = BUNSTF_RES_CORRUPTCTX;
                }
                else
                {
                    /* Init counter */
                    nExamByte = 0u;

                    /* Init result */
                    result = BUNSTF_RES_OK;

                    /* Elab all data */
                    while( ( nExamByte < stuffLen ) && ( BUNSTF_RES_OK == result ) &&
					       ( BUNSTF_SM_PRV_UNSTUFFEND != ctx->unStuffState ) &&
                           ( BUNSTF_SM_PRV_UNSTUFFFAIL != ctx->unStuffState ) )
                    {
                        /* Read current byte */
                        currentByte = stuffArea[nExamByte];

                        /* Decide what to do */
						switch( ctx->unStuffState )
						{
							case BUNSTF_SM_PRV_NEEDSOF:
							{
								/* Wait SOF, discharge others */
								if( ECU_SOF == currentByte )
								{
									/* Found start */
									ctx->memAreaCntr = 0u;
									ctx->unStuffState = BUNSTF_SM_PRV_NEEDRAWDATA;
								}
								else
								{
									/* Waiting for start, no other bytes */
                                    ctx->memAreaCntr = 0u;
                                    ctx->unStuffState = BUNSTF_SM_PRV_UNSTUFFFAIL;
								}
								nExamByte++;
								break;
							}

							case BUNSTF_SM_PRV_NEEDRAWDATA:
							{
								if( ECU_SOF == currentByte )
								{
									/* Found start, but wasn't expected */
									ctx->memAreaCntr = 0u;
                                    ctx->unStuffState = BUNSTF_SM_PRV_NEEDRAWDATA;
                                    result = BUNSTF_RES_FRAMERESTART;
									nExamByte++;
								}
								else if( ECU_EOF == currentByte )
								{
									if( ctx->memAreaCntr <= 0u )
									{
										/* Found end, but no data received..  */
										ctx->memAreaCntr = 0u;
                                        ctx->unStuffState = BUNSTF_SM_PRV_UNSTUFFFAIL;
									}
									else
									{
										/* Can close the frame, yey */
										ctx->unStuffState = BUNSTF_SM_PRV_UNSTUFFEND;
									}

									nExamByte++;
								}
								else if( ECU_ESC == currentByte )
								{
									/* Next data will be negated data */
									ctx->unStuffState = BUNSTF_SM_PRV_NEEDNEGATEDATA;
									nExamByte++;
								}
								else
								{
									/* Received good raw data */
									if( ctx->memAreaCntr >= ctx->memAreaSize )
									{
										/* No more data avaiable to save that thing */
										result = BUNSTF_RES_OUTOFMEM;
									}
									else
									{
										/* Only raw data */
										ctx->memArea[ctx->memAreaCntr] = currentByte;
										ctx->memAreaCntr++;
										nExamByte++;
									}
								}
								break;
							}

							case BUNSTF_SM_PRV_NEEDNEGATEDATA:
							{
								if( ECU_SOF == currentByte )
								{
									/* Found start, but wasn't expected */
									ctx->memAreaCntr = 0u;
                                    ctx->unStuffState = BUNSTF_SM_PRV_NEEDRAWDATA;
                                    result = BUNSTF_RES_FRAMERESTART;
									nExamByte++;
								}
								else if( ( ECU_EOF == currentByte ) ||
								         ( ECU_ESC == currentByte ) )
								{
									/* Found and error, we were expecting raw negated data here.  */
									ctx->memAreaCntr = 0u;
                                    ctx->unStuffState = BUNSTF_SM_PRV_UNSTUFFFAIL;
									nExamByte++;
								}
								else
								{
									/* Received negated data */
									if( ctx->memAreaCntr >= ctx->memAreaSize )
									{
										/* No more data avaiable to save that thing */
										result = BUNSTF_RES_OUTOFMEM;
									}
									else
									{
										/* Is it true that negate data is present ? */
										if( ( ECU_SOF == ( ( uint8_t ) ~currentByte ) ) ||
											( ECU_EOF == ( ( uint8_t ) ~currentByte ) ) ||
											( ECU_ESC == ( ( uint8_t ) ~currentByte ) ) )
										{
											/* current data is neg */
											ctx->memArea[ctx->memAreaCntr] = ( uint8_t ) ( ~currentByte );
											ctx->unStuffState = BUNSTF_SM_PRV_NEEDRAWDATA;
											ctx->memAreaCntr++;
											nExamByte++;
										}
										else
										{
											/* Impossible receive a data after esc that is not SOF EOF or ESC neg */
											ctx->memAreaCntr = 0u;
                                            ctx->unStuffState = BUNSTF_SM_PRV_UNSTUFFFAIL;
											nExamByte++;
										}
									}
								}
								break;
							}

							default:
							{
								/* Impossible end here, and if so something horrible happened ( memory corruption ) */
								result = BUNSTF_RES_CORRUPTCTX;
								break;
							}
						}
                    }

					/* Save the result */
					*consumedStuffData = nExamByte;

					if( BUNSTF_RES_OK == result )
					{
						if( BUNSTF_SM_PRV_UNSTUFFEND == ctx->unStuffState )
						{
							result = BUNSTF_RES_FRAMEENDED;
						}
                        else if( BUNSTF_SM_PRV_UNSTUFFFAIL == ctx->unStuffState )
                        {
                           result = BUNSTF_RES_BADFRAME;
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

    return result;
}

/***********************************************************************************************************************
 *  PRIVATE FUNCTION
 **********************************************************************************************************************/
bool_t isBUSStatusStillCoherent(const s_eCU_BUNSTF_Ctx* ctx)
{
    bool_t result;

	/* Check basic context validity */
	if( ( ctx->memAreaSize <= 0u ) || ( NULL == ctx->memArea ) )
	{
		result = false;
	}
	else
	{
        /* Check size validity */
        if( ctx->memAreaCntr > ctx->memAreaSize )
        {
            result = false;
        }
        else
        {
            /* Check status coherence */
            if( ( BUNSTF_SM_PRV_NEEDSOF == ctx->unStuffState ) && ( 0u != ctx->memAreaCntr ) )
            {
                result = false;
            }
            else
            {
                /* Check status coherence */
                if( ( BUNSTF_SM_PRV_UNSTUFFEND == ctx->unStuffState ) && ( ctx->memAreaCntr <= 0u ) )
                {
                    result = false;
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
    #pragma cstat_restore = "CERT-INT30-C_b"
#endif


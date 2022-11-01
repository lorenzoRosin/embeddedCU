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
static bool_t isBUSStatusStillCoherent(const s_eCU_BUStuffCtx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_dBUStf_Res bUStufferInitCtx(s_eCU_BUStuffCtx* const ctx, uint8_t memArea[], const uint32_t memAreaSize)
{
	/* Local variable */
	e_eCU_dBUStf_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == memArea ) )
	{
		result = DBUSTF_RES_BADPOINTER;
	}
	else
	{
        /* Check data validity */
        if( memAreaSize <= 0u )
        {
            result = DBUSTF_RES_BADPARAM;
        }
        else
        {
            /* Initialize internal status */
            ctx->isInit = true;
            ctx->memArea = memArea;
            ctx->memAreaSize = memAreaSize;
            ctx->memAreaCntr = 0u;
            ctx->unStuffState = DBUSTF_SM_PRV_NEEDSOF;
            result = DBUSTF_RES_OK;
        }
	}

	return result;
}

e_eCU_dBUStf_Res bUStufferStartNewFrame(s_eCU_BUStuffCtx* const ctx)
{
	/* Local variable */
	e_eCU_dBUStf_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = DBUSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBUSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = DBUSTF_RES_CORRUPTCTX;
            }
            else
            {
                /* Update index */
                ctx->memAreaCntr = 0u;
				ctx->unStuffState = DBUSTF_SM_PRV_NEEDSOF;
                result = DBUSTF_RES_OK;
            }
		}
	}

	return result;
}

e_eCU_dBUStf_Res bUStufferGetUnstufData(s_eCU_BUStuffCtx* const ctx, uint8_t** dataP, uint32_t* const retrivedLen)
{
	/* Local variable */
	e_eCU_dBUStf_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataP ) || ( NULL == retrivedLen ) )
	{
		result = DBUSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBUSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = DBUSTF_RES_CORRUPTCTX;
            }
            else
            {
                *dataP = ctx->memArea;
                *retrivedLen =  ctx->memAreaCntr;
                result = DBUSTF_RES_OK;
            }
		}
	}

	return result;
}

e_eCU_dBUStf_Res bUStufferGetUnstufLen(s_eCU_BUStuffCtx* const ctx, uint32_t* const retrivedLen)
{
	/* Local variable */
	e_eCU_dBUStf_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == retrivedLen ) )
	{
		result = DBUSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBUSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = DBUSTF_RES_CORRUPTCTX;
            }
            else
            {
                *retrivedLen =  ctx->memAreaCntr;
                result = DBUSTF_RES_OK;
            }
		}
	}

	return result;
}

e_eCU_dBUStf_Res bUStufferIsWaitingSof(s_eCU_BUStuffCtx* const ctx, bool_t* const isWaitingSof)
{
	/* Local variable */
	e_eCU_dBUStf_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == isWaitingSof ) )
	{
		result = DBUSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBUSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = DBUSTF_RES_CORRUPTCTX;
            }
            else
            {
                if( DBUSTF_SM_PRV_NEEDSOF == ctx->unStuffState )
                {
                    *isWaitingSof = true;
                }
                else
                {
                    *isWaitingSof = false;
                }

                result = DBUSTF_RES_OK;
            }
		}
	}

	return result;
}
#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2012-Rule-8.13"
    /* Suppressed for code clarity */
#endif

e_eCU_dBUStf_Res bUStufferIsAFullFrameUnstuff(s_eCU_BUStuffCtx* const ctx, bool_t* const isFrameUnstuff)
{
	/* Local variable */
	e_eCU_dBUStf_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == isFrameUnstuff ) )
	{
		result = DBUSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBUSTF_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isBUSStatusStillCoherent(ctx) )
            {
                result = DBUSTF_RES_CORRUPTCTX;
            }
            else
            {
                if( DBUSTF_SM_PRV_UNSTUFFEND == ctx->unStuffState )
                {
                    *isFrameUnstuff = true;
                }
                else
                {
                    *isFrameUnstuff = false;
                }
                result = DBUSTF_RES_OK;
            }
		}
	}

	return result;
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2012-Rule-8.13"
#endif

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-17.4_b"
    /* Suppressed for code clarity */
#endif

e_eCU_dBUStf_Res bUStufferInsStufChunk(s_eCU_BUStuffCtx* const ctx, uint8_t stuffedArea[], const uint32_t stuffLen,
                                       uint32_t* const consumedStuffData, uint32_t* errSofRec)
{
	/* Local variable */
	e_eCU_dBUStf_Res result;
    uint32_t nExamByte;
    uint32_t nErrorFound;
    uint8_t currentByte;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == stuffedArea ) || ( NULL == consumedStuffData )|| ( NULL == errSofRec ) )
	{
		result = DBUSTF_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DBUSTF_RES_NOINITLIB;
		}
		else
		{
            if( stuffLen <= 0u )
            {
                result = DBUSTF_RES_BADPARAM;
            }
            else
            {
                /* Check internal status validity */
                if( false == isBUSStatusStillCoherent(ctx) )
                {
                    result = DBUSTF_RES_CORRUPTCTX;
                }
                else
                {
                    /* Init counter */
                    nExamByte = 0u;
                    nErrorFound = 0u;

                    /* Init result */
                    result = DBUSTF_RES_OK;

                    /* Elab all data */
                    while( ( nExamByte < stuffLen ) && ( DBUSTF_RES_OK == result ) &&
					       ( DBUSTF_SM_PRV_UNSTUFFEND != ctx->unStuffState ) )
                    {
                        /* Read current byte */
                        currentByte = stuffedArea[nExamByte];

                        /* Decide what to do */
						switch( ctx->unStuffState )
						{
							case DBUSTF_SM_PRV_NEEDSOF:
							{
								/* Wait SOF, discharge others */
								if( ECU_SOF == currentByte )
								{
									/* Found start */
									ctx->memAreaCntr = 0u;
									ctx->unStuffState = DBUSTF_SM_PRV_NEEDRAWDATA;
								}
								else
								{
									/* Waiting for start, no other bytes */
									ctx->memAreaCntr = 0u;
                                    nErrorFound += 1u;
								}
								nExamByte++;
								break;
							}

							case DBUSTF_SM_PRV_NEEDRAWDATA:
							{
								if( ECU_SOF == currentByte )
								{
									/* Found start, but wasn't expected */
									ctx->memAreaCntr = 0u;
									ctx->unStuffState = DBUSTF_SM_PRV_NEEDRAWDATA;
									nErrorFound += 1u;
									nExamByte++;
								}
								else if( ECU_EOF == currentByte )
								{
									if( ctx->memAreaCntr <= 0u )
									{
										/* Found end, but no data received..  */
										ctx->memAreaCntr = 0u;
										ctx->unStuffState = DBUSTF_SM_PRV_NEEDSOF;
										nErrorFound += 1u;
									}
									else
									{
										/* Can close the frame, yey */
										ctx->unStuffState = DBUSTF_SM_PRV_UNSTUFFEND;
									}

									nExamByte++;
								}
								else if( ECU_ESC == currentByte )
								{
									/* Next data will be negated data */
									ctx->unStuffState = DBUSTF_SM_PRV_NEEDNEGATEDATA;
									nExamByte++;
								}
								else
								{
									/* Received good raw data */
									if( ctx->memAreaCntr >= ctx->memAreaSize )
									{
										/* No more data avaiable to save that thing */
										result = DBUSTF_RES_OUTOFMEM;
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

							case DBUSTF_SM_PRV_NEEDNEGATEDATA:
							{
								if( ECU_SOF == currentByte )
								{
									/* Found start, but wasn't expected */
									ctx->memAreaCntr = 0u;
									ctx->unStuffState = DBUSTF_SM_PRV_NEEDRAWDATA;
									nErrorFound += 1u;
									nExamByte++;
								}
								else if( ( ECU_EOF == currentByte ) ||
								         ( ECU_ESC == currentByte ) )
								{
									/* Found and error, we were expecting raw negated data here.  */
									ctx->memAreaCntr = 0u;
									ctx->unStuffState = DBUSTF_SM_PRV_NEEDSOF;
									nErrorFound += 1u;
									nExamByte++;
								}
								else
								{
									/* Received negated data */
									if( ctx->memAreaCntr >= ctx->memAreaSize )
									{
										/* No more data avaiable to save that thing */
										result = DBUSTF_RES_OUTOFMEM;
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
											ctx->unStuffState = DBUSTF_SM_PRV_NEEDRAWDATA;
											ctx->memAreaCntr++;
											nExamByte++;
										}
										else
										{
											/* Impossible receive a data after esc that is not SOF EOF or ESC neg */
											ctx->memAreaCntr = 0u;
											ctx->unStuffState = DBUSTF_SM_PRV_NEEDSOF;
											nErrorFound += 1u;
											nExamByte++;
										}
									}
								}
								break;
							}

							default:
							{
								/* Impossible end here, and if so something horrible happened ( memory corruption ) */
								result = DBUSTF_RES_CORRUPTCTX;
								break;
							}
						}
                    }

					/* Save the result */
					*consumedStuffData = nExamByte;
                    *errSofRec = nErrorFound;

					if( DBUSTF_RES_OK == result )
					{
						if( DBUSTF_SM_PRV_UNSTUFFEND == ctx->unStuffState )
						{
							result = DBUSTF_RES_FRAMEENDED;
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
bool_t isBUSStatusStillCoherent(const s_eCU_BUStuffCtx* ctx)
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
            if( ( DBUSTF_SM_PRV_NEEDSOF == ctx->unStuffState ) && ( 0u != ctx->memAreaCntr ) )
            {
                result = false;
            }
            else
            {
                /* Check status coherence */
                if( ( DBUSTF_SM_PRV_UNSTUFFEND == ctx->unStuffState ) && ( ctx->memAreaCntr <= 0u ) )
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
    #pragma cstat_restore = "MISRAC2004-17.4_b"
#endif


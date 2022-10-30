/**
 * @file       eCUCircularQueue.c
 *
 * @brief      Circular Queue utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUCircularQueue.h"



/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t isQueueStatusStillCoherent(const s_eCU_circQCtx* ctx);
static uint32_t getoccupiedIndex(const s_eCU_circQCtx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_cQueue_Res circQInitCtx(s_eCU_circQCtx* const ctx, uint8_t memP[], const uint32_t memPSize)
{
	/* Local variable */
	e_eCU_cQueue_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL ==  memP ) )
	{
		result = CQUEUE_RES_BADPOINTER;
	}
	else
	{
		/* Check data validity */
		if( memPSize <= 0u )
		{
			result = CQUEUE_RES_BADPARAM;
		}
		else
		{
			/* Check Init */
			ctx->isInit = true;
			ctx->memP = memP;
			ctx->memPSize = memPSize;
			ctx->memPUsedSize = 0u;
			ctx->memPFreeIdx = 0u;

			result = CQUEUE_RES_OK;
		}
    }

	return result;
}

e_eCU_cQueue_Res circQReset(s_eCU_circQCtx* const ctx)
{
	/* Local variable */
	e_eCU_cQueue_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = CQUEUE_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = CQUEUE_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == isQueueStatusStillCoherent(ctx) )
            {
                result = CQUEUE_RES_CORRUPTCTX;
            }
            else
            {
                /* Update index in order to discharge all saved data */
                ctx->memPUsedSize = 0u;
                ctx->memPFreeIdx = 0u;

                result = CQUEUE_RES_OK;
            }
		}
    }

	return result;
}

e_eCU_cQueue_Res circQGetFreeSapce(s_eCU_circQCtx* const ctx, uint32_t* const freeSpace)
{
	/* Local variable */
	e_eCU_cQueue_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == freeSpace ) )
	{
		result = CQUEUE_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = CQUEUE_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == isQueueStatusStillCoherent(ctx) )
            {
                result = CQUEUE_RES_CORRUPTCTX;
            }
			else
			{
				*freeSpace = ctx->memPSize - ctx->memPUsedSize;
				result = CQUEUE_RES_OK;
			}
		}
    }

	return result;
}

e_eCU_cQueue_Res circQGetOccupiedSapce(s_eCU_circQCtx* const ctx, uint32_t* const usedSpace)
{
	/* Local variable */
	e_eCU_cQueue_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == usedSpace ) )
	{
		result = CQUEUE_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = CQUEUE_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == isQueueStatusStillCoherent(ctx) )
            {
                result = CQUEUE_RES_CORRUPTCTX;
            }
			else
			{
				*usedSpace = ctx->memPUsedSize;
				result = CQUEUE_RES_OK;
			}
		}
    }

	return result;
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-17.4_b"
    /* Suppressed for code clarity */
#endif

e_eCU_cQueue_Res circQInsertData(s_eCU_circQCtx* const ctx, const uint8_t data[], const uint32_t datalen)
{
	/* Local variable */
	e_eCU_cQueue_Res result;
	uint32_t freeSpace;
	uint32_t firstTranshLen;
	uint32_t secondTranshLen;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == data ) )
	{
		result = CQUEUE_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = CQUEUE_RES_NOINITLIB;
		}
		else
		{
			/* Check data validity */
			if( datalen <= 0u )
			{
				result = CQUEUE_RES_BADPARAM;
			}
			else
			{
                /* Check data coherence */
                if( false == isQueueStatusStillCoherent(ctx) )
                {
                    result = CQUEUE_RES_CORRUPTCTX;
                }
                else
                {
                    /* Check for free memory */
                    result = circQGetFreeSapce(ctx, &freeSpace);

                    if( CQUEUE_RES_OK == result )
                    {
                        if( datalen > freeSpace )
                        {
                            /* No memory avaiable */
                            result = CQUEUE_RES_FULL;
                        }
                        else
                        {
                            /* Can insert data */
                            if( ( datalen + ctx->memPFreeIdx ) <= ctx->memPSize )
                            {
                                /* Direct copy */
                                (void)memcpy(&ctx->memP[ctx->memPFreeIdx], data, datalen);

                                /* Update free index */
                                ctx->memPFreeIdx += datalen;
                                if( ctx->memPFreeIdx >= ctx->memPSize )
                                {
                                    ctx->memPFreeIdx = 0u;
                                }
                            }
                            else
                            {
                                /* Multicopy */

                                /* First round */
                                firstTranshLen = ctx->memPSize - ctx->memPFreeIdx;
                                (void)memcpy(&ctx->memP[ctx->memPFreeIdx], data, firstTranshLen);
                                ctx->memPFreeIdx = 0u;

                                /* Second round */
                                secondTranshLen = datalen - firstTranshLen;
                                (void)memcpy(&ctx->memP[ctx->memPFreeIdx], &data[firstTranshLen], secondTranshLen);
                                ctx->memPFreeIdx += secondTranshLen;
                            }

                            ctx->memPUsedSize += datalen;
                            result = CQUEUE_RES_OK;
                        }
                    }
                }
			}
		}
    }

	return result;
}

e_eCU_cQueue_Res circQRetriveData(s_eCU_circQCtx* const ctx, uint8_t data[], const uint32_t datalen)
{
	/* Local variable */
	e_eCU_cQueue_Res result;
	uint32_t usedSpace;
	uint32_t firstTranshLen;
	uint32_t secondTranshLen;
    uint32_t memPOccIdx;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == data ) )
	{
		result = CQUEUE_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = CQUEUE_RES_NOINITLIB;
		}
		else
		{
			/* Check data validity an queue integrity */
			if( datalen <= 0u )
			{
				result = CQUEUE_RES_BADPARAM;
			}
			else
			{
                /* Check data coherence */
                if( false == isQueueStatusStillCoherent(ctx) )
                {
                    result = CQUEUE_RES_CORRUPTCTX;
                }
                else
                {
                    result = circQGetOccupiedSapce(ctx, &usedSpace);
                    if( CQUEUE_RES_OK == result )
                    {
                        if( datalen > usedSpace )
                        {
                            /* No enoght data in the queue */
                            result = CQUEUE_RES_EMPTY;
                        }
                        else
                        {
                            /* Retrive occupied index */
                            memPOccIdx = getoccupiedIndex(ctx);

                            /* Can retrive data */
                            if( ( datalen +  memPOccIdx ) <= ctx->memPSize )
                            {
                                /* Direct copy */
                                (void)memcpy(data, &ctx->memP[memPOccIdx], datalen);
                            }
                            else
                            {
                                /* Multicopy */

                                /* First round */
                                firstTranshLen = ctx->memPSize - memPOccIdx;
                                (void)memcpy(data, &ctx->memP[memPOccIdx], firstTranshLen);
                                memPOccIdx = 0u;

                                /* Second round */
                                secondTranshLen = datalen - firstTranshLen;
                                (void)memcpy(&data[firstTranshLen], &ctx->memP[memPOccIdx], secondTranshLen);
                            }

                            ctx->memPUsedSize -= datalen;
                            result = CQUEUE_RES_OK;
                        }
                    }
                }
			}
		}
    }

	return result;
}

e_eCU_cQueue_Res circQPeekData(s_eCU_circQCtx* const ctx, uint8_t data[], const uint32_t datalen)
{
	/* Local variable */
	e_eCU_cQueue_Res result;
	uint32_t usedSpace;
	uint32_t firstTranshLen;
	uint32_t secondTranshLen;
    uint32_t memPOccIdx;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == data ) )
	{
		result = CQUEUE_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = CQUEUE_RES_NOINITLIB;
		}
		else
		{
			/* Check data validity an queue integrity */
			if( datalen <= 0u )
			{
				result = CQUEUE_RES_BADPARAM;
			}
			else
			{
                /* Check data coherence */
                if( false == isQueueStatusStillCoherent(ctx) )
                {
                    result = CQUEUE_RES_CORRUPTCTX;
                }
                else
                {
                    result = circQGetOccupiedSapce(ctx, &usedSpace);
                    if( CQUEUE_RES_OK == result )
                    {
                        if( datalen > usedSpace )
                        {
                            /* No enoght data in the queue */
                            result = CQUEUE_RES_EMPTY;
                        }
                        else
                        {
                            /* Retrive occupied index */
                            memPOccIdx = getoccupiedIndex(ctx);

                            /* Can retrive data */
                            if( ( datalen +  memPOccIdx ) <= ctx->memPSize )
                            {
                                /* Direct copy */
                                (void)memcpy(data, &ctx->memP[memPOccIdx], datalen);
                            }
                            else
                            {
                                /* Multicopy */

                                /* First round */
                                firstTranshLen = ctx->memPSize - memPOccIdx;
                                (void)memcpy(data, &ctx->memP[memPOccIdx], firstTranshLen);
                                memPOccIdx = 0u;

                                /* Second round */
                                secondTranshLen = datalen - firstTranshLen;
                                (void)memcpy(&data[firstTranshLen], &ctx->memP[memPOccIdx], secondTranshLen);
                            }

                            result = CQUEUE_RES_OK;
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

/***********************************************************************************************************************
 *  PRIVATE FUNCTION
 **********************************************************************************************************************/
bool_t isQueueStatusStillCoherent(const s_eCU_circQCtx* ctx)
{
    bool_t result;

	/* Check context validity */
	if( ( ctx->memPSize <= 0u ) || ( NULL == ctx->memP ) )
	{
		result = false;
	}
	else
	{
		/* we cannot have more data than data size */
		if( ctx->memPUsedSize > ctx->memPSize )
		{
			result = false;
		}
		else
		{
            /* Cannot go beyond limits */
            if( ctx->memPFreeIdx >= ctx->memPSize )
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

uint32_t getoccupiedIndex(const s_eCU_circQCtx* ctx)
{
    uint32_t occIndx;

    if( ctx->memPUsedSize <= ctx->memPFreeIdx )
    {
        occIndx = ctx->memPFreeIdx - ctx->memPUsedSize;
    }
    else
    {
        occIndx = ctx->memPSize - ( ctx->memPUsedSize - ctx->memPFreeIdx );
    }

    return occIndx;
}
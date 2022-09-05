/**
 * @file eCUCircularQueue.c
 *
 */

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUCircularQueue.h"



/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t isQueueStatusStillCoherent(const s_eCU_circQCtx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_cQueue_Res circQInitCtx(s_eCU_circQCtx* const ctx, uint8_t* memPool, const uint32_t memPoolSize)
{
	/* Local variable */
	e_eCU_cQueue_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx) || ( NULL ==  memPool) )
	{
		result = CQUEUE_RES_BADPOINTER;
	}
	else
	{
		/* Check data validity */
		if( memPoolSize <= 0u )
		{
			result = CQUEUE_RES_BADPARAM;
		}
		else
		{
			/* Check Init */
			ctx->isInit = true;
			ctx->memPool = memPool;
			ctx->memPoolSize = memPoolSize;
			ctx->memPoolUsedSize = 0u;
			ctx->memPoolFrstFreeIdx = 0u;
			ctx->memPoolFrstOccIdx = 0u;

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
                ctx->memPoolUsedSize = 0u;
                ctx->memPoolFrstFreeIdx = 0u;
                ctx->memPoolFrstOccIdx = 0u;
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
				*freeSpace = ctx->memPoolSize - ctx->memPoolUsedSize;
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
				*usedSpace = ctx->memPoolUsedSize;
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

e_eCU_cQueue_Res circQInsertData(s_eCU_circQCtx* const ctx, const uint8_t* data, const uint32_t datalen)
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
                            if( ( datalen +  ctx->memPoolFrstFreeIdx ) <= ctx->memPoolSize )
                            {
                                /* Direct copy */
                                (void)memcpy(&ctx->memPool[ctx->memPoolFrstFreeIdx], data, datalen);

                                /* Update free index */
                                ctx->memPoolFrstFreeIdx += datalen;
                                if(ctx->memPoolFrstFreeIdx >= ctx->memPoolSize)
                                {
                                    ctx->memPoolFrstFreeIdx = 0u;
                                }
                            }
                            else
                            {
                                /* Multicopy */

                                /* First round */
                                firstTranshLen = ctx->memPoolSize - ctx->memPoolFrstFreeIdx;
                                (void)memcpy(&ctx->memPool[ctx->memPoolFrstFreeIdx], data, firstTranshLen);
                                ctx->memPoolFrstFreeIdx = 0u;

                                /* Second round */
                                secondTranshLen = datalen - firstTranshLen;
                                (void)memcpy(&ctx->memPool[ctx->memPoolFrstFreeIdx], &data[firstTranshLen], secondTranshLen);
                                ctx->memPoolFrstFreeIdx += secondTranshLen;
                            }

                            ctx->memPoolUsedSize += datalen;
                            result = CQUEUE_RES_OK;
                        }
                    }
                }
			}
		}
    }

	return result;
}

e_eCU_cQueue_Res circQRetriveData(s_eCU_circQCtx* const ctx, uint8_t* const data, const uint32_t datalen)
{
	/* Local variable */
	e_eCU_cQueue_Res result;
	uint32_t usedSpace;
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
                        if( datalen > usedSpace)
                        {
                            /* No enoght data in the queue */
                            result = CQUEUE_RES_EMPTY;
                        }
                        else
                        {
                            /* Can retrive data */
                            if( ( datalen +  ctx->memPoolFrstOccIdx ) <= ctx->memPoolSize )
                            {
                                /* Direct copy */
                                (void)memcpy(data, &ctx->memPool[ctx->memPoolFrstOccIdx], datalen);

                                /* Update used index */
                                ctx->memPoolFrstOccIdx += datalen;
                                if(ctx->memPoolFrstOccIdx >= ctx->memPoolSize)
                                {
                                    ctx->memPoolFrstOccIdx = 0u;
                                }
                            }
                            else
                            {
                                /* Multicopy */

                                /* First round */
                                firstTranshLen = ctx->memPoolSize - ctx->memPoolFrstOccIdx;
                                (void)memcpy(data, &ctx->memPool[ctx->memPoolFrstOccIdx], firstTranshLen);
                                ctx->memPoolFrstOccIdx = 0u;

                                /* Second round */
                                secondTranshLen = datalen - firstTranshLen;
                                (void)memcpy(&data[firstTranshLen], &ctx->memPool[ctx->memPoolFrstOccIdx], secondTranshLen);
                                ctx->memPoolFrstOccIdx += secondTranshLen;
                            }

                            ctx->memPoolUsedSize -= datalen;
                            result = CQUEUE_RES_OK;
                        }
                    }
                }
			}
		}
    }

	return result;
}

e_eCU_cQueue_Res circQPeekData(s_eCU_circQCtx* const ctx, uint8_t* const data, const uint32_t datalen)
{
	/* Local variable */
	e_eCU_cQueue_Res result;
	uint32_t usedSpace;
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
                        if( datalen > usedSpace)
                        {
                            /* No enoght data in the queue */
                            result = CQUEUE_RES_EMPTY;
                        }
                        else
                        {
                            /* Can retrive data */
                            if( ( datalen +  ctx->memPoolFrstOccIdx ) <= ctx->memPoolSize )
                            {
                                /* Direct copy */
                                (void)memcpy(data, &ctx->memPool[ctx->memPoolFrstOccIdx], datalen);
                            }
                            else
                            {
                                /* Multicopy */

                                /* First round */
                                firstTranshLen = ctx->memPoolSize - ctx->memPoolFrstOccIdx;
                                (void)memcpy(data, &ctx->memPool[ctx->memPoolFrstOccIdx], firstTranshLen);

                                /* Second round */
                                secondTranshLen = datalen - firstTranshLen;
                                (void)memcpy(&data[firstTranshLen], &ctx->memPool[0u], secondTranshLen);
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
	if( ( ctx->memPoolSize <= 0u ) || ( NULL == ctx->memPool ) )
	{
		result = false;
	}
	else
	{
		/* Check queue data coherence */
		if( ( ctx->memPoolFrstFreeIdx >= ctx->memPoolSize ) || ( ctx->memPoolFrstOccIdx >= ctx->memPoolSize ) ||
		    ( ctx->memPoolSize < ctx->memPoolUsedSize ) )
		{
			result = false;
		}
		else
		{
            result = true;
		}
	}

    return result;
}
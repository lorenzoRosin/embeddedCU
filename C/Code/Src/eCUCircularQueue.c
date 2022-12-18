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
static bool_t eCU_CIRQ_isStatusStillCoherent(const s_eCU_CIRQ_Ctx* p_ctx);
static uint32_t eCU_CIRQ_getoccupiedIndex(const s_eCU_CIRQ_Ctx* p_ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_CIRQ_Res eCU_CIRQ_InitCtx(s_eCU_CIRQ_Ctx* const p_ctx, uint8_t* a_memP, const uint32_t memPSize)
{
	/* Local variable */
	e_eCU_CIRQ_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL ==  a_memP ) )
	{
		l_result = CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check data validity */
		if( memPSize <= 0u )
		{
			l_result = CIRQ_RES_BADPARAM;
		}
		else
		{
			/* Check Init */
			p_ctx->isInit = true;
			p_ctx->p_memP = a_memP;
			p_ctx->memPSize = memPSize;
			p_ctx->memPUsedSize = 0u;
			p_ctx->memPFreeIdx = 0u;

			l_result = CIRQ_RES_OK;
		}
    }

	return l_result;
}

e_eCU_CIRQ_Res eCU_CIRQ_IsInit(s_eCU_CIRQ_Ctx* const p_ctx, bool_t* p_isInit)
{
	/* Local variable */
	e_eCU_CIRQ_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isInit ) )
	{
		l_result = CIRQ_RES_BADPOINTER;
	}
	else
	{
        *p_isInit = p_ctx->isInit;
        l_result = CIRQ_RES_OK;
	}

	return l_result;
}

e_eCU_CIRQ_Res eCU_CIRQ_Reset(s_eCU_CIRQ_Ctx* const p_ctx)
{
	/* Local variable */
	e_eCU_CIRQ_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = CIRQ_RES_CORRUPTCTX;
            }
            else
            {
                /* Update index in order to discharge all saved data */
                p_ctx->memPUsedSize = 0u;
                p_ctx->memPFreeIdx = 0u;

                l_result = CIRQ_RES_OK;
            }
		}
    }

	return l_result;
}

e_eCU_CIRQ_Res eCU_CIRQ_GetFreeSapce(s_eCU_CIRQ_Ctx* const p_ctx, uint32_t* const p_freeSpace)
{
	/* Local variable */
	e_eCU_CIRQ_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_freeSpace ) )
	{
		l_result = CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = CIRQ_RES_CORRUPTCTX;
            }
			else
			{
				*p_freeSpace = p_ctx->memPSize - p_ctx->memPUsedSize;
				l_result = CIRQ_RES_OK;
			}
		}
    }

	return l_result;
}

e_eCU_CIRQ_Res eCU_CIRQ_GetOccupiedSapce(s_eCU_CIRQ_Ctx* const p_ctx, uint32_t* const p_usedSpace)
{
	/* Local variable */
	e_eCU_CIRQ_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_usedSpace ) )
	{
		l_result = CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = CIRQ_RES_CORRUPTCTX;
            }
			else
			{
				*p_usedSpace = p_ctx->memPUsedSize;
				l_result = CIRQ_RES_OK;
			}
		}
    }

	return l_result;
}

e_eCU_CIRQ_Res eCU_CIRQ_InsertData(s_eCU_CIRQ_Ctx* const p_ctx, const uint8_t* a_data, const uint32_t datalen)
{
	/* Local variable */
	e_eCU_CIRQ_Res l_result;
	uint32_t l_freeSpace;
	uint32_t l_firstLen;
	uint32_t l_secondLen;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == a_data ) )
	{
		l_result = CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = CIRQ_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity */
                if( datalen <= 0u )
                {
                    l_result = CIRQ_RES_BADPARAM;
                }
                else
                {
                    l_freeSpace = p_ctx->memPSize - p_ctx->memPUsedSize;
                    if( datalen > l_freeSpace )
                    {
                        /* No memory avaiable */
                        l_result = CIRQ_RES_FULL;
                    }
                    else
                    {
                        /* Can insert data */
                        if( ( datalen + p_ctx->memPFreeIdx ) <= p_ctx->memPSize )
                        {
                            /* Direct copy */
                            (void)memcpy(&p_ctx->p_memP[p_ctx->memPFreeIdx], a_data, datalen);

                            /* Update free index */
                            p_ctx->memPFreeIdx += datalen;
                            if( p_ctx->memPFreeIdx >= p_ctx->memPSize )
                            {
                                p_ctx->memPFreeIdx = 0u;
                            }
                        }
                        else
                        {
                            /* Multicopy */

                            /* First round */
                            l_firstLen = p_ctx->memPSize - p_ctx->memPFreeIdx;
                            (void)memcpy(&p_ctx->p_memP[p_ctx->memPFreeIdx], a_data, l_firstLen);
                            p_ctx->memPFreeIdx = 0u;

                            /* Second round */
                            l_secondLen = datalen - l_firstLen;
                            (void)memcpy(&p_ctx->p_memP[p_ctx->memPFreeIdx], &a_data[l_firstLen], l_secondLen);
                            p_ctx->memPFreeIdx += l_secondLen;
                        }

                        p_ctx->memPUsedSize += datalen;
                        l_result = CIRQ_RES_OK;
                    }
                }
			}
		}
    }

	return l_result;
}

e_eCU_CIRQ_Res eCU_CIRQ_RetriveData(s_eCU_CIRQ_Ctx* const p_ctx, uint8_t* a_data, const uint32_t datalen)
{
	/* Local variable */
	e_eCU_CIRQ_Res l_result;
	uint32_t l_firstLen;
	uint32_t l_secondLen;
    uint32_t l_memPOccIdx;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == a_data ) )
	{
		l_result = CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = CIRQ_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity an queue integrity */
                if( datalen <= 0u )
                {
                    l_result = CIRQ_RES_BADPARAM;
                }
                else
                {
                    if( datalen > p_ctx->memPUsedSize )
                    {
                        /* No enoght data in the queue */
                        l_result = CIRQ_RES_EMPTY;
                    }
                    else
                    {
                        /* Retrive occupied index */
                        l_memPOccIdx = eCU_CIRQ_getoccupiedIndex(p_ctx);

                        /* Can retrive data */
                        if( ( datalen +  l_memPOccIdx ) <= p_ctx->memPSize )
                        {
                            /* Direct copy */
                            (void)memcpy(a_data, &p_ctx->p_memP[l_memPOccIdx], datalen);
                        }
                        else
                        {
                            /* Multicopy */

                            /* First round */
                            l_firstLen = p_ctx->memPSize - l_memPOccIdx;
                            (void)memcpy(a_data, &p_ctx->p_memP[l_memPOccIdx], l_firstLen);
                            l_memPOccIdx = 0u;

                            /* Second round */
                            l_secondLen = datalen - l_firstLen;
                            (void)memcpy(&a_data[l_firstLen], &p_ctx->p_memP[l_memPOccIdx], l_secondLen);
                        }

                        p_ctx->memPUsedSize -= datalen;
                        l_result = CIRQ_RES_OK;
                    }
                }
			}
		}
    }

	return l_result;
}

e_eCU_CIRQ_Res eCU_CIRQ_PeekData(s_eCU_CIRQ_Ctx* const p_ctx, uint8_t* a_data, const uint32_t datalen)
{
	/* Local variable */
	e_eCU_CIRQ_Res l_result;
	uint32_t l_firstLen;
	uint32_t l_secondLen;
    uint32_t l_memPOccIdx;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == a_data ) )
	{
		l_result = CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = CIRQ_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity an queue integrity */
                if( datalen <= 0u )
                {
                    l_result = CIRQ_RES_BADPARAM;
                }
                else
                {
                    if( datalen > p_ctx->memPUsedSize )
                    {
                        /* No enoght data in the queue */
                        l_result = CIRQ_RES_EMPTY;
                    }
                    else
                    {
                        /* Retrive occupied index */
                        l_memPOccIdx = eCU_CIRQ_getoccupiedIndex(p_ctx);

                        /* Can retrive data */
                        if( ( datalen +  l_memPOccIdx ) <= p_ctx->memPSize )
                        {
                            /* Direct copy */
                            (void)memcpy(a_data, &p_ctx->p_memP[l_memPOccIdx], datalen);
                        }
                        else
                        {
                            /* Multicopy */

                            /* First round */
                            l_firstLen = p_ctx->memPSize - l_memPOccIdx;
                            (void)memcpy(a_data, &p_ctx->p_memP[l_memPOccIdx], l_firstLen);
                            l_memPOccIdx = 0u;

                            /* Second round */
                            l_secondLen = datalen - l_firstLen;
                            (void)memcpy(&a_data[l_firstLen], &p_ctx->p_memP[l_memPOccIdx], l_secondLen);
                        }

                        l_result = CIRQ_RES_OK;
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
static bool_t eCU_CIRQ_isStatusStillCoherent(const s_eCU_CIRQ_Ctx* p_ctx)
{
    bool_t l_result;

	/* Check context validity */
	if( ( p_ctx->memPSize <= 0u ) || ( NULL == p_ctx->p_memP ) )
	{
		l_result = false;
	}
	else
	{
		/* we cannot have more data than data size */
		if( p_ctx->memPUsedSize > p_ctx->memPSize )
		{
			l_result = false;
		}
		else
		{
            /* Cannot go beyond limits */
            if( p_ctx->memPFreeIdx >= p_ctx->memPSize )
            {
                l_result = false;
            }
            else
            {
                l_result = true;
            }
		}
	}

    return l_result;
}

static uint32_t eCU_CIRQ_getoccupiedIndex(const s_eCU_CIRQ_Ctx* p_ctx)
{
    uint32_t l_occIndx;

    if( p_ctx->memPUsedSize <= p_ctx->memPFreeIdx )
    {
        l_occIndx = p_ctx->memPFreeIdx - p_ctx->memPUsedSize;
    }
    else
    {
        l_occIndx = p_ctx->memPSize - ( p_ctx->memPUsedSize - p_ctx->memPFreeIdx );
    }

    return l_occIndx;
}
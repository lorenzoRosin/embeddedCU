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
static bool_t eCU_CIRQ_isStatusStillCoherent(const t_eCU_CIRQ_Ctx* p_ctx);
static uint32_t eCU_CIRQ_getoccupiedIndex(const t_eCU_CIRQ_Ctx* p_ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_CIRQ_RES eCU_CIRQ_InitCtx(t_eCU_CIRQ_Ctx* const p_ctx, uint8_t* puBuff, const uint32_t uBuffL)
{
	/* Local variable */
	e_eCU_CIRQ_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL ==  puBuff ) )
	{
		l_result = e_eCU_CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check data validity */
		if( uBuffL <= 0u )
		{
			l_result = e_eCU_CIRQ_RES_BADPARAM;
		}
		else
		{
			/* Check Init */
			p_ctx->bIsInit = true;
			p_ctx->puBuff = puBuff;
			p_ctx->uBuffL = uBuffL;
			p_ctx->uBuffUsedL = 0u;
			p_ctx->uBuffFreeIdx = 0u;

			l_result = e_eCU_CIRQ_RES_OK;
		}
    }

	return l_result;
}

e_eCU_CIRQ_RES eCU_CIRQ_IsInit(t_eCU_CIRQ_Ctx* const p_ctx, bool_t* p_isInit)
{
	/* Local variable */
	e_eCU_CIRQ_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isInit ) )
	{
		l_result = e_eCU_CIRQ_RES_BADPOINTER;
	}
	else
	{
        *p_isInit = p_ctx->bIsInit;
        l_result = e_eCU_CIRQ_RES_OK;
	}

	return l_result;
}

e_eCU_CIRQ_RES eCU_CIRQ_Reset(t_eCU_CIRQ_Ctx* const p_ctx)
{
	/* Local variable */
	e_eCU_CIRQ_RES l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = e_eCU_CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_CIRQ_RES_CORRUPTCTX;
            }
            else
            {
                /* Update index in order to discharge all saved data */
                p_ctx->uBuffUsedL = 0u;
                p_ctx->uBuffFreeIdx = 0u;

                l_result = e_eCU_CIRQ_RES_OK;
            }
		}
    }

	return l_result;
}

e_eCU_CIRQ_RES eCU_CIRQ_GetFreeSapce(t_eCU_CIRQ_Ctx* const p_ctx, uint32_t* const p_freeSpace)
{
	/* Local variable */
	e_eCU_CIRQ_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_freeSpace ) )
	{
		l_result = e_eCU_CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_CIRQ_RES_CORRUPTCTX;
            }
			else
			{
				*p_freeSpace = p_ctx->uBuffL - p_ctx->uBuffUsedL;
				l_result = e_eCU_CIRQ_RES_OK;
			}
		}
    }

	return l_result;
}

e_eCU_CIRQ_RES eCU_CIRQ_GetOccupiedSapce(t_eCU_CIRQ_Ctx* const p_ctx, uint32_t* const p_usedSpace)
{
	/* Local variable */
	e_eCU_CIRQ_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_usedSpace ) )
	{
		l_result = e_eCU_CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_CIRQ_RES_CORRUPTCTX;
            }
			else
			{
				*p_usedSpace = p_ctx->uBuffUsedL;
				l_result = e_eCU_CIRQ_RES_OK;
			}
		}
    }

	return l_result;
}

e_eCU_CIRQ_RES eCU_CIRQ_InsertData(t_eCU_CIRQ_Ctx* const p_ctx, const uint8_t* p_data, const uint32_t datalen)
{
	/* Local variable */
	e_eCU_CIRQ_RES l_result;
	uint32_t l_freeSpace;
	uint32_t l_firstLen;
	uint32_t l_secondLen;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_data ) )
	{
		l_result = e_eCU_CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_CIRQ_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity */
                if( datalen <= 0u )
                {
                    l_result = e_eCU_CIRQ_RES_BADPARAM;
                }
                else
                {
                    l_freeSpace = p_ctx->uBuffL - p_ctx->uBuffUsedL;
                    if( datalen > l_freeSpace )
                    {
                        /* No memory avaiable */
                        l_result = CIRQ_RES_FULL;
                    }
                    else
                    {
                        /* Can insert data */
                        if( ( datalen + p_ctx->uBuffFreeIdx ) <= p_ctx->uBuffL )
                        {
                            /* Direct copy */
                            (void)memcpy(&p_ctx->puBuff[p_ctx->uBuffFreeIdx], p_data, datalen);

                            /* Update free index */
                            p_ctx->uBuffFreeIdx += datalen;
                            if( p_ctx->uBuffFreeIdx >= p_ctx->uBuffL )
                            {
                                p_ctx->uBuffFreeIdx = 0u;
                            }
                        }
                        else
                        {
                            /* Multicopy */

                            /* First round */
                            l_firstLen = p_ctx->uBuffL - p_ctx->uBuffFreeIdx;
                            (void)memcpy(&p_ctx->puBuff[p_ctx->uBuffFreeIdx], p_data, l_firstLen);
                            p_ctx->uBuffFreeIdx = 0u;

                            /* Second round */
                            l_secondLen = datalen - l_firstLen;
                            (void)memcpy(&p_ctx->puBuff[p_ctx->uBuffFreeIdx], &p_data[l_firstLen], l_secondLen);
                            p_ctx->uBuffFreeIdx += l_secondLen;
                        }

                        p_ctx->uBuffUsedL += datalen;
                        l_result = e_eCU_CIRQ_RES_OK;
                    }
                }
			}
		}
    }

	return l_result;
}

e_eCU_CIRQ_RES eCU_CIRQ_RetriveData(t_eCU_CIRQ_Ctx* const p_ctx, uint8_t* p_data, const uint32_t datalen)
{
	/* Local variable */
	e_eCU_CIRQ_RES l_result;
	uint32_t l_firstLen;
	uint32_t l_secondLen;
    uint32_t l_memPOccIdx;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_data ) )
	{
		l_result = e_eCU_CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_CIRQ_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity an queue integrity */
                if( datalen <= 0u )
                {
                    l_result = e_eCU_CIRQ_RES_BADPARAM;
                }
                else
                {
                    if( datalen > p_ctx->uBuffUsedL )
                    {
                        /* No enoght data in the queue */
                        l_result = e_eCU_CIRQ_RES_EMPTY;
                    }
                    else
                    {
                        /* Retrive occupied index */
                        l_memPOccIdx = eCU_CIRQ_getoccupiedIndex(p_ctx);

                        /* Can retrive data */
                        if( ( datalen +  l_memPOccIdx ) <= p_ctx->uBuffL )
                        {
                            /* Direct copy */
                            (void)memcpy(p_data, &p_ctx->puBuff[l_memPOccIdx], datalen);
                        }
                        else
                        {
                            /* Multicopy */

                            /* First round */
                            l_firstLen = p_ctx->uBuffL - l_memPOccIdx;
                            (void)memcpy(p_data, &p_ctx->puBuff[l_memPOccIdx], l_firstLen);
                            l_memPOccIdx = 0u;

                            /* Second round */
                            l_secondLen = datalen - l_firstLen;
                            (void)memcpy(&p_data[l_firstLen], &p_ctx->puBuff[l_memPOccIdx], l_secondLen);
                        }

                        p_ctx->uBuffUsedL -= datalen;
                        l_result = e_eCU_CIRQ_RES_OK;
                    }
                }
			}
		}
    }

	return l_result;
}

e_eCU_CIRQ_RES eCU_CIRQ_PeekData(t_eCU_CIRQ_Ctx* const p_ctx, uint8_t* p_data, const uint32_t datalen)
{
	/* Local variable */
	e_eCU_CIRQ_RES l_result;
	uint32_t l_firstLen;
	uint32_t l_secondLen;
    uint32_t l_memPOccIdx;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_data ) )
	{
		l_result = e_eCU_CIRQ_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_CIRQ_RES_NOINITLIB;
		}
		else
		{
            /* Check data coherence */
            if( false == eCU_CIRQ_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_CIRQ_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity an queue integrity */
                if( datalen <= 0u )
                {
                    l_result = e_eCU_CIRQ_RES_BADPARAM;
                }
                else
                {
                    if( datalen > p_ctx->uBuffUsedL )
                    {
                        /* No enoght data in the queue */
                        l_result = e_eCU_CIRQ_RES_EMPTY;
                    }
                    else
                    {
                        /* Retrive occupied index */
                        l_memPOccIdx = eCU_CIRQ_getoccupiedIndex(p_ctx);

                        /* Can retrive data */
                        if( ( datalen +  l_memPOccIdx ) <= p_ctx->uBuffL )
                        {
                            /* Direct copy */
                            (void)memcpy(p_data, &p_ctx->puBuff[l_memPOccIdx], datalen);
                        }
                        else
                        {
                            /* Multicopy */

                            /* First round */
                            l_firstLen = p_ctx->uBuffL - l_memPOccIdx;
                            (void)memcpy(p_data, &p_ctx->puBuff[l_memPOccIdx], l_firstLen);
                            l_memPOccIdx = 0u;

                            /* Second round */
                            l_secondLen = datalen - l_firstLen;
                            (void)memcpy(&p_data[l_firstLen], &p_ctx->puBuff[l_memPOccIdx], l_secondLen);
                        }

                        l_result = e_eCU_CIRQ_RES_OK;
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
static bool_t eCU_CIRQ_isStatusStillCoherent(const t_eCU_CIRQ_Ctx* p_ctx)
{
    bool_t l_result;

	/* Check context validity */
	if( ( p_ctx->uBuffL <= 0u ) || ( NULL == p_ctx->puBuff ) )
	{
		l_result = false;
	}
	else
	{
		/* we cannot have more data than data size */
		if( p_ctx->uBuffUsedL > p_ctx->uBuffL )
		{
			l_result = false;
		}
		else
		{
            /* Cannot go beyond limits */
            if( p_ctx->uBuffFreeIdx >= p_ctx->uBuffL )
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

static uint32_t eCU_CIRQ_getoccupiedIndex(const t_eCU_CIRQ_Ctx* p_ctx)
{
    uint32_t l_occIndx;

    if( p_ctx->uBuffUsedL <= p_ctx->uBuffFreeIdx )
    {
        l_occIndx = p_ctx->uBuffFreeIdx - p_ctx->uBuffUsedL;
    }
    else
    {
        l_occIndx = p_ctx->uBuffL - ( p_ctx->uBuffUsedL - p_ctx->uBuffFreeIdx );
    }

    return l_occIndx;
}
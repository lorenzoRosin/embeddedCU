/**
 * @file       eCUDataUnPack.c
 *
 * @brief      Data pack utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataUnPack.h"



/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t eCU_DUNPK_isStatusStillCoherent(const s_eCU_DUNPK_Ctx* p_ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_DUNPK_Res eCU_DUNPK_InitCtx(s_eCU_DUNPK_Ctx* const p_ctx, uint8_t a_memUPKA[], const uint32_t memUPKASize,
                                  const bool_t isLEnd)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL ==  a_memUPKA ) )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
		/* Check data validity */
		if( memUPKASize <= 0u )
		{
			result = DUNPK_RES_BADPARAM;
		}
		else
		{
            p_ctx->isInit = true;
            p_ctx->isLE = isLEnd;
            p_ctx->p_memUPKA = a_memUPKA;
            p_ctx->memUPKASize = memUPKASize;
            p_ctx->memUPKAFrameSize = 0u;
            p_ctx->memUPKACntr = 0u;

            result = DUNPK_RES_OK;
		}
    }

	return result;
}

e_eCU_DUNPK_Res eCU_DUNPK_IsInit(s_eCU_DUNPK_Ctx* const p_ctx, bool_t* p_isInit)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isInit ) )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
        *p_isInit = p_ctx->isInit;
        result = DUNPK_RES_OK;
	}

	return result;
}

e_eCU_DUNPK_Res eCU_DUNPK_StartNewFrame(s_eCU_DUNPK_Ctx* const p_ctx, const uint32_t frameLen)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			result = DUNPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DUNPK_isStatusStillCoherent(p_ctx) )
            {
                result = DUNPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check param validity */
                if( ( frameLen <= 0u ) || ( frameLen > p_ctx->memUPKASize ) )
                {
                    result = DUNPK_RES_BADPARAM;
                }
                else
                {
                    /* Update data */
                    p_ctx->memUPKAFrameSize = frameLen;
                    p_ctx->memUPKACntr = 0u;
                    result = DUNPK_RES_OK;
                }
            }
		}
	}

	return result;
}

e_eCU_DUNPK_Res eCU_DUNPK_GetUPkDataLocat(s_eCU_DUNPK_Ctx* const p_ctx, uint8_t** pp_data,
                                          uint32_t* const p_maxDataSize)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == pp_data ) || ( NULL == p_maxDataSize ) )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			result = DUNPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DUNPK_isStatusStillCoherent(p_ctx) )
            {
                result = DUNPK_RES_CORRUPTCTX;
            }
            else
            {
                /* return data */
                *pp_data = p_ctx->p_memUPKA;
                *p_maxDataSize = p_ctx->memUPKASize;
                result = DUNPK_RES_OK;
            }
		}
	}

	return result;
}

e_eCU_DUNPK_Res eCU_DUNPK_RestartCurrentUnpack(s_eCU_DUNPK_Ctx* const p_ctx)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			result = DUNPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DUNPK_isStatusStillCoherent(p_ctx) )
            {
                result = DUNPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check Init */
                if( p_ctx->memUPKAFrameSize <= 0u )
                {
                    result = DUNPK_RES_NOINITFRAME;
                }
                else
                {
                    /* Update index */
                    p_ctx->memUPKACntr = 0u;
                    result = DUNPK_RES_OK;
                }
            }
		}
    }

	return result;
}

e_eCU_DUNPK_Res eCU_DUNPK_GetRemToPop(s_eCU_DUNPK_Ctx* const p_ctx, uint32_t* const p_retrivedLen)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_retrivedLen ) )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			result = DUNPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DUNPK_isStatusStillCoherent(p_ctx) )
            {
                /* We have removed more data that we had */
                result = DUNPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check Init */
                if( p_ctx->memUPKAFrameSize <= 0u )
                {
                    result = DUNPK_RES_NOINITFRAME;
                }
                else
                {
                    *p_retrivedLen = p_ctx->memUPKAFrameSize - p_ctx->memUPKACntr;
                    result = DUNPK_RES_OK;
                }
            }
		}
    }

	return result;
}

e_eCU_DUNPK_Res eCU_DUNPK_PopArray(s_eCU_DUNPK_Ctx* const p_ctx, uint8_t a_dataDest[], uint32_t const p_toRetrivedLen)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == a_dataDest ) )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			result = DUNPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DUNPK_isStatusStillCoherent(p_ctx) )
            {
                result = DUNPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check Init */
                if( p_ctx->memUPKAFrameSize <= 0u )
                {
                    result = DUNPK_RES_NOINITFRAME;
                }
                else
                {
                    /* Check data validity */
                    if( p_toRetrivedLen <= 0u )
                    {
                        /* We have removed more data that we had */
                        result = DUNPK_RES_BADPARAM;
                    }
                    else
                    {
                        /* Check if we can pop that amount */
                        if( ( p_ctx->memUPKACntr + p_toRetrivedLen ) > p_ctx->memUPKAFrameSize )
                        {
                            result = DUNPK_RES_NODATA;
                        }
                        else
                        {
                            /* Copy data */
                            (void)memcpy(a_dataDest, &p_ctx->p_memUPKA[p_ctx->memUPKACntr], p_toRetrivedLen);

                            /* Update index */
                            p_ctx->memUPKACntr += p_toRetrivedLen;
                            result = DUNPK_RES_OK;
                        }
                    }
                }
            }
		}
    }

	return result;
}

e_eCU_DUNPK_Res eCU_DUNPK_PopU8(s_eCU_DUNPK_Ctx* const p_ctx, uint8_t *p_dataP)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_dataP ) )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			result = DUNPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DUNPK_isStatusStillCoherent(p_ctx) )
            {
                result = DUNPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check Init */
                if( p_ctx->memUPKAFrameSize <= 0u )
                {
                    result = DUNPK_RES_NOINITFRAME;
                }
                else
                {
                    /* Check if we can pop that amount */
                    if( ( p_ctx->memUPKACntr + sizeof(uint8_t) ) > p_ctx->memUPKAFrameSize )
                    {
                        result = DUNPK_RES_NODATA;
                    }
                    else
                    {
                        /* Copy data */
                        *p_dataP = p_ctx->p_memUPKA[p_ctx->memUPKACntr];

                        /* Update index */
                        p_ctx->memUPKACntr++;
                        result = DUNPK_RES_OK;
                    }
                }
            }
		}
    }

	return result;
}

e_eCU_DUNPK_Res eCU_DUNPK_PopU16(s_eCU_DUNPK_Ctx* const p_ctx, uint16_t* p_dataP)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;
    uint16_t tempS;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_dataP ) )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			result = DUNPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DUNPK_isStatusStillCoherent(p_ctx) )
            {
                result = DUNPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check Init */
                if( p_ctx->memUPKAFrameSize <= 0u )
                {
                    result = DUNPK_RES_NOINITFRAME;
                }
                else
                {
                    /* Check if we can pop that amount */
                    if( ( p_ctx->memUPKACntr + sizeof(uint16_t) ) > p_ctx->memUPKAFrameSize )
                    {
                        result = DUNPK_RES_NODATA;
                    }
                    else
                    {
                        *p_dataP = 0u;

                        if( true == p_ctx->isLE)
                        {
                            /* Copy data Little endian */
                            tempS = (uint16_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr];
                            *p_dataP |= ( tempS & 0x00FFu );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint16_t) ( ( (uint16_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 8u  );
                            *p_dataP |= ( tempS & 0xFF00u );
                            p_ctx->memUPKACntr++;
                        }
                        else
                        {
                            /* Copy data big endian */
                            tempS =  (uint16_t) ( ( (uint16_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 8u  );
                            *p_dataP |= ( tempS & 0xFF00u );
                            p_ctx->memUPKACntr++;

                            tempS = (uint16_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr];
                            *p_dataP |= ( tempS & 0x00FFu );
                            p_ctx->memUPKACntr++;
                        }

                        result = DUNPK_RES_OK;
                    }
                }
            }
		}
    }

	return result;
}

e_eCU_DUNPK_Res eCU_DUNPK_PopU32(s_eCU_DUNPK_Ctx* const p_ctx, uint32_t* p_dataP)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;
    uint32_t tempS;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_dataP ) )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			result = DUNPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DUNPK_isStatusStillCoherent(p_ctx) )
            {
                result = DUNPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check Init */
                if( p_ctx->memUPKAFrameSize <= 0u )
                {
                    result = DUNPK_RES_NOINITFRAME;
                }
                else
                {
                    /* Check if we can pop that amount */
                    if( ( p_ctx->memUPKACntr + sizeof(uint32_t) ) > p_ctx->memUPKAFrameSize )
                    {
                        result = DUNPK_RES_NODATA;
                    }
                    else
                    {
                        *p_dataP = 0u;

                        if( true == p_ctx->isLE)
                        {
                            /* Copy data Little endian */
                            tempS = (uint32_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr];
                            *p_dataP |= ( tempS & 0x000000FFu );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint32_t) ( ( (uint32_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 8u  );
                            *p_dataP |= ( tempS & 0x0000FF00u );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint32_t) ( ( (uint32_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 16u  );
                            *p_dataP |= ( tempS & 0x00FF0000u );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint32_t) ( ( (uint32_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 24u  );
                            *p_dataP |= ( tempS & 0xFF000000u );
                            p_ctx->memUPKACntr++;
                        }
                        else
                        {
                            /* Copy data big endian */
                            tempS =  (uint32_t) ( ( (uint32_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 24u  );
                            *p_dataP |= ( tempS & 0xFF000000u );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint32_t) ( ( (uint32_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 16u  );
                            *p_dataP |= ( tempS & 0x00FF0000u );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint32_t) ( ( (uint32_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 8u  );
                            *p_dataP |= ( tempS & 0x0000FF00u );
                            p_ctx->memUPKACntr++;

                            tempS = (uint32_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr];
                            *p_dataP |= ( tempS & 0x000000FFu );
                            p_ctx->memUPKACntr++;
                        }

                        result = DUNPK_RES_OK;
                    }
                }
            }
		}
	}

	return result;
}

e_eCU_DUNPK_Res eCU_DUNPK_PopU64(s_eCU_DUNPK_Ctx* const p_ctx, uint64_t* p_dataP)
{
	/* Local variable */
	e_eCU_DUNPK_Res result;
    uint64_t tempS;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_dataP ) )
	{
		result = DUNPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			result = DUNPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DUNPK_isStatusStillCoherent(p_ctx) )
            {
                result = DUNPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check Init */
                if( p_ctx->memUPKAFrameSize <= 0u )
                {
                    result = DUNPK_RES_NOINITFRAME;
                }
                else
                {
                    /* Check if we can pop that amount */
                    if( ( p_ctx->memUPKACntr + sizeof(uint64_t) ) > p_ctx->memUPKAFrameSize )
                    {
                        result = DUNPK_RES_NODATA;
                    }
                    else
                    {
                        *p_dataP = 0u;

                        if( true == p_ctx->isLE)
                        {
                            /* Copy data Little endian */
                            tempS = (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr];
                            *p_dataP |= ( tempS & 0x00000000000000FFUL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 8u  );
                            *p_dataP |= ( tempS & 0x000000000000FF00UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 16u  );
                            *p_dataP |= ( tempS & 0x0000000000FF0000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 24u  );
                            *p_dataP |= ( tempS & 0x00000000FF000000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 32u  );
                            *p_dataP |= ( tempS & 0x000000FF00000000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 40u  );
                            *p_dataP |= ( tempS & 0x0000FF0000000000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 48u  );
                            *p_dataP |= ( tempS & 0x00FF000000000000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 56u  );
                            *p_dataP |= ( tempS & 0xFF00000000000000UL );
                            p_ctx->memUPKACntr++;
                        }
                        else
                        {
                            /* Copy data big endian */
                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 56u  );
                            *p_dataP |= ( tempS & 0xFF00000000000000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 48u  );
                            *p_dataP |= ( tempS & 0x00FF000000000000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 40u  );
                            *p_dataP |= ( tempS & 0x0000FF0000000000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 32u  );
                            *p_dataP |= ( tempS & 0x000000FF00000000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 24u  );
                            *p_dataP |= ( tempS & 0x00000000FF000000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 16u  );
                            *p_dataP |= ( tempS & 0x0000000000FF0000UL );
                            p_ctx->memUPKACntr++;

                            tempS =  (uint64_t) ( ( (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr] ) << 8u  );
                            *p_dataP |= ( tempS & 0x000000000000FF00UL );
                            p_ctx->memUPKACntr++;

                            tempS = (uint64_t) p_ctx->p_memUPKA[p_ctx->memUPKACntr];
                            *p_dataP |= ( tempS & 0x00000000000000FFUL );
                            p_ctx->memUPKACntr++;
                        }

                        result = DUNPK_RES_OK;
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
static bool_t eCU_DUNPK_isStatusStillCoherent(const s_eCU_DUNPK_Ctx* p_ctx)
{
    bool_t result;

	/* Check context validity */
	if( ( p_ctx->memUPKASize <= 0u ) || ( NULL == p_ctx->p_memUPKA ) )
	{
		result = false;
	}
	else
	{
		/* Check queue data coherence */
		if( ( p_ctx->memUPKACntr > p_ctx->memUPKAFrameSize ) || ( p_ctx->memUPKAFrameSize > p_ctx->memUPKASize ) )
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
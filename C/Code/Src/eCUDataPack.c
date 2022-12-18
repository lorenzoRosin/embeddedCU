/**
 * @file       eCUDataPack.c
 *
 * @brief      Data pack utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataPack.h"



/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t eCU_DPK_isStatusStillCoherent(const s_eCU_DPK_Ctx* p_ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_DPK_Res eCU_DPK_InitCtx(s_eCU_DPK_Ctx* const p_ctx, uint8_t* p_memPKA, const uint32_t memPKASize,
                              const bool_t isLEnd)
{
	/* Local variable */
	e_eCU_DPK_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL ==  p_memPKA ) )
	{
		l_result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check data validity */
		if( memPKASize <= 0u )
		{
			l_result = DPK_RES_BADPARAM;
		}
		else
		{
            p_ctx->isInit = true;
            p_ctx->isLE = isLEnd;
            p_ctx->p_memPKA = p_memPKA;
            p_ctx->memPKASize = memPKASize;
            p_ctx->memPKACntr = 0u;

            l_result = DPK_RES_OK;
		}
    }

	return l_result;
}

e_eCU_DPK_Res eCU_DPK_IsInit(s_eCU_DPK_Ctx* const p_ctx, bool_t* p_isInit)
{
	/* Local variable */
	e_eCU_DPK_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isInit ) )
	{
		l_result = DPK_RES_BADPOINTER;
	}
	else
	{
        *p_isInit = p_ctx->isInit;
        l_result = DPK_RES_OK;
	}

	return l_result;
}

e_eCU_DPK_Res eCU_DPK_StartNewPack(s_eCU_DPK_Ctx* const p_ctx)
{
	/* Local variable */
	e_eCU_DPK_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Update index */
                p_ctx->memPKACntr = 0u;
                l_result = DPK_RES_OK;
            }
		}
    }

	return l_result;
}

e_eCU_DPK_Res eCU_DPK_GetDataReference(s_eCU_DPK_Ctx* const p_ctx, uint8_t** pp_data, uint32_t* const p_retrivedLen)
{
	/* Local variable */
	e_eCU_DPK_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == pp_data ) || ( NULL == p_retrivedLen ) )
	{
		l_result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                *pp_data = p_ctx->p_memPKA;
                *p_retrivedLen = p_ctx->memPKACntr;
                l_result = DPK_RES_OK;
            }
		}
    }

	return l_result;
}

e_eCU_DPK_Res eCU_DPK_GetNPushed(s_eCU_DPK_Ctx* const p_ctx, uint32_t* const p_retrivedLen)
{
	/* Local variable */
	e_eCU_DPK_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_retrivedLen ) )
	{
		l_result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                *p_retrivedLen = p_ctx->memPKACntr;
                l_result = DPK_RES_OK;
            }
		}
    }

	return l_result;
}

e_eCU_DPK_Res eCU_DPK_PushArray(s_eCU_DPK_Ctx* const p_ctx, uint8_t* p_data, const uint32_t dataLen)
{
	/* Local variable */
	e_eCU_DPK_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_data ) )
	{
		l_result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = DPK_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity */
                if( dataLen <= 0u )
                {
                    l_result = DPK_RES_BADPARAM;
                }
                else
                {
                    /* Check if we have memory for this */
                    if( ( p_ctx->memPKACntr + dataLen ) > p_ctx->memPKASize )
                    {
                        l_result = DPK_RES_OUTOFMEM;
                    }
                    else
                    {
                        /* Copy data */
                        (void)memcpy(&p_ctx->p_memPKA[p_ctx->memPKACntr], p_data, dataLen);

                        /* Update index */
                        p_ctx->memPKACntr += dataLen;

                        l_result = DPK_RES_OK;
                    }
                }
			}
		}
    }

	return l_result;
}

e_eCU_DPK_Res eCU_DPK_PushU8(s_eCU_DPK_Ctx* const p_ctx, const uint8_t dataToPush)
{
	/* Local variable */
	e_eCU_DPK_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( p_ctx->memPKACntr + sizeof(uint8_t) ) > p_ctx->memPKASize )
                {
                    /* no free memory */
                    l_result = DPK_RES_OUTOFMEM;
                }
                else
                {
                    /* Copy data */
                    p_ctx->p_memPKA[p_ctx->memPKACntr] = dataToPush;

                    /* Update index */
                    p_ctx->memPKACntr++;

                    l_result = DPK_RES_OK;
                }
            }
		}
    }

	return l_result;
}

e_eCU_DPK_Res eCU_DPK_PushU16(s_eCU_DPK_Ctx* const p_ctx, const uint16_t dataToPush)
{
	/* Local variable */
	e_eCU_DPK_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( p_ctx->memPKACntr + sizeof(uint16_t) ) > p_ctx->memPKASize )
                {
                    /* no free memory */
                    l_result = DPK_RES_OUTOFMEM;
                }
                else
                {
                    if( true == p_ctx->isLE)
                    {
                        /* Copy data Little endian */
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x00FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00FFu );
                        p_ctx->memPKACntr++;
                    }
                    else
                    {
                        /* Copy data big endian */
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x00FFu );
                        p_ctx->memPKACntr++;
                    }

                    l_result = DPK_RES_OK;
                }
            }
		}
    }

	return l_result;
}

e_eCU_DPK_Res eCU_DPK_PushU32(s_eCU_DPK_Ctx* const p_ctx, const uint32_t dataToPush)
{
	/* Local variable */
	e_eCU_DPK_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( p_ctx->memPKACntr + sizeof(uint32_t) ) > p_ctx->memPKASize )
                {
                    /* no free memory */
                    l_result = DPK_RES_OUTOFMEM;
                }
                else
                {
                    if( true == p_ctx->isLE)
                    {
                        /* Copy data Little endian */
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x000000FFu );
                        p_ctx->memPKACntr++;
                    }
                    else
                    {
                        /* Copy data big endian */
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x000000FFu );
                        p_ctx->memPKACntr++;
                    }

                    l_result = DPK_RES_OK;
                }
            }
		}
    }

	return l_result;
}

e_eCU_DPK_Res eCU_DPK_PushU64(s_eCU_DPK_Ctx* const p_ctx, const uint64_t dataToPush)
{
	/* Local variable */
	e_eCU_DPK_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( p_ctx->memPKACntr + sizeof(uint64_t) ) > p_ctx->memPKASize )
                {
                    /* no free memory */
                    l_result = DPK_RES_OUTOFMEM;
                }
                else
                {
                    if( true == p_ctx->isLE)
                    {
                        /* Copy data Little endian */
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 32u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 40u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 48u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 56u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                    }
                    else
                    {
                        /* Copy data big endian */
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 56u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 48u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 40u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 32u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                        p_ctx->p_memPKA[p_ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x00000000000000FFu );
                        p_ctx->memPKACntr++;
                    }

                    l_result = DPK_RES_OK;
                }
            }
		}
    }

	return l_result;
}



/***********************************************************************************************************************
 *  PRIVATE FUNCTION
 **********************************************************************************************************************/
static bool_t eCU_DPK_isStatusStillCoherent(const s_eCU_DPK_Ctx* p_ctx)
{
    bool_t l_result;

	/* Check context validity */
	if( ( p_ctx->memPKASize <= 0u ) || ( NULL == p_ctx->p_memPKA ) )
	{
		l_result = false;
	}
	else
	{
		/* Check queue data coherence */
		if( p_ctx->memPKACntr > p_ctx->memPKASize )
		{
			l_result = false;
		}
		else
		{
            l_result = true;
		}
	}

    return l_result;
}
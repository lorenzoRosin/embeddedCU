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
static bool_t eCU_DPK_isStatusStillCoherent(const t_eCU_DPK_Ctx* p_ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_DPK_RES eCU_DPK_InitCtx(t_eCU_DPK_Ctx* const p_ctx, uint8_t* puMemPK, const uint32_t uMemPKL,
                              const bool_t isLEnd)
{
	/* Local variable */
	e_eCU_DPK_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL ==  puMemPK ) )
	{
		l_result = e_eCU_DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check data validity */
		if( uMemPKL <= 0u )
		{
			l_result = e_eCU_DPK_RES_BADPARAM;
		}
		else
		{
            p_ctx->bIsInit = true;
            p_ctx->bIsLE = isLEnd;
            p_ctx->puMemPK = puMemPK;
            p_ctx->uMemPKL = uMemPKL;
            p_ctx->uMemPKCtr = 0u;

            l_result = e_eCU_DPK_RES_OK;
		}
    }

	return l_result;
}

e_eCU_DPK_RES eCU_DPK_IsInit(t_eCU_DPK_Ctx* const p_ctx, bool_t* p_isInit)
{
	/* Local variable */
	e_eCU_DPK_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isInit ) )
	{
		l_result = e_eCU_DPK_RES_BADPOINTER;
	}
	else
	{
        *p_isInit = p_ctx->bIsInit;
        l_result = e_eCU_DPK_RES_OK;
	}

	return l_result;
}

e_eCU_DPK_RES eCU_DPK_StartNewPack(t_eCU_DPK_Ctx* const p_ctx)
{
	/* Local variable */
	e_eCU_DPK_RES l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = e_eCU_DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Update index */
                p_ctx->uMemPKCtr = 0u;
                l_result = e_eCU_DPK_RES_OK;
            }
		}
    }

	return l_result;
}

e_eCU_DPK_RES eCU_DPK_GetDataReference(t_eCU_DPK_Ctx* const p_ctx, uint8_t** pp_data, uint32_t* const p_retrivedLen)
{
	/* Local variable */
	e_eCU_DPK_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == pp_data ) || ( NULL == p_retrivedLen ) )
	{
		l_result = e_eCU_DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_DPK_RES_CORRUPTCTX;
            }
            else
            {
                *pp_data = p_ctx->puMemPK;
                *p_retrivedLen = p_ctx->uMemPKCtr;
                l_result = e_eCU_DPK_RES_OK;
            }
		}
    }

	return l_result;
}

e_eCU_DPK_RES eCU_DPK_GetNPushed(t_eCU_DPK_Ctx* const p_ctx, uint32_t* const p_retrivedLen)
{
	/* Local variable */
	e_eCU_DPK_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_retrivedLen ) )
	{
		l_result = e_eCU_DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_DPK_RES_CORRUPTCTX;
            }
            else
            {
                *p_retrivedLen = p_ctx->uMemPKCtr;
                l_result = e_eCU_DPK_RES_OK;
            }
		}
    }

	return l_result;
}

e_eCU_DPK_RES eCU_DPK_PushArray(t_eCU_DPK_Ctx* const p_ctx, uint8_t* p_data, const uint32_t dataLen)
{
	/* Local variable */
	e_eCU_DPK_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_data ) )
	{
		l_result = e_eCU_DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_DPK_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity */
                if( dataLen <= 0u )
                {
                    l_result = e_eCU_DPK_RES_BADPARAM;
                }
                else
                {
                    /* Check if we have memory for this */
                    if( ( p_ctx->uMemPKCtr + dataLen ) > p_ctx->uMemPKL )
                    {
                        l_result = e_eCU_DPK_RES_OUTOFMEM;
                    }
                    else
                    {
                        /* Copy data */
                        (void)memcpy(&p_ctx->puMemPK[p_ctx->uMemPKCtr], p_data, dataLen);

                        /* Update index */
                        p_ctx->uMemPKCtr += dataLen;

                        l_result = e_eCU_DPK_RES_OK;
                    }
                }
			}
		}
    }

	return l_result;
}

e_eCU_DPK_RES eCU_DPK_PushU8(t_eCU_DPK_Ctx* const p_ctx, const uint8_t dataToPush)
{
	/* Local variable */
	e_eCU_DPK_RES l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = e_eCU_DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( p_ctx->uMemPKCtr + sizeof(uint8_t) ) > p_ctx->uMemPKL )
                {
                    /* no free memory */
                    l_result = e_eCU_DPK_RES_OUTOFMEM;
                }
                else
                {
                    /* Copy data */
                    p_ctx->puMemPK[p_ctx->uMemPKCtr] = dataToPush;

                    /* Update index */
                    p_ctx->uMemPKCtr++;

                    l_result = e_eCU_DPK_RES_OK;
                }
            }
		}
    }

	return l_result;
}

e_eCU_DPK_RES eCU_DPK_PushU16(t_eCU_DPK_Ctx* const p_ctx, const uint16_t dataToPush)
{
	/* Local variable */
	e_eCU_DPK_RES l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = e_eCU_DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( p_ctx->uMemPKCtr + sizeof(uint16_t) ) > p_ctx->uMemPKL )
                {
                    /* no free memory */
                    l_result = e_eCU_DPK_RES_OUTOFMEM;
                }
                else
                {
                    if( true == p_ctx->bIsLE)
                    {
                        /* Copy data Little endian */
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush        ) & 0x00FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00FFu );
                        p_ctx->uMemPKCtr++;
                    }
                    else
                    {
                        /* Copy data big endian */
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush        ) & 0x00FFu );
                        p_ctx->uMemPKCtr++;
                    }

                    l_result = e_eCU_DPK_RES_OK;
                }
            }
		}
    }

	return l_result;
}

e_eCU_DPK_RES eCU_DPK_PushU32(t_eCU_DPK_Ctx* const p_ctx, const uint32_t dataToPush)
{
	/* Local variable */
	e_eCU_DPK_RES l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = e_eCU_DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( p_ctx->uMemPKCtr + sizeof(uint32_t) ) > p_ctx->uMemPKL )
                {
                    /* no free memory */
                    l_result = e_eCU_DPK_RES_OUTOFMEM;
                }
                else
                {
                    if( true == p_ctx->bIsLE)
                    {
                        /* Copy data Little endian */
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush        ) & 0x000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x000000FFu );
                        p_ctx->uMemPKCtr++;
                    }
                    else
                    {
                        /* Copy data big endian */
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush        ) & 0x000000FFu );
                        p_ctx->uMemPKCtr++;
                    }

                    l_result = e_eCU_DPK_RES_OK;
                }
            }
		}
    }

	return l_result;
}

e_eCU_DPK_RES eCU_DPK_PushU64(t_eCU_DPK_Ctx* const p_ctx, const uint64_t dataToPush)
{
	/* Local variable */
	e_eCU_DPK_RES l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = e_eCU_DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_DPK_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( p_ctx->uMemPKCtr + sizeof(uint64_t) ) > p_ctx->uMemPKL )
                {
                    /* no free memory */
                    l_result = e_eCU_DPK_RES_OUTOFMEM;
                }
                else
                {
                    if( true == p_ctx->bIsLE)
                    {
                        /* Copy data Little endian */
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush        ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 32u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 40u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 48u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 56u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                    }
                    else
                    {
                        /* Copy data big endian */
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 56u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 48u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 40u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 32u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                        p_ctx->puMemPK[p_ctx->uMemPKCtr] = (uint8_t) ( ( dataToPush        ) & 0x00000000000000FFu );
                        p_ctx->uMemPKCtr++;
                    }

                    l_result = e_eCU_DPK_RES_OK;
                }
            }
		}
    }

	return l_result;
}



/***********************************************************************************************************************
 *  PRIVATE FUNCTION
 **********************************************************************************************************************/
static bool_t eCU_DPK_isStatusStillCoherent(const t_eCU_DPK_Ctx* p_ctx)
{
    bool_t l_result;

	/* Check context validity */
	if( ( p_ctx->uMemPKL <= 0u ) || ( NULL == p_ctx->puMemPK ) )
	{
		l_result = false;
	}
	else
	{
		/* Check queue data coherence */
		if( p_ctx->uMemPKCtr > p_ctx->uMemPKL )
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
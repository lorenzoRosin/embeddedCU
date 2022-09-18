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
static bool_t isPackStatusStillCoherent(const s_eCU_DataPackCtx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_dPk_Res dataPackinitCtx(s_eCU_DataPackCtx* const ctx, uint8_t* const memPKA, const uint32_t memPKASize,
					          const bool_t isLEnd)
{
	/* Local variable */
	e_eCU_dPk_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx) || ( NULL ==  memPKA) )
	{
		result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check data validity */
		if( memPKASize <= 0u )
		{
			result = DPK_RES_BADPARAM;
		}
		else
		{
            ctx->isInit = true;
            ctx->isLE = isLEnd;
            ctx->memPKA = memPKA;
            ctx->memPKASize = memPKASize;
            ctx->memPKACntr = 0u;

            result = DPK_RES_OK;
		}
    }

	return result;
}

e_eCU_dPk_Res dataPackStartNewPack(s_eCU_DataPackCtx* const ctx)
{
	/* Local variable */
	e_eCU_dPk_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DPK_RES_NOINITLIB;
		}
		else
		{
			/* Update index */
			ctx->memPKACntr = 0u;
			result = DPK_RES_OK;
		}
    }

	return result;
}

e_eCU_dPk_Res dataPackGetDataReference(s_eCU_DataPackCtx* const ctx, uint8_t** dataP, uint32_t* const retrivedLen)
{
	/* Local variable */
	e_eCU_dPk_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataP ) || ( NULL == retrivedLen ) )
	{
		result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isPackStatusStillCoherent(ctx) )
            {
                result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                *dataP = ctx->memPKA;
                *retrivedLen = ctx->memPKACntr;
                result = DPK_RES_OK;
            }
		}
    }

	return result;
}

e_eCU_dPk_Res dataPackGetNPushed(s_eCU_DataPackCtx* const ctx, uint32_t* const retrivedLen)
{
	/* Local variable */
	e_eCU_dPk_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == retrivedLen ) )
	{
		result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isPackStatusStillCoherent(ctx) )
            {
                result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                *retrivedLen = ctx->memPKACntr;
                result = DPK_RES_OK;
            }
		}
    }

	return result;
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-17.4_b"
    /* Suppressed for code clarity */
#endif

e_eCU_dPk_Res dataPackPushArray(s_eCU_DataPackCtx* const ctx, const uint8_t* data, const uint32_t dataLen)
{
	/* Local variable */
	e_eCU_dPk_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == data ) )
	{
		result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DPK_RES_NOINITLIB;
		}
		else
		{
			/* Check data validity */
			if( dataLen <= 0u )
			{
				result = DPK_RES_BADPARAM;
			}
			else
			{
                /* Check internal status validity */
                if( false == isPackStatusStillCoherent(ctx) )
                {
                    result = DPK_RES_CORRUPTCTX;
                }
                else
                {
                    /* Check if we have memory for this */
                    if( ( ctx->memPKACntr + dataLen ) > ctx->memPKASize )
                    {
                        result = DPK_RES_OUTOFMEM;
                    }
                    else
                    {
                        /* Copy data */
                        (void)memcpy(&ctx->memPKA[ctx->memPKACntr], data, dataLen);

                        /* Update index */
                        ctx->memPKACntr += dataLen;

                        result = DPK_RES_OK;
                    }
                }
			}
		}
    }

	return result;
}

e_eCU_dPk_Res dataPackPushU8(s_eCU_DataPackCtx* const ctx, const uint8_t dataToPush)
{
	/* Local variable */
	e_eCU_dPk_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isPackStatusStillCoherent(ctx) )
            {
                result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( ctx->memPKACntr + sizeof(uint8_t) ) > ctx->memPKASize )
                {
                    /* no free memory */
                    result = DPK_RES_OUTOFMEM;
                }
                else
                {
                    /* Copy data */
                    ctx->memPKA[ctx->memPKACntr] = dataToPush;

                    /* Update index */
                    ctx->memPKACntr++;

                    result = DPK_RES_OK;
                }
            }
		}
    }

	return result;
}

e_eCU_dPk_Res dataPackPushU16(s_eCU_DataPackCtx* const ctx, const uint16_t dataToPush)
{
	/* Local variable */
	e_eCU_dPk_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isPackStatusStillCoherent(ctx) )
            {
                result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( ctx->memPKACntr + sizeof(uint16_t) ) > ctx->memPKASize )
                {
                    /* no free memory */
                    result = DPK_RES_OUTOFMEM;
                }
                else
                {
                    if( true == ctx->isLE)
                    {
                        /* Copy data Little endian */
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x00FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00FFu );
                        ctx->memPKACntr++;
                    }
                    else
                    {
                        /* Copy data big endian */
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x00FFu );
                        ctx->memPKACntr++;
                    }

                    result = DPK_RES_OK;
                }
            }
		}
    }

	return result;
}

e_eCU_dPk_Res dataPackPushU32(s_eCU_DataPackCtx* const ctx, const uint32_t dataToPush)
{
	/* Local variable */
	e_eCU_dPk_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isPackStatusStillCoherent(ctx) )
            {
                result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( ctx->memPKACntr + sizeof(uint32_t) ) > ctx->memPKASize )
                {
                    /* no free memory */
                    result = DPK_RES_OUTOFMEM;
                }
                else
                {
                    if( true == ctx->isLE)
                    {
                        /* Copy data Little endian */
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x000000FFu );
                        ctx->memPKACntr++;
                    }
                    else
                    {
                        /* Copy data big endian */
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x000000FFu );
                        ctx->memPKACntr++;
                    }

                    result = DPK_RES_OK;
                }
            }
		}
    }

	return result;
}

e_eCU_dPk_Res dataPackPushU64(s_eCU_DataPackCtx* const ctx, const uint64_t dataToPush)
{
	/* Local variable */
	e_eCU_dPk_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = DPK_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = DPK_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isPackStatusStillCoherent(ctx) )
            {
                result = DPK_RES_CORRUPTCTX;
            }
            else
            {
                /* Check if we have memory for this */
                if( ( ctx->memPKACntr + sizeof(uint64_t) ) > ctx->memPKASize )
                {
                    /* no free memory */
                    result = DPK_RES_OUTOFMEM;
                }
                else
                {
                    if( true == ctx->isLE)
                    {
                        /* Copy data Little endian */
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 32u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 40u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 48u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 56u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                    }
                    else
                    {
                        /* Copy data big endian */
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 56u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 48u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 40u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 32u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 24u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 16u ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush >> 8u  ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                        ctx->memPKA[ctx->memPKACntr] = (uint8_t) ( ( dataToPush        ) & 0x00000000000000FFu );
                        ctx->memPKACntr++;
                    }

                    result = DPK_RES_OK;
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
bool_t isPackStatusStillCoherent(const s_eCU_DataPackCtx* ctx)
{
    bool_t result;

	/* Check context validity */
	if( ( ctx->memPKASize <= 0u ) || ( NULL == ctx->memPKA ) )
	{
		result = false;
	}
	else
	{
		/* Check queue data coherence */
		if( ctx->memPKACntr > ctx->memPKASize )
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

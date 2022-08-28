/**
 * @file eCUDataUnPack.c
 *
 */

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataUnPack.h"



/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t isUnPackStatusStillCoherent(const s_eCU_DataUnPackCtx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_Res dataUnPackinit(s_eCU_DataUnPackCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize,
                         const bool_t isLEnd)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx) || ( NULL ==  memPool) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check data validity */
		if( memPoolSize <= 0u )
		{
			result = ECU_RES_BADPARAM;
		}
		else
		{
			/* Check Init */
			if( true == ctx->isInit )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				ctx->isInit = true;
				ctx->isLE = isLEnd;
				ctx->memPool = memPool;
				ctx->memPoolSize = memPoolSize;
				ctx->memPoolFillSize = 0u;
				ctx->memPoolCntr = 0u;

				result = ECU_RES_OK;
			}
		}
    }

	return result;
}

e_eCU_Res dataUnPackReset(s_eCU_DataUnPackCtx* const ctx)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
			/* Update index */
			ctx->memPoolFillSize = 0u;
			ctx->memPoolCntr = 0u;

			result = ECU_RES_OK;
		}
    }

	return result;
}

e_eCU_Res dataUnPackGetDataSize(s_eCU_DataUnPackCtx* const ctx, uint32_t* const retrivedLen)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == retrivedLen ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
			/* Check internal status validity */
			if( false == isUnPackStatusStillCoherent(ctx) )
			{
				/* We have removed more data that we had */
				result = ECU_RES_BADPARAM;
			}
			else
			{
				*retrivedLen = ctx->memPoolFillSize - ctx->memPoolCntr;
				result = ECU_RES_OK;
			}

		}
    }

	return result;
}

e_eCU_Res dataUnPackSetData(s_eCU_DataUnPackCtx* const ctx, uint8_t* const data, uint32_t const dataLen)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == data ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
			/* Check data validity */
			if( dataLen <= 0u )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
                /* Check internal status validity */
                if( false == isUnPackStatusStillCoherent(ctx) )
                {
                    /* We have removed more data that we had */
                    result = ECU_RES_BADPARAM;
                }
                else
                {
                    /* Check if data can be stored */
                    if( dataLen > ctx->memPoolSize )
                    {
                        result = ECU_RES_OUTOFMEM;
                    }
                    else
                    {
                        /* Copy data */
                        (void)memcpy( ctx->memPool, data, dataLen );

                        /* Update index */
                        ctx->memPoolFillSize = dataLen;
                        ctx->memPoolCntr = 0u;

                        result = ECU_RES_OK;
                    }
                }
			}
		}
    }

	return result;
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-17.4_b"
    /* Suppressed for code clarity */
#endif

e_eCU_Res dataUnPackPopArray(s_eCU_DataUnPackCtx* const ctx, uint8_t* const dataDest, uint32_t const retrivedLen)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataDest ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
            /* Check data validity */
            if( retrivedLen <= 0u )
            {
                /* We have removed more data that we had */
                result = ECU_RES_BADPARAM;
            }
            else
            {
                /* Check internal status validity */
                if( false == isUnPackStatusStillCoherent(ctx) )
                {
                    result = ECU_RES_BADPARAM;
                }
                else
                {
                    /* Check if we can pop that amount */
                    if( ( ctx->memPoolCntr + retrivedLen ) > ctx->memPoolFillSize )
                    {
                        result = ECU_RES_OUTOFMEM;
                    }
                    else
                    {
                        /* Copy data */
                        (void)memcpy(dataDest, &ctx->memPool[ctx->memPoolCntr], retrivedLen);

                        /* Update index */
                        ctx->memPoolCntr += retrivedLen;
                        result = ECU_RES_OK;
                    }
                }
            }
		}
    }

	return result;
}

e_eCU_Res dataUnPackPopU8(s_eCU_DataUnPackCtx* const ctx, uint8_t *dataP)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataP ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isUnPackStatusStillCoherent(ctx) )
            {
                result = ECU_RES_BADPARAM;
            }
			else
			{
				/* Check if we can pop that amount */
				if( ( ctx->memPoolCntr + sizeof(uint8_t) ) > ctx->memPoolFillSize )
				{
					result = ECU_RES_OUTOFMEM;
				}
				else
				{
					/* Copy data */
					*dataP = ctx->memPool[ctx->memPoolCntr];

					/* Update index */
					ctx->memPoolCntr++;
					result = ECU_RES_OK;
				}
			}
		}
    }

	return result;
}

e_eCU_Res dataUnPackPopU16(s_eCU_DataUnPackCtx* const ctx, uint16_t* dataP)
{
	/* Local variable */
	e_eCU_Res result;
    uint16_t tempS;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataP ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isUnPackStatusStillCoherent(ctx) )
            {
                result = ECU_RES_BADPARAM;
            }
			else
			{
				/* Check if we can pop that amount */
				if( ( ctx->memPoolCntr + sizeof(uint16_t) ) > ctx->memPoolFillSize )
				{
					result = ECU_RES_OUTOFMEM;
				}
				else
				{
                    *dataP = 0u;

					if( true == ctx->isLE)
					{
                        /* Copy data Little endian */
                        tempS = (uint16_t) ctx->memPool[ctx->memPoolCntr];
                        *dataP |= ( tempS & 0x00FFu );
                        ctx->memPoolCntr++;

                        tempS =  (uint16_t) ( ( (uint16_t) ctx->memPool[ctx->memPoolCntr] ) << 8u  );
						*dataP |= ( tempS & 0xFF00u );
						ctx->memPoolCntr++;
					}
					else
					{
						/* Copy data big endian */
                        tempS =  (uint16_t) ( ( (uint16_t) ctx->memPool[ctx->memPoolCntr] ) << 8u  );
						*dataP |= ( tempS & 0xFF00u );
						ctx->memPoolCntr++;

                        tempS = (uint16_t) ctx->memPool[ctx->memPoolCntr];
                        *dataP |= ( tempS & 0x00FFu );
                        ctx->memPoolCntr++;
					}

					result = ECU_RES_OK;
				}
			}
		}
    }

	return result;
}

e_eCU_Res dataUnPackPopU32(s_eCU_DataUnPackCtx* const ctx, uint32_t* dataP)
{
	/* Local variable */
	e_eCU_Res result;
    uint32_t tempS;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataP ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isUnPackStatusStillCoherent(ctx) )
            {
                result = ECU_RES_BADPARAM;
            }
			else
			{
				/* Check if we can pop that amount */
				if( ( ctx->memPoolCntr + sizeof(uint32_t) ) > ctx->memPoolFillSize )
				{
					result = ECU_RES_OUTOFMEM;
				}
				else
				{
					*dataP = 0u;

					if( true == ctx->isLE)
					{
                        /* Copy data Little endian */
                        tempS = (uint32_t) ctx->memPool[ctx->memPoolCntr];
                        *dataP |= ( tempS & 0x000000FFu );
                        ctx->memPoolCntr++;

                        tempS =  (uint32_t) ( ( (uint32_t) ctx->memPool[ctx->memPoolCntr] ) << 8u  );
						*dataP |= ( tempS & 0x0000FF00u );
						ctx->memPoolCntr++;

                        tempS =  (uint32_t) ( ( (uint32_t) ctx->memPool[ctx->memPoolCntr] ) << 16u  );
						*dataP |= ( tempS & 0x00FF0000u );
						ctx->memPoolCntr++;

                        tempS =  (uint32_t) ( ( (uint32_t) ctx->memPool[ctx->memPoolCntr] ) << 24u  );
						*dataP |= ( tempS & 0xFF000000u );
						ctx->memPoolCntr++;
					}
					else
					{
						/* Copy data big endian */
                        tempS =  (uint32_t) ( ( (uint32_t) ctx->memPool[ctx->memPoolCntr] ) << 24u  );
						*dataP |= ( tempS & 0xFF000000u );
						ctx->memPoolCntr++;

                        tempS =  (uint32_t) ( ( (uint32_t) ctx->memPool[ctx->memPoolCntr] ) << 16u  );
                        *dataP |= ( tempS & 0x00FF0000u );
                        ctx->memPoolCntr++;

                        tempS =  (uint32_t) ( ( (uint32_t) ctx->memPool[ctx->memPoolCntr] ) << 8u  );
						*dataP |= ( tempS & 0x0000FF00u );
						ctx->memPoolCntr++;

                        tempS = (uint32_t) ctx->memPool[ctx->memPoolCntr];
                        *dataP |= ( tempS & 0x000000FFu );
                        ctx->memPoolCntr++;
					}

					result = ECU_RES_OK;
				}
			}
		}
	}

	return result;
}

e_eCU_Res dataUnPackPopU64(s_eCU_DataUnPackCtx* const ctx, uint64_t* dataP)
{
	/* Local variable */
	e_eCU_Res result;
    uint64_t tempS;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataP ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isUnPackStatusStillCoherent(ctx) )
            {
                result = ECU_RES_BADPARAM;
            }
			else
			{
				/* Check if we can pop that amount */
				if( ( ctx->memPoolCntr + sizeof(uint64_t) ) > ctx->memPoolFillSize )
				{
					result = ECU_RES_OUTOFMEM;
				}
				else
				{
					*dataP = 0u;

					if( true == ctx->isLE)
					{
                        /* Copy data Little endian */
                        tempS = (uint64_t) ctx->memPool[ctx->memPoolCntr];
                        *dataP |= ( tempS & 0x00000000000000FFUL );
                        ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 8u  );
						*dataP |= ( tempS & 0x000000000000FF00UL );
						ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 16u  );
						*dataP |= ( tempS & 0x0000000000FF0000UL );
						ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 24u  );
						*dataP |= ( tempS & 0x00000000FF000000UL );
						ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 32u  );
						*dataP |= ( tempS & 0x000000FF00000000UL );
						ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 40u  );
						*dataP |= ( tempS & 0x0000FF0000000000UL );
						ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 48u  );
						*dataP |= ( tempS & 0x00FF000000000000UL );
						ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 56u  );
						*dataP |= ( tempS & 0xFF00000000000000UL );
						ctx->memPoolCntr++;
					}
					else
					{
						/* Copy data big endian */
 						tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 56u  );
                        *dataP |= ( tempS & 0xFF00000000000000UL );
						ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 48u  );
                        *dataP |= ( tempS & 0x00FF000000000000UL );
                        ctx->memPoolCntr++;

						tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 40u  );
                        *dataP |= ( tempS & 0x0000FF0000000000UL );
						ctx->memPoolCntr++;

 						tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 32u  );
                        *dataP |= ( tempS & 0x000000FF00000000UL );
						ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 24u  );
						*dataP |= ( tempS & 0x00000000FF000000UL );
						ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 16u  );
                        *dataP |= ( tempS & 0x0000000000FF0000UL );
                        ctx->memPoolCntr++;

                        tempS =  (uint64_t) ( ( (uint64_t) ctx->memPool[ctx->memPoolCntr] ) << 8u  );
						*dataP |= ( tempS & 0x000000000000FF00UL );
						ctx->memPoolCntr++;

                        tempS = (uint64_t) ctx->memPool[ctx->memPoolCntr];
                        *dataP |= ( tempS & 0x00000000000000FFUL );
                        ctx->memPoolCntr++;
					}

					result = ECU_RES_OK;
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
bool_t isUnPackStatusStillCoherent(const s_eCU_DataUnPackCtx* ctx)
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
		if( ( ctx->memPoolFillSize > ctx->memPoolSize ) || ( ctx->memPoolCntr > ctx->memPoolSize ) ||
            ( ctx->memPoolCntr > ctx->memPoolFillSize ) )
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




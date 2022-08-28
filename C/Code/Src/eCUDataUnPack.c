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
			/* Check data validity */
			if( ctx->memPoolCntr > ctx->memPoolFillSize )
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
	uint32_t dataToCopy;

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
				/* Check if data can be stored */
				if( dataLen > ctx->memPoolSize )
				{
					result = ECU_RES_OUTOFMEM;
				}
				else
				{
					/* Copy data */
					memcpy( ctx->memPool, data, dataLen );

					/* Update index */
					ctx->memPoolCntr = 0u;
					ctx->memPoolFillSize = dataLen;
					result = ECU_RES_OK;
				}
			}
		}
    }

	return result;
}

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
			if( ( retrivedLen <= 0u ) || ( ctx->memPoolCntr > ctx->memPoolFillSize ) )
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
					memcpy(dataDest, &ctx->memPool[ctx->memPoolCntr], retrivedLen);

					/* Update index */
					ctx->memPoolCntr+= retrivedLen;
					result = ECU_RES_OK;
				}
			}
		}
    }

	return result;
}

e_eCU_Res dataUnPackPopU8(s_eCU_DataUnPackCtx* const ctx, uint8_t *dataToPop)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataToPop ) )
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
			if( ctx->memPoolCntr > ctx->memPoolFillSize )
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
					*dataToPop = ctx->memPool[ctx->memPoolCntr];

					/* Update index */
					ctx->memPoolCntr++;
					result = ECU_RES_OK;
				}
			}
		}
    }

	return result;
}

e_eCU_Res dataUnPackPopU16(s_eCU_DataUnPackCtx* const ctx, uint16_t* dataToPop)
{
	/* Local variable */
	e_eCU_Res result;
	uint32_t indx;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataToPop ) )
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
			if( ctx->memPoolCntr > ctx->memPoolFillSize )
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
					indx = 0u;
					if( true == ctx->isLE)
					{
						/* Copy data Little endian */
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr]        ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 8u  ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
					}
					else
					{
						/* Copy data big endian */
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 8u  ) & 0xFF );
						ctx->memPoolCntr++;
						indx;
						( (uint8_t*) dataToPop )[indx]= ( ( ctx->memPool[ctx->memPoolCntr]        ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
					}

					result = ECU_RES_OK;
				}
			}
		}
    }

	return result;
}

e_eCU_Res dataUnPackPopU32(s_eCU_DataUnPackCtx* const ctx, uint32_t* dataToPop)
{
	/* Local variable */
	e_eCU_Res result;
	uint32_t indx;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataToPop ) )
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
			if( ctx->memPoolCntr > ctx->memPoolFillSize )
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
					indx = 0u;
					if( true == ctx->isLE)
					{
						/* Copy data Little endian */
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr]        ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 8u  ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 16u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 24u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
					}
					else
					{
						/* Copy data big endian */
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 24u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 16u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 8u  ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr]        ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
					}

					result = ECU_RES_OK;
				}
			}
		}
	}

	return result;
}

e_eCU_Res dataUnPackPopU64(s_eCU_DataUnPackCtx* const ctx, uint64_t* dataToPop)
{
	/* Local variable */
	e_eCU_Res result;
	uint32_t indx;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataToPop ) )
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
			if( ctx->memPoolCntr > ctx->memPoolFillSize )
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
					indx = 0u;
					if( true == ctx->isLE)
					{
						/* Copy data Little endian */
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr]        ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 8u  ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 16u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 24u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 32u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 40u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 48u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 56u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
					}
					else
					{
						/* Copy data big endian */
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 56u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 48u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 40u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 32u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 24u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 16u ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr] >> 8u  ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
						( (uint8_t*) dataToPop )[indx] = ( ( ctx->memPool[ctx->memPoolCntr]        ) & 0xFF );
						ctx->memPoolCntr++;
						indx++;
					}

					result = ECU_RES_OK;
				}
			}
		}
	}

	return result;
}


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
		if( ctx->memPoolCntr > ctx->memPoolSize )
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

/**
 * @file eCUDataPack.c
 *
 */
 
/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataPack.h"



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_Res dataPackinit(s_eCU_DataPackCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize, 
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
				ctx->memPoolCntr = 0u;
				
				result = ECU_RES_OK;
			}			
		}

	return result;
}

e_eCU_Res dataPackReset(s_eCU_DataPackCtx* const ctx)
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
			ctx->memPoolCntr = 0u;
			result = ECU_RES_OK;		
		}

	return result;
}

e_eCU_Res dataPackGetDataSize(s_eCU_DataPackCtx* const ctx, uint32_t* const retrivedLen)
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
			*retrivedLen = ctx->memPoolCntr;
			
			result = ECU_RES_OK;			
		}

	return result;
}

e_eCU_Res dataPackGetDataArray(s_eCU_DataPackCtx* const ctx, uint8_t** datapointer, uint32_t* const retrivedLen)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == datapointer ) || ( NULL == retrivedLen ) )
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
			*datapointer = ctx->memPool;
			*retrivedLen = ctx->memPoolCntr;
			
			result = ECU_RES_OK;			
		}

	return result;
}

e_eCU_Res dataPackConsumeAllData(s_eCU_DataPackCtx* const ctx, uint8_t* const dataDest, uint32_t* const retrivedLen, 
								 const uint32_t dataDestMaxSize)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataDest ) || ( NULL == retrivedLen ) )
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
			if( dataDestMaxSize <= 0u )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				if( ctx->memPoolCntr > dataDestMaxSize )
				{
					result = ECU_RES_OUTOFMEM;
				}
				else
				{
					/* Copy the data */
					if( ctx->memPoolCntr > 0u )
					{
						memcpy(dataDest, ctx->memPool, ctx->memPoolCntr);
					}
					
					*retrivedLen = ctx->memPoolCntr;
					
					/* Reset data index */
					ctx->memPoolCntr = 0u;
					result = ECU_RES_OK;
				}
			}
		}

	return result;
}

e_eCU_Res dataPackPushArray(s_eCU_DataPackCtx* const ctx, const uint8_t* data, const uint32_t dataLen)
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
				if( ( ctx->memPoolCntr + dataLen ) > ctx->memPoolSize )
				{
					result = ECU_RES_OUTOFMEM;
				}
				else
				{
					/* Copy data */
					memcpy(&ctx->memPool[ctx->memPoolCntr], data, dataLen);

					/* Update index */
					ctx->memPoolCntr += dataLen;

					result = ECU_RES_OK;
				}	
			}
		}

	return result;
}

e_eCU_Res dataPackPushU8(s_eCU_DataPackCtx* const ctx, const uint8_t dataToPush)
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
			/* Check data validity */
			if( ( ctx->memPoolCntr + sizeof(uint8_t) ) > ctx->memPoolSize )
			{
				/* no free memory */
				result = ECU_RES_OUTOFMEM;
			}
			else
			{
				/* Copy data */
				ctx->memPool[ctx->memPoolCntr] = dataToPush;
				
				/* Update index */
				ctx->memPoolCntr++;
				
				result = ECU_RES_OK;			
			}
		}

	return result;
}

e_eCU_Res dataPackPushU16(s_eCU_DataPackCtx* const ctx, const uint16_t dataToPush)
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
			/* Check data validity */
			if( ( ctx->memPoolCntr + sizeof(uint16_t) ) > ctx->memPoolSize )
			{
				/* no free memory */
				result = ECU_RES_OUTOFMEM;
			}
			else
			{
				if( true == ctx->isLE)
				{
					/* Copy data Little endian */
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush        ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCntr++;
				}
				else
				{
					/* Copy data big endian */
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush        ) & 0xFF );
					memPoolCntr++;
				}

				result = ECU_RES_OK;
			}
		}

	return result;
}

e_eCU_Res dataPackPushU32(s_eCU_DataPackCtx* const ctx, const uint32_t dataToPush)
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
			/* Check data validity */
			if( ( ctx->memPoolCntr + sizeof(uint32_t) ) > ctx->memPoolSize )
			{
				/* no free memory */
				result = ECU_RES_OUTOFMEM;
			}
			else
			{
				if( true == ctx->isLE)
				{
					/* Copy data Little endian */
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush        ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 16u ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 24u ) & 0xFF );
					memPoolCntr++;					
				}
				else
				{
					/* Copy data big endian */
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 24u ) & 0xFF );
					memPoolCntr++;	
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 16u ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush        ) & 0xFF );
					memPoolCntr++;
				}

				result = ECU_RES_OK;
			}
		}

	return result;
}

e_eCU_Res dataPackPushU64(s_eCU_DataPackCtx* const ctx, const uint64_t dataToPush)
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
			/* Check data validity */
			if( ( ctx->memPoolCntr + sizeof(uint64_t) ) > ctx->memPoolSize )
			{
				/* no free memory */
				result = ECU_RES_OUTOFMEM;
			}
			else
			{
				if( true == ctx->isLE)
				{
					/* Copy data Little endian */
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush        ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 16u ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 24u ) & 0xFF );
					memPoolCntr++;		
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 32u ) & 0xFF );
					memPoolCntr++;	
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 40u ) & 0xFF );
					memPoolCntr++;		
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 48u ) & 0xFF );
					memPoolCntr++;	
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 56u ) & 0xFF );
					memPoolCntr++;						
				}
				else
				{
					/* Copy data big endian */
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 56u ) & 0xFF );
					memPoolCntr++;					
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 48u ) & 0xFF );
					memPoolCntr++;						
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 40u ) & 0xFF );
					memPoolCntr++;					
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 32u ) & 0xFF );
					memPoolCntr++;						
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 24u ) & 0xFF );
					memPoolCntr++;	
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 16u ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCntr++;
					ctx->memPool[ctx->memPoolCntr] = ( ( dataToPush        ) & 0xFF );
					memPoolCntr++;
				}

				result = ECU_RES_OK;
			}
		}

	return result;
}


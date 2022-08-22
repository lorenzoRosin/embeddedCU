/**
 * @file eCUDataPack.c
 *
 */

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataPack.h"

/***********************************************************************************************************************
 *      DEFINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      PRIVATE TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *   PRIVATE STATIC FUNCTIONS PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  STATIC VARIABLES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *      MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_Res dataPackinit(s_eCU_DataPackCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize, const bool_t isLittleEndian)
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
			if( true == ctx->isInitialized )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				ctx->isInitialized = true;
				ctx->isLE = isLittleEndian;
				ctx->memPool = memPool;
				ctx->memPoolSize = memPoolSize;
				ctx->memPoolCounter = 0u;
				
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
		if( false == ctx->isInitialized )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
			/* Clean memory */
			memset( ctx->memPool, 0u, ctx->memPoolSize );
			
			/* Update index */
			ctx->memPoolCounter = 0u;
			result = ECU_RES_OK;		
		}

	return result;
}


e_eCU_Res dataPackGetData(s_eCU_DataPackCtx* const ctx, uint8_t* const dataDest, uint32_t* const retrivedLen, const uint32_t dataDestMaxSize);
{
	/* Local variable */
	e_eCU_Res result;
	uint32_t dataToCopy;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataDest ) || ( NULL == retrivedLen ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInitialized )
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
				if( ctx->memPoolCounter > dataDestMaxSize )
				{
					dataToCopy = dataDestMaxSize;
				}
				else
				{
					dataToCopy = ctx->memPoolCounter;
				}
				
				/* Clean memory */
				memset( ctx->memPool, 0u, ctx->memPoolSize );
				
				/* Update index */
				ctx->memPoolCounter = 0u;
				result = ECU_RES_OK;			
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
		if( false == ctx->isInitialized )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
			/* Check data validity */
			if( ( ctx->memPoolCounter + sizeof(dataToPush) ) > ctx->memPoolSize )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				/* Copy data */
				ctx->memPool[ctx->memPoolCounter] = dataToPush;
				
				/* Update index */
				ctx->memPoolCounter++;
				
				result = ECU_RES_OK;			
			}
		}

	return result;
}

 e_eCU_Res dataPackPushI8(s_eCU_DataPackCtx* const ctx, const int8_t  dataToPush)
{
	/* Local variable */
	uint8_t  dataToPushCopy;
	
	if(dataToPush >= 0)
	{
		dataToPushCopy = (uint8_t)dataToPush;
	}
	else
	{
		dataToPushCopy = (uint8_t)(-dataToPush);
		dataToPushCopy |= 0x80;
	}
	
	return dataPackPushU8(ctx, dataToPushCopy);
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
		if( false == ctx->isInitialized )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
			/* Check data validity */
			if( ( ctx->memPoolCounter + sizeof(dataToPush) ) > ctx->memPoolSize )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				if( true == ctx->isLE)
				{
					/* Copy data Little endian */
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush        ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCounter++;
				}
				else
				{
					/* Copy data big endian */
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush        ) & 0xFF );
					memPoolCounter++;
				}

				result = ECU_RES_OK;
			}
		}

	return result;
}


e_eCU_Res dataPackPushI16(s_eCU_DataPackCtx* const ctx, const int16_t dataToPush)
{
	/* Local variable */
	uint16_t  dataToPushCopy;
	
	if(dataToPush >= 0)
	{
		dataToPushCopy = (uint16_t)dataToPush;
	}
	else
	{
		dataToPushCopy = (uint16_t)(-dataToPush);
		dataToPushCopy |= 0x8000;
	}
	
	return dataPackPushU16(ctx, dataToPushCopy);
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
		if( false == ctx->isInitialized )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
			/* Check data validity */
			if( ( ctx->memPoolCounter + sizeof(dataToPush) ) > ctx->memPoolSize )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				if( true == ctx->isLE)
				{
					/* Copy data Little endian */
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush        ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 16u ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 24u ) & 0xFF );
					memPoolCounter++;					
				}
				else
				{
					/* Copy data big endian */
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 24u ) & 0xFF );
					memPoolCounter++;	
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 16u ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush        ) & 0xFF );
					memPoolCounter++;
				}

				result = ECU_RES_OK;
			}
		}

	return result;
}

e_eCU_Res dataPackPushI32(s_eCU_DataPackCtx* const ctx, const int32_t dataToPush)
{
	/* Local variable */
	uint32_t  dataToPushCopy;
	
	if(dataToPush >= 0)
	{
		dataToPushCopy = (uint32_t)dataToPush;
	}
	else
	{
		dataToPushCopy = (uint32_t)(-dataToPush);
		dataToPushCopy |= 0x80000000;
	}
	
	return dataPackPushU32(ctx, dataToPushCopy);
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
		if( false == ctx->isInitialized )
		{
			result = ECU_RES_NOINITLIB;
		}
		else
		{
			/* Check data validity */
			if( ( ctx->memPoolCounter + sizeof(dataToPush) ) > ctx->memPoolSize )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				if( true == ctx->isLE)
				{
					/* Copy data Little endian */
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush        ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 16u ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 24u ) & 0xFF );
					memPoolCounter++;		
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 32u ) & 0xFF );
					memPoolCounter++;	
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 40u ) & 0xFF );
					memPoolCounter++;		
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 48u ) & 0xFF );
					memPoolCounter++;	
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 56u ) & 0xFF );
					memPoolCounter++;						
				}
				else
				{
					/* Copy data big endian */
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 56u ) & 0xFF );
					memPoolCounter++;					
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 48u ) & 0xFF );
					memPoolCounter++;						
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 40u ) & 0xFF );
					memPoolCounter++;					
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 32u ) & 0xFF );
					memPoolCounter++;						
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 24u ) & 0xFF );
					memPoolCounter++;	
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 16u ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush >> 8u  ) & 0xFF );
					memPoolCounter++;
					ctx->memPool[ctx->memPoolCounter] = ( ( dataToPush        ) & 0xFF );
					memPoolCounter++;
				}

				result = ECU_RES_OK;
			}
		}

	return result;
}


e_eCU_Res dataPackPushI64(s_eCU_DataPackCtx* const ctx, const int64_t  dataToPush)
{
	/* Local variable */
	uint64_t  dataToPushCopy;
	
	if(dataToPush >= 0)
	{
		dataToPushCopy = (uint64_t)dataToPush;
	}
	else
	{
		dataToPushCopy = (uint64_t)(-dataToPush);
		dataToPushCopy |= 0x80000000000000000;
	}
	
	return dataPackPushI64(ctx, dataToPushCopy);
}

/**
 * @file eCUDataUnPack.c
 *
 */

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUdataUnPack.h"

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
e_eCU_Res dataUnPackinit(s_eCU_DataUnPackCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize, const bool_t isLittleEndian)
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


e_eCU_Res dataUnPackAddData(s_eCU_DataUnPackCtx* const ctx, uint8_t* const data, uint32_t const dataLen)
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
		if( false == ctx->isInitialized )
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
				if( ctx->dataLen > memPoolSize )
				{
					result = ECU_RES_BADPARAM;
				}
				else
				{
					/* Clean memory */
					memcpy( ctx->memPool, data, ctx->dataLen );
					
					/* Update index */
					ctx->memPoolCounter = 0u;
					ctx->memPoolFillSize = dataLen;
					result = ECU_RES_OK;		
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
			if( ( ctx->memPoolCounter + sizeof(uint8_t) ) > ctx->memPoolFillSize )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				/* Copy data */
				*dataToPop = ctx->memPool[ctx->memPoolCounter];
				
				/* Update index */
				ctx->memPoolCounter++;
				result = ECU_RES_OK;			
			}
		}

	return result;
}

 e_eCU_Res dataUnPackPopI8(s_eCU_DataUnPackCtx* const ctx, int8_t*  dataToPop)
{
	/* Local variable */
	e_eCU_Res result;
	uint8_t  dataToPopCopy;
	
	result = dataUnPackPopU8(ctx, &dataToPopCopy);
	
	
	if(  0x00 == (dataToPopCopy & 0x80) )
	{
		*dataToPop = (int8_t)dataToPopCopy;
	}
	else
	{
		dataToPopCopy = (uint8_t)( dataToPopCopy & 0x7F );
		*dataToPop  = - ((uint8_t)dataToPopCopy);
	}
	
	return dataUnPackPopU8(ctx, dataToPopCopy);
}


e_eCU_Res dataUnPackPopU16(s_eCU_DataUnPackCtx* const ctx, uint16_t* dataToPop)
{
	/* Local variable */
	e_eCU_Res result;
	uint32_t startCnt;
	
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
			if( ( ctx->memPoolCounter + sizeof(uint16_t) ) > ctx->memPoolFillSize )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				startCnt = memPoolCounter;
				if( true == ctx->isLE)
				{
					/* Copy data Little endian */
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter]        ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 8u  ) & 0xFF );
					memPoolCounter++;
				}
				else
				{
					/* Copy data big endian */
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 8u  ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt]= ( ( ctx->memPool[ctx->memPoolCounter]        ) & 0xFF );
					memPoolCounter++;
				}

				result = ECU_RES_OK;
			}
		}

	return result;
}


e_eCU_Res dataUnPackPopI16(s_eCU_DataUnPackCtx* const ctx, int16_t* dataToPop)
{
	/* Local variable */
	e_eCU_Res result;
	uint8_t  dataToPopCopy;
	
	result = dataUnPackPopU8(ctx, &dataToPopCopy);
	
	
	if(  0x00 == (dataToPopCopy & 0x80) )
	{
		*dataToPop = (int8_t)dataToPopCopy;
	}
	else
	{
		dataToPopCopy = (uint8_t)( dataToPopCopy & 0x7F );
		*dataToPop  = - ((uint8_t)dataToPopCopy);
	}
	
	return dataUnPackPopU8(ctx, dataToPopCopy);
}


e_eCU_Res dataUnPackPopU32(s_eCU_DataUnPackCtx* const ctx, uint32_t* dataToPop)
{
	/* Local variable */
	e_eCU_Res result;
	uint32_t startCnt;

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
			if( ( ctx->memPoolCounter + sizeof(uint32_t) ) > ctx->memPoolFillSize )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				startCnt = memPoolCounter;
				if( true == ctx->isLE)
				{
					/* Copy data Little endian */
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter]        ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 8u  ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 16u ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 24u ) & 0xFF );
					memPoolCounter++;					
				}
				else
				{
					/* Copy data big endian */
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 24u ) & 0xFF );
					memPoolCounter++;	
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 16u ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 8u  ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter]        ) & 0xFF );
					memPoolCounter++;
				}

				result = ECU_RES_OK;
			}
		}

	return result;
}

e_eCU_Res dataUnPackPopI32(s_eCU_DataUnPackCtx* const ctx, int32_t* dataToPop)
{
	/* Local variable */
	e_eCU_Res result;
	uint8_t  dataToPopCopy;
	
	result = dataUnPackPopU8(ctx, &dataToPopCopy);
	
	
	if(  0x00 == (dataToPopCopy & 0x80) )
	{
		*dataToPop = (int8_t)dataToPopCopy;
	}
	else
	{
		dataToPopCopy = (uint8_t)( dataToPopCopy & 0x7F );
		*dataToPop  = - ((uint8_t)dataToPopCopy);
	}
	
	return dataUnPackPopU8(ctx, dataToPopCopy);
}


e_eCU_Res dataUnPackPopU64(s_eCU_DataUnPackCtx* const ctx, uint64_t* dataToPop)
{
	/* Local variable */
	e_eCU_Res result;
	uint32_t startCnt;
	
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
			if( ( ctx->memPoolCounter + sizeof(uint64_t) ) > ctx->memPoolFillSize )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				startCnt = memPoolCounter;
				if( true == ctx->isLE)
				{
					/* Copy data Little endian */
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter]        ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 8u  ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 16u ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 24u ) & 0xFF );
					memPoolCounter++;		
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 32u ) & 0xFF );
					memPoolCounter++;	
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 40u ) & 0xFF );
					memPoolCounter++;		
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 48u ) & 0xFF );
					memPoolCounter++;	
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 56u ) & 0xFF );
					memPoolCounter++;						
				}
				else
				{
					/* Copy data big endian */
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 56u ) & 0xFF );
					memPoolCounter++;					
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 48u ) & 0xFF );
					memPoolCounter++;						
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 40u ) & 0xFF );
					memPoolCounter++;					
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 32u ) & 0xFF );
					memPoolCounter++;						
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 24u ) & 0xFF );
					memPoolCounter++;	
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 16u ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter] >> 8u  ) & 0xFF );
					memPoolCounter++;
					( (uint8_t*) dataToPop )[memPoolCounter - startCnt] = ( ( ctx->memPool[ctx->memPoolCounter]        ) & 0xFF );
					memPoolCounter++;
				}

				result = ECU_RES_OK;
			}
		}

	return result;
}


e_eCU_Res dataUnPackPopI64(s_eCU_DataUnPackCtx* const ctx, int64_t*  dataToPop)
{
	/* Local variable */
	e_eCU_Res result;
	uint8_t  dataToPopCopy;
	
	result = dataUnPackPopU8(ctx, &dataToPopCopy);
	
	
	if(  0x00 == (dataToPopCopy & 0x80) )
	{
		*dataToPop = (int8_t)dataToPopCopy;
	}
	else
	{
		dataToPopCopy = (uint8_t)( dataToPopCopy & 0x7F );
		*dataToPop  = - ((uint8_t)dataToPopCopy);
	}
	
	return dataUnPackPopU8(ctx, dataToPopCopy);
}

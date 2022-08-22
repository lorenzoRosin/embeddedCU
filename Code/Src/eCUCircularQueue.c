/**
 * @file eCUCircularQueue.c
 *
 */

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUCircularQueue.h"

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
 e_eCU_Res circularQueueInit(s_eCU_CircularQueueCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize)
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
				ctx->memPool = memPool;
				ctx->memPoolSize = memPoolSize;
				ctx->memPoolOccupiedSize = 0u;
				ctx->memPoolFirstFreeByteIndex = 0u;
				ctx->memPoolFirstOccupiedByteIndex = 0u;
				
				result = ECU_RES_OK;
			}			
		}

	return result;
}


 e_eCU_Res circularQueueReset(s_eCU_CircularQueueCtx* const ctx)
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
			ctx->memPoolOccupiedSize = 0u;
			ctx->memPoolFirstFreeByteIndex = 0u;
			ctx->memPoolFirstOccupiedByteIndex = 0u;
			result = ECU_RES_OK;		
		}

	return result;
}



e_eCU_Res circularQueueGetFreeSapce(s_eCU_CircularQueueCtx* const ctx, uint32_t* freeSpace)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == freeSpace ) )
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
			*freeSpace = ctx->memPoolSize - ctx->memPoolOccupiedSize;
			result = ECU_RES_OK;			
		}

	return result;
}



e_eCU_Res circularQueueGetOccupiedSapce(s_eCU_CircularQueueCtx* const ctx, uint32_t* occupiedSpace)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == occupiedSpace ) )
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
			*occupiedSpace = ctx->memPoolOccupiedSize;
			result = ECU_RES_OK;			
		}

	return result;
}


 e_eCU_Res circularQueueInsertData(s_eCU_CircularQueueCtx* const ctx, uint32_t* data, uint32_t datalen)
 {
	/* Local variable */
	e_eCU_Res result;
	uint32_t freeSpace;
	uint32_t firstTransh;
	uint32_t secondTransh
	
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
			if( datalen <= 0u )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				result = circularQueueGetFreeSapce(ctx, &freeSpace);
				if( ECU_RES_OK == result )
				{
					if( datalen > freeSpace)
					{
						result = ECU_RES_BADPARAM;
					}
					else
					{
						if( ( datalen +  ctx->memPoolFirstFreeByteIndex ) <= ctx->memPoolSize )
						{
							/* Direct copy */
							memcpy(&ctx->memPool[ctx->memPoolFirstFreeByteIndex], data, datalen);
							ctx->memPoolFirstFreeByteIndex += datalen;
							if(ctx->memPoolFirstFreeByteIndex >= ctx->memPoolSize)
							{
								ctx->memPoolFirstFreeByteIndex = 0;
							}
						}
						else
						{
							/* Multicopy */
				
							/* First round */
							firstTransh = ctx->memPoolSize - ctx->memPoolFirstFreeByteIndex;
							memcpy(&ctx->memPool[ctx->memPoolFirstFreeByteIndex], data, firstTransh);
							ctx->memPoolFirstFreeByteIndex = 0;
				
							/* Second round */
							secondTransh = datalen - firstTransh;
							memcpy(&ctx->memPool[ctx->memPoolFirstFreeByteIndex], &data[firstTransh], secondTransh);
							ctx->memPoolFirstFreeByteIndex += secondTransh;
						}
				
						ctx->memPoolOccupiedSize += datalen;
						result = ECU_RES_OK;						
					}					
				}
			}
		}

	return result;
 }
 


 e_eCU_Res circularQueueInsertData(s_eCU_CircularQueueCtx* const ctx, uint32_t* data, uint32_t datalen)
 {
	/* Local variable */
	e_eCU_Res result;
	uint32_t freeSpace;
	uint32_t firstTransh;
	uint32_t secondTransh
	
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
			if( datalen <= 0u )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				result = circularQueueGetFreeSapce(ctx, &freeSpace);
				if( ECU_RES_OK == result )
				{
					if( datalen > freeSpace)
					{
						result = ECU_RES_BADPARAM;
					}
					else
					{
						if( ( datalen +  ctx->memPoolFirstFreeByteIndex ) <= ctx->memPoolSize )
						{
							/* Direct copy */
							memcpy(&ctx->memPool[ctx->memPoolFirstFreeByteIndex], data, datalen);
							ctx->memPoolFirstFreeByteIndex += datalen;
							if(ctx->memPoolFirstFreeByteIndex >= ctx->memPoolSize)
							{
								ctx->memPoolFirstFreeByteIndex = 0;
							}
						}
						else
						{
							/* Multicopy */
				
							/* First round */
							firstTransh = ctx->memPoolSize - ctx->memPoolFirstFreeByteIndex;
							memcpy(&ctx->memPool[ctx->memPoolFirstFreeByteIndex], data, firstTransh);
							ctx->memPoolFirstFreeByteIndex = 0;
				
							/* Second round */
							secondTransh = datalen - firstTransh;
							memcpy(&ctx->memPool[ctx->memPoolFirstFreeByteIndex], &data[firstTransh], secondTransh);
							ctx->memPoolFirstFreeByteIndex += secondTransh;
						}
				
						ctx->memPoolOccupiedSize += datalen;
						result = ECU_RES_OK;						
					}					
				}
			}
		}

	return result;
 }
 

 e_eCU_Res circularQueueRetriveData(s_eCU_CircularQueueCtx* const ctx, uint32_t* data, uint32_t datalen)
 {
	/* Local variable */
	e_eCU_Res result;
	uint32_t occupiedSpace;
	uint32_t firstTransh;
	uint32_t secondTransh
	
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
			if( datalen <= 0u )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				result = circularQueueGetOccupiedSapce(ctx, &occupiedSpace);
				if( ECU_RES_OK == result )
				{
					if( datalen > occupiedSpace)
					{
						result = ECU_RES_BADPARAM;
					}
					else
					{
						if( ( datalen +  ctx->memPoolFirstOccupiedByteIndex ) <= ctx->memPoolSize )
						{
							/* Direct copy */
							memcpy(data, &ctx->memPool[ctx->memPoolFirstOccupiedByteIndex], datalen);
							ctx->memPoolFirstOccupiedByteIndex += datalen;
							if(ctx->memPoolFirstOccupiedByteIndex >= ctx->memPoolSize)
							{
								ctx->memPoolFirstOccupiedByteIndex = 0;
							}
						}
						else
						{
							/* Multicopy */
				
							/* First round */
							firstTransh = ctx->memPoolSize - ctx->memPoolFirstOccupiedByteIndex;
							memcpy(data, &ctx->memPool[ctx->memPoolFirstOccupiedByteIndex], firstTransh);
							ctx->memPoolFirstOccupiedByteIndex = 0;
				
							/* Second round */
							secondTransh = datalen - firstTransh;
							memcpy(&data[firstTransh], &ctx->memPool[ctx->memPoolFirstOccupiedByteIndex], secondTransh);
							ctx->memPoolFirstOccupiedByteIndex += secondTransh;
						}
				
						ctx->memPoolOccupiedSize -= datalen;
						result = ECU_RES_OK;						
					}					
				}
			}
		}

	return result;
 }
 
 
 
e_eCU_Res circularQueuePeekData(s_eCU_CircularQueueCtx* const ctx, uint32_t* data, uint32_t datalen)
 {
	/* Local variable */
	e_eCU_Res result;
	uint32_t occupiedSpace;
	uint32_t firstTransh;
	uint32_t secondTransh
	
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
			if( datalen <= 0u )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				result = circularQueueGetOccupiedSapce(ctx, &occupiedSpace);
				if( ECU_RES_OK == result )
				{
					if( datalen > occupiedSpace)
					{
						result = ECU_RES_BADPARAM;
					}
					else
					{
						if( ( datalen +  ctx->memPoolFirstOccupiedByteIndex ) <= ctx->memPoolSize )
						{
							/* Direct copy */
							memcpy(data, &ctx->memPool[ctx->memPoolFirstOccupiedByteIndex], datalen);
						}
						else
						{
							/* Multicopy */
				
							/* First round */
							firstTransh = ctx->memPoolSize - ctx->memPoolFirstOccupiedByteIndex;
							memcpy(data, &ctx->memPool[ctx->memPoolFirstOccupiedByteIndex], firstTransh);
				
							/* Second round */
							secondTransh = datalen - firstTransh;
							memcpy(&data[firstTransh], &ctx->memPool[0u], secondTransh);
						}
				
						result = ECU_RES_OK;						
					}					
				}
			}
		}

	return result;
 } 
/**
 * @file eCUByteStuffer.c
 *
 */

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteStuffer.h"



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_Res bStuffer_init(e_eCU_BStuffCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize)
{
	/* Local variable */
	e_eCU_Res result;
	
	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == memPool ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
		if( true == ctx->isInit )
		{
			result = ECU_RES_BADPARAM;
		}
		else
		{
			if( memPoolSize < ECU_BSTF_MINPOOLSIZE )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				/* Initialize internal status */
				ctx->isInit = true;
				ctx->memPool = memPool;
				ctx->memPoolSize = memPoolSize;
				ctx->memPoolCntr = 0u;
				ctx->frameStarted = false;
				ctx->frameEnded = false;
				ctx->previousWasEsc = false;
				ctx->dataToElab = 0u;
				ctx->currentState = BSTUFF_NOACTION;
				
				result = ECU_RES_OK;				
			}
		}
	}

	return result;
}

e_eCU_Res bStuffer_resetFrame(e_eCU_BStuffCtx* const ctx)
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
			/* Initialize internal status */
			ctx->memPoolCntr = 0u;
			ctx->frameStarted = false;
			ctx->frameEnded = false;
			ctx->previousWasEsc = false;
			ctx->dataToElab = 0u;
			ctx->currentState = BSTUFF_NOACTION;
			
			result = ECU_RES_OK;
		}
	}

	return result;
}


e_eCU_Res bStuffer_startFrame(e_eCU_BStuffCtx* const ctx)
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
			/* Can start a frame only if we are not doing nothing */
			if ( ( BSTUFF_NOACTION != ctx->currentState ) || ( true == ctx->frameStarted ) )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				/* Prepare internal state */
				ctx->frameStarted = true;
				ctx->frameEnded = false;
				ctx->previousWasEsc = false;
				ctx->dataToElab = 0u;
				ctx->memPoolCntr = 0u;
				
				/* Insert SOF */
				ctx->memPool[ctx->memPoolCntr] = ECU_SOF;
				ctx->memPoolCntr++;
				
				/* Check next status */
				if( ctx->memPoolCntr >= ctx->memPoolSize )
				{
					ctx->currentState = BSTUFF_RETRIVE;
				}
				else
				{
					ctx->currentState = BSTUFF_INSERTRETRIVE;
				}
				
				result = ECU_RES_OK;				
			}
		}
	}

	return result;
}

e_eCU_Res bStuffer_endFrame(e_eCU_BStuffCtx* const ctx)
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
			/* Can start a frame only if we are not doing nothing */
			if ( ( BSTUFF_NOACTION != ctx->currentState ) || ( true == ctx->frameStarted ) )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				/* Prepare internal state */
				ctx->frameStarted = true;
				ctx->frameEnded = false;
				ctx->previousWasEsc = false;
				ctx->dataToElab = 0u;
				ctx->memPoolCntr = 0u;
				
				/* Insert SOF */
				ctx->memPool[ctx->memPoolCntr] = ECU_SOF;
				ctx->memPoolCntr++;
				
				/* Check next status */
				if( ctx->memPoolCntr >= ctx->memPoolSize )
				{
					ctx->currentState = BSTUFF_RETRIVE;
				}
				else
				{
					ctx->currentState = BSTUFF_INSERTRETRIVE;
				}
				
				result = ECU_RES_OK;				
			}
		}
	}

	return result;
}



e_eCU_Res bStuffer_getState(e_eCU_BStuffCtx* const ctx, e_eCU_BStuffState* const state);
{
	/* Local variable */
	e_eCU_Res result;
	
	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == state) )
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
			/* Sanity check */
			if ( ( ( ctrue == tx->previousWasEsc ) && ( ( ctrue == tx->needSof ) || ( ctrue == tx->needEof ) ) ) || 
				 ( ( ctrue == tx->needSof ) && ( ( ctrue == tx->previousWasEsc ) || ( ctrue == tx->needEof ) ) ) || 
				 ( ( ctrue == tx->needEof ) && ( ( ctrue == tx->needSof ) || ( ctrue == tx->previousWasEsc ) ) ) || )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				*state = ctx->currentState;
				result = ECU_RES_OK;
			}
		}
	}

	return result;
}


e_eCU_Res bStuffer_digest(e_eCU_BStuffCtx* const ctx, uint8_t dataToStuff)
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
			/* Sanity check */
			if ( ( BSTUFF_NOACTION == ctx->currentState ) || ( BSTUFF_RETRIVE == tctx->currentState ) || 
				 ( true == tx->previousWasEsc ) ||  ( true == tx->needSof ) || ( true == tx->needEof ) )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				/* Can insert data */
				if( (ECU_SOF == dataToStuff ) || (ECU_EOF == dataToStuff ) || (ECU_ESC == dataToStuff ) )
				{
					/* First insert escape, and after insert negation */
					ctx->currentState = BSTUFF_RETRIVE;
					ctx->previousWasEsc = true;
				}
				else
				{
					/* Raw data */
					ctx->currentState = BSTUFF_RETRIVE;
				}
				result = ECU_RES_OK;
			}					
		}
	}

	return result;	
}


e_eCU_Res bStuffer_retriveData(e_eCU_BStuffCtx* const ctx, uint8_t* const dataStuffed)
{
	/* Local variable */
	e_eCU_Res result;
	
	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == dataStuffed) )
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
			/* Sanity check */
			if ( ( BSTUFF_RETRIVE != tctx->currentState ) ||
     			 ( ( ctrue == tx->previousWasEsc ) && ( ( ctrue == tx->needSof ) || ( ctrue == tx->needEof ) ) ) || 
				 ( ( ctrue == tx->needSof ) && ( ( ctrue == tx->previousWasEsc ) || ( ctrue == tx->needEof ) ) ) || 
				 ( ( ctrue == tx->needEof ) && ( ( ctrue == tx->needSof ) || ( ctrue == tx->previousWasEsc ) ) ) || ) )
			{
				result = ECU_RES_BADPARAM;
			}
			else
			{
				/* Can insert data */
				if( true == tx->needSof )
				{
					/* First insert escape, and after insert negation */
					ctx->currentState = BSTUFF_RETRIVE;
					ctx->previousWasEsc = true;
				}
				else if( true == tx->needEof )
				{
					/* Raw data */
					ctx->currentState = BSTUFF_RETRIVE;
				}
				else if( true == tx->previousWasEsc )
				{
					/* Raw data */
					ctx->currentState = BSTUFF_RETRIVE;
				}
				else
				{
					/* Raw data */
				}
				result = ECU_RES_OK;
			}					
		}
	}

	return result;	
}




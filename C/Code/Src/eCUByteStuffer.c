/**
 * @file eCUByteStuffer.c
 *
 */

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteStuffer.h"



/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t isBSStatusStillCoherent(const e_eCU_BStuffCtx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_Res bStuffer_initCtx(e_eCU_BStuffCtx* const ctx, uint8_t* const memArea, const uint32_t memAreaSize)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == memArea ) )
	{
		result = ECU_RES_BADPOINTER;
	}
	else
	{
        /* Check data validity */
        if( memAreaSize <= 0u )
        {
            result = ECU_RES_BADPARAM;
        }
        else
        {
            /* Initialize internal status */
            ctx->isInit = true;
            ctx->memArea = memArea;
            ctx->memAreaSize = memAreaSize;
            ctx->memAreaCntr = 0u;
            ctx->precedentToCheck = false;

            result = ECU_RES_OK;
        }
	}

	return result;
}

e_eCU_Res bStuffer_reset(e_eCU_BStuffCtx* const ctx)
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
			ctx->memAreaCntr = 0u;
            ctx->precedentToCheck = false;
			result = ECU_RES_OK;
		}
	}

	return result;
}

e_eCU_Res bStuffer_getDataSize(e_eCU_BStuffCtx* const ctx, uint32_t* const retrivedLen)
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
            if( false == isBSStatusStillCoherent(ctx) )
            {
                result = ECU_RES_BADPARAM;
            }
            else
            {
                if( false == ctx->precedentToCheck )
                {
                    *retrivedLen = ctx->memAreaSize - ctx->memAreaCntr;
                }
                else
                {
                    *retrivedLen = ctx->memAreaSize - ctx->memAreaCntr + 1u;
                }

                result = ECU_RES_OK;
            }
		}
	}

	return result;
}

e_eCU_Res bStuffer_retiveElabData(e_eCU_BStuffCtx* const ctx, uint8_t* const stuffedDest, const uint32_t maxDestLen,
                                  uint8_t* const filledLen)
{
	/* Local variable */
	e_eCU_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == stuffedDest ) || ( NULL == filledLen ) )
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
            if(maxDestLen <= 0u)
            {
                result = ECU_RES_BADPARAM;
            }
            else
            {
                /* Check internal status validity */
                if( false == isBSStatusStillCoherent(ctx) )
                {
                    result = ECU_RES_BADPARAM;
                }
                else
                {
                    if( false == ctx->precedentToCheck )
                    {
                        *retrivedLen = ctx->memAreaSize - ctx->memAreaCntr;
                    }
                    else
                    {
                        *retrivedLen = ctx->memAreaSize - ctx->memAreaCntr + 1u;
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
bool_t isBSStatusStillCoherent(const e_eCU_BStuffCtx* ctx)
{
    bool_t result;

	/* Check context validity */
	if( ( ctx->memAreaSize <= 0u ) || ( NULL == ctx->memArea ) )
	{
		result = false;
	}
	else
	{
		/* Check queue data coherence */
		if( ctx->memAreaCntr > ctx->memAreaSize )
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

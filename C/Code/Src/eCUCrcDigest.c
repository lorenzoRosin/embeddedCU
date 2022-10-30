/**
 * @file       eCUCrcDigest.c
 *
 * @brief      Cal CRC using custom CRC32 using digest approach
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUCrcDigest.h"



/***********************************************************************************************************************
 *  PRIVATE STATIC FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t isCrctatusStillCoherent(const s_eCU_CrcDigestCtx* ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_CrcD_Res crcDigestInitCtx(s_eCU_CrcDigestCtx* const ctx, cb_crc32_seed cbCrcP, void* const clbCtx)
{
	/* Local variable */
	e_eCU_CrcD_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx) || ( NULL ==  cbCrcP) || ( NULL ==  clbCtx) )
	{
		result = CRCD_RES_BADPOINTER;
	}
	else
	{
        /* Init context */
		ctx->isInit = true;
		ctx->baseSeed = ECU_CRC_BASE_SEED;
		ctx->digestedTimes = 0u;
		ctx->lastDigVal = 0u;
		ctx->cbCrcPointer = cbCrcP;
        ctx->cbCrcCtx = clbCtx;

		result = CRCD_RES_OK;
    }

	return result;
}

e_eCU_CrcD_Res crcDigestSeedInitCtx(s_eCU_CrcDigestCtx* const ctx, const uint32_t seed, cb_crc32_seed cbCrcP,
                                    void* const clbCtx)
{
	/* Local variable */
	e_eCU_CrcD_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx) || ( NULL ==  cbCrcP) || ( NULL ==  clbCtx))
	{
		result = CRCD_RES_BADPOINTER;
	}
	else
	{
        /* Init context */
		ctx->isInit = true;
		ctx->baseSeed = seed;
		ctx->digestedTimes = 0u;
		ctx->lastDigVal = 0u;
		ctx->cbCrcPointer = cbCrcP;
        ctx->cbCrcCtx = clbCtx;

		result = CRCD_RES_OK;
    }

	return result;
}

e_eCU_CrcD_Res crcDigesRestart(s_eCU_CrcDigestCtx* const ctx)
{
	/* Local variable */
	e_eCU_CrcD_Res result;

	/* Check pointer validity */
	if( NULL == ctx )
	{
		result = CRCD_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = CRCD_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isCrctatusStillCoherent(ctx) )
            {
                result = CRCD_RES_CORRUPTCTX;
            }
            else
            {
                /* Init context */
                ctx->digestedTimes = 0u;
                ctx->lastDigVal = 0u;

                result = CRCD_RES_OK;
            }
        }
    }

    return result;
}

e_eCU_CrcD_Res crcDigesDigest(s_eCU_CrcDigestCtx* const ctx, const uint8_t* data, const uint32_t dataLen)
{
	/* Local variable */
	e_eCU_CrcD_Res result;
    uint32_t cR32;
    bool_t crcRes;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == data ) )
	{
		result = CRCD_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = CRCD_RES_NOINITLIB;
		}
		else
		{
			/* Check data validity */
			if( dataLen <= 0u )
			{
				result = CRCD_RES_BADPARAM;
			}
			else
			{
                /* Check internal status validity */
                if( false == isCrctatusStillCoherent(ctx) )
                {
                    result = CRCD_RES_CORRUPTCTX;
                }
                else
                {
                    /* Check if we have memory for this */
                    if( ctx->digestedTimes >= 0xFFFFFFFFu )
                    {
                        result = CRCD_RES_TOOMANYDIGEST;
                    }
                    else
                    {
                        /* First time? */
                        if( 0u >= ctx->digestedTimes )
                        {
                            /* Use base seed */
                            crcRes = (*(ctx->cbCrcPointer))( ctx->cbCrcCtx, ctx->baseSeed, data, dataLen, &cR32 );

                            if( true == crcRes )
                            {
                                ctx->digestedTimes++;
                                ctx->lastDigVal = cR32;
								result = CRCD_RES_OK;
                            }
							else
							{
								result = CRCD_RES_CLBCKREPORTERROR;
							}
                        }
                        else
                        {
                            /* Continue calc */
                            crcRes = (*(ctx->cbCrcPointer))( ctx->cbCrcCtx, ctx->lastDigVal, data, dataLen, &cR32 );

                            if( true == crcRes )
                            {
                                ctx->digestedTimes++;
                                ctx->lastDigVal = cR32;
								result = CRCD_RES_OK;
                            }
							else
							{
								result = CRCD_RES_CLBCKREPORTERROR;
							}
                        }
                    }
                }
			}
		}
    }

	return result;
}

e_eCU_CrcD_Res crcDigesGetDigestVal(s_eCU_CrcDigestCtx* const ctx, uint32_t* const crcCalc)
{
	/* Local variable */
	e_eCU_CrcD_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx ) || ( NULL == crcCalc ) )
	{
		result = CRCD_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == ctx->isInit )
		{
			result = CRCD_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == isCrctatusStillCoherent(ctx) )
            {
                result = CRCD_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity */
                if( ctx->digestedTimes <= 0u )
                {
                    result = CRCD_RES_NODIGESTDONE;
                }
                else
                {
                    /* Return digested value */
                    *crcCalc = ctx->lastDigVal;

                    /* Restart */
                    ctx->digestedTimes = 0u;
                    ctx->lastDigVal = 0u;

                    result = CRCD_RES_OK;
                }
			}
		}
    }

	return result;
}

/***********************************************************************************************************************
 *  PRIVATE FUNCTION
 **********************************************************************************************************************/
bool_t isCrctatusStillCoherent(const s_eCU_CrcDigestCtx* ctx)
{
    bool_t result;

	/* Check context validity */
	if( ( NULL == ctx->cbCrcPointer ) || ( NULL == ctx->cbCrcCtx ) )
	{
		result = false;
	}
	else
	{
        result = true;
	}

    return result;
}
/**
 * @file eCUCrcDigest.c
 *
 */

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
e_eCU_CrcD_Res crcDigestInitCtx(s_eCU_CrcDigestCtx* const ctx, cb_crc32_seed cbCrcP)
{
	/* Local variable */
	e_eCU_CrcD_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx) || ( NULL ==  cbCrcP) )
	{
		result = CRCD_RES_BADPOINTER;
	}
	else
	{
        /* Init context */
		ctx->isInit = true;
		ctx->usedBaseSeed = ECU_CRC_BASE_SEED;
		ctx->digestedTimes = 0u;
		ctx->lastDigest = 0u;
		ctx->cbCrcPointer = cbCrcP;

		result = CRCD_RES_OK;
    }

	return result;
}

e_eCU_CrcD_Res crcDigestSeedInitCtx(s_eCU_CrcDigestCtx* const ctx, const uint32_t seed, cb_crc32_seed cbCrcP)
{
	/* Local variable */
	e_eCU_CrcD_Res result;

	/* Check pointer validity */
	if( ( NULL == ctx) || ( NULL ==  cbCrcP) )
	{
		result = CRCD_RES_BADPOINTER;
	}
	else
	{
        /* Init context */
		ctx->isInit = true;
		ctx->usedBaseSeed = seed;
		ctx->digestedTimes = 0u;
		ctx->lastDigest = 0u;
		ctx->cbCrcPointer = cbCrcP;

		result = CRCD_RES_OK;
    }

	return result;
}

e_eCU_CrcD_Res crcDigesDigest(s_eCU_CrcDigestCtx* const ctx, const uint8_t* data, const uint32_t dataLen)
{
	/* Local variable */
	e_eCU_CrcD_Res result;
	e_eCU_Crc_Res crcRes;
    uint32_t cR32;

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
                        if( 0u == ctx->digestedTimes )
                        {
                            /* Use base seed */
                            crcRes = (*(ctx->cbCrcPointer))( ctx->usedBaseSeed, data, dataLen, &cR32 );

                            if( CRC_RES_OK == result )
                            {
                                ctx->digestedTimes++;
                                ctx->lastDigest = cR32;
								result = CRCD_RES_OK;
                            }
							else
							{
								result = CRCD_RES_BADPOINTER;
							}
                        }
                        else
                        {
                            /* Continue calc */
                            crcRes = (*(ctx->cbCrcPointer))( ctx->lastDigest, data, dataLen, &cR32 );

                            if( CRC_RES_OK == result )
                            {
                                ctx->digestedTimes++;
                                ctx->lastDigest = cR32;
								result = CRCD_RES_OK;
                            }
							else
							{
								result = CRCD_RES_BADPOINTER;
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
                    /* Return vgigested value */
                    *crcCalc = ctx->lastDigest;

                    /* Restart */
                    ctx->digestedTimes = 0u;
                    ctx->lastDigest = 0u;

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
	if( NULL == ctx->cbCrcPointer )
	{
		result = false;
	}
	else
	{
        result = true;
	}

    return result;
}
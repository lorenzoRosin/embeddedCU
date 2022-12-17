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
static bool_t eCU_CRCD_isStatusStillCoherent(const s_eCU_CRCD_Ctx* p_ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_CRCD_Res eCU_CRCD_InitCtx(s_eCU_CRCD_Ctx* const p_ctx, cb_crc32_seed f_Crc, cb_crc32_seed_ctx* const p_clbCtx)
{
	/* Local variable */
	e_eCU_CRCD_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx) || ( NULL ==  f_Crc) || ( NULL ==  p_clbCtx) )
	{
		l_result = CRCD_RES_BADPOINTER;
	}
	else
	{
        /* Init context */
		p_ctx->isInit = true;
		p_ctx->baseSeed = ECU_CRC_BASE_SEED;
		p_ctx->digestedTimes = 0u;
		p_ctx->lastDigVal = 0u;
		p_ctx->f_Crc = f_Crc;
        p_ctx->p_crcCtx = p_clbCtx;

		l_result = CRCD_RES_OK;
    }

	return l_result;
}

e_eCU_CRCD_Res eCU_CRCD_IsInit(s_eCU_CRCD_Ctx* const p_ctx, bool_t* p_isInit)
{
	/* Local variable */
	e_eCU_CRCD_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isInit ) )
	{
		l_result = CRCD_RES_BADPOINTER;
	}
	else
	{
        *p_isInit = p_ctx->isInit;
        l_result = CRCD_RES_OK;
	}

	return l_result;
}

e_eCU_CRCD_Res eCU_CRCD_SeedInitCtx(s_eCU_CRCD_Ctx* const p_ctx, const uint32_t seed, cb_crc32_seed f_Crc,
                                    cb_crc32_seed_ctx* const p_clbCtx)
{
	/* Local variable */
	e_eCU_CRCD_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx) || ( NULL ==  f_Crc) || ( NULL ==  p_clbCtx))
	{
		l_result = CRCD_RES_BADPOINTER;
	}
	else
	{
        /* Init context */
		p_ctx->isInit = true;
		p_ctx->baseSeed = seed;
		p_ctx->digestedTimes = 0u;
		p_ctx->lastDigVal = 0u;
		p_ctx->f_Crc = f_Crc;
        p_ctx->p_crcCtx = p_clbCtx;

		l_result = CRCD_RES_OK;
    }

	return l_result;
}

e_eCU_CRCD_Res eCU_CRCD_Restart(s_eCU_CRCD_Ctx* const p_ctx)
{
	/* Local variable */
	e_eCU_CRCD_Res l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = CRCD_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = CRCD_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_CRCD_isStatusStillCoherent(p_ctx) )
            {
                l_result = CRCD_RES_CORRUPTCTX;
            }
            else
            {
                /* Init context */
                p_ctx->digestedTimes = 0u;
                p_ctx->lastDigVal = 0u;

                l_result = CRCD_RES_OK;
            }
        }
    }

    return l_result;
}

e_eCU_CRCD_Res eCU_CRCD_Digest(s_eCU_CRCD_Ctx* const p_ctx, const uint8_t a_data[], const uint32_t dataLen)
{
	/* Local variable */
	e_eCU_CRCD_Res l_result;
    uint32_t l_cR32;
    bool_t l_cRes;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == a_data ) )
	{
		l_result = CRCD_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = CRCD_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_CRCD_isStatusStillCoherent(p_ctx) )
            {
                l_result = CRCD_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity */
                if( dataLen <= 0u )
                {
                    l_result = CRCD_RES_BADPARAM;
                }
                else
                {
                    /* Check if we have memory for this */
                    if( p_ctx->digestedTimes >= MAX_UINT32VAL )
                    {
                        l_result = CRCD_RES_TOOMANYDIGEST;
                    }
                    else
                    {
                        /* First time? */
                        if( 0u >= p_ctx->digestedTimes )
                        {
                            /* Use base seed for the first time */
                            l_cRes = (*(p_ctx->f_Crc))( p_ctx->p_crcCtx, p_ctx->baseSeed, a_data, dataLen, &l_cR32 );

                            if( true == l_cRes )
                            {
                                p_ctx->digestedTimes++;
                                p_ctx->lastDigVal = l_cR32;
								l_result = CRCD_RES_OK;
                            }
							else
							{
								l_result = CRCD_RES_CLBCKREPORTERROR;
							}
                        }
                        else
                        {
                            /* Continue calc using old digested value for seed */
                            l_cRes = (*(p_ctx->f_Crc))( p_ctx->p_crcCtx, p_ctx->lastDigVal, a_data, dataLen, &l_cR32 );

                            if( true == l_cRes )
                            {
                                p_ctx->digestedTimes++;
                                p_ctx->lastDigVal = l_cR32;
								l_result = CRCD_RES_OK;
                            }
							else
							{
								l_result = CRCD_RES_CLBCKREPORTERROR;
							}
                        }
                    }
                }
			}
		}
    }

	return l_result;
}

e_eCU_CRCD_Res eCU_CRCD_GetDigestVal(s_eCU_CRCD_Ctx* const p_ctx, uint32_t* const p_crcCalc)
{
	/* Local variable */
	e_eCU_CRCD_Res l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_crcCalc ) )
	{
		l_result = CRCD_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->isInit )
		{
			l_result = CRCD_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_CRCD_isStatusStillCoherent(p_ctx) )
            {
                l_result = CRCD_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity */
                if( p_ctx->digestedTimes <= 0u )
                {
                    /* Cannot retrive undigested value */
                    l_result = CRCD_RES_NODIGESTDONE;
                }
                else
                {
                    /* Return digested value */
                    *p_crcCalc = p_ctx->lastDigVal;

                    /* Restart */
                    p_ctx->digestedTimes = 0u;
                    p_ctx->lastDigVal = 0u;

                    l_result = CRCD_RES_OK;
                }
			}
		}
    }

	return l_result;
}



/***********************************************************************************************************************
 *  PRIVATE FUNCTION
 **********************************************************************************************************************/
static bool_t eCU_CRCD_isStatusStillCoherent(const s_eCU_CRCD_Ctx* p_ctx)
{
    bool_t l_result;

	/* Check context validity */
	if( ( NULL == p_ctx->f_Crc ) || ( NULL == p_ctx->p_crcCtx ) )
	{
		l_result = false;
	}
	else
	{
        l_result = true;
	}

    return l_result;
}
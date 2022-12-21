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
static bool_t eCU_CRCD_isStatusStillCoherent(const t_eCU_CRCD_Ctx* p_ctx);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
e_eCU_CRCD_RES eCU_CRCD_InitCtx(t_eCU_CRCD_Ctx* const p_ctx, f_eCU_CRCD_CrcCb fCrc, t_eCU_CRCD_CrcCtx* const p_clbCtx)
{
	/* Local variable */
	e_eCU_CRCD_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx) || ( NULL ==  fCrc) || ( NULL ==  p_clbCtx) )
	{
		l_result = e_eCU_CRCD_RES_BADPOINTER;
	}
	else
	{
        /* Init context */
		p_ctx->bIsInit = true;
		p_ctx->uBaseSeed = eCU_CRC_BASE_SEED;
		p_ctx->uDigestedTimes = 0u;
		p_ctx->uLastDigVal = 0u;
		p_ctx->fCrc = fCrc;
        p_ctx->ptCrcCtx = p_clbCtx;

		l_result = e_eCU_CRCD_RES_OK;
    }

	return l_result;
}

e_eCU_CRCD_RES eCU_CRCD_IsInit(t_eCU_CRCD_Ctx* const p_ctx, bool_t* p_isInit)
{
	/* Local variable */
	e_eCU_CRCD_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_isInit ) )
	{
		l_result = e_eCU_CRCD_RES_BADPOINTER;
	}
	else
	{
        *p_isInit = p_ctx->bIsInit;
        l_result = e_eCU_CRCD_RES_OK;
	}

	return l_result;
}

e_eCU_CRCD_RES eCU_CRCD_SeedInitCtx(t_eCU_CRCD_Ctx* const p_ctx, const uint32_t seed, f_eCU_CRCD_CrcCb fCrc,
                                    t_eCU_CRCD_CrcCtx* const p_clbCtx)
{
	/* Local variable */
	e_eCU_CRCD_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx) || ( NULL ==  fCrc) || ( NULL ==  p_clbCtx))
	{
		l_result = e_eCU_CRCD_RES_BADPOINTER;
	}
	else
	{
        /* Init context */
		p_ctx->bIsInit = true;
		p_ctx->uBaseSeed = seed;
		p_ctx->uDigestedTimes = 0u;
		p_ctx->uLastDigVal = 0u;
		p_ctx->fCrc = fCrc;
        p_ctx->ptCrcCtx = p_clbCtx;

		l_result = e_eCU_CRCD_RES_OK;
    }

	return l_result;
}

e_eCU_CRCD_RES eCU_CRCD_Restart(t_eCU_CRCD_Ctx* const p_ctx)
{
	/* Local variable */
	e_eCU_CRCD_RES l_result;

	/* Check pointer validity */
	if( NULL == p_ctx )
	{
		l_result = e_eCU_CRCD_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_CRCD_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_CRCD_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_CRCD_RES_CORRUPTCTX;
            }
            else
            {
                /* Init context */
                p_ctx->uDigestedTimes = 0u;
                p_ctx->uLastDigVal = 0u;

                l_result = e_eCU_CRCD_RES_OK;
            }
        }
    }

    return l_result;
}

e_eCU_CRCD_RES eCU_CRCD_Digest(t_eCU_CRCD_Ctx* const p_ctx, const uint8_t* p_data, const uint32_t dataLen)
{
	/* Local variable */
	e_eCU_CRCD_RES l_result;
    uint32_t l_cR32;
    bool_t l_cRes;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_data ) )
	{
		l_result = e_eCU_CRCD_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_CRCD_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_CRCD_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_CRCD_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity */
                if( dataLen <= 0u )
                {
                    l_result = e_eCU_CRCD_RES_BADPARAM;
                }
                else
                {
                    /* Check if we have memory for this */
                    if( p_ctx->uDigestedTimes >= MAX_UINT32VAL )
                    {
                        l_result = e_eCU_CRCD_RES_TOOMANYDIGEST;
                    }
                    else
                    {
                        /* First time? */
                        if( 0u >= p_ctx->uDigestedTimes )
                        {
                            /* Use base seed for the first time */
                            l_cRes = (*(p_ctx->fCrc))( p_ctx->ptCrcCtx, p_ctx->uBaseSeed, p_data, dataLen, &l_cR32 );

                            if( true == l_cRes )
                            {
                                p_ctx->uDigestedTimes++;
                                p_ctx->uLastDigVal = l_cR32;
								l_result = e_eCU_CRCD_RES_OK;
                            }
							else
							{
								l_result = e_eCU_CRCD_RES_CLBCKREPORTERROR;
							}
                        }
                        else
                        {
                            /* Continue calc using old digested value for seed */
                            l_cRes = (*(p_ctx->fCrc))( p_ctx->ptCrcCtx, p_ctx->uLastDigVal, p_data, dataLen, &l_cR32 );

                            if( true == l_cRes )
                            {
                                p_ctx->uDigestedTimes++;
                                p_ctx->uLastDigVal = l_cR32;
								l_result = e_eCU_CRCD_RES_OK;
                            }
							else
							{
								l_result = e_eCU_CRCD_RES_CLBCKREPORTERROR;
							}
                        }
                    }
                }
			}
		}
    }

	return l_result;
}

e_eCU_CRCD_RES eCU_CRCD_GetDigestVal(t_eCU_CRCD_Ctx* const p_ctx, uint32_t* const p_crcCalc)
{
	/* Local variable */
	e_eCU_CRCD_RES l_result;

	/* Check pointer validity */
	if( ( NULL == p_ctx ) || ( NULL == p_crcCalc ) )
	{
		l_result = e_eCU_CRCD_RES_BADPOINTER;
	}
	else
	{
		/* Check Init */
		if( false == p_ctx->bIsInit )
		{
			l_result = e_eCU_CRCD_RES_NOINITLIB;
		}
		else
		{
            /* Check internal status validity */
            if( false == eCU_CRCD_isStatusStillCoherent(p_ctx) )
            {
                l_result = e_eCU_CRCD_RES_CORRUPTCTX;
            }
			else
			{
                /* Check data validity */
                if( p_ctx->uDigestedTimes <= 0u )
                {
                    /* Cannot retrive undigested value */
                    l_result = e_eCU_CRCD_RES_NODIGESTDONE;
                }
                else
                {
                    /* Return digested value */
                    *p_crcCalc = p_ctx->uLastDigVal;

                    /* Restart */
                    p_ctx->uDigestedTimes = 0u;
                    p_ctx->uLastDigVal = 0u;

                    l_result = e_eCU_CRCD_RES_OK;
                }
			}
		}
    }

	return l_result;
}



/***********************************************************************************************************************
 *  PRIVATE FUNCTION
 **********************************************************************************************************************/
static bool_t eCU_CRCD_isStatusStillCoherent(const t_eCU_CRCD_Ctx* p_ctx)
{
    bool_t l_result;

	/* Check context validity */
	if( ( NULL == p_ctx->fCrc ) || ( NULL == p_ctx->ptCrcCtx ) )
	{
		l_result = false;
	}
	else
	{
        l_result = true;
	}

    return l_result;
}
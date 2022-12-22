/**
 * @file       eCU_CRCDTST.c
 *
 * @brief      CRC digest test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCU_CRCDTST.h"
#include "eCU_CRCD.h"
#include "eCU_CRC.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE TEST FUNCTION DECLARATION
 **********************************************************************************************************************/
struct t_eCU_CRCD_CrcCtxUser
{
    e_eCU_CRC_RES lastError;
};

static bool_t eCU_TEST_c32SAdapt(t_eCU_CRCD_CrcCtx* const p_ctx, const uint32_t s, const uint8_t* p_d, const uint32_t dLen, uint32_t* const p_c32Val);
static bool_t eCU_TEST_c32SAdaptEr(t_eCU_CRCD_CrcCtx* const p_ctx, const uint32_t s, const uint8_t* p_d, const uint32_t dLen, uint32_t* const p_c32Val);



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_TEST_cUCrcDigestBadPointer(void);
static void eCU_TEST_cUCrcDigestBadInit(void);
static void eCU_TEST_cUCrcDigestBadParamEntr(void);
static void eCU_TEST_cUCrcDigestContextStatus(void);
static void eCU_TEST_cUCrcDigestToManyOperation(void);
static void eCU_TEST_cUCrcDigestNoOperation(void);
static void eCU_TEST_cUCrcDigestClbErr(void);
static void eCU_TEST_cUCrcDigestMono(void);
static void eCU_TEST_cUCrcDigestCombined(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_CRCDTST_ExeTest(void)
{
	(void)printf("\n\nCRC DIGEST TEST START \n\n");

    eCU_TEST_cUCrcDigestBadPointer();
    eCU_TEST_cUCrcDigestBadInit();
    eCU_TEST_cUCrcDigestBadParamEntr();
    eCU_TEST_cUCrcDigestContextStatus();
    eCU_TEST_cUCrcDigestToManyOperation();
    eCU_TEST_cUCrcDigestNoOperation();
    eCU_TEST_cUCrcDigestClbErr();
    eCU_TEST_cUCrcDigestMono();
    eCU_TEST_cUCrcDigestCombined();

    (void)printf("\n\nCRC DIGEST END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE TEST FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t eCU_TEST_c32SAdapt(t_eCU_CRCD_CrcCtx* p_ctx, const uint32_t s, const uint8_t* p_d, const uint32_t dLen, uint32_t* const p_c32Val)
{
    bool_t result;

    if( ( NULL == p_ctx ) || ( NULL == p_d ) || ( NULL == p_c32Val ) )
    {
        result = false;
    }
    else
    {
        if( 0u == dLen )
        {
            result = false;
        }
        else
        {
            p_ctx->lastError = eCU_CRC_32Seed(s, p_d, dLen, p_c32Val);
            if( e_eCU_CRC_RES_OK == p_ctx->lastError )
            {
                result = true;
            }
            else
            {
                result = false;
            }
        }
    }

    return result;
}

static bool_t eCU_TEST_c32SAdaptEr(t_eCU_CRCD_CrcCtx* p_ctx, const uint32_t s, const uint8_t* p_d, const uint32_t dLen, uint32_t* const p_c32Val)
{
    bool_t result;

    (void)s;
    (void)p_d;
    (void)dLen;

    if( ( NULL == p_ctx ) || ( NULL == p_d ) || ( NULL == p_c32Val ) )
    {
        result = false;
    }
    else
    {
        if( 0u == dLen )
        {
            result = false;
        }
        else
        {
            p_ctx->lastError = e_eCU_CRC_RES_BADPOINTER;
            result = false;
            *p_c32Val = 0u;
        }
    }

    return result;
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_TEST_cUCrcDigestBadPointer(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_TEST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;

    uint8_t  la_varBuff[5u];
    uint32_t l_varTemp;
    bool_t l_isInit;

    /* Function */
    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(NULL, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 1  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(&l_ctx, NULL, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 2  -- FAIL \n");
    }


    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, NULL) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 2  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(NULL, 0x123456u, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 4  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(&l_ctx, 0x123456u, NULL, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 5  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(&l_ctx, 0x123456u, lf_cbCrcTest, NULL) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 6  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_Restart( NULL ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 7  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_Digest( NULL, la_varBuff, sizeof(la_varBuff) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 8  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_Digest( &l_ctx, NULL, sizeof(la_varBuff) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 9  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_GetDigestVal( NULL, &l_varTemp) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 10 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_GetDigestVal( &l_ctx, NULL) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 11 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_IsInit( NULL, &l_isInit ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 12 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_IsInit( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 13 -- FAIL \n");
    }
}

static void eCU_TEST_cUCrcDigestBadInit(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    uint8_t  la_varBuff[5u];
    uint32_t l_varTemp;
    bool_t l_isInit;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_NOINITLIB == eCU_CRCD_Restart( &l_ctx ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 1  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_NOINITLIB == eCU_CRCD_Digest( &l_ctx, la_varBuff, sizeof(la_varBuff) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 2  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_NOINITLIB == eCU_CRCD_GetDigestVal( &l_ctx, &l_varTemp) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 3  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_IsInit( &l_ctx, &l_isInit ) )
    {
        if( false == l_isInit )
        {
            (void)printf("eCU_TEST_cUCrcDigestBadInit 4  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_cUCrcDigestBadInit 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 4  -- FAIL \n");
    }
}

static void eCU_TEST_cUCrcDigestBadParamEntr(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_TEST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;
    bool_t l_isInit;
    uint8_t  la_varBuff[5u];
    la_varBuff[0] = 0u;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 1  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPARAM == eCU_CRCD_Digest( &l_ctx, la_varBuff, 0u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 2  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_IsInit( &l_ctx, &l_isInit ) )
    {
        if( true == l_isInit )
        {
            (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 3  -- FAIL \n");
    }
}

static void eCU_TEST_cUCrcDigestContextStatus(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_TEST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;
    uint8_t  la_varBuff[5u];
    uint32_t l_varTemp;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 1  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.fCrc = NULL;
    if( e_eCU_CRCD_RES_CORRUPTCTX == eCU_CRCD_Restart( &l_ctx ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 2  -- FAIL \n");
    }


    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 3  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.fCrc = NULL;
    if( e_eCU_CRCD_RES_CORRUPTCTX == eCU_CRCD_Digest( &l_ctx, la_varBuff, sizeof(la_varBuff) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 4  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 5  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.ptCrcCtx = NULL;
    if( e_eCU_CRCD_RES_CORRUPTCTX == eCU_CRCD_GetDigestVal( &l_ctx, &l_varTemp ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 6  -- FAIL \n");
    }
}

static void eCU_TEST_cUCrcDigestToManyOperation(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_TEST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;
    uint8_t  la_varBuff[5u];

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestToManyOperation 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestToManyOperation 1  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uDigestedTimes = 0xFFFFFFFFu;
    if( e_eCU_CRCD_RES_TOOMANYDIGEST == eCU_CRCD_Digest( &l_ctx, la_varBuff, sizeof(la_varBuff) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestToManyOperation 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestToManyOperation 2  -- FAIL \n");
    }
}

static void eCU_TEST_cUCrcDigestNoOperation(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_TEST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;
    uint32_t  l_varCarc;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestNoOperation 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestNoOperation 1  -- FAIL \n");
    }

    /* Init variable */
    if( e_eCU_CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &l_ctx, &l_varCarc ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestNoOperation 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestNoOperation 2  -- FAIL \n");
    }
}

static void eCU_TEST_cUCrcDigestClbErr(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcPTestErr = &eCU_TEST_c32SAdaptEr;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_TEST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;
    uint8_t  la_varBuff[5u];

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    l_ctxAdapterCrc.lastError = e_eCU_CRC_RES_OK;
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcPTestErr, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 1  -- FAIL \n");
    }

    /* Init variable */
    if( e_eCU_CRCD_RES_CLBCKREPORTERROR == eCU_CRCD_Digest( &l_ctx, la_varBuff, sizeof(la_varBuff) ) )
    {
        if( e_eCU_CRC_RES_BADPOINTER == l_ctxAdapterCrc.lastError )
        {
            (void)printf("eCU_TEST_cUCrcDigestClbErr 2  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_cUCrcDigestClbErr 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 2  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    l_ctxAdapterCrc.lastError = e_eCU_CRC_RES_OK;
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 3  -- FAIL \n");
    }

    /* Init variable */
    if( e_eCU_CRCD_RES_OK== eCU_CRCD_Digest( &l_ctx, la_varBuff, 1u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 4  -- FAIL \n");
    }

    l_ctx.fCrc = lf_cbCrcPTestErr;
    if( e_eCU_CRCD_RES_CLBCKREPORTERROR == eCU_CRCD_Digest( &l_ctx, la_varBuff, sizeof(la_varBuff) ) )
    {
        if( e_eCU_CRC_RES_BADPOINTER == l_ctxAdapterCrc.lastError )
        {
            (void)printf("eCU_TEST_cUCrcDigestClbErr 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_cUCrcDigestClbErr 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 5  -- FAIL \n");
    }
}

static void eCU_TEST_cUCrcDigestMono(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_TEST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;

    /* Test value */
    uint8_t la_crcTestData[] = {0xA1u, 0xB3u, 0xFFu, 0xFFu, 0x00u, 0xCFu, 0xD9u, 0x56u};
    uint32_t l_crcTestValRet;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 1  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestData, sizeof(la_crcTestData) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 2  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        if( 0xBCF43C51u == l_crcTestValRet)
        {
            (void)printf("eCU_TEST_cUCrcDigestMono 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_cUCrcDigestMono 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 3  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_SeedInitCtx(&l_ctx, 0x0u, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 4  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestData, sizeof(la_crcTestData) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 5  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        if( 0xD5F08708u == l_crcTestValRet)
        {
            (void)printf("eCU_TEST_cUCrcDigestMono 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_cUCrcDigestMono 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 6  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Restart(&l_ctx) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 7  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestData, sizeof(la_crcTestData) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 8  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        if( 0xD5F08708u == l_crcTestValRet)
        {
            (void)printf("eCU_TEST_cUCrcDigestMono 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_cUCrcDigestMono 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 9  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Restart(&l_ctx) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 10 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 11 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestData, sizeof(la_crcTestData) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 12 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        if( 0xD5F08708u == l_crcTestValRet)
        {
            (void)printf("eCU_TEST_cUCrcDigestMono 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_cUCrcDigestMono 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 13 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 14 -- FAIL \n");
    }
}

static void eCU_TEST_cUCrcDigestCombined(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_TEST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;

    /* Test value */
    uint8_t la_crcTestDataC[] = {0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0xA1u, 0xB3u, 0xFFu, 0xFFu, 0x00u, 0xCFu, 0xD9u,
                              0x56u, 0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0xA1u, 0xB3u, 0xFFu, 0xFFu, 0x00u, 0xCFu,
                              0xD9u, 0x56u };
    uint32_t l_crcTestValRetC;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 1  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestDataC, 0x02u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 2  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[2u], 0x04u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 3  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[6u], 0x04u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 4  -- FAIL \n");
    }


    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[10u], 0x12u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 5  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRetC ) )
    {
        if( 0x1CE847A8u == l_crcTestValRetC)
        {
            (void)printf("eCU_TEST_cUCrcDigestCombined 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_cUCrcDigestCombined 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 6  -- FAIL \n");
    }

     /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_SeedInitCtx(&l_ctx, 0x00u, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 7  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestDataC, 0x02u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 8  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[2u], 0x04u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 9  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[6u], 0x04u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 10 -- FAIL \n");
    }


    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[10u], 0x12u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 11 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRetC ) )
    {
        if( 0x74F9B656u == l_crcTestValRetC)
        {
            (void)printf("eCU_TEST_cUCrcDigestCombined 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_cUCrcDigestCombined 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 12 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRetC ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 13 -- FAIL \n");
    }
}
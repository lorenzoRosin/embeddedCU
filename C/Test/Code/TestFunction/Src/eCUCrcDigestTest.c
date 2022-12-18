/**
 * @file       eCUCrcDigestTest.c
 *
 * @brief      CRC digest test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUCrcDigestTest.h"
#include "eCUCrc.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE TEST FUNCTION DECLARATION
 **********************************************************************************************************************/
struct cb_crc32_seed_ctx_user
{
    e_eCU_CRC_Res lastError;
};

static bool_t eCU_TEST_c32SAdapt(cb_crc32_seed_ctx* cntx, const uint32_t s, const uint8_t* d, const uint32_t dLen, uint32_t* const c32Val);
static bool_t eCU_TEST_c32SAdaptEr(cb_crc32_seed_ctx* cntx, const uint32_t s, const uint8_t* d, const uint32_t dLen, uint32_t* const c32Val);



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
void eCU_TEST_cUCrcDigest(void)
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
static bool_t eCU_TEST_c32SAdapt(cb_crc32_seed_ctx* cntx, const uint32_t s, const uint8_t* d, const uint32_t dLen, uint32_t* const c32Val)
{
    bool_t result;

    if( ( NULL == cntx ) || ( NULL == d ) || ( NULL == c32Val ) )
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
            cntx->lastError = eCU_CRC_32Seed(s, d, dLen, c32Val);
            if( CRC_RES_OK == cntx->lastError )
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

static bool_t eCU_TEST_c32SAdaptEr(cb_crc32_seed_ctx* cntx, const uint32_t s, const uint8_t* d, const uint32_t dLen, uint32_t* const c32Val)
{
    bool_t result;

    (void)s;
    (void)d;
    (void)dLen;

    if( ( NULL == cntx ) || ( NULL == d ) || ( NULL == c32Val ) )
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
            cntx->lastError = CRC_RES_BADPOINTER;
            result = false;
            *c32Val = 0u;
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
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &eCU_TEST_c32SAdapt;
    cb_crc32_seed_ctx ctxAdapterCrc;

    uint8_t  varBuff[5u];
    uint32_t varTemp;
    bool_t isInit;

    /* Function */
    if( CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(NULL, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 1  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(&ctx, NULL, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 2  -- FAIL \n");
    }


    if( CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, NULL) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 2  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(NULL, 0x123456u, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 4  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(&ctx, 0x123456u, NULL, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 5  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(&ctx, 0x123456u, cbCrcPTest, NULL) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 6  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_Restart( NULL ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 7  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_Digest( NULL, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 8  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_Digest( &ctx, NULL, sizeof(varBuff) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 9  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_GetDigestVal( NULL, &varTemp) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 10 -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_GetDigestVal( &ctx, NULL) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 11 -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_IsInit( NULL, &isInit ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadPointer 12 -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_IsInit( &ctx, NULL ) )
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
    s_eCU_CRCD_Ctx ctx;
    uint8_t  varBuff[5u];
    uint32_t varTemp;
    bool_t isInit;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_NOINITLIB == eCU_CRCD_Restart( &ctx ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 1  -- FAIL \n");
    }

    if( CRCD_RES_NOINITLIB == eCU_CRCD_Digest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 2  -- FAIL \n");
    }

    if( CRCD_RES_NOINITLIB == eCU_CRCD_GetDigestVal( &ctx, &varTemp) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadInit 3  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_IsInit( &ctx, &isInit ) )
    {
        if( false == isInit )
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
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &eCU_TEST_c32SAdapt;
    cb_crc32_seed_ctx ctxAdapterCrc;
    bool_t isInit;
    uint8_t  varBuff[5u];
    varBuff[0] = 0u;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 1  -- FAIL \n");
    }

    if( CRCD_RES_BADPARAM == eCU_CRCD_Digest( &ctx, varBuff, 0u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestBadParamEntr 2  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_IsInit( &ctx, &isInit ) )
    {
        if( true == isInit )
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
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &eCU_TEST_c32SAdapt;
    cb_crc32_seed_ctx ctxAdapterCrc;
    uint8_t  varBuff[5u];
    uint32_t varTemp;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.f_Crc = NULL;
    if( CRCD_RES_CORRUPTCTX == eCU_CRCD_Restart( &ctx ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 2  -- FAIL \n");
    }


    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 3  -- FAIL \n");
    }

    /* Init variable */
    ctx.f_Crc = NULL;
    if( CRCD_RES_CORRUPTCTX == eCU_CRCD_Digest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 4  -- FAIL \n");
    }

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestContextStatus 5  -- FAIL \n");
    }

    /* Init variable */
    ctx.p_crcCtx = NULL;
    if( CRCD_RES_CORRUPTCTX == eCU_CRCD_GetDigestVal( &ctx, &varTemp ) )
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
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &eCU_TEST_c32SAdapt;
    cb_crc32_seed_ctx ctxAdapterCrc;
    uint8_t  varBuff[5u];

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestToManyOperation 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestToManyOperation 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.digestedTimes = 0xFFFFFFFFu;
    if( CRCD_RES_TOOMANYDIGEST == eCU_CRCD_Digest( &ctx, varBuff, sizeof(varBuff) ) )
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
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &eCU_TEST_c32SAdapt;
    cb_crc32_seed_ctx ctxAdapterCrc;
    uint32_t  varCarc;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestNoOperation 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestNoOperation 1  -- FAIL \n");
    }

    /* Init variable */
    if( CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &ctx, &varCarc ) )
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
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTestErr = &eCU_TEST_c32SAdaptEr;
    cb_crc32_seed cbCrcPTest = &eCU_TEST_c32SAdapt;
    cb_crc32_seed_ctx ctxAdapterCrc;
    uint8_t  varBuff[5u];

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    ctxAdapterCrc.lastError = CRC_RES_OK;
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTestErr, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 1  -- FAIL \n");
    }

    /* Init variable */
    if( CRCD_RES_CLBCKREPORTERROR == eCU_CRCD_Digest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        if( CRC_RES_BADPOINTER == ctxAdapterCrc.lastError )
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
    ctx.isInit = false;

    /* Function */
    ctxAdapterCrc.lastError = CRC_RES_OK;
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 3  -- FAIL \n");
    }

    /* Init variable */
    if( CRCD_RES_OK== eCU_CRCD_Digest( &ctx, varBuff, 1u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestClbErr 4  -- FAIL \n");
    }

    ctx.f_Crc = cbCrcPTestErr;
    if( CRCD_RES_CLBCKREPORTERROR == eCU_CRCD_Digest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        if( CRC_RES_BADPOINTER == ctxAdapterCrc.lastError )
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
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &eCU_TEST_c32SAdapt;
    cb_crc32_seed_ctx ctxAdapterCrc;

    /* Test value */
    uint8_t crcTestData[] = {0xA1u, 0xB3u, 0xFFu, 0xFFu, 0x00u, 0xCFu, 0xD9u, 0x56u};
    uint32_t crcTestValRet;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 1  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestData, sizeof(crcTestData) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 2  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        if( 0xBCF43C51u == crcTestValRet)
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
    if( CRCD_RES_OK == eCU_CRCD_SeedInitCtx(&ctx, 0x0u, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 4  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestData, sizeof(crcTestData) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 5  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        if( 0xD5F08708u == crcTestValRet)
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
    if( CRCD_RES_OK == eCU_CRCD_Restart(&ctx) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 7  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestData, sizeof(crcTestData) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 8  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        if( 0xD5F08708u == crcTestValRet)
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
    if( CRCD_RES_OK == eCU_CRCD_Restart(&ctx) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 10 -- FAIL \n");
    }

    if( CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 11 -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestData, sizeof(crcTestData) ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestMono 12 -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        if( 0xD5F08708u == crcTestValRet)
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

    if( CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
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
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &eCU_TEST_c32SAdapt;
    cb_crc32_seed_ctx ctxAdapterCrc;

    /* Test value */
    uint8_t crcTestDataC[] = {0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0xA1u, 0xB3u, 0xFFu, 0xFFu, 0x00u, 0xCFu, 0xD9u,
                              0x56u, 0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0xA1u, 0xB3u, 0xFFu, 0xFFu, 0x00u, 0xCFu,
                              0xD9u, 0x56u };
    uint32_t crcTestValRetC;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 1  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestDataC, 0x02u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 2  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[2u], 0x04u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 3  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[6u], 0x04u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 4  -- FAIL \n");
    }


    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[10u], 0x12u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 5  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRetC ) )
    {
        if( 0x1CE847A8u == crcTestValRetC)
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
    if( CRCD_RES_OK == eCU_CRCD_SeedInitCtx(&ctx, 0x00u, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 7  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestDataC, 0x02u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 8  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[2u], 0x04u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 9  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[6u], 0x04u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 10 -- FAIL \n");
    }


    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[10u], 0x12u ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 11 -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRetC ) )
    {
        if( 0x74F9B656u == crcTestValRetC)
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

    if( CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRetC ) )
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_cUCrcDigestCombined 13 -- FAIL \n");
    }
}
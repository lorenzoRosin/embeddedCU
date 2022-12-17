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

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif

#include <stdio.h>

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif


#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2012-Rule-10.3", "MISRAC2012-Rule-11.5", "CERT-EXP36-C_b"
    /* Suppressed for code clarity in test execution*/
#endif
/***********************************************************************************************************************
 *   PRIVATE TEST FUNCTION DECLARATION
 **********************************************************************************************************************/
typedef struct
{
    e_eCU_CRC_Res lastError;
}s_eCU_crcAdapterCtx;

static bool_t c32SAdapt(void* cntx, const uint32_t s, const uint8_t d[], const uint32_t dLen, uint32_t* const c32Val);
static bool_t c32SAdaptEr(void* cntx, const uint32_t s, const uint8_t d[], const uint32_t dLen, uint32_t* const c32Val);



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void cUCrcDigestTestBadPointer(void);
static void cUCrcDigestTestBadInit(void);
static void cUCrcDigestTestBadParamEntr(void);
static void cUCrcDigestTestContextStatus(void);
static void cUCrcDigestTestToManyOperation(void);
static void cUCrcDigestTestNoOperation(void);
static void cUCrcDigestTestClbErr(void);
static void cUCrcDigestTestMono(void);
static void cUCrcDigestTestCombined(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void cUCrcDigestTest(void)
{
	(void)printf("\n\nCRC DIGEST TEST START \n\n");

    cUCrcDigestTestBadPointer();
    cUCrcDigestTestBadInit();
    cUCrcDigestTestBadParamEntr();
    cUCrcDigestTestContextStatus();
    cUCrcDigestTestToManyOperation();
    cUCrcDigestTestNoOperation();
    cUCrcDigestTestClbErr();
    cUCrcDigestTestMono();
    cUCrcDigestTestCombined();

    (void)printf("\n\nCRC DIGEST END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE TEST FUNCTION DECLARATION
 **********************************************************************************************************************/
bool_t c32SAdapt(void* cntx, const uint32_t s, const uint8_t d[], const uint32_t dLen, uint32_t* const c32Val)
{
    bool_t result;
    s_eCU_crcAdapterCtx* ctxCur;

    if( ( NULL == cntx ) || ( NULL == c32Val ) )
    {
        result = false;
    }
    else
    {
        ctxCur = (s_eCU_crcAdapterCtx*)cntx;

        ctxCur->lastError = eCU_CRC_32Seed(s, d, dLen, c32Val);
        if( CRC_RES_OK == ctxCur->lastError )
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }

    return result;
}

bool_t c32SAdaptEr(void* cntx, const uint32_t s, const uint8_t d[], const uint32_t dLen, uint32_t* const c32Val)
{
    bool_t result;
    s_eCU_crcAdapterCtx* ctxCur;

    (void)s;
    (void)d;
    (void)dLen;

    if( ( NULL == cntx ) || ( NULL == c32Val ) )
    {
        result = false;
    }
    else
    {
        ctxCur = (s_eCU_crcAdapterCtx*)cntx;

        ctxCur->lastError = CRC_RES_BADPOINTER;
        result = false;
        *c32Val = 0u;
    }

    return result;
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void cUCrcDigestTestBadPointer(void)
{
    /* Local variable */
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;

    uint8_t  varBuff[5u];
    uint32_t varTemp;
    bool_t isInit;

    /* Function */
    if( CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(NULL, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 1  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(&ctx, NULL, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 2  -- FAIL \n");
    }


    if( CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, NULL) )
    {
        (void)printf("cUCrcDigestTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 2  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(NULL, 0x123456u, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 4  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(&ctx, 0x123456u, NULL, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 5  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(&ctx, 0x123456u, cbCrcPTest, NULL) )
    {
        (void)printf("cUCrcDigestTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 6  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_Restart( NULL ) )
    {
        (void)printf("cUCrcDigestTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 7  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_Digest( NULL, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("cUCrcDigestTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 8  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_Digest( &ctx, NULL, sizeof(varBuff) ) )
    {
        (void)printf("cUCrcDigestTestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 9  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_GetDigestVal( NULL, &varTemp) )
    {
        (void)printf("cUCrcDigestTestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 10 -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_GetDigestVal( &ctx, NULL) )
    {
        (void)printf("cUCrcDigestTestBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 11 -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_IsInit( NULL, &isInit ) )
    {
        (void)printf("cUCrcDigestTestBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 12 -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == eCU_CRCD_IsInit( &ctx, NULL ) )
    {
        (void)printf("cUCrcDigestTestBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 13 -- FAIL \n");
    }
}

void cUCrcDigestTestBadInit(void)
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
        (void)printf("cUCrcDigestTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadInit 1  -- FAIL \n");
    }

    if( CRCD_RES_NOINITLIB == eCU_CRCD_Digest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("cUCrcDigestTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadInit 2  -- FAIL \n");
    }

    if( CRCD_RES_NOINITLIB == eCU_CRCD_GetDigestVal( &ctx, &varTemp) )
    {
        (void)printf("cUCrcDigestTestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadInit 3  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_IsInit( &ctx, &isInit ) )
    {
        if( false == isInit )
        {
            (void)printf("cUCrcDigestTestBadInit 4  -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestBadInit 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestBadInit 4  -- FAIL \n");
    }
}

void cUCrcDigestTestBadParamEntr(void)
{
    /* Local variable */
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;
    bool_t isInit;
    uint8_t  varBuff[5u];
    varBuff[0] = 0u;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadParamEntr 1  -- FAIL \n");
    }

    if( CRCD_RES_BADPARAM == eCU_CRCD_Digest( &ctx, varBuff, 0u ) )
    {
        (void)printf("cUCrcDigestTestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadParamEntr 2  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_IsInit( &ctx, &isInit ) )
    {
        if( true == isInit )
        {
            (void)printf("cUCrcDigestTestBadParamEntr 3  -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestBadParamEntr 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestBadParamEntr 3  -- FAIL \n");
    }
}

void cUCrcDigestTestContextStatus(void)
{
    /* Local variable */
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;
    uint8_t  varBuff[5u];
    uint32_t varTemp;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestContextStatus 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestContextStatus 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.f_Crc = NULL;
    if( CRCD_RES_CORRUPTCTX == eCU_CRCD_Restart( &ctx ) )
    {
        (void)printf("cUCrcDigestTestContextStatus 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestContextStatus 2  -- FAIL \n");
    }


    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestContextStatus 3  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestContextStatus 3  -- FAIL \n");
    }

    /* Init variable */
    ctx.f_Crc = NULL;
    if( CRCD_RES_CORRUPTCTX == eCU_CRCD_Digest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("cUCrcDigestTestContextStatus 4  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestContextStatus 4  -- FAIL \n");
    }

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestContextStatus 5  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestContextStatus 5  -- FAIL \n");
    }

    /* Init variable */
    ctx.p_crcCtx = NULL;
    if( CRCD_RES_CORRUPTCTX == eCU_CRCD_GetDigestVal( &ctx, &varTemp ) )
    {
        (void)printf("cUCrcDigestTestContextStatus 6  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestContextStatus 6  -- FAIL \n");
    }
}

void cUCrcDigestTestToManyOperation(void)
{
    /* Local variable */
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;
    uint8_t  varBuff[5u];

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestToManyOperation 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestToManyOperation 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.digestedTimes = 0xFFFFFFFFu;
    if( CRCD_RES_TOOMANYDIGEST == eCU_CRCD_Digest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("cUCrcDigestTestToManyOperation 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestToManyOperation 2  -- FAIL \n");
    }
}

void cUCrcDigestTestNoOperation(void)
{
    /* Local variable */
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;
    uint32_t  varCarc;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestNoOperation 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestNoOperation 1  -- FAIL \n");
    }

    /* Init variable */
    if( CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &ctx, &varCarc ) )
    {
        (void)printf("cUCrcDigestTestNoOperation 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestNoOperation 2  -- FAIL \n");
    }
}


void cUCrcDigestTestClbErr(void)
{
    /* Local variable */
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTestErr = &c32SAdaptEr;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;
    uint8_t  varBuff[5u];

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    ctxAdapterCrc.lastError = CRC_RES_OK;
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTestErr, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestClbErr 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestClbErr 1  -- FAIL \n");
    }

    /* Init variable */
    if( CRCD_RES_CLBCKREPORTERROR == eCU_CRCD_Digest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        if( CRC_RES_BADPOINTER == ctxAdapterCrc.lastError )
        {
            (void)printf("cUCrcDigestTestClbErr 2  -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestClbErr 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestClbErr 2  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    ctxAdapterCrc.lastError = CRC_RES_OK;
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestClbErr 3  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestClbErr 3  -- FAIL \n");
    }

    /* Init variable */
    if( CRCD_RES_OK== eCU_CRCD_Digest( &ctx, varBuff, 1u ) )
    {
        (void)printf("cUCrcDigestTestClbErr 4  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestClbErr 4  -- FAIL \n");
    }

    ctx.f_Crc = cbCrcPTestErr;
    if( CRCD_RES_CLBCKREPORTERROR == eCU_CRCD_Digest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        if( CRC_RES_BADPOINTER == ctxAdapterCrc.lastError )
        {
            (void)printf("cUCrcDigestTestClbErr 5  -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestClbErr 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestClbErr 5  -- FAIL \n");
    }
}

void cUCrcDigestTestMono(void)
{
    /* Local variable */
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;

    /* Test value */
    uint8_t crcTestData[] = {0xA1u, 0xB3u, 0xFFu, 0xFFu, 0x00u, 0xCFu, 0xD9u, 0x56u};
    uint32_t crcTestValRet;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_InitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestMono 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 1  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestData, sizeof(crcTestData) ) )
    {
        (void)printf("cUCrcDigestTestMono 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 2  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        if( 0xBCF43C51u == crcTestValRet)
        {
            (void)printf("cUCrcDigestTestMono 3  -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestMono 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 3  -- FAIL \n");
    }

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_SeedInitCtx(&ctx, 0x0u, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestMono 4  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 4  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestData, sizeof(crcTestData) ) )
    {
        (void)printf("cUCrcDigestTestMono 5  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 5  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        if( 0xD5F08708u == crcTestValRet)
        {
            (void)printf("cUCrcDigestTestMono 6  -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestMono 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 6  -- FAIL \n");
    }

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_Restart(&ctx) )
    {
        (void)printf("cUCrcDigestTestMono 7  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 7  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestData, sizeof(crcTestData) ) )
    {
        (void)printf("cUCrcDigestTestMono 8  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 8  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        if( 0xD5F08708u == crcTestValRet)
        {
            (void)printf("cUCrcDigestTestMono 9  -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestMono 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 9  -- FAIL \n");
    }

    /* Function */
    if( CRCD_RES_OK == eCU_CRCD_Restart(&ctx) )
    {
        (void)printf("cUCrcDigestTestMono 10 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 10 -- FAIL \n");
    }

    if( CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        (void)printf("cUCrcDigestTestMono 11 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 11 -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestData, sizeof(crcTestData) ) )
    {
        (void)printf("cUCrcDigestTestMono 12 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 12 -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        if( 0xD5F08708u == crcTestValRet)
        {
            (void)printf("cUCrcDigestTestMono 13 -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestMono 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 13 -- FAIL \n");
    }

    if( CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRet ) )
    {
        (void)printf("cUCrcDigestTestMono 14 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 14 -- FAIL \n");
    }
}

void cUCrcDigestTestCombined(void)
{
    /* Local variable */
    s_eCU_CRCD_Ctx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;

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
        (void)printf("cUCrcDigestTestCombined 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 1  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestDataC, 0x02u ) )
    {
        (void)printf("cUCrcDigestTestCombined 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 2  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[2u], 0x04u ) )
    {
        (void)printf("cUCrcDigestTestCombined 3  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 3  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[6u], 0x04u ) )
    {
        (void)printf("cUCrcDigestTestCombined 4  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 4  -- FAIL \n");
    }


    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[10u], 0x12u ) )
    {
        (void)printf("cUCrcDigestTestCombined 5  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 5  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRetC ) )
    {
        if( 0x1CE847A8u == crcTestValRetC)
        {
            (void)printf("cUCrcDigestTestCombined 6  -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestCombined 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 6  -- FAIL \n");
    }

     /* Function */
    if( CRCD_RES_OK == eCU_CRCD_SeedInitCtx(&ctx, 0x00u, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestCombined 7  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 7  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, crcTestDataC, 0x02u ) )
    {
        (void)printf("cUCrcDigestTestCombined 8  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 8  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[2u], 0x04u ) )
    {
        (void)printf("cUCrcDigestTestCombined 9  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 9  -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[6u], 0x04u ) )
    {
        (void)printf("cUCrcDigestTestCombined 10 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 10 -- FAIL \n");
    }


    if( CRCD_RES_OK == eCU_CRCD_Digest( &ctx, &crcTestDataC[10u], 0x12u ) )
    {
        (void)printf("cUCrcDigestTestCombined 11 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 11 -- FAIL \n");
    }

    if( CRCD_RES_OK == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRetC ) )
    {
        if( 0x74F9B656u == crcTestValRetC)
        {
            (void)printf("cUCrcDigestTestCombined 12 -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestCombined 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 12 -- FAIL \n");
    }

    if( CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &ctx, &crcTestValRetC ) )
    {
        (void)printf("cUCrcDigestTestCombined 13 -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 13 -- FAIL \n");
    }
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2012-Rule-10.3", "MISRAC2012-Rule-11.5", "CERT-EXP36-C_b"
#endif
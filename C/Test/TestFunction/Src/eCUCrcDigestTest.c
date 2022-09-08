/**
 * @file eCUCrcDigestTest.c
 *
 */
#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUCrcDigestTest.h"
#include "eCUCrc.h"
#include <stdio.h>




/***********************************************************************************************************************
 *   PRIVATE TEST FUNCTION DECLARATION
 **********************************************************************************************************************/
typedef struct
{
    e_eCU_Crc_Res lastError;
}s_eCU_crcAdapterCtx;

static bool_t c32SAdapt(void* cntx, const uint32_t s, const uint8_t d[], const uint32_t dLen, uint32_t* const c32Val);



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void cUCrcDigestTestBadPointer(void);
static void cUCrcDigestTestBadInit(void);
static void cUCrcDigestTestBadParamEntr(void);
static void cUCrcDigestTestBadParamStatus(void);
static void cUCrcDigestTestOutOfMem(void);
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
    cUCrcDigestTestBadParamStatus();
    cUCrcDigestTestOutOfMem();
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
    e_eCU_Crc_Res crcReturned;

    crcReturned = crc32Seed(s, d, dLen, c32Val);
    if( CRC_RES_OK == crcReturned )
    {
        result = true;
    }
    else
    {
        s_eCU_crcAdapterCtx* ctxCur = (s_eCU_crcAdapterCtx*)cntx;
        ctxCur->lastError = crcReturned;
        result = false;
    }

    return result;
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void cUCrcDigestTestBadPointer(void)
{
    /* Local variable */
    s_eCU_CrcDigestCtx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;

    uint8_t  varBuff[5u];
    uint32_t varTemp;

    /* Function */
    if( CRCD_RES_BADPOINTER == crcDigestInitCtx(NULL, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 1  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == crcDigestInitCtx(&ctx, NULL, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 2  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == crcDigestSeedInitCtx(NULL, 0x123456u, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 3  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == crcDigestSeedInitCtx(&ctx, 0x123456u, NULL, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 4  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == crcDigesDigest( NULL, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("cUCrcDigestTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestsBadPointer 5  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == crcDigesDigest( &ctx, NULL, sizeof(varBuff) ) )
    {
        (void)printf("cUCrcDigestTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 6  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == crcDigesGetDigestVal( NULL, &varTemp) )
    {
        (void)printf("cUCrcDigestTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 7  -- FAIL \n");
    }

    if( CRCD_RES_BADPOINTER == crcDigesGetDigestVal( &ctx, NULL) )
    {
        (void)printf("cUCrcDigestTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadPointer 8  -- FAIL \n");
    }
}

void cUCrcDigestTestBadInit(void)
{
    /* Local variable */
    s_eCU_CrcDigestCtx ctx;
    uint8_t  varBuff[5u];
    uint32_t varTemp;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_NOINITLIB == crcDigesDigest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("cUCrcDigestTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadInit 1  -- FAIL \n");
    }

    if( CRCD_RES_NOINITLIB == crcDigesGetDigestVal( &ctx, &varTemp) )
    {
        (void)printf("cUCrcDigestTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadInit 2  -- FAIL \n");
    }
}

void cUCrcDigestTestBadParamEntr(void)
{
    /* Local variable */
    s_eCU_CrcDigestCtx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;
    uint8_t  varBuff[5u];
    varBuff[0] = 0u;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == crcDigestInitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadParamEntr 1  -- FAIL \n");
    }

    if( CRCD_RES_BADPARAM == crcDigesDigest( &ctx, varBuff, 0u ) )
    {
        (void)printf("cUCrcDigestTestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadParamEntr 2  -- FAIL \n");
    }
}

void cUCrcDigestTestBadParamStatus(void)
{
    /* Local variable */
    s_eCU_CrcDigestCtx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;
    uint8_t  varBuff[5u];
    uint32_t varTemp;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == crcDigestInitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadParamStatus 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadParamStatus 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.cbCrcPointer = NULL;
    if( CRCD_RES_BADPARAM == crcDigesDigest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("cUCrcDigestTestBadParamStatus 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadParamStatus 2  -- FAIL \n");
    }

    /* Function */
    if( CRCD_RES_OK == crcDigestInitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestBadParamStatus 3  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadParamStatus 3  -- FAIL \n");
    }

    /* Init variable */
    ctx.cbCrcPointer = NULL;
    if( CRCD_RES_BADPARAM == crcDigesGetDigestVal( &ctx, &varTemp ) )
    {
        (void)printf("cUCrcDigestTestBadParamStatus 4  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestBadParamStatus 4  -- FAIL \n");
    }
}

void cUCrcDigestTestOutOfMem(void)
{
    /* Local variable */
    s_eCU_CrcDigestCtx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;
    uint8_t  varBuff[5u];

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == crcDigestInitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestOutOfMem 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.digestedTimes = 0xFFFFFFFFu;
    if( CRCD_RES_TOOMANYDIGEST == crcDigesDigest( &ctx, varBuff, sizeof(varBuff) ) )
    {
        (void)printf("cUCrcDigestTestOutOfMem 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestOutOfMem 2  -- FAIL \n");
    }
}

void cUCrcDigestTestMono(void)
{
    /* Local variable */
    s_eCU_CrcDigestCtx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;

    /* Test value */
    uint8_t crcTestData[] = {0x00u, 0x01u, 0x02u};
    uint32_t crcTestValRet;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == crcDigestInitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestMono 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 1  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesDigest( &ctx, crcTestData, sizeof(crcTestData) ) )
    {
        (void)printf("cUCrcDigestTestMono 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 2  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesGetDigestVal( &ctx, &crcTestValRet ) )
    {
        if( 0x6CFF87B2u == crcTestValRet)
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
    if( CRCD_RES_OK == crcDigestSeedInitCtx(&ctx, 0x0u,cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestMono 4  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 4  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesDigest( &ctx, crcTestData, sizeof(crcTestData) ) )
    {
        (void)printf("cUCrcDigestTestMono 5  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestMono 5  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesGetDigestVal( &ctx, &crcTestValRet ) )
    {
        if( 0xDB9BFAB2u == crcTestValRet)
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
}


void cUCrcDigestTestCombined(void)
{
    /* Local variable */
    s_eCU_CrcDigestCtx ctx;
    cb_crc32_seed cbCrcPTest = &c32SAdapt;
    s_eCU_crcAdapterCtx ctxAdapterCrc;

    /* Test value */
    uint8_t crcTestDataC[] = {0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u};
    uint32_t crcTestValRetC;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CRCD_RES_OK == crcDigestInitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestCombined 1  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 1  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesDigest( &ctx, crcTestDataC, 0x02u ) )
    {
        (void)printf("cUCrcDigestTestCombined 2  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 2  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesDigest( &ctx, &crcTestDataC[2u], 0x04u ) )
    {
        (void)printf("cUCrcDigestTestCombined 3  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 3  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesGetDigestVal( &ctx, &crcTestValRetC ) )
    {
        if( 0x9FE54C6Du == crcTestValRetC)
        {
            (void)printf("cUCrcDigestTestCombined 4  -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestCombined 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 4  -- FAIL \n");
    }

     /* Function */
    if( CRCD_RES_OK == crcDigestInitCtx(&ctx, cbCrcPTest, &ctxAdapterCrc) )
    {
        (void)printf("cUCrcDigestTestCombined 5  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 5  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesDigest( &ctx, crcTestDataC, 0x02u ) )
    {
        (void)printf("cUCrcDigestTestCombined 6  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 6  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesDigest( &ctx, &crcTestDataC[2u], 0x02u ) )
    {
        (void)printf("cUCrcDigestTestCombined 7  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 7  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesDigest( &ctx, &crcTestDataC[4u], 0x02u ) )
    {
        (void)printf("cUCrcDigestTestCombined 8  -- OK \n");
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 8  -- FAIL \n");
    }

    if( CRCD_RES_OK == crcDigesGetDigestVal( &ctx, &crcTestValRetC ) )
    {
        if( 0x9FE54C6Du == crcTestValRetC)
        {
            (void)printf("cUCrcDigestTestCombined 9  -- OK \n");
        }
        else
        {
            (void)printf("cUCrcDigestTestCombined 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("cUCrcDigestTestCombined 9  -- FAIL \n");
    }
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif
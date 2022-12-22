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

static bool_t eCU_CRCDTST_c32SAdapt(t_eCU_CRCD_CrcCtx* const p_ctx, const uint32_t s, const uint8_t* p_d, const uint32_t dLen, uint32_t* const p_c32Val);
static bool_t eCU_CRCDTST_c32SAdaptEr(t_eCU_CRCD_CrcCtx* const p_ctx, const uint32_t s, const uint8_t* p_d, const uint32_t dLen, uint32_t* const p_c32Val);



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_CRCDTST_BadPointer(void);
static void eCU_CRCDTST_BadInit(void);
static void eCU_CRCDTST_BadParamEntr(void);
static void eCU_CRCDTST_ContextStatus(void);
static void eCU_CRCDTST_ToManyOperation(void);
static void eCU_CRCDTST_NoOperation(void);
static void eCU_CRCDTST_ClbErr(void);
static void eCU_CRCDTST_Mono(void);
static void eCU_CRCDTST_Combined(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_CRCDTST_ExeTest(void)
{
	(void)printf("\n\nCRC DIGEST TEST START \n\n");

    eCU_CRCDTST_BadPointer();
    eCU_CRCDTST_BadInit();
    eCU_CRCDTST_BadParamEntr();
    eCU_CRCDTST_ContextStatus();
    eCU_CRCDTST_ToManyOperation();
    eCU_CRCDTST_NoOperation();
    eCU_CRCDTST_ClbErr();
    eCU_CRCDTST_Mono();
    eCU_CRCDTST_Combined();

    (void)printf("\n\nCRC DIGEST END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE TEST FUNCTION DECLARATION
 **********************************************************************************************************************/
static bool_t eCU_CRCDTST_c32SAdapt(t_eCU_CRCD_CrcCtx* p_ctx, const uint32_t s, const uint8_t* p_d, const uint32_t dLen, uint32_t* const p_c32Val)
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

static bool_t eCU_CRCDTST_c32SAdaptEr(t_eCU_CRCD_CrcCtx* p_ctx, const uint32_t s, const uint8_t* p_d, const uint32_t dLen, uint32_t* const p_c32Val)
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
static void eCU_CRCDTST_BadPointer(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_CRCDTST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;

    uint8_t  la_varBuff[5u];
    uint32_t l_varTemp;
    bool_t l_isInit;

    /* Function */
    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(NULL, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 1  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(&l_ctx, NULL, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 2  -- FAIL \n");
    }


    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, NULL) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 2  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(NULL, 0x123456u, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 4  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(&l_ctx, 0x123456u, NULL, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 5  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_SeedInitCtx(&l_ctx, 0x123456u, lf_cbCrcTest, NULL) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 6  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_Restart( NULL ) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 7  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_Digest( NULL, la_varBuff, sizeof(la_varBuff) ) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 8  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_Digest( &l_ctx, NULL, sizeof(la_varBuff) ) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 9  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_GetDigestVal( NULL, &l_varTemp) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 10 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_GetDigestVal( &l_ctx, NULL) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 11 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_IsInit( NULL, &l_isInit ) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 12 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPOINTER == eCU_CRCD_IsInit( &l_ctx, NULL ) )
    {
        (void)printf("eCU_CRCDTST_BadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadPointer 13 -- FAIL \n");
    }
}

static void eCU_CRCDTST_BadInit(void)
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
        (void)printf("eCU_CRCDTST_BadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadInit 1  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_NOINITLIB == eCU_CRCD_Digest( &l_ctx, la_varBuff, sizeof(la_varBuff) ) )
    {
        (void)printf("eCU_CRCDTST_BadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadInit 2  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_NOINITLIB == eCU_CRCD_GetDigestVal( &l_ctx, &l_varTemp) )
    {
        (void)printf("eCU_CRCDTST_BadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadInit 3  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_IsInit( &l_ctx, &l_isInit ) )
    {
        if( false == l_isInit )
        {
            (void)printf("eCU_CRCDTST_BadInit 4  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CRCDTST_BadInit 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadInit 4  -- FAIL \n");
    }
}

static void eCU_CRCDTST_BadParamEntr(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_CRCDTST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;
    bool_t l_isInit;
    uint8_t  la_varBuff[5u];
    la_varBuff[0] = 0u;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_BadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadParamEntr 1  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_BADPARAM == eCU_CRCD_Digest( &l_ctx, la_varBuff, 0u ) )
    {
        (void)printf("eCU_CRCDTST_BadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadParamEntr 2  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_IsInit( &l_ctx, &l_isInit ) )
    {
        if( true == l_isInit )
        {
            (void)printf("eCU_CRCDTST_BadParamEntr 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CRCDTST_BadParamEntr 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CRCDTST_BadParamEntr 3  -- FAIL \n");
    }
}

static void eCU_CRCDTST_ContextStatus(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_CRCDTST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;
    uint8_t  la_varBuff[5u];
    uint32_t l_varTemp;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_ContextStatus 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ContextStatus 1  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.fCrc = NULL;
    if( e_eCU_CRCD_RES_CORRUPTCTX == eCU_CRCD_Restart( &l_ctx ) )
    {
        (void)printf("eCU_CRCDTST_ContextStatus 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ContextStatus 2  -- FAIL \n");
    }


    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_ContextStatus 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ContextStatus 3  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.fCrc = NULL;
    if( e_eCU_CRCD_RES_CORRUPTCTX == eCU_CRCD_Digest( &l_ctx, la_varBuff, sizeof(la_varBuff) ) )
    {
        (void)printf("eCU_CRCDTST_ContextStatus 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ContextStatus 4  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_ContextStatus 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ContextStatus 5  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.ptCrcCtx = NULL;
    if( e_eCU_CRCD_RES_CORRUPTCTX == eCU_CRCD_GetDigestVal( &l_ctx, &l_varTemp ) )
    {
        (void)printf("eCU_CRCDTST_ContextStatus 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ContextStatus 6  -- FAIL \n");
    }
}

static void eCU_CRCDTST_ToManyOperation(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_CRCDTST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;
    uint8_t  la_varBuff[5u];

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_ToManyOperation 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ToManyOperation 1  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uDigestedTimes = 0xFFFFFFFFu;
    if( e_eCU_CRCD_RES_TOOMANYDIGEST == eCU_CRCD_Digest( &l_ctx, la_varBuff, sizeof(la_varBuff) ) )
    {
        (void)printf("eCU_CRCDTST_ToManyOperation 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ToManyOperation 2  -- FAIL \n");
    }
}

static void eCU_CRCDTST_NoOperation(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_CRCDTST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;
    uint32_t  l_varCarc;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_NoOperation 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_NoOperation 1  -- FAIL \n");
    }

    /* Init variable */
    if( e_eCU_CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &l_ctx, &l_varCarc ) )
    {
        (void)printf("eCU_CRCDTST_NoOperation 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_NoOperation 2  -- FAIL \n");
    }
}

static void eCU_CRCDTST_ClbErr(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcPTestErr = &eCU_CRCDTST_c32SAdaptEr;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_CRCDTST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;
    uint8_t  la_varBuff[5u];

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    l_ctxAdapterCrc.lastError = e_eCU_CRC_RES_OK;
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcPTestErr, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_ClbErr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ClbErr 1  -- FAIL \n");
    }

    /* Init variable */
    if( e_eCU_CRCD_RES_CLBCKREPORTERROR == eCU_CRCD_Digest( &l_ctx, la_varBuff, sizeof(la_varBuff) ) )
    {
        if( e_eCU_CRC_RES_BADPOINTER == l_ctxAdapterCrc.lastError )
        {
            (void)printf("eCU_CRCDTST_ClbErr 2  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CRCDTST_ClbErr 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CRCDTST_ClbErr 2  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    l_ctxAdapterCrc.lastError = e_eCU_CRC_RES_OK;
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_ClbErr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ClbErr 3  -- FAIL \n");
    }

    /* Init variable */
    if( e_eCU_CRCD_RES_OK== eCU_CRCD_Digest( &l_ctx, la_varBuff, 1u ) )
    {
        (void)printf("eCU_CRCDTST_ClbErr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_ClbErr 4  -- FAIL \n");
    }

    l_ctx.fCrc = lf_cbCrcPTestErr;
    if( e_eCU_CRCD_RES_CLBCKREPORTERROR == eCU_CRCD_Digest( &l_ctx, la_varBuff, sizeof(la_varBuff) ) )
    {
        if( e_eCU_CRC_RES_BADPOINTER == l_ctxAdapterCrc.lastError )
        {
            (void)printf("eCU_CRCDTST_ClbErr 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CRCDTST_ClbErr 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CRCDTST_ClbErr 5  -- FAIL \n");
    }
}

static void eCU_CRCDTST_Mono(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_CRCDTST_c32SAdapt;
    t_eCU_CRCD_CrcCtx l_ctxAdapterCrc;

    /* Test value */
    uint8_t la_crcTestData[] = {0xA1u, 0xB3u, 0xFFu, 0xFFu, 0x00u, 0xCFu, 0xD9u, 0x56u};
    uint32_t l_crcTestValRet;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_InitCtx(&l_ctx, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_Mono 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 1  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestData, sizeof(la_crcTestData) ) )
    {
        (void)printf("eCU_CRCDTST_Mono 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 2  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        if( 0xBCF43C51u == l_crcTestValRet)
        {
            (void)printf("eCU_CRCDTST_Mono 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CRCDTST_Mono 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 3  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_SeedInitCtx(&l_ctx, 0x0u, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_Mono 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 4  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestData, sizeof(la_crcTestData) ) )
    {
        (void)printf("eCU_CRCDTST_Mono 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 5  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        if( 0xD5F08708u == l_crcTestValRet)
        {
            (void)printf("eCU_CRCDTST_Mono 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CRCDTST_Mono 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 6  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Restart(&l_ctx) )
    {
        (void)printf("eCU_CRCDTST_Mono 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 7  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestData, sizeof(la_crcTestData) ) )
    {
        (void)printf("eCU_CRCDTST_Mono 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 8  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        if( 0xD5F08708u == l_crcTestValRet)
        {
            (void)printf("eCU_CRCDTST_Mono 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CRCDTST_Mono 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 9  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Restart(&l_ctx) )
    {
        (void)printf("eCU_CRCDTST_Mono 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 10 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        (void)printf("eCU_CRCDTST_Mono 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 11 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestData, sizeof(la_crcTestData) ) )
    {
        (void)printf("eCU_CRCDTST_Mono 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 12 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        if( 0xD5F08708u == l_crcTestValRet)
        {
            (void)printf("eCU_CRCDTST_Mono 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_CRCDTST_Mono 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 13 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRet ) )
    {
        (void)printf("eCU_CRCDTST_Mono 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Mono 14 -- FAIL \n");
    }
}

static void eCU_CRCDTST_Combined(void)
{
    /* Local variable */
    t_eCU_CRCD_Ctx l_ctx;
    f_eCU_CRCD_CrcCb lf_cbCrcTest = &eCU_CRCDTST_c32SAdapt;
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
        (void)printf("eCU_CRCDTST_Combined 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 1  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestDataC, 0x02u ) )
    {
        (void)printf("eCU_CRCDTST_Combined 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 2  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[2u], 0x04u ) )
    {
        (void)printf("eCU_CRCDTST_Combined 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 3  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[6u], 0x04u ) )
    {
        (void)printf("eCU_CRCDTST_Combined 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 4  -- FAIL \n");
    }


    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[10u], 0x12u ) )
    {
        (void)printf("eCU_CRCDTST_Combined 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 5  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRetC ) )
    {
        if( 0x1CE847A8u == l_crcTestValRetC)
        {
            (void)printf("eCU_CRCDTST_Combined 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CRCDTST_Combined 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 6  -- FAIL \n");
    }

     /* Function */
    if( e_eCU_CRCD_RES_OK == eCU_CRCD_SeedInitCtx(&l_ctx, 0x00u, lf_cbCrcTest, &l_ctxAdapterCrc) )
    {
        (void)printf("eCU_CRCDTST_Combined 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 7  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, la_crcTestDataC, 0x02u ) )
    {
        (void)printf("eCU_CRCDTST_Combined 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 8  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[2u], 0x04u ) )
    {
        (void)printf("eCU_CRCDTST_Combined 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 9  -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[6u], 0x04u ) )
    {
        (void)printf("eCU_CRCDTST_Combined 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 10 -- FAIL \n");
    }


    if( e_eCU_CRCD_RES_OK == eCU_CRCD_Digest( &l_ctx, &la_crcTestDataC[10u], 0x12u ) )
    {
        (void)printf("eCU_CRCDTST_Combined 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 11 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_OK == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRetC ) )
    {
        if( 0x74F9B656u == l_crcTestValRetC)
        {
            (void)printf("eCU_CRCDTST_Combined 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_CRCDTST_Combined 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 12 -- FAIL \n");
    }

    if( e_eCU_CRCD_RES_NODIGESTDONE == eCU_CRCD_GetDigestVal( &l_ctx, &l_crcTestValRetC ) )
    {
        (void)printf("eCU_CRCDTST_Combined 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CRCDTST_Combined 13 -- FAIL \n");
    }
}
/**
 * @file       eCUByteUnStufferTest.c
 *
 * @brief      Byte unstuffer test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteUnStufferTest.h"
#include "eCU_BSTF.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_TEST_byteUnStuffBadPointer(void);
static void eCU_TEST_byteUnStuffBadInit(void);
static void eCU_TEST_byteUnStuffBadParamEntr(void);
static void eCU_TEST_byteUnStuffCorrupterContext(void);
static void eCU_TEST_byteUnStuffOutOfMem(void);
static void eCU_TEST_byteUnStuffFrameEnd(void);
static void eCU_TEST_byteUnStuffGeneral(void);
static void eCU_TEST_byteUnStuffCornerCase(void);
static void eCU_TEST_byteUnStuffCornerCase2(void);
static void eCU_TEST_byteUnStuffCodeCoverage(void);

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_TEST_byteUnStuffer(void)
{
	(void)printf("\n\nBYTE UNSTUFFER TEST START \n\n");

    eCU_TEST_byteUnStuffBadPointer();
    eCU_TEST_byteUnStuffBadInit();
    eCU_TEST_byteUnStuffBadParamEntr();
    eCU_TEST_byteUnStuffCorrupterContext();
    eCU_TEST_byteUnStuffOutOfMem();
    eCU_TEST_byteUnStuffFrameEnd();
    eCU_TEST_byteUnStuffGeneral();
    eCU_TEST_byteUnStuffCornerCase();
    eCU_TEST_byteUnStuffCornerCase2();
    eCU_TEST_byteUnStuffCodeCoverage();

    (void)printf("\n\nBYTE UNSTUFFER TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_TEST_byteUnStuffBadPointer(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint32_t l_varTemp32;
    uint8_t *lp_aPointerP;
    bool_t l_frameIsUnstuffed;
    bool_t l_isWaiting;
    bool_t l_isInit;

    /* Function */
    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_InitCtx(NULL, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 1  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_InitCtx(&l_ctx, NULL, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 2  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_NewFrame( NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 3  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_GetUnstufData( NULL, &lp_aPointerP, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 4  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_GetUnstufData( &l_ctx, NULL, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 5  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_GetUnstufData( &l_ctx, &lp_aPointerP, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 6  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_GetUnstufLen( NULL, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 7  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_GetUnstufLen( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 8  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsWaitingSof( NULL, &l_isWaiting ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 9  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsWaitingSof( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 10 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsAFullFrameUnstuff( NULL, &l_frameIsUnstuffed ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 11 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsAFullFrameUnstuff( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 12 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsFrameBad( NULL, &l_frameIsUnstuffed ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 13 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsFrameBad( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 14 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_InsStufChunk( NULL, la_memArea, sizeof(la_memArea), &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 15 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_InsStufChunk( &l_ctx, NULL, sizeof(la_memArea), &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 16 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_InsStufChunk( &l_ctx, la_memArea, sizeof(la_memArea), NULL) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 17 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsInit( NULL, &l_isInit ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 18 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsInit( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 19 -- FAIL \n");
    }
}

static void eCU_TEST_byteUnStuffBadInit(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint32_t l_varTemp32;
    uint8_t *lp_aPointerP;
    bool_t l_frameIsUnstuffed;
    bool_t l_isWaiting;
    bool_t l_isInit;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_BUNSTF_RES_NOINITLIB == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 1  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_NOINITLIB == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 2  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_NOINITLIB == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 3  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_NOINITLIB == eCU_BUNSTF_IsWaitingSof(&l_ctx, &l_isWaiting ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 4  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_NOINITLIB == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frameIsUnstuffed) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 5  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_NOINITLIB == eCU_BUNSTF_IsFrameBad(&l_ctx, &l_frameIsUnstuffed) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 6  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_NOINITLIB == eCU_BUNSTF_InsStufChunk( &l_ctx, la_memArea, sizeof(la_memArea), &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 7  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsInit( &l_ctx, &l_isInit ) )
    {
        if( false == l_isInit )
        {
            (void)printf("eCU_TEST_byteUnStuffBadInit 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffBadInit 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 8  -- FAIL \n");
    }
}

static void eCU_TEST_byteUnStuffBadParamEntr(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint32_t l_varTemp32;
    bool_t l_isInit;

    /* Function */
    if( e_eCU_BUNSTF_RES_BADPARAM == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, 0u) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 1  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 2  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADPARAM == eCU_BUNSTF_InsStufChunk( &l_ctx, la_memArea, 0u, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 3  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsInit( &l_ctx, &l_isInit ) )
    {
        if( true == l_isInit )
        {
            (void)printf("eCU_TEST_byteUnStuffBadParamEntr 4  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffBadParamEntr 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 4  -- FAIL \n");
    }
}

static void eCU_TEST_byteUnStuffCorrupterContext(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint32_t l_varTemp32;
    uint8_t *lp_aPointerP;
    bool_t l_frameIsUnstuffed;
    bool_t l_isWaiting;

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 1  -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 2  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 3  -- FAIL \n");
    }

    l_ctx.puBuff = NULL;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 4  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 5  -- FAIL \n");
    }

    l_ctx.uFrameCtr = l_ctx.uBuffL + 1u;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 6  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 7  -- FAIL \n");
    }

    l_ctx.uFrameCtr = 1u;
    l_ctx.eSM = e_eCU_BUNSTFPRV_SM_NEEDSOF;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 8  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 9  -- FAIL \n");
    }

    l_ctx.uFrameCtr = 0u;
    l_ctx.eSM = e_eCU_BUNSTFPRV_SM_UNSTUFFEND;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 10 -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 11 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 12 -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 13 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufData( &l_ctx, &lp_aPointerP, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 14 -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 15 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_IsWaitingSof(&l_ctx, &l_isWaiting) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 16 -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 17 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frameIsUnstuffed) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 18 -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 19 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_IsFrameBad(&l_ctx, &l_frameIsUnstuffed) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 20 -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 21 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_InsStufChunk( &l_ctx, la_memArea, 9u, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 22 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 22 -- FAIL \n");
    }
}

static void eCU_TEST_byteUnStuffOutOfMem(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint8_t  l_stuffed[10u];
    uint32_t l_varTemp32;
    uint8_t* lp_aPointerP;
    bool_t l_frIsUnstuf;
    bool_t l_isWaiting;
    bool_t l_isBad;

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 1  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsWaitingSof(&l_ctx, &l_isWaiting) )
    {
        if( true == l_isWaiting )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 2  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 2  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = 0x01u;
    l_stuffed[2u] = 0x02u;
    l_stuffed[3u] = 0x03u;
    l_stuffed[4u] = 0x04u;
    l_stuffed[5u] = 0x01u;
    l_stuffed[6u] = ECU_ESC;
    l_stuffed[7u] = 0x03u;
    l_stuffed[8u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_OUTOFMEM == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 9u, &l_varTemp32 ) )
    {
        if( 7u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != la_memArea[0u] ) || ( 0x02u != la_memArea[1u] ) || ( 0x03u != la_memArea[2u] ) ||
                ( 0x04u != la_memArea[3u] ) || ( 0x01u != la_memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
            }
            else
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 5u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 5u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                                {
                                    if( false == l_frIsUnstuf)
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsWaitingSof(&l_ctx, &l_isWaiting) )
    {
        if( false == l_isWaiting )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 4  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 4  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 5  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = 0x01u;
    l_stuffed[2u] = 0x02u;
    l_stuffed[3u] = 0x03u;
    l_stuffed[4u] = 0x04u;
    l_stuffed[5u] = 0x05u;
    l_stuffed[6u] = 0x06u;
    l_stuffed[7u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_OUTOFMEM == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 7u, &l_varTemp32 ) )
    {
        if( 6u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != la_memArea[0u] ) || ( 0x02u != la_memArea[1u] ) || ( 0x03u != la_memArea[2u] ) ||
                ( 0x04u != la_memArea[3u] ) || ( 0x05u != la_memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
            }
            else
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 5u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 5u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                                {
                                    if( false == l_frIsUnstuf)
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 7  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = 0x01u;
    l_stuffed[2u] = 0x02u;
    l_stuffed[3u] = 0x03u;
    l_stuffed[4u] = 0x04u;
    l_stuffed[5u] = 0x01u;
    l_stuffed[6u] = ECU_ESC;
    l_stuffed[7u] = 0x03u;
    l_stuffed[8u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 3u, &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 8  -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 2u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 2u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 8  -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 8  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 8  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 8  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 8  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 8  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[3u], 4u, &l_varTemp32 ) )
    {
        if( 4u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != la_memArea[0u] ) || ( 0x02u != la_memArea[1u] ) || ( 0x03u != la_memArea[2u] ) ||
                ( 0x04u != la_memArea[3u] ) || ( 0x01u != la_memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
            }
            else
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 5u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 5u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                                {
                                    if( false == l_frIsUnstuf)
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OUTOFMEM == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[7u], 1u, &l_varTemp32 ) )
    {
        if( 0u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != la_memArea[0u] ) || ( 0x02u != la_memArea[1u] ) || ( 0x03u != la_memArea[2u] ) ||
                ( 0x04u != la_memArea[3u] ) || ( 0x01u != la_memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
            }
            else
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 5u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 5u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                                {
                                    if( false == l_frIsUnstuf)
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 11 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&l_ctx, &l_isBad) )
    {
        if( false == l_isBad )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 12 -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = 0x01u;
    l_stuffed[2u] = 0x02u;
    l_stuffed[3u] = 0x03u;
    l_stuffed[4u] = 0x04u;
    l_stuffed[5u] = 0x05u;
    l_stuffed[6u] = 0x06u;
    l_stuffed[7u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 3u, &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 2u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 2u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                            {
                                if( false == l_frIsUnstuf)
                                {
                                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&l_ctx, &l_isBad) )
                                    {
                                        if( false == l_isBad)
                                        {
                                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- OK \n");
                                        }
                                        else
                                        {
                                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
                                        }
                                    }
                                    else
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OUTOFMEM == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[3u], 4u, &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != la_memArea[0u] ) || ( 0x02u != la_memArea[1u] ) || ( 0x03u != la_memArea[2u] ) ||
                ( 0x04u != la_memArea[3u] ) || ( 0x05u != la_memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
            }
            else
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 5u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 5u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                                {
                                    if( false == l_frIsUnstuf)
                                    {
                                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&l_ctx, &l_isBad) )
                                        {
                                            if( false == l_isBad)
                                            {
                                                (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- OK \n");
                                            }
                                            else
                                            {
                                                (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
                                            }
                                        }
                                        else
                                        {
                                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
                                        }
                                    }
                                    else
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
    }
}

static void eCU_TEST_byteUnStuffFrameEnd(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint8_t  l_stuffed[10u];
    uint32_t l_varTemp32;
    uint8_t* lp_aPointerP;
    bool_t l_frIsUnstuf;
    bool_t l_isBad;

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 1  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = 0x01u;
    l_stuffed[2u] = 0x02u;
    l_stuffed[3u] = 0x03u;
    l_stuffed[4u] = 0x04u;
    l_stuffed[5u] = 0x01u;
    l_stuffed[6u] = ECU_EOF;
    l_stuffed[7u] = ECU_SOF;


    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 7u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != la_memArea[0u] ) || ( 0x02u != la_memArea[1u] ) || ( 0x03u != la_memArea[2u] ) ||
                ( 0x04u != la_memArea[3u] ) || ( 0x01u != la_memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
            }
            else
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 5u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 5u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                                {
                                    if( true == l_frIsUnstuf)
                                    {
                                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&l_ctx, &l_isBad) )
                                        {
                                            if( false == l_isBad)
                                            {
                                                (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- OK \n");
                                            }
                                            else
                                            {
                                                (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
                                            }
                                        }
                                        else
                                        {
                                            (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
                                        }
                                    }
                                    else
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
    }


    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 3  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = 0x01u;
    l_stuffed[2u] = ECU_ESC;
    l_stuffed[3u] = (uint8_t)(~ECU_SOF);
    l_stuffed[4u] = 0x02u;
    l_stuffed[5u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 6u, &l_varTemp32 ) )
    {
        if( 6u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != la_memArea[0u] ) || ( ECU_SOF != la_memArea[1u] ) || ( 0x02u != la_memArea[2u] ) )
            {
                (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
            }
            else
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 3u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 3u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                                {
                                    if( true == l_frIsUnstuf)
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 5  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = 0x01u;
    l_stuffed[2u] = 0x02u;
    l_stuffed[3u] = 0x03u;
    l_stuffed[4u] = 0x04u;
    l_stuffed[5u] = 0x01u;
    l_stuffed[6u] = ECU_EOF;
    l_stuffed[7u] = ECU_SOF;

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 3u, &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 6  -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 2u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 2u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                            {
                                if( false == l_frIsUnstuf)
                                {
                                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 6  -- OK \n");
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 6  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffFrameEnd 6  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffFrameEnd 6  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 6  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 6  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffFrameEnd 6  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 6  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[3u], 6u, &l_varTemp32 ) )
    {
        if( 4u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != la_memArea[0u] ) || ( 0x02u != la_memArea[1u] ) || ( 0x03u != la_memArea[2u] ) ||
                ( 0x04u != la_memArea[3u] ) || ( 0x01u != la_memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
            }
            else
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 5u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 5u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                                {
                                    if( true == l_frIsUnstuf)
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 8  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = 0x01u;
    l_stuffed[2u] = ECU_ESC;
    l_stuffed[3u] = (uint8_t)(~ECU_SOF);
    l_stuffed[4u] = 0x02u;
    l_stuffed[5u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 3u, &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 9  -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 1u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 1u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                            {
                                if( false == l_frIsUnstuf)
                                {
                                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 9  -- OK \n");
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 9  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffFrameEnd 9  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffFrameEnd 9  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 9  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 9  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffFrameEnd 9  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 9  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[3u], 3u, &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != la_memArea[0u] ) || ( ECU_SOF != la_memArea[1u] ) || ( 0x02u != la_memArea[2u] ) )
            {
                (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
            }
            else
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 3u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 3u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&l_ctx, &l_frIsUnstuf) )
                                {
                                    if( true == l_frIsUnstuf)
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
    }
}

static void eCU_TEST_byteUnStuffGeneral(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctx;
    uint8_t  la_memArea[50u];
    uint8_t  l_stuffed[10u];
    uint32_t l_varTemp32;
    uint8_t* lp_aPointerP;
    bool_t l_isBad;

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 1  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 2u, &l_varTemp32 ) )
    {
        if( 2u != l_varTemp32  )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 2  -- FAIL \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 2  -- OK \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 2  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 1u, &l_varTemp32 ) )
    {
        if( 0u != l_varTemp32  )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 3  -- FAIL \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 3  -- OK \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 3  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 4  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = ECU_SOF;
    l_stuffed[2u] = ECU_ESC;
    l_stuffed[3u] = (uint8_t)(~ECU_SOF);
    l_stuffed[4u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_FRAMERESTART == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 5u, &l_varTemp32 ) )
    {
        if( 2u !=  l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 5  -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 0u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&l_ctx, &l_isBad) )
                            {
                                if( false == l_isBad)
                                {
                                    (void)printf("eCU_TEST_byteUnStuffGeneral 5  -- OK \n");
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffGeneral 5  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffGeneral 5  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffGeneral 5  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffGeneral 5  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffGeneral 5  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffGeneral 5  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 5  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[2u], 3u, &l_varTemp32 ) )
    {
        if( 3u !=  l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 6  -- FAIL \n");
        }
        else
        {
            if( ECU_SOF == la_memArea[0u] )
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 1u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 1u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                (void)printf("eCU_TEST_byteUnStuffGeneral 6  -- OK \n");
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffGeneral 6  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffGeneral 6  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffGeneral 6  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffGeneral 6  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffGeneral 6  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 6  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 3u, &l_varTemp32 ) )
    {
        if( 0u !=  l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 7  -- FAIL \n");
        }
        else
        {
            if( ECU_SOF == la_memArea[0u] )
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 1u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 1u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                (void)printf("eCU_TEST_byteUnStuffGeneral 7  -- OK \n");
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffGeneral 7  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffGeneral 7  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffGeneral 7  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffGeneral 7  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffGeneral 7  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 7  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 8  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = ECU_ESC;
    l_stuffed[2u] = 0x02u;
    l_stuffed[3u] = 0x02u;
    l_stuffed[4u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, 5u, &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 9  -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 0u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&l_ctx, &l_isBad) )
                            {
                                if( true == l_isBad)
                                {
                                    (void)printf("eCU_TEST_byteUnStuffGeneral 9  -- OK \n");
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffGeneral 9  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffGeneral 9  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffGeneral 9  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffGeneral 9  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffGeneral 9  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffGeneral 9  -- FAIL \n");
            }

        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 9  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 10 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[3u], 2u, &l_varTemp32 ) )
    {
        if( 1u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 11 -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 0u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            (void)printf("eCU_TEST_byteUnStuffGeneral 11 -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffGeneral 11 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffGeneral 11 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffGeneral 11 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffGeneral 11 -- FAIL \n");
            }

        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 11 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 12 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&l_ctx, &l_isBad) )
    {
        if( false == l_isBad)
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 13 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[4u], 1u, &l_varTemp32 ) )
    {
        if( 1u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 14 -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 0u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&l_ctx, &l_isBad) )
                            {
                                if( true == l_isBad)
                                {
                                    (void)printf("eCU_TEST_byteUnStuffGeneral 14 -- OK \n");
                                }
                                else
                                {
                                    (void)printf("eCU_TEST_byteUnStuffGeneral 14 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffGeneral 14 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffGeneral 14 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffGeneral 14 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffGeneral 14 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffGeneral 14 -- FAIL \n");
            }

        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 14 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame( &l_ctx ) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 15 -- FAIL \n");
    }

}

static void eCU_TEST_byteUnStuffCornerCase(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint8_t  l_stuffed[10u];
    uint32_t l_varTemp32;
    uint8_t* lp_aPointerP;

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 1  -- FAIL \n");
    }

    l_stuffed[0u] = 0x02u;
    l_stuffed[1u] = ECU_SOF;
    l_stuffed[2u] = 0x02u;
    l_stuffed[3u] = 0x03u;
    l_stuffed[4u] = 0x04u;
    l_stuffed[5u] = 0x01u;
    l_stuffed[6u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 1u !=  l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 2  -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( 0u == l_varTemp32 )
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 2  -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 2  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 2  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 2  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 2  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 2  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 3  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[1], sizeof(l_stuffed)-1u, &l_varTemp32 ) )
    {
        if( 6u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 4  -- FAIL \n");
        }
        else
        {
            if( ( 0x02u == la_memArea[0u] ) && ( 0x03u == la_memArea[1u] ) && ( 0x04u == la_memArea[2u] ) &&
                ( 0x01u == la_memArea[3u] ) )
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 4u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 4u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 4  -- OK \n");
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 4  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 4  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 4  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 4  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 4  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 5  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = ECU_SOF;
    l_stuffed[2u] = 0x01u;
    l_stuffed[3u] = 0x02u;
    l_stuffed[4u] = 0x03u;
    l_stuffed[5u] = 0x04u;
    l_stuffed[6u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_FRAMERESTART == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 2u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 6  -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 0u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 6  -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 6  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 6  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 6  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 6  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 6  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[2u], sizeof(l_stuffed)-1u, &l_varTemp32 ) )
    {
        if( 5u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 7  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u == la_memArea[0u] ) && ( 0x02u == la_memArea[1u] ) && ( 0x03u == la_memArea[2u] ) &&
                ( 0x04u == la_memArea[3u] ) )
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 4u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 4u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 7  -- OK \n");
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 7  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 7  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 7  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 7  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 7  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 7  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 8  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = ECU_EOF;
    l_stuffed[2u] = ECU_SOF;
    l_stuffed[3u] = 0x02u;
    l_stuffed[4u] = 0x03u;
    l_stuffed[5u] = 0x04u;
    l_stuffed[6u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 2u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 9  -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 0u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 9  -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 9  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 9  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 9  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 9  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 9  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 10 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[2u], sizeof(l_stuffed)-2u, &l_varTemp32 ) )
    {
        if( 5u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 11 -- FAIL \n");
        }
        else
        {
            if( ( 0x02u == la_memArea[0u] ) && ( 0x03u == la_memArea[1u] ) && ( 0x04u == la_memArea[2u] ) )
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 3u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 3u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 11 -- OK \n");
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 11 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 11 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 11 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 11 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 11 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 11 -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 12 -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = 0x02u;
    l_stuffed[2u] = ECU_ESC;
    l_stuffed[3u] = ECU_EOF;
    l_stuffed[4u] = ECU_SOF;
    l_stuffed[5u] = 0x02u;
    l_stuffed[6u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 4u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 13 -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 1u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 1u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 13 -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 13 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 13 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 13 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 13 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 13 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 14 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[4u], sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 3u !=  l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 15 -- FAIL \n");
        }
        else
        {
            if( 0x02u == la_memArea[0u] )
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 1u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 1u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 15 -- OK \n");
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 15 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 15 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 15 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 15 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 15 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 15 -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 16 -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = ECU_ESC;
    l_stuffed[2u] = ECU_ESC;
    l_stuffed[3u] = ECU_SOF;
    l_stuffed[4u] = 0x03u;
    l_stuffed[5u] = 0x02u;
    l_stuffed[6u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 17 -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 0u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 17 -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 17 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 17 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 17 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 17 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 17 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 18 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[3u], sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 4u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 19 -- FAIL \n");
        }
        else
        {
            if( ( 0x03u == la_memArea[0u] ) && ( 0x02u == la_memArea[1u] ) )
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 2u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 2u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 19 -- OK \n");
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 19 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 19 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 19 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 19 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 19 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 19 -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 20 -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = ECU_ESC;
    l_stuffed[2u] = 0x01u;
    l_stuffed[3u] = ECU_EOF;
    l_stuffed[4u] = ECU_SOF;
    l_stuffed[5u] = 0x03u;
    l_stuffed[6u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 21 -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 0u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 21 -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 21 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 21 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 21 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 21 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 21 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 22 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 22 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[3u], sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 1u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 23 -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 0u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 23 -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 23 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 23 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 23 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 23 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 23 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 24 -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[4u], sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 25 -- FAIL \n");
        }
        else
        {
            if( 0x03u == la_memArea[0u] )
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 1u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 1u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 25 -- OK \n");
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase 25 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase 25 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase 25 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase 25 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase 25 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 25 -- FAIL \n");
    }
}

static void eCU_TEST_byteUnStuffCornerCase2(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint8_t  l_stuffed[10u];
    uint32_t l_varTemp32;
    uint8_t* lp_aPointerP;

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase2 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase2 1  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = 0x02u;
    l_stuffed[2u] = ECU_ESC;
    l_stuffed[3u] = ECU_SOF;
    l_stuffed[4u] = 0x04u;
    l_stuffed[5u] = 0x01u;
    l_stuffed[6u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_FRAMERESTART == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 4u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase2 2  -- FAIL \n");
        }
        else
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                    {
                        if( ( 0u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase2 2  -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase2 2  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase2 2  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase2 2  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase2 2  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase2 2  -- FAIL \n");
    }

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, &l_stuffed[4u], sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( 3u != l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase2 3  -- FAIL \n");
        }
        else
        {
            if( ( 0x04u == la_memArea[0u] ) && ( 0x01u == la_memArea[1u] ) )
            {
                if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctx, &l_varTemp32) )
                {
                    if( 2u == l_varTemp32 )
                    {
                        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
                        {
                            if( ( 2u == l_varTemp32 ) && ( la_memArea == lp_aPointerP) )
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase2 3  -- OK \n");
                            }
                            else
                            {
                                (void)printf("eCU_TEST_byteUnStuffCornerCase2 3  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("eCU_TEST_byteUnStuffCornerCase2 3  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_byteUnStuffCornerCase2 3  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_byteUnStuffCornerCase2 3  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteUnStuffCornerCase2 3  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase2 3  -- FAIL \n");
    }

}

static void eCU_TEST_byteUnStuffCodeCoverage(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctx;
    uint8_t  la_memArea[50u];
    uint8_t  l_stuffed[10u];
    uint32_t l_varTemp32;

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 1  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 2  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = ECU_ESC;
    l_stuffed[2u] = (uint8_t)(~ECU_SOF);
    l_stuffed[3u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( ( (ECU_SOF == la_memArea[0u]) ) && ( 4u == l_varTemp32 ) )
        {
            (void)printf("eCU_TEST_byteUnStuffCodeCoverage 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffCodeCoverage 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 3  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 4  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = ECU_ESC;
    l_stuffed[2u] = (uint8_t)(~ECU_ESC);
    l_stuffed[3u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( ( (ECU_ESC == la_memArea[0u]) ) && ( 4u == l_varTemp32 ) )
        {
            (void)printf("eCU_TEST_byteUnStuffCodeCoverage 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffCodeCoverage 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 5  -- FAIL \n");
    }

    /* Function  */
    if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 6  -- FAIL \n");
    }

    l_stuffed[0u] = ECU_SOF;
    l_stuffed[1u] = ECU_ESC;
    l_stuffed[2u] = (uint8_t)(~ECU_EOF);
    l_stuffed[3u] = ECU_EOF;

    if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctx, l_stuffed, sizeof(l_stuffed), &l_varTemp32 ) )
    {
        if( ( (ECU_EOF == la_memArea[0u]) ) && ( 4u == l_varTemp32 ) )
        {
            (void)printf("eCU_TEST_byteUnStuffCodeCoverage 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteUnStuffCodeCoverage 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 7  -- FAIL \n");
    }
}
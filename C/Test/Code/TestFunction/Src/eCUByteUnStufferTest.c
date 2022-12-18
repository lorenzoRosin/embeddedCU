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
#include "eCUByteStuffer.h"
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
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t *dataP;
    bool_t frameIsUnstuffed;
    bool_t isWaiting;
    bool_t isInit;

    /* Function */
    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_InitCtx(NULL, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 1  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_InitCtx(&ctx, NULL, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 2  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_NewFrame( NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 3  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_GetUnstufData( NULL, &dataP, &varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 4  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_GetUnstufData( &ctx, NULL, &varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 5  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_GetUnstufData( &ctx, &dataP, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 6  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_GetUnstufLen( NULL, &varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 7  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_GetUnstufLen( &ctx, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 8  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsWaitingSof( NULL, &isWaiting ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 9  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsWaitingSof( &ctx, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 10 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsAFullFrameUnstuff( NULL, &frameIsUnstuffed ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 11 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsAFullFrameUnstuff( &ctx, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 12 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsFrameBad( NULL, &frameIsUnstuffed ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 13 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsFrameBad( &ctx, NULL ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 14 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_InsStufChunk( NULL, memArea, sizeof(memArea), &varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 15 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_InsStufChunk( &ctx, NULL, sizeof(memArea), &varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 16 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_InsStufChunk( &ctx, memArea, sizeof(memArea), NULL) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 17 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsInit( NULL, &isInit ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadPointer 18 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == eCU_BUNSTF_IsInit( &ctx, NULL ) )
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
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t *dataP;
    bool_t frameIsUnstuffed;
    bool_t isWaiting;
    bool_t isInit;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( BUNSTF_RES_NOINITLIB == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 1  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 2  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 3  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == eCU_BUNSTF_IsWaitingSof(&ctx, &isWaiting ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 4  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frameIsUnstuffed) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 5  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == eCU_BUNSTF_IsFrameBad(&ctx, &frameIsUnstuffed) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 6  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == eCU_BUNSTF_InsStufChunk( &ctx, memArea, sizeof(memArea), &varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadInit 7  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == eCU_BUNSTF_IsInit( &ctx, &isInit ) )
    {
        if( false == isInit )
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
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    bool_t isInit;

    /* Function */
    if( BUNSTF_RES_BADPARAM == eCU_BUNSTF_InitCtx(&ctx, memArea, 0u) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 1  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 2  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPARAM == eCU_BUNSTF_InsStufChunk( &ctx, memArea, 0u, &varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffBadParamEntr 3  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == eCU_BUNSTF_IsInit( &ctx, &isInit ) )
    {
        if( true == isInit )
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
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t *dataP;
    bool_t frameIsUnstuffed;
    bool_t isWaiting;

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 1  -- FAIL \n");
    }

    ctx.memASize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 2  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 3  -- FAIL \n");
    }

    ctx.p_memA = NULL;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 4  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 5  -- FAIL \n");
    }

    ctx.memACntr = ctx.memASize + 1u;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 6  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 7  -- FAIL \n");
    }

    ctx.memACntr = 1u;
    ctx.unStuffState = BUNSTF_SM_PRV_NEEDSOF;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 8  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 9  -- FAIL \n");
    }

    ctx.memACntr = 0u;
    ctx.unStuffState = BUNSTF_SM_PRV_UNSTUFFEND;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 10 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 11 -- FAIL \n");
    }

    ctx.memASize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 12 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 13 -- FAIL \n");
    }

    ctx.memASize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_GetUnstufData( &ctx, &dataP, &varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 14 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 15 -- FAIL \n");
    }

    ctx.memASize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_IsWaitingSof(&ctx, &isWaiting) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 16 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 17 -- FAIL \n");
    }

    ctx.memASize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frameIsUnstuffed) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 18 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 19 -- FAIL \n");
    }

    ctx.memASize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_IsFrameBad(&ctx, &frameIsUnstuffed) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 20 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCorrupterContext 21 -- FAIL \n");
    }

    ctx.memASize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == eCU_BUNSTF_InsStufChunk( &ctx, memArea, 9u, &varTemp32 ) )
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
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint8_t* dataP;
    bool_t frIsUnstuf;
    bool_t isWaiting;
    bool_t isBad;

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 1  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == eCU_BUNSTF_IsWaitingSof(&ctx, &isWaiting) )
    {
        if( true == isWaiting )
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

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_ESC;
    stuffed[7u] = 0x03u;
    stuffed[8u] = ECU_EOF;

    if( BUNSTF_RES_OUTOFMEM == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 9u, &varTemp32 ) )
    {
        if( 7u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 3  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( false == frIsUnstuf)
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_IsWaitingSof(&ctx, &isWaiting) )
    {
        if( false == isWaiting )
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 5  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x05u;
    stuffed[6u] = 0x06u;
    stuffed[7u] = ECU_EOF;

    if( BUNSTF_RES_OUTOFMEM == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 7u, &varTemp32 ) )
    {
        if( 6u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x05u != memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 6  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( false == frIsUnstuf)
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 7  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_ESC;
    stuffed[7u] = 0x03u;
    stuffed[8u] = ECU_EOF;

    if( BUNSTF_RES_OK == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 3u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 8  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 2u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 2u == varTemp32 ) && ( memArea == dataP) )
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[3u], 4u, &varTemp32 ) )
    {
        if( 4u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 9  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( false == frIsUnstuf)
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

    if( BUNSTF_RES_OUTOFMEM == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[7u], 1u, &varTemp32 ) )
    {
        if( 0u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 10 -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( false == frIsUnstuf)
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffOutOfMem 11 -- FAIL \n");
    }

    if( BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&ctx, &isBad) )
    {
        if( false == isBad )
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

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x05u;
    stuffed[6u] = 0x06u;
    stuffed[7u] = ECU_EOF;

    if( BUNSTF_RES_OK == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 3u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 13 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 2u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 2u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                            {
                                if( false == frIsUnstuf)
                                {
                                    if( BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&ctx, &isBad) )
                                    {
                                        if( false == isBad)
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

    if( BUNSTF_RES_OUTOFMEM == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[3u], 4u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x05u != memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffOutOfMem 14 -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( false == frIsUnstuf)
                                    {
                                        if( BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&ctx, &isBad) )
                                        {
                                            if( false == isBad)
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
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint8_t* dataP;
    bool_t frIsUnstuf;
    bool_t isBad;

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 1  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_EOF;
    stuffed[7u] = ECU_SOF;


    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 7u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffFrameEnd 2  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( true == frIsUnstuf)
                                    {
                                        if( BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&ctx, &isBad) )
                                        {
                                            if( false == isBad)
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 3  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = (uint8_t)(~ECU_SOF);
    stuffed[4u] = 0x02u;
    stuffed[5u] = ECU_EOF;

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 6u, &varTemp32 ) )
    {
        if( 6u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( ECU_SOF != memArea[1u] ) || ( 0x02u != memArea[2u] ) )
            {
                (void)printf("eCU_TEST_byteUnStuffFrameEnd 4  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 3u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 3u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( true == frIsUnstuf)
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 5  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_EOF;
    stuffed[7u] = ECU_SOF;

    if( BUNSTF_RES_OK == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 3u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 6  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 2u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 2u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                            {
                                if( false == frIsUnstuf)
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

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[3u], 6u, &varTemp32 ) )
    {
        if( 4u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
            {
                (void)printf("eCU_TEST_byteUnStuffFrameEnd 7  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( true == frIsUnstuf)
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffFrameEnd 8  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = (uint8_t)(~ECU_SOF);
    stuffed[4u] = 0x02u;
    stuffed[5u] = ECU_EOF;

    if( BUNSTF_RES_OK == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 3u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 9  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 1u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                            {
                                if( false == frIsUnstuf)
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

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[3u], 3u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( ECU_SOF != memArea[1u] ) || ( 0x02u != memArea[2u] ) )
            {
                (void)printf("eCU_TEST_byteUnStuffFrameEnd 10 -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 3u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 3u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == eCU_BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( true == frIsUnstuf)
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
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[50u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint8_t* dataP;
    bool_t isBad;

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 1  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 2u, &varTemp32 ) )
    {
        if( 2u != varTemp32  )
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

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 1u, &varTemp32 ) )
    {
        if( 0u != varTemp32  )
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 4  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_SOF;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = (uint8_t)(~ECU_SOF);
    stuffed[4u] = ECU_EOF;

    if( BUNSTF_RES_FRAMERESTART == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 5u, &varTemp32 ) )
    {
        if( 2u !=  varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 5  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&ctx, &isBad) )
                            {
                                if( false == isBad)
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

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[2u], 3u, &varTemp32 ) )
    {
        if( 3u !=  varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 6  -- FAIL \n");
        }
        else
        {
            if( ECU_SOF == memArea[0u] )
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 1u == varTemp32 ) && ( memArea == dataP) )
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

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 3u, &varTemp32 ) )
    {
        if( 0u !=  varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 7  -- FAIL \n");
        }
        else
        {
            if( ECU_SOF == memArea[0u] )
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 1u == varTemp32 ) && ( memArea == dataP) )
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 8  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x02u;
    stuffed[4u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, 5u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 9  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&ctx, &isBad) )
                            {
                                if( true == isBad)
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 10 -- FAIL \n");
    }

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[3u], 2u, &varTemp32 ) )
    {
        if( 1u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 11 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffGeneral 12 -- FAIL \n");
    }

    if( BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&ctx, &isBad) )
    {
        if( false == isBad)
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

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[4u], 1u, &varTemp32 ) )
    {
        if( 1u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffGeneral 14 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == eCU_BUNSTF_IsFrameBad(&ctx, &isBad) )
                            {
                                if( true == isBad)
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame( &ctx ) )
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
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint8_t* dataP;

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 1  -- FAIL \n");
    }

    stuffed[0u] = 0x02u;
    stuffed[1u] = ECU_SOF;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 1u !=  varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 2  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( 0u == varTemp32 )
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 3  -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[1], sizeof(stuffed)-1u, &varTemp32 ) )
    {
        if( 6u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 4  -- FAIL \n");
        }
        else
        {
            if( ( 0x02u == memArea[0u] ) && ( 0x03u == memArea[1u] ) && ( 0x04u == memArea[2u] ) &&
                ( 0x01u == memArea[3u] ) )
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 4u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 4u == varTemp32 ) && ( memArea == dataP) )
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 5  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_SOF;
    stuffed[2u] = 0x01u;
    stuffed[3u] = 0x02u;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x04u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_FRAMERESTART == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 2u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 6  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
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

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[2u], sizeof(stuffed)-1u, &varTemp32 ) )
    {
        if( 5u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 7  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u == memArea[0u] ) && ( 0x02u == memArea[1u] ) && ( 0x03u == memArea[2u] ) &&
                ( 0x04u == memArea[3u] ) )
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 4u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 4u == varTemp32 ) && ( memArea == dataP) )
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 8  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_EOF;
    stuffed[2u] = ECU_SOF;
    stuffed[3u] = 0x02u;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x04u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 2u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 9  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 10 -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[2u], sizeof(stuffed)-2u, &varTemp32 ) )
    {
        if( 5u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 11 -- FAIL \n");
        }
        else
        {
            if( ( 0x02u == memArea[0u] ) && ( 0x03u == memArea[1u] ) && ( 0x04u == memArea[2u] ) )
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 3u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 3u == varTemp32 ) && ( memArea == dataP) )
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 12 -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x02u;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = ECU_EOF;
    stuffed[4u] = ECU_SOF;
    stuffed[5u] = 0x02u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 4u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 13 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 1u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 1u == varTemp32 ) && ( memArea == dataP) )
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 14 -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[4u], sizeof(stuffed), &varTemp32 ) )
    {
        if( 3u !=  varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 15 -- FAIL \n");
        }
        else
        {
            if( 0x02u == memArea[0u] )
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 1u == varTemp32 ) && ( memArea == dataP) )
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 16 -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = ECU_SOF;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x02u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 17 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 18 -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[3u], sizeof(stuffed), &varTemp32 ) )
    {
        if( 4u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 19 -- FAIL \n");
        }
        else
        {
            if( ( 0x03u == memArea[0u] ) && ( 0x02u == memArea[1u] ) )
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 2u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 2u == varTemp32 ) && ( memArea == dataP) )
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 20 -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = 0x01u;
    stuffed[3u] = ECU_EOF;
    stuffed[4u] = ECU_SOF;
    stuffed[5u] = 0x03u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 21 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 22 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 22 -- FAIL \n");
    }

    if( BUNSTF_RES_BADFRAME == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[3u], sizeof(stuffed), &varTemp32 ) )
    {
        if( 1u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 23 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
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

    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase 24 -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[4u], sizeof(stuffed), &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase 25 -- FAIL \n");
        }
        else
        {
            if( 0x03u == memArea[0u] )
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 1u == varTemp32 ) && ( memArea == dataP) )
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
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint8_t* dataP;

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase2 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCornerCase2 1  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x02u;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = ECU_SOF;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_FRAMERESTART == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 4u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase2 2  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
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

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, &stuffed[4u], sizeof(stuffed), &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("eCU_TEST_byteUnStuffCornerCase2 3  -- FAIL \n");
        }
        else
        {
            if( ( 0x04u == memArea[0u] ) && ( 0x01u == memArea[1u] ) )
            {
                if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 2u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 2u == varTemp32 ) && ( memArea == dataP) )
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
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[50u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 1  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 2  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = (uint8_t)(~ECU_SOF);
    stuffed[3u] = ECU_EOF;

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( ( (ECU_SOF == memArea[0u]) ) && ( 4u == varTemp32 ) )
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 4  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = (uint8_t)(~ECU_ESC);
    stuffed[3u] = ECU_EOF;

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( ( (ECU_ESC == memArea[0u]) ) && ( 4u == varTemp32 ) )
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
    if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteUnStuffCodeCoverage 6  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = (uint8_t)(~ECU_EOF);
    stuffed[3u] = ECU_EOF;

    if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( ( (ECU_EOF == memArea[0u]) ) && ( 4u == varTemp32 ) )
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
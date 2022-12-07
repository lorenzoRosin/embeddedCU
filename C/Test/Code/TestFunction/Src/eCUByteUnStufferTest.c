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

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif

#include <stdio.h>

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2012-Rule-10.3"
    /* Suppressed for code clarity in test execution*/
#endif

/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void byteUnStuffTestBadPointer(void);
static void byteUnStuffTestBadInit(void);
static void byteUnStuffTestBadParamEntr(void);
static void byteUnStuffTestCorrupterContext(void);
static void byteUnStuffTestOutOfMem(void);
static void byteUnStuffTestFrameEnd(void);
static void byteUnStuffTestGeneral(void);
static void byteUnStuffTestCornerCase(void);
static void byteUnStuffTestCornerCase2(void);
static void byteUnStuffTestCodeCoverage(void);

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void byteUnStufferTest(void)
{
	(void)printf("\n\nBYTE UNSTUFFER TEST START \n\n");

    byteUnStuffTestBadPointer();
    byteUnStuffTestBadInit();
    byteUnStuffTestBadParamEntr();
    byteUnStuffTestCorrupterContext();
    byteUnStuffTestOutOfMem();
    byteUnStuffTestFrameEnd();
    byteUnStuffTestGeneral();
    byteUnStuffTestCornerCase();
    byteUnStuffTestCornerCase2();
    byteUnStuffTestCodeCoverage();

    (void)printf("\n\nBYTE UNSTUFFER TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void byteUnStuffTestBadPointer(void)
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
    if( BUNSTF_RES_BADPOINTER == BUNSTF_InitCtx(NULL, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 1  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_InitCtx(&ctx, NULL, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 2  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_StartNewFrame( NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 3  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_GetUnstufData( NULL, &dataP, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 4  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_GetUnstufData( &ctx, NULL, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 5  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_GetUnstufData( &ctx, &dataP, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 6  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_GetUnstufLen( NULL, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 7  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_GetUnstufLen( &ctx, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 8  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_IsWaitingSof( NULL, &isWaiting ) )
    {
        (void)printf("byteUnStuffTestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 9  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_IsWaitingSof( &ctx, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 10 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_IsAFullFrameUnstuff( NULL, &frameIsUnstuffed ) )
    {
        (void)printf("byteUnStuffTestBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 11 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_IsAFullFrameUnstuff( &ctx, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 12 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_IsCurrentFrameBad( NULL, &frameIsUnstuffed ) )
    {
        (void)printf("byteUnStuffTestBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 13 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_IsCurrentFrameBad( &ctx, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 14 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_InsStufChunk( NULL, memArea, sizeof(memArea), &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadPointer 15 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 15 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_InsStufChunk( &ctx, NULL, sizeof(memArea), &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadPointer 16 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 16 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_InsStufChunk( &ctx, memArea, sizeof(memArea), NULL) )
    {
        (void)printf("byteUnStuffTestBadPointer 17 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 17 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_IsInit( NULL, &isInit ) )
    {
        (void)printf("byteUnStuffTestBadPointer 18 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 18 -- FAIL \n");
    }

    if( BUNSTF_RES_BADPOINTER == BUNSTF_IsInit( &ctx, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 19 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 19 -- FAIL \n");
    }
}

void byteUnStuffTestBadInit(void)
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
    if( BUNSTF_RES_NOINITLIB == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 1  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 2  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 3  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == BUNSTF_IsWaitingSof(&ctx, &isWaiting ) )
    {
        (void)printf("byteUnStuffTestBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 4  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == BUNSTF_IsAFullFrameUnstuff(&ctx, &frameIsUnstuffed) )
    {
        (void)printf("byteUnStuffTestBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 5  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == BUNSTF_IsCurrentFrameBad(&ctx, &frameIsUnstuffed) )
    {
        (void)printf("byteUnStuffTestBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 6  -- FAIL \n");
    }

    if( BUNSTF_RES_NOINITLIB == BUNSTF_InsStufChunk( &ctx, memArea, sizeof(memArea), &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 7  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_IsInit( &ctx, &isInit ) )
    {
        if( false == isInit )
        {
            (void)printf("byteUnStuffTestBadInit 8  -- OK \n");
        }
        else
        {
            (void)printf("byteUnStuffTestBadInit 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 8  -- FAIL \n");
    }
}

void byteUnStuffTestBadParamEntr(void)
{
    /* Local variable */
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    bool_t isInit;

    /* Function */
    if( BUNSTF_RES_BADPARAM == BUNSTF_InitCtx(&ctx, memArea, 0u) )
    {
        (void)printf("byteUnStuffTestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamEntr 1  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamEntr 2  -- FAIL \n");
    }

    if( BUNSTF_RES_BADPARAM == BUNSTF_InsStufChunk( &ctx, memArea, 0u, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamEntr 3  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_IsInit( &ctx, &isInit ) )
    {
        if( true == isInit )
        {
            (void)printf("byteUnStuffTestBadParamEntr 4  -- OK \n");
        }
        else
        {
            (void)printf("byteUnStuffTestBadParamEntr 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamEntr 4  -- FAIL \n");
    }
}

void byteUnStuffTestCorrupterContext(void)
{
    /* Local variable */
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t *dataP;
    bool_t frameIsUnstuffed;
    bool_t isWaiting;

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 1  -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 2  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 3  -- FAIL \n");
    }

    ctx.memArea = NULL;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 4  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 5  -- FAIL \n");
    }

    ctx.memAreaCntr = ctx.memAreaSize + 1u;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 6  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 6  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 7  -- FAIL \n");
    }

    ctx.memAreaCntr = 1u;
    ctx.unStuffState = BUNSTF_SM_PRV_NEEDSOF;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 8  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 9  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 9  -- FAIL \n");
    }

    ctx.memAreaCntr = 0u;
    ctx.unStuffState = BUNSTF_SM_PRV_UNSTUFFEND;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 10 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 10 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 11 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 11 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 12 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 12 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 13 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 13 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_GetUnstufData( &ctx, &dataP, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 14 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 14 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 15 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 15 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_IsWaitingSof(&ctx, &isWaiting) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 16 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 16 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 17 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 17 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_IsAFullFrameUnstuff(&ctx, &frameIsUnstuffed) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 18 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 18 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 19 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 19 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_IsCurrentFrameBad(&ctx, &frameIsUnstuffed) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 20 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 20 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 21 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 21 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( BUNSTF_RES_CORRUPTCTX == BUNSTF_InsStufChunk( &ctx, memArea, 9u, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestCorrupterContext 22 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCorrupterContext 22 -- FAIL \n");
    }
}

void byteUnStuffTestOutOfMem(void)
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
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 1  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_IsWaitingSof(&ctx, &isWaiting) )
    {
        if( true == isWaiting )
        {
            (void)printf("byteUnStuffTestOutOfMem 2  -- OK \n");
        }
        else
        {
            (void)printf("byteUnStuffTestOutOfMem 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 2  -- FAIL \n");
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

    if( BUNSTF_RES_OUTOFMEM == BUNSTF_InsStufChunk( &ctx, stuffed, 9u, &varTemp32 ) )
    {
        if( 7u != varTemp32 )
        {
            (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
            {
                (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( false == frIsUnstuf)
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 3  -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_IsWaitingSof(&ctx, &isWaiting) )
    {
        if( false == isWaiting )
        {
            (void)printf("byteUnStuffTestOutOfMem 4  -- OK \n");
        }
        else
        {
            (void)printf("byteUnStuffTestOutOfMem 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 4  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestOutOfMem 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 5  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x05u;
    stuffed[6u] = 0x06u;
    stuffed[7u] = ECU_EOF;

    if( BUNSTF_RES_OUTOFMEM == BUNSTF_InsStufChunk( &ctx, stuffed, 7u, &varTemp32 ) )
    {
        if( 6u != varTemp32 )
        {
            (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x05u != memArea[4u] )  )
            {
                (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( false == frIsUnstuf)
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 6  -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestOutOfMem 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
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

    if( BUNSTF_RES_OK == BUNSTF_InsStufChunk( &ctx, stuffed, 3u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 2u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 2u == varTemp32 ) && ( memArea == dataP) )
                        {
                            (void)printf("byteUnStuffTestOutOfMem 8  -- OK \n");
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_InsStufChunk( &ctx, &stuffed[3u], 4u, &varTemp32 ) )
    {
        if( 4u != varTemp32 )
        {
            (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
            {
                (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( false == frIsUnstuf)
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 9  -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
    }

    if( BUNSTF_RES_OUTOFMEM == BUNSTF_InsStufChunk( &ctx, &stuffed[7u], 1u, &varTemp32 ) )
    {
        if( 0u != varTemp32 )
        {
            (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
            {
                (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( false == frIsUnstuf)
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 10 -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestOutOfMem 11 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_IsCurrentFrameBad(&ctx, &isBad) )
    {
        if( false == isBad )
        {
            (void)printf("byteUnStuffTestOutOfMem 12 -- OK \n");
        }
        else
        {
            (void)printf("byteUnStuffTestOutOfMem 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 12 -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x05u;
    stuffed[6u] = 0x06u;
    stuffed[7u] = ECU_EOF;

    if( BUNSTF_RES_OK == BUNSTF_InsStufChunk( &ctx, stuffed, 3u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestOutOfMem 13 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 2u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 2u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                            {
                                if( false == frIsUnstuf)
                                {
                                    if( BUNSTF_RES_OK == BUNSTF_IsCurrentFrameBad(&ctx, &isBad) )
                                    {
                                        if( false == isBad)
                                        {
                                            (void)printf("byteUnStuffTestOutOfMem 13 -- OK \n");
                                        }
                                        else
                                        {
                                            (void)printf("byteUnStuffTestOutOfMem 13 -- FAIL \n");
                                        }
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 13 -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestOutOfMem 13 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestOutOfMem 13 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestOutOfMem 13 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestOutOfMem 13 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestOutOfMem 13 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestOutOfMem 13 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 13 -- FAIL \n");
    }

    if( BUNSTF_RES_OUTOFMEM == BUNSTF_InsStufChunk( &ctx, &stuffed[3u], 4u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x05u != memArea[4u] )  )
            {
                (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( false == frIsUnstuf)
                                    {
                                        if( BUNSTF_RES_OK == BUNSTF_IsCurrentFrameBad(&ctx, &isBad) )
                                        {
                                            if( false == isBad)
                                            {
                                                (void)printf("byteUnStuffTestOutOfMem 14 -- OK \n");
                                            }
                                            else
                                            {
                                                (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
                                            }
                                        }
                                        else
                                        {
                                            (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
                                        }
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 14 -- FAIL \n");
    }
}

void byteUnStuffTestFrameEnd(void)
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
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestFrameEnd 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 1  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_EOF;
    stuffed[7u] = ECU_SOF;


    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 7u != varTemp32 )
        {
            (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
            {
                (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( true == frIsUnstuf)
                                    {
                                        if( BUNSTF_RES_OK == BUNSTF_IsCurrentFrameBad(&ctx, &isBad) )
                                        {
                                            if( false == isBad)
                                            {
                                                (void)printf("byteUnStuffTestFrameEnd 2  -- OK \n");
                                            }
                                            else
                                            {
                                                (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
                                            }
                                        }
                                        else
                                        {
                                            (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
                                        }
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
    }


    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestFrameEnd 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 3  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = (uint8_t)(~ECU_SOF);
    stuffed[4u] = 0x02u;
    stuffed[5u] = ECU_EOF;

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, stuffed, 6u, &varTemp32 ) )
    {
        if( 6u != varTemp32 )
        {
            (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( ECU_SOF != memArea[1u] ) || ( 0x02u != memArea[2u] ) )
            {
                (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 3u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 3u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( true == frIsUnstuf)
                                    {
                                        (void)printf("byteUnStuffTestFrameEnd 4  -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestFrameEnd 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 5  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_EOF;
    stuffed[7u] = ECU_SOF;

    if( BUNSTF_RES_OK == BUNSTF_InsStufChunk( &ctx, stuffed, 3u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 2u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 2u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                            {
                                if( false == frIsUnstuf)
                                {
                                    (void)printf("byteUnStuffTestFrameEnd 6  -- OK \n");
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, &stuffed[3u], 6u, &varTemp32 ) )
    {
        if( 4u != varTemp32 )
        {
            (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
            {
                (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 5u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( true == frIsUnstuf)
                                    {
                                        (void)printf("byteUnStuffTestFrameEnd 7  -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestFrameEnd 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 8  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = (uint8_t)(~ECU_SOF);
    stuffed[4u] = 0x02u;
    stuffed[5u] = ECU_EOF;

    if( BUNSTF_RES_OK == BUNSTF_InsStufChunk( &ctx, stuffed, 3u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 1u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                            {
                                if( false == frIsUnstuf)
                                {
                                    (void)printf("byteUnStuffTestFrameEnd 9  -- OK \n");
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, &stuffed[3u], 3u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
        }
        else
        {
            if( ( 0x01u != memArea[0u] ) || ( ECU_SOF != memArea[1u] ) || ( 0x02u != memArea[2u] ) )
            {
                (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
            }
            else
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 3u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 3u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( BUNSTF_RES_OK == BUNSTF_IsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                {
                                    if( true == frIsUnstuf)
                                    {
                                        (void)printf("byteUnStuffTestFrameEnd 10 -- OK \n");
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
    }
}

void byteUnStuffTestGeneral(void)
{
    /* Local variable */
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[50u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint8_t* dataP;
    bool_t isBad;

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestGeneral 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 1  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, stuffed, 2u, &varTemp32 ) )
    {
        if( 2u != varTemp32  )
        {
            (void)printf("byteUnStuffTestGeneral 2  -- FAIL \n");
        }
        else
        {
            (void)printf("byteUnStuffTestGeneral 2  -- OK \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 2  -- FAIL \n");
    }

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, stuffed, 1u, &varTemp32 ) )
    {
        if( 0u != varTemp32  )
        {
            (void)printf("byteUnStuffTestGeneral 3  -- FAIL \n");
        }
        else
        {
            (void)printf("byteUnStuffTestGeneral 3  -- OK \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 3  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestGeneral 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 4  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_SOF;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = (uint8_t)(~ECU_SOF);
    stuffed[4u] = ECU_EOF;

    if( BUNSTF_RES_FRAMERESTART == BUNSTF_InsStufChunk( &ctx, stuffed, 5u, &varTemp32 ) )
    {
        if( 2u !=  varTemp32 )
        {
            (void)printf("byteUnStuffTestGeneral 5  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == BUNSTF_IsCurrentFrameBad(&ctx, &isBad) )
                            {
                                if( false == isBad)
                                {
                                    (void)printf("byteUnStuffTestGeneral 5  -- OK \n");
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestGeneral 5  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestGeneral 5  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestGeneral 5  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestGeneral 5  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestGeneral 5  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestGeneral 5  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 5  -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, &stuffed[2u], 3u, &varTemp32 ) )
    {
        if( 3u !=  varTemp32 )
        {
            (void)printf("byteUnStuffTestGeneral 6  -- FAIL \n");
        }
        else
        {
            if( ECU_SOF == memArea[0u] )
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                            {
                                (void)printf("byteUnStuffTestGeneral 6  -- OK \n");
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestGeneral 6  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestGeneral 6  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestGeneral 6  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestGeneral 6  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestGeneral 6  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 6  -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, stuffed, 3u, &varTemp32 ) )
    {
        if( 0u !=  varTemp32 )
        {
            (void)printf("byteUnStuffTestGeneral 7  -- FAIL \n");
        }
        else
        {
            if( ECU_SOF == memArea[0u] )
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                            {
                                (void)printf("byteUnStuffTestGeneral 7  -- OK \n");
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestGeneral 7  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestGeneral 7  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestGeneral 7  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestGeneral 7  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestGeneral 7  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 7  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestGeneral 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 8  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x02u;
    stuffed[4u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, stuffed, 5u, &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestGeneral 9  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == BUNSTF_IsCurrentFrameBad(&ctx, &isBad) )
                            {
                                if( true == isBad)
                                {
                                    (void)printf("byteUnStuffTestGeneral 9  -- OK \n");
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestGeneral 9  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestGeneral 9  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestGeneral 9  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestGeneral 9  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestGeneral 9  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestGeneral 9  -- FAIL \n");
            }

        }
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 9  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestGeneral 10 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 10 -- FAIL \n");
    }

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, &stuffed[3u], 2u, &varTemp32 ) )
    {
        if( 1u != varTemp32 )
        {
            (void)printf("byteUnStuffTestGeneral 11 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            (void)printf("byteUnStuffTestGeneral 11 -- OK \n");
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestGeneral 11 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestGeneral 11 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestGeneral 11 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestGeneral 11 -- FAIL \n");
            }

        }
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 11 -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestGeneral 12 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 12 -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_IsCurrentFrameBad(&ctx, &isBad) )
    {
        if( false == isBad)
        {
            (void)printf("byteUnStuffTestGeneral 13 -- OK \n");
        }
        else
        {
            (void)printf("byteUnStuffTestGeneral 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 13 -- FAIL \n");
    }

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, &stuffed[4u], 1u, &varTemp32 ) )
    {
        if( 1u != varTemp32 )
        {
            (void)printf("byteUnStuffTestGeneral 14 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            if( BUNSTF_RES_OK == BUNSTF_IsCurrentFrameBad(&ctx, &isBad) )
                            {
                                if( true == isBad)
                                {
                                    (void)printf("byteUnStuffTestGeneral 14 -- OK \n");
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestGeneral 14 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestGeneral 14 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestGeneral 14 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestGeneral 14 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestGeneral 14 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestGeneral 14 -- FAIL \n");
            }

        }
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 14 -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame( &ctx ) )
    {
        (void)printf("byteUnStuffTestGeneral 15 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 15 -- FAIL \n");
    }

}

void byteUnStuffTestCornerCase(void)
{
    /* Local variable */
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint8_t* dataP;

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- FAIL \n");
    }

    stuffed[0u] = 0x02u;
    stuffed[1u] = ECU_SOF;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 1u !=  varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( 0u == varTemp32 )
                        {
                            (void)printf("byteUnStuffTestCornerCase 2  -- OK \n");
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCornerCase 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 3  -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, &stuffed[1], sizeof(stuffed)-1u, &varTemp32 ) )
    {
        if( 6u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 4  -- FAIL \n");
        }
        else
        {
            if( ( 0x02u == memArea[0u] ) && ( 0x03u == memArea[1u] ) && ( 0x04u == memArea[2u] ) &&
                ( 0x01u == memArea[3u] ) )
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 4u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 4u == varTemp32 ) && ( memArea == dataP) )
                            {
                                (void)printf("byteUnStuffTestCornerCase 4  -- OK \n");
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestCornerCase 4  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 4  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 4  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 4  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 4  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 5  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_SOF;
    stuffed[2u] = 0x01u;
    stuffed[3u] = 0x02u;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x04u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_FRAMERESTART == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 2u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 6  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            (void)printf("byteUnStuffTestCornerCase 6  -- OK \n");
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 6  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 6  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 6  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 6  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 6  -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, &stuffed[2u], sizeof(stuffed)-1u, &varTemp32 ) )
    {
        if( 5u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 7  -- FAIL \n");
        }
        else
        {
            if( ( 0x01u == memArea[0u] ) && ( 0x02u == memArea[1u] ) && ( 0x03u == memArea[2u] ) &&
                ( 0x04u == memArea[3u] ) )
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 4u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 4u == varTemp32 ) && ( memArea == dataP) )
                            {
                                (void)printf("byteUnStuffTestCornerCase 7  -- OK \n");
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestCornerCase 7  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 7  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 7  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 7  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 7  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 7  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 8  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_EOF;
    stuffed[2u] = ECU_SOF;
    stuffed[3u] = 0x02u;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x04u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 2u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 9  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            (void)printf("byteUnStuffTestCornerCase 9  -- OK \n");
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 9  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 9  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 9  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 9  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 9  -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 10 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 10 -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, &stuffed[2u], sizeof(stuffed)-2u, &varTemp32 ) )
    {
        if( 5u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 11 -- FAIL \n");
        }
        else
        {
            if( ( 0x02u == memArea[0u] ) && ( 0x03u == memArea[1u] ) && ( 0x04u == memArea[2u] ) )
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 3u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 3u == varTemp32 ) && ( memArea == dataP) )
                            {
                                (void)printf("byteUnStuffTestCornerCase 11 -- OK \n");
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestCornerCase 11 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 11 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 11 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 11 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 11 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 11 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 12 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 12 -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x02u;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = ECU_EOF;
    stuffed[4u] = ECU_SOF;
    stuffed[5u] = 0x02u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 4u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 13 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 1u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                        {
                            (void)printf("byteUnStuffTestCornerCase 13 -- OK \n");
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 13 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 13 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 13 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 13 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 13 -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 14 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 14 -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, &stuffed[4u], sizeof(stuffed), &varTemp32 ) )
    {
        if( 3u !=  varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 15 -- FAIL \n");
        }
        else
        {
            if( 0x02u == memArea[0u] )
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                            {
                                (void)printf("byteUnStuffTestCornerCase 15 -- OK \n");
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestCornerCase 15 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 15 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 15 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 15 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 15 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 15 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 16 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 16 -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = ECU_SOF;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x02u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 17 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            (void)printf("byteUnStuffTestCornerCase 17 -- OK \n");
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 17 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 17 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 17 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 17 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 17 -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 18 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 18 -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, &stuffed[3u], sizeof(stuffed), &varTemp32 ) )
    {
        if( 4u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 19 -- FAIL \n");
        }
        else
        {
            if( ( 0x03u == memArea[0u] ) && ( 0x02u == memArea[1u] ) )
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 2u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 2u == varTemp32 ) && ( memArea == dataP) )
                            {
                                (void)printf("byteUnStuffTestCornerCase 19 -- OK \n");
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestCornerCase 19 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 19 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 19 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 19 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 19 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 19 -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 20 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 20 -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = 0x01u;
    stuffed[3u] = ECU_EOF;
    stuffed[4u] = ECU_SOF;
    stuffed[5u] = 0x03u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 21 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            (void)printf("byteUnStuffTestCornerCase 21 -- OK \n");
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 21 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 21 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 21 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 21 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 21 -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 22 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 22 -- FAIL \n");
    }

    if( BUNSTF_RES_BADFRAME == BUNSTF_InsStufChunk( &ctx, &stuffed[3u], sizeof(stuffed), &varTemp32 ) )
    {
        if( 1u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 23 -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            (void)printf("byteUnStuffTestCornerCase 23 -- OK \n");
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 23 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 23 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 23 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 23 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 23 -- FAIL \n");
    }

    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 24 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 24 -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, &stuffed[4u], sizeof(stuffed), &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase 25 -- FAIL \n");
        }
        else
        {
            if( 0x03u == memArea[0u] )
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                            {
                                (void)printf("byteUnStuffTestCornerCase 25 -- OK \n");
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestCornerCase 25 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 25 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 25 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 25 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase 25 -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 25 -- FAIL \n");
    }
}

void byteUnStuffTestCornerCase2(void)
{
    /* Local variable */
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint8_t* dataP;

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCornerCase2 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase2 1  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x02u;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = ECU_SOF;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_EOF;

    if( BUNSTF_RES_FRAMERESTART == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( 4u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase2 2  -- FAIL \n");
        }
        else
        {
            if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
                        {
                            (void)printf("byteUnStuffTestCornerCase2 2  -- OK \n");
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase2 2  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase2 2  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase2 2  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase2 2  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase2 2  -- FAIL \n");
    }

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, &stuffed[4u], sizeof(stuffed), &varTemp32 ) )
    {
        if( 3u != varTemp32 )
        {
            (void)printf("byteUnStuffTestCornerCase2 3  -- FAIL \n");
        }
        else
        {
            if( ( 0x04u == memArea[0u] ) && ( 0x01u == memArea[1u] ) )
            {
                if( BUNSTF_RES_OK == BUNSTF_GetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 2u == varTemp32 )
                    {
                        if( BUNSTF_RES_OK == BUNSTF_GetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 2u == varTemp32 ) && ( memArea == dataP) )
                            {
                                (void)printf("byteUnStuffTestCornerCase2 3  -- OK \n");
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestCornerCase2 3  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase2 3  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase2 3  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase2 3  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestCornerCase2 3  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase2 3  -- FAIL \n");
    }

}

void byteUnStuffTestCodeCoverage(void)
{
    /* Local variable */
    s_eCU_BUNSTF_Ctx ctx;
    uint8_t  memArea[50u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCodeCoverage 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCodeCoverage 1  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCodeCoverage 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCodeCoverage 2  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = (uint8_t)(~ECU_SOF);
    stuffed[3u] = ECU_EOF;

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( ( (ECU_SOF == memArea[0u]) ) && ( 4u == varTemp32 ) )
        {
            (void)printf("byteUnStuffTestCodeCoverage 3  -- OK \n");
        }
        else
        {
            (void)printf("byteUnStuffTestCodeCoverage 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCodeCoverage 3  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCodeCoverage 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCodeCoverage 4  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = (uint8_t)(~ECU_ESC);
    stuffed[3u] = ECU_EOF;

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( ( (ECU_ESC == memArea[0u]) ) && ( 4u == varTemp32 ) )
        {
            (void)printf("byteUnStuffTestCodeCoverage 5  -- OK \n");
        }
        else
        {
            (void)printf("byteUnStuffTestCodeCoverage 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCodeCoverage 5  -- FAIL \n");
    }

    /* Function  */
    if( BUNSTF_RES_OK == BUNSTF_StartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCodeCoverage 6  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCodeCoverage 6  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = (uint8_t)(~ECU_EOF);
    stuffed[3u] = ECU_EOF;

    if( BUNSTF_RES_FRAMEENDED == BUNSTF_InsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32 ) )
    {
        if( ( (ECU_EOF == memArea[0u]) ) && ( 4u == varTemp32 ) )
        {
            (void)printf("byteUnStuffTestCodeCoverage 7  -- OK \n");
        }
        else
        {
            (void)printf("byteUnStuffTestCodeCoverage 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCodeCoverage 7  -- FAIL \n");
    }
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2012-Rule-10.3"
#endif
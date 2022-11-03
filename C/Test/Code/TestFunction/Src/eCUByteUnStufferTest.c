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
static void byteUnStuffTestBadParamStatus(void);
static void byteUnStuffTestOutOfMem(void);
static void byteUnStuffTestFrameEnd(void);
static void byteUnStuffTestGeneral(void);
static void byteUnStuffTestCornerCase(void);
static void byteUnStuffTestCornerCase2(void);

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void byteUnStufferTest(void)
{
	(void)printf("\n\nBYTE UNSTUFFER TEST START \n\n");

    byteUnStuffTestBadPointer();
    byteUnStuffTestBadInit();
    byteUnStuffTestBadParamEntr();
    byteUnStuffTestBadParamStatus();
    byteUnStuffTestOutOfMem();
    byteUnStuffTestFrameEnd();
    byteUnStuffTestGeneral();
    byteUnStuffTestCornerCase();
    byteUnStuffTestCornerCase2();

    (void)printf("\n\nBYTE UNSTUFFER TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void byteUnStuffTestBadPointer(void)
{
    /* Local variable */
    s_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint32_t a;
    uint8_t *dataP;
    bool_t frameIsUnstuffed;

    /* Function */
    if( DBUSTF_RES_BADPOINTER == bUStufferInitCtx(NULL, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 1  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferInitCtx(&ctx, NULL, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 2  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferStartNewFrame( NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 3  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferGetUnstufData( NULL, &dataP, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 4  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferGetUnstufData( &ctx, NULL, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 5  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferGetUnstufData( &ctx, &dataP, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 6  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferGetUnstufLen( NULL, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 7  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferGetUnstufLen( &ctx, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 8  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferIsAFullFrameUnstuff( NULL, &frameIsUnstuffed ) )
    {
        (void)printf("byteUnStuffTestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 9  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferIsAFullFrameUnstuff( &ctx, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 10 -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferInsStufChunk( NULL, memArea, sizeof(memArea), &varTemp32, &a ) )
    {
        (void)printf("byteUnStuffTestBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 11 -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferInsStufChunk( &ctx, NULL, sizeof(memArea), &varTemp32, &a ) )
    {
        (void)printf("byteUnStuffTestBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 12 -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferInsStufChunk( &ctx, memArea, sizeof(memArea), NULL, &a ) )
    {
        (void)printf("byteUnStuffTestBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 13 -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferInsStufChunk( &ctx, memArea, sizeof(memArea), &varTemp32, NULL) )
    {
        (void)printf("byteUnStuffTestBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 14 -- FAIL \n");
    }
}

void byteUnStuffTestBadInit(void)
{
    /* Local variable */
    s_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint32_t a;
    uint8_t *dataP;
    bool_t frameIsUnstuffed;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DBUSTF_RES_NOINITLIB == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 1  -- FAIL \n");
    }

    if( DBUSTF_RES_NOINITLIB == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 2  -- FAIL \n");
    }

    if( DBUSTF_RES_NOINITLIB == bUStufferGetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 3  -- FAIL \n");
    }

    if( DBUSTF_RES_NOINITLIB == bUStufferIsAFullFrameUnstuff(&ctx, &frameIsUnstuffed) )
    {
        (void)printf("byteUnStuffTestBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 4  -- FAIL \n");
    }

    if( DBUSTF_RES_NOINITLIB == bUStufferInsStufChunk( &ctx, memArea, sizeof(memArea), &varTemp32, &a ) )
    {
        (void)printf("byteUnStuffTestBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 5  -- FAIL \n");
    }
}

void byteUnStuffTestBadParamEntr(void)
{
    /* Local variable */
    s_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint32_t a;

    /* Function */
    if( DBUSTF_RES_BADPARAM == bUStufferInitCtx(&ctx, memArea, 0u) )
    {
        (void)printf("byteUnStuffTestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamEntr 1  -- FAIL \n");
    }

    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamEntr 2  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPARAM == bUStufferInsStufChunk( &ctx, memArea, 0u, &varTemp32, &a ) )
    {
        (void)printf("byteUnStuffTestBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamEntr 3  -- FAIL \n");
    }
}

void byteUnStuffTestBadParamStatus(void)
{
    /* Local variable */
    s_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t *dataP;
    bool_t frameIsUnstuffed;

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 1  -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 2  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 3  -- FAIL \n");
    }

    ctx.memArea = NULL;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 4  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 5  -- FAIL \n");
    }

    ctx.memAreaCntr = ctx.memAreaSize + 1u;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 6  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 6  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 7  -- FAIL \n");
    }

    ctx.memAreaCntr = 1u;
    ctx.unStuffState = DBUSTF_SM_PRV_NEEDSOF;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 8  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 9  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 9  -- FAIL \n");
    }

    ctx.memAreaCntr = 0u;
    ctx.unStuffState = DBUSTF_SM_PRV_UNSTUFFEND;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetUnstufLen(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 10 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 10 -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 11 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 11 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 12 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 12 -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 13 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 13 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetUnstufData( &ctx, &dataP, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 14 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 14 -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 15 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 15 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferIsAFullFrameUnstuff(&ctx, &frameIsUnstuffed) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 16 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 16 -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 17 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 17 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferInsStufChunk( &ctx, memArea, 9u, &varTemp32, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 18 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 18 -- FAIL \n");
    }
}

void byteUnStuffTestOutOfMem(void)
{
    /* Local variable */
    s_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint32_t errSofRec;
    uint8_t* dataP;
    bool_t frIsUnstuf;

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 1  -- FAIL \n");
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

    if( DBUSTF_RES_OUTOFMEM == bUStufferInsStufChunk( &ctx, stuffed, 9u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestOutOfMem 2  -- FAIL \n");
        }
        else
        {
            if( 7u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 2  -- FAIL \n");
            }
            else
            {
                if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                    ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
                {
                    (void)printf("byteUnStuffTestOutOfMem 2  -- FAIL \n");
                }
                else
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                    {
                                        if( false == frIsUnstuf)
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
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 2  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestOutOfMem 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x05u;
    stuffed[6u] = 0x06u;
    stuffed[7u] = ECU_EOF;

    if( DBUSTF_RES_OUTOFMEM == bUStufferInsStufChunk( &ctx, stuffed, 7u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestOutOfMem 4  -- FAIL \n");
        }
        else
        {
            if( 6u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 4  -- FAIL \n");
            }
            else
            {
                if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                    ( 0x04u != memArea[3u] ) || ( 0x05u != memArea[4u] )  )
                {
                    (void)printf("byteUnStuffTestOutOfMem 4  -- FAIL \n");
                }
                else
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                    {
                                        if( false == frIsUnstuf)
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
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 4  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
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
    stuffed[5u] = 0x01u;
    stuffed[6u] = ECU_ESC;
    stuffed[7u] = 0x03u;
    stuffed[8u] = ECU_EOF;

    if( DBUSTF_RES_OK == bUStufferInsStufChunk( &ctx, stuffed, 3u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
        }
        else
        {
            if( 3u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
            }
            else
            {
                if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 2u == varTemp32 )
                    {
                        if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 2u == varTemp32 ) && ( memArea == dataP) )
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
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
    }

    if( DBUSTF_RES_OK == bUStufferInsStufChunk( &ctx, &stuffed[3u], 4u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
        }
        else
        {
            if( 4u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
            }
            else
            {
                if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                    ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
                {
                    (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
                }
                else
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                    {
                                        if( false == frIsUnstuf)
                                        {
                                            (void)printf("byteUnStuffTestOutOfMem 7  -- OK \n");
                                        }
                                        else
                                        {
                                            (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
                                        }
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
                    }
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
    }

    if( DBUSTF_RES_OUTOFMEM == bUStufferInsStufChunk( &ctx, &stuffed[7u], 1u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
        }
        else
        {
            if( 0u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
            }
            else
            {
                if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                    ( 0x04u != memArea[3u] ) || ( 0x01u != memArea[4u] )  )
                {
                    (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
                }
                else
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                    {
                                        if( false == frIsUnstuf)
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
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestOutOfMem 9  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x01u;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x04u;
    stuffed[5u] = 0x05u;
    stuffed[6u] = 0x06u;
    stuffed[7u] = ECU_EOF;

    if( DBUSTF_RES_OK == bUStufferInsStufChunk( &ctx, stuffed, 3u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
        }
        else
        {
            if( 3u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
            }
            else
            {
                if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 2u == varTemp32 )
                    {
                        if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 2u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
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


    if( DBUSTF_RES_OUTOFMEM == bUStufferInsStufChunk( &ctx, &stuffed[3u], 4u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
        }
        else
        {
            if( 3u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
            }
            else
            {
                if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                    ( 0x04u != memArea[3u] ) || ( 0x05u != memArea[4u] )  )
                {
                    (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
                }
                else
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                    {
                                        if( false == frIsUnstuf)
                                        {
                                            (void)printf("byteUnStuffTestOutOfMem 11 -- OK \n");
                                        }
                                        else
                                        {
                                            (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
                                        }
                                    }
                                    else
                                    {
                                        (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
                                    }
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
                    }
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 11 -- FAIL \n");
    }

}

void byteUnStuffTestFrameEnd(void)
{
    /* Local variable */
    s_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint32_t errSofRec;
    uint8_t* dataP;
    bool_t frIsUnstuf;

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
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


    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
        }
        else
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
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
                                    {
                                        if( true == frIsUnstuf)
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
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
    }


    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
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

    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, stuffed, 6u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
        }
        else
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
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 3u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 3u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
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
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
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

    if( DBUSTF_RES_OK == bUStufferInsStufChunk( &ctx, stuffed, 3u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
        }
        else
        {
            if( 3u != varTemp32 )
            {
                (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
            }
            else
            {
                if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 2u == varTemp32 )
                    {
                        if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 2u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
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
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 6  -- FAIL \n");
    }

    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, &stuffed[3u], 6u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
        }
        else
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
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 5u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
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
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
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

    if( DBUSTF_RES_OK == bUStufferInsStufChunk( &ctx, stuffed, 3u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
        }
        else
        {
            if( 3u != varTemp32 )
            {
                (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
            }
            else
            {
                if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
                    {
                        if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                            {
                                if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
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
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 9  -- FAIL \n");
    }


    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, &stuffed[3u], 3u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
        }
        else
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
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 3u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 3u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    if( DBUSTF_RES_OK == bUStufferIsAFullFrameUnstuff(&ctx, &frIsUnstuf) )
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
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 10 -- FAIL \n");
    }
}

void byteUnStuffTestGeneral(void)
{
    /* Local variable */
    s_eCU_BUStuffCtx ctx;
    uint8_t  memArea[50u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint32_t errSofRec;
    uint8_t* dataP;

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestGeneral 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 1  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_EOF;

    if( DBUSTF_RES_OK == bUStufferInsStufChunk( &ctx, stuffed, 2u, &varTemp32, &errSofRec ) )
    {
        if( 1u != errSofRec  )
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

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestGeneral 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 3  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_SOF;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = (uint8_t)(~ECU_SOF);
    stuffed[4u] = ECU_EOF;

    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, stuffed, 5u, &varTemp32, &errSofRec ) )
    {
        if( 1u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestGeneral 4  -- FAIL \n");
        }
        else
        {
            if( ( (ECU_SOF == memArea[0u]) ) && ( 5u == varTemp32 ) )
            {
                if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
                    {
                        if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                        {
                            if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                            {
                                (void)printf("byteUnStuffTestGeneral 4  -- OK \n");
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestGeneral 4  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestGeneral 4  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestGeneral 4  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestGeneral 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteUnStuffTestGeneral 4  -- FAIL \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 4  -- FAIL \n");
    }


    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestGeneral 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 5  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = 0x02u;
    stuffed[3u] = 0x02u;
    stuffed[4u] = ECU_EOF;

    if( DBUSTF_RES_OK == bUStufferInsStufChunk( &ctx, stuffed, 5u, &varTemp32, &errSofRec ) )
    {
        if( 3u != errSofRec )
        {
            (void)printf("byteUnStuffTestGeneral 6  -- FAIL \n");
        }
        else
        {
            if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                    {
                        if( ( 0u == varTemp32 ) && ( memArea == dataP) )
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
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 6  -- FAIL \n");
    }


    if( DBUSTF_RES_OK == bUStufferStartNewFrame( &ctx ) )
    {
        (void)printf("byteUnStuffTestGeneral 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 7  -- FAIL \n");
    }


}

void byteUnStuffTestCornerCase(void)
{
    /* Local variable */
    s_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint32_t errSofRec;
    uint8_t* dataP;

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
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


    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32, &errSofRec ) )
    {
        if( 1u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
        }
        else
        {
            if( 7u != varTemp32 )
            {
                (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
            }
            else
            {
                if( ( 0x02u == memArea[0u] ) && ( 0x03u == memArea[1u] ) && ( 0x04u == memArea[2u] ) &&
                    ( 0x01u == memArea[3u] ) )
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 4u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 4u == varTemp32 ) && ( memArea == dataP) )
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
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 3  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_SOF;
    stuffed[2u] = 0x01u;
    stuffed[3u] = 0x02u;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x04u;
    stuffed[6u] = ECU_EOF;


    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32, &errSofRec ) )
    {
        if( 1u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestCornerCase 4  -- FAIL \n");
        }
        else
        {
            if( 7u != varTemp32 )
            {
                (void)printf("byteUnStuffTestCornerCase 4  -- FAIL \n");
            }
            else
            {
                if( ( 0x01u == memArea[0u] ) && ( 0x02u == memArea[1u] ) && ( 0x03u == memArea[2u] ) &&
                    ( 0x04u == memArea[3u] ) )
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 4u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
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
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 4  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 5  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_EOF;
    stuffed[2u] = ECU_SOF;
    stuffed[3u] = 0x02u;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x04u;
    stuffed[6u] = ECU_EOF;


    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32, &errSofRec ) )
    {
        if( 1u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestCornerCase 6  -- FAIL \n");
        }
        else
        {
            if( 7u != varTemp32 )
            {
                (void)printf("byteUnStuffTestCornerCase 6  -- FAIL \n");
            }
            else
            {
                if( ( 0x02u == memArea[0u] ) && ( 0x03u == memArea[1u] ) && ( 0x04u == memArea[2u] ) )
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 3u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 3u == varTemp32 ) && ( memArea == dataP) )
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
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 6  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 6  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 7  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x02u;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = ECU_EOF;
    stuffed[4u] = ECU_SOF;
    stuffed[5u] = 0x02u;
    stuffed[6u] = ECU_EOF;


    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32, &errSofRec ) )
    {
        if( 1u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestCornerCase 8  -- FAIL \n");
        }
        else
        {
            if( 7u != varTemp32 )
            {
                (void)printf("byteUnStuffTestCornerCase 8  -- FAIL \n");
            }
            else
            {
                if( 0x02u == memArea[0u] )
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 1u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    (void)printf("byteUnStuffTestCornerCase 8  -- OK \n");
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestCornerCase 8  -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestCornerCase 8  -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 8  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 8  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 8  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 8  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 9  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 9  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = ECU_ESC;
    stuffed[3u] = ECU_SOF;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x02u;
    stuffed[6u] = ECU_EOF;


    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32, &errSofRec ) )
    {
        if( 1u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestCornerCase 10 -- FAIL \n");
        }
        else
        {
            if( 7u != varTemp32 )
            {
                (void)printf("byteUnStuffTestCornerCase 10 -- FAIL \n");
            }
            else
            {
                if( ( 0x03u == memArea[0u] ) && ( 0x02u == memArea[1u] ) )
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 2u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 2u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    (void)printf("byteUnStuffTestCornerCase 10 -- OK \n");
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestCornerCase 10 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestCornerCase 10 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 10 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 10 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 10 -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 10 -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferStartNewFrame(&ctx) )
    {
        (void)printf("byteUnStuffTestCornerCase 11 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 11 -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = 0x01u;
    stuffed[3u] = ECU_EOF;
    stuffed[4u] = ECU_SOF;
    stuffed[5u] = 0x03u;
    stuffed[6u] = ECU_EOF;


    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32, &errSofRec ) )
    {
        if( 2u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestCornerCase 12 -- FAIL \n");
        }
        else
        {
            if( 7u != varTemp32 )
            {
                (void)printf("byteUnStuffTestCornerCase 12 -- FAIL \n");
            }
            else
            {
                if( 0x03u == memArea[0u] )
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 1u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 1u == varTemp32 ) && ( memArea == dataP) )
                                {
                                    (void)printf("byteUnStuffTestCornerCase 12 -- OK \n");
                                }
                                else
                                {
                                    (void)printf("byteUnStuffTestCornerCase 12 -- FAIL \n");
                                }
                            }
                            else
                            {
                                (void)printf("byteUnStuffTestCornerCase 12 -- FAIL \n");
                            }
                        }
                        else
                        {
                            (void)printf("byteUnStuffTestCornerCase 12 -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("byteUnStuffTestCornerCase 12 -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("byteUnStuffTestCornerCase 12 -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 12 -- FAIL \n");
    }
}

void byteUnStuffTestCornerCase2(void)
{
    /* Local variable */
    s_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint32_t errSofRec;
    uint8_t* dataP;

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
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


    if( DBUSTF_RES_FRAMEENDED == bUStufferInsStufChunk( &ctx, stuffed, sizeof(stuffed), &varTemp32, &errSofRec ) )
    {
        if( 1u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestCornerCase2 2  -- FAIL \n");
        }
        else
        {
            if( 7u != varTemp32 )
            {
                (void)printf("byteUnStuffTestCornerCase2 2  -- FAIL \n");
            }
            else
            {
                if( ( 0x04u == memArea[0u] ) && ( 0x01u == memArea[1u] ) )
                {
                    if( DBUSTF_RES_OK == bUStufferGetUnstufLen(&ctx, &varTemp32) )
                    {
                        if( 2u == varTemp32 )
                        {
                            if( DBUSTF_RES_OK == bUStufferGetUnstufData(&ctx, &dataP, &varTemp32) )
                            {
                                if( ( 2u == varTemp32 ) && ( memArea == dataP) )
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
                else
                {
                    (void)printf("byteUnStuffTestCornerCase2 2  -- FAIL \n");
                }
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase2 2  -- FAIL \n");
    }

}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2012-Rule-10.3"
#endif
/**
 * @file eCUByteUnStufferTest.c
 *
 */
#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6", "MISRAC2004-17.4_b", "CERT-STR32-C"
    /* Suppressed for code clarity in test execution*/
#endif


/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteUnStufferTest.h"
#include "eCUByteStuffer.h"
#include <stdio.h>



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

    (void)printf("\n\nBYTE UNSTUFFER TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void byteUnStuffTestBadPointer(void)
{
    /* Local variable */
    e_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint32_t a;

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

    if( DBUSTF_RES_BADPOINTER == bUStufferReset( NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 3  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferGetNUnstuf( NULL, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 4  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferGetNUnstuf( &ctx, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 5  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferInsStufChunk( NULL, memArea, sizeof(memArea), &varTemp32, &a ) )
    {
        (void)printf("byteUnStuffTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 6  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferInsStufChunk( &ctx, NULL, sizeof(memArea), &varTemp32, &a ) )
    {
        (void)printf("byteUnStuffTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 7  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferInsStufChunk( &ctx, memArea, sizeof(memArea), NULL, &a ) )
    {
        (void)printf("byteUnStuffTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 8  -- FAIL \n");
    }

    if( DBUSTF_RES_BADPOINTER == bUStufferInsStufChunk( &ctx, memArea, sizeof(memArea), &varTemp32, NULL) )
    {
        (void)printf("byteUnStuffTestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 9  -- FAIL \n");
    }
}

void byteUnStuffTestBadInit(void)
{
    /* Local variable */
    e_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint32_t a;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DBUSTF_RES_NOINITLIB == bUStufferReset(&ctx) )
    {
        (void)printf("byteUnStuffTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 1  -- FAIL \n");
    }

    if( DBUSTF_RES_NOINITLIB == bUStufferGetNUnstuf(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 2  -- FAIL \n");
    }

    if( DBUSTF_RES_NOINITLIB == bUStufferInsStufChunk( &ctx, memArea, sizeof(memArea), &varTemp32, &a ) )
    {
        (void)printf("byteUnStuffTestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 3  -- FAIL \n");
    }
}

void byteUnStuffTestBadParamEntr(void)
{
    /* Local variable */
    e_eCU_BUStuffCtx ctx;
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
    e_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;

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
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetNUnstuf(&ctx, &varTemp32) )
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
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetNUnstuf(&ctx, &varTemp32) )
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
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetNUnstuf(&ctx, &varTemp32) )
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

    ctx.needSof = true;
    ctx.needEof = false;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetNUnstuf(&ctx, &varTemp32) )
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

    ctx.needSof = true;
    ctx.precedentWasEsc = true;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetNUnstuf(&ctx, &varTemp32) )
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

    ctx.needEof = false;
    ctx.precedentWasEsc = true;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetNUnstuf(&ctx, &varTemp32) )
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

    ctx.needSof = true;
    ctx.memAreaCntr = 1u;
    if( DBUSTF_RES_CORRUPTCTX == bUStufferGetNUnstuf(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 14 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 14 -- FAIL \n");
    }
}

void byteUnStuffTestOutOfMem(void)
{
    /* Local variable */
    e_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint32_t errSofRec;


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
            if( 6u != varTemp32 )
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
                    if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
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
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 2  -- FAIL \n");
    }


    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
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
                    if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
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
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 4  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
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
                if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                {
                    if( 2u == varTemp32 )
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
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
    }

    if( DBUSTF_RES_OUTOFMEM == bUStufferInsStufChunk( &ctx, &stuffed[3u], 4u, &varTemp32, &errSofRec ) )
    {
        if( 0u !=  errSofRec )
        {
            (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
        }
        else
        {
            if( 3u != varTemp32 )
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
                    if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
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
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestOutOfMem 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 8  -- FAIL \n");
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
            (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
        }
        else
        {
            if( 3u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
            }
            else
            {
                if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                {
                    if( 2u == varTemp32 )
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
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 9  -- FAIL \n");
    }


    if( DBUSTF_RES_OUTOFMEM == bUStufferInsStufChunk( &ctx, &stuffed[3u], 4u, &varTemp32, &errSofRec ) )
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
                if( ( 0x01u != memArea[0u] ) || ( 0x02u != memArea[1u] ) || ( 0x03u != memArea[2u] ) ||
                    ( 0x04u != memArea[3u] ) || ( 0x05u != memArea[4u] )  )
                {
                    (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
                }
                else
                {
                    if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
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
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 10 -- FAIL \n");
    }

}

void byteUnStuffTestFrameEnd(void)
{
    /* Local variable */
    e_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint32_t errSofRec;


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
                    if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
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
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 2  -- FAIL \n");
    }


    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
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
                    if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                    {
                        if( 3u == varTemp32 )
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
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 4  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
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
                if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                {
                    if( 2u == varTemp32 )
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
                    if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                    {
                        if( 5u == varTemp32 )
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
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestFrameEnd 7  -- FAIL \n");
    }

    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
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
                if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
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
                    if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                    {
                        if( 3u == varTemp32 )
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
    e_eCU_BUStuffCtx ctx;
    uint8_t  memArea[50u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint32_t errSofRec;

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
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
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
                if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
                {
                    if( 1u == varTemp32 )
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
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 4  -- FAIL \n");
    }


    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
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
            if( DBUSTF_RES_OK == bUStufferGetNUnstuf(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
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
    }
    else
    {
        (void)printf("byteUnStuffTestGeneral 6  -- FAIL \n");
    }
}

























































void byteUnStuffTestCornerCase(void)
{
    /* Local variable */
    e_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint8_t  stuffed[10u];
    uint32_t varTemp32;
    uint32_t errSofRec;


    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- FAIL \n");
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
                (void)printf("byteUnStuffTestCornerCase 2  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
    }



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
                (void)printf("byteUnStuffTestCornerCase 2  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
    }


    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- FAIL \n");
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
                (void)printf("byteUnStuffTestCornerCase 2  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
    }



    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- FAIL \n");
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
                (void)printf("byteUnStuffTestCornerCase 2  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
    }



    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- FAIL \n");
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
                (void)printf("byteUnStuffTestCornerCase 2  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
    }



    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = 0x03u;
    stuffed[2u] = 0x03u;
    stuffed[3u] = 0x03u;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x03u;
    stuffed[6u] = ECU_ESC;
    stuffed[7u] = ECU_EOF;


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
                (void)printf("byteUnStuffTestCornerCase 2  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
    }



    /* Function  */
    if( DBUSTF_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 1  -- FAIL \n");
    }

    stuffed[0u] = ECU_SOF;
    stuffed[1u] = ECU_ESC;
    stuffed[2u] = 0x03u;
    stuffed[3u] = ECU_SOF;
    stuffed[4u] = 0x03u;
    stuffed[5u] = 0x02u;
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
                (void)printf("byteUnStuffTestCornerCase 2  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestCornerCase 2  -- FAIL \n");
    }
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6", "MISRAC2004-17.4_b", "CERT-STR32-C"
#endif
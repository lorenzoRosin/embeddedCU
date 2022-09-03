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
static void byteUnStuffTestGeneral(void);


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
    byteUnStuffTestGeneral();

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
    bool_t a;
    bool_t b;

    /* Function */
    if( ECU_RES_BADPOINTER == bUStufferInitCtx(NULL, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 1  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == bUStufferInitCtx(&ctx, NULL, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 2  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == bUStufferReset( NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 3  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == bUStufferGetNUnstuf( NULL, &varTemp32 ) )
    {
        (void)printf("byteUnStuffTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 4  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == bUStufferGetNUnstuf( &ctx, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 5  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == bUStufferInsStufChunk( NULL, memArea, sizeof(memArea), &varTemp32, &a, &b ) )
    {
        (void)printf("byteUnStuffTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 6  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == bUStufferInsStufChunk( &ctx, NULL, sizeof(memArea), &varTemp32, &a, &b ) )
    {
        (void)printf("byteUnStuffTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 7  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == bUStufferInsStufChunk( &ctx, memArea, sizeof(memArea), NULL, &a, &b ) )
    {
        (void)printf("byteUnStuffTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 8  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == bUStufferInsStufChunk( &ctx, memArea, sizeof(memArea), &varTemp32, NULL, &b ) )
    {
        (void)printf("byteUnStuffTestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 9  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == bUStufferInsStufChunk( &ctx, memArea, sizeof(memArea), &varTemp32, &a, NULL ) )
    {
        (void)printf("byteUnStuffTestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 10 -- FAIL \n");
    }
}

void byteUnStuffTestBadInit(void)
{
    /* Local variable */
    e_eCU_BUStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    bool_t a;
    bool_t b;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( ECU_RES_NOINITLIB == bUStufferReset(&ctx) )
    {
        (void)printf("byteUnStuffTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 1  -- FAIL \n");
    }

    if( ECU_RES_NOINITLIB == bUStufferGetNUnstuf(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadInit 2  -- FAIL \n");
    }

    if( ECU_RES_NOINITLIB == bUStufferInsStufChunk( &ctx, memArea, sizeof(memArea), &varTemp32, &a, &b ) )
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
    bool_t a;
    bool_t b;

    /* Function */
    if( ECU_RES_BADPARAM == bUStufferInitCtx(&ctx, memArea, 0u) )
    {
        (void)printf("byteUnStuffTestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamEntr 1  -- FAIL \n");
    }

    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamEntr 2  -- FAIL \n");
    }

    if( ECU_RES_BADPARAM == bUStufferInsStufChunk( &ctx, memArea, 0u, &varTemp32, &a, &b ) )
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
    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 1  -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( ECU_RES_BADPARAM == bUStufferGetNUnstuf(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 2  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 2  -- FAIL \n");
    }

    /* Function  */
    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 3  -- FAIL \n");
    }

    ctx.memArea = NULL;
    if( ECU_RES_BADPARAM == bUStufferGetNUnstuf(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 4  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 4  -- FAIL \n");
    }

    /* Function  */
    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 5  -- FAIL \n");
    }

    ctx.memAreaCntr = ctx.memAreaSize + 1u;
    if( ECU_RES_BADPARAM == bUStufferGetNUnstuf(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 6  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 6  -- FAIL \n");
    }

    /* Function  */
    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 7  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 7  -- FAIL \n");
    }

    ctx.needSof = true;
    ctx.needEof = false;
    if( ECU_RES_BADPARAM == bUStufferGetNUnstuf(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 8  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 8  -- FAIL \n");
    }

    /* Function  */
    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 9  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 9  -- FAIL \n");
    }

    ctx.needSof = true;
    ctx.precedentWasEsc = true;
    if( ECU_RES_BADPARAM == bUStufferGetNUnstuf(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 10 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 10 -- FAIL \n");
    }

    /* Function  */
    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 11 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 11 -- FAIL \n");
    }

    ctx.needEof = false;
    ctx.precedentWasEsc = true;
    if( ECU_RES_BADPARAM == bUStufferGetNUnstuf(&ctx, &varTemp32) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 12 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 12 -- FAIL \n");
    }

    /* Function  */
    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestBadParamStatus 13 -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadParamStatus 13 -- FAIL \n");
    }

    ctx.needSof = true;
    ctx.memAreaCntr = 1u;
    if( ECU_RES_BADPARAM == bUStufferGetNUnstuf(&ctx, &varTemp32) )
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
    bool_t errSofRec;
    bool_t eofRec;


    /* Function  */
    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 1  -- FAIL \n");
    }

    stuffed[0] = ECU_SOF;
    stuffed[1] = 0x01;
    stuffed[2] = 0x02;
    stuffed[3] = 0x03;
    stuffed[4] = 0x04;
    stuffed[5] = 0x01;
    stuffed[6] = 0x02;
    stuffed[7] = 0x03;
    stuffed[8] = ECU_EOF;

    if( ECU_RES_OUTOFMEM == bUStufferInsStufChunk( &ctx, stuffed, 9u, &varTemp32, &errSofRec, &eofRec ) )
    {
        if( (true == errSofRec) || (true == eofRec) )
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
                (void)printf("byteUnStuffTestOutOfMem 2  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 2  -- FAIL \n");
    }


    /* Function  */
    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestOutOfMem 3  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 3  -- FAIL \n");
    }

    stuffed[0] = ECU_SOF;
    stuffed[1] = 0x01;
    stuffed[2] = 0x02;
    stuffed[3] = 0x03;
    stuffed[4] = 0x04;
    stuffed[5] = 0x05;
    stuffed[6] = ECU_EOF;

    if( ECU_RES_OK == bUStufferInsStufChunk( &ctx, stuffed, 7u, &varTemp32, &errSofRec, &eofRec ) )
    {
        if( (true == errSofRec) || (false == eofRec) )
        {
            (void)printf("byteUnStuffTestOutOfMem 4  -- FAIL \n");
        }
        else
        {
            if( 7u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 4  -- FAIL \n");
            }
            else
            {
                (void)printf("byteUnStuffTestOutOfMem 4  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 4  -- FAIL \n");
    }



    /* Function  */
    if( ECU_RES_OK == bUStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteUnStuffTestOutOfMem 5  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 5  -- FAIL \n");
    }

    stuffed[0] = ECU_SOF;
    stuffed[1] = 0x01;
    stuffed[2] = 0x02;
    stuffed[3] = 0x03;
    stuffed[4] = 0x04;
    stuffed[5] = 0x01;
    stuffed[6] = 0x02;
    stuffed[7] = 0x03;
    stuffed[8] = ECU_EOF;

    if( ECU_RES_OK == bUStufferInsStufChunk( &ctx, stuffed, 5u, &varTemp32, &errSofRec, &eofRec ) )
    {
        if( (true == errSofRec) || (true == eofRec) )
        {
            (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
        }
        else
        {
            if( 5u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
            }
            else
            {
                (void)printf("byteUnStuffTestOutOfMem 6  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 6  -- FAIL \n");
    }


    if( ECU_RES_OUTOFMEM == bUStufferInsStufChunk( &ctx, &stuffed[5], 4u, &varTemp32, &errSofRec, &eofRec ) )
    {
        if( (true == errSofRec) || (true == eofRec) )
        {
            (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
        }
        else
        {
            if( 1u != varTemp32 )
            {
                (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
            }
            else
            {
                (void)printf("byteUnStuffTestOutOfMem 7  -- OK \n");
            }
        }
    }
    else
    {
        (void)printf("byteUnStuffTestOutOfMem 7  -- FAIL \n");
    }

}

void byteUnStuffTestGeneral(void)
{

}


#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6", "MISRAC2004-17.4_b", "CERT-STR32-C"
#endif
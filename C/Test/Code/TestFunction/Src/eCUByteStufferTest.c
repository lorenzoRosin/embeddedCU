/**
 * @file       eCUByteStufferTest.c
 *
 * @brief      Byte stuffer test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteStufferTest.h"

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif

#include <stdio.h>

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2012-Rule-10.3", "CERT-STR32-C"
    /* Suppressed for code clarity in test execution*/
#endif

/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void byteStuffTestBadPointer(void);
static void byteStuffTestBadInit(void);
static void byteStuffTestBadIniFrame(void);
static void byteStuffTestBadParamEntr(void);
static void byteStuffTestCorrupterContext(void);
static void byteStuffTestOutOfMem(void);
static void byteStuffTestStartRestart(void);
static void byteStuffTestGetRemainings(void);
static void byteStuffTestGeneral(void);
static void byteStuffTestGeneralAnother(void);
static void byteStuffTestCorrecteness(void);

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void byteStufferTest(void)
{
	(void)printf("\n\nBYTE STUFFER TEST START \n\n");

    byteStuffTestBadPointer();
    byteStuffTestBadInit();
    byteStuffTestBadIniFrame();
    byteStuffTestBadParamEntr();
    byteStuffTestCorrupterContext();
    byteStuffTestOutOfMem();
    byteStuffTestStartRestart();
    byteStuffTestGetRemainings();
    byteStuffTestGeneral();
    byteStuffTestGeneralAnother();
    byteStuffTestCorrecteness();

    (void)printf("\n\nBYTE STUFFER TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void byteStuffTestBadPointer(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t* pointer;


    /* Function */
    if( DBSTF_RES_BADPOINTER == bStufferInitCtx(NULL, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 1  -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferInitCtx(&ctx, NULL, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 2  -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferStartNewFrame(NULL, 2u) )
    {
        (void)printf("byteStuffTestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 3  -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferGetUnStufDataLocation(NULL, &pointer, &varTemp32) )
    {
        (void)printf("byteStuffTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 4  -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferGetUnStufDataLocation(&ctx, NULL, &varTemp32) )
    {
        (void)printf("byteStuffTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 5  -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferGetUnStufDataLocation(&ctx, &pointer, NULL) )
    {
        (void)printf("byteStuffTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 6  -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferRestartCurrentFrame(NULL) )
    {
        (void)printf("byteStuffTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 7  -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferGetRemToRetrive(NULL, &varTemp32) )
    {
        (void)printf("byteStuffTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 8  -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferGetRemToRetrive(&ctx, NULL) )
    {
        (void)printf("byteStuffTestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 9  -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferRetriStufChunk(NULL, memArea, sizeof(memArea), &varTemp32 ) )
    {
        (void)printf("byteStuffTestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 10 -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferRetriStufChunk(&ctx, NULL, sizeof(memArea), &varTemp32) )
    {
        (void)printf("byteStuffTestBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 11 -- FAIL \n");
    }

    if( DBSTF_RES_BADPOINTER == bStufferRetriStufChunk(&ctx, memArea, sizeof(memArea), NULL) )
    {
        (void)printf("byteStuffTestBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadPointer 12 -- FAIL \n");
    }

}

void byteStuffTestBadInit(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t* pointer;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DBSTF_RES_NOINITLIB == bStufferStartNewFrame(&ctx, 2u) )
    {
        (void)printf("byteStuffTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadInit 1  -- FAIL \n");
    }

    if( DBSTF_RES_NOINITLIB == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        (void)printf("byteStuffTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadInit 2  -- FAIL \n");
    }

    if( DBSTF_RES_NOINITLIB == bStufferRestartCurrentFrame(&ctx) )
    {
        (void)printf("byteStuffTestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadInit 3  -- FAIL \n");
    }

    if( DBSTF_RES_NOINITLIB == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        (void)printf("byteStuffTestBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadInit 4  -- FAIL \n");
    }

    if( DBSTF_RES_NOINITLIB == bStufferRetriStufChunk(&ctx, memArea, sizeof(memArea), &varTemp32) )
    {
        (void)printf("byteStuffTestBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadInit 5  -- FAIL \n");
    }
}

void byteStuffTestBadIniFrame(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;

    /* Init variable */
    ctx.isInit = false;
    (void)memset(memArea, 0, sizeof(memArea));

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestBadIniFrame 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadIniFrame 1  -- FAIL \n");
    }

    if( DBSTF_RES_NOINITFRAME == bStufferRestartCurrentFrame(&ctx) )
    {
        (void)printf("byteStuffTestBadIniFrame 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadIniFrame 2  -- FAIL \n");
    }

    if( DBSTF_RES_NOINITFRAME == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        (void)printf("byteStuffTestBadIniFrame 3  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadIniFrame 3  -- FAIL \n");
    }

    if( DBSTF_RES_NOINITFRAME == bStufferRetriStufChunk(&ctx, memArea, sizeof(memArea), &varTemp32) )
    {
        (void)printf("byteStuffTestBadIniFrame 4  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadIniFrame 4  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, 2u) )
    {
        (void)printf("byteStuffTestBadIniFrame 5  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadIniFrame 5  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRestartCurrentFrame(&ctx) )
    {
        (void)printf("byteStuffTestBadIniFrame 6  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadIniFrame 6  -- FAIL \n");
    }
}

void byteStuffTestBadParamEntr(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;

    /* Init variable */
    ctx.isInit = false;
    (void)memset(memArea, 0, sizeof(memArea));

    /* Function */
    if( DBSTF_RES_BADPARAM == bStufferInitCtx(&ctx, memArea, 0u) )
    {
        (void)printf("byteStuffTestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadParamEntr 1  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadParamEntr 2  -- FAIL \n");
    }

    if( DBSTF_RES_BADPARAM == bStufferStartNewFrame(&ctx, 0u) )
    {
        (void)printf("byteStuffTestBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadParamEntr 3  -- FAIL \n");
    }

    if( DBSTF_RES_BADPARAM == bStufferStartNewFrame(&ctx, (sizeof(memArea) +1u) ) )
    {
        (void)printf("byteStuffTestBadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadParamEntr 4  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestBadParamEntr 5  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadParamEntr 5  -- FAIL \n");
    }

    if( DBSTF_RES_BADPARAM == bStufferRetriStufChunk(&ctx, memArea, 0u, &varTemp32) )
    {
        (void)printf("byteStuffTestBadParamEntr 6  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestBadParamEntr 6  -- FAIL \n");
    }
}

void byteStuffTestCorrupterContext(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 1  -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( DBSTF_RES_CORRUPTCTX == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 2  -- FAIL \n");
    }


    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 3  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 3  -- FAIL \n");
    }

    ctx.memArea = NULL;
    if( DBSTF_RES_CORRUPTCTX == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 4  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 4  -- FAIL \n");
    }

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 5  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 5  -- FAIL \n");
    }

    ctx.memAreaFrameSize = 2u;
    ctx.memAreaCntr = ctx.memAreaFrameSize + 1u;
    if( DBSTF_RES_CORRUPTCTX == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 6  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 6  -- FAIL \n");
    }

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 7  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 7  -- FAIL \n");
    }

    ctx.memAreaFrameSize = ctx.memAreaSize + 1u;
    if( DBSTF_RES_CORRUPTCTX == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 8  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 8  -- FAIL \n");
    }

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 9  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 9  -- FAIL \n");
    }

    ctx.memAreaFrameSize = DBSTF_SM_PRV_NEEDSOF;
    ctx.memAreaFrameSize = 2u;
    ctx.memAreaCntr = 1u;
    if( DBSTF_RES_CORRUPTCTX == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 10 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 10 -- FAIL \n");
    }

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 11 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 11 -- FAIL \n");
    }

    ctx.memAreaCntr = 0u;
    ctx.stuffState = DBSTF_SM_PRV_NEEDNEGATEPRECDATA;
    if( DBSTF_RES_CORRUPTCTX == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 12 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 12 -- FAIL \n");
    }

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 13 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 13 -- FAIL \n");
    }

    ctx.memAreaCntr = 0u;
    ctx.stuffState = DBSTF_SM_PRV_NEEDEOF;
    if( DBSTF_RES_CORRUPTCTX == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 14 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 14 -- FAIL \n");
    }

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 15 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 15 -- FAIL \n");
    }

    ctx.memAreaCntr = 0u;
    ctx.stuffState = DBSTF_SM_PRV_STUFFEND;
    if( DBSTF_RES_CORRUPTCTX == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 16 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 16 -- FAIL \n");
    }

     /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 17 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 17 -- FAIL \n");
    }

    ctx.stuffState = DBSTF_SM_PRV_STUFFEND;
    ctx.memAreaCntr = 1u;
    ctx.memAreaFrameSize = 2u;
    ctx.memAreaSize = 3u;
    if( DBSTF_RES_CORRUPTCTX == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 18 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 18 -- FAIL \n");
    }

     /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 19 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 19 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 20 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 20 -- FAIL \n");
    }

    ctx.stuffState = DBSTF_SM_PRV_NEEDNEGATEPRECDATA;
    ctx.memAreaCntr = 1u;
    memArea[ctx.memAreaCntr - 1u] = 0xFFu;
    if( DBSTF_RES_CORRUPTCTX == bStufferStartNewFrame(&ctx, 4u) )
    {
        (void)printf("byteStuffTestCorrupterContext 21 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 21 -- FAIL \n");
    }

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 22 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 22 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    if( DBSTF_RES_CORRUPTCTX == bStufferGetUnStufDataLocation(&ctx, &dataP, &varTemp32) )
    {
        (void)printf("byteStuffTestCorrupterContext 23 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 23 -- FAIL \n");
    }


    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 24 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 24 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    ctx.memAreaFrameSize = 1u;
    if( DBSTF_RES_CORRUPTCTX == bStufferRestartCurrentFrame(&ctx) )
    {
        (void)printf("byteStuffTestCorrupterContext 25 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 25 -- FAIL \n");
    }

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 26 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 26 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    ctx.memAreaFrameSize = 1u;
    if( DBSTF_RES_CORRUPTCTX == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        (void)printf("byteStuffTestCorrupterContext 27 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 27 -- FAIL \n");
    }

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrupterContext 28 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 28 -- FAIL \n");
    }

    ctx.memAreaSize = 0u;
    ctx.memAreaFrameSize = 1u;
    if( DBSTF_RES_CORRUPTCTX == bStufferRetriStufChunk(&ctx, memArea, 1u, &varTemp32) )
    {
        (void)printf("byteStuffTestCorrupterContext 29 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrupterContext 29 -- FAIL \n");
    }
}

void byteStuffTestOutOfMem(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[5u];
    uint8_t  memAreaFinalChunk[50u];
    uint32_t varTemp32;
    uint32_t reman;
    uint8_t* pointer;

    /* Init variable */
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = ECU_ESC;
    memArea[3u] = 0x12u;
    memArea[4u] = 0xFFu;

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 1  -- FAIL \n");
    }

    if( DBSTF_RES_NOINITFRAME == bStufferGetRemToRetrive(&ctx, &reman) )
    {
        (void)printf("byteStuffTestOutOfMem 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 2  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
            {
                (void)printf("byteStuffTestOutOfMem 3  -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestOutOfMem 3  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 3  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestOutOfMem 4  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 4  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &reman) )
    {
        if( 10u == reman )
        {
            (void)printf("byteStuffTestOutOfMem 5  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 5  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
            {
                (void)printf("byteStuffTestOutOfMem 6  -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestOutOfMem 6  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 6  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestOutOfMem 7  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 7  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[1], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestOutOfMem 8  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 8  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &reman) )
    {
        if( 8u == reman )
        {
            (void)printf("byteStuffTestOutOfMem 9  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 9  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
            {
                (void)printf("byteStuffTestOutOfMem 10 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestOutOfMem 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 10 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[2], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestOutOfMem 11 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 11 -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[3], 7u, &varTemp32) )
    {
        if( 7u == varTemp32 )
        {
            (void)printf("byteStuffTestOutOfMem 12 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 12 -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[10], 1u, &varTemp32) )
    {
        if( 0u == varTemp32 )
        {
            (void)printf("byteStuffTestOutOfMem 13 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 13 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &reman) )
    {
        if( 0u == reman )
        {
            (void)printf("byteStuffTestOutOfMem 14 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 14 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
            {
                (void)printf("byteStuffTestOutOfMem 15 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestOutOfMem 15 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestOutOfMem 15 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestOutOfMem 15 -- FAIL \n");
    }
}

void byteStuffTestStartRestart(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[5u];
    uint8_t  memAreaFinalChunk[50u];
    uint32_t varTemp32;
    uint32_t reman;
    uint8_t* pointer;

    /* Init variable */
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = ECU_ESC;
    memArea[3u] = 0x12u;
    memArea[4u] = 0xFFu;

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestStartRestart 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 1  -- FAIL \n");
    }

    if( DBSTF_RES_NOINITFRAME == bStufferGetRemToRetrive(&ctx, &reman) )
    {
        (void)printf("byteStuffTestStartRestart 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 2  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
            {
                (void)printf("byteStuffTestStartRestart 3  -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestStartRestart 3  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 3  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestStartRestart 4  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 4  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &reman) )
    {
        if( 10u == reman )
        {
            (void)printf("byteStuffTestStartRestart 5  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 5  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
            {
                (void)printf("byteStuffTestStartRestart 6  -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestStartRestart 6  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 6  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestStartRestart 7  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 7  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRestartCurrentFrame(&ctx) )
    {
        (void)printf("byteStuffTestStartRestart 8  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 8  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &reman) )
    {
        if( 10u == reman )
        {
            (void)printf("byteStuffTestStartRestart 9  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 9  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
            {
                (void)printf("byteStuffTestStartRestart 10 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestStartRestart 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 10 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestStartRestart 11 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 11 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[1], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestStartRestart 12 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 12 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &reman) )
    {
        if( 8u == reman )
        {
            (void)printf("byteStuffTestStartRestart 13 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 13 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
            {
                (void)printf("byteStuffTestStartRestart 14 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestStartRestart 14 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 14 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[2], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestStartRestart 15 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 15 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 15 -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[3], 7u, &varTemp32) )
    {
        if( 7u == varTemp32 )
        {
            (void)printf("byteStuffTestStartRestart 16 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 16 -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[10], 1u, &varTemp32) )
    {
        if( 0u == varTemp32 )
        {
            (void)printf("byteStuffTestStartRestart 17 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 17 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 17 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &reman) )
    {
        if( 0u == reman )
        {
            (void)printf("byteStuffTestStartRestart 18 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 18 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 18 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
            {
                (void)printf("byteStuffTestStartRestart 19 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestStartRestart 19 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestStartRestart 19 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestStartRestart 19 -- FAIL \n");
    }
}

void byteStuffTestGetRemainings(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[5u];
    uint8_t  memAreaFinalChunk[50u];
    uint32_t varTemp32;
    uint8_t* pointer;

    /* Init variable */
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = ECU_ESC;
    memArea[3u] = 0x12u;
    memArea[4u] = 0xFFu;

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGetRemainings 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 1  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGetRemainings 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 2  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 10u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 3  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 3  -- FAIL \n");
        }
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 4  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 4  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 9u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 5  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 5  -- FAIL \n");
        }
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[1], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 6  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 6  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[2], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 7  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 7  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 7u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 8  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 8  -- FAIL \n");
        }
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[3], 7u, &varTemp32) )
    {
        if( 7u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 9  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 9  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 0u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 10 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 10 -- FAIL \n");
        }
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( ( sizeof(memArea) == varTemp32 ) && ( memArea == pointer))
        {
            (void)printf("byteStuffTestGetRemainings 11 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 11 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRestartCurrentFrame(&ctx) )
    {
        (void)printf("byteStuffTestGetRemainings 12 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 12 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 10u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 13 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 3 -- FAIL \n");
        }
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 14 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 14 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 9u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 15 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 15 -- FAIL \n");
        }
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[1], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 16 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 16 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[2], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 17 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 17 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 17 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 7u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 18 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 18 -- FAIL \n");
        }
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[3], 6u, &varTemp32) )
    {
        if( 6u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 19 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 19 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 19 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 20 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 20 -- FAIL \n");
        }
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[9], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 21 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 21 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 21 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 0u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 22 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 22 -- FAIL \n");
        }
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( ( sizeof(memArea) == varTemp32 ) && ( memArea == pointer))
        {
            (void)printf("byteStuffTestGetRemainings 23 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 23 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 23 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, 1u) )
    {
        (void)printf("byteStuffTestGetRemainings 24 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGetRemainings 24 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 4u == varTemp32 )
        {
            (void)printf("byteStuffTestGetRemainings 25 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGetRemainings 25 -- FAIL \n");
        }
    }
}

void byteStuffTestGeneral(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[4u];
    uint8_t  memAreaFinalChunk[50u];
    uint8_t  memAreaExpected[9u];
    uint32_t varTemp32;
    uint32_t counter;
    uint32_t remaining;
    uint8_t* pointer;

    /* Init variable */
    memAreaExpected[0u] = ECU_SOF;
    memAreaExpected[1u] = ECU_ESC;
    memAreaExpected[2u] = (uint8_t)~ECU_SOF;
    memAreaExpected[3u] = ECU_ESC;
    memAreaExpected[4u] = (uint8_t)~ECU_EOF;
    memAreaExpected[5u] = 0x12u;
    memAreaExpected[6u] = ECU_ESC;
    memAreaExpected[7u] = (uint8_t)~ECU_ESC;
    memAreaExpected[8u] = ECU_EOF;

    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 1  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 2  -- FAIL \n");
    }

    e_eCU_dBStf_Res result = DBSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( DBSTF_RES_OK == result )
    {
        result = bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 1u, &varTemp32);
        if( ( DBSTF_RES_FRAMEENDED == result) || ( DBSTF_RES_OK == result) )
        {
            if(varTemp32 <= sizeof(memAreaFinalChunk))
            {
                counter += varTemp32;
            }
            else
            {
                result = DBSTF_RES_BADPARAM;
            }
        }
    }

    if( DBSTF_RES_FRAMEENDED == result )
    {
        (void)printf("byteStuffTestGeneral 3  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 3  -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneral 4  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 4  -- FAIL \n");
    }

    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 5  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 5  -- FAIL \n");
    }

    result = DBSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( DBSTF_RES_OK == result )
    {
        result = bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 2u, &varTemp32);
        if( ( DBSTF_RES_FRAMEENDED == result) || ( DBSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( DBSTF_RES_FRAMEENDED == result )
    {
        (void)printf("byteStuffTestGeneral 6  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 6  -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneral 7  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 7  -- FAIL \n");
    }

    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 8  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 8  -- FAIL \n");
    }

    result = DBSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( DBSTF_RES_OK == result )
    {
        result = bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 3u, &varTemp32);
        if( ( DBSTF_RES_FRAMEENDED == result) || ( DBSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( DBSTF_RES_FRAMEENDED == result )
    {
        (void)printf("byteStuffTestGeneral 9  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 9  -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneral 10 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 10 -- FAIL \n");
    }


    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 11 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 11 -- FAIL \n");
    }

    result = DBSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( DBSTF_RES_OK == result )
    {
        result = bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 4u, &varTemp32);
        if( ( DBSTF_RES_FRAMEENDED == result) || ( DBSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( DBSTF_RES_FRAMEENDED == result )
    {
        (void)printf("byteStuffTestGeneral 12 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 12 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneral 13 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 13 -- FAIL \n");
    }



    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 14 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 14 -- FAIL \n");
    }

    result = DBSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( DBSTF_RES_OK == result )
    {
        result = bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 5u, &varTemp32);
        if( ( DBSTF_RES_FRAMEENDED == result) || ( DBSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( DBSTF_RES_FRAMEENDED == result )
    {
        (void)printf("byteStuffTestGeneral 15 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 15 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneral 16 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 16 -- FAIL \n");
    }


    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 17 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 17 -- FAIL \n");
    }

    result = DBSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( DBSTF_RES_OK == result )
    {
        result = bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 6u, &varTemp32);
        if( ( DBSTF_RES_FRAMEENDED == result) || ( DBSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( DBSTF_RES_FRAMEENDED == result )
    {
        (void)printf("byteStuffTestGeneral 18 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 18 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneral 19 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 19 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 19 -- FAIL \n");
    }



    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 20 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 20 -- FAIL \n");
    }

    result = DBSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( DBSTF_RES_OK == result )
    {
        result = bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 7u, &varTemp32);
        if( ( DBSTF_RES_FRAMEENDED == result) || ( DBSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( DBSTF_RES_FRAMEENDED == result )
    {
        (void)printf("byteStuffTestGeneral 21 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 21 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneral 22 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 22 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 22 -- FAIL \n");
    }




    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 23 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 23 -- FAIL \n");
    }

    result = DBSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( DBSTF_RES_OK == result )
    {
        result = bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 8u, &varTemp32);
        if( ( DBSTF_RES_FRAMEENDED == result) || ( DBSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( DBSTF_RES_FRAMEENDED == result )
    {
        (void)printf("byteStuffTestGeneral 24 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 24 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneral 25 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 25 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 25 -- FAIL \n");
    }


    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 26 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 26 -- FAIL \n");
    }

    result = DBSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( DBSTF_RES_OK == result )
    {
        result = bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 9u, &varTemp32);
        if( ( DBSTF_RES_FRAMEENDED == result) || ( DBSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( DBSTF_RES_FRAMEENDED == result )
    {
        (void)printf("byteStuffTestGeneral 27 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 27 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneral 28 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 28 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 28 -- FAIL \n");
    }



    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 29 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 29 -- FAIL \n");
    }

    varTemp32 = 0u;
    counter = 0u;
    remaining = 0u;

    result = bStufferGetRemToRetrive(&ctx, &remaining);
    if( DBSTF_RES_OK == result )
    {
        if( 9u == remaining )
        {
            (void)printf("byteStuffTestGeneral 30 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 30 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 30 -- FAIL \n");
    }



    while( ( DBSTF_RES_OK == result ) && ( 0u != remaining ) )
    {
        result = bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 10u, &varTemp32);
        if( ( DBSTF_RES_FRAMEENDED == result) || ( DBSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }

        result = bStufferGetRemToRetrive(&ctx, &remaining);
    }

    if( DBSTF_RES_OK == result )
    {
        (void)printf("byteStuffTestGeneral 31 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 31 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneral 32 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 32 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 32 -- FAIL \n");
    }

    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_ESC;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneral 33 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 33 -- FAIL \n");
    }

    varTemp32 = 0u;
    counter = 0u;
    remaining = 0u;


    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 2u, &varTemp32) )
    {
        (void)printf("byteStuffTestGeneral 34 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 34 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &remaining) )
    {
        if( 7u == remaining )
        {
            (void)printf("byteStuffTestGeneral 35 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 35 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 35 -- FAIL \n");
    }


    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, 1u) )
    {
        (void)printf("byteStuffTestGeneral 36 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneral 36 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetUnStufDataLocation(&ctx, &pointer, &varTemp32) )
    {
        if( ( sizeof(memArea) == varTemp32 ) && ( memArea == pointer))
        {
            (void)printf("byteStuffTestGeneral 37 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneral 37 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneral 37 -- FAIL \n");
    }
}

void byteStuffTestGeneralAnother(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[4u];
    uint8_t  memAreaFinalChunk[50u];
    uint8_t  memAreaExpected[9u];
    uint32_t varTemp32;
    uint32_t counter;

    /* Init variable */
    memAreaExpected[0u] = ECU_SOF;
    memAreaExpected[1u] = ECU_ESC;
    memAreaExpected[2u] = (uint8_t)~ECU_SOF;
    memAreaExpected[3u] = ECU_ESC;
    memAreaExpected[4u] = (uint8_t)~ECU_EOF;
    memAreaExpected[5u] = 0x12u;
    memAreaExpected[6u] = ECU_ESC;
    memAreaExpected[7u] = (uint8_t)~ECU_ESC;
    memAreaExpected[8u] = ECU_EOF;

    /* Init variable */
    counter = 0u;
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneralAnother 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 1  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneralAnother 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 2  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 9u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 3  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 3  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 1u, &varTemp32) )
    {
        counter += varTemp32;
        if( 1u == varTemp32 )
        {
            if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
            {
                if( 8u == varTemp32 )
                {
                    (void)printf("byteStuffTestGeneralAnother 4  -- OK \n");
                }
                else
                {
                    (void)printf("byteStuffTestGeneralAnother 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteStuffTestGeneralAnother 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 4  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 7u, &varTemp32) )
    {
        counter += varTemp32;
        if( 7u == varTemp32 )
        {
            if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
            {
                if( 1u == varTemp32 )
                {
                    (void)printf("byteStuffTestGeneralAnother 3  -- OK \n");
                }
                else
                {
                    (void)printf("byteStuffTestGeneralAnother 3  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteStuffTestGeneralAnother 3  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 3  -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[counter], 7u, &varTemp32) )
    {
        counter += varTemp32;
        if( 1u == varTemp32 )
        {
            if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
                {
                    (void)printf("byteStuffTestGeneralAnother 4  -- OK \n");
                }
                else
                {
                    (void)printf("byteStuffTestGeneralAnother 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("byteStuffTestGeneralAnother 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 4  -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
        {
            (void)printf("byteStuffTestGeneralAnother 5  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother   -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 5  -- FAIL \n");
    }

    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;


    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneralAnother 6  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 6  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, 1u) )
    {
        (void)printf("byteStuffTestGeneralAnother 7  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 7  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 4u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 8  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 8  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ECU_SOF == memAreaFinalChunk[0u] )
            {
                (void)printf("byteStuffTestGeneralAnother 9  -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestGeneralAnother 9  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 9  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 3u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 10 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 10 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ECU_ESC == memAreaFinalChunk[0u] )
            {
                (void)printf("byteStuffTestGeneralAnother 11 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestGeneralAnother 11 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 11 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 2u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 12 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 12 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ((uint8_t)~ECU_SOF) == memAreaFinalChunk[0u] )
            {
                (void)printf("byteStuffTestGeneralAnother 13 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestGeneralAnother 13 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 13 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 14 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 14 -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ECU_EOF == memAreaFinalChunk[0u] )
            {
                (void)printf("byteStuffTestGeneralAnother 15 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestGeneralAnother 15 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 15 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 15 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 0u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 16 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 16 -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 0u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 17 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 17 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 17 -- FAIL \n");
    }

    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = 0x12u;


    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestGeneralAnother 18 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 18 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, 1u) )
    {
        (void)printf("byteStuffTestGeneralAnother 19 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 19 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 3u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 20 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 20 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 20 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ECU_SOF == memAreaFinalChunk[0u] )
            {
                (void)printf("byteStuffTestGeneralAnother 21 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestGeneralAnother 21 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 21 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 21 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 2u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 22 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 22 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 22 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( 0x12u == memAreaFinalChunk[0u] )
            {
                (void)printf("byteStuffTestGeneralAnother 23 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestGeneralAnother 23 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 23 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 23 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 24 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 24 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 24 -- FAIL \n");
    }


    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ECU_EOF == memAreaFinalChunk[0u] )
            {
                (void)printf("byteStuffTestGeneralAnother 25 -- OK \n");
            }
            else
            {
                (void)printf("byteStuffTestGeneralAnother 25 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 25 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 25 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferGetRemToRetrive(&ctx, &varTemp32) )
    {
        if( 0u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 26 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 26 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 26 -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 0u == varTemp32 )
        {
            (void)printf("byteStuffTestGeneralAnother 27 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestGeneralAnother 27 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestGeneralAnother 27 -- FAIL \n");
    }
}

void byteStuffTestCorrecteness(void)
{
    /* Local variable */
    s_eCU_BStuffCtx ctx;
    uint8_t  memArea[4u];
    uint8_t  memAreaFinalChunk[50u];
    uint8_t  memAreaExpected[9u];
    uint32_t varTemp32;

    /* Init variable */
    memAreaExpected[0u] = ECU_SOF;
    memAreaExpected[1u] = ECU_ESC;
    memAreaExpected[2u] = (uint8_t)~ECU_SOF;
    memAreaExpected[3u] = ECU_ESC;
    memAreaExpected[4u] = (uint8_t)~ECU_EOF;
    memAreaExpected[5u] = 0x12u;
    memAreaExpected[6u] = ECU_ESC;
    memAreaExpected[7u] = (uint8_t)~ECU_ESC;
    memAreaExpected[8u] = ECU_EOF;

    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrecteness 1  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 1  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrecteness 2  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 2  -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0], sizeof(memAreaFinalChunk), &varTemp32) )
    {
        if( 9u == varTemp32 )
        {
            (void)printf("byteStuffTestCorrecteness 3  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestCorrecteness 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 3  -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, 9u) )
    {
        (void)printf("byteStuffTestCorrecteness 5  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 5  -- FAIL \n");
    }

    /* Init variable */
    memAreaExpected[0u] = ECU_SOF;
    memAreaExpected[1u] = 0xFFu;
    memAreaExpected[2u] = 0xFFu;
    memAreaExpected[3u] = 0xFFu;
    memAreaExpected[4u] = 0xFFu;
    memAreaExpected[5u] = ECU_EOF;

    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = 0xFFu;
    memArea[1u] = 0xFFu;
    memArea[2u] = 0xFFu;
    memArea[3u] = 0xFFu;

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrecteness 6  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 6  -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrecteness 7  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 7  -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0], sizeof(memAreaFinalChunk), &varTemp32) )
    {
        if( 6u == varTemp32 )
        {
            (void)printf("byteStuffTestCorrecteness 8  -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestCorrecteness 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 8  -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, 6u) )
    {
        (void)printf("byteStuffTestCorrecteness 9  -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 9  -- FAIL \n");
    }

    /* Init variable */
    memAreaExpected[0u] = ECU_SOF;
    memAreaExpected[1u] = 0xFFu;
    memAreaExpected[2u] = 0xFFu;
    memAreaExpected[3u] = 0xFFu;
    memAreaExpected[4u] = ECU_ESC;
    memAreaExpected[5u] = (uint8_t)~ECU_SOF;;
    memAreaExpected[6u] = ECU_EOF;

    /* Init variable */
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = 0xFFu;
    memArea[1u] = 0xFFu;
    memArea[2u] = 0xFFu;
    memArea[3u] = ECU_SOF;

    /* Function */
    if( DBSTF_RES_OK == bStufferInitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrecteness 10 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 10 -- FAIL \n");
    }

    if( DBSTF_RES_OK == bStufferStartNewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("byteStuffTestCorrecteness 11 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 11 -- FAIL \n");
    }

    if( DBSTF_RES_FRAMEENDED == bStufferRetriStufChunk(&ctx, &memAreaFinalChunk[0], sizeof(memAreaFinalChunk), &varTemp32) )
    {
        if( 7u == varTemp32 )
        {
            (void)printf("byteStuffTestCorrecteness 12 -- OK \n");
        }
        else
        {
            (void)printf("byteStuffTestCorrecteness 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 12 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, 7u) )
    {
        (void)printf("byteStuffTestCorrecteness 13 -- OK \n");
    }
    else
    {
        (void)printf("byteStuffTestCorrecteness 13 -- FAIL \n");
    }


}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2012-Rule-10.3", "CERT-STR32-C"
#endif
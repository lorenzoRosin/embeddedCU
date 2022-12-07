/**
 * @file       eCUDataUnPackTest.c
 *
 * @brief      Data unpack test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataUnPackTest.h"

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif

#include <stdio.h>

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif




/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void dataUnPackTestBadPointer(void);
static void dataUnPackTestBadInit(void);
static void dataUnPackTestBadInitSession(void);
static void dataUnPackTestBadParamEntr(void);
static void dataUnPackTestCorruptContext(void);
static void dataUnPackTestOutOfMem(void);
static void dataUnPackTestEndianLe(void);
static void dataUnPackTestEndianBe(void);
static void dataUnPackTestCycle(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void dataUnPackTest(void)
{
	(void)printf("\n\nDATA UNPACK TEST START \n\n");

    dataUnPackTestBadPointer();
    dataUnPackTestBadInit();
    dataUnPackTestBadInitSession();
    dataUnPackTestBadParamEntr();
    dataUnPackTestCorruptContext();
    dataUnPackTestOutOfMem();
    dataUnPackTestEndianLe();
    dataUnPackTestEndianBe();
    dataUnPackTestCycle();

    (void)printf("\n\nDATA UNPACK END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void dataUnPackTestBadPointer(void)
{
    /* Local variable */
    s_eCU_DUNPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint8_t* dataP;
    uint64_t varTemp64;
    uint32_t varTemp32;
    uint16_t varTemp16;
    uint8_t  varTemp8;
    bool_t isInit;

    /* Function */
    if( DUNPK_RES_BADPOINTER == DUNPK_InitCtx(NULL, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 1  -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_InitCtx(&ctx, NULL, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 2  -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_StartNewFrame(NULL, 3u) )
    {
        (void)printf("dataUnPackTestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 3  -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_GetUPkDataLocat( NULL, &dataP, &varTemp32) )
    {
        (void)printf("dataUnPackTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 4  -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_GetUPkDataLocat( &ctx, NULL, &varTemp32) )
    {
        (void)printf("dataUnPackTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 5  -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_GetUPkDataLocat( &ctx, &dataP, NULL) )
    {
        (void)printf("dataUnPackTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 6  -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_RestartCurrentUnpack( NULL ) )
    {
        (void)printf("dataUnPackTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 7  -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_GetRemToPop( NULL, &varTemp32 ) )
    {
        (void)printf("dataUnPackTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 8  -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_GetRemToPop( &ctx, NULL ) )
    {
        (void)printf("dataUnPackTestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 9  -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_PopArray( NULL, badPointerMempool, sizeof(badPointerMempool) ) )
    {
        (void)printf("dataUnPackTestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 10 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_PopArray( &ctx, NULL, sizeof(badPointerMempool) ) )
    {
        (void)printf("dataUnPackTestBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 11 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_PopU8( NULL, &varTemp8 ) )
    {
        (void)printf("dataUnPackTestBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 12 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_PopU8( &ctx, NULL ) )
    {
        (void)printf("dataUnPackTestBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 13 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_PopU16( NULL, &varTemp16 ) )
    {
        (void)printf("dataUnPackTestBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 14 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_PopU16( &ctx, NULL ) )
    {
        (void)printf("dataUnPackTestBadPointer 15 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 15 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_PopU32( NULL, &varTemp32 ) )
    {
        (void)printf("dataUnPackTestBadPointer 16 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 16 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_PopU32( &ctx, NULL ) )
    {
        (void)printf("dataUnPackTestBadPointer 17 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 17 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_PopU64( NULL, &varTemp64 ) )
    {
        (void)printf("dataUnPackTestBadPointer 18 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 18 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_PopU64( &ctx, NULL ) )
    {
        (void)printf("dataUnPackTestBadPointer 19 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 19 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_IsInit( NULL, &isInit ) )
    {
        (void)printf("dataUnPackTestBadPointer 20 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 20 -- FAIL \n");
    }

    if( DUNPK_RES_BADPOINTER == DUNPK_IsInit( &ctx, NULL ) )
    {
        (void)printf("dataUnPackTestBadPointer 21 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadPointer 21 -- FAIL \n");
    }
}

void dataUnPackTestBadInit(void)
{
    /* Local variable */
    s_eCU_DUNPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint8_t* dataP;
    uint64_t varTemp64;
    uint32_t varTemp32;
    uint16_t varTemp16;
    uint8_t  varTemp8;
    bool_t isInit;

    /* Init variable */
    ctx.isInit = true;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    if( DUNPK_RES_NOINITLIB == DUNPK_StartNewFrame( &ctx, 1u ) )
    {
        (void)printf("dataUnPackTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 2  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITLIB == DUNPK_GetUPkDataLocat( &ctx, &dataP, &varTemp32 ) )
    {
        (void)printf("dataUnPackTestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 3  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITLIB == DUNPK_RestartCurrentUnpack( &ctx ) )
    {
        (void)printf("dataUnPackTestBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 4  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITLIB == DUNPK_GetRemToPop( &ctx, &varTemp32 ) )
    {
        (void)printf("dataUnPackTestBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 5  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITLIB == DUNPK_PopArray( &ctx, badPointerMempool, sizeof(badPointerMempool) ) )
    {
        (void)printf("dataUnPackTestBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 6  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITLIB == DUNPK_PopU8( &ctx, &varTemp8 ) )
    {
        (void)printf("dataUnPackTestBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 7  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITLIB == DUNPK_PopU16( &ctx, &varTemp16 ) )
    {
        (void)printf("dataUnPackTestBadInit 8  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 8  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITLIB == DUNPK_PopU32( &ctx, &varTemp32 ) )
    {
        (void)printf("dataUnPackTestBadInit 9  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 9  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITLIB == DUNPK_PopU64( &ctx, &varTemp64 ) )
    {
        (void)printf("dataUnPackTestBadInit 10 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_IsInit( &ctx, &isInit ) )
    {
        if( false == isInit )
        {
            (void)printf("dataUnPackTestBadInit 11 -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestBadInit 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestBadInit 11 -- FAIL \n");
    }
}

void dataUnPackTestBadInitSession(void)
{
    /* Local variable */
    s_eCU_DUNPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint64_t varTemp64;
    uint32_t varTemp32;
    uint16_t varTemp16;
    uint8_t  varTemp8;
    bool_t isInit;

    /* Init variable */
    ctx.isInit = true;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestBadInitSession 1  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInitSession 1  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITFRAME == DUNPK_RestartCurrentUnpack( &ctx  ) )
    {
        (void)printf("dataUnPackTestBadInitSession 2  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInitSession 2  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITFRAME == DUNPK_GetRemToPop( &ctx, &varTemp32  ) )
    {
        (void)printf("dataUnPackTestBadInitSession 3  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInitSession 3  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITFRAME == DUNPK_PopArray( &ctx, badPointerMempool, 2u  ) )
    {
        (void)printf("dataUnPackTestBadInitSession 4  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInitSession 4  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITFRAME == DUNPK_PopU8( &ctx, &varTemp8  ) )
    {
        (void)printf("dataUnPackTestBadInitSession 5  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInitSession 5  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITFRAME == DUNPK_PopU16( &ctx, &varTemp16  ) )
    {
        (void)printf("dataUnPackTestBadInitSession 6  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInitSession 6  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITFRAME == DUNPK_PopU32( &ctx, &varTemp32  ) )
    {
        (void)printf("dataUnPackTestBadInitSession 7  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInitSession 7  -- FAIL \n");
    }

    if( DUNPK_RES_NOINITFRAME == DUNPK_PopU64( &ctx, &varTemp64  ) )
    {
        (void)printf("dataUnPackTestBadInitSession 8  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadInitSession 8  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_IsInit( &ctx, &isInit ) )
    {
        if( true == isInit )
        {
            (void)printf("dataUnPackTestBadInitSession 9  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestBadInitSession 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestBadInitSession 9  -- FAIL \n");
    }
}

void dataUnPackTestBadParamEntr(void)
{
    /* Local variable */
    s_eCU_DUNPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];

    /* Init variable */
    ctx.isInit = false;
    (void)memset(badPointerMempool, 0, sizeof(badPointerMempool));

    /* Function */
    if( DUNPK_RES_BADPARAM == DUNPK_InitCtx(&ctx, badPointerMempool, 0u, true) )
    {
        (void)printf("dataUnPackTestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadParamEntr 1  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadParamEntr 2  -- FAIL \n");
    }

    if( DUNPK_RES_BADPARAM == DUNPK_StartNewFrame( &ctx, 0u ) )
    {
        (void)printf("dataUnPackTestBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadParamEntr 3  -- FAIL \n");
    }

    if( DUNPK_RES_BADPARAM == DUNPK_StartNewFrame( &ctx, ( sizeof(badPointerMempool) + 1u ) ) )
    {
        (void)printf("dataUnPackTestBadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadParamEntr 4  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_StartNewFrame( &ctx, 2u ) )
    {
        (void)printf("dataUnPackTestBadParamEntr 5  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadParamEntr 5  -- FAIL \n");
    }

    if( DUNPK_RES_BADPARAM == DUNPK_PopArray( &ctx, badPointerMempool, 0u ) )
    {
        (void)printf("dataUnPackTestBadParamEntr 6  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestBadParamEntr 6  -- FAIL \n");
    }
}

void dataUnPackTestCorruptContext(void)
{
    /* Local variable */
    s_eCU_DUNPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint8_t* dataP;
    uint32_t varTemp;
    uint8_t  varTemp8;
    uint16_t varTemp16;
    uint32_t varTemp32;
    uint64_t varTemp64;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 1  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKASize = 0u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_StartNewFrame(&ctx, 4u) )
    {
        (void)printf("dataUnPackTestCorruptContext 2  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 2  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 3  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 3  -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKA = NULL;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_StartNewFrame(&ctx, 4u) )
    {
        (void)printf("dataUnPackTestCorruptContext 4  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 4  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 5  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 5  -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKAFrameSize = ctx.memUPKASize + 1u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_StartNewFrame(&ctx, 4u) )
    {
        (void)printf("dataUnPackTestCorruptContext 6  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 6  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 7  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 7  -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKAFrameSize = ctx.memUPKASize - 2u;
    ctx.memUPKACntr = ctx.memUPKAFrameSize + 1u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_StartNewFrame(&ctx, 4u) )
    {
        (void)printf("dataUnPackTestCorruptContext 8  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 8  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 9  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 9  -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKAFrameSize = 1u;
    ctx.memUPKASize = 0u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_GetUPkDataLocat( &ctx, &dataP, &varTemp32 ) )
    {
        (void)printf("dataUnPackTestCorruptContext 10 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 10 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 11 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 11 -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKAFrameSize = 1u;
    ctx.memUPKASize = 0u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_RestartCurrentUnpack(&ctx) )
    {
        (void)printf("dataUnPackTestCorruptContext 12 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 12 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 13 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 13 -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKAFrameSize = 1u;
    ctx.memUPKASize = 0u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_GetRemToPop(&ctx, &varTemp) )
    {
        (void)printf("dataUnPackTestCorruptContext 14 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 14 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 15 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 15 -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKAFrameSize = 1u;
    ctx.memUPKASize = 0u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_PopArray(&ctx, badPointerMempool, 1u) )
    {
        (void)printf("dataUnPackTestCorruptContext 16 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 16 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 17 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 17 -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKAFrameSize = 1u;
    ctx.memUPKASize = 0u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_PopU8(&ctx, &varTemp8) )
    {
        (void)printf("dataUnPackTestCorruptContext 18 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 18 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 19 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 19 -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKAFrameSize = 1u;
    ctx.memUPKASize = 0u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_PopU16(&ctx, &varTemp16) )
    {
        (void)printf("dataUnPackTestCorruptContext 20 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 20 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 21 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 21 -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKAFrameSize = 1u;
    ctx.memUPKASize = 0u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_PopU32(&ctx, &varTemp32) )
    {
        (void)printf("dataUnPackTestCorruptContext 22 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 22 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCorruptContext 23 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 23 -- FAIL \n");
    }

    /* Init variable */
    ctx.memUPKAFrameSize = 1u;
    ctx.memUPKASize = 0u;

    if( DUNPK_RES_CORRUPTCTX == DUNPK_PopU64(&ctx, &varTemp64) )
    {
        (void)printf("dataUnPackTestCorruptContext 24 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCorruptContext 24 -- FAIL \n");
    }
}

void dataUnPackTestOutOfMem(void)
{
    /* Local variable */
    s_eCU_DUNPK_Ctx ctx;
    uint8_t  badPointerMempool[9u];
    uint8_t  pushPool[5u];
    uint64_t varTemp64;
    uint32_t varTemp32;
    uint16_t varTemp16;
    uint8_t  varTemp8;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;
    (void)memset(badPointerMempool, 0, sizeof(badPointerMempool));

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 1  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 9u) )
    {
        (void)printf("dataUnPackTestOutOfMem 2  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 2  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_GetUPkDataLocat(&ctx, &dataP, &varTemp32) )
    {
        if( ( badPointerMempool == dataP ) && ( sizeof(badPointerMempool) == varTemp32 ) )
        {
            (void)printf("dataUnPackTestOutOfMem 3  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestOutOfMem 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 3  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_GetRemToPop(&ctx, &varTemp32) )
    {
        if( sizeof(badPointerMempool) == varTemp32 )
        {
            (void)printf("dataUnPackTestOutOfMem 4  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestOutOfMem 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 4  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU64( &ctx, &varTemp64 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 5  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 5  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_GetUPkDataLocat(&ctx, &dataP, &varTemp32) )
    {
        if( ( badPointerMempool == dataP ) && ( sizeof(badPointerMempool) == varTemp32 ) )
        {
            (void)printf("dataUnPackTestOutOfMem 6  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestOutOfMem 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 6  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_GetRemToPop(&ctx, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("dataUnPackTestOutOfMem 7  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestOutOfMem 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 7  -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == DUNPK_PopU64( &ctx, &varTemp64 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 8  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 8  -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 7u) )
    {
        (void)printf("dataUnPackTestOutOfMem 9  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 9  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_GetUPkDataLocat(&ctx, &dataP, &varTemp32) )
    {
        if( ( badPointerMempool == dataP ) && ( sizeof(badPointerMempool) == varTemp32 ) )
        {
            (void)printf("dataUnPackTestOutOfMem 10 -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestOutOfMem 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_GetRemToPop(&ctx, &varTemp32) )
    {
        if( 7u == varTemp32 )
        {
            (void)printf("dataUnPackTestOutOfMem 11 -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestOutOfMem 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 11 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == DUNPK_PopU64( &ctx, &varTemp64 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 12 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 12 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_GetUPkDataLocat(&ctx, &dataP, &varTemp32) )
    {
        if( ( badPointerMempool == dataP ) && ( sizeof(badPointerMempool) == varTemp32 ) )
        {
            (void)printf("dataUnPackTestOutOfMem 13 -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestOutOfMem 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 13 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_GetRemToPop(&ctx, &varTemp32) )
    {
        if( 7u == varTemp32 )
        {
            (void)printf("dataUnPackTestOutOfMem 14 -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestOutOfMem 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 14 -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 5u) )
    {
        (void)printf("dataUnPackTestOutOfMem 15 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 15 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU32( &ctx, &varTemp32 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 16 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 16 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == DUNPK_PopU32( &ctx, &varTemp32 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 17 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 17 -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 3u) )
    {
        (void)printf("dataUnPackTestOutOfMem 18 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 18 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == DUNPK_PopU32( &ctx, &varTemp32 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 19 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 19 -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 3u) )
    {
        (void)printf("dataUnPackTestOutOfMem 20 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 20 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU16( &ctx, &varTemp16 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 21 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 21 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == DUNPK_PopU16( &ctx, &varTemp16 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 22 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 22 -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 1u) )
    {
        (void)printf("dataUnPackTestOutOfMem 23 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 23 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == DUNPK_PopU16( &ctx, &varTemp16 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 24 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 24 -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 1u) )
    {
        (void)printf("dataUnPackTestOutOfMem 25 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 25 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU8( &ctx, &varTemp8 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 26 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 26 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == DUNPK_PopU8( &ctx, &varTemp8 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 27 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 27 -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 6u) )
    {
        (void)printf("dataUnPackTestOutOfMem 28 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 28 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopArray( &ctx, pushPool, 5u ) )
    {
        (void)printf("dataUnPackTestOutOfMem 29 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 29 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == DUNPK_PopArray( &ctx, pushPool, 5u ) )
    {
        (void)printf("dataUnPackTestOutOfMem 30 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 30 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU8( &ctx, &varTemp8 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 31 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 31 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == DUNPK_PopU8( &ctx, &varTemp8 ) )
    {
        (void)printf("dataUnPackTestOutOfMem 32 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 32 -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 1u) )
    {
        (void)printf("dataUnPackTestOutOfMem 33 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 33 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == DUNPK_PopArray( &ctx, pushPool, 2u ) )
    {
        (void)printf("dataUnPackTestOutOfMem 34 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestOutOfMem 34 -- FAIL \n");
    }
}

void dataUnPackTestEndianLe(void)
{
    /* Local variable */
    s_eCU_DUNPK_Ctx ctx;
    uint8_t  badPointerMempool[20u];
    uint8_t  pushPool[20u];
    uint32_t remtoPop;
    uint8_t* dataP;
    uint64_t varTemp64;
    uint32_t varTemp32;
    uint16_t varTemp16;
    uint8_t  varTemp8;

    /* Init variable */
    ctx.isInit = false;
    (void)memset(badPointerMempool, 0, sizeof(badPointerMempool));

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestEndianLe 1  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 1  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x12u;
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 1u) )
    {
        (void)printf("dataUnPackTestEndianLe 2  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 2  -- FAIL \n");
    }

    badPointerMempool[0u] = 0xF1u;
    if( DUNPK_RES_OK == DUNPK_PopArray( &ctx, pushPool, 1u ) )
    {
        if( 0xF1u == pushPool[0u] )
        {
            (void)printf("dataUnPackTestEndianLe 3  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestEndianLe 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 3  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x12u;
    if( DUNPK_RES_OK == DUNPK_RestartCurrentUnpack( &ctx  ) )
    {
        (void)printf("dataUnPackTestEndianLe 4  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 4  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU8( &ctx, &varTemp8 ) )
    {
        if( 0x12u == varTemp8 )
        {
            (void)printf("dataUnPackTestEndianLe 5  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestEndianLe 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 5  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x34u;
    badPointerMempool[1u] = 0x12u;
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 4u) )
    {
        (void)printf("dataUnPackTestEndianLe 6  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 6  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU16( &ctx, &varTemp16 ) )
    {
        if( 0x1234u == varTemp16 )
        {
            (void)printf("dataUnPackTestEndianLe 7  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestEndianLe 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 7  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x78u;
    badPointerMempool[1u] = 0x56u;
    badPointerMempool[2u] = 0x34u;
    badPointerMempool[3u] = 0x12u;
    if( DUNPK_RES_OK == DUNPK_RestartCurrentUnpack( &ctx ) )
    {
        (void)printf("dataUnPackTestEndianLe 8  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 8  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU32( &ctx, &varTemp32 ) )
    {
        if( 0x12345678u == varTemp32 )
        {
            (void)printf("dataUnPackTestEndianLe 9  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestEndianLe 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 9  -- FAIL \n");
    }

    badPointerMempool[0u] = 0xF0u;
    badPointerMempool[1u] = 0xDEu;
    badPointerMempool[2u] = 0xBCu;
    badPointerMempool[3u] = 0x9Au;
    badPointerMempool[4u] = 0x78u;
    badPointerMempool[5u] = 0x56u;
    badPointerMempool[6u] = 0x34u;
    badPointerMempool[7u] = 0x12u;
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 8u) )
    {
        (void)printf("dataUnPackTestEndianLe 10 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_GetRemToPop(&ctx, &remtoPop) )
    {
        if( 0x08u == remtoPop )
        {
            if( DUNPK_RES_OK == DUNPK_GetUPkDataLocat(&ctx, &dataP, &remtoPop) )
            {
                if( ( sizeof(badPointerMempool) == remtoPop ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("dataUnPackTestEndianLe 11 -- OK \n");
                }
                else
                {
                    (void)printf("dataUnPackTestEndianLe 11 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataUnPackTestEndianLe 11 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataUnPackTestEndianLe 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 11 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU64( &ctx, &varTemp64 ) )
    {
        if( 0x123456789ABCDEF0UL == varTemp64 )
        {
            (void)printf("dataUnPackTestEndianLe 12 -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestEndianLe 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianLe 12 -- FAIL \n");
    }
}

void dataUnPackTestEndianBe(void)
{
    /* Local variable */
    s_eCU_DUNPK_Ctx ctx;
    uint8_t  badPointerMempool[20u];
    uint8_t  pushPool[20u];
    uint32_t remtoPop;
    uint8_t* dataP;
    uint64_t varTemp64;
    uint32_t varTemp32;
    uint16_t varTemp16;
    uint8_t  varTemp8;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), false) )
    {
        (void)printf("dataUnPackTestEndianBe 1  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 1  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x12u;
    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 20u) )
    {
        (void)printf("dataUnPackTestEndianBe 2  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 2  -- FAIL \n");
    }

    badPointerMempool[0u] = 0xF1u;
    if( DUNPK_RES_OK == DUNPK_PopArray( &ctx, pushPool, 1u ) )
    {
        if( 0xF1u == pushPool[0u] )
        {
            (void)printf("dataUnPackTestEndianBe 3  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestEndianBe 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 3  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x12u;
    if( DUNPK_RES_OK == DUNPK_RestartCurrentUnpack( &ctx ) )
    {
        (void)printf("dataUnPackTestEndianBe 4  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 4  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU8( &ctx, &varTemp8 ) )
    {
        if( 0x12u == varTemp8 )
        {
            (void)printf("dataUnPackTestEndianBe 5  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestEndianBe 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 5  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x12u;
    badPointerMempool[1u] = 0x34u;
    if( DUNPK_RES_OK == DUNPK_RestartCurrentUnpack( &ctx ) )
    {
        (void)printf("dataUnPackTestEndianBe 6  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 6  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU16( &ctx, &varTemp16 ) )
    {
        if( 0x1234u == varTemp16 )
        {
            (void)printf("dataUnPackTestEndianBe 7  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestEndianBe 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 7  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x12u;
    badPointerMempool[1u] = 0x34u;
    badPointerMempool[2u] = 0x56u;
    badPointerMempool[3u] = 0x78u;
    if( DUNPK_RES_OK == DUNPK_RestartCurrentUnpack( &ctx ) )
    {
        (void)printf("dataUnPackTestEndianBe 8  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 8  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU32( &ctx, &varTemp32 ) )
    {
        if( 0x12345678u == varTemp32 )
        {
            (void)printf("dataUnPackTestEndianBe 9  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestEndianBe 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 9  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x12u;
    badPointerMempool[1u] = 0x34u;
    badPointerMempool[2u] = 0x56u;
    badPointerMempool[3u] = 0x78u;
    badPointerMempool[4u] = 0x9Au;
    badPointerMempool[5u] = 0xBCu;
    badPointerMempool[6u] = 0xDEu;
    badPointerMempool[7u] = 0xF0u;

    if( DUNPK_RES_OK == DUNPK_RestartCurrentUnpack( &ctx ) )
    {
        (void)printf("dataUnPackTestEndianBe 10 -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_GetRemToPop(&ctx, &remtoPop) )
    {
        if( 0x14u == remtoPop )
        {
            if( DUNPK_RES_OK == DUNPK_GetUPkDataLocat(&ctx, &dataP, &remtoPop) )
            {
                if( ( 0x14u == remtoPop ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("dataUnPackTestEndianBe 11 -- OK \n");
                }
                else
                {
                    (void)printf("dataUnPackTestEndianBe 11 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataUnPackTestEndianBe 11 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataUnPackTestEndianBe 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 11 -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU64( &ctx, &varTemp64 ) )
    {
        if( 0x123456789ABCDEF0UL == varTemp64 )
        {
            (void)printf("dataUnPackTestEndianBe 12 -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestEndianBe 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestEndianBe 12 -- FAIL \n");
    }
}

void dataUnPackTestCycle(void)
{
    /* Local variable */
    s_eCU_DUNPK_Ctx ctx;
    uint8_t  badPointerMempool[20u];
    uint16_t varTemp16;
    uint32_t remtoPop;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DUNPK_RES_OK == DUNPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataUnPackTestCycle 1  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCycle 1  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_StartNewFrame(&ctx, 20u) )
    {
        (void)printf("dataUnPackTestCycle 2  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCycle 2  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x78u;
    badPointerMempool[1u] = 0x56u;
    badPointerMempool[2u] = 0x34u;
    badPointerMempool[3u] = 0x12u;
    if( DUNPK_RES_OK == DUNPK_RestartCurrentUnpack( &ctx ) )
    {
        (void)printf("dataUnPackTestCycle 3  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCycle 3  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU16( &ctx, &varTemp16 ) )
    {
        if( 0x5678u == varTemp16 )
        {
            if( DUNPK_RES_OK == DUNPK_GetRemToPop(&ctx, &remtoPop) )
            {
                if( 0x12u == remtoPop )
                {
                    if( DUNPK_RES_OK == DUNPK_GetUPkDataLocat(&ctx, &dataP, &remtoPop) )
                    {
                        if( ( sizeof(badPointerMempool) == remtoPop ) && ( badPointerMempool == dataP ) )
                        {
                            (void)printf("dataUnPackTestCycle 4  -- OK \n");
                        }
                        else
                        {
                            (void)printf("dataUnPackTestCycle 4  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("dataUnPackTestCycle 4  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("dataUnPackTestCycle 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataUnPackTestCycle 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataUnPackTestCycle 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestCycle 4  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU16( &ctx, &varTemp16 ) )
    {
        if( 0x1234u == varTemp16 )
        {
            (void)printf("dataUnPackTestCycle 5  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestCycle 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestCycle 5  -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == DUNPK_RestartCurrentUnpack( &ctx ) )
    {
        (void)printf("dataUnPackTestCycle 6  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCycle 6  -- FAIL \n");
    }

    badPointerMempool[0u] = 0x78u;
    badPointerMempool[1u] = 0x56u;
    badPointerMempool[2u] = 0x34u;
    badPointerMempool[3u] = 0x12u;
    if( DUNPK_RES_OK == DUNPK_RestartCurrentUnpack( &ctx ) )
    {
        (void)printf("dataUnPackTestCycle 7  -- OK \n");
    }
    else
    {
        (void)printf("dataUnPackTestCycle 7  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU16( &ctx, &varTemp16 ) )
    {
        if( 0x5678u == varTemp16 )
        {
            (void)printf("dataUnPackTestCycle 8  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestCycle 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestCycle 8  -- FAIL \n");
    }

    if( DUNPK_RES_OK == DUNPK_PopU16( &ctx, &varTemp16 ) )
    {
        if( 0x1234u == varTemp16 )
        {
            (void)printf("dataUnPackTestCycle 9  -- OK \n");
        }
        else
        {
            (void)printf("dataUnPackTestCycle 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataUnPackTestCycle 9  -- FAIL \n");
    }
}


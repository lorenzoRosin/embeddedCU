/**
 * @file       eCUDataPackTest.c
 *
 * @brief      Data pack test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataPackTest.h"

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
static void dataPackTestBadPointer(void);
static void dataPackTestBadInit(void);
static void dataPackTestBadParamEntr(void);
static void dataPackTestCorruptContext(void);
static void dataPackTestOutOfMem(void);
static void dataPackTestEndianLe(void);
static void dataPackTestEndianBe(void);
static void dataPackTestCycle(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void dataPackTest(void)
{
	(void)printf("\n\nDATA PACK TEST START \n\n");

    dataPackTestBadPointer();
    dataPackTestBadInit();
    dataPackTestBadParamEntr();
    dataPackTestCorruptContext();
    dataPackTestOutOfMem();
    dataPackTestEndianLe();
    dataPackTestEndianBe();
    dataPackTestCycle();

    (void)printf("\n\nDATA PACK END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void dataPackTestBadPointer(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;
    uint8_t* dataP;
    bool_t isInit;

    /* Function */
    if( DPK_RES_BADPOINTER == DPK_InitCtx(NULL, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 1  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_InitCtx(&ctx, NULL, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 2  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_StartNewPack( NULL ) )
    {
        (void)printf("dataPackTestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 3  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_GetDataReference( NULL, &dataP, &varTemp ) )
    {
        (void)printf("dataPackTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 4  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_GetDataReference( &ctx, NULL, &varTemp ) )
    {
        (void)printf("dataPackTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 5  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_GetDataReference( &ctx, &dataP, NULL ) )
    {
        (void)printf("dataPackTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 6  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_GetNPushed( NULL, &varTemp ) )
    {
        (void)printf("dataPackTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 7  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_GetNPushed( &ctx, NULL ) )
    {
        (void)printf("dataPackTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 8  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_PushArray( NULL, badPointerMempool, sizeof(badPointerMempool) ) )
    {
        (void)printf("dataPackTestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 9  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_PushArray( &ctx, NULL, sizeof(badPointerMempool) ) )
    {
        (void)printf("dataPackTestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 10 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_PushU8( NULL, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 11 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_PushU16( NULL, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 12 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_PushU32( NULL, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 13 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_PushU64( NULL, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 14 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_IsInit( NULL, &isInit ) )
    {
        (void)printf("dataPackTestBadPointer 15 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 15 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == DPK_IsInit( &ctx, NULL ) )
    {
        (void)printf("dataPackTestBadPointer 16 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 16 -- FAIL \n");
    }
}

void dataPackTestBadInit(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    if( DPK_RES_NOINITLIB == DPK_StartNewPack( &ctx ) )
    {
        (void)printf("dataPackTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 2  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
    {
        (void)printf("dataPackTestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 3  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("dataPackTestBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 4  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == DPK_PushArray( &ctx, badPointerMempool, sizeof(badPointerMempool) ) )
    {
        (void)printf("dataPackTestBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 5  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == DPK_PushU8( &ctx, 10u ) )
    {
        (void)printf("dataPackTestBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 6  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == DPK_PushU16( &ctx, 10u ) )
    {
        (void)printf("dataPackTestBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 7  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == DPK_PushU32( &ctx, 10u ) )
    {
        (void)printf("dataPackTestBadInit 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 8  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == DPK_PushU64( &ctx, 10u ) )
    {
        (void)printf("dataPackTestBadInit 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 9  -- FAIL \n");
    }
}

void dataPackTestBadParamEntr(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_BADPARAM == DPK_InitCtx(&ctx, badPointerMempool, 0u, true) )
    {
        (void)printf("dataPackTestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamEntr 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_BADPARAM == DPK_InitCtx(&ctx, badPointerMempool, 0u, false) )
    {
        (void)printf("dataPackTestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamEntr 2  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = true;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamEntr 3  -- FAIL \n");
    }

    if( DPK_RES_BADPARAM == DPK_PushArray( &ctx, badPointerMempool, 0u ) )
    {
        (void)printf("dataPackTestBadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamEntr 4  -- FAIL \n");
    }
}

void dataPackTestCorruptContext(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCorruptContext 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == DPK_GetNPushed(&ctx, &varTemp) )
    {
        (void)printf("dataPackTestCorruptContext 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 2  -- FAIL \n");
    }



    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCorruptContext 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 3  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKA = NULL;

    if( DPK_RES_CORRUPTCTX == DPK_GetNPushed(&ctx, &varTemp) )
    {
        (void)printf("dataPackTestCorruptContext 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 4  -- FAIL \n");
    }



    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCorruptContext 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 5  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKACntr = ctx.memPKASize + 1u;

    if( DPK_RES_CORRUPTCTX == DPK_GetNPushed(&ctx, &varTemp) )
    {
        (void)printf("dataPackTestCorruptContext 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 6  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCorruptContext 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 7  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == DPK_StartNewPack( &ctx ) )
    {
        (void)printf("dataPackTestCorruptContext 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 8  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCorruptContext 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 9  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
    {
        (void)printf("dataPackTestCorruptContext 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 10 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCorruptContext 11 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 11 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == DPK_PushArray(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("dataPackTestCorruptContext 12 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 12 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCorruptContext 13 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 13 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == DPK_PushU8(&ctx, 10u) )
    {
        (void)printf("dataPackTestCorruptContext 14 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 14 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCorruptContext 15 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 15 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == DPK_PushU16(&ctx, 10u) )
    {
        (void)printf("dataPackTestCorruptContext 16 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 16 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCorruptContext 17 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 17 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == DPK_PushU32(&ctx, 10u) )
    {
        (void)printf("dataPackTestCorruptContext 18 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 18 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCorruptContext 19 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 19 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == DPK_PushU64(&ctx, 10u) )
    {
        (void)printf("dataPackTestCorruptContext 20 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCorruptContext 20 -- FAIL \n");
    }
}

void dataPackTestOutOfMem(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[9u];
    uint8_t  arrayTest[5u];

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 1  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU64( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 2  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == DPK_PushU64( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 3  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, 7u, true) )
    {
        (void)printf("dataPackTestOutOfMem 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 4  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == DPK_PushU64( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 5  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, 5u, true) )
    {
        (void)printf("dataPackTestOutOfMem 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 6  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU32( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 7  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == DPK_PushU32( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 8  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, 3u, true) )
    {
        (void)printf("dataPackTestOutOfMem 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 9  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == DPK_PushU32( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 10 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, 3u, true) )
    {
        (void)printf("dataPackTestOutOfMem 11 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 11 -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU16( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 12 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 12 -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == DPK_PushU16( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 13 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 13 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, 1u, true) )
    {
        (void)printf("dataPackTestOutOfMem 14 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 14 -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == DPK_PushU16( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 15 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 15 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, 1u, true) )
    {
        (void)printf("dataPackTestOutOfMem 16 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 16 -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU8( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 17 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 17 -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == DPK_PushU8( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 18 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 18 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestOutOfMem 19 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 19 -- FAIL \n");
    }

    (void)memset(arrayTest, 0, sizeof(arrayTest));
    if( DPK_RES_OK == DPK_PushArray( &ctx, arrayTest, sizeof(arrayTest) ) )
    {
        (void)printf("dataPackTestOutOfMem 20 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 20 -- FAIL \n");
    }

    (void)memset(arrayTest, 0, sizeof(arrayTest));
    if( DPK_RES_OUTOFMEM == DPK_PushArray( &ctx, arrayTest, sizeof(arrayTest) ) )
    {
        (void)printf("dataPackTestOutOfMem 21 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 21 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, 4u, true) )
    {
        (void)printf("dataPackTestOutOfMem 22 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 22 -- FAIL \n");
    }

    (void)memset(arrayTest, 0, sizeof(arrayTest));
    if( DPK_RES_OUTOFMEM == DPK_PushArray( &ctx, arrayTest, sizeof(arrayTest) ) )
    {
        (void)printf("dataPackTestOutOfMem 23 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 23 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestOutOfMem 24 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 24 -- FAIL \n");
    }

    (void)memset(arrayTest, 0, sizeof(arrayTest));
    if( DPK_RES_OK == DPK_PushArray( &ctx, arrayTest, sizeof(arrayTest) ) )
    {
        (void)printf("dataPackTestOutOfMem 25 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 25 -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU8( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 26 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 26 -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU16( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 27 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 27 -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == DPK_PushU32( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 28 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 28 -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == DPK_PushU64( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 29 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 29 -- FAIL \n");
    }
}

void dataPackTestEndianLe(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[20u];
    uint32_t varTemp;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestEndianLe 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianLe 1  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU16( &ctx, 0x1234u ) )
    {
        (void)printf("dataPackTestEndianLe 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianLe 2  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("dataPackTestEndianLe 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianLe 3  -- FAIL \n");
    }

    if( 0x02u == varTemp)
    {
        if( ( 0x34u == badPointerMempool[0u] ) && ( 0x12u == badPointerMempool[1u] ) )
        {
            if( DPK_RES_OK == DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x02u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("dataPackTestEndianLe 4  -- OK \n");
                }
                else
                {
                    (void)printf("dataPackTestEndianLe 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataPackTestEndianLe 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataPackTestEndianLe 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackTestEndianLe 4  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_StartNewPack( &ctx ) )
    {
        (void)printf("dataPackTestEndianLe 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianLe 5  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU32( &ctx, 0x12345678u ) )
    {
        (void)printf("dataPackTestEndianLe 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianLe 6  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("dataPackTestEndianLe 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianLe 7  -- FAIL \n");
    }

    if( 0x04u == varTemp)
    {
        if( ( 0x78u == badPointerMempool[0u] ) && ( 0x56u == badPointerMempool[1u] ) &&
            ( 0x34u == badPointerMempool[2u] ) && ( 0x12u == badPointerMempool[3u] ) )
        {
            if( DPK_RES_OK == DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x04u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("dataPackTestEndianLe 8  -- OK \n");
                }
                else
                {
                    (void)printf("dataPackTestEndianLe 8  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataPackTestEndianLe 8  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataPackTestEndianLe 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackTestEndianLe 8  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_StartNewPack( &ctx ) )
    {
        (void)printf("dataPackTestEndianLe 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianLe 9  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU64( &ctx, 0x123456789ABCDEF0u ) )
    {
        (void)printf("dataPackTestEndianLe 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianLe 10 -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("dataPackTestEndianLe 11 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianLe 11 -- FAIL \n");
    }

    if( 0x08u == varTemp)
    {
        if( ( 0xF0u == badPointerMempool[0u] ) && ( 0xDEu == badPointerMempool[1u] ) &&
            ( 0xBCu == badPointerMempool[2u] ) && ( 0x9Au == badPointerMempool[3u] ) &&
            ( 0x78u == badPointerMempool[4u] ) && ( 0x56u == badPointerMempool[5u] ) &&
            ( 0x34u == badPointerMempool[6u] ) && ( 0x12u == badPointerMempool[7u] ))
        {
            if( DPK_RES_OK == DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x08u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("dataPackTestEndianLe 12 -- OK \n");
                }
                else
                {
                    (void)printf("dataPackTestEndianLe 12 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataPackTestEndianLe 12 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataPackTestEndianLe 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackTestEndianLe 12 -- FAIL \n");
    }
}

void dataPackTestEndianBe(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[20u];
    uint32_t varTemp;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), false) )
    {
        (void)printf("dataPackTestEndianBe 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianBe 1  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU16( &ctx, 0x1234u ) )
    {
        (void)printf("dataPackTestEndianBe 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianBe 2  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("dataPackTestEndianBe 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianBe 3  -- FAIL \n");
    }

    if( 0x02u == varTemp)
    {
        if( ( 0x12u == badPointerMempool[0u] ) && ( 0x34u == badPointerMempool[1u] ) )
        {
            if( DPK_RES_OK == DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x02u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("dataPackTestEndianBe 4  -- OK \n");
                }
                else
                {
                    (void)printf("dataPackTestEndianBe 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataPackTestEndianBe 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataPackTestEndianBe 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackTestEndianBe 4  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_StartNewPack( &ctx ) )
    {
        (void)printf("dataPackTestEndianBe 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianBe 5  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU32( &ctx, 0x12345678u ) )
    {
        (void)printf("dataPackTestEndianBe 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianBe 6  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("dataPackTestEndianBe 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianBe 7  -- FAIL \n");
    }

    if( 0x04u == varTemp)
    {
        if( ( 0x12u == badPointerMempool[0u] ) && ( 0x34u == badPointerMempool[1u] ) &&
            ( 0x56u == badPointerMempool[2u] ) && ( 0x78u == badPointerMempool[3u] ) )
        {
            if( DPK_RES_OK == DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x04u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("dataPackTestEndianBe 8  -- OK \n");
                }
                else
                {
                    (void)printf("dataPackTestEndianBe 8  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataPackTestEndianBe 8  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataPackTestEndianBe 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackTestEndianBe 8  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_StartNewPack( &ctx ) )
    {
        (void)printf("dataPackTestEndianBe 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianBe 9  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU64( &ctx, 0x123456789ABCDEF0u ) )
    {
        (void)printf("dataPackTestEndianBe 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianBe 10 -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("dataPackTestEndianBe 11 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestEndianBe 11 -- FAIL \n");
    }

    if( 0x08u == varTemp)
    {
        if( ( 0x12u == badPointerMempool[0u] ) && ( 0x34u == badPointerMempool[1u] ) &&
            ( 0x56u == badPointerMempool[2u] ) && ( 0x78u == badPointerMempool[3u] ) &&
            ( 0x9Au == badPointerMempool[4u] ) && ( 0xBCu == badPointerMempool[5u] ) &&
            ( 0xDEu == badPointerMempool[6u] ) && ( 0xF0u == badPointerMempool[7u] ))
        {
            if( DPK_RES_OK == DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x08u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("dataPackTestEndianBe 12 -- OK \n");
                }
                else
                {
                    (void)printf("dataPackTestEndianBe 12 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataPackTestEndianBe 12 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataPackTestEndianBe 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackTestEndianBe 12 -- FAIL \n");
    }
}

void dataPackTestCycle(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[20u];
    uint32_t varTemp;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestCycle 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCycle 1  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU16( &ctx, 0x1234u ) )
    {
        (void)printf("dataPackTestCycle 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCycle 2  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU16( &ctx, 0x5678u ) )
    {
        (void)printf("dataPackTestCycle 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCycle 3  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("dataPackTestCycle 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCycle 4  -- FAIL \n");
    }

    if( 0x04u == varTemp)
    {
        if( ( 0x34u == badPointerMempool[0u] ) && ( 0x12u == badPointerMempool[1u] ) &&
            ( 0x78u == badPointerMempool[2u] ) && ( 0x56u == badPointerMempool[3u] )  )
        {
            if( DPK_RES_OK == DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x04u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("dataPackTestCycle 5  -- OK \n");
                }
                else
                {
                    (void)printf("dataPackTestCycle 5  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataPackTestCycle 5  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataPackTestCycle 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackTestCycle 5  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == DPK_StartNewPack( &ctx ) )
    {
        (void)printf("dataPackTestCycle 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCycle 6  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU16( &ctx, 0x1234u ) )
    {
        (void)printf("dataPackTestCycle 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCycle 7  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_PushU16( &ctx, 0x5678u ) )
    {
        (void)printf("dataPackTestCycle 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCycle 8  -- FAIL \n");
    }

    if( DPK_RES_OK == DPK_GetNPushed( &ctx, &varTemp) )
    {
        (void)printf("dataPackTestCycle 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestCycle 9  -- FAIL \n");
    }

    if( 0x04u == varTemp)
    {
        if( ( 0x34u == badPointerMempool[0u] ) && ( 0x12u == badPointerMempool[1u] ) &&
            ( 0x78u == badPointerMempool[2u] ) && ( 0x56u == badPointerMempool[3u] )  )
        {
            if( DPK_RES_OK == DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x04u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("dataPackTestCycle 10 -- OK \n");
                }
                else
                {
                    (void)printf("dataPackTestCycle 10 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("dataPackTestCycle 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("dataPackTestCycle 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackTestCycle 10 -- FAIL \n");
    }
}
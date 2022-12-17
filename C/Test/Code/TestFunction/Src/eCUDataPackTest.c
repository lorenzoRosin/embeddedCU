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
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_TEST_dataPackBadPointer(void);
static void eCU_TEST_dataPackBadInit(void);
static void eCU_TEST_dataPackBadParamEntr(void);
static void eCU_TEST_dataPackCorruptContext(void);
static void eCU_TEST_dataPackOutOfMem(void);
static void eCU_TEST_dataPackEndianLe(void);
static void eCU_TEST_dataPackEndianBe(void);
static void eCU_TEST_dataPackCycle(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_TEST_dataPack(void)
{
	(void)printf("\n\nDATA PACK TEST START \n\n");

    eCU_TEST_dataPackBadPointer();
    eCU_TEST_dataPackBadInit();
    eCU_TEST_dataPackBadParamEntr();
    eCU_TEST_dataPackCorruptContext();
    eCU_TEST_dataPackOutOfMem();
    eCU_TEST_dataPackEndianLe();
    eCU_TEST_dataPackEndianBe();
    eCU_TEST_dataPackCycle();

    (void)printf("\n\nDATA PACK END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_TEST_dataPackBadPointer(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;
    uint8_t* dataP;
    bool_t isInit;

    /* Function */
    if( DPK_RES_BADPOINTER == eCU_DPK_InitCtx(NULL, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 1  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_InitCtx(&ctx, NULL, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 2  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_StartNewPack( NULL ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 3  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_GetDataReference( NULL, &dataP, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 4  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_GetDataReference( &ctx, NULL, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 5  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_GetDataReference( &ctx, &dataP, NULL ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 6  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_GetNPushed( NULL, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 7  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_GetNPushed( &ctx, NULL ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 8  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_PushArray( NULL, badPointerMempool, sizeof(badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 9  -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_PushArray( &ctx, NULL, sizeof(badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 10 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_PushU8( NULL, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 11 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_PushU16( NULL, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 12 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_PushU32( NULL, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 13 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_PushU64( NULL, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 14 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_IsInit( NULL, &isInit ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 15 -- FAIL \n");
    }

    if( DPK_RES_BADPOINTER == eCU_DPK_IsInit( &ctx, NULL ) )
    {
        (void)printf("eCU_TEST_dataPackBadPointer 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadPointer 16 -- FAIL \n");
    }
}

static void eCU_TEST_dataPackBadInit(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;
    uint8_t* dataP;
    bool_t isInit;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadInit 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    if( DPK_RES_NOINITLIB == eCU_DPK_StartNewPack( &ctx ) )
    {
        (void)printf("eCU_TEST_dataPackBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadInit 2  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == eCU_DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadInit 3  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == eCU_DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadInit 4  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == eCU_DPK_PushArray( &ctx, badPointerMempool, sizeof(badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_dataPackBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadInit 5  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == eCU_DPK_PushU8( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadInit 6  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == eCU_DPK_PushU16( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadInit 7  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == eCU_DPK_PushU32( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackBadInit 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadInit 8  -- FAIL \n");
    }

    if( DPK_RES_NOINITLIB == eCU_DPK_PushU64( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackBadInit 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadInit 9  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_IsInit( &ctx, &isInit ) )
    {
        if( false == isInit )
        {
            (void)printf("eCU_TEST_dataPackBadInit 10 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataPackBadInit 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadInit 10 -- FAIL \n");
    }
}

static void eCU_TEST_dataPackBadParamEntr(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    bool_t isInit;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_BADPARAM == eCU_DPK_InitCtx(&ctx, badPointerMempool, 0u, true) )
    {
        (void)printf("eCU_TEST_dataPackBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadParamEntr 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_BADPARAM == eCU_DPK_InitCtx(&ctx, badPointerMempool, 0u, false) )
    {
        (void)printf("eCU_TEST_dataPackBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadParamEntr 2  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = true;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadParamEntr 3  -- FAIL \n");
    }

    if( DPK_RES_BADPARAM == eCU_DPK_PushArray( &ctx, badPointerMempool, 0u ) )
    {
        (void)printf("eCU_TEST_dataPackBadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadParamEntr 4  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_IsInit( &ctx, &isInit ) )
    {
        if( true == isInit )
        {
            (void)printf("eCU_TEST_dataPackBadParamEntr 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataPackBadParamEntr 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackBadParamEntr 5  -- FAIL \n");
    }
}

static void eCU_TEST_dataPackCorruptContext(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == eCU_DPK_GetNPushed(&ctx, &varTemp) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 2  -- FAIL \n");
    }



    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 3  -- FAIL \n");
    }

    /* Init variable */
    ctx.p_memPKA = NULL;

    if( DPK_RES_CORRUPTCTX == eCU_DPK_GetNPushed(&ctx, &varTemp) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 4  -- FAIL \n");
    }



    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 5  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKACntr = ctx.memPKASize + 1u;

    if( DPK_RES_CORRUPTCTX == eCU_DPK_GetNPushed(&ctx, &varTemp) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 6  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 7  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == eCU_DPK_StartNewPack( &ctx ) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 8  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 9  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == eCU_DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 10 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 11 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == eCU_DPK_PushArray(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 12 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 13 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == eCU_DPK_PushU8(&ctx, 10u) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 14 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 15 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == eCU_DPK_PushU16(&ctx, 10u) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 16 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 17 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == eCU_DPK_PushU32(&ctx, 10u) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 18 -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 19 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPKASize = 0u;

    if( DPK_RES_CORRUPTCTX == eCU_DPK_PushU64(&ctx, 10u) )
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCorruptContext 20 -- FAIL \n");
    }
}

static void eCU_TEST_dataPackOutOfMem(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[9u];
    uint8_t  arrayTest[5u];

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 1  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU64( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 2  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU64( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 3  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, 7u, true) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 4  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU64( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 5  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, 5u, true) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 6  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 7  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU32( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 8  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, 3u, true) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 9  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU32( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 10 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, 3u, true) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 11 -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 12 -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU16( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 13 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, 1u, true) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 14 -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU16( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 15 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, 1u, true) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 16 -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU8( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 17 -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU8( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 18 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 19 -- FAIL \n");
    }

    (void)memset(arrayTest, 0, sizeof(arrayTest));
    if( DPK_RES_OK == eCU_DPK_PushArray( &ctx, arrayTest, sizeof(arrayTest) ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 20 -- FAIL \n");
    }

    (void)memset(arrayTest, 0, sizeof(arrayTest));
    if( DPK_RES_OUTOFMEM == eCU_DPK_PushArray( &ctx, arrayTest, sizeof(arrayTest) ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 21 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, 4u, true) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 22 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 22 -- FAIL \n");
    }

    (void)memset(arrayTest, 0, sizeof(arrayTest));
    if( DPK_RES_OUTOFMEM == eCU_DPK_PushArray( &ctx, arrayTest, sizeof(arrayTest) ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 23 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 23 -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 24 -- FAIL \n");
    }

    (void)memset(arrayTest, 0, sizeof(arrayTest));
    if( DPK_RES_OK == eCU_DPK_PushArray( &ctx, arrayTest, sizeof(arrayTest) ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 25 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 25 -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU8( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 26 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 26 -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 27 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 27 -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU32( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 28 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 28 -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU64( &ctx, 10u ) )
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 29 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackOutOfMem 29 -- FAIL \n");
    }
}

static void eCU_TEST_dataPackEndianLe(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[20u];
    uint32_t varTemp;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackEndianLe 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 1  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16( &ctx, 0x1234u ) )
    {
        (void)printf("eCU_TEST_dataPackEndianLe 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackEndianLe 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 3  -- FAIL \n");
    }

    if( 0x02u == varTemp)
    {
        if( ( 0x34u == badPointerMempool[0u] ) && ( 0x12u == badPointerMempool[1u] ) )
        {
            if( DPK_RES_OK == eCU_DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x02u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("eCU_TEST_dataPackEndianLe 4  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_dataPackEndianLe 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataPackEndianLe 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataPackEndianLe 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 4  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_StartNewPack( &ctx ) )
    {
        (void)printf("eCU_TEST_dataPackEndianLe 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 5  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32( &ctx, 0x12345678u ) )
    {
        (void)printf("eCU_TEST_dataPackEndianLe 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 6  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackEndianLe 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 7  -- FAIL \n");
    }

    if( 0x04u == varTemp)
    {
        if( ( 0x78u == badPointerMempool[0u] ) && ( 0x56u == badPointerMempool[1u] ) &&
            ( 0x34u == badPointerMempool[2u] ) && ( 0x12u == badPointerMempool[3u] ) )
        {
            if( DPK_RES_OK == eCU_DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x04u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("eCU_TEST_dataPackEndianLe 8  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_dataPackEndianLe 8  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataPackEndianLe 8  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataPackEndianLe 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 8  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_StartNewPack( &ctx ) )
    {
        (void)printf("eCU_TEST_dataPackEndianLe 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 9  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU64( &ctx, 0x123456789ABCDEF0u ) )
    {
        (void)printf("eCU_TEST_dataPackEndianLe 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 10 -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackEndianLe 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 11 -- FAIL \n");
    }

    if( 0x08u == varTemp)
    {
        if( ( 0xF0u == badPointerMempool[0u] ) && ( 0xDEu == badPointerMempool[1u] ) &&
            ( 0xBCu == badPointerMempool[2u] ) && ( 0x9Au == badPointerMempool[3u] ) &&
            ( 0x78u == badPointerMempool[4u] ) && ( 0x56u == badPointerMempool[5u] ) &&
            ( 0x34u == badPointerMempool[6u] ) && ( 0x12u == badPointerMempool[7u] ))
        {
            if( DPK_RES_OK == eCU_DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x08u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("eCU_TEST_dataPackEndianLe 12 -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_dataPackEndianLe 12 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataPackEndianLe 12 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataPackEndianLe 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianLe 12 -- FAIL \n");
    }
}

static void eCU_TEST_dataPackEndianBe(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[20u];
    uint32_t varTemp;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), false) )
    {
        (void)printf("eCU_TEST_dataPackEndianBe 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 1  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16( &ctx, 0x1234u ) )
    {
        (void)printf("eCU_TEST_dataPackEndianBe 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackEndianBe 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 3  -- FAIL \n");
    }

    if( 0x02u == varTemp)
    {
        if( ( 0x12u == badPointerMempool[0u] ) && ( 0x34u == badPointerMempool[1u] ) )
        {
            if( DPK_RES_OK == eCU_DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x02u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("eCU_TEST_dataPackEndianBe 4  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_dataPackEndianBe 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataPackEndianBe 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataPackEndianBe 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 4  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_StartNewPack( &ctx ) )
    {
        (void)printf("eCU_TEST_dataPackEndianBe 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 5  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32( &ctx, 0x12345678u ) )
    {
        (void)printf("eCU_TEST_dataPackEndianBe 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 6  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackEndianBe 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 7  -- FAIL \n");
    }

    if( 0x04u == varTemp)
    {
        if( ( 0x12u == badPointerMempool[0u] ) && ( 0x34u == badPointerMempool[1u] ) &&
            ( 0x56u == badPointerMempool[2u] ) && ( 0x78u == badPointerMempool[3u] ) )
        {
            if( DPK_RES_OK == eCU_DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x04u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("eCU_TEST_dataPackEndianBe 8  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_dataPackEndianBe 8  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataPackEndianBe 8  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataPackEndianBe 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 8  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_StartNewPack( &ctx ) )
    {
        (void)printf("eCU_TEST_dataPackEndianBe 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 9  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU64( &ctx, 0x123456789ABCDEF0u ) )
    {
        (void)printf("eCU_TEST_dataPackEndianBe 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 10 -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackEndianBe 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 11 -- FAIL \n");
    }

    if( 0x08u == varTemp)
    {
        if( ( 0x12u == badPointerMempool[0u] ) && ( 0x34u == badPointerMempool[1u] ) &&
            ( 0x56u == badPointerMempool[2u] ) && ( 0x78u == badPointerMempool[3u] ) &&
            ( 0x9Au == badPointerMempool[4u] ) && ( 0xBCu == badPointerMempool[5u] ) &&
            ( 0xDEu == badPointerMempool[6u] ) && ( 0xF0u == badPointerMempool[7u] ))
        {
            if( DPK_RES_OK == eCU_DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x08u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("eCU_TEST_dataPackEndianBe 12 -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_dataPackEndianBe 12 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataPackEndianBe 12 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataPackEndianBe 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackEndianBe 12 -- FAIL \n");
    }
}

static void eCU_TEST_dataPackCycle(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctx;
    uint8_t  badPointerMempool[20u];
    uint32_t varTemp;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataPackCycle 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCycle 1  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16( &ctx, 0x1234u ) )
    {
        (void)printf("eCU_TEST_dataPackCycle 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCycle 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16( &ctx, 0x5678u ) )
    {
        (void)printf("eCU_TEST_dataPackCycle 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCycle 3  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed( &ctx, &varTemp ) )
    {
        (void)printf("eCU_TEST_dataPackCycle 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCycle 4  -- FAIL \n");
    }

    if( 0x04u == varTemp)
    {
        if( ( 0x34u == badPointerMempool[0u] ) && ( 0x12u == badPointerMempool[1u] ) &&
            ( 0x78u == badPointerMempool[2u] ) && ( 0x56u == badPointerMempool[3u] )  )
        {
            if( DPK_RES_OK == eCU_DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x04u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("eCU_TEST_dataPackCycle 5  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_dataPackCycle 5  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataPackCycle 5  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataPackCycle 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCycle 5  -- FAIL \n");
    }

    /* Function */
    if( DPK_RES_OK == eCU_DPK_StartNewPack( &ctx ) )
    {
        (void)printf("eCU_TEST_dataPackCycle 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCycle 6  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16( &ctx, 0x1234u ) )
    {
        (void)printf("eCU_TEST_dataPackCycle 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCycle 7  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16( &ctx, 0x5678u ) )
    {
        (void)printf("eCU_TEST_dataPackCycle 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCycle 8  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed( &ctx, &varTemp) )
    {
        (void)printf("eCU_TEST_dataPackCycle 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCycle 9  -- FAIL \n");
    }

    if( 0x04u == varTemp)
    {
        if( ( 0x34u == badPointerMempool[0u] ) && ( 0x12u == badPointerMempool[1u] ) &&
            ( 0x78u == badPointerMempool[2u] ) && ( 0x56u == badPointerMempool[3u] )  )
        {
            if( DPK_RES_OK == eCU_DPK_GetDataReference( &ctx, &dataP, &varTemp ) )
            {
                if( ( 0x04u == varTemp ) && ( badPointerMempool == dataP ) )
                {
                    (void)printf("eCU_TEST_dataPackCycle 10 -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_dataPackCycle 10 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataPackCycle 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataPackCycle 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackCycle 10 -- FAIL \n");
    }
}
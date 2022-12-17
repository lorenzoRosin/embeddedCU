/**
 * @file       eCUCircularQueueTest.c
 *
 * @brief      Circular queue test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUCircularQueueTest.h"
#include <stdio.h>

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "CERT-STR32-C"
    /* Suppressed for code clarity in test execution*/
#endif



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_TEST_circularqueueBadPointer(void);
static void eCU_TEST_circularqueueBadInit(void);
static void eCU_TEST_circularqueueBadParamEntr(void);
static void eCU_TEST_circularqueueCorruptedContext(void);
static void eCU_TEST_circularqueueEmptyMem(void);
static void eCU_TEST_circularqueueFullMem(void);
static void eCU_TEST_circularqueueGeneric(void);
static void eCU_TEST_circularqueueCycle1(void);
static void eCU_TEST_circularqueueCycle2(void);

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_TEST_circularQueue(void)
{
	(void)printf("\n\nCIRCULAR QUEUE TEST START \n\n");

    eCU_TEST_circularqueueBadPointer();
    eCU_TEST_circularqueueBadInit();
    eCU_TEST_circularqueueBadParamEntr();
    eCU_TEST_circularqueueCorruptedContext();
    eCU_TEST_circularqueueEmptyMem();
    eCU_TEST_circularqueueFullMem();
    eCU_TEST_circularqueueGeneric();
    eCU_TEST_circularqueueCycle1();
    eCU_TEST_circularqueueCycle2();

    (void)printf("\n\nCIRCULAR QUEUE TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_TEST_circularqueueBadPointer(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;
    bool_t isInit;

    /* Function */
    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_InitCtx(NULL, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 1  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_InitCtx(&ctx, NULL, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 2  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_Reset(NULL) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 3  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_GetFreeSapce(NULL, &varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 4  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_GetFreeSapce(&ctx, NULL) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 5  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_GetOccupiedSapce(NULL, &varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 6  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_GetOccupiedSapce(&ctx, NULL) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 7  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_InsertData(NULL, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 8  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_InsertData(&ctx, NULL, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 9  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_RetriveData(NULL, badPointerMempool, varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 10 -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_RetriveData(&ctx, NULL, varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 11 -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_PeekData(NULL, badPointerMempool, varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 12 -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_PeekData(&ctx, NULL, varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 13 -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_IsInit( NULL, &isInit ) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 14 -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == eCU_CIRQ_IsInit( &ctx, NULL ) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 15 -- FAIL \n");
    }
}

static void eCU_TEST_circularqueueBadInit(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;
    bool_t isInit;

    /* Init variable */
    ctx.isInit = true;

    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    if( CIRQ_RES_NOINITLIB == eCU_CIRQ_Reset(&ctx) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 2  -- FAIL \n");
    }

    if( CIRQ_RES_NOINITLIB == eCU_CIRQ_GetFreeSapce(&ctx, &varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 3  -- FAIL \n");
    }

    if( CIRQ_RES_NOINITLIB == eCU_CIRQ_GetOccupiedSapce(&ctx, &varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 4  -- FAIL \n");
    }

    if( CIRQ_RES_NOINITLIB == eCU_CIRQ_InsertData(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 5  -- FAIL \n");
    }

    if( CIRQ_RES_NOINITLIB == eCU_CIRQ_RetriveData(&ctx, badPointerMempool, varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 6  -- FAIL \n");
    }

    if( CIRQ_RES_NOINITLIB == eCU_CIRQ_PeekData(&ctx, badPointerMempool, varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 7  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_IsInit( &ctx, &isInit ) )
    {
        if( false == isInit )
        {
            (void)printf("eCU_TEST_circularqueueBadInit 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueBadInit 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 8  -- FAIL \n");
    }
}

static void eCU_TEST_circularqueueBadParamEntr(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    bool_t isInit;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CIRQ_RES_BADPARAM == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, 0u) )
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 1  -- FAIL \n");
    }

    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 2  -- FAIL \n");
    }

    if( CIRQ_RES_BADPARAM == eCU_CIRQ_InsertData(&ctx, badPointerMempool, 0u) )
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 3  -- FAIL \n");
    }

    if( CIRQ_RES_BADPARAM == eCU_CIRQ_RetriveData(&ctx, badPointerMempool, 0u) )
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 4  -- FAIL \n");
    }

    if( CIRQ_RES_BADPARAM == eCU_CIRQ_PeekData(&ctx, badPointerMempool, 0u) )
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 5  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_IsInit( &ctx, &isInit ) )
    {
        if( true == isInit )
        {
            (void)printf("eCU_TEST_circularqueueBadParamEntr 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueBadParamEntr 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 6  -- FAIL \n");
    }
}

static void eCU_TEST_circularqueueCorruptedContext(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t val;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&ctx) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 2  -- FAIL \n");
    }


    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 3  -- FAIL \n");
    }

    ctx.p_memP = NULL;

    if( CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&ctx) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 4  -- FAIL \n");
    }


    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 5  -- FAIL \n");
    }

    ctx.memPFreeIdx = sizeof(badPointerMempool) +1u;

    if( CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&ctx) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 6  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 5  -- FAIL \n");
    }

    ctx.memPUsedSize = sizeof(badPointerMempool) +1u;

    if( CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&ctx) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 6  -- FAIL \n");
    }

    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 7  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == eCU_CIRQ_GetFreeSapce(&ctx, &val) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 8  -- FAIL \n");
    }

    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 9  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == eCU_CIRQ_GetOccupiedSapce(&ctx, &val) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 10 -- FAIL \n");
    }

    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 11 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == eCU_CIRQ_InsertData(&ctx, badPointerMempool, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 12 -- FAIL \n");
    }

    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 13 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == eCU_CIRQ_RetriveData(&ctx, badPointerMempool, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 14 -- FAIL \n");
    }


    /* Function */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 15 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == eCU_CIRQ_PeekData(&ctx, badPointerMempool, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 16 -- FAIL \n");
    }

}

static void eCU_TEST_circularqueueEmptyMem(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint8_t  retriveData[10u];

    /* Init variable */
    ctx.isInit = false;

    /* Easy one  */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 1  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&ctx, retriveData, sizeof(retriveData)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 2  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&ctx, retriveData, sizeof(retriveData)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 3  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&ctx, retriveData, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 4  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&ctx, retriveData, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 5  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_InsertData(&ctx, retriveData, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 6  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_PeekData(&ctx, retriveData, sizeof(badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 7  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 8  -- FAIL \n");
    }

    /* most complete one */
    if( CIRQ_RES_OK == eCU_CIRQ_InsertData(&ctx, retriveData, sizeof(badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 9  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&ctx, retriveData, sizeof(retriveData)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 10 -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 11 -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&ctx, retriveData, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 12 -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_InsertData(&ctx, retriveData, 2u ) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 13 -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_InsertData(&ctx, retriveData, 3u ) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 14 -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_PeekData(&ctx, retriveData, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 15 -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 16 -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&ctx, retriveData, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 17 -- FAIL \n");
    }
}

static void eCU_TEST_circularqueueFullMem(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint8_t  retriveData[10u];

    /* Init variable */
    ctx.isInit = false;

    /* Easy one  */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 1  -- FAIL \n");
    }

    if( CIRQ_RES_FULL == eCU_CIRQ_InsertData(&ctx, retriveData, sizeof(retriveData)) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 2  -- FAIL \n");
    }

    if( CIRQ_RES_FULL == eCU_CIRQ_InsertData(&ctx, retriveData, sizeof(badPointerMempool) +1u ) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 3  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_InsertData(&ctx, retriveData, sizeof(badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 4  -- FAIL \n");
    }

    if( CIRQ_RES_FULL == eCU_CIRQ_InsertData(&ctx, retriveData, 1u ) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 5  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 6  -- FAIL \n");
    }

    if( CIRQ_RES_FULL == eCU_CIRQ_InsertData(&ctx, retriveData, 2u ) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 7  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_PeekData(&ctx, retriveData, 4u) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 8  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&ctx, retriveData, 5u) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 9  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData, 4u) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 10 -- FAIL \n");
    }
}

static void eCU_TEST_circularqueueGeneric(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  pointerMempool[10u];
    uint32_t varTemp;
    uint8_t  retriveData[10u] = {0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u};
    uint8_t  insertData[10u]  = {0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u};

    /* Init variable */
    ctx.isInit = false;

    /* Easy one  */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, pointerMempool, sizeof(pointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 1  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_GetFreeSapce(&ctx, &varTemp) )
    {
        if( 10u == varTemp )
        {
            (void)printf("eCU_TEST_circularqueueGeneric 2  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueGeneric 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 2  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_GetOccupiedSapce(&ctx, &varTemp) )
    {
        if( 0u == varTemp )
        {
            (void)printf("eCU_TEST_circularqueueGeneric 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueGeneric 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 3  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_InsertData(&ctx, insertData, sizeof(insertData) ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 4  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_GetFreeSapce(&ctx, &varTemp) )
    {
        if( 0u == varTemp )
        {
            (void)printf("eCU_TEST_circularqueueGeneric 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueGeneric 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 5  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_GetOccupiedSapce(&ctx, &varTemp) )
    {
        if( 10u == varTemp )
        {
            (void)printf("eCU_TEST_circularqueueGeneric 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueGeneric 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 6  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_PeekData(&ctx, retriveData, sizeof(retriveData)) )
    {
        if( 0 == memcmp(insertData, retriveData, sizeof(retriveData) ) )
        {
            (void)printf("eCU_TEST_circularqueueGeneric 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueGeneric 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 7  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData, 7u ) )
    {
        if( 0 == memcmp(insertData, retriveData, 7u ) )
        {
            (void)printf("eCU_TEST_circularqueueGeneric 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueGeneric 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 8  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_InsertData(&ctx, insertData, 2u ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 9  -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData, 5u ) )
    {
        if( 0 == memcmp(&insertData[7], retriveData, 3u ) )
        {
            if( 0 == memcmp(&insertData[0], &retriveData[3u], 2u ) )
            {
                (void)printf("eCU_TEST_circularqueueGeneric 10 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_circularqueueGeneric 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueGeneric 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 10 -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_Reset(&ctx) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 11 -- FAIL \n");
    }

    /* Easy one  */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, pointerMempool, sizeof(pointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 12 -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_InsertData(&ctx, insertData, sizeof(insertData) ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 13 -- FAIL \n");
    }

    if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData, 5u ) )
    {
        if( 0 == memcmp(insertData, retriveData, 5u ) )
        {
            (void)printf("eCU_TEST_circularqueueGeneric 14 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueGeneric 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 14 -- FAIL \n");
    }


    if( CIRQ_RES_OK == eCU_CIRQ_InsertData(&ctx, insertData, 5u ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 15 -- FAIL \n");
    }


    if( CIRQ_RES_OK == eCU_CIRQ_PeekData(&ctx, retriveData, sizeof(retriveData)) )
    {
        if( 0 == memcmp(&insertData[5u], retriveData, 5u ) )
        {
            if( 0 == memcmp(insertData, &retriveData[5], 5u ) )
            {
                (void)printf("eCU_TEST_circularqueueGeneric 16 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_circularqueueGeneric 16 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_circularqueueGeneric 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 16 -- FAIL \n");
    }

}

static void eCU_TEST_circularqueueCycle1(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  pointerMempool[10u];
    uint8_t  retriveData3[3u] = {0u};
    uint8_t  retriveData4[4u] = {0u};
    uint8_t  insertData[7u]  = {0u, 1u, 2u, 3u, 4u, 5u, 6u};
    bool_t   testOk = true;

    /* Init variable */
    ctx.isInit = false;

    /* Test */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, pointerMempool, sizeof(pointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueCycle1 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCycle1 1  -- FAIL \n");
    }

    for(uint32_t i = 0u; ( ( i <= 1000u ) && ( true == testOk ) ); i++)
    {
        if( CIRQ_RES_OK != eCU_CIRQ_InsertData(&ctx, insertData, sizeof(insertData) ) )
        {
            testOk = false;
        }

        if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData3, sizeof(retriveData3) ) )
        {
            if( 0 != memcmp(insertData, retriveData3, sizeof(retriveData3) ) )
            {
                testOk = false;
            }
        }
        else
        {
            testOk = false;
        }

        if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData4, sizeof(retriveData4) ) )
        {
            if( 0 != memcmp(&insertData[3], retriveData4, sizeof(retriveData4) ) )
            {
                testOk = false;
            }
        }
        else
        {
            testOk = false;
        }
    }

    if( true == testOk )
    {
        (void)printf("eCU_TEST_circularqueueCycle1 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCycle1 2  -- FAIL \n");
    }
}

static void eCU_TEST_circularqueueCycle2(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  pointerMempool[10u];
    uint8_t  retriveData3[1u] = {0u};
    uint8_t  retriveData4[1u] = {0u};
    uint8_t  insertData[2u]  = {1u, 1u};
    bool_t   testOk = true;

    /* Init variable */
    ctx.isInit = false;

    /* Test */
    if( CIRQ_RES_OK == eCU_CIRQ_InitCtx(&ctx, pointerMempool, sizeof(pointerMempool) ) )
    {
        (void)printf("circularqueueTestCycle2 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCycle2 1  -- FAIL \n");
    }

    for(uint32_t i = 0u; ( ( i <= 1000u ) && ( true == testOk ) ); i++)
    {
        if( CIRQ_RES_OK != eCU_CIRQ_InsertData(&ctx, insertData, sizeof(insertData) ) )
        {
            testOk = false;
        }

        if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData3, sizeof(retriveData3) ) )
        {
            if( 0 != memcmp(insertData, retriveData3, sizeof(retriveData3) ) )
            {
                testOk = false;
            }
        }
        else
        {
            testOk = false;
        }

        if( CIRQ_RES_OK == eCU_CIRQ_RetriveData(&ctx, retriveData4, sizeof(retriveData4) ) )
        {
            if( 0 != memcmp(insertData, retriveData4, sizeof(retriveData4) ) )
            {
                testOk = false;
            }
        }
        else
        {
            testOk = false;
        }
    }

    if( true == testOk )
    {
        (void)printf("circularqueueTestCycle2 2  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCycle2 2  -- FAIL \n");
    }
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "CERT-STR32-C"
#endif
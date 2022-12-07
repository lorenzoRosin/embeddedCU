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

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif

#include <stdio.h>

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "CERT-STR32-C"
    /* Suppressed for code clarity in test execution*/
#endif



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void circularqueueTestBadPointer(void);
static void circularqueueTestBadInit(void);
static void circularqueueTestBadParamEntr(void);
static void circularqueueTestCorruptedContext(void);
static void circularqueueTestEmptyMem(void);
static void circularqueueTestFullMem(void);
static void circularqueueTestGeneric(void);
static void circularqueueTestCycle1(void);
static void circularqueueTestCycle2(void);

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void circularQueueTest(void)
{
	(void)printf("\n\nCIRCULAR QUEUE TEST START \n\n");

    circularqueueTestBadPointer();
    circularqueueTestBadInit();
    circularqueueTestBadParamEntr();
    circularqueueTestCorruptedContext();
    circularqueueTestEmptyMem();
    circularqueueTestFullMem();
    circularqueueTestGeneric();
    circularqueueTestCycle1();
    circularqueueTestCycle2();

    (void)printf("\n\nCIRCULAR QUEUE TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void circularqueueTestBadPointer(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;
    bool_t isInit;

    /* Function */
    if( CIRQ_RES_BADPOINTER == CIRQ_InitCtx(NULL, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 1  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_InitCtx(&ctx, NULL, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 2  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_Reset(NULL) )
    {
        (void)printf("circularqueueTestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 3  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_GetFreeSapce(NULL, &varTemp) )
    {
        (void)printf("circularqueueTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 4  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_GetFreeSapce(&ctx, NULL) )
    {
        (void)printf("circularqueueTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 5  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_GetOccupiedSapce(NULL, &varTemp) )
    {
        (void)printf("circularqueueTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 6  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_GetOccupiedSapce(&ctx, NULL) )
    {
        (void)printf("circularqueueTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 7  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_InsertData(NULL, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 8  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_InsertData(&ctx, NULL, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 9  -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_RetriveData(NULL, badPointerMempool, varTemp) )
    {
        (void)printf("circularqueueTestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 10 -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_RetriveData(&ctx, NULL, varTemp) )
    {
        (void)printf("circularqueueTestBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 11 -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_PeekData(NULL, badPointerMempool, varTemp) )
    {
        (void)printf("circularqueueTestBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 12 -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_PeekData(&ctx, NULL, varTemp) )
    {
        (void)printf("circularqueueTestBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 13 -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_IsInit( NULL, &isInit ) )
    {
        (void)printf("circularqueueTestBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 14 -- FAIL \n");
    }

    if( CIRQ_RES_BADPOINTER == CIRQ_IsInit( &ctx, NULL ) )
    {
        (void)printf("circularqueueTestBadPointer 15 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadPointer 15 -- FAIL \n");
    }
}

void circularqueueTestBadInit(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;

    /* Init variable */
    ctx.isInit = true;

    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadInit 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    if( CIRQ_RES_NOINITLIB == CIRQ_Reset(&ctx) )
    {
        (void)printf("circularqueueTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadInit 2  -- FAIL \n");
    }

    if( CIRQ_RES_NOINITLIB == CIRQ_GetFreeSapce(&ctx, &varTemp) )
    {
        (void)printf("circularqueueTestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadInit 3  -- FAIL \n");
    }

    if( CIRQ_RES_NOINITLIB == CIRQ_GetOccupiedSapce(&ctx, &varTemp) )
    {
        (void)printf("circularqueueTestBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadInit 4  -- FAIL \n");
    }

    if( CIRQ_RES_NOINITLIB == CIRQ_InsertData(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadInit 5  -- FAIL \n");
    }

    if( CIRQ_RES_NOINITLIB == CIRQ_RetriveData(&ctx, badPointerMempool, varTemp) )
    {
        (void)printf("circularqueueTestBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadInit 6  -- FAIL \n");
    }

    if( CIRQ_RES_NOINITLIB == CIRQ_PeekData(&ctx, badPointerMempool, varTemp) )
    {
        (void)printf("circularqueueTestBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadInit 7  -- FAIL \n");
    }
}

void circularqueueTestBadParamEntr(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CIRQ_RES_BADPARAM == CIRQ_InitCtx(&ctx, badPointerMempool, 0u) )
    {
        (void)printf("circularqueueTestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadParamEntr 1  -- FAIL \n");
    }

    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadParamEntr 2  -- FAIL \n");
    }

    if( CIRQ_RES_BADPARAM == CIRQ_InsertData(&ctx, badPointerMempool, 0u) )
    {
        (void)printf("circularqueueTestBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadParamEntr 3  -- FAIL \n");
    }

    if( CIRQ_RES_BADPARAM == CIRQ_RetriveData(&ctx, badPointerMempool, 0u) )
    {
        (void)printf("circularqueueTestBadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadParamEntr 4  -- FAIL \n");
    }

    if( CIRQ_RES_BADPARAM == CIRQ_PeekData(&ctx, badPointerMempool, 0u) )
    {
        (void)printf("circularqueueTestBadParamEntr 5  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestBadParamEntr 5  -- FAIL \n");
    }
}

static void circularqueueTestCorruptedContext(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t val;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestCorruptedContext 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == CIRQ_Reset(&ctx) )
    {
        (void)printf("circularqueueTestCorruptedContext 2  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 2  -- FAIL \n");
    }


    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestCorruptedContext 3  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 3  -- FAIL \n");
    }

    ctx.memP = NULL;

    if( CIRQ_RES_CORRUPTCTX == CIRQ_Reset(&ctx) )
    {
        (void)printf("circularqueueTestCorruptedContext 4  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 4  -- FAIL \n");
    }


    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestCorruptedContext 5  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 5  -- FAIL \n");
    }

    ctx.memPFreeIdx = sizeof(badPointerMempool) +1u;

    if( CIRQ_RES_CORRUPTCTX == CIRQ_Reset(&ctx) )
    {
        (void)printf("circularqueueTestCorruptedContext 6  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 6  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestCorruptedContext 5  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 5  -- FAIL \n");
    }

    ctx.memPUsedSize = sizeof(badPointerMempool) +1u;

    if( CIRQ_RES_CORRUPTCTX == CIRQ_Reset(&ctx) )
    {
        (void)printf("circularqueueTestCorruptedContext 6  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 6  -- FAIL \n");
    }

    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestCorruptedContext 7  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 7  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == CIRQ_GetFreeSapce(&ctx, &val) )
    {
        (void)printf("circularqueueTestCorruptedContext 8  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 8  -- FAIL \n");
    }

    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestCorruptedContext 9  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 9  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == CIRQ_GetOccupiedSapce(&ctx, &val) )
    {
        (void)printf("circularqueueTestCorruptedContext 10 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 10 -- FAIL \n");
    }

    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestCorruptedContext 11 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 11 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == CIRQ_InsertData(&ctx, badPointerMempool, 1u) )
    {
        (void)printf("circularqueueTestCorruptedContext 12 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 12 -- FAIL \n");
    }

    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestCorruptedContext 13 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 13 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == CIRQ_RetriveData(&ctx, badPointerMempool, 1u) )
    {
        (void)printf("circularqueueTestCorruptedContext 14 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 14 -- FAIL \n");
    }


    /* Function */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestCorruptedContext 15 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 15 -- FAIL \n");
    }

    /* Init variable */
    ctx.memPSize = 0u;

    if( CIRQ_RES_CORRUPTCTX == CIRQ_PeekData(&ctx, badPointerMempool, 1u) )
    {
        (void)printf("circularqueueTestCorruptedContext 16 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCorruptedContext 16 -- FAIL \n");
    }

}

void circularqueueTestEmptyMem(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint8_t  retriveData[10u];

    /* Init variable */
    ctx.isInit = false;

    /* Easy one  */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestEmptyMem 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 1  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == CIRQ_PeekData(&ctx, retriveData, sizeof(retriveData)) )
    {
        (void)printf("circularqueueTestEmptyMem 2  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 2  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == CIRQ_RetriveData(&ctx, retriveData, sizeof(retriveData)) )
    {
        (void)printf("circularqueueTestEmptyMem 3  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 3  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == CIRQ_PeekData(&ctx, retriveData, 1u) )
    {
        (void)printf("circularqueueTestEmptyMem 4  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 4  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == CIRQ_RetriveData(&ctx, retriveData, 1u) )
    {
        (void)printf("circularqueueTestEmptyMem 5  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 5  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_InsertData(&ctx, retriveData, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestEmptyMem 6  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 6  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_PeekData(&ctx, retriveData, sizeof(badPointerMempool) ) )
    {
        (void)printf("circularqueueTestEmptyMem 7  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 7  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestEmptyMem 8  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 8  -- FAIL \n");
    }

    /* most complete one */
    if( CIRQ_RES_OK == CIRQ_InsertData(&ctx, retriveData, sizeof(badPointerMempool) ) )
    {
        (void)printf("circularqueueTestEmptyMem 9  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 9  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == CIRQ_RetriveData(&ctx, retriveData, sizeof(retriveData)) )
    {
        (void)printf("circularqueueTestEmptyMem 10 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 10 -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestEmptyMem 11 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 11 -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == CIRQ_RetriveData(&ctx, retriveData, 1u) )
    {
        (void)printf("circularqueueTestEmptyMem 12 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 12 -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_InsertData(&ctx, retriveData, 2u ) )
    {
        (void)printf("circularqueueTestEmptyMem 13 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 13 -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_InsertData(&ctx, retriveData, 3u ) )
    {
        (void)printf("circularqueueTestEmptyMem 14 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 14 -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_PeekData(&ctx, retriveData, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestEmptyMem 15 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 15 -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestEmptyMem 16 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 16 -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == CIRQ_PeekData(&ctx, retriveData, 1u) )
    {
        (void)printf("circularqueueTestEmptyMem 17 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestEmptyMem 17 -- FAIL \n");
    }
}

void circularqueueTestFullMem(void)
{
    /* Local variable */
    s_eCU_CIRQ_Ctx ctx;
    uint8_t  badPointerMempool[5u];
    uint8_t  retriveData[10u];

    /* Init variable */
    ctx.isInit = false;

    /* Easy one  */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, badPointerMempool, sizeof(badPointerMempool)) )
    {
        (void)printf("circularqueueTestFullMem 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestFullMem 1  -- FAIL \n");
    }

    if( CIRQ_RES_FULL == CIRQ_InsertData(&ctx, retriveData, sizeof(retriveData)) )
    {
        (void)printf("circularqueueTestFullMem 2  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestFullMem 2  -- FAIL \n");
    }

    if( CIRQ_RES_FULL == CIRQ_InsertData(&ctx, retriveData, sizeof(badPointerMempool) +1u ) )
    {
        (void)printf("circularqueueTestFullMem 3  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestFullMem 3  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_InsertData(&ctx, retriveData, sizeof(badPointerMempool) ) )
    {
        (void)printf("circularqueueTestFullMem 4  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestFullMem 4  -- FAIL \n");
    }

    if( CIRQ_RES_FULL == CIRQ_InsertData(&ctx, retriveData, 1u ) )
    {
        (void)printf("circularqueueTestFullMem 5  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestFullMem 5  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData, 1u) )
    {
        (void)printf("circularqueueTestFullMem 6  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestFullMem 6  -- FAIL \n");
    }

    if( CIRQ_RES_FULL == CIRQ_InsertData(&ctx, retriveData, 2u ) )
    {
        (void)printf("circularqueueTestFullMem 7  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestFullMem 7  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_PeekData(&ctx, retriveData, 4u) )
    {
        (void)printf("circularqueueTestFullMem 8  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestFullMem 8  -- FAIL \n");
    }

    if( CIRQ_RES_EMPTY == CIRQ_PeekData(&ctx, retriveData, 5u) )
    {
        (void)printf("circularqueueTestFullMem 9  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestFullMem 9  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData, 4u) )
    {
        (void)printf("circularqueueTestFullMem 10 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestFullMem 10 -- FAIL \n");
    }
}

static void circularqueueTestGeneric(void)
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
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, pointerMempool, sizeof(pointerMempool) ) )
    {
        (void)printf("circularqueueTestGeneric 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestGeneric 1  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_GetFreeSapce(&ctx, &varTemp) )
    {
        if( 10u == varTemp )
        {
            (void)printf("circularqueueTestGeneric 2  -- OK \n");
        }
        else
        {
            (void)printf("circularqueueTestGeneric 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("circularqueueTestGeneric 2  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_GetOccupiedSapce(&ctx, &varTemp) )
    {
        if( 0u == varTemp )
        {
            (void)printf("circularqueueTestGeneric 3  -- OK \n");
        }
        else
        {
            (void)printf("circularqueueTestGeneric 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("circularqueueTestGeneric 3  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_InsertData(&ctx, insertData, sizeof(insertData) ) )
    {
        (void)printf("circularqueueTestGeneric 4  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestGeneric 4  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_GetFreeSapce(&ctx, &varTemp) )
    {
        if( 0u == varTemp )
        {
            (void)printf("circularqueueTestGeneric 5  -- OK \n");
        }
        else
        {
            (void)printf("circularqueueTestGeneric 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("circularqueueTestGeneric 5  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_GetOccupiedSapce(&ctx, &varTemp) )
    {
        if( 10u == varTemp )
        {
            (void)printf("circularqueueTestGeneric 6  -- OK \n");
        }
        else
        {
            (void)printf("circularqueueTestGeneric 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("circularqueueTestGeneric 6  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_PeekData(&ctx, retriveData, sizeof(retriveData)) )
    {
        if( 0 == memcmp(insertData, retriveData, sizeof(retriveData) ) )
        {
            (void)printf("circularqueueTestGeneric 7  -- OK \n");
        }
        else
        {
            (void)printf("circularqueueTestGeneric 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("circularqueueTestGeneric 7  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData, 7u ) )
    {
        if( 0 == memcmp(insertData, retriveData, 7u ) )
        {
            (void)printf("circularqueueTestGeneric 8  -- OK \n");
        }
        else
        {
            (void)printf("circularqueueTestGeneric 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("circularqueueTestGeneric 8  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_InsertData(&ctx, insertData, 2u ) )
    {
        (void)printf("circularqueueTestGeneric 9  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestGeneric 9  -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData, 5u ) )
    {
        if( 0 == memcmp(&insertData[7], retriveData, 3u ) )
        {
            if( 0 == memcmp(&insertData[0], &retriveData[3u], 2u ) )
            {
                (void)printf("circularqueueTestGeneric 10 -- OK \n");
            }
            else
            {
                (void)printf("circularqueueTestGeneric 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("circularqueueTestGeneric 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("circularqueueTestGeneric 10 -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_Reset(&ctx) )
    {
        (void)printf("circularqueueTestGeneric 11 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestGeneric 11 -- FAIL \n");
    }

    /* Easy one  */
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, pointerMempool, sizeof(pointerMempool) ) )
    {
        (void)printf("circularqueueTestGeneric 12 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestGeneric 12 -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_InsertData(&ctx, insertData, sizeof(insertData) ) )
    {
        (void)printf("circularqueueTestGeneric 13 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestGeneric 13 -- FAIL \n");
    }

    if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData, 5u ) )
    {
        if( 0 == memcmp(insertData, retriveData, 5u ) )
        {
            (void)printf("circularqueueTestGeneric 14 -- OK \n");
        }
        else
        {
            (void)printf("circularqueueTestGeneric 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("circularqueueTestGeneric 14 -- FAIL \n");
    }


    if( CIRQ_RES_OK == CIRQ_InsertData(&ctx, insertData, 5u ) )
    {
        (void)printf("circularqueueTestGeneric 15 -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestGeneric 15 -- FAIL \n");
    }


    if( CIRQ_RES_OK == CIRQ_PeekData(&ctx, retriveData, sizeof(retriveData)) )
    {
        if( 0 == memcmp(&insertData[5u], retriveData, 5u ) )
        {
            if( 0 == memcmp(insertData, &retriveData[5], 5u ) )
            {
                (void)printf("circularqueueTestGeneric 16 -- OK \n");
            }
            else
            {
                (void)printf("circularqueueTestGeneric 16 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("circularqueueTestGeneric 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("circularqueueTestGeneric 16 -- FAIL \n");
    }

}

static void circularqueueTestCycle1(void)
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
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, pointerMempool, sizeof(pointerMempool) ) )
    {
        (void)printf("circularqueueTestCycle1 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCycle1 1  -- FAIL \n");
    }

    for(uint32_t i = 0u; ( ( i <= 1000u ) && ( true == testOk ) ); i++)
    {
        if( CIRQ_RES_OK != CIRQ_InsertData(&ctx, insertData, sizeof(insertData) ) )
        {
            testOk = false;
        }

        if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData3, sizeof(retriveData3) ) )
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

        if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData4, sizeof(retriveData4) ) )
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
        (void)printf("circularqueueTestCycle1 2  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCycle1 2  -- FAIL \n");
    }
}

static void circularqueueTestCycle2(void)
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
    if( CIRQ_RES_OK == CIRQ_InitCtx(&ctx, pointerMempool, sizeof(pointerMempool) ) )
    {
        (void)printf("circularqueueTestCycle2 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCycle2 1  -- FAIL \n");
    }

    for(uint32_t i = 0u; ( ( i <= 1000u ) && ( true == testOk ) ); i++)
    {
        if( CIRQ_RES_OK != CIRQ_InsertData(&ctx, insertData, sizeof(insertData) ) )
        {
            testOk = false;
        }

        if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData3, sizeof(retriveData3) ) )
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

        if( CIRQ_RES_OK == CIRQ_RetriveData(&ctx, retriveData4, sizeof(retriveData4) ) )
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
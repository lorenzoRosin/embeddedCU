/**
 * @file       eCU_CIRQTST.c
 *
 * @brief      Circular queue test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCU_CIRQTST.h"
#include "eCU_CIRQ.h"
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
void eCU_CIRQTST_ExeTest(void)
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
    t_eCU_CIRQ_Ctx l_ctx;
    uint8_t  l_badPointerMempool[5u];
    uint32_t l_varTemp;
    bool_t l_isInit;

    /* Function */
    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_InitCtx(NULL, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 1  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_InitCtx(&l_ctx, NULL, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_Reset(NULL) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_GetFreeSapce(NULL, &l_varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_GetFreeSapce(&l_ctx, NULL) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_GetOccupiedSapce(NULL, &l_varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 6  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_GetOccupiedSapce(&l_ctx, NULL) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 7  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_InsertData(NULL, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 8  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_InsertData(&l_ctx, NULL, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 9  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_RetriveData(NULL, l_badPointerMempool, l_varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 10 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_RetriveData(&l_ctx, NULL, l_varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 11 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_PeekData(NULL, l_badPointerMempool, l_varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 12 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_PeekData(&l_ctx, NULL, l_varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 13 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_IsInit( NULL, &l_isInit ) )
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadPointer 14 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_IsInit( &l_ctx, NULL ) )
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
    t_eCU_CIRQ_Ctx l_ctx;
    uint8_t  l_badPointerMempool[5u];
    uint32_t l_varTemp;
    bool_t l_isInit;

    /* Init variable */
    l_ctx.bIsInit = true;

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 1  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_GetFreeSapce(&l_ctx, &l_varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_GetOccupiedSapce(&l_ctx, &l_varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_InsertData(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_RetriveData(&l_ctx, l_badPointerMempool, l_varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 6  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_PeekData(&l_ctx, l_badPointerMempool, l_varTemp) )
    {
        (void)printf("eCU_TEST_circularqueueBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadInit 7  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_IsInit( &l_ctx, &l_isInit ) )
    {
        if( false == l_isInit )
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
    t_eCU_CIRQ_Ctx l_ctx;
    uint8_t  l_badPointerMempool[5u];
    bool_t l_isInit;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CIRQ_RES_BADPARAM == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, 0u) )
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 1  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPARAM == eCU_CIRQ_InsertData(&l_ctx, l_badPointerMempool, 0u) )
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPARAM == eCU_CIRQ_RetriveData(&l_ctx, l_badPointerMempool, 0u) )
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPARAM == eCU_CIRQ_PeekData(&l_ctx, l_badPointerMempool, 0u) )
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueBadParamEntr 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_IsInit( &l_ctx, &l_isInit ) )
    {
        if( true == l_isInit )
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
    t_eCU_CIRQ_Ctx l_ctx;
    uint8_t  l_badPointerMempool[5u];
    uint32_t l_val;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 1  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 2  -- FAIL \n");
    }


    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 3  -- FAIL \n");
    }

    l_ctx.puBuff = NULL;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 4  -- FAIL \n");
    }


    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 5  -- FAIL \n");
    }

    l_ctx.uBuffFreeIdx = sizeof(l_badPointerMempool) +1u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 6  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 5  -- FAIL \n");
    }

    l_ctx.uBuffUsedL = sizeof(l_badPointerMempool) +1u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 6  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 7  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_GetFreeSapce(&l_ctx, &l_val) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 8  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 9  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_GetOccupiedSapce(&l_ctx, &l_val) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 10 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 11 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_InsertData(&l_ctx, l_badPointerMempool, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 12 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 13 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_RetriveData(&l_ctx, l_badPointerMempool, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 14 -- FAIL \n");
    }


    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCorruptedContext 15 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_PeekData(&l_ctx, l_badPointerMempool, 1u) )
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
    t_eCU_CIRQ_Ctx l_ctx;
    uint8_t  l_badPointerMempool[5u];
    uint8_t  la_retriveData[10u];

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Easy one  */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 1  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 6  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 7  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 8  -- FAIL \n");
    }

    /* most complete one */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 9  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 10 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 11 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 12 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, 2u ) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 13 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, 3u ) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 14 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 15 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueEmptyMem 16 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, 1u) )
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
    t_eCU_CIRQ_Ctx l_ctx;
    uint8_t  l_badPointerMempool[5u];
    uint8_t  la_retriveData[10u];

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Easy one  */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 1  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_FULL == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_FULL == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool) +1u ) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_FULL == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, 1u ) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 1u) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 6  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_FULL == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, 2u ) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 7  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, 4u) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 8  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, 5u) )
    {
        (void)printf("eCU_TEST_circularqueueFullMem 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueFullMem 9  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 4u) )
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
    t_eCU_CIRQ_Ctx l_ctx;
    uint8_t  la_pointerMempool[10u];
    uint32_t l_varTemp;
    uint8_t  la_retriveData[10u] = {0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u};
    uint8_t  la_insertData[10u]  = {0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u};

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Easy one  */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, la_pointerMempool, sizeof(la_pointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 1  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_GetFreeSapce(&l_ctx, &l_varTemp) )
    {
        if( 10u == l_varTemp )
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

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_GetOccupiedSapce(&l_ctx, &l_varTemp) )
    {
        if( 0u == l_varTemp )
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

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_insertData, sizeof(la_insertData) ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_GetFreeSapce(&l_ctx, &l_varTemp) )
    {
        if( 0u == l_varTemp )
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

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_GetOccupiedSapce(&l_ctx, &l_varTemp) )
    {
        if( 10u == l_varTemp )
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

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        if( 0 == memcmp(la_insertData, la_retriveData, sizeof(la_retriveData) ) )
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

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 7u ) )
    {
        if( 0 == memcmp(la_insertData, la_retriveData, 7u ) )
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

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_insertData, 2u ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 9  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 5u ) )
    {
        if( 0 == memcmp(&la_insertData[7], la_retriveData, 3u ) )
        {
            if( 0 == memcmp(&la_insertData[0], &la_retriveData[3u], 2u ) )
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

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 11 -- FAIL \n");
    }

    /* Easy one  */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, la_pointerMempool, sizeof(la_pointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 12 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_insertData, sizeof(la_insertData) ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 13 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 5u ) )
    {
        if( 0 == memcmp(la_insertData, la_retriveData, 5u ) )
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


    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_insertData, 5u ) )
    {
        (void)printf("eCU_TEST_circularqueueGeneric 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueGeneric 15 -- FAIL \n");
    }


    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        if( 0 == memcmp(&la_insertData[5u], la_retriveData, 5u ) )
        {
            if( 0 == memcmp(la_insertData, &la_retriveData[5], 5u ) )
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
    t_eCU_CIRQ_Ctx l_ctx;
    uint8_t  la_pointerMempool[10u];
    uint8_t  la_retriveData3[3u] = {0u};
    uint8_t  la_retriveData4[4u] = {0u};
    uint8_t  la_insertData[7u]  = {0u, 1u, 2u, 3u, 4u, 5u, 6u};
    bool_t   l_testOk = true;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Test */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, la_pointerMempool, sizeof(la_pointerMempool) ) )
    {
        (void)printf("eCU_TEST_circularqueueCycle1 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_circularqueueCycle1 1  -- FAIL \n");
    }

    for(uint32_t i = 0u; ( ( i <= 1000u ) && ( true == l_testOk ) ); i++)
    {
        if( e_eCU_CIRQ_RES_OK != eCU_CIRQ_InsertData(&l_ctx, la_insertData, sizeof(la_insertData) ) )
        {
            l_testOk = false;
        }

        if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData3, sizeof(la_retriveData3) ) )
        {
            if( 0 != memcmp(la_insertData, la_retriveData3, sizeof(la_retriveData3) ) )
            {
                l_testOk = false;
            }
        }
        else
        {
            l_testOk = false;
        }

        if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData4, sizeof(la_retriveData4) ) )
        {
            if( 0 != memcmp(&la_insertData[3], la_retriveData4, sizeof(la_retriveData4) ) )
            {
                l_testOk = false;
            }
        }
        else
        {
            l_testOk = false;
        }
    }

    if( true == l_testOk )
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
    t_eCU_CIRQ_Ctx l_ctx;
    uint8_t  la_pointerMempool[10u];
    uint8_t  la_retriveData3[1u] = {0u};
    uint8_t  la_retriveData4[1u] = {0u};
    uint8_t  la_insertData[2u]  = {1u, 1u};
    bool_t   l_testOk = true;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Test */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, la_pointerMempool, sizeof(la_pointerMempool) ) )
    {
        (void)printf("circularqueueTestCycle2 1  -- OK \n");
    }
    else
    {
        (void)printf("circularqueueTestCycle2 1  -- FAIL \n");
    }

    for(uint32_t i = 0u; ( ( i <= 1000u ) && ( true == l_testOk ) ); i++)
    {
        if( e_eCU_CIRQ_RES_OK != eCU_CIRQ_InsertData(&l_ctx, la_insertData, sizeof(la_insertData) ) )
        {
            l_testOk = false;
        }

        if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData3, sizeof(la_retriveData3) ) )
        {
            if( 0 != memcmp(la_insertData, la_retriveData3, sizeof(la_retriveData3) ) )
            {
                l_testOk = false;
            }
        }
        else
        {
            l_testOk = false;
        }

        if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData4, sizeof(la_retriveData4) ) )
        {
            if( 0 != memcmp(la_insertData, la_retriveData4, sizeof(la_retriveData4) ) )
            {
                l_testOk = false;
            }
        }
        else
        {
            l_testOk = false;
        }
    }

    if( true == l_testOk )
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
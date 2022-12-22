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
static void eCU_CIRQTST_BadPointer(void);
static void eCU_CIRQTST_BadInit(void);
static void eCU_CIRQTST_BadParamEntr(void);
static void eCU_CIRQTST_CorruptedContext(void);
static void eCU_CIRQTST_EmptyMem(void);
static void eCU_CIRQTST_FullMem(void);
static void eCU_CIRQTST_Generic(void);
static void eCU_CIRQTST_Cycle1(void);
static void eCU_CIRQTST_Cycle2(void);

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_CIRQTST_ExeTest(void)
{
	(void)printf("\n\nCIRCULAR QUEUE TEST START \n\n");

    eCU_CIRQTST_BadPointer();
    eCU_CIRQTST_BadInit();
    eCU_CIRQTST_BadParamEntr();
    eCU_CIRQTST_CorruptedContext();
    eCU_CIRQTST_EmptyMem();
    eCU_CIRQTST_FullMem();
    eCU_CIRQTST_Generic();
    eCU_CIRQTST_Cycle1();
    eCU_CIRQTST_Cycle2();

    (void)printf("\n\nCIRCULAR QUEUE TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_CIRQTST_BadPointer(void)
{
    /* Local variable */
    t_eCU_CIRQ_Ctx l_ctx;
    uint8_t  l_badPointerMempool[5u];
    uint32_t l_varTemp;
    bool_t l_isInit;

    /* Function */
    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_InitCtx(NULL, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 1  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_InitCtx(&l_ctx, NULL, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_Reset(NULL) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_GetFreeSapce(NULL, &l_varTemp) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_GetFreeSapce(&l_ctx, NULL) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_GetOccupiedSapce(NULL, &l_varTemp) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 6  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_GetOccupiedSapce(&l_ctx, NULL) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 7  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_InsertData(NULL, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 8  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_InsertData(&l_ctx, NULL, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 9  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_RetriveData(NULL, l_badPointerMempool, l_varTemp) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 10 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_RetriveData(&l_ctx, NULL, l_varTemp) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 11 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_PeekData(NULL, l_badPointerMempool, l_varTemp) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 12 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_PeekData(&l_ctx, NULL, l_varTemp) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 13 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_IsInit( NULL, &l_isInit ) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 14 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPOINTER == eCU_CIRQ_IsInit( &l_ctx, NULL ) )
    {
        (void)printf("eCU_CIRQTST_BadPointer 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadPointer 15 -- FAIL \n");
    }
}

static void eCU_CIRQTST_BadInit(void)
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
        (void)printf("eCU_CIRQTST_BadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadInit 1  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_CIRQTST_BadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadInit 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_GetFreeSapce(&l_ctx, &l_varTemp) )
    {
        (void)printf("eCU_CIRQTST_BadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadInit 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_GetOccupiedSapce(&l_ctx, &l_varTemp) )
    {
        (void)printf("eCU_CIRQTST_BadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadInit 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_InsertData(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_BadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadInit 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_RetriveData(&l_ctx, l_badPointerMempool, l_varTemp) )
    {
        (void)printf("eCU_CIRQTST_BadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadInit 6  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_NOINITLIB == eCU_CIRQ_PeekData(&l_ctx, l_badPointerMempool, l_varTemp) )
    {
        (void)printf("eCU_CIRQTST_BadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadInit 7  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_IsInit( &l_ctx, &l_isInit ) )
    {
        if( false == l_isInit )
        {
            (void)printf("eCU_CIRQTST_BadInit 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CIRQTST_BadInit 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadInit 8  -- FAIL \n");
    }
}

static void eCU_CIRQTST_BadParamEntr(void)
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
        (void)printf("eCU_CIRQTST_BadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadParamEntr 1  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_BadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadParamEntr 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPARAM == eCU_CIRQ_InsertData(&l_ctx, l_badPointerMempool, 0u) )
    {
        (void)printf("eCU_CIRQTST_BadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadParamEntr 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPARAM == eCU_CIRQ_RetriveData(&l_ctx, l_badPointerMempool, 0u) )
    {
        (void)printf("eCU_CIRQTST_BadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadParamEntr 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_BADPARAM == eCU_CIRQ_PeekData(&l_ctx, l_badPointerMempool, 0u) )
    {
        (void)printf("eCU_CIRQTST_BadParamEntr 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadParamEntr 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_IsInit( &l_ctx, &l_isInit ) )
    {
        if( true == l_isInit )
        {
            (void)printf("eCU_CIRQTST_BadParamEntr 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CIRQTST_BadParamEntr 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_BadParamEntr 6  -- FAIL \n");
    }
}

static void eCU_CIRQTST_CorruptedContext(void)
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
        (void)printf("eCU_CIRQTST_CorruptedContext 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 1  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 2  -- FAIL \n");
    }


    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 3  -- FAIL \n");
    }

    l_ctx.puBuff = NULL;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 4  -- FAIL \n");
    }


    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 5  -- FAIL \n");
    }

    l_ctx.uBuffFreeIdx = sizeof(l_badPointerMempool) +1u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 6  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 5  -- FAIL \n");
    }

    l_ctx.uBuffUsedL = sizeof(l_badPointerMempool) +1u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 6  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 7  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_GetFreeSapce(&l_ctx, &l_val) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 8  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 9  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_GetOccupiedSapce(&l_ctx, &l_val) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 10 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 11 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_InsertData(&l_ctx, l_badPointerMempool, 1u) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 12 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 13 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_RetriveData(&l_ctx, l_badPointerMempool, 1u) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 14 -- FAIL \n");
    }


    /* Function */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, l_badPointerMempool, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 15 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uBuffL = 0u;

    if( e_eCU_CIRQ_RES_CORRUPTCTX == eCU_CIRQ_PeekData(&l_ctx, l_badPointerMempool, 1u) )
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_CorruptedContext 16 -- FAIL \n");
    }

}

static void eCU_CIRQTST_EmptyMem(void)
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
        (void)printf("eCU_CIRQTST_EmptyMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 1  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, 1u) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 1u) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 6  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool) ) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 7  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 8  -- FAIL \n");
    }

    /* most complete one */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool) ) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 9  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 10 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 11 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 1u) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 12 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, 2u ) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 13 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, 3u ) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 14 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 15 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool)) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 16 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, 1u) )
    {
        (void)printf("eCU_CIRQTST_EmptyMem 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_EmptyMem 17 -- FAIL \n");
    }
}

static void eCU_CIRQTST_FullMem(void)
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
        (void)printf("eCU_CIRQTST_FullMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_FullMem 1  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_FULL == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        (void)printf("eCU_CIRQTST_FullMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_FullMem 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_FULL == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool) +1u ) )
    {
        (void)printf("eCU_CIRQTST_FullMem 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_FullMem 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, sizeof(l_badPointerMempool) ) )
    {
        (void)printf("eCU_CIRQTST_FullMem 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_FullMem 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_FULL == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, 1u ) )
    {
        (void)printf("eCU_CIRQTST_FullMem 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_FullMem 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 1u) )
    {
        (void)printf("eCU_CIRQTST_FullMem 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_FullMem 6  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_FULL == eCU_CIRQ_InsertData(&l_ctx, la_retriveData, 2u ) )
    {
        (void)printf("eCU_CIRQTST_FullMem 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_FullMem 7  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, 4u) )
    {
        (void)printf("eCU_CIRQTST_FullMem 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_FullMem 8  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_EMPTY == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, 5u) )
    {
        (void)printf("eCU_CIRQTST_FullMem 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_FullMem 9  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 4u) )
    {
        (void)printf("eCU_CIRQTST_FullMem 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_FullMem 10 -- FAIL \n");
    }
}

static void eCU_CIRQTST_Generic(void)
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
        (void)printf("eCU_CIRQTST_Generic 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 1  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_GetFreeSapce(&l_ctx, &l_varTemp) )
    {
        if( 10u == l_varTemp )
        {
            (void)printf("eCU_CIRQTST_Generic 2  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CIRQTST_Generic 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 2  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_GetOccupiedSapce(&l_ctx, &l_varTemp) )
    {
        if( 0u == l_varTemp )
        {
            (void)printf("eCU_CIRQTST_Generic 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CIRQTST_Generic 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 3  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_insertData, sizeof(la_insertData) ) )
    {
        (void)printf("eCU_CIRQTST_Generic 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 4  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_GetFreeSapce(&l_ctx, &l_varTemp) )
    {
        if( 0u == l_varTemp )
        {
            (void)printf("eCU_CIRQTST_Generic 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CIRQTST_Generic 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 5  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_GetOccupiedSapce(&l_ctx, &l_varTemp) )
    {
        if( 10u == l_varTemp )
        {
            (void)printf("eCU_CIRQTST_Generic 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CIRQTST_Generic 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 6  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        if( 0 == memcmp(la_insertData, la_retriveData, sizeof(la_retriveData) ) )
        {
            (void)printf("eCU_CIRQTST_Generic 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CIRQTST_Generic 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 7  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 7u ) )
    {
        if( 0 == memcmp(la_insertData, la_retriveData, 7u ) )
        {
            (void)printf("eCU_CIRQTST_Generic 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_CIRQTST_Generic 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 8  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_insertData, 2u ) )
    {
        (void)printf("eCU_CIRQTST_Generic 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 9  -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 5u ) )
    {
        if( 0 == memcmp(&la_insertData[7], la_retriveData, 3u ) )
        {
            if( 0 == memcmp(&la_insertData[0], &la_retriveData[3u], 2u ) )
            {
                (void)printf("eCU_CIRQTST_Generic 10 -- OK \n");
            }
            else
            {
                (void)printf("eCU_CIRQTST_Generic 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_CIRQTST_Generic 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 10 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_Reset(&l_ctx) )
    {
        (void)printf("eCU_CIRQTST_Generic 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 11 -- FAIL \n");
    }

    /* Easy one  */
    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InitCtx(&l_ctx, la_pointerMempool, sizeof(la_pointerMempool) ) )
    {
        (void)printf("eCU_CIRQTST_Generic 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 12 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_insertData, sizeof(la_insertData) ) )
    {
        (void)printf("eCU_CIRQTST_Generic 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 13 -- FAIL \n");
    }

    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_RetriveData(&l_ctx, la_retriveData, 5u ) )
    {
        if( 0 == memcmp(la_insertData, la_retriveData, 5u ) )
        {
            (void)printf("eCU_CIRQTST_Generic 14 -- OK \n");
        }
        else
        {
            (void)printf("eCU_CIRQTST_Generic 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 14 -- FAIL \n");
    }


    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_InsertData(&l_ctx, la_insertData, 5u ) )
    {
        (void)printf("eCU_CIRQTST_Generic 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 15 -- FAIL \n");
    }


    if( e_eCU_CIRQ_RES_OK == eCU_CIRQ_PeekData(&l_ctx, la_retriveData, sizeof(la_retriveData)) )
    {
        if( 0 == memcmp(&la_insertData[5u], la_retriveData, 5u ) )
        {
            if( 0 == memcmp(la_insertData, &la_retriveData[5], 5u ) )
            {
                (void)printf("eCU_CIRQTST_Generic 16 -- OK \n");
            }
            else
            {
                (void)printf("eCU_CIRQTST_Generic 16 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_CIRQTST_Generic 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_CIRQTST_Generic 16 -- FAIL \n");
    }

}

static void eCU_CIRQTST_Cycle1(void)
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
        (void)printf("eCU_CIRQTST_Cycle1 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_Cycle1 1  -- FAIL \n");
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
        (void)printf("eCU_CIRQTST_Cycle1 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_CIRQTST_Cycle1 2  -- FAIL \n");
    }
}

static void eCU_CIRQTST_Cycle2(void)
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
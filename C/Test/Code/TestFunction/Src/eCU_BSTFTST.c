/**
 * @file       eCU_BSTFTST.c
 *
 * @brief      Byte stuffer test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCU_BSTFTST.h"
#include "eCU_BSTF.h"
#include <stdio.h>

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "CERT-STR32-C"
    /* Suppressed for code clarity in test execution*/
#endif



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_BSTFTST_BadPointer(void);
static void eCU_BSTFTST_BadInit(void);
static void eCU_BSTFTST_BadInitFrame(void);
static void eCU_BSTFTST_BadParamEntr(void);
static void eCU_BSTFTST_CorrupterContext(void);
static void eCU_BSTFTST_OutOfMem(void);
static void eCU_BSTFTST_StartRestart(void);
static void eCU_BSTFTST_GetRemainings(void);
static void eCU_BSTFTST_General(void);
static void eCU_BSTFTST_GeneralAnother(void);
static void eCU_BSTFTST_Correcteness(void);

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_BSTFTST_ExeTest(void)
{
	(void)printf("\n\nBYTE STUFFER TEST START \n\n");

    eCU_BSTFTST_BadPointer();
    eCU_BSTFTST_BadInit();
    eCU_BSTFTST_BadInitFrame();
    eCU_BSTFTST_BadParamEntr();
    eCU_BSTFTST_CorrupterContext();
    eCU_BSTFTST_OutOfMem();
    eCU_BSTFTST_StartRestart();
    eCU_BSTFTST_GetRemainings();
    eCU_BSTFTST_General();
    eCU_BSTFTST_GeneralAnother();
    eCU_BSTFTST_Correcteness();

    (void)printf("\n\nBYTE STUFFER TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_BSTFTST_BadPointer(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint32_t l_varTemp32;
    uint8_t* lp_aPointer;
    bool_t l_isInit;


    /* Function */
    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_InitCtx(NULL, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_InitCtx(&l_ctx, NULL, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_NewFrame(NULL, 2u) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetWherePutData(NULL, &lp_aPointer, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetWherePutData(&l_ctx, NULL, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, NULL) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_RestartFrame(NULL) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetRemByteToGet(NULL, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 8  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetRemByteToGet(&l_ctx, NULL) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 9  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetStufChunk(NULL, la_memArea, sizeof(la_memArea), &l_varTemp32 ) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 10 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetStufChunk(&l_ctx, NULL, sizeof(la_memArea), &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetStufChunk(&l_ctx, la_memArea, sizeof(la_memArea), NULL) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 12 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_IsInit( NULL, &l_isInit ) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 13 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_IsInit( &l_ctx, NULL ) )
    {
        (void)printf("eCU_BSTFTST_BadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadPointer 14 -- FAIL \n");
    }
}

static void eCU_BSTFTST_BadInit(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint32_t l_varTemp32;
    uint8_t* lp_aPointer;
    bool_t l_isInit;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_BSTF_RES_NOINITLIB == eCU_BSTF_NewFrame(&l_ctx, 2u) )
    {
        (void)printf("eCU_BSTFTST_BadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInit 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITLIB == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_BadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInit 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITLIB == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_BSTFTST_BadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInit 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITLIB == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_BadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInit 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITLIB == eCU_BSTF_GetStufChunk(&l_ctx, la_memArea, sizeof(la_memArea), &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_BadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInit 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_IsInit( &l_ctx, &l_isInit ) )
    {
        if( false == l_isInit )
        {
            (void)printf("eCU_BSTFTST_BadInit 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_BadInit 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInit 6  -- FAIL \n");
    }

}

static void eCU_BSTFTST_BadInitFrame(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint32_t l_varTemp32;
    bool_t l_isInit;

    /* Init variable */
    l_ctx.bIsInit = false;
    (void)memset(la_memArea, 0, sizeof(la_memArea));

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITFRAME == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITFRAME == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITFRAME == eCU_BSTF_GetStufChunk(&l_ctx, la_memArea, sizeof(la_memArea), &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 2u) )
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_IsInit( &l_ctx, &l_isInit ) )
    {
        if( true == l_isInit )
        {
            (void)printf("eCU_BSTFTST_BadInitFrame 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_BadInitFrame 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadInitFrame 7  -- FAIL \n");
    }
}

static void eCU_BSTFTST_BadParamEntr(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint32_t l_varTemp32;

    /* Init variable */
    l_ctx.bIsInit = false;
    (void)memset(la_memArea, 0, sizeof(la_memArea));

    /* Function */
    if( e_eCU_BSTF_RES_BADPARAM == eCU_BSTF_InitCtx(&l_ctx, la_memArea, 0u) )
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPARAM == eCU_BSTF_NewFrame(&l_ctx, 0u) )
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPARAM == eCU_BSTF_NewFrame(&l_ctx, (sizeof(la_memArea) +1u) ) )
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPARAM == eCU_BSTF_GetStufChunk(&l_ctx, la_memArea, 0u, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_BadParamEntr 6  -- FAIL \n");
    }
}

static void eCU_BSTFTST_CorrupterContext(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint32_t l_varTemp32;
    uint8_t* lp_aPointerP;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 1  -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 2  -- FAIL \n");
    }


    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 3  -- FAIL \n");
    }

    l_ctx.puBuff = NULL;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 4  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 5  -- FAIL \n");
    }

    l_ctx.uFrameL = 2u;
    l_ctx.uFrameCtr = l_ctx.uFrameL + 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 6  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 7  -- FAIL \n");
    }

    l_ctx.uFrameL = l_ctx.uBuffL + 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 8  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 9  -- FAIL \n");
    }

    l_ctx.uFrameL = 2u;
    l_ctx.uFrameCtr = 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 10 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 11 -- FAIL \n");
    }

    l_ctx.uFrameCtr = 0u;
    l_ctx.eSM = e_eCU_BSTFPRV_SM_NEEDNEGATEPRECDATA;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 12 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 13 -- FAIL \n");
    }

    l_ctx.uFrameCtr = 0u;
    l_ctx.eSM = e_eCU_BSTFPRV_SM_NEEDEOF;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 14 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 15 -- FAIL \n");
    }

    l_ctx.uFrameCtr = 0u;
    l_ctx.eSM = e_eCU_BSTFPRV_SM_STUFFEND;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 16 -- FAIL \n");
    }

     /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 17 -- FAIL \n");
    }

    l_ctx.eSM = e_eCU_BSTFPRV_SM_STUFFEND;
    l_ctx.uFrameCtr = 1u;
    l_ctx.uFrameL = 2u;
    l_ctx.uBuffL = 3u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 18 -- FAIL \n");
    }

     /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 19 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 20 -- FAIL \n");
    }

    l_ctx.eSM = e_eCU_BSTFPRV_SM_NEEDNEGATEPRECDATA;
    l_ctx.uFrameCtr = 1u;
    la_memArea[l_ctx.uFrameCtr - 1u] = 0xFFu;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 21 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 22 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 22 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 23 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 23 -- FAIL \n");
    }


    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 24 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    l_ctx.uFrameL = 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 25 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 25 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 26 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 26 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    l_ctx.uFrameL = 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 27 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 27 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 28 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 28 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    l_ctx.uFrameL = 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_GetStufChunk(&l_ctx, la_memArea, 1u, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 29 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_CorrupterContext 29 -- FAIL \n");
    }
}

static void eCU_BSTFTST_OutOfMem(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint8_t  la_memAreaFinalChunk[50u];
    uint32_t l_varTemp32;
    uint32_t l_reman;
    uint8_t* lp_aPointer;

    /* Init variable */
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = ECU_ESC;
    la_memArea[3u] = 0x12u;
    la_memArea[4u] = 0xFFu;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_OutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITFRAME == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        (void)printf("eCU_BSTFTST_OutOfMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_BSTFTST_OutOfMem 3  -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_OutOfMem 3  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_OutOfMem 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 10u == l_reman )
        {
            (void)printf("eCU_BSTFTST_OutOfMem 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_BSTFTST_OutOfMem 6  -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_OutOfMem 6  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_OutOfMem 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[1], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_OutOfMem 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 8  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 8u == l_reman )
        {
            (void)printf("eCU_BSTFTST_OutOfMem 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 9  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_BSTFTST_OutOfMem 10 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_OutOfMem 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 10 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[2], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_OutOfMem 11 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[3], 7u, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_OutOfMem 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 12 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[10], 1u, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_OutOfMem 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 13 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 0u == l_reman )
        {
            (void)printf("eCU_BSTFTST_OutOfMem 14 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 14 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_BSTFTST_OutOfMem 15 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_OutOfMem 15 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_OutOfMem 15 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_OutOfMem 15 -- FAIL \n");
    }
}

static void eCU_BSTFTST_StartRestart(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint8_t  la_memAreaFinalChunk[50u];
    uint32_t l_varTemp32;
    uint32_t l_reman;
    uint8_t* lp_aPointer;

    /* Init variable */
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = ECU_ESC;
    la_memArea[3u] = 0x12u;
    la_memArea[4u] = 0xFFu;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_StartRestart 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITFRAME == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        (void)printf("eCU_BSTFTST_StartRestart 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_BSTFTST_StartRestart 3  -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_StartRestart 3  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_StartRestart 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 10u == l_reman )
        {
            (void)printf("eCU_BSTFTST_StartRestart 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_BSTFTST_StartRestart 6  -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_StartRestart 6  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_StartRestart 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_BSTFTST_StartRestart 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 8  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 10u == l_reman )
        {
            (void)printf("eCU_BSTFTST_StartRestart 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 9  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_BSTFTST_StartRestart 10 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_StartRestart 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 10 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_StartRestart 11 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[1], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_StartRestart 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 12 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 8u == l_reman )
        {
            (void)printf("eCU_BSTFTST_StartRestart 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 13 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_BSTFTST_StartRestart 14 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_StartRestart 14 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 14 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[2], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_StartRestart 15 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 15 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 15 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[3], 7u, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_StartRestart 16 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 16 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[10], 1u, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_StartRestart 17 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 17 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 17 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 0u == l_reman )
        {
            (void)printf("eCU_BSTFTST_StartRestart 18 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 18 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 18 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_BSTFTST_StartRestart 19 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_StartRestart 19 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_StartRestart 19 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_StartRestart 19 -- FAIL \n");
    }
}

static void eCU_BSTFTST_GetRemainings(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[5u];
    uint8_t  la_memAreaFinalChunk[50u];
    uint32_t l_varTemp32;
    uint8_t* lp_aPointer;

    /* Init variable */
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = ECU_ESC;
    la_memArea[3u] = 0x12u;
    la_memArea[4u] = 0xFFu;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_GetRemainings 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_GetRemainings 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 10u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 3  -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 4  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 9u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 5  -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[1], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[2], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 8  -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[3], 7u, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 9  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 10 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 10 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( ( sizeof(la_memArea) == l_varTemp32 ) && ( la_memArea == lp_aPointer))
        {
            (void)printf("eCU_BSTFTST_GetRemainings 11 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_BSTFTST_GetRemainings 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 12 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 10u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 3 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 14 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 14 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 9u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 15 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 15 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[1], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 16 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 16 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[2], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 17 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 17 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 17 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 18 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 18 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[3], 6u, &l_varTemp32) )
    {
        if( 6u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 19 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 19 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 19 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 20 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 20 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[9], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 21 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 21 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 21 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 22 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 22 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( ( sizeof(la_memArea) == l_varTemp32 ) && ( la_memArea == lp_aPointer))
        {
            (void)printf("eCU_BSTFTST_GetRemainings 23 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 23 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 23 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_BSTFTST_GetRemainings 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_GetRemainings 24 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 4u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GetRemainings 25 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GetRemainings 25 -- FAIL \n");
        }
    }
}

static void eCU_BSTFTST_General(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[4u];
    uint8_t  la_memAreaFinalChunk[50u];
    uint8_t  la_memAreaExpected[9u];
    uint32_t l_varTemp32;
    uint32_t l_counter;
    uint32_t l_remaining;
    e_eCU_BSTF_RES l_result = e_eCU_BSTF_RES_OK;
    uint8_t* lp_aPointer;

    /* Init variable */
    la_memAreaExpected[0u] = ECU_SOF;
    la_memAreaExpected[1u] = ECU_ESC;
    la_memAreaExpected[2u] = (uint8_t)~ECU_SOF;
    la_memAreaExpected[3u] = ECU_ESC;
    la_memAreaExpected[4u] = (uint8_t)~ECU_EOF;
    la_memAreaExpected[5u] = 0x12u;
    la_memAreaExpected[6u] = ECU_ESC;
    la_memAreaExpected[7u] = (uint8_t)~ECU_ESC;
    la_memAreaExpected[8u] = ECU_EOF;

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 2  -- FAIL \n");
    }

    l_varTemp32 = 0u;
    l_counter = 0u;

    while( e_eCU_BSTF_RES_OK == l_result )
    {
        l_result = eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 1u, &l_varTemp32);
        if( ( e_eCU_BSTF_RES_FRAMEENDED == l_result) || ( e_eCU_BSTF_RES_OK == l_result) )
        {
            if(l_varTemp32 <= sizeof(la_memAreaFinalChunk))
            {
                l_counter += l_varTemp32;
            }
            else
            {
                l_result = e_eCU_BSTF_RES_BADPARAM;
            }
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == l_result )
    {
        (void)printf("eCU_BSTFTST_General 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 3  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_General 4  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 4  -- FAIL \n");
    }

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 5  -- FAIL \n");
    }

    l_result = e_eCU_BSTF_RES_OK;
    l_varTemp32 = 0u;
    l_counter = 0u;

    while( e_eCU_BSTF_RES_OK == l_result )
    {
        l_result = eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 2u, &l_varTemp32);
        if( ( e_eCU_BSTF_RES_FRAMEENDED == l_result) || ( e_eCU_BSTF_RES_OK == l_result) )
        {
            l_counter += l_varTemp32;
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == l_result )
    {
        (void)printf("eCU_BSTFTST_General 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 6  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_General 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 7  -- FAIL \n");
    }

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 8  -- FAIL \n");
    }

    l_result = e_eCU_BSTF_RES_OK;
    l_varTemp32 = 0u;
    l_counter = 0u;

    while( e_eCU_BSTF_RES_OK == l_result )
    {
        l_result = eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 3u, &l_varTemp32);
        if( ( e_eCU_BSTF_RES_FRAMEENDED == l_result) || ( e_eCU_BSTF_RES_OK == l_result) )
        {
            l_counter += l_varTemp32;
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == l_result )
    {
        (void)printf("eCU_BSTFTST_General 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 9  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_General 10 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 10 -- FAIL \n");
    }


    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 11 -- FAIL \n");
    }

    l_result = e_eCU_BSTF_RES_OK;
    l_varTemp32 = 0u;
    l_counter = 0u;

    while( e_eCU_BSTF_RES_OK == l_result )
    {
        l_result = eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 4u, &l_varTemp32);
        if( ( e_eCU_BSTF_RES_FRAMEENDED == l_result) || ( e_eCU_BSTF_RES_OK == l_result) )
        {
            l_counter += l_varTemp32;
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == l_result )
    {
        (void)printf("eCU_BSTFTST_General 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 12 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_General 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 13 -- FAIL \n");
    }



    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 14 -- FAIL \n");
    }

    l_result = e_eCU_BSTF_RES_OK;
    l_varTemp32 = 0u;
    l_counter = 0u;

    while( e_eCU_BSTF_RES_OK == l_result )
    {
        l_result = eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 5u, &l_varTemp32);
        if( ( e_eCU_BSTF_RES_FRAMEENDED == l_result) || ( e_eCU_BSTF_RES_OK == l_result) )
        {
            l_counter += l_varTemp32;
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == l_result )
    {
        (void)printf("eCU_BSTFTST_General 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 15 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_General 16 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 16 -- FAIL \n");
    }


    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 17 -- FAIL \n");
    }

    l_result = e_eCU_BSTF_RES_OK;
    l_varTemp32 = 0u;
    l_counter = 0u;

    while( e_eCU_BSTF_RES_OK == l_result )
    {
        l_result = eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 6u, &l_varTemp32);
        if( ( e_eCU_BSTF_RES_FRAMEENDED == l_result) || ( e_eCU_BSTF_RES_OK == l_result) )
        {
            l_counter += l_varTemp32;
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == l_result )
    {
        (void)printf("eCU_BSTFTST_General 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 18 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_General 19 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 19 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 19 -- FAIL \n");
    }



    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 20 -- FAIL \n");
    }

    l_result = e_eCU_BSTF_RES_OK;
    l_varTemp32 = 0u;
    l_counter = 0u;

    while( e_eCU_BSTF_RES_OK == l_result )
    {
        l_result = eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 7u, &l_varTemp32);
        if( ( e_eCU_BSTF_RES_FRAMEENDED == l_result) || ( e_eCU_BSTF_RES_OK == l_result) )
        {
            l_counter += l_varTemp32;
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == l_result )
    {
        (void)printf("eCU_BSTFTST_General 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 21 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_General 22 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 22 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 22 -- FAIL \n");
    }




    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 23 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 23 -- FAIL \n");
    }

    l_result = e_eCU_BSTF_RES_OK;
    l_varTemp32 = 0u;
    l_counter = 0u;

    while( e_eCU_BSTF_RES_OK == l_result )
    {
        l_result = eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 8u, &l_varTemp32);
        if( ( e_eCU_BSTF_RES_FRAMEENDED == l_result) || ( e_eCU_BSTF_RES_OK == l_result) )
        {
            l_counter += l_varTemp32;
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == l_result )
    {
        (void)printf("eCU_BSTFTST_General 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 24 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_General 25 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 25 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 25 -- FAIL \n");
    }


    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 26 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 26 -- FAIL \n");
    }

    l_result = e_eCU_BSTF_RES_OK;
    l_varTemp32 = 0u;
    l_counter = 0u;

    while( e_eCU_BSTF_RES_OK == l_result )
    {
        l_result = eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 9u, &l_varTemp32);
        if( ( e_eCU_BSTF_RES_FRAMEENDED == l_result) || ( e_eCU_BSTF_RES_OK == l_result) )
        {
            l_counter += l_varTemp32;
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == l_result )
    {
        (void)printf("eCU_BSTFTST_General 27 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 27 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_General 28 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 28 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 28 -- FAIL \n");
    }



    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 29 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 29 -- FAIL \n");
    }

    l_varTemp32 = 0u;
    l_counter = 0u;
    l_remaining = 0u;

    l_result = eCU_BSTF_GetRemByteToGet(&l_ctx, &l_remaining);
    if( e_eCU_BSTF_RES_OK == l_result )
    {
        if( 9u == l_remaining )
        {
            (void)printf("eCU_BSTFTST_General 30 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 30 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 30 -- FAIL \n");
    }



    while( ( e_eCU_BSTF_RES_OK == l_result ) && ( 0u != l_remaining ) )
    {
        l_result = eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 10u, &l_varTemp32);
        if( ( e_eCU_BSTF_RES_FRAMEENDED == l_result) || ( e_eCU_BSTF_RES_OK == l_result) )
        {
            l_counter += l_varTemp32;
        }

        l_result = eCU_BSTF_GetRemByteToGet(&l_ctx, &l_remaining);
    }

    if( e_eCU_BSTF_RES_OK == l_result )
    {
        (void)printf("eCU_BSTFTST_General 31 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 31 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_General 32 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 32 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 32 -- FAIL \n");
    }

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_ESC;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_General 33 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 33 -- FAIL \n");
    }

    l_varTemp32 = 0u;
    l_counter = 0u;
    l_remaining = 0u;


    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 2u, &l_varTemp32) )
    {
        (void)printf("eCU_BSTFTST_General 34 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 34 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_remaining) )
    {
        if( 7u == l_remaining )
        {
            (void)printf("eCU_BSTFTST_General 35 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 35 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 35 -- FAIL \n");
    }


    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_BSTFTST_General 36 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 36 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( ( sizeof(la_memArea) == l_varTemp32 ) && ( la_memArea == lp_aPointer))
        {
            (void)printf("eCU_BSTFTST_General 37 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_General 37 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_General 37 -- FAIL \n");
    }
}

static void eCU_BSTFTST_GeneralAnother(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[4u];
    uint8_t  la_memAreaFinalChunk[50u];
    uint8_t  la_memAreaExpected[9u];
    uint32_t l_varTemp32;
    uint32_t l_counter;

    /* Init variable */
    la_memAreaExpected[0u] = ECU_SOF;
    la_memAreaExpected[1u] = ECU_ESC;
    la_memAreaExpected[2u] = (uint8_t)~ECU_SOF;
    la_memAreaExpected[3u] = ECU_ESC;
    la_memAreaExpected[4u] = (uint8_t)~ECU_EOF;
    la_memAreaExpected[5u] = 0x12u;
    la_memAreaExpected[6u] = ECU_ESC;
    la_memAreaExpected[7u] = (uint8_t)~ECU_ESC;
    la_memAreaExpected[8u] = ECU_EOF;

    /* Init variable */
    l_counter = 0u;
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 9u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 1u, &l_varTemp32) )
    {
        l_counter += l_varTemp32;
        if( 1u == l_varTemp32 )
        {
            if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
            {
                if( 8u == l_varTemp32 )
                {
                    (void)printf("eCU_BSTFTST_GeneralAnother 4  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_BSTFTST_GeneralAnother 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 7u, &l_varTemp32) )
    {
        l_counter += l_varTemp32;
        if( 7u == l_varTemp32 )
        {
            if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
            {
                if( 1u == l_varTemp32 )
                {
                    (void)printf("eCU_BSTFTST_GeneralAnother 3  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_BSTFTST_GeneralAnother 3  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 3  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 7u, &l_varTemp32) )
    {
        l_counter += l_varTemp32;
        if( 1u == l_varTemp32 )
        {
            if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
            {
                if( 0u == l_varTemp32 )
                {
                    (void)printf("eCU_BSTFTST_GeneralAnother 4  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_BSTFTST_GeneralAnother 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 4  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother   -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 5  -- FAIL \n");
    }

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;


    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 4u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 8  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ECU_SOF == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 9  -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 9  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 9  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 3u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 10 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 10 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ECU_ESC == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 11 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 11 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 2u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 12 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ((uint8_t)~ECU_SOF) == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 13 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 13 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 13 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 14 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 14 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ECU_EOF == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 15 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 15 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 15 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 15 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 16 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 16 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 17 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 17 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 17 -- FAIL \n");
    }

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = 0x12u;


    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 18 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 19 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 3u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 20 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 20 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 20 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ECU_SOF == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 21 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 21 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 21 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 21 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 2u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 22 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 22 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 22 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( 0x12u == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 23 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 23 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 23 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 23 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 24 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 24 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 24 -- FAIL \n");
    }


    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ECU_EOF == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 25 -- OK \n");
            }
            else
            {
                (void)printf("eCU_BSTFTST_GeneralAnother 25 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 25 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 25 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 26 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 26 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 26 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 27 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_GeneralAnother 27 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_GeneralAnother 27 -- FAIL \n");
    }
}

static void eCU_BSTFTST_Correcteness(void)
{
    /* Local variable */
    t_eCU_BSTF_Ctx l_ctx;
    uint8_t  la_memArea[4u];
    uint8_t  la_memAreaFinalChunk[50u];
    uint8_t  la_memAreaExpected[9u];
    uint32_t l_varTemp32;

    /* Init variable */
    la_memAreaExpected[0u] = ECU_SOF;
    la_memAreaExpected[1u] = ECU_ESC;
    la_memAreaExpected[2u] = (uint8_t)~ECU_SOF;
    la_memAreaExpected[3u] = ECU_ESC;
    la_memAreaExpected[4u] = (uint8_t)~ECU_EOF;
    la_memAreaExpected[5u] = 0x12u;
    la_memAreaExpected[6u] = ECU_ESC;
    la_memAreaExpected[7u] = (uint8_t)~ECU_ESC;
    la_memAreaExpected[8u] = ECU_EOF;

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;
    la_memArea[1u] = ECU_EOF;
    la_memArea[2u] = 0x12u;
    la_memArea[3u] = ECU_ESC;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_Correcteness 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_Correcteness 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], sizeof(la_memAreaFinalChunk), &l_varTemp32) )
    {
        if( 9u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_Correcteness 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_Correcteness 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 3  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, 9u) )
    {
        (void)printf("eCU_BSTFTST_Correcteness 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 5  -- FAIL \n");
    }

    /* Init variable */
    la_memAreaExpected[0u] = ECU_SOF;
    la_memAreaExpected[1u] = 0xFFu;
    la_memAreaExpected[2u] = 0xFFu;
    la_memAreaExpected[3u] = 0xFFu;
    la_memAreaExpected[4u] = 0xFFu;
    la_memAreaExpected[5u] = ECU_EOF;

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = 0xFFu;
    la_memArea[1u] = 0xFFu;
    la_memArea[2u] = 0xFFu;
    la_memArea[3u] = 0xFFu;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_Correcteness 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_Correcteness 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], sizeof(la_memAreaFinalChunk), &l_varTemp32) )
    {
        if( 6u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_Correcteness 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_Correcteness 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 8  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, 6u) )
    {
        (void)printf("eCU_BSTFTST_Correcteness 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 9  -- FAIL \n");
    }

    /* Init variable */
    la_memAreaExpected[0u] = ECU_SOF;
    la_memAreaExpected[1u] = 0xFFu;
    la_memAreaExpected[2u] = 0xFFu;
    la_memAreaExpected[3u] = 0xFFu;
    la_memAreaExpected[4u] = ECU_ESC;
    la_memAreaExpected[5u] = (uint8_t)~ECU_SOF;;
    la_memAreaExpected[6u] = ECU_EOF;

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = 0xFFu;
    la_memArea[1u] = 0xFFu;
    la_memArea[2u] = 0xFFu;
    la_memArea[3u] = ECU_SOF;

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_Correcteness 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 10 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_BSTFTST_Correcteness 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], sizeof(la_memAreaFinalChunk), &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_BSTFTST_Correcteness 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_BSTFTST_Correcteness 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 12 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, 7u) )
    {
        (void)printf("eCU_BSTFTST_Correcteness 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_BSTFTST_Correcteness 13 -- FAIL \n");
    }


}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "CERT-STR32-C"
#endif
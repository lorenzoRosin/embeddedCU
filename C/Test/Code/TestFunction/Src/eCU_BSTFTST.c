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
static void eCU_TEST_byteStuffBadPointer(void);
static void eCU_TEST_byteStuffBadInit(void);
static void eCU_TEST_byteStuffBadIniFrame(void);
static void eCU_TEST_byteStuffBadParamEntr(void);
static void eCU_TEST_byteStuffCorrupterContext(void);
static void eCU_TEST_byteStuffOutOfMem(void);
static void eCU_TEST_byteStuffStartRestart(void);
static void eCU_TEST_byteStuffGetRemainings(void);
static void eCU_TEST_byteStuffGeneral(void);
static void eCU_TEST_byteStuffGeneralAnother(void);
static void eCU_TEST_byteStuffCorrecteness(void);

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_BSTFTST_ExeTest(void)
{
	(void)printf("\n\nBYTE STUFFER TEST START \n\n");

    eCU_TEST_byteStuffBadPointer();
    eCU_TEST_byteStuffBadInit();
    eCU_TEST_byteStuffBadIniFrame();
    eCU_TEST_byteStuffBadParamEntr();
    eCU_TEST_byteStuffCorrupterContext();
    eCU_TEST_byteStuffOutOfMem();
    eCU_TEST_byteStuffStartRestart();
    eCU_TEST_byteStuffGetRemainings();
    eCU_TEST_byteStuffGeneral();
    eCU_TEST_byteStuffGeneralAnother();
    eCU_TEST_byteStuffCorrecteness();

    (void)printf("\n\nBYTE STUFFER TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_TEST_byteStuffBadPointer(void)
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
        (void)printf("eCU_TEST_byteStuffBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_InitCtx(&l_ctx, NULL, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_NewFrame(NULL, 2u) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetWherePutData(NULL, &lp_aPointer, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetWherePutData(&l_ctx, NULL, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, NULL) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_RestartFrame(NULL) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetRemByteToGet(NULL, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 8  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetRemByteToGet(&l_ctx, NULL) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 9  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetStufChunk(NULL, la_memArea, sizeof(la_memArea), &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 10 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetStufChunk(&l_ctx, NULL, sizeof(la_memArea), &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_GetStufChunk(&l_ctx, la_memArea, sizeof(la_memArea), NULL) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 12 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_IsInit( NULL, &l_isInit ) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 13 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPOINTER == eCU_BSTF_IsInit( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 14 -- FAIL \n");
    }
}

static void eCU_TEST_byteStuffBadInit(void)
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
        (void)printf("eCU_TEST_byteStuffBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITLIB == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITLIB == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteStuffBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITLIB == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITLIB == eCU_BSTF_GetStufChunk(&l_ctx, la_memArea, sizeof(la_memArea), &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_IsInit( &l_ctx, &l_isInit ) )
    {
        if( false == l_isInit )
        {
            (void)printf("eCU_TEST_byteStuffBadInit 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffBadInit 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 6  -- FAIL \n");
    }

}

static void eCU_TEST_byteStuffBadIniFrame(void)
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
        (void)printf("eCU_TEST_byteStuffBadIniFrame 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITFRAME == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITFRAME == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITFRAME == eCU_BSTF_GetStufChunk(&l_ctx, la_memArea, sizeof(la_memArea), &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 2u) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_IsInit( &l_ctx, &l_isInit ) )
    {
        if( true == l_isInit )
        {
            (void)printf("eCU_TEST_byteStuffBadIniFrame 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffBadIniFrame 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 7  -- FAIL \n");
    }
}

static void eCU_TEST_byteStuffBadParamEntr(void)
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
        (void)printf("eCU_TEST_byteStuffBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPARAM == eCU_BSTF_NewFrame(&l_ctx, 0u) )
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPARAM == eCU_BSTF_NewFrame(&l_ctx, (sizeof(la_memArea) +1u) ) )
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_BADPARAM == eCU_BSTF_GetStufChunk(&l_ctx, la_memArea, 0u, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 6  -- FAIL \n");
    }
}

static void eCU_TEST_byteStuffCorrupterContext(void)
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
        (void)printf("eCU_TEST_byteStuffCorrupterContext 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 1  -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 2  -- FAIL \n");
    }


    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 3  -- FAIL \n");
    }

    l_ctx.puBuff = NULL;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 4  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 5  -- FAIL \n");
    }

    l_ctx.uFrameL = 2u;
    l_ctx.uFrameCtr = l_ctx.uFrameL + 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 6  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 7  -- FAIL \n");
    }

    l_ctx.uFrameL = l_ctx.uBuffL + 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 8  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 9  -- FAIL \n");
    }

    l_ctx.uFrameL = 2u;
    l_ctx.uFrameCtr = 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 10 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 11 -- FAIL \n");
    }

    l_ctx.uFrameCtr = 0u;
    l_ctx.eSM = e_eCU_BSTFPRV_SM_NEEDNEGATEPRECDATA;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 12 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 13 -- FAIL \n");
    }

    l_ctx.uFrameCtr = 0u;
    l_ctx.eSM = e_eCU_BSTFPRV_SM_NEEDEOF;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 14 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 15 -- FAIL \n");
    }

    l_ctx.uFrameCtr = 0u;
    l_ctx.eSM = e_eCU_BSTFPRV_SM_STUFFEND;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 16 -- FAIL \n");
    }

     /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 17 -- FAIL \n");
    }

    l_ctx.eSM = e_eCU_BSTFPRV_SM_STUFFEND;
    l_ctx.uFrameCtr = 1u;
    l_ctx.uFrameL = 2u;
    l_ctx.uBuffL = 3u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 18 -- FAIL \n");
    }

     /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 19 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 20 -- FAIL \n");
    }

    l_ctx.eSM = e_eCU_BSTFPRV_SM_NEEDNEGATEPRECDATA;
    l_ctx.uFrameCtr = 1u;
    la_memArea[l_ctx.uFrameCtr - 1u] = 0xFFu;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 21 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 22 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 22 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointerP, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 23 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 23 -- FAIL \n");
    }


    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 24 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    l_ctx.uFrameL = 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 25 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 25 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 26 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 26 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    l_ctx.uFrameL = 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 27 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 27 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 28 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 28 -- FAIL \n");
    }

    l_ctx.uBuffL = 0u;
    l_ctx.uFrameL = 1u;
    if( e_eCU_BSTF_RES_CORRUPTCTX == eCU_BSTF_GetStufChunk(&l_ctx, la_memArea, 1u, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 29 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 29 -- FAIL \n");
    }
}

static void eCU_TEST_byteStuffOutOfMem(void)
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
        (void)printf("eCU_TEST_byteStuffOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITFRAME == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_TEST_byteStuffOutOfMem 3  -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffOutOfMem 3  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 10u == l_reman )
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_TEST_byteStuffOutOfMem 6  -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffOutOfMem 6  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[1], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 8  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 8u == l_reman )
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 9  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_TEST_byteStuffOutOfMem 10 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffOutOfMem 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 10 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[2], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 11 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[3], 7u, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 12 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[10], 1u, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 13 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 0u == l_reman )
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 14 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 14 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_TEST_byteStuffOutOfMem 15 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffOutOfMem 15 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffOutOfMem 15 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 15 -- FAIL \n");
    }
}

static void eCU_TEST_byteStuffStartRestart(void)
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
        (void)printf("eCU_TEST_byteStuffStartRestart 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_NOINITFRAME == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_TEST_byteStuffStartRestart 3  -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffStartRestart 3  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 3  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 10u == l_reman )
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 5  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_TEST_byteStuffStartRestart 6  -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffStartRestart 6  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 8  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 10u == l_reman )
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 9  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_TEST_byteStuffStartRestart 10 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffStartRestart 10 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 10 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 11 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[1], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 12 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 8u == l_reman )
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 13 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_TEST_byteStuffStartRestart 14 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffStartRestart 14 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 14 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[2], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 15 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 15 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 15 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[3], 7u, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 16 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 16 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[10], 1u, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 17 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 17 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 17 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_reman) )
    {
        if( 0u == l_reman )
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 18 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 18 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 18 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( la_memArea == lp_aPointer )
        {
            if( sizeof(la_memArea) == l_varTemp32 )
            {
                (void)printf("eCU_TEST_byteStuffStartRestart 19 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffStartRestart 19 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffStartRestart 19 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 19 -- FAIL \n");
    }
}

static void eCU_TEST_byteStuffGetRemainings(void)
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
        (void)printf("eCU_TEST_byteStuffGetRemainings 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 10u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 3  -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 4  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 4  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 9u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 5  -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[1], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[2], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 8  -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[3], 7u, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 9  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 10 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 10 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( ( sizeof(la_memArea) == l_varTemp32 ) && ( la_memArea == lp_aPointer))
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 11 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_RestartFrame(&l_ctx) )
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 12 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 10u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 3 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 14 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 14 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 9u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 15 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 15 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[1], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 16 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 16 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[2], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 17 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 17 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 17 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 18 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 18 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[3], 6u, &l_varTemp32) )
    {
        if( 6u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 19 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 19 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 19 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 20 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 20 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[9], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 21 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 21 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 21 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 22 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 22 -- FAIL \n");
        }
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( ( sizeof(la_memArea) == l_varTemp32 ) && ( la_memArea == lp_aPointer))
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 23 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 23 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 23 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 24 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 4u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 25 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 25 -- FAIL \n");
        }
    }
}

static void eCU_TEST_byteStuffGeneral(void)
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
        (void)printf("eCU_TEST_byteStuffGeneral 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 2  -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 3  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 4  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 4  -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 5  -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 6  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 7  -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 8  -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 9  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 10 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 10 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 11 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 12 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 13 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 14 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 15 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 16 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 16 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 17 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 18 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 19 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 19 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 19 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 20 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 21 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 22 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 22 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 22 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 23 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 23 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 24 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 25 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 25 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 25 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 26 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 26 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 27 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 27 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 28 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 28 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 28 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 29 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 29 -- FAIL \n");
    }

    l_varTemp32 = 0u;
    l_counter = 0u;
    l_remaining = 0u;

    l_result = eCU_BSTF_GetRemByteToGet(&l_ctx, &l_remaining);
    if( e_eCU_BSTF_RES_OK == l_result )
    {
        if( 9u == l_remaining )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 30 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 30 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 30 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 31 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 31 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 32 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 32 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 32 -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffGeneral 33 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 33 -- FAIL \n");
    }

    l_varTemp32 = 0u;
    l_counter = 0u;
    l_remaining = 0u;


    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[l_counter], 2u, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 34 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 34 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_remaining) )
    {
        if( 7u == l_remaining )
        {
            (void)printf("eCU_TEST_byteStuffGeneral 35 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 35 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 35 -- FAIL \n");
    }


    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 36 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 36 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctx, &lp_aPointer, &l_varTemp32) )
    {
        if( ( sizeof(la_memArea) == l_varTemp32 ) && ( la_memArea == lp_aPointer))
        {
            (void)printf("eCU_TEST_byteStuffGeneral 37 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneral 37 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 37 -- FAIL \n");
    }
}

static void eCU_TEST_byteStuffGeneralAnother(void)
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
        (void)printf("eCU_TEST_byteStuffGeneralAnother 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 9u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 3  -- FAIL \n");
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
                    (void)printf("eCU_TEST_byteStuffGeneralAnother 4  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_byteStuffGeneralAnother 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 4  -- FAIL \n");
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
                    (void)printf("eCU_TEST_byteStuffGeneralAnother 3  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_byteStuffGeneralAnother 3  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 3  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 3  -- FAIL \n");
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
                    (void)printf("eCU_TEST_byteStuffGeneralAnother 4  -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_byteStuffGeneralAnother 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 4  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, l_counter) )
    {
        if( sizeof(la_memAreaExpected) == l_counter )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother   -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 5  -- FAIL \n");
    }

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = ECU_SOF;


    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 4u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 8  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ECU_SOF == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 9  -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 9  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 9  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 3u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 10 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 10 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ECU_ESC == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 11 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 11 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 2u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 12 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ((uint8_t)~ECU_SOF) == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 13 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 13 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 13 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 14 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 14 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ECU_EOF == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 15 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 15 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 15 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 15 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 16 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 16 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 16 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 17 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 17 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 17 -- FAIL \n");
    }

    /* Init variable */
    (void)memset(la_memAreaFinalChunk, 0, sizeof(la_memAreaFinalChunk));
    la_memArea[0u] = 0x12u;


    /* Function */
    if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctx, la_memArea, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 18 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 19 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 3u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 20 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 20 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 20 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ECU_SOF == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 21 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 21 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 21 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 21 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 2u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 22 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 22 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 22 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( 0x12u == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 23 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 23 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 23 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 23 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 24 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 24 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 24 -- FAIL \n");
    }


    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            if( ECU_EOF == la_memAreaFinalChunk[0u] )
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 25 -- OK \n");
            }
            else
            {
                (void)printf("eCU_TEST_byteStuffGeneralAnother 25 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 25 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 25 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&l_ctx, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 26 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 26 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 26 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0u], 1u, &l_varTemp32) )
    {
        if( 0u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 27 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGeneralAnother 27 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 27 -- FAIL \n");
    }
}

static void eCU_TEST_byteStuffCorrecteness(void)
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
        (void)printf("eCU_TEST_byteStuffCorrecteness 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 1  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 2  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], sizeof(la_memAreaFinalChunk), &l_varTemp32) )
    {
        if( 9u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffCorrecteness 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffCorrecteness 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 3  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, 9u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 5  -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffCorrecteness 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 6  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 7  -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], sizeof(la_memAreaFinalChunk), &l_varTemp32) )
    {
        if( 6u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffCorrecteness 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffCorrecteness 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 8  -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, 6u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 9  -- FAIL \n");
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
        (void)printf("eCU_TEST_byteStuffCorrecteness 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 10 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctx, sizeof(la_memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 11 -- FAIL \n");
    }

    if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctx, &la_memAreaFinalChunk[0], sizeof(la_memAreaFinalChunk), &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffCorrecteness 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffCorrecteness 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 12 -- FAIL \n");
    }

    if( 0 == memcmp(la_memAreaExpected, la_memAreaFinalChunk, 7u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 13 -- FAIL \n");
    }


}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "CERT-STR32-C"
#endif
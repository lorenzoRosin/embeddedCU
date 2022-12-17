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
#include <stdio.h>

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2012-Rule-10.3", "CERT-STR32-C"
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
void eCU_TEST_byteStuffer(void)
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
    s_eCU_BSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t* pointer;
    bool_t isInit;


    /* Function */
    if( BSTF_RES_BADPOINTER == eCU_BSTF_InitCtx(NULL, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 1  -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_InitCtx(&ctx, NULL, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 2  -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_NewFrame(NULL, 2u) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 3  -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_GetWherePutData(NULL, &pointer, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 4  -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_GetWherePutData(&ctx, NULL, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 5  -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_GetWherePutData(&ctx, &pointer, NULL) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 6  -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_RestartFrame(NULL) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 7  -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_GetRemByteToGet(NULL, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 8  -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_GetRemByteToGet(&ctx, NULL) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 9  -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_GetStufChunk(NULL, memArea, sizeof(memArea), &varTemp32 ) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 10 -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_GetStufChunk(&ctx, NULL, sizeof(memArea), &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 11 -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_GetStufChunk(&ctx, memArea, sizeof(memArea), NULL) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 12 -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_IsInit( NULL, &isInit ) )
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadPointer 13 -- FAIL \n");
    }

    if( BSTF_RES_BADPOINTER == eCU_BSTF_IsInit( &ctx, NULL ) )
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
    s_eCU_BSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t* pointer;
    bool_t isInit;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( BSTF_RES_NOINITLIB == eCU_BSTF_NewFrame(&ctx, 2u) )
    {
        (void)printf("eCU_TEST_byteStuffBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 1  -- FAIL \n");
    }

    if( BSTF_RES_NOINITLIB == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 2  -- FAIL \n");
    }

    if( BSTF_RES_NOINITLIB == eCU_BSTF_RestartFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteStuffBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 3  -- FAIL \n");
    }

    if( BSTF_RES_NOINITLIB == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 4  -- FAIL \n");
    }

    if( BSTF_RES_NOINITLIB == eCU_BSTF_GetStufChunk(&ctx, memArea, sizeof(memArea), &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadInit 5  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_IsInit( &ctx, &isInit ) )
    {
        if( false == isInit )
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
    s_eCU_BSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    bool_t isInit;

    /* Init variable */
    ctx.isInit = false;
    (void)memset(memArea, 0, sizeof(memArea));

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 1  -- FAIL \n");
    }

    if( BSTF_RES_NOINITFRAME == eCU_BSTF_RestartFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 2  -- FAIL \n");
    }

    if( BSTF_RES_NOINITFRAME == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 3  -- FAIL \n");
    }

    if( BSTF_RES_NOINITFRAME == eCU_BSTF_GetStufChunk(&ctx, memArea, sizeof(memArea), &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 4  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, 2u) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 5  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_RestartFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadIniFrame 6  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_IsInit( &ctx, &isInit ) )
    {
        if( true == isInit )
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
    s_eCU_BSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;

    /* Init variable */
    ctx.isInit = false;
    (void)memset(memArea, 0, sizeof(memArea));

    /* Function */
    if( BSTF_RES_BADPARAM == eCU_BSTF_InitCtx(&ctx, memArea, 0u) )
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 1  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 2  -- FAIL \n");
    }

    if( BSTF_RES_BADPARAM == eCU_BSTF_NewFrame(&ctx, 0u) )
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 3  -- FAIL \n");
    }

    if( BSTF_RES_BADPARAM == eCU_BSTF_NewFrame(&ctx, (sizeof(memArea) +1u) ) )
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 4  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffBadParamEntr 5  -- FAIL \n");
    }

    if( BSTF_RES_BADPARAM == eCU_BSTF_GetStufChunk(&ctx, memArea, 0u, &varTemp32) )
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
    s_eCU_BSTF_Ctx ctx;
    uint8_t  memArea[5u];
    uint32_t varTemp32;
    uint8_t* dataP;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 1  -- FAIL \n");
    }

    ctx.memASize = 0u;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 2  -- FAIL \n");
    }


    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 3  -- FAIL \n");
    }

    ctx.p_memA = NULL;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 4  -- FAIL \n");
    }

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 5  -- FAIL \n");
    }

    ctx.memAFrameSize = 2u;
    ctx.memACtr = ctx.memAFrameSize + 1u;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 6  -- FAIL \n");
    }

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 7  -- FAIL \n");
    }

    ctx.memAFrameSize = ctx.memASize + 1u;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 8  -- FAIL \n");
    }

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 9  -- FAIL \n");
    }

    ctx.memAFrameSize = BSTF_SM_PRV_NEEDSOF;
    ctx.memAFrameSize = 2u;
    ctx.memACtr = 1u;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 10 -- FAIL \n");
    }

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 11 -- FAIL \n");
    }

    ctx.memACtr = 0u;
    ctx.stuffState = BSTF_SM_PRV_NEEDNEGATEPRECDATA;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 12 -- FAIL \n");
    }

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 13 -- FAIL \n");
    }

    ctx.memACtr = 0u;
    ctx.stuffState = BSTF_SM_PRV_NEEDEOF;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 14 -- FAIL \n");
    }

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 15 -- FAIL \n");
    }

    ctx.memACtr = 0u;
    ctx.stuffState = BSTF_SM_PRV_STUFFEND;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 16 -- FAIL \n");
    }

     /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 17 -- FAIL \n");
    }

    ctx.stuffState = BSTF_SM_PRV_STUFFEND;
    ctx.memACtr = 1u;
    ctx.memAFrameSize = 2u;
    ctx.memASize = 3u;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 18 -- FAIL \n");
    }

     /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 19 -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 20 -- FAIL \n");
    }

    ctx.stuffState = BSTF_SM_PRV_NEEDNEGATEPRECDATA;
    ctx.memACtr = 1u;
    memArea[ctx.memACtr - 1u] = 0xFFu;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_NewFrame(&ctx, 4u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 21 -- FAIL \n");
    }

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 22 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 22 -- FAIL \n");
    }

    ctx.memASize = 0u;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_GetWherePutData(&ctx, &dataP, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 23 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 23 -- FAIL \n");
    }


    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 24 -- FAIL \n");
    }

    ctx.memASize = 0u;
    ctx.memAFrameSize = 1u;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_RestartFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 25 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 25 -- FAIL \n");
    }

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 26 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 26 -- FAIL \n");
    }

    ctx.memASize = 0u;
    ctx.memAFrameSize = 1u;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 27 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 27 -- FAIL \n");
    }

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 28 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrupterContext 28 -- FAIL \n");
    }

    ctx.memASize = 0u;
    ctx.memAFrameSize = 1u;
    if( BSTF_RES_CORRUPTCTX == eCU_BSTF_GetStufChunk(&ctx, memArea, 1u, &varTemp32) )
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
    s_eCU_BSTF_Ctx ctx;
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
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 1  -- FAIL \n");
    }

    if( BSTF_RES_NOINITFRAME == eCU_BSTF_GetRemByteToGet(&ctx, &reman) )
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 2  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffOutOfMem 4  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &reman) )
    {
        if( 10u == reman )
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

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[1], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &reman) )
    {
        if( 8u == reman )
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

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[2], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[3], 7u, &varTemp32) )
    {
        if( 7u == varTemp32 )
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

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[10], 1u, &varTemp32) )
    {
        if( 0u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &reman) )
    {
        if( 0u == reman )
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

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
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
    s_eCU_BSTF_Ctx ctx;
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
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 1  -- FAIL \n");
    }

    if( BSTF_RES_NOINITFRAME == eCU_BSTF_GetRemByteToGet(&ctx, &reman) )
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 2  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 4  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &reman) )
    {
        if( 10u == reman )
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

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_RestartFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffStartRestart 8  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &reman) )
    {
        if( 10u == reman )
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

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[1], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &reman) )
    {
        if( 8u == reman )
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

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[2], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[3], 7u, &varTemp32) )
    {
        if( 7u == varTemp32 )
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

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[10], 1u, &varTemp32) )
    {
        if( 0u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &reman) )
    {
        if( 0u == reman )
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

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( memArea == pointer )
        {
            if( sizeof(memArea) == varTemp32 )
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
    s_eCU_BSTF_Ctx ctx;
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
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 1  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 2  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 10u == varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 3  -- FAIL \n");
        }
    }

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 9u == varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 5  -- FAIL \n");
        }
    }

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[1], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[2], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 7u == varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 8  -- FAIL \n");
        }
    }

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[3], 7u, &varTemp32) )
    {
        if( 7u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 0u == varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 10 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 10 -- FAIL \n");
        }
    }

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( ( sizeof(memArea) == varTemp32 ) && ( memArea == pointer))
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

    if( BSTF_RES_OK == eCU_BSTF_RestartFrame(&ctx) )
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 12 -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 10u == varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 3 -- FAIL \n");
        }
    }

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 9u == varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 15 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 15 -- FAIL \n");
        }
    }

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[1], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[2], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 7u == varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 18 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 18 -- FAIL \n");
        }
    }

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[3], 6u, &varTemp32) )
    {
        if( 6u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 20 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 20 -- FAIL \n");
        }
    }

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[9], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 0u == varTemp32 )
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 22 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_byteStuffGetRemainings 22 -- FAIL \n");
        }
    }

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( ( sizeof(memArea) == varTemp32 ) && ( memArea == pointer))
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

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, 1u) )
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGetRemainings 24 -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 4u == varTemp32 )
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
    s_eCU_BSTF_Ctx ctx;
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
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 1  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 2  -- FAIL \n");
    }

    e_eCU_BSTF_Res result = BSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( BSTF_RES_OK == result )
    {
        result = eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 1u, &varTemp32);
        if( ( BSTF_RES_FRAMEENDED == result) || ( BSTF_RES_OK == result) )
        {
            if(varTemp32 <= sizeof(memAreaFinalChunk))
            {
                counter += varTemp32;
            }
            else
            {
                result = BSTF_RES_BADPARAM;
            }
        }
    }

    if( BSTF_RES_FRAMEENDED == result )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 3  -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 5  -- FAIL \n");
    }

    result = BSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( BSTF_RES_OK == result )
    {
        result = eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 2u, &varTemp32);
        if( ( BSTF_RES_FRAMEENDED == result) || ( BSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( BSTF_RES_FRAMEENDED == result )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 6  -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 8  -- FAIL \n");
    }

    result = BSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( BSTF_RES_OK == result )
    {
        result = eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 3u, &varTemp32);
        if( ( BSTF_RES_FRAMEENDED == result) || ( BSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( BSTF_RES_FRAMEENDED == result )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 9  -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 11 -- FAIL \n");
    }

    result = BSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( BSTF_RES_OK == result )
    {
        result = eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 4u, &varTemp32);
        if( ( BSTF_RES_FRAMEENDED == result) || ( BSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( BSTF_RES_FRAMEENDED == result )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 12 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 14 -- FAIL \n");
    }

    result = BSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( BSTF_RES_OK == result )
    {
        result = eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 5u, &varTemp32);
        if( ( BSTF_RES_FRAMEENDED == result) || ( BSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( BSTF_RES_FRAMEENDED == result )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 15 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 17 -- FAIL \n");
    }

    result = BSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( BSTF_RES_OK == result )
    {
        result = eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 6u, &varTemp32);
        if( ( BSTF_RES_FRAMEENDED == result) || ( BSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( BSTF_RES_FRAMEENDED == result )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 18 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 20 -- FAIL \n");
    }

    result = BSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( BSTF_RES_OK == result )
    {
        result = eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 7u, &varTemp32);
        if( ( BSTF_RES_FRAMEENDED == result) || ( BSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( BSTF_RES_FRAMEENDED == result )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 21 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 23 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 23 -- FAIL \n");
    }

    result = BSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( BSTF_RES_OK == result )
    {
        result = eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 8u, &varTemp32);
        if( ( BSTF_RES_FRAMEENDED == result) || ( BSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( BSTF_RES_FRAMEENDED == result )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 24 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 26 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 26 -- FAIL \n");
    }

    result = BSTF_RES_OK;
    varTemp32 = 0u;
    counter = 0u;

    while( BSTF_RES_OK == result )
    {
        result = eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 9u, &varTemp32);
        if( ( BSTF_RES_FRAMEENDED == result) || ( BSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }
    }

    if( BSTF_RES_FRAMEENDED == result )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 27 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 27 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_EOF;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 29 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 29 -- FAIL \n");
    }

    varTemp32 = 0u;
    counter = 0u;
    remaining = 0u;

    result = eCU_BSTF_GetRemByteToGet(&ctx, &remaining);
    if( BSTF_RES_OK == result )
    {
        if( 9u == remaining )
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



    while( ( BSTF_RES_OK == result ) && ( 0u != remaining ) )
    {
        result = eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 10u, &varTemp32);
        if( ( BSTF_RES_FRAMEENDED == result) || ( BSTF_RES_OK == result) )
        {
            counter += varTemp32;
        }

        result = eCU_BSTF_GetRemByteToGet(&ctx, &remaining);
    }

    if( BSTF_RES_OK == result )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 31 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 31 -- FAIL \n");
    }

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;
    memArea[1u] = ECU_ESC;
    memArea[2u] = 0x12u;
    memArea[3u] = ECU_ESC;

    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 33 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 33 -- FAIL \n");
    }

    varTemp32 = 0u;
    counter = 0u;
    remaining = 0u;


    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 2u, &varTemp32) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 34 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 34 -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &remaining) )
    {
        if( 7u == remaining )
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


    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, 1u) )
    {
        (void)printf("eCU_TEST_byteStuffGeneral 36 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneral 36 -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctx, &pointer, &varTemp32) )
    {
        if( ( sizeof(memArea) == varTemp32 ) && ( memArea == pointer))
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
    s_eCU_BSTF_Ctx ctx;
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
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 1  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 2  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 9u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 1u, &varTemp32) )
    {
        counter += varTemp32;
        if( 1u == varTemp32 )
        {
            if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
            {
                if( 8u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 7u, &varTemp32) )
    {
        counter += varTemp32;
        if( 7u == varTemp32 )
        {
            if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
            {
                if( 1u == varTemp32 )
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

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[counter], 7u, &varTemp32) )
    {
        counter += varTemp32;
        if( 1u == varTemp32 )
        {
            if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
            {
                if( 0u == varTemp32 )
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

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, counter) )
    {
        if( sizeof(memAreaExpected) == counter )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = ECU_SOF;


    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 6  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, 1u) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 7  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 4u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ECU_SOF == memAreaFinalChunk[0u] )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 3u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ECU_ESC == memAreaFinalChunk[0u] )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 2u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ((uint8_t)~ECU_SOF) == memAreaFinalChunk[0u] )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 1u == varTemp32 )
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

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ECU_EOF == memAreaFinalChunk[0u] )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 0u == varTemp32 )
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

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 0u == varTemp32 )
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
    (void)memset(memAreaFinalChunk, 0, sizeof(memAreaFinalChunk));
    memArea[0u] = 0x12u;


    /* Function */
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 18 -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, 1u) )
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffGeneralAnother 19 -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 3u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ECU_SOF == memAreaFinalChunk[0u] )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 2u == varTemp32 )
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

    if( BSTF_RES_OK == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( 0x12u == memAreaFinalChunk[0u] )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 1u == varTemp32 )
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


    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 1u == varTemp32 )
        {
            if( ECU_EOF == memAreaFinalChunk[0u] )
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

    if( BSTF_RES_OK == eCU_BSTF_GetRemByteToGet(&ctx, &varTemp32) )
    {
        if( 0u == varTemp32 )
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

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0u], 1u, &varTemp32) )
    {
        if( 0u == varTemp32 )
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
    s_eCU_BSTF_Ctx ctx;
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
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 1  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 2  -- FAIL \n");
    }

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0], sizeof(memAreaFinalChunk), &varTemp32) )
    {
        if( 9u == varTemp32 )
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

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, 9u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 5  -- FAIL \n");
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
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 6  -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 7  -- FAIL \n");
    }

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0], sizeof(memAreaFinalChunk), &varTemp32) )
    {
        if( 6u == varTemp32 )
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

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, 6u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 9  -- FAIL \n");
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
    if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctx, memArea, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 10 -- FAIL \n");
    }

    if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctx, sizeof(memArea)) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 11 -- FAIL \n");
    }

    if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctx, &memAreaFinalChunk[0], sizeof(memAreaFinalChunk), &varTemp32) )
    {
        if( 7u == varTemp32 )
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

    if( 0 == memcmp(memAreaExpected, memAreaFinalChunk, 7u) )
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_byteStuffCorrecteness 13 -- FAIL \n");
    }


}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2012-Rule-10.3", "CERT-STR32-C"
#endif
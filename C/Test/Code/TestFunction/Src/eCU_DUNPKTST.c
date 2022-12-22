/**
 * @file       eCU_DUNPKTST.c
 *
 * @brief      Data unpack test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCU_DUNPKTST.h"
#include "eCU_DUNPK.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_TEST_dataUnPackBadPointer(void);
static void eCU_TEST_dataUnPackBadInit(void);
static void eCU_TEST_dataUnPackBadInitSession(void);
static void eCU_TEST_dataUnPackBadParamEntr(void);
static void eCU_TEST_dataUnPackCorruptContext(void);
static void eCU_TEST_dataUnPackOutOfMem(void);
static void eCU_TEST_dataUnPackEndianLe(void);
static void eCU_TEST_dataUnPackEndianBe(void);
static void eCU_TEST_dataUnPackCycle(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_DUNPKTST_ExeTest(void)
{
	(void)printf("\n\nDATA UNPACK TEST START \n\n");

    eCU_TEST_dataUnPackBadPointer();
    eCU_TEST_dataUnPackBadInit();
    eCU_TEST_dataUnPackBadInitSession();
    eCU_TEST_dataUnPackBadParamEntr();
    eCU_TEST_dataUnPackCorruptContext();
    eCU_TEST_dataUnPackOutOfMem();
    eCU_TEST_dataUnPackEndianLe();
    eCU_TEST_dataUnPackEndianBe();
    eCU_TEST_dataUnPackCycle();

    (void)printf("\n\nDATA UNPACK END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_TEST_dataUnPackBadPointer(void)
{
    /* Local variable */
    t_eCU_DUNPK_Ctx l_ctx;
    uint8_t  la_badPointerMempool[5u];
    uint8_t* lp_tempPo;
    uint64_t l_varTemp64;
    uint32_t l_varTemp32;
    uint16_t l_varTemp16;
    uint8_t  l_varTemp8;
    bool_t l_isInit;

    /* Function */
    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_InitCtx(NULL, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 1  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_InitCtx(&l_ctx, NULL, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 2  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_StartNewFrame(NULL, 3u) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 3  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_GetUPkDataLocat( NULL, &lp_tempPo, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 4  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_GetUPkDataLocat( &l_ctx, NULL, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 5  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_GetUPkDataLocat( &l_ctx, &lp_tempPo, NULL) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 6  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_RestartCurrentUnpack( NULL ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 7  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_GetRemToPop( NULL, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 8  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_GetRemToPop( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 9  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_PopArray( NULL, la_badPointerMempool, sizeof(la_badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 10 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_PopArray( &l_ctx, NULL, sizeof(la_badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 11 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_PopU8( NULL, &l_varTemp8 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 12 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_PopU8( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 13 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_PopU16( NULL, &l_varTemp16 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 14 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_PopU16( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 15 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_PopU32( NULL, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 16 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_PopU32( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 17 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_PopU64( NULL, &l_varTemp64 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 18 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_PopU64( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 19 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_IsInit( NULL, &l_isInit ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 20 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPOINTER == eCU_DUNPK_IsInit( &l_ctx, NULL ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadPointer 21 -- FAIL \n");
    }
}

static void eCU_TEST_dataUnPackBadInit(void)
{
    /* Local variable */
    t_eCU_DUNPK_Ctx l_ctx;
    uint8_t  la_badPointerMempool[5u];
    uint8_t* lp_tempPo;
    uint64_t l_varTemp64;
    uint32_t l_varTemp32;
    uint16_t l_varTemp16;
    uint8_t  l_varTemp8;
    bool_t l_isInit;

    /* Init variable */
    l_ctx.bIsInit = true;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 1  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    if( e_eCU_DUNPK_RES_NOINITLIB == eCU_DUNPK_StartNewFrame( &l_ctx, 1u ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 2  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITLIB == eCU_DUNPK_GetUPkDataLocat( &l_ctx, &lp_tempPo, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 3  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITLIB == eCU_DUNPK_RestartCurrentUnpack( &l_ctx ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 4  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITLIB == eCU_DUNPK_GetRemToPop( &l_ctx, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 5  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITLIB == eCU_DUNPK_PopArray( &l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool) ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 6  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITLIB == eCU_DUNPK_PopU8( &l_ctx, &l_varTemp8 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 7  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITLIB == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 8  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITLIB == eCU_DUNPK_PopU32( &l_ctx, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 9  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITLIB == eCU_DUNPK_PopU64( &l_ctx, &l_varTemp64 ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 10 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_IsInit( &l_ctx, &l_isInit ) )
    {
        if( false == l_isInit )
        {
            (void)printf("eCU_TEST_dataUnPackBadInit 11 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackBadInit 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInit 11 -- FAIL \n");
    }
}

static void eCU_TEST_dataUnPackBadInitSession(void)
{
    /* Local variable */
    t_eCU_DUNPK_Ctx l_ctx;
    uint8_t  la_badPointerMempool[5u];
    uint64_t l_varTemp64;
    uint32_t l_varTemp32;
    uint16_t l_varTemp16;
    uint8_t  l_varTemp8;
    bool_t l_isInit;

    /* Init variable */
    l_ctx.bIsInit = true;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 1  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITFRAME == eCU_DUNPK_RestartCurrentUnpack( &l_ctx  ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 2  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITFRAME == eCU_DUNPK_GetRemToPop( &l_ctx, &l_varTemp32  ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 3  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITFRAME == eCU_DUNPK_PopArray( &l_ctx, la_badPointerMempool, 2u  ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 4  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITFRAME == eCU_DUNPK_PopU8( &l_ctx, &l_varTemp8  ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 5  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITFRAME == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16  ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 6  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITFRAME == eCU_DUNPK_PopU32( &l_ctx, &l_varTemp32  ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 7  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NOINITFRAME == eCU_DUNPK_PopU64( &l_ctx, &l_varTemp64  ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 8  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_IsInit( &l_ctx, &l_isInit ) )
    {
        if( true == l_isInit )
        {
            (void)printf("eCU_TEST_dataUnPackBadInitSession 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackBadInitSession 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadInitSession 9  -- FAIL \n");
    }
}

static void eCU_TEST_dataUnPackBadParamEntr(void)
{
    /* Local variable */
    t_eCU_DUNPK_Ctx l_ctx;
    uint8_t  la_badPointerMempool[5u];

    /* Init variable */
    l_ctx.bIsInit = false;
    (void)memset(la_badPointerMempool, 0, sizeof(la_badPointerMempool));

    /* Function */
    if( e_eCU_DUNPK_RES_BADPARAM == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, 0u, true) )
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 1  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 2  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPARAM == eCU_DUNPK_StartNewFrame( &l_ctx, 0u ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 3  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPARAM == eCU_DUNPK_StartNewFrame( &l_ctx, ( sizeof(la_badPointerMempool) + 1u ) ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 4  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame( &l_ctx, 2u ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 5  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_BADPARAM == eCU_DUNPK_PopArray( &l_ctx, la_badPointerMempool, 0u ) )
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackBadParamEntr 6  -- FAIL \n");
    }
}

static void eCU_TEST_dataUnPackCorruptContext(void)
{
    /* Local variable */
    t_eCU_DUNPK_Ctx l_ctx;
    uint8_t  la_badPointerMempool[5u];
    uint8_t* lp_tempPo;
    uint32_t l_varTemp;
    uint8_t  l_varTemp8;
    uint16_t l_varTemp16;
    uint32_t l_varTemp32;
    uint64_t l_varTemp64;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 1  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKL = 0u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_StartNewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 2  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 3  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.puMemUPK = NULL;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_StartNewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 4  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 5  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKFrameL = l_ctx.uMemUPKL + 1u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_StartNewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 6  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 7  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKFrameL = l_ctx.uMemUPKL - 2u;
    l_ctx.uMemUPKCtr = l_ctx.uMemUPKFrameL + 1u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_StartNewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 8  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 9  -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKFrameL = 1u;
    l_ctx.uMemUPKL = 0u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_GetUPkDataLocat( &l_ctx, &lp_tempPo, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 10 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 11 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKFrameL = 1u;
    l_ctx.uMemUPKL = 0u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_RestartCurrentUnpack(&l_ctx) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 12 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 13 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKFrameL = 1u;
    l_ctx.uMemUPKL = 0u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_GetRemToPop(&l_ctx, &l_varTemp) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 14 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 15 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKFrameL = 1u;
    l_ctx.uMemUPKL = 0u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_PopArray(&l_ctx, la_badPointerMempool, 1u) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 16 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 17 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKFrameL = 1u;
    l_ctx.uMemUPKL = 0u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_PopU8(&l_ctx, &l_varTemp8) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 18 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 19 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKFrameL = 1u;
    l_ctx.uMemUPKL = 0u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_PopU16(&l_ctx, &l_varTemp16) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 20 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 21 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKFrameL = 1u;
    l_ctx.uMemUPKL = 0u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_PopU32(&l_ctx, &l_varTemp32) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 22 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 22 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 23 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 23 -- FAIL \n");
    }

    /* Init variable */
    l_ctx.uMemUPKFrameL = 1u;
    l_ctx.uMemUPKL = 0u;

    if( e_eCU_DUNPK_RES_CORRUPTCTX == eCU_DUNPK_PopU64(&l_ctx, &l_varTemp64) )
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCorruptContext 24 -- FAIL \n");
    }
}

static void eCU_TEST_dataUnPackOutOfMem(void)
{
    /* Local variable */
    t_eCU_DUNPK_Ctx l_ctx;
    uint8_t  la_badPointerMempool[9u];
    uint8_t  la_pushPool[5u];
    uint64_t l_varTemp64;
    uint32_t l_varTemp32;
    uint16_t l_varTemp16;
    uint8_t  l_varTemp8;
    uint8_t* lp_tempPo;

    /* Init variable */
    l_ctx.bIsInit = false;
    (void)memset(la_badPointerMempool, 0, sizeof(la_badPointerMempool));

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 1  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 9u) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 2  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetUPkDataLocat(&l_ctx, &lp_tempPo, &l_varTemp32) )
    {
        if( ( la_badPointerMempool == lp_tempPo ) && ( sizeof(la_badPointerMempool) == l_varTemp32 ) )
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 3  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetRemToPop(&l_ctx, &l_varTemp32) )
    {
        if( sizeof(la_badPointerMempool) == l_varTemp32 )
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 4  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 4  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU64( &l_ctx, &l_varTemp64 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 5  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetUPkDataLocat(&l_ctx, &lp_tempPo, &l_varTemp32) )
    {
        if( ( la_badPointerMempool == lp_tempPo ) && ( sizeof(la_badPointerMempool) == l_varTemp32 ) )
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 6  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetRemToPop(&l_ctx, &l_varTemp32) )
    {
        if( 1u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 7  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU64( &l_ctx, &l_varTemp64 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 8  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 7u) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 9  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetUPkDataLocat(&l_ctx, &lp_tempPo, &l_varTemp32) )
    {
        if( ( la_badPointerMempool == lp_tempPo ) && ( sizeof(la_badPointerMempool) == l_varTemp32 ) )
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 10 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 10 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 10 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetRemToPop(&l_ctx, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 11 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 11 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU64( &l_ctx, &l_varTemp64 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 12 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetUPkDataLocat(&l_ctx, &lp_tempPo, &l_varTemp32) )
    {
        if( ( la_badPointerMempool == lp_tempPo ) && ( sizeof(la_badPointerMempool) == l_varTemp32 ) )
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 13 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 13 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 13 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetRemToPop(&l_ctx, &l_varTemp32) )
    {
        if( 7u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 14 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackOutOfMem 14 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 14 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 5u) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 15 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU32( &l_ctx, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 16 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU32( &l_ctx, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 17 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 3u) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 18 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU32( &l_ctx, &l_varTemp32 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 19 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 3u) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 20 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 21 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 22 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 22 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 23 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 23 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 24 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 24 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 25 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 25 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU8( &l_ctx, &l_varTemp8 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 26 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 26 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU8( &l_ctx, &l_varTemp8 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 27 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 27 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 6u) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 28 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 28 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopArray( &l_ctx, la_pushPool, 5u ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 29 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 29 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopArray( &l_ctx, la_pushPool, 5u ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 30 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 30 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU8( &l_ctx, &l_varTemp8 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 31 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 31 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU8( &l_ctx, &l_varTemp8 ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 32 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 32 -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 33 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 33 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopArray( &l_ctx, la_pushPool, 2u ) )
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 34 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackOutOfMem 34 -- FAIL \n");
    }
}

static void eCU_TEST_dataUnPackEndianLe(void)
{
    /* Local variable */
    t_eCU_DUNPK_Ctx l_ctx;
    uint8_t  la_badPointerMempool[20u];
    uint8_t  la_pushPool[20u];
    uint32_t l_remtoPop;
    uint8_t* lp_tempPo;
    uint64_t l_varTemp64;
    uint32_t l_varTemp32;
    uint16_t l_varTemp16;
    uint8_t  l_varTemp8;

    /* Init variable */
    l_ctx.bIsInit = false;
    (void)memset(la_badPointerMempool, 0, sizeof(la_badPointerMempool));

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 1  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x12u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 1u) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 2  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0xF1u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopArray( &l_ctx, la_pushPool, 1u ) )
    {
        if( 0xF1u == la_pushPool[0u] )
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 3  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x12u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_RestartCurrentUnpack( &l_ctx  ) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 4  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU8( &l_ctx, &l_varTemp8 ) )
    {
        if( 0x12u == l_varTemp8 )
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 5  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x34u;
    la_badPointerMempool[1u] = 0x12u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 4u) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 6  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16 ) )
    {
        if( 0x1234u == l_varTemp16 )
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 7  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x78u;
    la_badPointerMempool[1u] = 0x56u;
    la_badPointerMempool[2u] = 0x34u;
    la_badPointerMempool[3u] = 0x12u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_RestartCurrentUnpack( &l_ctx ) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 8  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU32( &l_ctx, &l_varTemp32 ) )
    {
        if( 0x12345678u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 9  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0xF0u;
    la_badPointerMempool[1u] = 0xDEu;
    la_badPointerMempool[2u] = 0xBCu;
    la_badPointerMempool[3u] = 0x9Au;
    la_badPointerMempool[4u] = 0x78u;
    la_badPointerMempool[5u] = 0x56u;
    la_badPointerMempool[6u] = 0x34u;
    la_badPointerMempool[7u] = 0x12u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 8u) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 10 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetRemToPop(&l_ctx, &l_remtoPop) )
    {
        if( 0x08u == l_remtoPop )
        {
            if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetUPkDataLocat(&l_ctx, &lp_tempPo, &l_remtoPop) )
            {
                if( ( sizeof(la_badPointerMempool) == l_remtoPop ) && ( la_badPointerMempool == lp_tempPo ) )
                {
                    (void)printf("eCU_TEST_dataUnPackEndianLe 11 -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_dataUnPackEndianLe 11 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataUnPackEndianLe 11 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 11 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU64( &l_ctx, &l_varTemp64 ) )
    {
        if( 0x123456789ABCDEF0UL == l_varTemp64 )
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianLe 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianLe 12 -- FAIL \n");
    }
}

static void eCU_TEST_dataUnPackEndianBe(void)
{
    /* Local variable */
    t_eCU_DUNPK_Ctx l_ctx;
    uint8_t  la_badPointerMempool[20u];
    uint8_t  la_pushPool[20u];
    uint32_t l_remtoPop;
    uint8_t* lp_tempPo;
    uint64_t l_varTemp64;
    uint32_t l_varTemp32;
    uint16_t l_varTemp16;
    uint8_t  l_varTemp8;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), false) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 1  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x12u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 20u) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 2  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0xF1u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopArray( &l_ctx, la_pushPool, 1u ) )
    {
        if( 0xF1u == la_pushPool[0u] )
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 3  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x12u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_RestartCurrentUnpack( &l_ctx ) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 4  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU8( &l_ctx, &l_varTemp8 ) )
    {
        if( 0x12u == l_varTemp8 )
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 5  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x12u;
    la_badPointerMempool[1u] = 0x34u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_RestartCurrentUnpack( &l_ctx ) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 6  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16 ) )
    {
        if( 0x1234u == l_varTemp16 )
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 7  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x12u;
    la_badPointerMempool[1u] = 0x34u;
    la_badPointerMempool[2u] = 0x56u;
    la_badPointerMempool[3u] = 0x78u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_RestartCurrentUnpack( &l_ctx ) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 8  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU32( &l_ctx, &l_varTemp32 ) )
    {
        if( 0x12345678u == l_varTemp32 )
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 9  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x12u;
    la_badPointerMempool[1u] = 0x34u;
    la_badPointerMempool[2u] = 0x56u;
    la_badPointerMempool[3u] = 0x78u;
    la_badPointerMempool[4u] = 0x9Au;
    la_badPointerMempool[5u] = 0xBCu;
    la_badPointerMempool[6u] = 0xDEu;
    la_badPointerMempool[7u] = 0xF0u;

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_RestartCurrentUnpack( &l_ctx ) )
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 10 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetRemToPop(&l_ctx, &l_remtoPop) )
    {
        if( 0x14u == l_remtoPop )
        {
            if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetUPkDataLocat(&l_ctx, &lp_tempPo, &l_remtoPop) )
            {
                if( ( 0x14u == l_remtoPop ) && ( la_badPointerMempool == lp_tempPo ) )
                {
                    (void)printf("eCU_TEST_dataUnPackEndianBe 11 -- OK \n");
                }
                else
                {
                    (void)printf("eCU_TEST_dataUnPackEndianBe 11 -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataUnPackEndianBe 11 -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 11 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 11 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU64( &l_ctx, &l_varTemp64 ) )
    {
        if( 0x123456789ABCDEF0UL == l_varTemp64 )
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 12 -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackEndianBe 12 -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackEndianBe 12 -- FAIL \n");
    }
}

static void eCU_TEST_dataUnPackCycle(void)
{
    /* Local variable */
    t_eCU_DUNPK_Ctx l_ctx;
    uint8_t  la_badPointerMempool[20u];
    uint16_t l_varTemp16;
    uint32_t l_remtoPop;
    uint8_t* lp_tempPo;

    /* Init variable */
    l_ctx.bIsInit = false;

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctx, la_badPointerMempool, sizeof(la_badPointerMempool), true) )
    {
        (void)printf("eCU_TEST_dataUnPackCycle 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCycle 1  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctx, 20u) )
    {
        (void)printf("eCU_TEST_dataUnPackCycle 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCycle 2  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x78u;
    la_badPointerMempool[1u] = 0x56u;
    la_badPointerMempool[2u] = 0x34u;
    la_badPointerMempool[3u] = 0x12u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_RestartCurrentUnpack( &l_ctx ) )
    {
        (void)printf("eCU_TEST_dataUnPackCycle 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCycle 3  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16 ) )
    {
        if( 0x5678u == l_varTemp16 )
        {
            if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetRemToPop(&l_ctx, &l_remtoPop) )
            {
                if( 0x12u == l_remtoPop )
                {
                    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_GetUPkDataLocat(&l_ctx, &lp_tempPo, &l_remtoPop) )
                    {
                        if( ( sizeof(la_badPointerMempool) == l_remtoPop ) && ( la_badPointerMempool == lp_tempPo ) )
                        {
                            (void)printf("eCU_TEST_dataUnPackCycle 4  -- OK \n");
                        }
                        else
                        {
                            (void)printf("eCU_TEST_dataUnPackCycle 4  -- FAIL \n");
                        }
                    }
                    else
                    {
                        (void)printf("eCU_TEST_dataUnPackCycle 4  -- FAIL \n");
                    }
                }
                else
                {
                    (void)printf("eCU_TEST_dataUnPackCycle 4  -- FAIL \n");
                }
            }
            else
            {
                (void)printf("eCU_TEST_dataUnPackCycle 4  -- FAIL \n");
            }
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackCycle 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCycle 4  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16 ) )
    {
        if( 0x1234u == l_varTemp16 )
        {
            (void)printf("eCU_TEST_dataUnPackCycle 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackCycle 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCycle 5  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_RestartCurrentUnpack( &l_ctx ) )
    {
        (void)printf("eCU_TEST_dataUnPackCycle 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCycle 6  -- FAIL \n");
    }

    la_badPointerMempool[0u] = 0x78u;
    la_badPointerMempool[1u] = 0x56u;
    la_badPointerMempool[2u] = 0x34u;
    la_badPointerMempool[3u] = 0x12u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_RestartCurrentUnpack( &l_ctx ) )
    {
        (void)printf("eCU_TEST_dataUnPackCycle 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCycle 7  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16 ) )
    {
        if( 0x5678u == l_varTemp16 )
        {
            (void)printf("eCU_TEST_dataUnPackCycle 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackCycle 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCycle 8  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16( &l_ctx, &l_varTemp16 ) )
    {
        if( 0x1234u == l_varTemp16 )
        {
            (void)printf("eCU_TEST_dataUnPackCycle 9  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataUnPackCycle 9  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataUnPackCycle 9  -- FAIL \n");
    }
}


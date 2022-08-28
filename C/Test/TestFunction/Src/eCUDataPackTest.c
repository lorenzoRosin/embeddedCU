/**
 * @file eCUDataPackTest.c
 *
 */
#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataPackTest.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void dataPackTestBadPointer(void);
static void dataPackTestBadInit(void);
static void dataPackTestBadParamEntr(void);
static void dataPackTestBadParamStatus(void);
static void dataPackTestOutOfMem(void);
static void dataPackTestGeneric(void);
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
    dataPackTestBadParamStatus();
    dataPackTestOutOfMem();
    dataPackTestGeneric();
    dataPackTestCycle();

    (void)printf("\n\nDATA PACK END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void dataPackTestBadPointer(void)
{
    /* Local variable */
    s_eCU_DataPackCtx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;

    /* Function */
    if( ECU_RES_BADPOINTER == dataPackinit(NULL, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 1  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackinit(&ctx, NULL, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 2  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackReset( NULL ) )
    {
        (void)printf("dataPackTestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 3  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackGetDataSize( NULL, &varTemp ) )
    {
        (void)printf("dataPackTestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 4  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackGetDataSize( &ctx, NULL ) )
    {
        (void)printf("dataPackTestBadPointer 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 5  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackConsumeAllData( NULL, badPointerMempool, &varTemp, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 6  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackConsumeAllData( &ctx, NULL, &varTemp, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 7  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackConsumeAllData( &ctx, badPointerMempool, NULL, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 8  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackPushArray( NULL, badPointerMempool, sizeof(badPointerMempool) ) )
    {
        (void)printf("dataPackTestBadPointer 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 9  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackPushArray( &ctx, NULL, sizeof(badPointerMempool) ) )
    {
        (void)printf("dataPackTestBadPointer 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 10 -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackPushU8( NULL, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 11 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 11 -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackPushU16( NULL, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 12 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 12 -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackPushU32( NULL, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 13 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 13 -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == dataPackPushU64( NULL, 10u ) )
    {
        (void)printf("dataPackTestBadPointer 14 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadPointer 14 -- FAIL \n");
    }
}

void dataPackTestBadInit(void)
{
    /* Local variable */
    s_eCU_DataPackCtx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;

    /* Init variable */
    ctx.isInit = true;

    /* Function */
    if( ECU_RES_BADPARAM == dataPackinit(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestBadInit 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = false;

    if( ECU_RES_NOINITLIB == dataPackReset( &ctx ) )
    {
        (void)printf("dataPackTestBadInit 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 2  -- FAIL \n");
    }

    if( ECU_RES_NOINITLIB == dataPackGetDataSize( &ctx, &varTemp ) )
    {
        (void)printf("dataPackTestBadInit 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 3  -- FAIL \n");
    }

    if( ECU_RES_NOINITLIB == dataPackConsumeAllData( &ctx, badPointerMempool, &varTemp, 10u ) )
    {
        (void)printf("dataPackTestBadInit 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 4  -- FAIL \n");
    }

    if( ECU_RES_NOINITLIB == dataPackPushArray( &ctx, badPointerMempool, sizeof(badPointerMempool) ) )
    {
        (void)printf("dataPackTestBadInit 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 5  -- FAIL \n");
    }

    if( ECU_RES_NOINITLIB == dataPackPushU8( &ctx, 10u ) )
    {
        (void)printf("dataPackTestBadInit 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 6  -- FAIL \n");
    }

    if( ECU_RES_NOINITLIB == dataPackPushU16( &ctx, 10u ) )
    {
        (void)printf("dataPackTestBadInit 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 7  -- FAIL \n");
    }

    if( ECU_RES_NOINITLIB == dataPackPushU32( &ctx, 10u ) )
    {
        (void)printf("dataPackTestBadInit 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadInit 8  -- FAIL \n");
    }

    if( ECU_RES_NOINITLIB == dataPackPushU64( &ctx, 10u ) )
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
    s_eCU_DataPackCtx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;

    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( ECU_RES_BADPARAM == dataPackinit(&ctx, badPointerMempool, 0u, true) )
    {
        (void)printf("dataPackTestBadParamEntr 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamEntr 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.isInit = true;

    if( ECU_RES_BADPARAM == dataPackConsumeAllData( &ctx, badPointerMempool, &varTemp, 0u ) )
    {
        (void)printf("dataPackTestBadParamEntr 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamEntr 2  -- FAIL \n");
    }

    if( ECU_RES_BADPARAM == dataPackPushArray( &ctx, badPointerMempool, 0u ) )
    {
        (void)printf("dataPackTestBadParamEntr 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamEntr 3  -- FAIL \n");
    }
}

void dataPackTestBadParamStatus(void)
{
    /* Local variable */
    s_eCU_DataPackCtx ctx;
    uint8_t  badPointerMempool[5u];
    uint32_t varTemp;



    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( ECU_RES_OK == dataPackinit(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestBadParamStatus 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamStatus 1  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPoolSize = 0u;

    if( ECU_RES_BADPARAM == dataPackGetDataSize(&ctx, &varTemp) )
    {
        (void)printf("dataPackTestBadParamStatus 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamStatus 2  -- FAIL \n");
    }



    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( ECU_RES_OK == dataPackinit(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestBadParamStatus 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamStatus 3  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPool = NULL;

    if( ECU_RES_BADPARAM == dataPackGetDataSize(&ctx, &varTemp) )
    {
        (void)printf("dataPackTestBadParamStatus 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamStatus 4  -- FAIL \n");
    }



    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( ECU_RES_OK == dataPackinit(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestBadParamStatus 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamStatus 5  -- FAIL \n");
    }

    /* Init variable */
    ctx.memPoolCntr = ctx.memPoolSize + 1u;

    if( ECU_RES_BADPARAM == dataPackGetDataSize(&ctx, &varTemp) )
    {
        (void)printf("dataPackTestBadParamStatus 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestBadParamStatus 6  -- FAIL \n");
    }
}

void dataPackTestOutOfMem(void)
{
    /* Local variable */
    s_eCU_DataPackCtx ctx;
    uint8_t  badPointerMempool[2u];
    uint8_t  retrivePool[2u];
    uint32_t varTemp;



    /* Init variable */
    ctx.isInit = false;

    /* Function */
    if( ECU_RES_OK == dataPackinit(&ctx, badPointerMempool, sizeof(badPointerMempool), true) )
    {
        (void)printf("dataPackTestOutOfMem 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 1  -- FAIL \n");
    }

    if( ECU_RES_OUTOFMEM == dataPackPushU64( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 2  -- FAIL \n");
    }

    if( ECU_RES_OUTOFMEM == dataPackPushU32( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 3  -- FAIL \n");
    }

    if( ECU_RES_OK == dataPackPushU16( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 4  -- FAIL \n");
    }

    if( ECU_RES_OUTOFMEM == dataPackPushU16( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 5  -- FAIL \n");
    }

    if( ECU_RES_OUTOFMEM == dataPackPushU8( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 6  -- FAIL \n");
    }

    if( ECU_RES_OK == dataPackReset( &ctx ) )
    {
        (void)printf("dataPackTestOutOfMem 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 7  -- FAIL \n");
    }

    if( ECU_RES_OUTOFMEM == dataPackPushArray( &ctx, badPointerMempool, 4u ) )
    {
        (void)printf("dataPackTestOutOfMem 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 8  -- FAIL \n");
    }

    if( ECU_RES_OK == dataPackPushU16( &ctx, 10u ) )
    {
        (void)printf("dataPackTestOutOfMem 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 9  -- FAIL \n");
    }

    if( ECU_RES_BADPARAM == dataPackConsumeAllData( &ctx, retrivePool, &varTemp, 1u ) )
    {
        (void)printf("dataPackTestOutOfMem 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackTestOutOfMem 10 -- FAIL \n");
    }
}

void dataPackTestGeneric(void)
{
}

void dataPackTestCycle(void)
{
}


#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif
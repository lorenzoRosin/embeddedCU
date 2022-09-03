/**
 * @file eCUDataStuffUnStuffTest.c
 *
 */
#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataStuffUnStuffTest.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void dataStuffUnStuffCommon(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void dataStuffUnStuffTest(void)
{
	(void)printf("\n\nDATA STUFF UNSTUFF TEST START \n\n");

    dataStuffUnStuffCommon();

    (void)printf("\n\nDATA STUFF UNSTUFF END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void dataStuffUnStuffCommon(void)
{
    /* Local variable */
    e_eCU_BUStuffCtx ctxUnStuff;
    e_eCU_BStuffCtx ctxStuff;
    uint8_t  dataStuffPool[50u];
    uint8_t  dataUnStuffPool[50u];


    /* Function */
    if( ECU_RES_OK == dataPackinitCtx(&ctxUnStuff, dataPackPool, sizeof(dataPackPool), true) )
    {
        (void)printf("dataStuffUnStuffCommon 1  -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 1  -- FAIL \n");
    }

    if( ECU_RES_OK == dataPackPushU8(&ctxUnStuff, 0xF1u) )
    {
        (void)printf("dataStuffUnStuffCommon 2  -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 2  -- FAIL \n");
    }

    if( ECU_RES_OK == dataPackPushU16(&ctxUnStuff, 0xF1F2u) )
    {
        (void)printf("dataStuffUnStuffCommon 3  -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 3  -- FAIL \n");
    }

    if( ECU_RES_OK == dataPackPushU32(&ctxUnStuff, 0xF1F2F3F4u) )
    {
        (void)printf("dataStuffUnStuffCommon 4  -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 4  -- FAIL \n");
    }

    if( ECU_RES_OK == dataPackPushU64(&ctxUnStuff, 0xF1F2F3F4F5F6F7F8UL) )
    {
        (void)printf("dataStuffUnStuffCommon 5  -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 5  -- FAIL \n");
    }

    if( ECU_RES_OK == dataPackGetNPushed(&ctxUnStuff, &supportbuffget) )
    {
        (void)printf("dataStuffUnStuffCommon 6  -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 6  -- FAIL \n");
    }

    if( ECU_RES_OK == dataPackReset( &ctxUnStuff ) )
    {
        (void)printf("dataStuffUnStuffCommon 7  -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 7  -- FAIL \n");
    }

    /* Function */
    if( ECU_RES_OK == dataUnPackinitCtx(&ctxStuff, dataPackPool, supportbuffget, true) )
    {
        (void)printf("dataStuffUnStuffCommon 8  -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 8  -- FAIL \n");
    }

    if( ECU_RES_OK == dataUnPackPopU8(&ctxStuff, &var8) )
    {
        (void)printf("dataStuffUnStuffCommon 10 -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 10 -- FAIL \n");
    }

    if( ECU_RES_OK == dataUnPackPopU16(&ctxStuff, &var16) )
    {
        (void)printf("dataStuffUnStuffCommon 11 -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 11 -- FAIL \n");
    }

    if( ECU_RES_OK == dataUnPackPopU32(&ctxStuff, &var32) )
    {
        (void)printf("dataStuffUnStuffCommon 12 -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 12 -- FAIL \n");
    }

    if( ECU_RES_OK == dataUnPackPopU64(&ctxStuff, &var64) )
    {
        (void)printf("dataStuffUnStuffCommon 13 -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 13 -- FAIL \n");
    }

    /* Function */
    if( 0xF1u == var8 )
    {
        (void)printf("dataStuffUnStuffCommon 14 -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 14 -- FAIL \n");
    }

    if( 0xF1F2u == var16 )
    {
        (void)printf("dataStuffUnStuffCommon 15 -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 15 -- FAIL \n");
    }

    if( 0xF1F2F3F4u == var32 )
    {
        (void)printf("dataStuffUnStuffCommon 16 -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 16 -- FAIL \n");
    }

    if( 0xF1F2F3F4F5F6F7F8UL == var64 )
    {
        (void)printf("dataStuffUnStuffCommon 17 -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 17 -- FAIL \n");
    }
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif
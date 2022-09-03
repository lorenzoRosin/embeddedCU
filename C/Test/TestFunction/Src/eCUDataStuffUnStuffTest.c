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
    if( ECU_RES_BADPOINTER == bStufferInitCtx(&ctxStuff, dataStuffPool, sizeof(dataStuffPool)) )
    {
        (void)printf("dataStuffUnStuffCommon 1  -- OK \n");
    }
    else
    {
        (void)printf("dataStuffUnStuffCommon 1  -- FAIL \n");
    }

    if( ECU_RES_BADPOINTER == bUStufferInitCtx(&ctxUnStuff, dataUnStuffPool, sizeof(dataUnStuffPool)) )
    {
        (void)printf("byteUnStuffTestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("byteUnStuffTestBadPointer 1  -- FAIL \n");
    }
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif
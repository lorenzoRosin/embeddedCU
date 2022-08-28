/**
 * @file eCUDataPackUnPackTest.c
 *
 */
#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataPackUnPackTest.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void dataPackUnPackCommon(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void dataPackUnPackTest(void)
{
	(void)printf("\n\nDATA PACK UNPACK TEST START \n\n");

    dataPackUnPackCommon();

    (void)printf("\n\nDATA PACK UNPACK END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void dataPackUnPackCommon(void)
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

}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif
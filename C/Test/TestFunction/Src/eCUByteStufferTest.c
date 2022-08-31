/**
 * @file eCUByteStufferTest.c
 *
 */
#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif


/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteStufferTest.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void byteStuffTestBadPointer(void);
static void byteStuffTestBadInit(void);
static void byteStuffTestBadParamEntr(void);
static void byteStuffTestBadParamStatus(void);
static void byteStuffTestOutOfMem(void);
static void byteStuffTestGeneral(void);


/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void byteStufferTest(void)
{
	(void)printf("\n\nBYTE STUFFER TEST START \n\n");

    byteStuffTestBadPointer();
    byteStuffTestBadInit();
    byteStuffTestBadParamEntr();
    byteStuffTestBadParamStatus();
    byteStuffTestOutOfMem();
    byteStuffTestGeneral();

    (void)printf("\n\nBYTE STUFFER TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void byteStuffTestBadPointer(void)
{

}

void byteStuffTestBadInit(void)
{

}

void byteStuffTestBadParamEntr(void)
{

}

void byteStuffTestBadParamStatus(void)
{

}

void byteStuffTestOutOfMem(void)
{

}

void byteStuffTestGeneral(void)
{

}


#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif
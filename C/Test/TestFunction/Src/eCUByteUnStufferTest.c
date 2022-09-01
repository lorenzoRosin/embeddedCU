/**
 * @file eCUByteUnStufferTest.c
 *
 */
#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6", "MISRAC2004-17.4_b", "CERT-STR32-C"
    /* Suppressed for code clarity in test execution*/
#endif


/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUByteUnStufferTest.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void byteUnStuffTestBadPointer(void);
static void byteUnStuffTestBadInit(void);
static void byteUnStuffTestBadParamEntr(void);
static void byteUnStuffTestBadParamStatus(void);
static void byteUnStuffTestOutOfMem(void);
static void byteUnStuffTestGeneral(void);


/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void byteUnStufferTest(void)
{
	(void)printf("\n\nBYTE UNSTUFFER TEST START \n\n");

    byteUnStuffTestBadPointer();
    byteUnStuffTestBadInit();
    byteUnStuffTestBadParamEntr();
    byteUnStuffTestBadParamStatus();
    byteUnStuffTestOutOfMem();
    byteUnStuffTestGeneral();

    (void)printf("\n\nBYTE UNSTUFFER TEST END \n\n");
}





/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void byteUnStuffTestBadPointer(void)
{

}

void byteUnStuffTestBadInit(void)
{

}

void byteUnStuffTestBadParamEntr(void)
{

}

void byteUnStuffTestBadParamStatus(void)
{

}

void byteUnStuffTestOutOfMem(void)
{

}

void byteUnStuffTestGeneral(void)
{

}


#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6", "MISRAC2004-17.4_b", "CERT-STR32-C"
#endif
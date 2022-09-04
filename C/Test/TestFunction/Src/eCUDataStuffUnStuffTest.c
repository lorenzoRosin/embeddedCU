/**
 * @file eCUDataStuffUnStuffTest.c
 *
 */
#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6", "CERT-STR32-C"
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
typedef struct
{
    uint32_t dataTestSize;
    uint8_t  *dataTest;
}s_priv_test_stuffUnstuffMatrix;

void dataStuffUnStuffCommon(void)
{
    /* Local variable */
    e_eCU_BUStuffCtx ctxUnStuff;
    e_eCU_BStuffCtx ctxStuff;
    uint8_t  dataUnStuffPool[300];
    uint8_t  tempPool[300u];
    uint32_t  temp32;
    uint32_t  temp32sec;
    bool_t errSofRec;
    bool_t eofRec;
    uint32_t index;

    /* Test data */
    static uint8_t test1[5u]   = {0x01u, ECU_SOF, ECU_EOF, ECU_ESC, 0x21u};
    static uint8_t test2[5u]   = {0x01u, ECU_ESC, ECU_ESC, ECU_ESC, 0x21u};
    static uint8_t test3[7u]   = {0x01u, ECU_ESC, ECU_ESC, ECU_ESC, 0x21u, (uint8_t)(~ECU_ESC), (uint8_t)(~ECU_ESC)};
    static uint8_t test4[1u]   = {0x01u};
    static uint8_t test5[200u] = {0xFFu};


    /* Test Matrix */
    s_priv_test_stuffUnstuffMatrix testMatrix[5] = {
        { .dataTestSize = sizeof(test1), .dataTest = test1 },
        { .dataTestSize = sizeof(test2), .dataTest = test2 },
        { .dataTestSize = sizeof(test3), .dataTest = test3 },
        { .dataTestSize = sizeof(test4), .dataTest = test4 },
        { .dataTestSize = sizeof(test5), .dataTest = test5 }
    };


    for(index = 0u; index < (uint32_t)( ( sizeof(testMatrix) ) / ( sizeof(s_priv_test_stuffUnstuffMatrix) ) ); index++)
    {
        /* Function Init */
        if( ECU_RES_OK == bStufferInitCtx(&ctxStuff, testMatrix[index].dataTest, testMatrix[index].dataTestSize) )
        {
            (void)printf("dataStuffUnStuffCommon 1[%u]  -- OK \n", index);
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 1[%u]  -- FAIL \n", index);
        }

        if( ECU_RES_OK == bUStufferInitCtx(&ctxUnStuff, dataUnStuffPool, sizeof(dataUnStuffPool)) )
        {
            (void)printf("dataStuffUnStuffCommon 2[%u]  -- OK \n", index);
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 2[%u]  -- FAIL \n", index);
        }

        /* Stuff */
        if( ECU_RES_OK == bStufferRetriStufChunk(&ctxStuff, tempPool, sizeof(tempPool), &temp32) )
        {
            (void)printf("dataStuffUnStuffCommon 3[%u]  -- OK \n", index);
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 3[%u]  -- FAIL \n", index);
        }

        /* unstuff */
        if( ECU_RES_OK == bUStufferInsStufChunk( &ctxUnStuff, tempPool, temp32, &temp32sec, &errSofRec, &eofRec ) )
        {
            if( (true == errSofRec) || (false == eofRec) )
            {
                (void)printf("dataStuffUnStuffCommon 4[%u]  -- FAIL \n", index);
            }
            else
            {
                if( ECU_RES_OK == bUStufferGetNUnstuf(&ctxUnStuff, &temp32sec) )
                {
                    if( testMatrix[index].dataTestSize == temp32sec )
                    {
                        if( 0 == memcmp(dataUnStuffPool, testMatrix[index].dataTest, testMatrix[index].dataTestSize) )
                        {
                            (void)printf("dataStuffUnStuffCommon 4[%u]  -- OK \n", index);
                        }
                        else
                        {
                            (void)printf("dataStuffUnStuffCommon 4[%u]  -- FAIL \n", index);
                        }
                    }
                    else
                    {
                        (void)printf("dataStuffUnStuffCommon 4[%u]  -- FAIL \n", index);
                    }
                }
                else
                {
                    (void)printf("dataStuffUnStuffCommon 4[%u]  -- FAIL \n", index);
                }
            }
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 4[%u]  -- FAIL \n", index);
        }
    }
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6", "CERT-STR32-C"
#endif
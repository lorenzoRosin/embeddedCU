/**
 * @file       eCUDataStuffUnStuffTest.c
 *
 * @brief      Data stuffer and unstuffer test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataStuffUnStuffTest.h"

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif

#include <stdio.h>

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "CERT-STR32-C"
    /* Suppressed for code clarity in test execution*/
#endif



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
    s_eCU_BUNSTF_Ctx ctxUnStuff;
    s_eCU_BSTF_Ctx ctxStuff;
    static uint8_t  dataUnStuffPool[300];
    static uint8_t  dataStuffPool[300];
    static uint8_t  tempPool[300u];
    uint32_t  temp32;
    uint32_t  temp32sec;
    uint32_t index;
    uint8_t* tempP;
    uint32_t tempPSize;

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
        if( BSTF_RES_OK == eCU_BSTF_InitCtx(&ctxStuff, dataStuffPool, sizeof(dataStuffPool)) )
        {
            (void)printf("dataStuffUnStuffCommon 1[%u]  -- OK \n", index);
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 1[%u]  -- FAIL \n", index);
        }

        if( BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&ctxUnStuff, dataUnStuffPool, sizeof(dataUnStuffPool)) )
        {
            (void)printf("dataStuffUnStuffCommon 2[%u]  -- OK \n", index);
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 2[%u]  -- FAIL \n", index);
        }

        /* Copy data in byte stuffer */
        if( BSTF_RES_OK == eCU_BSTF_GetWherePutData(&ctxStuff, &tempP, &tempPSize) )
        {
            if( tempPSize == sizeof(dataStuffPool) )
            {
                (void)memcpy(tempP, testMatrix[index].dataTest, testMatrix[index].dataTestSize);
                (void)printf("dataStuffUnStuffCommon 3[%u]  -- OK \n", index);
            }
            else
            {
                (void)printf("dataStuffUnStuffCommon 3[%u]  -- FAIL \n", index);
            }
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 3[%u]  -- FAIL \n", index);
        }


        /* Function Init part two */
        if( BSTF_RES_OK == eCU_BSTF_NewFrame(&ctxStuff, testMatrix[index].dataTestSize) )
        {
            (void)printf("dataStuffUnStuffCommon 4[%u]  -- OK \n", index);
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 4[%u]  -- FAIL \n", index);
        }

        if( BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&ctxUnStuff) )
        {
            (void)printf("dataStuffUnStuffCommon 5[%u]  -- OK \n", index);
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 5[%u]  -- FAIL \n", index);
        }

        /* Stuff */
        if( BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&ctxStuff, tempPool, sizeof(tempPool), &temp32) )
        {
            (void)printf("dataStuffUnStuffCommon 6[%u]  -- OK \n", index);
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 6[%u]  -- FAIL \n", index);
        }

        /* unstuff */
        if( BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &ctxUnStuff, tempPool, temp32, &temp32sec ) )
        {
            if( BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&ctxUnStuff, &temp32sec) )
            {
                if( testMatrix[index].dataTestSize == temp32sec )
                {
                    if( 0 == memcmp(dataUnStuffPool, testMatrix[index].dataTest, testMatrix[index].dataTestSize) )
                    {
                        (void)printf("dataStuffUnStuffCommon 7[%u]  -- OK \n", index);
                    }
                    else
                    {
                        (void)printf("dataStuffUnStuffCommon 7[%u]  -- FAIL \n", index);
                    }
                }
                else
                {
                    (void)printf("dataStuffUnStuffCommon 7[%u]  -- FAIL \n", index);
                }
            }
            else
            {
                (void)printf("dataStuffUnStuffCommon 7[%u]  -- FAIL \n", index);
            }
        }
        else
        {
            (void)printf("dataStuffUnStuffCommon 7[%u]  -- FAIL \n", index);
        }
    }
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "CERT-STR32-C"
#endif
/**
 * @file       eCU_BSTFBUNSTFTST.c
 *
 * @brief      Data stuffer and unstuffer test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCU_BSTFBUNSTFTST.h"
#include "eCU_BSTF.h"
#include "eCU_BUNSTF.h"
#include <stdio.h>

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "CERT-STR32-C"
    /* Suppressed for code clarity in test execution*/
#endif



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_BSTFBUNSTFTST_Common(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_BSTFBUNSTFTST_ExeTest(void)
{
	(void)printf("\n\nDATA STUFF UNSTUFF TEST START \n\n");

    eCU_BSTFBUNSTFTST_Common();

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

static void eCU_BSTFBUNSTFTST_Common(void)
{
    /* Local variable */
    t_eCU_BUNSTF_Ctx l_ctxUnStuff;
    t_eCU_BSTF_Ctx l_ctxStuff;
    static uint8_t  la_dataUnStuffPool[300];
    static uint8_t  la_dataStuffPool[300];
    static uint8_t  la_tempPool[300u];
    uint32_t  l_temp32;
    uint32_t  l_temp32sec;
    uint32_t l_index;
    uint8_t* lp_tempPo;
    uint32_t l_tempPSize;

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

    for(l_index = 0u; l_index < (uint32_t)( ( sizeof(testMatrix) ) / ( sizeof(s_priv_test_stuffUnstuffMatrix) ) ); l_index++)
    {
        /* Function Init */
        if( e_eCU_BSTF_RES_OK == eCU_BSTF_InitCtx(&l_ctxStuff, la_dataStuffPool, sizeof(la_dataStuffPool)) )
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 1[%u]  -- OK \n", l_index);
        }
        else
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 1[%u]  -- FAIL \n", l_index);
        }

        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_InitCtx(&l_ctxUnStuff, la_dataUnStuffPool, sizeof(la_dataUnStuffPool)) )
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 2[%u]  -- OK \n", l_index);
        }
        else
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 2[%u]  -- FAIL \n", l_index);
        }

        /* Copy data in byte stuffer */
        if( e_eCU_BSTF_RES_OK == eCU_BSTF_GetWherePutData(&l_ctxStuff, &lp_tempPo, &l_tempPSize) )
        {
            if( l_tempPSize == sizeof(la_dataStuffPool) )
            {
                (void)memcpy(lp_tempPo, testMatrix[l_index].dataTest, testMatrix[l_index].dataTestSize);
                (void)printf("eCU_BSTFBUNSTFTST_Common 3[%u]  -- OK \n", l_index);
            }
            else
            {
                (void)printf("eCU_BSTFBUNSTFTST_Common 3[%u]  -- FAIL \n", l_index);
            }
        }
        else
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 3[%u]  -- FAIL \n", l_index);
        }


        /* Function Init part two */
        if( e_eCU_BSTF_RES_OK == eCU_BSTF_NewFrame(&l_ctxStuff, testMatrix[l_index].dataTestSize) )
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 4[%u]  -- OK \n", l_index);
        }
        else
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 4[%u]  -- FAIL \n", l_index);
        }

        if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_NewFrame(&l_ctxUnStuff) )
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 5[%u]  -- OK \n", l_index);
        }
        else
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 5[%u]  -- FAIL \n", l_index);
        }

        /* Stuff */
        if( e_eCU_BSTF_RES_FRAMEENDED == eCU_BSTF_GetStufChunk(&l_ctxStuff, la_tempPool, sizeof(la_tempPool), &l_temp32) )
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 6[%u]  -- OK \n", l_index);
        }
        else
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 6[%u]  -- FAIL \n", l_index);
        }

        /* unstuff */
        if( e_eCU_BUNSTF_RES_FRAMEENDED == eCU_BUNSTF_InsStufChunk( &l_ctxUnStuff, la_tempPool, l_temp32, &l_temp32sec ) )
        {
            if( e_eCU_BUNSTF_RES_OK == eCU_BUNSTF_GetUnstufLen(&l_ctxUnStuff, &l_temp32sec) )
            {
                if( testMatrix[l_index].dataTestSize == l_temp32sec )
                {
                    if( 0 == memcmp(la_dataUnStuffPool, testMatrix[l_index].dataTest, testMatrix[l_index].dataTestSize) )
                    {
                        (void)printf("eCU_BSTFBUNSTFTST_Common 7[%u]  -- OK \n", l_index);
                    }
                    else
                    {
                        (void)printf("eCU_BSTFBUNSTFTST_Common 7[%u]  -- FAIL \n", l_index);
                    }
                }
                else
                {
                    (void)printf("eCU_BSTFBUNSTFTST_Common 7[%u]  -- FAIL \n", l_index);
                }
            }
            else
            {
                (void)printf("eCU_BSTFBUNSTFTST_Common 7[%u]  -- FAIL \n", l_index);
            }
        }
        else
        {
            (void)printf("eCU_BSTFBUNSTFTST_Common 7[%u]  -- FAIL \n", l_index);
        }
    }
}

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "CERT-STR32-C"
#endif
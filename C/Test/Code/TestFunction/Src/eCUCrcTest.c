/**
 * @file       eCUCrcTest.c
 *
 * @brief      CRC test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUCrcTest.h"
#include "eCU_CRC.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_TEST_crc32BadPointer(void);
static void eCU_TEST_crc32Value(void);
static void eCU_TEST_crc32Combined(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_CRCTST_ExeTest(void)
{
	(void)printf("\n\nCRC TEST START \n\n");

    eCU_TEST_crc32BadPointer();
    eCU_TEST_crc32Value();
    eCU_TEST_crc32Combined();

    (void)printf("\n\nCRC TEST END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_TEST_crc32BadPointer(void)
{
    /* Local variable */
    uint32_t l_crc32SValTest;
    uint8_t  la_crc8SValTest[1u];
    la_crc8SValTest[0u] = 0x00u;

    /* Function */
    if( e_eCU_CRC_RES_BADPOINTER == eCU_CRC_32Seed(0u, NULL, 1u, &l_crc32SValTest) )
    {
        (void)printf("eCU_TEST_crc32BadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_crc32BadPointer 1  -- FAIL \n");
    }

    if( e_eCU_CRC_RES_BADPOINTER == eCU_CRC_32Seed(0u, la_crc8SValTest, 1u, NULL) )
    {
        (void)printf("eCU_TEST_crc32BadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_crc32BadPointer 2  -- FAIL \n");
    }

    if( e_eCU_CRC_RES_BADPOINTER == eCU_CRC_32(NULL, 1u, &l_crc32SValTest) )
    {
        (void)printf("eCU_TEST_crc32BadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_crc32BadPointer 3  -- FAIL \n");
    }

    if( e_eCU_CRC_RES_BADPOINTER == eCU_CRC_32(la_crc8SValTest, 1u, NULL) )
    {
        (void)printf("eCU_TEST_crc32BadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_crc32BadPointer 4  -- FAIL \n");
    }
}

static void eCU_TEST_crc32Value(void)
{
    /* Local variable */
    uint32_t l_crcTestValSeed;
    uint8_t la_crcTestData1[] = {0x00u, 0x01u, 0x02u};
    uint32_t l_crcTestValRet;

    /* Function */
    l_crcTestValSeed = 0xFFFFFFFFu;
    if( e_eCU_CRC_RES_OK == eCU_CRC_32Seed(l_crcTestValSeed, la_crcTestData1, sizeof(la_crcTestData1), &l_crcTestValRet) )
    {
        if( 0x6CFF87B2u == l_crcTestValRet)
        {
            (void)printf("eCU_TEST_crc32Value 1  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_crc32Value 1  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_crc32Value 1  -- FAIL \n");
    }

    l_crcTestValSeed = 0x0u;
    if( e_eCU_CRC_RES_OK == eCU_CRC_32Seed(l_crcTestValSeed, la_crcTestData1, sizeof(la_crcTestData1), &l_crcTestValRet) )
    {
        if( 0xDB9BFAB2u == l_crcTestValRet)
        {
            (void)printf("eCU_TEST_crc32Value 2  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_crc32Value 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_crc32Value 2  -- FAIL \n");
    }

    if( e_eCU_CRC_RES_OK == eCU_CRC_32(la_crcTestData1, sizeof(la_crcTestData1), &l_crcTestValRet) )
    {
        if( 0x6CFF87B2u == l_crcTestValRet)
        {
            (void)printf("eCU_TEST_crc32Value 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_crc32Value 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_crc32Value 3  -- FAIL \n");
    }

    /* Function */
    uint8_t crcTestData2[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0xFF, 0xF1, 0xF5, 0x31, 0x32, 0x33,
                              0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0xFF, 0xF1, 0xF5};

    l_crcTestValSeed = 0xFFFFFFFFu;
    if( e_eCU_CRC_RES_OK == eCU_CRC_32Seed(l_crcTestValSeed, crcTestData2, sizeof(crcTestData2), &l_crcTestValRet) )
    {
        if( 0x4DBE0510u == l_crcTestValRet)
        {
            (void)printf("eCU_TEST_crc32Value 4  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_crc32Value 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_crc32Value 4  -- FAIL \n");
    }

    l_crcTestValSeed = 0x0u;
    if( e_eCU_CRC_RES_OK == eCU_CRC_32Seed(l_crcTestValSeed, crcTestData2, sizeof(crcTestData2), &l_crcTestValRet) )
    {
        if( 0xB612792Au == l_crcTestValRet)
        {
            (void)printf("eCU_TEST_crc32Value 5  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_crc32Value 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_crc32Value 5  -- FAIL \n");
    }

    if( e_eCU_CRC_RES_OK == eCU_CRC_32(crcTestData2, sizeof(crcTestData2), &l_crcTestValRet) )
    {
        if( 0x4DBE0510u == l_crcTestValRet)
        {
            (void)printf("eCU_TEST_crc32Value 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_crc32Value 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_crc32Value 6  -- FAIL \n");
    }
}

static void eCU_TEST_crc32Combined(void)
{
    /* Local variable */
    uint32_t l_crcTestValSeedC;
    uint8_t la_crcTestDataC[] = {0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u};
    uint8_t la_crcTestDataC2[] = {0x03u, 0x04u, 0x05u};
    uint32_t l_crcTestValRetC;

    /* Function */
    l_crcTestValSeedC = 0xFFFFFFFFu;
    if( e_eCU_CRC_RES_OK == eCU_CRC_32Seed(l_crcTestValSeedC, la_crcTestDataC, sizeof(la_crcTestDataC), &l_crcTestValRetC) )
    {
        if( 0x9FE54C6Du == l_crcTestValRetC)
        {
            (void)printf("eCU_TEST_crc32Combined 1  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_crc32Combined 1  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_crc32Combined 1  -- FAIL \n");
    }

    l_crcTestValSeedC = 0xFFFFFFFFu;
    if( e_eCU_CRC_RES_OK == eCU_CRC_32Seed(l_crcTestValSeedC, la_crcTestDataC, 0x03u, &l_crcTestValRetC) )
    {
        if( 0x6CFF87B2u == l_crcTestValRetC)
        {
            (void)printf("eCU_TEST_crc32Combined 2  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_crc32Combined 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_crc32Combined 2  -- FAIL \n");
    }

    l_crcTestValSeedC = l_crcTestValRetC;
    if( e_eCU_CRC_RES_OK == eCU_CRC_32Seed(l_crcTestValSeedC, la_crcTestDataC2, 0x03u, &l_crcTestValRetC) )
    {
        if( 0x9FE54C6Du == l_crcTestValRetC)
        {
            (void)printf("eCU_TEST_crc32Combined 3  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_crc32Combined 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_crc32Combined 3  -- FAIL \n");
    }
}
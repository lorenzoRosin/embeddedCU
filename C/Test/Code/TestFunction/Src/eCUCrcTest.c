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
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void crc32TestBadPointer(void);
static void crc32TestValue(void);
static void crc32TestCombined(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void crc32Test(void)
{
	(void)printf("\n\nCRC TEST START \n\n");

    crc32TestBadPointer();
    crc32TestValue();
    crc32TestCombined();

    (void)printf("\n\nCRC TEST END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void crc32TestBadPointer(void)
{
    /* Local variable */
    uint32_t crc32SValTest;
    uint8_t  crc8SValTest[1u];

    /* Function */
    if( CRC_RES_BADPOINTER == eCU_CRC_32Seed(0u, NULL, 1u, &crc32SValTest) )
    {
        (void)printf("crc32TestBadPointer 1  -- OK \n");
    }
    else
    {
        (void)printf("crc32TestBadPointer 1  -- FAIL \n");
    }

    if( CRC_RES_BADPOINTER == eCU_CRC_32Seed(0u, crc8SValTest, 1u, NULL) )
    {
        (void)printf("crc32TestBadPointer 2  -- OK \n");
    }
    else
    {
        (void)printf("crc32TestBadPointer 2  -- FAIL \n");
    }

    if( CRC_RES_BADPOINTER == eCU_CRC_32(NULL, 1u, &crc32SValTest) )
    {
        (void)printf("crc32TestBadPointer 3  -- OK \n");
    }
    else
    {
        (void)printf("crc32TestBadPointer 3  -- FAIL \n");
    }

    if( CRC_RES_BADPOINTER == eCU_CRC_32(crc8SValTest, 1u, NULL) )
    {
        (void)printf("crc32TestBadPointer 4  -- OK \n");
    }
    else
    {
        (void)printf("crc32TestBadPointer 4  -- FAIL \n");
    }
}

void crc32TestValue(void)
{
    /* Local variable */
    uint32_t crcTestValSeed;
    uint8_t crcTestData1[] = {0x00u, 0x01u, 0x02u};
    uint32_t crcTestValRet;

    /* Function */
    crcTestValSeed = 0xFFFFFFFFu;
    if( CRC_RES_OK == eCU_CRC_32Seed(crcTestValSeed, crcTestData1, sizeof(crcTestData1), &crcTestValRet) )
    {
        if( 0x6CFF87B2u == crcTestValRet)
        {
            (void)printf("crc32TestValue 1  -- OK \n");
        }
        else
        {
            (void)printf("crc32TestValue 1  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("crc32TestValue 1  -- FAIL \n");
    }

    crcTestValSeed = 0x0u;
    if( CRC_RES_OK == eCU_CRC_32Seed(crcTestValSeed, crcTestData1, sizeof(crcTestData1), &crcTestValRet) )
    {
        if( 0xDB9BFAB2u == crcTestValRet)
        {
            (void)printf("crc32TestValue 2  -- OK \n");
        }
        else
        {
            (void)printf("crc32TestValue 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("crc32TestValue 2  -- FAIL \n");
    }

    if( CRC_RES_OK == eCU_CRC_32(crcTestData1, sizeof(crcTestData1), &crcTestValRet) )
    {
        if( 0x6CFF87B2u == crcTestValRet)
        {
            (void)printf("crc32TestValue 3  -- OK \n");
        }
        else
        {
            (void)printf("crc32TestValue 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("crc32TestValue 3  -- FAIL \n");
    }

    /* Function */
    uint8_t crcTestData2[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0xFF, 0xF1, 0xF5, 0x31, 0x32, 0x33,
                              0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0xFF, 0xF1, 0xF5};

    crcTestValSeed = 0xFFFFFFFFu;
    if( CRC_RES_OK == eCU_CRC_32Seed(crcTestValSeed, crcTestData2, sizeof(crcTestData2), &crcTestValRet) )
    {
        if( 0x4DBE0510u == crcTestValRet)
        {
            (void)printf("crc32TestValue 4  -- OK \n");
        }
        else
        {
            (void)printf("crc32TestValue 4  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("crc32TestValue 4  -- FAIL \n");
    }

    crcTestValSeed = 0x0u;
    if( CRC_RES_OK == eCU_CRC_32Seed(crcTestValSeed, crcTestData2, sizeof(crcTestData2), &crcTestValRet) )
    {
        if( 0xB612792Au == crcTestValRet)
        {
            (void)printf("crc32TestValue 5  -- OK \n");
        }
        else
        {
            (void)printf("crc32TestValue 5  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("crc32TestValue 5  -- FAIL \n");
    }

    if( CRC_RES_OK == eCU_CRC_32(crcTestData2, sizeof(crcTestData2), &crcTestValRet) )
    {
        if( 0x4DBE0510u == crcTestValRet)
        {
            (void)printf("crc32TestValue 6  -- OK \n");
        }
        else
        {
            (void)printf("crc32TestValue 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("crc32TestValue 6  -- FAIL \n");
    }
}

void crc32TestCombined(void)
{
    /* Local variable */
    uint32_t crcTestValSeedC;
    uint8_t crcTestDataC[] = {0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u};
    uint8_t crcTestDataC2[] = {0x03u, 0x04u, 0x05u};
    uint32_t crcTestValRetC;

    /* Function */
    crcTestValSeedC = 0xFFFFFFFFu;
    if( CRC_RES_OK == eCU_CRC_32Seed(crcTestValSeedC, crcTestDataC, sizeof(crcTestDataC), &crcTestValRetC) )
    {
        if( 0x9FE54C6Du == crcTestValRetC)
        {
            (void)printf("crc32TestCombined 1  -- OK \n");
        }
        else
        {
            (void)printf("crc32TestCombined 1  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("crc32TestCombined 1  -- FAIL \n");
    }

    crcTestValSeedC = 0xFFFFFFFFu;
    if( CRC_RES_OK == eCU_CRC_32Seed(crcTestValSeedC, crcTestDataC, 0x03u, &crcTestValRetC) )
    {
        if( 0x6CFF87B2u == crcTestValRetC)
        {
            (void)printf("crc32TestCombined 2  -- OK \n");
        }
        else
        {
            (void)printf("crc32TestCombined 2  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("crc32TestCombined 2  -- FAIL \n");
    }

    crcTestValSeedC = crcTestValRetC;
    if( CRC_RES_OK == eCU_CRC_32Seed(crcTestValSeedC, crcTestDataC2, 0x03u, &crcTestValRetC) )
    {
        if( 0x9FE54C6Du == crcTestValRetC)
        {
            (void)printf("crc32TestCombined 3  -- OK \n");
        }
        else
        {
            (void)printf("crc32TestCombined 3  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("crc32TestCombined 3  -- FAIL \n");
    }
}
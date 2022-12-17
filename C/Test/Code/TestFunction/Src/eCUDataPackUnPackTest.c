/**
 * @file       eCUDataPackUnPackTest.c
 *
 * @brief      Data pack and unpack test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUDataPackUnPackTest.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_TEST_dataPackUnPackLE(void);
static void eCU_TEST_dataPackUnPackBE(void);
static void eCU_TEST_dataPackUnPackGeneral(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_TEST_dataPackUnPack(void)
{
	(void)printf("\n\nDATA PACK UNPACK TEST START \n\n");

    eCU_TEST_dataPackUnPackLE();
    eCU_TEST_dataPackUnPackBE();
    eCU_TEST_dataPackUnPackGeneral();

    (void)printf("\n\nDATA PACK UNPACK END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_TEST_dataPackUnPackLE(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctxPack;
    s_eCU_DUNPK_Ctx ctxUnPack;
    uint8_t  dataPackPool[20u];
    uint8_t  supportArray[5u];
    uint32_t supportbuffget;
    uint8_t  var8;
    uint16_t var16;
    uint32_t var32;
    uint64_t var64;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctxPack, dataPackPool, sizeof(dataPackPool), true) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 1  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_StartNewPack(&ctxPack) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU8(&ctxPack, 0x12u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 3  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16(&ctxPack, 0x1234u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 4  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32(&ctxPack, 0x12345678u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 5  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU64(&ctxPack, 0x123456789ABCDEF0UL) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 6  -- FAIL \n");
    }

    supportArray[0u] = 0xF0u;
    supportArray[1u] = 0xF1u;
    supportArray[2u] = 0xF2u;
    supportArray[3u] = 0xF3u;
    supportArray[4u] = 0xF4u;
    if( DPK_RES_OK == eCU_DPK_PushArray( &ctxPack, supportArray, sizeof(supportArray) ) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 7  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed(&ctxPack, &supportbuffget) )
    {
        if( 20u == supportbuffget )
        {
            (void)printf("eCU_TEST_dataPackUnPackLE 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataPackUnPackLE 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 8  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU8(&ctxPack, 0x12u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 9  -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == eCU_DUNPK_InitCtx(&ctxUnPack, dataPackPool, sizeof(dataPackPool), true) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&ctxUnPack, supportbuffget) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 11 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU8(&ctxUnPack, &var8) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 12 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&ctxUnPack, &var16) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 13 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU32(&ctxUnPack, &var32) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 14 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU64(&ctxUnPack, &var64) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 15 -- FAIL \n");
    }

    supportArray[0u] = 0x00u;
    supportArray[1u] = 0x00u;
    supportArray[2u] = 0x00u;
    supportArray[3u] = 0x00u;
    supportArray[4u] = 0x00u;
    if( DUNPK_RES_OK == eCU_DUNPK_PopArray(&ctxUnPack, supportArray, 5u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 16 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == eCU_DUNPK_PopU8(&ctxUnPack, &var8) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 17 -- FAIL \n");
    }

    /* Function */
    if( 0x12u == var8 )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 18 -- FAIL \n");
    }

    if( 0x1234u == var16 )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 19 -- FAIL \n");
    }

    if( 0x12345678u == var32 )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 20 -- FAIL \n");
    }

    if( 0x123456789ABCDEF0UL == var64 )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 21 -- FAIL \n");
    }
}

static void eCU_TEST_dataPackUnPackBE(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctxPack;
    s_eCU_DUNPK_Ctx ctxUnPack;
    uint8_t  dataPackPool[20u];
    uint8_t  supportArray[5u];
    uint32_t supportbuffget;
    uint8_t  var8;
    uint16_t var16;
    uint32_t var32;
    uint64_t var64;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctxPack, dataPackPool, sizeof(dataPackPool), false) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 1  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU8(&ctxPack, 0x12u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16(&ctxPack, 0x1234u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 3  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32(&ctxPack, 0x12345678u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 4  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU64(&ctxPack, 0x123456789ABCDEF0UL) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 5  -- FAIL \n");
    }

    supportArray[0u] = 0xF0u;
    supportArray[1u] = 0xF1u;
    supportArray[2u] = 0xF2u;
    supportArray[3u] = 0xF3u;
    supportArray[4u] = 0xF4u;
    if( DPK_RES_OK == eCU_DPK_PushArray( &ctxPack, supportArray, sizeof(supportArray) ) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 6  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed(&ctxPack, &supportbuffget) )
    {
        if( 20u == supportbuffget )
        {
            (void)printf("eCU_TEST_dataPackUnPackBE 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataPackUnPackBE 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 7  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU8(&ctxPack, 0x12u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 8  -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == eCU_DUNPK_InitCtx(&ctxUnPack, dataPackPool, sizeof(dataPackPool), false) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 9  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&ctxUnPack, supportbuffget) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU8(&ctxUnPack, &var8) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 11 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&ctxUnPack, &var16) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 12 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU32(&ctxUnPack, &var32) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 13 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU64(&ctxUnPack, &var64) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 14 -- FAIL \n");
    }

    supportArray[0u] = 0x00u;
    supportArray[1u] = 0x00u;
    supportArray[2u] = 0x00u;
    supportArray[3u] = 0x00u;
    supportArray[4u] = 0x00u;
    if( DUNPK_RES_OK == eCU_DUNPK_PopArray(&ctxUnPack, supportArray, 5u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 15 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == eCU_DUNPK_PopU8(&ctxUnPack, &var8) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 16 -- FAIL \n");
    }

    /* Function */
    if( 0x12u == var8 )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 17 -- FAIL \n");
    }

    if( 0x1234u == var16 )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 18 -- FAIL \n");
    }

    if( 0x12345678u == var32 )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 19 -- FAIL \n");
    }

    if( 0x123456789ABCDEF0UL == var64 )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 20 -- FAIL \n");
    }
}

static void eCU_TEST_dataPackUnPackGeneral(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctxPack;
    s_eCU_DUNPK_Ctx ctxUnPack;
    uint8_t  dataPackPool[20u];
    uint16_t var16;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctxPack, dataPackPool, sizeof(dataPackPool), true) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 1  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_InitCtx(&ctxUnPack, dataPackPool, sizeof(dataPackPool), true) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_StartNewPack(&ctxPack) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 3  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&ctxUnPack, 4u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 4  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32(&ctxPack, 0x12345678u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 5  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&ctxUnPack, &var16) )
    {
        if( 0x5678u == var16 )
        {
            (void)printf("eCU_TEST_dataPackUnPackGeneral 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataPackUnPackGeneral 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 6  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&ctxUnPack, &var16) )
    {
        if( 0x1234u == var16 )
        {
            (void)printf("eCU_TEST_dataPackUnPackGeneral 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_TEST_dataPackUnPackGeneral 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 7  -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == eCU_DUNPK_PopU16(&ctxUnPack, &var16) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 8  -- FAIL \n");
    }
}
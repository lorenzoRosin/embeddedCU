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
    s_eCU_DPK_Ctx l_ctxPack;
    s_eCU_DUNPK_Ctx l_ctxUnPack;
    uint8_t  la_dataPackPool[20u];
    uint8_t  la_supportArray[5u];
    uint32_t l_supportbuffget;
    uint8_t  l_var8;
    uint16_t l_var16;
    uint32_t l_var32;
    uint64_t l_var64;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&l_ctxPack, la_dataPackPool, sizeof(la_dataPackPool), true) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 1  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_StartNewPack(&l_ctxPack) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU8(&l_ctxPack, 0x12u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 3  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16(&l_ctxPack, 0x1234u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 4  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32(&l_ctxPack, 0x12345678u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 5  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU64(&l_ctxPack, 0x123456789ABCDEF0UL) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 6  -- FAIL \n");
    }

    la_supportArray[0u] = 0xF0u;
    la_supportArray[1u] = 0xF1u;
    la_supportArray[2u] = 0xF2u;
    la_supportArray[3u] = 0xF3u;
    la_supportArray[4u] = 0xF4u;
    if( DPK_RES_OK == eCU_DPK_PushArray( &l_ctxPack, la_supportArray, sizeof(la_supportArray) ) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 7  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed(&l_ctxPack, &l_supportbuffget) )
    {
        if( 20u == l_supportbuffget )
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

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU8(&l_ctxPack, 0x12u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 9  -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctxUnPack, la_dataPackPool, sizeof(la_dataPackPool), true) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctxUnPack, l_supportbuffget) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 11 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU8(&l_ctxUnPack, &l_var8) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 12 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&l_ctxUnPack, &l_var16) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 13 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU32(&l_ctxUnPack, &l_var32) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 14 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU64(&l_ctxUnPack, &l_var64) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 15 -- FAIL \n");
    }

    la_supportArray[0u] = 0x00u;
    la_supportArray[1u] = 0x00u;
    la_supportArray[2u] = 0x00u;
    la_supportArray[3u] = 0x00u;
    la_supportArray[4u] = 0x00u;
    if( DUNPK_RES_OK == eCU_DUNPK_PopArray(&l_ctxUnPack, la_supportArray, 5u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 16 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == eCU_DUNPK_PopU8(&l_ctxUnPack, &l_var8) )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 17 -- FAIL \n");
    }

    /* Function */
    if( 0x12u == l_var8 )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 18 -- FAIL \n");
    }

    if( 0x1234u == l_var16 )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 19 -- FAIL \n");
    }

    if( 0x12345678u == l_var32 )
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackLE 20 -- FAIL \n");
    }

    if( 0x123456789ABCDEF0UL == l_var64 )
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
    s_eCU_DPK_Ctx l_ctxPack;
    s_eCU_DUNPK_Ctx l_ctxUnPack;
    uint8_t  la_dataPackPool[20u];
    uint8_t  la_supportArray[5u];
    uint32_t l_supportbuffget;
    uint8_t  l_var8;
    uint16_t l_var16;
    uint32_t l_var32;
    uint64_t l_var64;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&l_ctxPack, la_dataPackPool, sizeof(la_dataPackPool), false) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 1  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU8(&l_ctxPack, 0x12u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16(&l_ctxPack, 0x1234u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 3  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32(&l_ctxPack, 0x12345678u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 4  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU64(&l_ctxPack, 0x123456789ABCDEF0UL) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 5  -- FAIL \n");
    }

    la_supportArray[0u] = 0xF0u;
    la_supportArray[1u] = 0xF1u;
    la_supportArray[2u] = 0xF2u;
    la_supportArray[3u] = 0xF3u;
    la_supportArray[4u] = 0xF4u;
    if( DPK_RES_OK == eCU_DPK_PushArray( &l_ctxPack, la_supportArray, sizeof(la_supportArray) ) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 6  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed(&l_ctxPack, &l_supportbuffget) )
    {
        if( 20u == l_supportbuffget )
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

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU8(&l_ctxPack, 0x12u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 8  -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctxUnPack, la_dataPackPool, sizeof(la_dataPackPool), false) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 9  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctxUnPack, l_supportbuffget) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU8(&l_ctxUnPack, &l_var8) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 11 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&l_ctxUnPack, &l_var16) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 12 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU32(&l_ctxUnPack, &l_var32) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 13 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU64(&l_ctxUnPack, &l_var64) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 14 -- FAIL \n");
    }

    la_supportArray[0u] = 0x00u;
    la_supportArray[1u] = 0x00u;
    la_supportArray[2u] = 0x00u;
    la_supportArray[3u] = 0x00u;
    la_supportArray[4u] = 0x00u;
    if( DUNPK_RES_OK == eCU_DUNPK_PopArray(&l_ctxUnPack, la_supportArray, 5u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 15 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == eCU_DUNPK_PopU8(&l_ctxUnPack, &l_var8) )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 16 -- FAIL \n");
    }

    /* Function */
    if( 0x12u == l_var8 )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 17 -- FAIL \n");
    }

    if( 0x1234u == l_var16 )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 18 -- FAIL \n");
    }

    if( 0x12345678u == l_var32 )
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackBE 19 -- FAIL \n");
    }

    if( 0x123456789ABCDEF0UL == l_var64 )
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
    s_eCU_DPK_Ctx l_ctxPack;
    s_eCU_DUNPK_Ctx l_ctxUnPack;
    uint8_t  la_dataPackPool[20u];
    uint16_t l_var16;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&l_ctxPack, la_dataPackPool, sizeof(la_dataPackPool), true) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 1  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctxUnPack, la_dataPackPool, sizeof(la_dataPackPool), true) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_StartNewPack(&l_ctxPack) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 3  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctxUnPack, 4u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 4  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32(&l_ctxPack, 0x12345678u) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 5  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&l_ctxUnPack, &l_var16) )
    {
        if( 0x5678u == l_var16 )
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

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&l_ctxUnPack, &l_var16) )
    {
        if( 0x1234u == l_var16 )
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

    if( DUNPK_RES_NODATA == eCU_DUNPK_PopU16(&l_ctxUnPack, &l_var16) )
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_TEST_dataPackUnPackGeneral 8  -- FAIL \n");
    }
}
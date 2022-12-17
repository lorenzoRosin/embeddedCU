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
static void dataPackUnPackLE(void);
static void dataPackUnPackBE(void);
static void dataPackUnPackGeneral(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void dataPackUnPackTest(void)
{
	(void)printf("\n\nDATA PACK UNPACK TEST START \n\n");

    dataPackUnPackLE();
    dataPackUnPackBE();
    dataPackUnPackGeneral();

    (void)printf("\n\nDATA PACK UNPACK END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void dataPackUnPackLE(void)
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
        (void)printf("dataPackUnPackLE 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 1  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_StartNewPack(&ctxPack) )
    {
        (void)printf("dataPackUnPackLE 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU8(&ctxPack, 0x12u) )
    {
        (void)printf("dataPackUnPackLE 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 3  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16(&ctxPack, 0x1234u) )
    {
        (void)printf("dataPackUnPackLE 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 4  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32(&ctxPack, 0x12345678u) )
    {
        (void)printf("dataPackUnPackLE 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 5  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU64(&ctxPack, 0x123456789ABCDEF0UL) )
    {
        (void)printf("dataPackUnPackLE 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 6  -- FAIL \n");
    }

    supportArray[0u] = 0xF0u;
    supportArray[1u] = 0xF1u;
    supportArray[2u] = 0xF2u;
    supportArray[3u] = 0xF3u;
    supportArray[4u] = 0xF4u;
    if( DPK_RES_OK == eCU_DPK_PushArray( &ctxPack, supportArray, sizeof(supportArray) ) )
    {
        (void)printf("dataPackUnPackLE 7  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 7  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed(&ctxPack, &supportbuffget) )
    {
        if( 20u == supportbuffget )
        {
            (void)printf("dataPackUnPackLE 8  -- OK \n");
        }
        else
        {
            (void)printf("dataPackUnPackLE 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackUnPackLE 8  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU8(&ctxPack, 0x12u) )
    {
        (void)printf("dataPackUnPackLE 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 9  -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == eCU_DUNPK_InitCtx(&ctxUnPack, dataPackPool, sizeof(dataPackPool), true) )
    {
        (void)printf("dataPackUnPackLE 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&ctxUnPack, supportbuffget) )
    {
        (void)printf("dataPackUnPackLE 11 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 11 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU8(&ctxUnPack, &var8) )
    {
        (void)printf("dataPackUnPackLE 12 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 12 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&ctxUnPack, &var16) )
    {
        (void)printf("dataPackUnPackLE 13 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 13 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU32(&ctxUnPack, &var32) )
    {
        (void)printf("dataPackUnPackLE 14 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 14 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU64(&ctxUnPack, &var64) )
    {
        (void)printf("dataPackUnPackLE 15 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 15 -- FAIL \n");
    }

    supportArray[0u] = 0x00u;
    supportArray[1u] = 0x00u;
    supportArray[2u] = 0x00u;
    supportArray[3u] = 0x00u;
    supportArray[4u] = 0x00u;
    if( DUNPK_RES_OK == eCU_DUNPK_PopArray(&ctxUnPack, supportArray, 5u) )
    {
        (void)printf("dataPackUnPackLE 16 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 16 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == eCU_DUNPK_PopU8(&ctxUnPack, &var8) )
    {
        (void)printf("dataPackUnPackLE 17 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 17 -- FAIL \n");
    }

    /* Function */
    if( 0x12u == var8 )
    {
        (void)printf("dataPackUnPackLE 18 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 18 -- FAIL \n");
    }

    if( 0x1234u == var16 )
    {
        (void)printf("dataPackUnPackLE 19 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 19 -- FAIL \n");
    }

    if( 0x12345678u == var32 )
    {
        (void)printf("dataPackUnPackLE 20 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 20 -- FAIL \n");
    }

    if( 0x123456789ABCDEF0UL == var64 )
    {
        (void)printf("dataPackUnPackLE 21 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 21 -- FAIL \n");
    }
}

void dataPackUnPackBE(void)
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
        (void)printf("dataPackUnPackBE 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 1  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU8(&ctxPack, 0x12u) )
    {
        (void)printf("dataPackUnPackBE 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU16(&ctxPack, 0x1234u) )
    {
        (void)printf("dataPackUnPackBE 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 3  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32(&ctxPack, 0x12345678u) )
    {
        (void)printf("dataPackUnPackBE 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 4  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU64(&ctxPack, 0x123456789ABCDEF0UL) )
    {
        (void)printf("dataPackUnPackBE 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 5  -- FAIL \n");
    }

    supportArray[0u] = 0xF0u;
    supportArray[1u] = 0xF1u;
    supportArray[2u] = 0xF2u;
    supportArray[3u] = 0xF3u;
    supportArray[4u] = 0xF4u;
    if( DPK_RES_OK == eCU_DPK_PushArray( &ctxPack, supportArray, sizeof(supportArray) ) )
    {
        (void)printf("dataPackUnPackBE 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 6  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_GetNPushed(&ctxPack, &supportbuffget) )
    {
        if( 20u == supportbuffget )
        {
            (void)printf("dataPackUnPackBE 7  -- OK \n");
        }
        else
        {
            (void)printf("dataPackUnPackBE 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackUnPackBE 7  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == eCU_DPK_PushU8(&ctxPack, 0x12u) )
    {
        (void)printf("dataPackUnPackBE 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 8  -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == eCU_DUNPK_InitCtx(&ctxUnPack, dataPackPool, sizeof(dataPackPool), false) )
    {
        (void)printf("dataPackUnPackBE 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 9  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&ctxUnPack, supportbuffget) )
    {
        (void)printf("dataPackUnPackBE 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU8(&ctxUnPack, &var8) )
    {
        (void)printf("dataPackUnPackBE 11 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 11 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&ctxUnPack, &var16) )
    {
        (void)printf("dataPackUnPackBE 12 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 12 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU32(&ctxUnPack, &var32) )
    {
        (void)printf("dataPackUnPackBE 13 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 13 -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU64(&ctxUnPack, &var64) )
    {
        (void)printf("dataPackUnPackBE 14 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 14 -- FAIL \n");
    }

    supportArray[0u] = 0x00u;
    supportArray[1u] = 0x00u;
    supportArray[2u] = 0x00u;
    supportArray[3u] = 0x00u;
    supportArray[4u] = 0x00u;
    if( DUNPK_RES_OK == eCU_DUNPK_PopArray(&ctxUnPack, supportArray, 5u) )
    {
        (void)printf("dataPackUnPackBE 15 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 15 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == eCU_DUNPK_PopU8(&ctxUnPack, &var8) )
    {
        (void)printf("dataPackUnPackBE 16 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 16 -- FAIL \n");
    }

    /* Function */
    if( 0x12u == var8 )
    {
        (void)printf("dataPackUnPackBE 17 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 17 -- FAIL \n");
    }

    if( 0x1234u == var16 )
    {
        (void)printf("dataPackUnPackBE 18 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 18 -- FAIL \n");
    }

    if( 0x12345678u == var32 )
    {
        (void)printf("dataPackUnPackBE 19 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 19 -- FAIL \n");
    }

    if( 0x123456789ABCDEF0UL == var64 )
    {
        (void)printf("dataPackUnPackBE 20 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 20 -- FAIL \n");
    }
}



void dataPackUnPackGeneral(void)
{
    /* Local variable */
    s_eCU_DPK_Ctx ctxPack;
    s_eCU_DUNPK_Ctx ctxUnPack;
    uint8_t  dataPackPool[20u];
    uint16_t var16;

    /* Function */
    if( DPK_RES_OK == eCU_DPK_InitCtx(&ctxPack, dataPackPool, sizeof(dataPackPool), true) )
    {
        (void)printf("dataPackUnPackGeneral 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackGeneral 1  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_InitCtx(&ctxUnPack, dataPackPool, sizeof(dataPackPool), true) )
    {
        (void)printf("dataPackUnPackGeneral 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackGeneral 2  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_StartNewPack(&ctxPack) )
    {
        (void)printf("dataPackUnPackGeneral 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackGeneral 3  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&ctxUnPack, 4u) )
    {
        (void)printf("dataPackUnPackGeneral 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackGeneral 4  -- FAIL \n");
    }

    if( DPK_RES_OK == eCU_DPK_PushU32(&ctxPack, 0x12345678u) )
    {
        (void)printf("dataPackUnPackGeneral 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackGeneral 5  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&ctxUnPack, &var16) )
    {
        if( 0x5678u == var16 )
        {
            (void)printf("dataPackUnPackGeneral 6  -- OK \n");
        }
        else
        {
            (void)printf("dataPackUnPackGeneral 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackUnPackGeneral 6  -- FAIL \n");
    }

    if( DUNPK_RES_OK == eCU_DUNPK_PopU16(&ctxUnPack, &var16) )
    {
        if( 0x1234u == var16 )
        {
            (void)printf("dataPackUnPackGeneral 7  -- OK \n");
        }
        else
        {
            (void)printf("dataPackUnPackGeneral 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackUnPackGeneral 7  -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == eCU_DUNPK_PopU16(&ctxUnPack, &var16) )
    {
        (void)printf("dataPackUnPackGeneral 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackGeneral 8  -- FAIL \n");
    }
}
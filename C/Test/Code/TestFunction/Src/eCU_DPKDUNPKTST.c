/**
 * @file       eCU_DPKDUNPKTST.c
 *
 * @brief      Data pack and unpack test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCU_DPKDUNPKTST.h"
#include "eCU_DPK.h"
#include "eCU_DUNPK.h"
#include <stdio.h>



/***********************************************************************************************************************
 *   PRIVATE FUNCTION DECLARATION
 **********************************************************************************************************************/
static void eCU_DPKDUNPKTST_LE(void);
static void eCU_DPKDUNPKTST_BE(void);
static void eCU_DPKDUNPKTST_General(void);



/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void eCU_DPKDUNPKTST_ExeTest(void)
{
	(void)printf("\n\nDATA PACK UNPACK TEST START \n\n");

    eCU_DPKDUNPKTST_LE();
    eCU_DPKDUNPKTST_BE();
    eCU_DPKDUNPKTST_General();

    (void)printf("\n\nDATA PACK UNPACK END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
static void eCU_DPKDUNPKTST_LE(void)
{
    /* Local variable */
    t_eCU_DPK_Ctx l_ctxPack;
    t_eCU_DUNPK_Ctx l_ctxUnPack;
    uint8_t  la_dataPackPool[20u];
    uint8_t  la_supportArray[5u];
    uint32_t l_supportbuffget;
    uint8_t  l_var8;
    uint16_t l_var16;
    uint32_t l_var32;
    uint64_t l_var64;

    /* Function */
    if( e_eCU_DPK_RES_OK == eCU_DPK_InitCtx(&l_ctxPack, la_dataPackPool, sizeof(la_dataPackPool), true) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 1  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_StartNewPack(&l_ctxPack) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 2  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_PushU8(&l_ctxPack, 0x12u) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 3  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_PushU16(&l_ctxPack, 0x1234u) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 4  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_PushU32(&l_ctxPack, 0x12345678u) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 5  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_PushU64(&l_ctxPack, 0x123456789ABCDEF0UL) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 6  -- FAIL \n");
    }

    la_supportArray[0u] = 0xF0u;
    la_supportArray[1u] = 0xF1u;
    la_supportArray[2u] = 0xF2u;
    la_supportArray[3u] = 0xF3u;
    la_supportArray[4u] = 0xF4u;
    if( e_eCU_DPK_RES_OK == eCU_DPK_PushArray( &l_ctxPack, la_supportArray, sizeof(la_supportArray) ) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 7  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 7  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_GetNPushed(&l_ctxPack, &l_supportbuffget) )
    {
        if( 20u == l_supportbuffget )
        {
            (void)printf("eCU_DPKDUNPKTST_LE 8  -- OK \n");
        }
        else
        {
            (void)printf("eCU_DPKDUNPKTST_LE 8  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 8  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OUTOFMEM == eCU_DPK_PushU8(&l_ctxPack, 0x12u) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 9  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctxUnPack, la_dataPackPool, sizeof(la_dataPackPool), true) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 10 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctxUnPack, l_supportbuffget) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 11 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU8(&l_ctxUnPack, &l_var8) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 12 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16(&l_ctxUnPack, &l_var16) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 13 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU32(&l_ctxUnPack, &l_var32) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 14 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU64(&l_ctxUnPack, &l_var64) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 15 -- FAIL \n");
    }

    la_supportArray[0u] = 0x00u;
    la_supportArray[1u] = 0x00u;
    la_supportArray[2u] = 0x00u;
    la_supportArray[3u] = 0x00u;
    la_supportArray[4u] = 0x00u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopArray(&l_ctxUnPack, la_supportArray, 5u) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 16 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU8(&l_ctxUnPack, &l_var8) )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 17 -- FAIL \n");
    }

    /* Function */
    if( 0x12u == l_var8 )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 18 -- FAIL \n");
    }

    if( 0x1234u == l_var16 )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 19 -- FAIL \n");
    }

    if( 0x12345678u == l_var32 )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 20 -- FAIL \n");
    }

    if( 0x123456789ABCDEF0UL == l_var64 )
    {
        (void)printf("eCU_DPKDUNPKTST_LE 21 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_LE 21 -- FAIL \n");
    }
}

static void eCU_DPKDUNPKTST_BE(void)
{
    /* Local variable */
    t_eCU_DPK_Ctx l_ctxPack;
    t_eCU_DUNPK_Ctx l_ctxUnPack;
    uint8_t  la_dataPackPool[20u];
    uint8_t  la_supportArray[5u];
    uint32_t l_supportbuffget;
    uint8_t  l_var8;
    uint16_t l_var16;
    uint32_t l_var32;
    uint64_t l_var64;

    /* Function */
    if( e_eCU_DPK_RES_OK == eCU_DPK_InitCtx(&l_ctxPack, la_dataPackPool, sizeof(la_dataPackPool), false) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 1  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_PushU8(&l_ctxPack, 0x12u) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 2  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_PushU16(&l_ctxPack, 0x1234u) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 3  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_PushU32(&l_ctxPack, 0x12345678u) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 4  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_PushU64(&l_ctxPack, 0x123456789ABCDEF0UL) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 5  -- FAIL \n");
    }

    la_supportArray[0u] = 0xF0u;
    la_supportArray[1u] = 0xF1u;
    la_supportArray[2u] = 0xF2u;
    la_supportArray[3u] = 0xF3u;
    la_supportArray[4u] = 0xF4u;
    if( e_eCU_DPK_RES_OK == eCU_DPK_PushArray( &l_ctxPack, la_supportArray, sizeof(la_supportArray) ) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 6  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 6  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_GetNPushed(&l_ctxPack, &l_supportbuffget) )
    {
        if( 20u == l_supportbuffget )
        {
            (void)printf("eCU_DPKDUNPKTST_BE 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_DPKDUNPKTST_BE 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 7  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OUTOFMEM == eCU_DPK_PushU8(&l_ctxPack, 0x12u) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 8  -- FAIL \n");
    }

    /* Function */
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctxUnPack, la_dataPackPool, sizeof(la_dataPackPool), false) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 9  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 9  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctxUnPack, l_supportbuffget) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 10 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 10 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU8(&l_ctxUnPack, &l_var8) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 11 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 11 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16(&l_ctxUnPack, &l_var16) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 12 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 12 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU32(&l_ctxUnPack, &l_var32) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 13 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 13 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU64(&l_ctxUnPack, &l_var64) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 14 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 14 -- FAIL \n");
    }

    la_supportArray[0u] = 0x00u;
    la_supportArray[1u] = 0x00u;
    la_supportArray[2u] = 0x00u;
    la_supportArray[3u] = 0x00u;
    la_supportArray[4u] = 0x00u;
    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopArray(&l_ctxUnPack, la_supportArray, 5u) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 15 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 15 -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU8(&l_ctxUnPack, &l_var8) )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 16 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 16 -- FAIL \n");
    }

    /* Function */
    if( 0x12u == l_var8 )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 17 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 17 -- FAIL \n");
    }

    if( 0x1234u == l_var16 )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 18 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 18 -- FAIL \n");
    }

    if( 0x12345678u == l_var32 )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 19 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 19 -- FAIL \n");
    }

    if( 0x123456789ABCDEF0UL == l_var64 )
    {
        (void)printf("eCU_DPKDUNPKTST_BE 20 -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_BE 20 -- FAIL \n");
    }
}

static void eCU_DPKDUNPKTST_General(void)
{
    /* Local variable */
    t_eCU_DPK_Ctx l_ctxPack;
    t_eCU_DUNPK_Ctx l_ctxUnPack;
    uint8_t  la_dataPackPool[20u];
    uint16_t l_var16;

    /* Function */
    if( e_eCU_DPK_RES_OK == eCU_DPK_InitCtx(&l_ctxPack, la_dataPackPool, sizeof(la_dataPackPool), true) )
    {
        (void)printf("eCU_DPKDUNPKTST_General 1  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_General 1  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_InitCtx(&l_ctxUnPack, la_dataPackPool, sizeof(la_dataPackPool), true) )
    {
        (void)printf("eCU_DPKDUNPKTST_General 2  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_General 2  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_StartNewPack(&l_ctxPack) )
    {
        (void)printf("eCU_DPKDUNPKTST_General 3  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_General 3  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_StartNewFrame(&l_ctxUnPack, 4u) )
    {
        (void)printf("eCU_DPKDUNPKTST_General 4  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_General 4  -- FAIL \n");
    }

    if( e_eCU_DPK_RES_OK == eCU_DPK_PushU32(&l_ctxPack, 0x12345678u) )
    {
        (void)printf("eCU_DPKDUNPKTST_General 5  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_General 5  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16(&l_ctxUnPack, &l_var16) )
    {
        if( 0x5678u == l_var16 )
        {
            (void)printf("eCU_DPKDUNPKTST_General 6  -- OK \n");
        }
        else
        {
            (void)printf("eCU_DPKDUNPKTST_General 6  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_General 6  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_OK == eCU_DUNPK_PopU16(&l_ctxUnPack, &l_var16) )
    {
        if( 0x1234u == l_var16 )
        {
            (void)printf("eCU_DPKDUNPKTST_General 7  -- OK \n");
        }
        else
        {
            (void)printf("eCU_DPKDUNPKTST_General 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_General 7  -- FAIL \n");
    }

    if( e_eCU_DUNPK_RES_NODATA == eCU_DUNPK_PopU16(&l_ctxUnPack, &l_var16) )
    {
        (void)printf("eCU_DPKDUNPKTST_General 8  -- OK \n");
    }
    else
    {
        (void)printf("eCU_DPKDUNPKTST_General 8  -- FAIL \n");
    }
}
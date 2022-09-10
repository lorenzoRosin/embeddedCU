/**
 * @file eCUDataPackUnPackTest.c
 *
 */
#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
    /* Suppressed for code clarity in test execution*/
#endif



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


/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/
void dataPackUnPackTest(void)
{
	(void)printf("\n\nDATA PACK UNPACK TEST START \n\n");

    dataPackUnPackLE();
    dataPackUnPackBE();

    (void)printf("\n\nDATA PACK UNPACK END \n\n");
}



/***********************************************************************************************************************
 *   PRIVATE FUNCTION
 **********************************************************************************************************************/
void dataPackUnPackLE(void)
{
    /* Local variable */
    s_eCU_DataPackCtx ctxPack;
    s_eCU_DataUnPackCtx ctxUnPack;
    uint8_t  dataPackPool[20u];
    uint8_t  supportArray[5u];
    uint32_t supportbuffget;
    uint8_t  var8;
    uint16_t var16;
    uint32_t var32;
    uint64_t var64;

    /* Function */
    if( DPK_RES_OK == dataPackinitCtx(&ctxPack, dataPackPool, sizeof(dataPackPool), true) )
    {
        (void)printf("dataPackUnPackLE 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 1  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackPushU8(&ctxPack, 0x12u) )
    {
        (void)printf("dataPackUnPackLE 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 2  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackPushU16(&ctxPack, 0x1234u) )
    {
        (void)printf("dataPackUnPackLE 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 3  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackPushU32(&ctxPack, 0x12345678u) )
    {
        (void)printf("dataPackUnPackLE 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 4  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackPushU64(&ctxPack, 0x123456789ABCDEF0UL) )
    {
        (void)printf("dataPackUnPackLE 5  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 5  -- FAIL \n");
    }

    supportArray[0u] = 0xF0u;
    supportArray[1u] = 0xF1u;
    supportArray[2u] = 0xF2u;
    supportArray[3u] = 0xF3u;
    supportArray[4u] = 0xF4u;
    if( DPK_RES_OK == dataPackPushArray( &ctxPack, supportArray, sizeof(supportArray) ) )
    {
        (void)printf("dataPackUnPackLE 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 6  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackGetNPushed(&ctxPack, &supportbuffget) )
    {
        if( 20u == supportbuffget )
        {
            (void)printf("dataPackUnPackLE 7  -- OK \n");
        }
        else
        {
            (void)printf("dataPackUnPackLE 7  -- FAIL \n");
        }
    }
    else
    {
        (void)printf("dataPackUnPackLE 7  -- FAIL \n");
    }

    if( DPK_RES_OUTOFMEM == dataPackPushU8(&ctxPack, 0x12u) )
    {
        (void)printf("dataPackUnPackLE 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 8  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackReset( &ctxPack ) )
    {
        (void)printf("dataPackUnPackLE 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 9  -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == dataUnPackinitCtx(&ctxUnPack, dataPackPool, supportbuffget, true) )
    {
        (void)printf("dataPackUnPackLE 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == dataUnPackPopU8(&ctxUnPack, &var8) )
    {
        (void)printf("dataPackUnPackLE 11 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 14 -- FAIL \n");
    }

    if( DUNPK_RES_OK == dataUnPackPopU16(&ctxUnPack, &var16) )
    {
        (void)printf("dataPackUnPackLE 12 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 12 -- FAIL \n");
    }

    if( DUNPK_RES_OK == dataUnPackPopU32(&ctxUnPack, &var32) )
    {
        (void)printf("dataPackUnPackLE 13 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 13 -- FAIL \n");
    }

    if( DUNPK_RES_OK == dataUnPackPopU64(&ctxUnPack, &var64) )
    {
        (void)printf("dataPackUnPackLE 14 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 14 -- FAIL \n");
    }

    supportArray[0u] = 0x00u;
    supportArray[1u] = 0x00u;
    supportArray[2u] = 0x00u;
    supportArray[3u] = 0x00u;
    supportArray[4u] = 0x00u;
    if( DUNPK_RES_OK == dataUnPackPopArray(&ctxUnPack, supportArray, 5u) )
    {
        (void)printf("dataPackUnPackLE 15 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 15 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == dataUnPackPopU8(&ctxUnPack, &var8) )
    {
        (void)printf("dataPackUnPackLE 16 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 16 -- FAIL \n");
    }

    /* Function */
    if( 0x12u == var8 )
    {
        (void)printf("dataPackUnPackLE 17 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 17 -- FAIL \n");
    }

    if( 0x1234u == var16 )
    {
        (void)printf("dataPackUnPackLE 18 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 18 -- FAIL \n");
    }

    if( 0x12345678u == var32 )
    {
        (void)printf("dataPackUnPackLE 19 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 19 -- FAIL \n");
    }

    if( 0x123456789ABCDEF0UL == var64 )
    {
        (void)printf("dataPackUnPackLE 20 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackLE 20 -- FAIL \n");
    }
}

void dataPackUnPackBE(void)
{
    /* Local variable */
    s_eCU_DataPackCtx ctxPack;
    s_eCU_DataUnPackCtx ctxUnPack;
    uint8_t  dataPackPool[20u];
    uint8_t  supportArray[5u];
    uint32_t supportbuffget;
    uint8_t  var8;
    uint16_t var16;
    uint32_t var32;
    uint64_t var64;

    /* Function */
    if( DPK_RES_OK == dataPackinitCtx(&ctxPack, dataPackPool, sizeof(dataPackPool), false) )
    {
        (void)printf("dataPackUnPackBE 1  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 1  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackPushU8(&ctxPack, 0x12u) )
    {
        (void)printf("dataPackUnPackBE 2  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 2  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackPushU16(&ctxPack, 0x1234u) )
    {
        (void)printf("dataPackUnPackBE 3  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 3  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackPushU32(&ctxPack, 0x12345678u) )
    {
        (void)printf("dataPackUnPackBE 4  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 4  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackPushU64(&ctxPack, 0x123456789ABCDEF0UL) )
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
    if( DPK_RES_OK == dataPackPushArray( &ctxPack, supportArray, sizeof(supportArray) ) )
    {
        (void)printf("dataPackUnPackBE 6  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 6  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackGetNPushed(&ctxPack, &supportbuffget) )
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

    if( DPK_RES_OUTOFMEM == dataPackPushU8(&ctxPack, 0x12u) )
    {
        (void)printf("dataPackUnPackBE 8  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 8  -- FAIL \n");
    }

    if( DPK_RES_OK == dataPackReset( &ctxPack ) )
    {
        (void)printf("dataPackUnPackBE 9  -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 9  -- FAIL \n");
    }

    /* Function */
    if( DUNPK_RES_OK == dataUnPackinitCtx(&ctxUnPack, dataPackPool, supportbuffget, false) )
    {
        (void)printf("dataPackUnPackBE 10 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 10 -- FAIL \n");
    }

    if( DUNPK_RES_OK == dataUnPackPopU8(&ctxUnPack, &var8) )
    {
        (void)printf("dataPackUnPackBE 11 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 14 -- FAIL \n");
    }

    if( DUNPK_RES_OK == dataUnPackPopU16(&ctxUnPack, &var16) )
    {
        (void)printf("dataPackUnPackBE 12 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 12 -- FAIL \n");
    }

    if( DUNPK_RES_OK == dataUnPackPopU32(&ctxUnPack, &var32) )
    {
        (void)printf("dataPackUnPackBE 13 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 13 -- FAIL \n");
    }

    if( DUNPK_RES_OK == dataUnPackPopU64(&ctxUnPack, &var64) )
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
    if( DUNPK_RES_OK == dataUnPackPopArray(&ctxUnPack, supportArray, 5u) )
    {
        (void)printf("dataPackUnPackBE 15 -- OK \n");
    }
    else
    {
        (void)printf("dataPackUnPackBE 15 -- FAIL \n");
    }

    if( DUNPK_RES_NODATA == dataUnPackPopU8(&ctxUnPack, &var8) )
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

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-20.9", "MISRAC2012-Rule-21.6"
#endif
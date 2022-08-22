/**
 * @file eCUDataPack.h
 *
 */

#ifndef ECUDATAPACK_H
#define ECUDATAPACK_H



#ifdef __cplusplus
extern "C" {
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUType.h"



/***********************************************************************************************************************
 *      TYPEDEFS
 **********************************************************************************************************************/
typedef struct
{
    bool_t isInitialized;
	bool_t isLE;
	uint8_t* memPool;
	uint32_t memPoolSize;
	uint32_t memPoolCounter;
}s_eCU_DataPackCtx

/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataPackinit(s_eCU_DataPackCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize, const bool_t isLittleEndian);
 
 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataPackReset(s_eCU_DataPackCtx* const ctx);

 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
e_eCU_Res dataPackGetData(s_eCU_DataPackCtx* const ctx, uint8_t* const dataDest, uint32_t* const retrivedLen, const uint32_t dataDestMaxSize);
 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataPackPushU8(s_eCU_DataPackCtx* const ctx, const uint8_t dataToPush);
 e_eCU_Res dataPackPushI8(s_eCU_DataPackCtx* const ctx, const int8_t  dataToPush);
 /**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataPackPushU16(s_eCU_DataPackCtx* const ctx, const uint16_t dataToPush);
 e_eCU_Res dataPackPushI16(s_eCU_DataPackCtx* const ctx, const int16_t  dataToPush); 
  /**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataPackPushU32(s_eCU_DataPackCtx* const ctx, const uint32_t dataToPush);
 e_eCU_Res dataPackPushI32(s_eCU_DataPackCtx* const ctx, const int32_t  dataToPush); 
  
  /**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataPackPushU64(s_eCU_DataPackCtx* const ctx, const uint64_t dataToPush);
 e_eCU_Res dataPackPushI64(s_eCU_DataPackCtx* const ctx, const int64_t  dataToPush); 
 
 
 
 
#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUDATAPACK_H */
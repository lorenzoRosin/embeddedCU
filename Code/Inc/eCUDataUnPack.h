/**
 * @file eCUDataUnPack.h
 *
 */

#ifndef ECUDATAUNPACK_H
#define ECUDATAUNPACK_H



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
	uint32_t memPoolFillSize;
	uint32_t memPoolCounter;
}s_eCU_DataUnPackCtx

/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataUnPackinit(s_eCU_DataUnPackCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize, const bool_t isLittleEndian);
 
 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataUnPackReset(s_eCU_DataUnPackCtx* const ctx);

 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
e_eCU_Res dataUnPackAddData(s_eCU_DataUnPackCtx* const ctx, uint8_t* const data, uint32_t const dataLen);
 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataUnPackPopU8(s_eCU_DataUnPackCtx* const ctx, uint8_t* dataToPop);
 e_eCU_Res dataUnPackPopI8(s_eCU_DataUnPackCtx* const ctx, int8_t*  dataToPop);
 /**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataUnPackPopU16(s_eCU_DataUnPackCtx* const ctx, uint16_t* dataToPop);
 e_eCU_Res dataUnPackPopI16(s_eCU_DataUnPackCtx* const ctx, int16_t * dataToPop); 
  /**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataUnPackPopU32(s_eCU_DataUnPackCtx* const ctx, uint32_t* dataToPop);
 e_eCU_Res dataUnPackPopI32(s_eCU_DataUnPackCtx* const ctx, int32_t*  dataToPop); 
  
  /**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res dataUnPackPopU64(s_eCU_DataUnPackCtx* const ctx, uint64_t* dataToPop);
 e_eCU_Res dataUnPackPopI64(s_eCU_DataUnPackCtx* const ctx, int64_t*  dataToPop); 
 




#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUDATAUNPACK_H */
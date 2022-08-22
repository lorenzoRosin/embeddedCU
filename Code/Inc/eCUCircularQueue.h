/**
 * @file eCUCircularQueue.h
 *
 */

#ifndef ECUCIRCULARQUEUE_H
#define ECUCIRCULARQUEUE_H



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
	uint8_t* memPool;
	uint32_t memPoolSize;
	uint32_t memPoolOccupiedSize;
	uint32_t memPoolFirstFreeByteIndex;
	uint32_t memPoolFirstOccupiedByteIndex;
}s_eCU_CircularQueueCtx

/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res circularQueueInit(s_eCU_CircularQueueCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize);
 
 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res circularQueueReset(s_eCU_CircularQueueCtx* const ctx);
 
 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res circularQueueGetFreeSapce(s_eCU_CircularQueueCtx* const ctx, uint32_t* freeSpace);
  
 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res circularQueueGetOccupiedSapce(s_eCU_CircularQueueCtx* const ctx, uint32_t* occupiedSpace);
 
   
 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res circularQueueInsertData(s_eCU_CircularQueueCtx* const ctx, uint32_t* data, uint32_t datalen);
 
 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res circularQueueRetriveData(s_eCU_CircularQueueCtx* const ctx, uint32_t* data, uint32_t datalen);
 
 
/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
 e_eCU_Res circularQueuePeekData(s_eCU_CircularQueueCtx* const ctx, uint32_t* data, uint32_t datalen);
 
 
 
 
 
 
 
 
#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCIRCULARQUEUE_H */
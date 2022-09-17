/**
 * @file       eCUCircularQueue.h
 *
 * @brief      Circular Queue utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

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
typedef enum
{
    CQUEUE_RES_OK = 0,
    CQUEUE_RES_BADPARAM,
    CQUEUE_RES_BADPOINTER,
	CQUEUE_RES_CORRUPTCTX,
	CQUEUE_RES_FULL,
    CQUEUE_RES_EMPTY,
    CQUEUE_RES_NOINITLIB,
}e_eCU_cQueue_Res;

typedef struct
{
    bool_t   isInit;
    uint8_t* memPool;
    uint32_t memPoolSize;
    uint32_t memPoolUsedSize;
    uint32_t memPoolFrstFreeIdx;
    uint32_t memPoolFrstOccIdx;
}s_eCU_circQCtx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Initialize the circular queue context
 *
 * @param[in]   ctx         - Circular queue context
 * @param[in]   memPool     - Pointer to a memory buffer that we will use to manage the circular queue
 * @param[out]  memPoolSize - Dimension in byte of the circular queue
 *
 * @return      CQUEUE_RES_BADPOINTER   - In case of bad pointer passed to the function
 *              CQUEUE_RES_BADPARAM     - In case of bad parameter passed to the function
 *              CQUEUE_RES_OK           - Circular queue initialized successfully
 */
e_eCU_cQueue_Res circQInitCtx(s_eCU_circQCtx* const ctx, uint8_t* memPool, const uint32_t memPoolSize);

/**
 * @brief       Reset the state of the circular queue and discharge all saved data
 *
 * @param[in]   ctx         - Circular queue context
 *
 * @return      CQUEUE_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CQUEUE_RES_NOINITLIB    - Need to init the queue before taking some action
 *		        CQUEUE_RES_CORRUPTCTX   - In case of an corrupted context
 *              CQUEUE_RES_OK           - Circular queue resetted successfully
 */
e_eCU_cQueue_Res circQReset(s_eCU_circQCtx* const ctx);

/**
 * @brief       Get free space present in the queue
 *
 * @param[in]   ctx         - Circular queue context
 * @param[out]  freeSpace  - Pointer to variable where free space present in queue will be stored
 *
 * @return      CQUEUE_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CQUEUE_RES_NOINITLIB    - Need to init the queue before taking some action
 *		        CQUEUE_RES_CORRUPTCTX   - In case of an corrupted context
 *              CQUEUE_RES_OK           - Operation ended successfully
 */
e_eCU_cQueue_Res circQGetFreeSapce(s_eCU_circQCtx* const ctx, uint32_t* const freeSpace);

/**
 * @brief       Get used space present in the queue
 *
 * @param[in]   ctx         - Circular queue context
 * @param[out]  usedSpace  - Pointer to variable where used space present in queue will be stored
 *
 * @return      CQUEUE_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CQUEUE_RES_NOINITLIB    - Need to init the queue before taking some action
 *		        CQUEUE_RES_CORRUPTCTX   - In case of an corrupted context
 *              CQUEUE_RES_OK           - Operation ended successfully
 */
e_eCU_cQueue_Res circQGetOccupiedSapce(s_eCU_circQCtx* const ctx, uint32_t* const usedSpace);

/**
 * @brief       Insert data in the queue if free space is avaiable
 *
 * @param[in]   ctx         - Circular queue context
 * @param[in]   data        - Pointer to the data that we want to insert in the queue
 * @param[in]   datalen     - Lenght of the data present in the pointer passed
 *
 * @return      CQUEUE_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CQUEUE_RES_NOINITLIB    - Need to init the queue before taking some action
 *              CQUEUE_RES_BADPARAM     - In case of bad parameter passed to the function
 *		        CQUEUE_RES_FULL         - Queue full, can't push this amount of data
 *		        CQUEUE_RES_CORRUPTCTX   - In case of an corrupted context
 *              CQUEUE_RES_OK           - Operation ended successfully
 */
e_eCU_cQueue_Res circQInsertData(s_eCU_circQCtx* const ctx, const uint8_t* data, const uint32_t datalen);

/**
 * @brief       Retrive data from the queue if avaiable
 *
 * @param[in]   ctx         - Circular queue context
 * @param[out]  data        - Pointer to the buffer that will contain retrived data from queue
 * @param[in]   datalen     - Lenght of the data that we want to retrive
 *
 * @return      CQUEUE_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CQUEUE_RES_NOINITLIB    - Need to init the queue before taking some action
 *              CQUEUE_RES_BADPARAM     - In case of bad parameter passed to the function
 *		        CQUEUE_RES_EMPTY        - Not so many byte present in queue
 *		        CQUEUE_RES_CORRUPTCTX   - In case of an corrupted context
 *              CQUEUE_RES_OK           - Operation ended successfully
 */
e_eCU_cQueue_Res circQRetriveData(s_eCU_circQCtx* const ctx, uint8_t* const data, const uint32_t datalen);

/**
 * @brief       Peek data from the queue if avaiable
 *
 * @param[in]   ctx         - Circular queue context
 * @param[out]  data        - Pointer to the buffer that will contain retrived data from queue
 * @param[in]   datalen     - Lenght of the data that we want to peek
 *
 * @return      CQUEUE_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CQUEUE_RES_NOINITLIB    - Need to init the queue before taking some action
 *              CQUEUE_RES_BADPARAM     - In case of bad parameter passed to the function
 *		        CQUEUE_RES_EMPTY        - Not so many byte present in queue
 *		        CQUEUE_RES_CORRUPTCTX   - In case of an corrupted context
 *              CQUEUE_RES_OK           - Operation ended successfully
 */
e_eCU_cQueue_Res circQPeekData(s_eCU_circQCtx* const ctx, uint8_t* const data, const uint32_t datalen);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCIRCULARQUEUE_H */
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
    CIRQ_RES_OK = 0,
    CIRQ_RES_BADPARAM,
    CIRQ_RES_BADPOINTER,
	CIRQ_RES_CORRUPTCTX,
	CIRQ_RES_FULL,
    CIRQ_RES_EMPTY,
    CIRQ_RES_NOINITLIB,
}e_eCU_CIRQ_Res;

typedef struct
{
    bool_t   isInit;
    uint8_t* p_memP;
    uint32_t memPSize;
    uint32_t memPUsedSize;
    uint32_t memPFreeIdx;
}s_eCU_CIRQ_Ctx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Initialize the circular queue context
 *
 * @param[in]   p_ctx       - Circular queue context
 * @param[in]   memP        - Pointer to a memory buffer that we will use to manage the circular queue
 * @param[in]   memPSize    - Dimension in byte of the memory buffer
 *
 * @return      CIRQ_RES_BADPOINTER   - In case of bad pointer passed to the function
 *              CIRQ_RES_BADPARAM     - In case of bad parameter passed to the function
 *              CIRQ_RES_OK           - Circular queue initialized successfully
 */
e_eCU_CIRQ_Res eCU_CIRQ_InitCtx(s_eCU_CIRQ_Ctx* const p_ctx, uint8_t a_memP[], const uint32_t memPSize);

/**
 * @brief       Check if the lib is initialized
 *
 * @param[in]   p_ctx         - Circular queue context
 * @param[out]  p_isInit      - Pointer to a bool_t variable that will be filled with true if the lib is initialized
 *
 * @return      CIRQ_RES_BADPOINTER    - In case of bad pointer passed to the function
 *              CIRQ_RES_OK            - Operation ended correctly
 */
e_eCU_CIRQ_Res eCU_CIRQ_IsInit(s_eCU_CIRQ_Ctx* const p_ctx, bool_t* p_isInit);

/**
 * @brief       Reset the state of the circular queue and discharge all saved data
 *
 * @param[in]   p_ctx         - Circular queue context
 *
 * @return      CIRQ_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CIRQ_RES_NOINITLIB    - Need to init the queue before taking some action
 *		        CIRQ_RES_CORRUPTCTX   - In case of an corrupted context
 *              CIRQ_RES_OK           - Circular queue resetted successfully
 */
e_eCU_CIRQ_Res eCU_CIRQ_Reset(s_eCU_CIRQ_Ctx* const p_ctx);

/**
 * @brief       Get free space present in the queue
 *
 * @param[in]   p_ctx           - Circular queue context
 * @param[out]  p_freeSpace     - Pointer to variable where free space present in queue will be stored
 *
 * @return      CIRQ_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CIRQ_RES_NOINITLIB    - Need to init the queue before taking some action
 *		        CIRQ_RES_CORRUPTCTX   - In case of an corrupted context
 *              CIRQ_RES_OK           - Operation ended successfully
 */
e_eCU_CIRQ_Res eCU_CIRQ_GetFreeSapce(s_eCU_CIRQ_Ctx* const p_ctx, uint32_t* const p_freeSpace);

/**
 * @brief       Get used space present in the queue
 *
 * @param[in]   p_ctx         - Circular queue context
 * @param[out]  p_usedSpace   - Pointer to variable where used space present in queue will be stored
 *
 * @return      CIRQ_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CIRQ_RES_NOINITLIB    - Need to init the queue before taking some action
 *		        CIRQ_RES_CORRUPTCTX   - In case of an corrupted context
 *              CIRQ_RES_OK           - Operation ended successfully
 */
e_eCU_CIRQ_Res eCU_CIRQ_GetOccupiedSapce(s_eCU_CIRQ_Ctx* const p_ctx, uint32_t* const p_usedSpace);

/**
 * @brief       Insert data in the queue if free space is avaiable
 *
 * @param[in]   p_ctx         - Circular queue context
 * @param[in]   a_data        - Pointer to the data that we want to insert in the queue
 * @param[in]   datalen     - Lenght of the data present in the pointer passed
 *
 * @return      CIRQ_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CIRQ_RES_NOINITLIB    - Need to init the queue before taking some action
 *              CIRQ_RES_BADPARAM     - In case of bad parameter passed to the function
 *		        CIRQ_RES_FULL         - Queue full, can't push this amount of data
 *		        CIRQ_RES_CORRUPTCTX   - In case of an corrupted context
 *              CIRQ_RES_OK           - Operation ended successfully
 */
e_eCU_CIRQ_Res eCU_CIRQ_InsertData(s_eCU_CIRQ_Ctx* const p_ctx, const uint8_t a_data[], const uint32_t datalen);

/**
 * @brief       Retrive data from the queue if avaiable
 *
 * @param[in]   p_ctx           - Circular queue context
 * @param[out]  a_data          - Pointer to the buffer that will contain retrived data from queue
 * @param[in]   datalen         - Lenght of the data that we want to retrive
 *
 * @return      CIRQ_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CIRQ_RES_NOINITLIB    - Need to init the queue before taking some action
 *              CIRQ_RES_BADPARAM     - In case of bad parameter passed to the function
 *		        CIRQ_RES_EMPTY        - Not so many byte present in queue
 *		        CIRQ_RES_CORRUPTCTX   - In case of an corrupted context
 *              CIRQ_RES_OK           - Operation ended successfully
 */
e_eCU_CIRQ_Res eCU_CIRQ_RetriveData(s_eCU_CIRQ_Ctx* const p_ctx, uint8_t a_data[], const uint32_t datalen);

/**
 * @brief       Peek data from the queue if avaiable
 *
 * @param[in]   p_ctx           - Circular queue context
 * @param[out]  a_data          - Pointer to the buffer that will contain retrived data from queue
 * @param[in]   datalen         - Lenght of the data that we want to peek
 *
 * @return      CIRQ_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        CIRQ_RES_NOINITLIB    - Need to init the queue before taking some action
 *              CIRQ_RES_BADPARAM     - In case of bad parameter passed to the function
 *		        CIRQ_RES_EMPTY        - Not so many byte present in queue
 *		        CIRQ_RES_CORRUPTCTX   - In case of an corrupted context
 *              CIRQ_RES_OK           - Operation ended successfully
 */
e_eCU_CIRQ_Res eCU_CIRQ_PeekData(s_eCU_CIRQ_Ctx* const p_ctx, uint8_t a_data[], const uint32_t datalen);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCIRCULARQUEUE_H */
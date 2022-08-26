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
    bool_t isInit;
	bool_t isLE;
	uint8_t* memPool;
	uint32_t memPoolSize;
	uint32_t memPoolCntr;
}s_eCU_DataPackCtx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * Initialize the data packer context
 * @param ctx Data packer context
 * @param memPool Pointer to a memory pool that we will use to manage the data packer
 * @param memPoolSize Dimension in byte of the data packer pool
 * @param isLEnd Select if data packer must work in Little Endian or Big Endian
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OK data packer is initialized correctly
 */
e_eCU_Res dataPackinit(s_eCU_DataPackCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize,
					   const bool_t isLEnd);

/**
 * Reset data packer and discharge stored data
 * @param ctx Data packer context
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data packer before taking some action
 *         ECU_RES_OK operation ended correctly
 */
e_eCU_Res dataPackReset(s_eCU_DataPackCtx* const ctx);

/**
 * Retrive how many byte we have stored
 * @param ctx Data packer context
 * @param retrivedLen Pointer to a memory area were we will store size of serialized data
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data packer before taking some action
 *         ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OK operation ended correctly
 */
e_eCU_Res dataPackGetDataSize(s_eCU_DataPackCtx* const ctx, uint32_t* const retrivedLen);

/**
 * Retrive all data serialized and reset the datapacker
 * @param ctx Data packer context
 * @param dataDest Pointer to a memory area
 * @param retrivedLen Pointer to a memory area were we will store size of serialized data
 * @param dataDestMaxSize Max destination buffer capability
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data packer before taking some action
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OUTOFMEM Not enought memory to copy all the data
 *         ECU_RES_OK circular queue is initialized correctly
 */
e_eCU_Res dataPackConsumeAllData(s_eCU_DataPackCtx* const ctx, uint8_t* const dataDest, uint32_t* const retrivedLen,
								 const uint32_t dataDestMaxSize);

/**
 * Push an array in data packer
 * @param ctx Data packer context
 * @param data Pointer to a memory area where data are stored
 * @param dataLen  data size
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data packer before taking some action
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OUTOFMEM Not enought memory to copy all the data
 *         ECU_RES_OK circular queue is initialized correctly
 */
e_eCU_Res dataPackPushArray(s_eCU_DataPackCtx* const ctx, const uint8_t* data, const uint32_t dataLen);

/**
 * Push one byte in data packer
 * @param ctx Data packer context
 * @param dataToPush Byte to push in data packer
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data packer before taking some action
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OUTOFMEM Not enought memory to copy all the data
 *         ECU_RES_OK circular queue is initialized correctly
 */
e_eCU_Res dataPackPushU8(s_eCU_DataPackCtx* const ctx, const uint8_t dataToPush);

/**
 * Push 2 byte in data packer
 * @param ctx Data packer context
 * @param dataToPush Byte to push in data packer
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data packer before taking some action
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OUTOFMEM Not enought memory to copy all the data
 *         ECU_RES_OK circular queue is initialized correctly
 */
e_eCU_Res dataPackPushU16(s_eCU_DataPackCtx* const ctx, const uint16_t dataToPush);

/**
 * Push 4 byte in data packer
 * @param ctx Data packer context
 * @param dataToPush Byte to push in data packer
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data packer before taking some action
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OUTOFMEM Not enought memory to copy all the data
 *         ECU_RES_OK circular queue is initialized correctly
 */
e_eCU_Res dataPackPushU32(s_eCU_DataPackCtx* const ctx, const uint32_t dataToPush);

/**
 * Push 8 byte in data packer
 * @param ctx Data packer context
 * @param dataToPush Byte to push in data packer
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data packer before taking some action
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OUTOFMEM Not enought memory to copy all the data
 *         ECU_RES_OK circular queue is initialized correctly
 */
 e_eCU_Res dataPackPushU64(s_eCU_DataPackCtx* const ctx, const uint64_t dataToPush);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUDATAPACK_H */
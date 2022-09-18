/**
 * @file       eCUDataPack.h
 *
 * @brief      Data pack utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

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
typedef enum
{
    DPK_RES_OK = 0,
    DPK_RES_BADPARAM,
    DPK_RES_BADPOINTER,
	DPK_RES_CORRUPTCTX,
    DPK_RES_OUTOFMEM,
    DPK_RES_NOINITLIB,
}e_eCU_dPk_Res;

typedef struct
{
    bool_t isInit;
	bool_t isLE;
	uint8_t* memPKA;
	uint32_t memPKASize;
	uint32_t memPKACntr;
}s_eCU_DataPackCtx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Initialize the data packer context
 *
 * @param[in]   ctx         - Data packer context
 * @param[in]   memPKA      - Pointer to a memory area that we will fill with packet data
 * @param[in]   memPKASize  - Dimension in byte of the data packer area
 * @param[in]   isLEnd      - Select if data packer must work in Little Endian or Big Endian
 *
 * @return      DPK_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        DPK_RES_BADPARAM     - In case of an invalid parameter passed to the function
 *              DPK_RES_OK           - Operation ended correctly
 */
e_eCU_dPk_Res dataPackinitCtx(s_eCU_DataPackCtx* const ctx, uint8_t* const memPKA, const uint32_t memPKASize,
					          const bool_t isLEnd);

/**
 * @brief       Reset data packer and restart packing data from start, discharging old data present
 *
 * @param[in]   ctx         - Data packer context
 *
 * @return      DPK_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        DPK_RES_NOINITLIB    - Need to init the data packer before taking some action
 *		        DPK_RES_CORRUPTCTX   - In case of a corrupted context
 *              DPK_RES_OK           - Operation ended correctly
 */
e_eCU_dPk_Res dataPackStartNewPack(s_eCU_DataPackCtx* const ctx);

/**
 * @brief       Retrive the pointer to the stored packed data, and the data size of the packed data buffer.
 *
 * @param[in]   ctx         - Data packer context
 * @param[out]  dataP       - Pointer to a Pointer pointing to the packed data buffer
 * @param[out]  retrivedLen - Pointer to a uint32_t variable where the size of the packed data buffer will be placed
 *
 * @return      DPK_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        DPK_RES_NOINITLIB    - Need to init the data packer before taking some action
 *		        DPK_RES_CORRUPTCTX   - In case of a corrupted context
 *              DPK_RES_OK           - Operation ended correctly
 */
e_eCU_dPk_Res dataPackGetDataReference(s_eCU_DataPackCtx* const ctx, uint8_t** dataP, uint32_t* const retrivedLen);

/**
 * @brief       Retrive how many byte we have packed
 *
 * @param[in]   ctx         - Data packer context
 * @param[out]  retrivedLen - Pointer to a uint32_t variable where the size of the packed data buffer will be placed
 *
 * @return      DPK_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        DPK_RES_NOINITLIB    - Need to init the data packer before taking some action
 *		        DPK_RES_CORRUPTCTX   - In case of a corrupted context
 *              DPK_RES_OK           - Operation ended correctly
 */
e_eCU_dPk_Res dataPackGetNPushed(s_eCU_DataPackCtx* const ctx, uint32_t* const retrivedLen);

/**
 * @brief       Push an array in data packer
 *
 * @param[in]   ctx         - Data packer context
 * @param[in]   data        - Pointer to a memory area containing the data that we want to push
 * @param[in]   dataLen     - Data size of the data that we want to push
 *
 * @return      DPK_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        DPK_RES_NOINITLIB    - Need to init the data packer before taking some action
 *		        DPK_RES_BADPARAM     - In case of an invalid parameter passed to the function
 *		        DPK_RES_CORRUPTCTX   - In case of a corrupted context
 *              DPK_RES_OUTOFMEM     - Not enought memory to push other data
 *              DPK_RES_OK           - Operation ended correctly
 */
e_eCU_dPk_Res dataPackPushArray(s_eCU_DataPackCtx* const ctx, const uint8_t* data, const uint32_t dataLen);

/**
 * @brief       Push one byte in data packer
 *
 * @param[in]   ctx         - Data packer context
 * @param[in]   dataToPush  - Data to push in data packer
 *
 * @return      DPK_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        DPK_RES_NOINITLIB    - Need to init the data packer before taking some action
 *		        DPK_RES_CORRUPTCTX   - In case of a corrupted context
 *              DPK_RES_OUTOFMEM     - Not enought memory to push other data
 *              DPK_RES_OK           - Operation ended correctly
 */
e_eCU_dPk_Res dataPackPushU8(s_eCU_DataPackCtx* const ctx, const uint8_t dataToPush);

/**
 * @brief       Push 2 byte in data packer
 *
 * @param[in]   ctx         - Data packer context
 * @param[in]   dataToPush  - Data to push in data packer
 *
 * @return      DPK_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        DPK_RES_NOINITLIB    - Need to init the data packer before taking some action
 *		        DPK_RES_CORRUPTCTX   - In case of a corrupted context
 *              DPK_RES_OUTOFMEM     - Not enought memory to push other data
 *              DPK_RES_OK           - Operation ended correctly
 */
e_eCU_dPk_Res dataPackPushU16(s_eCU_DataPackCtx* const ctx, const uint16_t dataToPush);

/**
 * @brief       Push 4 byte in data packer
 *
 * @param[in]   ctx         - Data packer context
 * @param[in]   dataToPush  - Data to push in data packer
 *
 * @return      DPK_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        DPK_RES_NOINITLIB    - Need to init the data packer before taking some action
 *		        DPK_RES_CORRUPTCTX   - In case of a corrupted context
 *              DPK_RES_OUTOFMEM     - Not enought memory to push other data
 *              DPK_RES_OK           - Operation ended correctly
 */
e_eCU_dPk_Res dataPackPushU32(s_eCU_DataPackCtx* const ctx, const uint32_t dataToPush);

/**
 * @brief       Push 8 byte in data packer
 *
 * @param[in]   ctx         - Data packer context
 * @param[in]   dataToPush  - Data to push in data packer
 *
 * @return      DPK_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        DPK_RES_NOINITLIB    - Need to init the data packer before taking some action
 *		        DPK_RES_CORRUPTCTX   - In case of a corrupted context
 *              DPK_RES_OUTOFMEM     - Not enought memory to push other data
 *              DPK_RES_OK           - Operation ended correctly
 */
 e_eCU_dPk_Res dataPackPushU64(s_eCU_DataPackCtx* const ctx, const uint64_t dataToPush);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUDATAPACK_H */
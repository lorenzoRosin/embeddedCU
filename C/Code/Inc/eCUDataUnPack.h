/**
 * @file       eCUDataUnPack.h
 *
 * @brief      Data pack utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

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
typedef enum
{
    DUNPK_RES_OK = 0,
    DUNPK_RES_BADPARAM,
    DUNPK_RES_BADPOINTER,
	DUNPK_RES_CORRUPTCTX,
    DUNPK_RES_NODATA,
    DUNPK_RES_NOINITLIB,
    DUNPK_RES_NOINITFRAME,
}e_eCU_dUnpk_Res;

typedef struct
{
    bool_t isInit;
	bool_t isLE;
	uint8_t* memUPKA;
	uint32_t memUPKASize;
    uint32_t memUPKAFrameSize;
	uint32_t memUPKACntr;
}s_eCU_DataUnPackCtx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Initialize the data unpacker context
 *
 * @param[in]   ctx         - Data Unpacker context
 * @param[in]   memUPKA     - Pointer to a memory area that we will use to store data that needs to be unpacked
 * @param[in]   memUPKASize - Dimension in byte of the data unpacker area
 * @param[in]   isLEnd      - Select if data unpacker must work in Little Endian or Big Endian
 *
 * @return      DUNPK_RES_BADPOINTER - In case of bad pointer passed to the function
 *		        DUNPK_RES_BADPARAM   - In case of an invalid parameter passed to the function
 *              DUNPK_RES_OK         - Operation ended correctly
 */
e_eCU_dUnpk_Res dataUnPackinitCtx(s_eCU_DataUnPackCtx* const ctx, uint8_t memUPKA[], const uint32_t memUPKASize,
                                  const bool_t isLEnd);

/**
 * @brief       Start to unpack a new frame given the dimension of raw payload it self. This function suppouse that
 *              data payload that need to be unpocked were already copied in memory.( see dataUnPackGetUPkDataLocat
 *              in order to know how get the data pointer )
 *
 * @param[in]   ctx         - Data Unpacker context
 * @param[in]   frameLen    - lenght of the raw data present in the frame that we need to unpack
 *
 * @return      DUNPK_RES_BADPOINTER - In case of bad pointer passed to the function
 *		        DUNPK_RES_BADPARAM   - In case of an invalid parameter passed to the function
 *		        DUNPK_RES_NOINITLIB  - Need to init the data unpacker before taking some action
 *		        DUNPK_RES_CORRUPTCTX - In case of a corrupted context
 *              DUNPK_RES_OK         - Operation ended correctly
 */
e_eCU_dUnpk_Res dataUnPackStartNewFrame(s_eCU_DataUnPackCtx* const ctx, const uint32_t frameLen);

/**
 * @brief       Retrive the pointer of the buffer that the user can use to insert data payload that need to be unpacked
 *
 * @param[in]   ctx         - Data Unpacker context
 * @param[out]  dataP       - Pointer to a Pointer where the raw data needs to be copied before starting a session
 * @param[out]  maxDataSize - Pointer to a uint32_t variable where the max number of data that can be copied in dataP
 *                            will be placed
 *
 * @return      DUNPK_RES_BADPOINTER - In case of bad pointer passed to the function
 *		        DUNPK_RES_NOINITLIB  - Need to init the data unpacker before taking some action
 *		        DUNPK_RES_CORRUPTCTX - In case of a corrupted context
 *              DUNPK_RES_OK         - Operation ended correctly
 */
e_eCU_dUnpk_Res dataUnPackGetUPkDataLocat(s_eCU_DataUnPackCtx* const ctx, uint8_t** dataP, uint32_t* const maxDataSize);


/**
 * @brief       Reset data unpacker status and restart from start un packing. This will not delete or start a new
 *              session. This function will simply restart the packing process of already loaded data.
 *
 * @param[in]   ctx         - Data Unpacker context
 *
 * @return      DUNPK_RES_BADPOINTER  - In case of bad pointer passed to the function
 *		        DUNPK_RES_NOINITLIB   - Need to init the data unpacker before taking some action
 *		        DUNPK_RES_NOINITFRAME - Need to start a frame before restarting the current frame
 *		        DUNPK_RES_CORRUPTCTX  - In case of a corrupted context
 *              DUNPK_RES_OK          - Operation ended correctly
 */
e_eCU_dUnpk_Res dataUnPackRestartCurrentUnpack(s_eCU_DataUnPackCtx* const ctx);

/**
 * @brief       Retrive how many byte we can still pop
 *
 * @param[in]   ctx         - Data Unpacker context
 * @param[out]  retrivedLen - Pointer to a memory area were we will store the size of the remaining poppable data
 *
 * @return      DUNPK_RES_BADPOINTER  - In case of bad pointer passed to the function
 *		        DUNPK_RES_NOINITLIB   - Need to init the data unpacker before taking some action
 *		        DUNPK_RES_NOINITFRAME - Need to start a frame before restarting the current frame
 *		        DUNPK_RES_CORRUPTCTX  - In case of a corrupted context
 *              DUNPK_RES_OK          - Operation ended correctly
 */
e_eCU_dUnpk_Res dataUnPackGetRemToPop(s_eCU_DataUnPackCtx* const ctx, uint32_t* const retrivedLen);

/**
 * @brief       Pop some raw data
 *
 * @param[in]   ctx         - Data Unpacker context
 * @param[out]  dataDest    - Pointer to a memory area where popped data will be copied
 * @param[out]  retrivedLen - The amount of data that need to be copied in dataDest
 *
 * @return      DUNPK_RES_BADPOINTER  - In case of bad pointer passed to the function
 *		        DUNPK_RES_NOINITLIB   - Need to init the data unpacker before taking some action
 *		        DUNPK_RES_BADPARAM    - In case of an invalid parameter passed to the function
 *		        DUNPK_RES_NOINITFRAME - Need to start a frame before restarting the current frame
 *		        DUNPK_RES_CORRUPTCTX  - In case of a corrupted context
 *              DUNPK_RES_NODATA      - Not so much data to pop
 *              DUNPK_RES_OK          - Operation ended correctly
 */
e_eCU_dUnpk_Res dataUnPackPopArray(s_eCU_DataUnPackCtx* const ctx, uint8_t dataDest[], uint32_t const toRetrivedLen);

/**
 * @brief       Pop one byte from data packeted passed to session
 *
 * @param[in]   ctx         - Data Unpacker context
 * @param[out]  dataP       - Pointer to a variable that will contain the popped data
 *
 * @return      DUNPK_RES_BADPOINTER  - In case of bad pointer passed to the function
 *		        DUNPK_RES_NOINITLIB   - Need to init the data unpacker before taking some action
 *		        DUNPK_RES_NOINITFRAME - Need to start a frame before restarting the current frame
 *		        DUNPK_RES_CORRUPTCTX  - In case of a corrupted context
 *              DUNPK_RES_NODATA      - Not so much data to pop
 *              DUNPK_RES_OK          - Operation ended correctly
 */
e_eCU_dUnpk_Res dataUnPackPopU8(s_eCU_DataUnPackCtx* const ctx, uint8_t* dataP);

/**
 * @brief       Pop 2 byte from data packeted passed to session
 *
 * @param[in]   ctx         - Data Unpacker context
 * @param[out]  dataP       - Pointer to a variable that will contain the popped data
 *
 * @return      DUNPK_RES_BADPOINTER  - In case of bad pointer passed to the function
 *		        DUNPK_RES_NOINITLIB   - Need to init the data unpacker before taking some action
 *		        DUNPK_RES_NOINITFRAME - Need to start a frame before restarting the current frame
 *		        DUNPK_RES_CORRUPTCTX  - In case of a corrupted context
 *              DUNPK_RES_NODATA      - Not so much data to pop
 *              DUNPK_RES_OK          - Operation ended correctly
 */
e_eCU_dUnpk_Res dataUnPackPopU16(s_eCU_DataUnPackCtx* const ctx, uint16_t* dataP);

/**
 * @brief       Pop 4 byte from data packeted passed to session
 *
 * @param[in]   ctx         - Data Unpacker context
 * @param[out]  dataP       - Pointer to a variable that will contain the popped data
 *
 * @return      DUNPK_RES_BADPOINTER  - In case of bad pointer passed to the function
 *		        DUNPK_RES_NOINITLIB   - Need to init the data unpacker before taking some action
 *		        DUNPK_RES_NOINITFRAME - Need to start a frame before restarting the current frame
 *		        DUNPK_RES_CORRUPTCTX  - In case of a corrupted context
 *              DUNPK_RES_NODATA      - Not so much data to pop
 *              DUNPK_RES_OK          - Operation ended correctly
 */
e_eCU_dUnpk_Res dataUnPackPopU32(s_eCU_DataUnPackCtx* const ctx, uint32_t* dataP);

/**
 * @brief       Pop 8 byte from data packeted passed to session
 *
 * @param[in]   ctx         - Data Unpacker context
 * @param[out]  dataP       - Pointer to a variable that will contain the popped data
 *
 * @return      DUNPK_RES_BADPOINTER  - In case of bad pointer passed to the function
 *		        DUNPK_RES_NOINITLIB   - Need to init the data unpacker before taking some action
 *		        DUNPK_RES_NOINITFRAME - Need to start a frame before restarting the current frame
 *		        DUNPK_RES_CORRUPTCTX  - In case of a corrupted context
 *              DUNPK_RES_NODATA      - Not so much data to pop
 *              DUNPK_RES_OK          - Operation ended correctly
 */
e_eCU_dUnpk_Res dataUnPackPopU64(s_eCU_DataUnPackCtx* const ctx, uint64_t* dataP);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUDATAUNPACK_H */
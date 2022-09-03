/**
 * @file eCUByteUnStuffer.h
 *
 */

#ifndef ECUBYTEUNSTUFFER_H
#define ECUBYTEUNSTUFFER_H



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
    bool_t   isInit;
	uint8_t* memArea;
	uint32_t memAreaSize;
	uint32_t memAreaCntr;
    bool_t   precedentWasEsc;
    bool_t   needSof;
    bool_t   needEof;
}e_eCU_BUStuffCtx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * Initialize the byte unstuffer context
 * @param  ctx Byte Unstuffer context
 * @param  memPool Pointer to a memory area that we will use to save unstuffed data
 * @param  memPoolSize Dimension in byte of the memory area
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OK circular queue is initialized correctly
 */
e_eCU_Res bUStuffer_initCtx(e_eCU_BUStuffCtx* const ctx, uint8_t* const memArea, const uint32_t memAreaSize);

/**
 * Reset data Unstuffer and restart from memory start
 * @param  ctx Byte Unstuffer context
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data unstuffer context before taking some action
 *         ECU_RES_OK operation ended correctly
 */
e_eCU_Res bUStuffer_reset(e_eCU_BUStuffCtx* const ctx);

/**
 * Retrive how many raw byte we have unstuffed
 * @param  ctx Byte Unstuffer context
 * @param  retrivedLen Pointer to a memory area were we will store size of the unstuffed raw data
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data unstuffer context before taking some action
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OK operation ended correctly
 */
e_eCU_Res bUStuffer_getDataSize(e_eCU_BUStuffCtx* const ctx, uint32_t* const retrivedLen);

/**
 * Insert stuffed data chunk
 * @param  ctx Byte Unstuffer context
 * @param  stuffedDest Pointer to the destination area of stuffed data
 * @param  maxDestLen max fillable size of the destination area
 * @param  filledLen Pointer to an uint32_t were we will store the filled stuffed data
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data unstuffer context before taking some action
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OUTOFMEM No more data that we can elaborate
 *         ECU_RES_OK operation ended correctly
 */
e_eCU_Res bUStuffer_insertStuffData(e_eCU_BUStuffCtx* const ctx, uint8_t* const stuffedDest, const uint32_t maxDestLen,
                                  uint32_t* const filledLen);

#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUBYTEUNSTUFFER_H */
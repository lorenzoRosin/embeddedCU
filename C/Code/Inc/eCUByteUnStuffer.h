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
typedef enum
{
    DBUSTF_RES_OK = 0,
    DBUSTF_RES_BADPARAM,
    DBUSTF_RES_BADPOINTER,
	DBUSTF_RES_CORRUPTCTX,
    DBUSTF_RES_OUTOFMEM,
	DBUSTF_RES_FRAMEENDED,
    DBUSTF_RES_NOINITLIB,
}e_eCU_dBUStf_Res;

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
 * @param  memArea Pointer to a memory area that we will use to save unstuffed data
 * @param  memAreaSize Dimension in byte of the memory area
 * @return DBUSTF_RES_BADPOINTER in case of bad pointer
 *		   DBUSTF_RES_BADPARAM in case of an invalid parameter
 *         DBUSTF_RES_OK operation ended correctly
 */
e_eCU_dBUStf_Res bUStufferInitCtx(e_eCU_BUStuffCtx* const ctx, uint8_t* const memArea, const uint32_t memAreaSize);

/**
 * Reset data Unstuffer and restart from memory start
 * @param  ctx Byte Unstuffer context
 * @return DBUSTF_RES_BADPOINTER in case of bad pointer
 *		   DBUSTF_RES_NOINITLIB need to init context before taking some action
 *         DBUSTF_RES_OK operation ended correctly
 */
e_eCU_dBUStf_Res bUStufferReset(e_eCU_BUStuffCtx* const ctx);

/**
 * Retrive how many raw byte we have unstuffed
 * @param  ctx Byte Unstuffer context
 * @param  retrivedLen Pointer to a memory area were we will store size of the unstuffed raw data
 * @return DBUSTF_RES_BADPOINTER in case of bad pointer
 *		   DBUSTF_RES_NOINITLIB need to init context before taking some action
 *		   DBUSTF_RES_CORRUPTCTX in case of an corrupted context
 *         DBUSTF_RES_OK operation ended correctly
 */
e_eCU_dBUStf_Res bUStufferGetNUnstuf(e_eCU_BUStuffCtx* const ctx, uint32_t* const retrivedLen);

/**
 * Insert stuffed data chunk
 * @param  ctx Byte Unstuffer context
 * @param  stuffedArea Pointer to the stuffed Data that we will unstuff
 * @param  stuffLen data to unstuff size
 * @param  consumedStuffData Pointer to an uint32_t were we will store how many stuffed data byte were analyzed
 *         and that dosent need to be inserted in this function anymore
 * @param  errSofRec Pointer to an uint32_t were we will store how many protocol error were detected. Even with
 *         some error detected, the protocol will continue parsing data discharging error
 * @return DBUSTF_RES_BADPOINTER in case of bad pointer
 *		   DBUSTF_RES_NOINITLIB need to init context before taking some action
 *		   DBUSTF_RES_BADPARAM in case of an invalid parameter or state
 *		   DBUSTF_RES_CORRUPTCTX in case of an corrupted context
 *         DBUSTF_RES_OUTOFMEM Can not unstuff data, initial mem pointer was too small
 *		   DBUSTF_RES_FRAMEENDED Frame ended, restart context in order to parse a new frame
 *         DBUSTF_RES_OK operation ended correctly
 */
e_eCU_dBUStf_Res bUStufferInsStufChunk(e_eCU_BUStuffCtx* const ctx, const uint8_t* stuffedArea, const uint32_t stuffLen,
                                  uint32_t* const consumedStuffData, uint32_t* errSofRec);

#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUBYTEUNSTUFFER_H */
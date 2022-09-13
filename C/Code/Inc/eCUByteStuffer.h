/**
 * @file eCUByteStuffer.h
 *
 */

#ifndef ECUBYTESTUFFER_H
#define ECUBYTESTUFFER_H



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
    DBSTF_RES_OK = 0,
    DBSTF_RES_BADPARAM,
    DBSTF_RES_BADPOINTER,
	DBSTF_RES_CORRUPTCTX,
    DBSTF_RES_FRAMEENDED,
    DBSTF_RES_NOINITLIB,
    DBSTF_RES_NOINITFRAME,
}e_eCU_dBStf_Res;

typedef struct
{
    bool_t   isInit;
	uint8_t* memArea;
	uint32_t memAreaSize;
    uint32_t memAreaFrameSize;
	uint32_t memAreaCntr;
    bool_t   precedentToCheck;
    bool_t   needSof;
    bool_t   needEof;
}e_eCU_BStuffCtx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * Initialize the byte stuffer context
 * @param ctx Byte stuffer context
 * @param memArea Pointer to a memory area that we will use to retrive data to stuff
 * @param memPoolSize Dimension in byte of the memory area
 * @return DBSTF_RES_BADPOINTER in case of bad pointer
 *		   DBSTF_RES_BADPARAM in case of an invalid parameter
 *         DBSTF_RES_OK operation ended correctly
 */
e_eCU_dBStf_Res bStufferInitCtx(e_eCU_BStuffCtx* const ctx, uint8_t* const memArea, const uint32_t memAreaSize);

/**
 * Start stuffing a new frame given the size of the raw data
 * @param  ctx Byte stuffer context
 * @param  ctx frameLen lenght of the raw data present in the frame that we need to stuff
 * @return DBSTF_RES_BADPOINTER in case of bad pointer
 *		   DBSTF_RES_NOINITLIB need to init the data stuffer context before taking some action
 *		   DBSTF_RES_CORRUPTCTX in case of an corrupted context
 *         DBSTF_RES_OK operation ended correctly
 */
e_eCU_dBStf_Res bStufferStartNewFrame(e_eCU_BStuffCtx* const ctx, const uint32_t frameLen);

/**
 * Restart stuffing the current frame
 * @param  ctx Byte stuffer context
 * @return DBSTF_RES_BADPOINTER in case of bad pointer
 *		   DBSTF_RES_NOINITLIB need to init the data stuffer context before taking some action
 *		   DBSTF_RES_CORRUPTCTX in case of an corrupted context
 *         DBSTF_RES_OK operation ended correctly
 */
e_eCU_dBStf_Res bStufferRestartCurrentFrame(e_eCU_BStuffCtx* const ctx);

/**
 * Retrive the unstuffed data location
 * @param  ctx Byte stuffer context
 * @param  dataP Pointer of Pointer where the unstuffed data are present
 * @param  retrivedLen Pointer to a memory area were we will store size of the unstuffed data
 * @return DBSTF_RES_BADPOINTER in case of bad pointer
 *		   DBSTF_RES_NOINITLIB need to init the data stuffer context before taking some action
 *		   DBSTF_RES_CORRUPTCTX in case of an corrupted context
 *         DBSTF_RES_OK operation ended correctly
 */
e_eCU_dBStf_Res bStufferGetUnStufDataLocation(e_eCU_BStuffCtx* const ctx, uint8_t** dataP);

/**
 * Retrive how many byte we can still retrive
 * @param  ctx Byte stuffer context
 * @param  retrivedLen Pointer to a memory area were we will store size of the retrivable data
 * @return DBSTF_RES_BADPOINTER in case of bad pointer
 *		   DBSTF_RES_NOINITLIB need to init the data stuffer context before taking some action
 *		   DBSTF_RES_CORRUPTCTX in case of an corrupted context
 *         DBSTF_RES_OK operation ended correctly
 */
e_eCU_dBStf_Res bStufferGetRemToRetrive(e_eCU_BStuffCtx* const ctx, uint32_t* const retrivedLen);

/**
 * Retrive stuffed data chunk
 * @param  ctx Byte stuffer context
 * @param  stuffedDest Pointer to the destination area of stuffed data
 * @param  maxDestLen max fillable size of the destination area
 * @param  filledLen Pointer to an uint32_t were we will store the filled stuffed data
 * @return DBSTF_RES_BADPOINTER in case of bad pointer
 *		   DBSTF_RES_NOINITLIB need to init the data stuffer context before taking some action
 *		   DBSTF_RES_BADPARAM in case of an invalid parameter
 *		   DBSTF_RES_CORRUPTCTX in case of an corrupted context
 *         DBSTF_RES_FRAMEENDED No more data that we can elaborate
 *         DBSTF_RES_OK operation ended correctly
 */
e_eCU_dBStf_Res bStufferRetriStufChunk(e_eCU_BStuffCtx* const ctx, uint8_t* const stuffedDest,
									   const uint32_t maxDestLen, uint32_t* const filledLen);

#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUBYTESTUFFER_H */

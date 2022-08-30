/**
 * @file eCUCrc.h
 *
 */

#ifndef ECUCRC_H
#define ECUCRC_H



#ifdef __cplusplus
extern "C" {
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUType.h"



/***********************************************************************************************************************
 *      DEFINES
 **********************************************************************************************************************/
#define ECU_SOF                               ( 0xA1u )
#define ECU_EOF                               ( 0xA2u )
#define ECU_ESC                               ( 0xA3u )

#define ECU_NSOF                              ( 0x5Eu )
#define ECU_NEOF                              ( 0x5Du )
#define ECU_NESC                              ( 0x5Cu )



/***********************************************************************************************************************
 *      TYPEDEFS
 **********************************************************************************************************************/
typedef struct
{
    bool_t   isInit;
	uint8_t* memArea;
	uint32_t memAreaSize;
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
 * @param memPool Pointer to a memory area that we will use to retrive data to stuff
 * @param memPoolSize Dimension in byte of the memory area
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OK circular queue is initialized correctly
 */
e_eCU_Res bStuffer_initCtx(e_eCU_BStuffCtx* const ctx, uint8_t* const memArea, const uint32_t memAreaSize);

/**
 * Reset data stuffer and restart from memory start
 * @param  ctx Byte stuffer context
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data stuffer context before taking some action
 *         ECU_RES_OK operation ended correctly
 */
e_eCU_Res bStuffer_reset(e_eCU_BStuffCtx* const ctx);

/**
 * Retrive how many raw byte we can still stuff
 * @param  ctx Byte stuffer context
 * @param  retrivedLen Pointer to a memory area were we will store size of the stuffable data
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data stuffer context before taking some action
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OK operation ended correctly
 */
e_eCU_Res bStuffer_getDataSize(e_eCU_BStuffCtx* const ctx, uint32_t* const retrivedLen);

/**
 * Retrive stuffed data chunk
 * @param  ctx Byte stuffer context
 * @param  stuffedDest Pointer to the destination area of stuffed data
 * @param  maxDestLen max fillable size of the destination area
 * @param  filledLen Pointer to an uint32_t were we will store the filled stuffed data
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *		   ECU_RES_NOINITLIB need to init the data stuffer context before taking some action
 *		   ECU_RES_BADPARAM in case of an invalid parameter or state
 *         ECU_RES_OUTOFMEM No more data that we can elaborate
 *         ECU_RES_OK operation ended correctly
 */
e_eCU_Res bStuffer_retiveElabData(e_eCU_BStuffCtx* const ctx, uint8_t* const stuffedDest, const uint32_t maxDestLen,
                                  uint32_t* const filledLen);

#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCRC_H */
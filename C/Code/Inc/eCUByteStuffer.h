/**
 * @file       eCUByteStuffer.h
 *
 * @brief      Byte stuffer utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

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
 * @brief       Initialize the byte stuffer context
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[in]   memArea     - Pointer to a memory area that we will use to store data that needs to be stuffed
 * @param[in]   memPoolSize - Dimension in byte of the memory area
 *
 * @return      DBSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        DBSTF_RES_BADPARAM      - In case of an invalid parameter passed to the function
 *              DBSTF_RES_OK            - Operation ended correctly
 */
e_eCU_dBStf_Res bStufferInitCtx(e_eCU_BStuffCtx* const ctx, uint8_t* const memArea, const uint32_t memAreaSize);

/**
 * @brief       Start to stuff a new frame given the dimension of raw payload it self. This function suppouse that
 *              data payload that need to be stuffed were already copied in memory.( see bStufferGetUnStufDataLocation
 *              in order to know how get the data pointer )
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[in]   frameLen    - lenght of the raw data present in the frame that we need to stuff
 *
 * @return      DBSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        DBSTF_RES_BADPARAM      - In case of an invalid parameter passed to the function
 *		        DBSTF_RES_NOINITLIB     - Need to init the data stuffer context before taking some action
 *		        DBSTF_RES_CORRUPTCTX    - In case of an corrupted context
 *              DBSTF_RES_OK            - Operation ended correctly
 */
e_eCU_dBStf_Res bStufferStartNewFrame(e_eCU_BStuffCtx* const ctx, const uint32_t frameLen);

/**
 * @brief       Retrive the pointer of the buffer that the user can use to insert data payload that need to be stuffed
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[out]  dataP       - Pointer to a Pointer where the raw data needs to be copied before starting a frame
 * @param[out]  maxDataSize - Pointer to a uint32_t variable where the max number of data that can be copied in dataP
 *                            will be placed
 *
 * @return      DBSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        DBSTF_RES_NOINITLIB     - Need to init the data stuffer context before taking some action
 *		        DBSTF_RES_CORRUPTCTX    - In case of an corrupted context
 *              DBSTF_RES_OK            - Operation ended correctly
 */
e_eCU_dBStf_Res bStufferGetUnStufDataLocation(e_eCU_BStuffCtx* const ctx, uint8_t** dataP, uint32_t* const maxDataSize);

/**
 * @brief       Restart to stuff the already passed/the current frame
 *
 * @param[in]   ctx         - Byte stuffer context
 *
 * @return      DBSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        DBSTF_RES_NOINITLIB     - Need to init the data stuffer context before taking some action
 *		        DBSTF_RES_NOINITFRAME   - Need to start a frame before restarting the current frame
 *		        DBSTF_RES_CORRUPTCTX    - In case of an corrupted context
 *              DBSTF_RES_OK            - Operation ended correctly
 */
e_eCU_dBStf_Res bStufferRestartCurrentFrame(e_eCU_BStuffCtx* const ctx);

/**
 * @brief       Retrive the numbers of stuffed bytes that can be retrived using bStufferRetriStufChunk (e.g. if the
 *              value of the returned value is zero it's means that the frame is ended ).
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[out]  retrivedLen - Pointer to a uint32_t variable where the numbers of retrivable stuffed data will be placed
 *
 * @return      DBSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        DBSTF_RES_NOINITLIB     - Need to init the data stuffer context before taking some action
 *		        DBSTF_RES_NOINITFRAME   - Need to start a frame before requesting how many stuffed data we can retrive
 *		        DBSTF_RES_CORRUPTCTX    - In case of an corrupted context
 *              DBSTF_RES_OK            - Operation ended correctly
 */
e_eCU_dBStf_Res bStufferGetRemToRetrive(e_eCU_BStuffCtx* const ctx, uint32_t* const retrivedLen);

/**
 * @brief       Retrive stuffed data chunk. The raw data copied in the buffer retrived using the function
 *              bStufferGetUnStufDataLocation will be stuffed and retrived by this function.
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[in]   stuffedDest - Pointer to the destination area where stuffed data will be placed by this function
 * @param[in]   maxDestLen  - Max fillable size of the destination area
 * @param[out]  filledLen   - Pointer to an uint32_t were we will store the number stuffed data inserted in stuffedDest
 * @return      DBSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        DBSTF_RES_NOINITLIB     - Need to init the data stuffer context before taking some action
 *		        DBSTF_RES_BADPARAM      - In case of an invalid parameter passed to the function
 *		        DBSTF_RES_NOINITFRAME   - Need to start a frame before retriving data
 *		        DBSTF_RES_CORRUPTCTX    - In case of an corrupted context
 *              DBSTF_RES_FRAMEENDED    - No more data that we can elaborate, restart or start a new frame to proceed.
 *                                        This means that we have finished stuffing the current frame.
 *              DBSTF_RES_OK            - Operation ended correctly. This dosent mean that the stuffing process is
 *                                        completed.
 */
e_eCU_dBStf_Res bStufferRetriStufChunk(e_eCU_BStuffCtx* const ctx, uint8_t* const stuffedDest,
									   const uint32_t maxDestLen, uint32_t* const filledLen);

#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUBYTESTUFFER_H */

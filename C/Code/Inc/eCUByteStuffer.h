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
#include "eCUByteStuffer_prv.h"



/***********************************************************************************************************************
 *      TYPEDEFS
 **********************************************************************************************************************/
typedef enum
{
    BSTF_RES_OK = 0,
    BSTF_RES_BADPARAM,
    BSTF_RES_BADPOINTER,
	BSTF_RES_CORRUPTCTX,
    BSTF_RES_FRAMEENDED,
    BSTF_RES_NOINITLIB,
    BSTF_RES_NOINITFRAME,
}e_eCU_BSTF_Res;

typedef struct
{
    bool_t   isInit;
	uint8_t* memArea;
	uint32_t memAreaSize;
    uint32_t memAreaFrameSize;
	uint32_t memAreaCntr;
    e_eCU_BSTF_sm_prv stuffState;
}s_eCU_BSTF_Ctx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Initialize the byte stuffer context
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[in]   memArea     - Pointer to a memory area that we will use to store data that needs to be stuffed
 * @param[in]   memAreaSize - Dimension in byte of the memory area
 *
 * @return      BSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        BSTF_RES_BADPARAM      - In case of an invalid parameter passed to the function
 *              BSTF_RES_OK            - Operation ended correctly
 */
e_eCU_BSTF_Res BSTF_InitCtx(s_eCU_BSTF_Ctx* const ctx, uint8_t memArea[], const uint32_t memAreaSize);

/**
 * @brief       Check if the lib is initialized
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[out]  isInit      - Pointer to a bool_t variable that will be filled with true if the lib is initialized
 *
 * @return      BSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *              BSTF_RES_OK            - Operation ended correctly
 */
e_eCU_BSTF_Res BSTF_IsInit(s_eCU_BSTF_Ctx* const ctx, bool_t* isInit);

/**
 * @brief       Start to stuff a new frame given the dimension of raw payload it self. This function suppouse that
 *              data payload that need to be stuffed were already copied in memory.( see BSTF_GetUnStufDataLocation
 *              in order to know how get the data pointer )
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[in]   frameLen    - lenght of the raw data present in the frame that we need to stuff
 *
 * @return      BSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        BSTF_RES_BADPARAM      - In case of an invalid parameter passed to the function
 *		        BSTF_RES_NOINITLIB     - Need to init the data stuffer context before taking some action
 *		        BSTF_RES_CORRUPTCTX    - In case of an corrupted context
 *              BSTF_RES_OK            - Operation ended correctly
 */
e_eCU_BSTF_Res BSTF_StartNewFrame(s_eCU_BSTF_Ctx* const ctx, const uint32_t frameLen);

/**
 * @brief       Retrive the pointer of the buffer that the user can use to insert data payload that need to be stuffed
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[out]  dataP       - Pointer to a Pointer where the raw data needs to be copied before starting a frame
 * @param[out]  maxDataSize - Pointer to a uint32_t variable where the max number of data that can be copied in dataP
 *                            will be placed
 *
 * @return      BSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        BSTF_RES_NOINITLIB     - Need to init the data stuffer context before taking some action
 *		        BSTF_RES_CORRUPTCTX    - In case of an corrupted context
 *              BSTF_RES_OK            - Operation ended correctly
 */
e_eCU_BSTF_Res BSTF_GetUnStufDataLocation(s_eCU_BSTF_Ctx* const ctx, uint8_t** dataP, uint32_t* const maxDataSize);

/**
 * @brief       Restart to stuff the already passed data/the current frame
 *
 * @param[in]   ctx         - Byte stuffer context
 *
 * @return      BSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        BSTF_RES_NOINITLIB     - Need to init the data stuffer context before taking some action
 *		        BSTF_RES_NOINITFRAME   - Need to start a frame before restarting the current frame
 *		        BSTF_RES_CORRUPTCTX    - In case of an corrupted context
 *              BSTF_RES_OK            - Operation ended correctly
 */
e_eCU_BSTF_Res BSTF_RestartCurrentFrame(s_eCU_BSTF_Ctx* const ctx);

/**
 * @brief       Retrive the numbers of stuffed bytes that can be retrived using BSTF_RetriStufChunk (e.g. if the
 *              value of the returned value is zero it's means that the frame is ended ).
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[out]  retrivedLen - Pointer to a uint32_t variable where the numbers of retrivable stuffed data will be placed
 *
 * @return      BSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        BSTF_RES_NOINITLIB     - Need to init the data stuffer context before taking some action
 *		        BSTF_RES_NOINITFRAME   - Need to start a frame before requesting how many stuffed data we can retrive
 *		        BSTF_RES_CORRUPTCTX    - In case of an corrupted context
 *              BSTF_RES_OK            - Operation ended correctly
 */
e_eCU_BSTF_Res BSTF_GetRemToRetrive(s_eCU_BSTF_Ctx* const ctx, uint32_t* const retrivedLen);

/**
 * @brief       Retrive stuffed data chunk. The raw data copied in the buffer retrived using the function
 *              BSTF_GetUnStufDataLocation will be stuffed and retrived by this function.
 *
 * @param[in]   ctx         - Byte stuffer context
 * @param[in]   stuffedDest - Pointer to the destination area where stuffed data will be placed by this function
 * @param[in]   maxDestLen  - Max fillable size of the destination area
 * @param[out]  filledLen   - Pointer to an uint32_t were we will store the number stuffed data inserted in stuffedDest.
 *                            Note that if the function return BSTF_RES_OK the value of filledLen will be equals to
 *                            maxDestLen. The value filledLen infact could be lower than max dest size only if
 *                            some error is returned or if the frame is ended ( BSTF_RES_FRAMEENDED )
 * @return      BSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *		        BSTF_RES_NOINITLIB     - Need to init the data stuffer context before taking some action
 *		        BSTF_RES_BADPARAM      - In case of an invalid parameter passed to the function
 *		        BSTF_RES_NOINITFRAME   - Need to start a frame before retriving data
 *		        BSTF_RES_CORRUPTCTX    - In case of an corrupted context
 *              BSTF_RES_FRAMEENDED    - No more data that we can elaborate, restart or start a new frame to proceed.
 *                                        This means that we have finished stuffing the current frame. Keep in mind
 *                                        in this case that the value of filledLen could be lower than maxDestLen.
 *              BSTF_RES_OK            - Operation ended correctly. This dosent mean that the stuffing process is
 *                                        completed, but we can be sure that filledLen will have the same value of
 *                                        maxDestLen
 */
e_eCU_BSTF_Res BSTF_RetriStufChunk(s_eCU_BSTF_Ctx* const ctx, uint8_t stuffedDest[], const uint32_t maxDestLen,
                                       uint32_t* const filledLen);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUBYTESTUFFER_H */
/**
 * @file       eCUByteUnStuffer.h
 *
 * @brief      Byte unstuffer utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

#ifndef ECUBYTEUNSTUFFER_H
#define ECUBYTEUNSTUFFER_H



#ifdef __cplusplus
extern "C" {
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUType.h"
#include "eCUByteUnStuffer_prv.h"



/***********************************************************************************************************************
 *      TYPEDEFS
 **********************************************************************************************************************/
typedef enum
{
    BUNSTF_RES_OK = 0,
    BUNSTF_RES_BADPARAM,
    BUNSTF_RES_BADPOINTER,
	BUNSTF_RES_CORRUPTCTX,
    BUNSTF_RES_OUTOFMEM,
    BUNSTF_RES_BADFRAME,
	BUNSTF_RES_FRAMEENDED,
    BUNSTF_RES_FRAMERESTART,
    BUNSTF_RES_NOINITLIB,
}s_eCU_BUNSTF_Res;

typedef struct
{
    bool_t   isInit;
	uint8_t* memArea;
	uint32_t memAreaSize;
	uint32_t memAreaCntr;
	e_eCU_BUNSTF_sm_prv unStuffState;
}s_eCU_BUNSTF_Ctx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Initialize the byte unStuffer context
 *
 * @param[in]   ctx         - Byte unStuffer context
 * @param[in]   memArea     - Pointer to a memory area that we will use to store the unstuffed data
 * @param[in]   memAreaSize - Dimension in byte of the memory area
 *
 * @return      BUNSTF_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        BUNSTF_RES_BADPARAM     - In case of an invalid parameter passed to the function
 *              BUNSTF_RES_OK           - Operation ended correctly
 */
s_eCU_BUNSTF_Res BUNSTF_InitCtx(s_eCU_BUNSTF_Ctx* const ctx, uint8_t memArea[], const uint32_t memAreaSize);

/**
 * @brief       Check if the lib is initialized
 *
 * @param[in]   ctx         - Byte unStuffer context
 * @param[out]  isInit      - Pointer to a bool_t variable that will be filled with true if the lib is initialized
 *
 * @return      BUNSTF_RES_BADPOINTER    - In case of bad pointer passed to the function
 *              BUNSTF_RES_OK            - Operation ended correctly
 */
s_eCU_BUNSTF_Res BUNSTF_IsInit(s_eCU_BUNSTF_Ctx* const ctx, bool_t* isInit);

/**
 * @brief       Start receiving a new frame, loosing the previous stored unstuffed frame
 *
 * @param[in]   ctx         - Byte unStuffer context
 *
 * @return      BUNSTF_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        BUNSTF_RES_NOINITLIB    - Need to init context before taking some action
 *		        BUNSTF_RES_CORRUPTCTX   - In case of an corrupted context
 *              BUNSTF_RES_OK           - Operation ended correctly
 */
s_eCU_BUNSTF_Res BUNSTF_StartNewFrame(s_eCU_BUNSTF_Ctx* const ctx);

/**
 * @brief       Retrive the pointer to the stored unstuffed data, and the data size of the frame. Keep in mind that
 *              the frame parsing could be ongoing, and that value could change.
 *
 * @param[in]   ctx         - Byte unStuffer context
 * @param[out]  dataP       - Pointer to a Pointer pointing to the unstuffed data frame
 * @param[out]  retrivedLen - Pointer to a uint32_t variable where the size of the unstuffed data will be placed
 *
 * @return      BUNSTF_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        BUNSTF_RES_NOINITLIB    - Need to init context before taking some action
 *		        BUNSTF_RES_CORRUPTCTX   - In case of an corrupted context
 *              BUNSTF_RES_OK           - Operation ended correctly
 */
s_eCU_BUNSTF_Res BUNSTF_GetUnstufData(s_eCU_BUNSTF_Ctx* const ctx, uint8_t** dataP, uint32_t* const retrivedLen);

/**
 * @brief       Retrive the current numbers of unstuffed data received. Keep in mind that the frame parsing could be
 *              ongoing, and that value could change.
 *
 * @param[in]   ctx         - Byte unStuffer context
 * @param[out]  retrivedLen - Pointer to a uint32_t variable where the size of the unstuffed data will be placed
 *
 * @return      BUNSTF_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        BUNSTF_RES_NOINITLIB    - Need to init context before taking some action
 *		        BUNSTF_RES_CORRUPTCTX   - In case of an corrupted context
 *              BUNSTF_RES_OK           - Operation ended correctly
 */
s_eCU_BUNSTF_Res BUNSTF_GetUnstufLen(s_eCU_BUNSTF_Ctx* const ctx, uint32_t* const retrivedLen);

/**
 * @brief       Retrive if the Unstuffer is currently waiting for the Start of frame in order to start saving data.
 *
 * @param[in]   ctx          - Byte unStuffer context
 * @param[out]  isWaitingSof - Pointer to a bool_t variable that will be filled with true if we are waiting SOF
 *
 * @return      BUNSTF_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        BUNSTF_RES_NOINITLIB    - Need to init context before taking some action
 *		        BUNSTF_RES_CORRUPTCTX   - In case of an corrupted context
 *              BUNSTF_RES_OK           - Operation ended correctly
 */
s_eCU_BUNSTF_Res BUNSTF_IsWaitingSof(const s_eCU_BUNSTF_Ctx* ctx, bool_t* const isWaitingSof);

/**
 * @brief       Check if the current frame is finished or if we need to unstuff some more data to have the full frame.
 *              If a frame is received with a bad format this function return that the frame is not fully unstuffed.
 *
 * @param[in]   ctx            - Byte unStuffer context
 * @param[out]  isFrameUnstuff - Pointer to a bool_t variable where we will store if the frame parsing is ongoing
 *
 * @return      BUNSTF_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        BUNSTF_RES_NOINITLIB    - Need to init context before taking some action
 *		        BUNSTF_RES_CORRUPTCTX   - In case of an corrupted context
 *              BUNSTF_RES_OK           - Operation ended correctly
 */
s_eCU_BUNSTF_Res BUNSTF_IsAFullFrameUnstuff(const s_eCU_BUNSTF_Ctx* ctx, bool_t* const isFrameUnstuff);

/**
 * @brief       Check if the current received data compose a bad frame. If a bad frame is detected we can only
 *              call BUNSTF_StartNewFrame before parsing new data.
 *
 * @param[in]   ctx            - Byte unStuffer context
 * @param[out]  isFrameBad     - Pointer to a bool_t variable where we will store if the frame is bad formed
 *
 * @return      BUNSTF_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        BUNSTF_RES_NOINITLIB    - Need to init context before taking some action
 *		        BUNSTF_RES_CORRUPTCTX   - In case of an corrupted context
 *              BUNSTF_RES_OK           - Operation ended correctly
 */
s_eCU_BUNSTF_Res BUNSTF_IsCurrentFrameBad(const s_eCU_BUNSTF_Ctx* ctx, bool_t* const isFrameBad);

/**
 * @brief       Insert the stuffed data chunk that the alg will unstuff byte per byte
 *
 * @param[in]   ctx                - Byte unStuffer context
 * @param[in]   stuffArea          - Pointer to the stuffed Data that we will unstuff
 * @param[in]   stuffLen           - Size of the stuffArea
 * @param[out]  consumedStuffData  - Pointer to an uint32_t were we will store how many stuffed data byte has been
 *                                   analized. Keep in mind that unalized data were not unstuffed and they will need to
 *                                   be reparsed. Un parsed data happens when the frame ended earlier
 *                                   ( BUNSTF_RES_FRAMEENDED, BUNSTF_RES_BADFRAME or BUNSTF_RES_FRAMERESTART is
 *                                   returned ) or when some other error is returned. When the function return
 *                                   BUNSTF_RES_OK consumedStuffData will always be returned has stuffLen.
 *
 * @return      BUNSTF_RES_BADPOINTER   - In case of bad pointer passed to the function
 *		        BUNSTF_RES_NOINITLIB    - Need to init context before taking some action
 *		        BUNSTF_RES_BADPARAM     - In case of an invalid parameter passed to the function
 *		        BUNSTF_RES_CORRUPTCTX   - In case of an corrupted context
 *              BUNSTF_RES_OUTOFMEM     - Can not unstuff data, initial mem pointer was too small. The only way to
 *                                        resolve the issue is increasing the size of the memory area passed to init
 *		        BUNSTF_RES_FRAMEENDED   - Frame ended, restart context in order to parse a new frame. Every other call
 *                                        to this function will not have effect until we call BUNSTF_StartNewFrame.
 *                                        In this situation bear in mind that some data could be left out the parsing,
 *                                        and so we need to reparse that data after calling BUNSTF_StartNewFrame.
 *              BUNSTF_RES_BADFRAME     - Found an error while parsing, the frame passed is invalid.
 *                                        Restart context in order to parse a new frame. Every other call
 *                                        to this function will not have effect until we call BUNSTF_StartNewFrame.
 *                                        In this situation bear in mind that some data could be left out the parsing,
 *                                        and so we need to reparse that data after calling BUNSTF_StartNewFrame.
 *              BUNSTF_RES_FRAMERESTART - During frame receiving another start of frame is received. In this situation
 *                                        clear old data and restart the frame, witouth the need to call any other
 *                                        function. In this situation bear in mind that some data could be left out
 *                                        the parsing and so we need to reparse that data with another call of
 *                                        BUNSTF_InsStufChunk.
 *              BUNSTF_RES_OK           - Operation ended correctly. The chunk is parsed correclty but the frame is not
 *                                        finished yet. In this situation consumedStuffData is always reported with a
 *                                        value equals to stuffLen.
 */
s_eCU_BUNSTF_Res BUNSTF_InsStufChunk(s_eCU_BUNSTF_Ctx* const ctx, const uint8_t stuffArea[], const uint32_t stuffLen,
                                       uint32_t* const consumedStuffData);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUBYTEUNSTUFFER_H */
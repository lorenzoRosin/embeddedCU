/**
 * @file       eCUCrcDigest.h
 *
 * @brief      Cal CRC using custom CRC32 using digest approach
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

#ifndef ECUCRCDIGEST_H
#define ECUCRCDIGEST_H



#ifdef __cplusplus
extern "C" {
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUCrc.h"



/***********************************************************************************************************************
 *      TYPEDEFS
 **********************************************************************************************************************/
/* Define a generic crc callback context that must be implemented by the user */
typedef struct cb_crc32_seed_ctx_user cb_crc32_seed_ctx;

/* Call back of a function that will calculate the CRC for this modules.
 * the p_ctx parameter is a custom pointer that can be used by the creator of this CRC callback, and will not be used
 * by the CRCdigest module */
typedef bool_t (*cb_crc32_seed) ( cb_crc32_seed_ctx* p_ctx, const uint32_t seed, const uint8_t* p_data,
                                  const uint32_t dataSLen, uint32_t* const p_crc32Val );

typedef enum
{
    CRCD_RES_OK = 0,
    CRCD_RES_BADPARAM,
    CRCD_RES_BADPOINTER,
	CRCD_RES_CORRUPTCTX,
    CRCD_RES_TOOMANYDIGEST,
    CRCD_RES_NODIGESTDONE,
    CRCD_RES_NOINITLIB,
    CRCD_RES_CLBCKREPORTERROR,
}e_eCU_CRCD_Res;

typedef struct
{
    bool_t isInit;
    uint32_t baseSeed;
	uint32_t digestedTimes;
    uint32_t lastDigVal;
    cb_crc32_seed f_Crc;
    cb_crc32_seed_ctx* p_crcCtx;
}s_eCU_CRCD_Ctx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Initialize the CRC32 digester context ( use as base seed 0xFFFFFFFFu )
 *
 * @param[in]   p_ctx           - Crc digester context
 * @param[in]   f_Crc           - Pointer to a CRC 32 seed callback function, that will be used to calculate the CRC32
 * @param[in]   p_clbCtx        - Custom context passed to the callback function f_Crc
 *
 * @return      CRCD_RES_BADPOINTER     - In case of bad pointer passed to the function
 *              CRCD_RES_OK             - Crc digester initialized successfully
 */
e_eCU_CRCD_Res eCU_CRCD_InitCtx(s_eCU_CRCD_Ctx* const p_ctx, cb_crc32_seed f_Crc, cb_crc32_seed_ctx* const p_clbCtx);

/**
 * @brief       Check if the lib is initialized
 *
 * @param[in]   p_ctx           - Crc digester context
 * @param[out]  p_isInit        - Pointer to a bool_t variable that will be filled with true if the lib is initialized
 *
 * @return      CRCD_RES_BADPOINTER    - In case of bad pointer passed to the function
 *              CRCD_RES_OK            - Operation ended correctly
 */
e_eCU_CRCD_Res eCU_CRCD_IsInit(s_eCU_CRCD_Ctx* const p_ctx, bool_t* p_isInit);

/**
 * @brief       Initialize the CRC32 digester context using a selected seed
 *
 * @param[in]   p_ctx           - Crc digester context
 * @param[in]   seed            - Base Seed
 * @param[in]   f_Crc           - Pointer to a CRC 32 seed callback function, that will be used to calculate the CRC32
 * @param[in]   p_clbCtx        - Custom context passed to the callback function f_Crc
 *
 * @return      CRCD_RES_BADPOINTER     - In case of bad pointer passed to the function
 *              CRCD_RES_OK             - Crc digester initialized successfully
 */
e_eCU_CRCD_Res eCU_CRCD_SeedInitCtx(s_eCU_CRCD_Ctx* const p_ctx, const uint32_t seed, cb_crc32_seed f_Crc,
                                    cb_crc32_seed_ctx* const p_clbCtx);

/**
 * @brief       Restart the digester and disharge all old value
 *
 * @param[in]   p_ctx         - Crc digester context
 *
 * @return      CRCD_RES_BADPOINTER         - In case of bad pointer passed to the function
 *              CRCD_RES_OK                 - Data digested successfully
 *              CRCD_RES_NOINITLIB          - Need to init the lib before taking some action
 *              CRCD_RES_CORRUPTCTX         - In case of a corrupted context
 */
e_eCU_CRCD_Res eCU_CRCD_Restart(s_eCU_CRCD_Ctx* const p_ctx);

/**
 * @brief       Digest a chunk of data that we want to calculate CRC
 *
 * @param[in]   p_ctx           - Crc digester context
 * @param[in]   p_data          - Pointer to a memory area containg a chunk of data to digest
 * @param[in]   dataLen         - Lenght of the buffer we will digest
 *
 * @return      CRCD_RES_BADPOINTER         - In case of bad pointer passed to the function
 *              CRCD_RES_OK                 - Data digested successfully
 *              CRCD_RES_NOINITLIB          - Need to init the lib before taking some action
 *              CRCD_RES_BADPARAM           - In case of bad parameter passed to the function
 *              CRCD_RES_CORRUPTCTX         - In case of a corrupted context
 *              CRCD_RES_TOOMANYDIGEST      - Too many digest operation
 *              CRCD_RES_CLBCKREPORTERROR   - The callback function reported an error
 */
e_eCU_CRCD_Res eCU_CRCD_Digest(s_eCU_CRCD_Ctx* const p_ctx, const uint8_t* p_data, const uint32_t dataLen);

/**
 * @brief       Retrive the CRC32 of all the chunk digested using eCU_CRCD_Digest. After this function is used the
 *              internal state is resetted and old result are discharged.
 *
 * @param[in]   p_ctx         - Crc digester context
 * @param[out]  p_crcCalc     - Pointer to a memory area that will contain the value of the calculated CRC
 *
 * @return      CRCD_RES_BADPOINTER         - In case of bad pointer passed to the function
 *              CRCD_RES_OK                 - Data digested successfully
 *              CRCD_RES_NOINITLIB          - Need to init the lib before taking some action
 *              CRCD_RES_CORRUPTCTX         - In case of a corrupted context
 *              CRCD_RES_NODIGESTDONE       - Need to do al least one digest before getting the CRC32
 */
e_eCU_CRCD_Res eCU_CRCD_GetDigestVal(s_eCU_CRCD_Ctx* const p_ctx, uint32_t* const p_crcCalc);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCRCDIGEST_H */
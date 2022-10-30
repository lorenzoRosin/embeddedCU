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

/* Call back of a function that will calculate the CRC for this modules.
 * the cntx parameter is a custom pointer that can be used by the creator of this CRC callback, and will not be used
 * by the CRCdigest module */
typedef bool_t (*cb_crc32_seed) ( void* cntx, const uint32_t seed, const uint8_t dataS[], const uint32_t dataSLen,
                                         uint32_t* const crc32SVal );

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
}e_eCU_CrcD_Res;

typedef struct
{
    bool_t isInit;
    uint32_t baseSeed;
	uint32_t digestedTimes;
    uint32_t lastDigVal;
    cb_crc32_seed cbCrcPointer;
    void* cbCrcCtx;
}s_eCU_CrcDigestCtx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Initialize the CRC32 digester context ( use as base seed 0xFFFFFFFFu )
 *
 * @param[in]   ctx         - Crc digester context
 * @param[in]   cbCrcP      - Pointer to a CRC 32 seed callback function, that will be used to calculate the CRC32
 * @param[in]   clbCtx      - Custom context passed to the callback function cbCrcP
 *
 * @return      CRCD_RES_BADPOINTER     - In case of bad pointer passed to the function
 *              CRCD_RES_OK             - Crc digester initialized successfully
 */
e_eCU_CrcD_Res crcDigestInitCtx(s_eCU_CrcDigestCtx* const ctx, cb_crc32_seed cbCrcP, void* const clbCtx);

/**
 * @brief       Initialize the CRC32 digester context using a selected seed
 *
 * @param[in]   ctx         - Crc digester context
 * @param[in]   seed        - Base Seed
 * @param[in]   cbCrcP      - Pointer to a CRC 32 seed callback function, that will be used to calculate the CRC32
 * @param[in]   clbCtx      - Custom context passed to the callback function cbCrcP
 *
 * @return      CRCD_RES_BADPOINTER     - In case of bad pointer passed to the function
 *              CRCD_RES_OK             - Crc digester initialized successfully
 */
e_eCU_CrcD_Res crcDigestSeedInitCtx(s_eCU_CrcDigestCtx* const ctx, const uint32_t seed, cb_crc32_seed cbCrcP,
                                    void* const clbCtx);

/**
 * @brief       Restart the digester and disharge all old value
 *
 * @param[in]   ctx         - Crc digester context
 *
 * @return      CRCD_RES_BADPOINTER         - In case of bad pointer passed to the function
 *              CRCD_RES_OK                 - Data digested successfully
 *              CRCD_RES_NOINITLIB          - Need to init the lib before taking some action
 *              CRCD_RES_CORRUPTCTX         - In case of a corrupted context
 */
e_eCU_CrcD_Res crcDigestRestart(s_eCU_CrcDigestCtx* const ctx);

/**
 * @brief       Digest a chunk of data that we want to calculate CRC
 *
 * @param[in]   ctx         - Crc digester context
 * @param[in]   data        - Pointer to a memory area containg a chunk of data to digest
 * @param[in]   dataLen     - Lenght of the buffer we will digest
 *
 * @return      CRCD_RES_BADPOINTER         - In case of bad pointer passed to the function
 *              CRCD_RES_OK                 - Data digested successfully
 *              CRCD_RES_NOINITLIB          - Need to init the lib before taking some action
 *              CRCD_RES_BADPARAM           - In case of bad parameter passed to the function
 *              CRCD_RES_CORRUPTCTX         - In case of a corrupted context
 *              CRCD_RES_TOOMANYDIGEST      - Too many digest operation
 *              CRCD_RES_CLBCKREPORTERROR   - The callback function reported an error
 */
e_eCU_CrcD_Res crcDigestDigest(s_eCU_CrcDigestCtx* const ctx, const uint8_t data[], const uint32_t dataLen);

/**
 * @brief       Retrive the CRC32 of all the chunk digested using crcDigestDigest. After this function is used the
 *              internal state is resetted and old result are discharged.
 *
 * @param[in]   ctx         - Crc digester context
 * @param[out]  crcCalc     - Pointer to a memory area that will contain the value of the calculated CRC
 *
 * @return      CRCD_RES_BADPOINTER         - In case of bad pointer passed to the function
 *              CRCD_RES_OK                 - Data digested successfully
 *              CRCD_RES_NOINITLIB          - Need to init the lib before taking some action
 *              CRCD_RES_CORRUPTCTX         - In case of a corrupted context
 *              CRCD_RES_NODIGESTDONE       - Need to do al least one digest before getting the CRC32
 */
e_eCU_CrcD_Res crcDigestGetDigestVal(s_eCU_CrcDigestCtx* const ctx, uint32_t* const crcCalc);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCRCDIGEST_H */
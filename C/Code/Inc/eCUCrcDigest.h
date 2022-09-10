/**
 * @file eCUCrcDigest.h
 *
 */

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

/* Call back to a function that will calculate the CRC for this modules
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
    uint32_t usedBaseSeed;
	uint32_t digestedTimes;
    uint32_t lastDigest;
    cb_crc32_seed cbCrcPointer;
    void* cbCrcCtx;
}s_eCU_CrcDigestCtx;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * Initialize the CRC32 digester context ( use as base seed 0xffffffffu )
 * @param ctx Crc digester context
 * @param cbCrcP Pointer to a CRC 32 seed callback function
 * @param clbCtx Custom context passed to the callback function
 * @return CRCD_RES_BADPOINTER in case of bad pointer
 *         CRCD_RES_OK crc digester is initialized correctly
 */
e_eCU_CrcD_Res crcDigestInitCtx(s_eCU_CrcDigestCtx* const ctx, cb_crc32_seed cbCrcP, void* const clbCtx);

/**
 * Initialize the CRC32 digester context using a selected seed
 * @param ctx Crc digester context
 * @param seed Base Seed
 * @param cbCrcP Pointer to a CRC 32 seed callback function
 * @param clbCtx Custom context passed to the callback function
 * @return CRCD_RES_BADPOINTER in case of bad pointer
 *         CRCD_RES_OK crc digester is initialized correctly
 */
e_eCU_CrcD_Res crcDigestSeedInitCtx(s_eCU_CrcDigestCtx* const ctx, const uint32_t seed, cb_crc32_seed cbCrcP,
                                    void* const clbCtx);

/**
 * Digest a chunk of data in to the CRC32 calc
 * @param ctx Crc digester context
 * @param data Pointer to a memory area containg a chunk of data to analyze
 * @param dataLen Lenght of the buffer we will digest
 * @return CRCD_RES_BADPOINTER in case of bad pointer
 *		   CRCD_RES_NOINITLIB need to init the lib before taking some action
 *		   CRCD_RES_BADPARAM in case of an invalid parameter
 *		   CRCD_RES_CORRUPTCTX in case of an corrupted context
 *         CRCD_RES_TOOMANYDIGEST Too many digest operation
 *         CRCD_RES_CLBCKREPORTERROR The callback function reported an error
 *         CRCD_RES_OK operation ended correctly
*/
e_eCU_CrcD_Res crcDigesDigest(s_eCU_CrcDigestCtx* const ctx, const uint8_t* data, const uint32_t dataLen);

/**
 * Retrive the CRC32 value calculated till now
 * @param ctx Crc digester context
 * @param crcCalc Pointer to a memory that will contain the value of the calculated CRC
 * @return CRCD_RES_BADPOINTER in case of bad pointer
 *		   CRCD_RES_NOINITLIB need to init the lib before taking some action
 *		   CRCD_RES_CORRUPTCTX in case of an corrupted context
 *		   CRCD_RES_NODIGESTDONE need to do al least one digest before getting val
 *         CRCD_RES_OK operation ended correctly
 */
e_eCU_CrcD_Res crcDigesGetDigestVal(s_eCU_CrcDigestCtx* const ctx, uint32_t* const crcCalc);

#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCRCDIGEST_H */











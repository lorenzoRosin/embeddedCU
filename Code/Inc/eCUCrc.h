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
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * Calculate the CRC 32 of a passed buffer using as seed the default value of 0xffffffffu
 * @param data Pointer to the data buffer where we will calculate the CRC 32
 * @param dataLen how many byte will be used to calculate the CRC 32
 * @param crc32 Pointer to an uint32_t were we will store the calculated CRC 32
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *         ECU_RES_OK crc 32 calculated successfully
 */
e_eCU_Res crc32(const uint8_t* data, const uint32_t dataLen, uint32_t const* crc32);

/**
 * Calculate the CRC 32 of a passed buffer using a custom seed
 * @param seed Seed that will be used to calculate the CRC 32
 * @param data Pointer to the data buffer where we will calculate the CRC 32
 * @param dataLen how many byte will be used to calculate the CRC 32
 * @param crc32 Pointer to an uint32_t were we will store the calculated CRC 32
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *         ECU_RES_OK crc 32 calculated successfully
 */
e_eCU_Res crc32_seed(const uint32_t seed, const uint8_t* data, const uint32_t dataLen, uint32_t const* crc32);

#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCRC_H */
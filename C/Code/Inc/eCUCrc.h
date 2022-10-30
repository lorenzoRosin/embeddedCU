/**
 * @file       eCUCrc.h
 *
 * @brief      Cal crc32 (CRC-32/MPEG-2) utils
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

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
#define ECU_CRC_BASE_SEED                                                                    ( (uint32_t ) 0xFFFFFFFFu )



/***********************************************************************************************************************
 *      TYPEDEFS
 **********************************************************************************************************************/
typedef enum
{
    CRC_RES_OK = 0,
    CRC_RES_BADPOINTER
}e_eCU_Crc_Res;



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Calculate the CRC 32 (CRC-32/MPEG-2) of a passed buffer using as seed the default value of 0xFFFFFFFFu
 *
 * @param[in]   data        - Pointer to the data buffer used to calculate CRC 32
 * @param[in]   dataLen     - How many byte will be used to calculate the CRC 32
 * @param[out]  crc32Val    - Pointer to an uint32_t were we will store the calculated CRC 32
 *
 * @return      CRC_RES_BADPOINTER      - In case of bad pointer passed to the function
 *              CRC_RES_OK              - Crc 32 calculated successfully
 */
e_eCU_Crc_Res crc32(const uint8_t data[], const uint32_t dataLen, uint32_t* const crc32Val);


/**
 * @brief       Calculate the CRC 32 (CRC-32/MPEG-2) of a passed buffer using a custom seed
 *
 * @param[in]   seed        - Seed that will be used to calculate the CRC 32
 * @param[in]   data        - Pointer to the data buffer used to calculate CRC 32
 * @param[in]   dataLen     - How many byte will be used to calculate the CRC 32
 * @param[out]  crc32Val    - Pointer to an uint32_t were we will store the calculated CRC 32
 *
 * @return      CRC_RES_BADPOINTER      - In case of bad pointer passed to the function
 *              CRC_RES_OK              - Crc 32 calculated successfully
 */
e_eCU_Crc_Res crc32Seed(const uint32_t seed, const uint8_t dataS[], const uint32_t dataSLen, uint32_t* const crc32SVal);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCRC_H */
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
#define ECU_BSTF_MINPOOLSIZE                  ( 0x01u )

/***********************************************************************************************************************
 *      TYPEDEFS
 **********************************************************************************************************************/
typedef enum
{
    BSTUFF_NOACTION = 0,
    BSTUFF_RETRIVE,
    BSTUFF_INSERT,
	BSTUFF_INSERTRETRIVE
}e_eCU_BStuffState;



typedef struct
{
    bool_t isInit;
	uint8_t* memPool;
	uint32_t memPoolSize;
	uint32_t memPoolCntr;
	bool_t frameStarted;
	bool_t frameEnded;
	bool_t previousWasEsc;
	uint8_t prevDataToElab;
	e_eCU_BStuffState currentState;
}e_eCU_BStuffCtx;



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
e_eCU_Res bStuffer_init(e_eCU_BStuffCtx* const ctx, uint8_t* const memPool, const uint32_t memPoolSize);

/**
 * Calculate the CRC 32 of a passed buffer using a custom seed
 * @param seed Seed that will be used to calculate the CRC 32
 * @param data Pointer to the data buffer where we will calculate the CRC 32
 * @param dataLen how many byte will be used to calculate the CRC 32
 * @param crc32 Pointer to an uint32_t were we will store the calculated CRC 32
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *         ECU_RES_OK crc 32 calculated successfully
 */
e_eCU_Res bStuffer_resetFrame(e_eCU_BStuffCtx* const ctx);

/**
 * Calculate the CRC 32 of a passed buffer using a custom seed
 * @param seed Seed that will be used to calculate the CRC 32
 * @param data Pointer to the data buffer where we will calculate the CRC 32
 * @param dataLen how many byte will be used to calculate the CRC 32
 * @param crc32 Pointer to an uint32_t were we will store the calculated CRC 32
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *         ECU_RES_OK crc 32 calculated successfully
 */
e_eCU_Res bStuffer_startFrame(e_eCU_BStuffCtx* const ctx);

/**
 * Calculate the CRC 32 of a passed buffer using a custom seed
 * @param seed Seed that will be used to calculate the CRC 32
 * @param data Pointer to the data buffer where we will calculate the CRC 32
 * @param dataLen how many byte will be used to calculate the CRC 32
 * @param crc32 Pointer to an uint32_t were we will store the calculated CRC 32
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *         ECU_RES_OK crc 32 calculated successfully
 */
e_eCU_Res bStuffer_endFrame(e_eCU_BStuffCtx* const ctx);

/**
 * Calculate the CRC 32 of a passed buffer using a custom seed
 * @param seed Seed that will be used to calculate the CRC 32
 * @param data Pointer to the data buffer where we will calculate the CRC 32
 * @param dataLen how many byte will be used to calculate the CRC 32
 * @param crc32 Pointer to an uint32_t were we will store the calculated CRC 32
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *         ECU_RES_OK crc 32 calculated successfully
 */
e_eCU_Res bStuffer_getState(e_eCU_BStuffCtx* const ctx, e_eCU_BStuffState* const state);

/**
 * Calculate the CRC 32 of a passed buffer using a custom seed
 * @param seed Seed that will be used to calculate the CRC 32
 * @param data Pointer to the data buffer where we will calculate the CRC 32
 * @param dataLen how many byte will be used to calculate the CRC 32
 * @param crc32 Pointer to an uint32_t were we will store the calculated CRC 32
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *         ECU_RES_OK crc 32 calculated successfully
 */
e_eCU_Res bStuffer_digest(e_eCU_BStuffCtx* const ctx, uint8_t dataToStuff);

/**
 * Calculate the CRC 32 of a passed buffer using a custom seed
 * @param seed Seed that will be used to calculate the CRC 32
 * @param data Pointer to the data buffer where we will calculate the CRC 32
 * @param dataLen how many byte will be used to calculate the CRC 32
 * @param crc32 Pointer to an uint32_t were we will store the calculated CRC 32
 * @return ECU_RES_BADPOINTER in case of bad pointer
 *         ECU_RES_OK crc 32 calculated successfully
 */
e_eCU_Res bStuffer_retriveData(e_eCU_BStuffCtx* const ctx, uint8_t* const dataStuffed);


#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCRC_H */
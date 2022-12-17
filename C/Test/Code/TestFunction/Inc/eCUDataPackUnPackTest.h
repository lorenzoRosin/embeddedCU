/**
 * @file       eCUDataPackUnPackTest.h
 *
 * @brief      Data pack and unpack test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

#ifndef ECUDATAPACKUNPACKTEST_H
#define ECUDATAPACKUNPACKTEST_H



#ifdef __cplusplus
extern "C" {
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCUType.h"
#include "eCUDataPack.h"
#include "eCUDataUnPack.h"



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Test the data pack and unpack modules
 *
 * @param[in]   none
 *
 * @return      none
 */
void eCU_TEST_dataPackUnPack(void);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUDATAPACKUNPACKTEST_H */
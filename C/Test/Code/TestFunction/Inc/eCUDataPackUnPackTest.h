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
#include "eCU_TYPE.h"
#include "eCU_DPK.h"
#include "eCU_DUNPK.h"



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
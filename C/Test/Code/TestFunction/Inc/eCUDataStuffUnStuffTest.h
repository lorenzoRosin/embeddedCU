/**
 * @file       eCUDataStuffUnStuffTest.h
 *
 * @brief      Data stuffer and unstuffer test
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

#ifndef ECUDATASTUFFUNSTUFFTEST_H
#define ECUDATASTUFFUNSTUFFTEST_H



#ifdef __cplusplus
extern "C" {
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include "eCU_TYPE.h"
#include "eCUByteUnStufferTest.h"
#include "eCU_BSTF.h"



/***********************************************************************************************************************
 * GLOBAL PROTOTYPES
 **********************************************************************************************************************/
/**
 * @brief       Test the data stuffer and unstuffer modules
 *
 * @param[in]   none
 *
 * @return      none
 */
void eCU_TEST_dataStuffUnStuff(void);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUDATASTUFFUNSTUFFTEST_H */
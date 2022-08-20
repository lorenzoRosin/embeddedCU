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
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
uint32_t calc_crc32( const uint8_t * p, uint32_t len);



/**
 * Return with a pointer to the active screen
 * @param disp pointer to display which active screen should be get. (NULL to use the default
 * screen)
 * @return pointer to the active screen object (loaded by 'lv_scr_load()')
 */
uint32_t calc_crc32_seedStart(uint32_t seed, const uint8_t * p, uint32_t len);
bool_t crc32_seed(const uint32_t seed, const uint8_t* data, const uint32_t dataLen, uint32_t const* crc32);


#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUCRC_H */
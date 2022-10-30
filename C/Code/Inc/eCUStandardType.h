/**
 * @file       eCUStandardType.h
 *
 * @brief      Ecu standard type header
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

#ifndef ECU_STANDARDTYPE_H
#define ECU_STANDARDTYPE_H



#ifdef __cplusplus
extern "C" {
#endif



/***********************************************************************************************************************
 *      INCLUDES
 **********************************************************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>



/***********************************************************************************************************************
 *      DEFINES
 **********************************************************************************************************************/
#ifndef NULL
  #define NULL          ( _NULL )
#endif

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_disable = "MISRAC2004-19.4"
    /* Suppressed for code clarity in test execution*/
#endif

    #ifndef bool_t
        #define bool_t           bool
    #endif

#ifdef __IAR_SYSTEMS_ICC__
    #pragma cstat_restore = "MISRAC2004-19.4"
#endif

#ifndef MAX_UINT32VAL
  #define MAX_UINT32VAL                                                                     ( ( uint32_t ) 0xFFFFFFFFu )
#endif

#ifndef MIN_UINT32VAL
  #define MIN_UINT32VAL                                                                     ( ( uint32_t ) 0x00000000u )
#endif

#ifndef MAX_UINT16VAL
  #define MAX_UINT16VAL                                                                         ( ( uint16_t ) 0xFFFFu )
#endif

#ifndef MIN_UINT16VAL
  #define MIN_UINT16VAL                                                                         ( ( uint16_t ) 0x0000u )
#endif

#ifndef MAX_UINT8VAL
  #define MAX_UINT8VAL                                                                             ( ( uint8_t ) 0xFFu )
#endif

#ifndef MIN_UINT8VAL
  #define MIN_UINT8VAL                                                                             ( ( uint8_t ) 0x00u )
#endif



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECU_STANDARDTYPE_H */
/**
 * @file eCUType.h
 *
 */

#ifndef ECU_TYPE_H
#define ECU_TYPE_H



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

#ifndef bool_t
  #define bool_t        ( bool  )
#endif


#define ECU_CRC_BASE_SEED                               ( 0xffffffffu )



/***********************************************************************************************************************
 *      TYPEDEFS
 **********************************************************************************************************************/
typedef enum t_eCU_Res
{
    ECU_RES_OK = 0,
    ECU_RES_BADPARAM,
    ECU_RES_BADPOINTER,
    ECU_RES_OUTOFMEM,
    ECU_RES_NOINITLIB,
}e_eCU_Res;



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECU_TYPE_H */

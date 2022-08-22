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
  #define NULL          _NULL
#endif

#ifndef bool_t
  #define bool_t          bool
#endif


#define CRC_BASE_SEED                               ( 0xffffffffu )




/***********************************************************************************************************************
 *      TYPEDEFS
 **********************************************************************************************************************/
typedef enum t_eCU_Res
{
    ECU_RES_OK = 0,
    ECU_RES_BADPARAM,
    ECU_RES_BADPOINTER,
    ECU_RES_BADTYPE,
    ECU_RES_NOINITLIB,
}e_eCU_Res;


typedef bool_t (*cb_readPage)      ( const uint32_t startPageId, const uint32_t pageOffset, const uint32_t pageSize, uint8_t* const dataToRead );
typedef bool_t (*cb_writePage)     ( const uint32_t startPageId, const uint32_t pageOffset, const uint32_t pageSize, const uint8_t* dataToWrite );
typedef bool_t (*cb_erasePage)     ( const uint32_t startPageId, const uint32_t pageOffset, const uint32_t pageSize );
typedef bool_t (*cb_crc32)         ( uint32_t* const calculatedCrc, const uint8_t* dataBuffer, const uint32_t calcSize, const uint32_t seed );


typedef enum t_eFSS_PageType
{
    EFSS_PAGETYPE_PARAM = 0,
    EFSS_PAGETYPE_LOG,
    EFSS_PAGETYPE_RAW,
}e_eFSS_PageType;

typedef struct t_eFSS_Cb
{
    /* CallBack Pointer */
    cb_readPage  pReadPg;
    cb_writePage pWritePg;
    cb_erasePage pErasePg;
    cb_crc32     pCrc32;

    /* Call back Options */
    uint32_t operationRetry;
    bool_t enableWriteCheck;
}s_eFSS_Cb;


typedef struct t_eFSS_PgInfo
{
    /* Page Info */
    uint32_t pageSize;
    uint32_t nOfPages;
    uint32_t areaId;
    e_eFSS_PageType pageType;
    bool_t pageBkp;
}s_eFSS_PgInfo;

typedef struct t_eFSS_PgLogVer
{
    /* Page Info */
    uint16_t logVersion;
    uint16_t rawPageVersion;
    uint8_t* parameterDefaultValue;
}s_eFSS_PgLogVer;

typedef struct t_eFSS_InitParam
{
    /* Page information */
    uint32_t pageSize;
    uint32_t nOfPages;
    uint32_t pageId;
    uint16_t logVersion;
    uint16_t rawPageVersion;
    uint8_t* parameterDefaultValue;

    /* Param Handler behaviour */
    uint32_t paramHandlerFlag;
    e_eFSS_PageType pageType;

    /* CallBack Pointer */
    s_eFSS_Cb    cbHolder;

    /* MemPool information */
    uint8_t* memPoolPointer;
    uint32_t memPoolSize;
}s_eFSS_InitParam;

typedef struct t_eFSS_Ctx
{
    /* Page information */
    s_eFSS_PgInfo pageInfo;

    /* Log Page version */
    s_eFSS_PgLogVer pageLogVer;

    /* CallBack Pointer */
    s_eFSS_Cb    cbHolder;

    /* MemPool information */
    uint8_t* memPoolPointer;
    uint32_t memPoolSize;

    /* Init information */
    bool_t isInitParams;
    bool_t isInitMemory;
}s_eFSS_Ctx;

typedef enum t_eFSS_PrmType
{
    EFSS_RESPARAMTYPE_INT8 = 0,
    EFSS_RESPARAMTYPE_UINT8,
    EFSS_RESPARAMTYPE_INT16,
    EFSS_RESPARAMTYPE_UINT16,
    EFSS_RESPARAMTYPE_INT32,
    EFSS_RESPARAMTYPE_UINT32,
    EFSS_RESPARAMTYPE_FLOAT,
    EFSS_RESPARAMTYPE_UINT64
}e_eFSS_PrmType;

typedef struct t_eFSS_SinglePrmType
{
    uint64_t    parameter;
    uint16_t    parameterID;
    uint8_t     parameterType;
    uint16_t    parameterTimeSetted;
    uint8_t     parameterMagicNumber;
    uint16_t    parameterVersion;
}s_eFSS_SinglePrmType;



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECU_TYPE_H */

/**
 * @file       eCUByteStuffer_prv.h
 *
 * @brief      Byte stuffer utils private definition
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

#ifndef ECUBYTESTUFFER_PRV_H
#define ECUBYTESTUFFER_PRV_H



#ifdef __cplusplus
extern "C" {
#endif



/***********************************************************************************************************************
 *      PRIVATE TYPEDEFS
 **********************************************************************************************************************/
typedef enum
{
    DBSTF_ST_PRV_NEEDSOF = 0,
    DBSTF_ST_PRV_NEEDRAWDATA,
    DBSTF_ST_PRV_NEEDNEGATEPRECDATA,
	DBSTF_ST_PRV_NEEDEOF,
    DBSTF_ST_PRV_STUFFEND,
}e_eCU_dBStf_st_prv;



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUBYTESTUFFER_PRV_H */

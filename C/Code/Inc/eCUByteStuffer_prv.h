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
    BSTF_SM_PRV_NEEDSOF = 0,
    BSTF_SM_PRV_NEEDRAWDATA,
    BSTF_SM_PRV_NEEDNEGATEPRECDATA,
	BSTF_SM_PRV_NEEDEOF,
    BSTF_SM_PRV_STUFFEND,
}e_eCU_BSTF_sm_prv;



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUBYTESTUFFER_PRV_H */
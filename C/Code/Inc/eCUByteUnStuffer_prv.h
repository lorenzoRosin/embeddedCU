/**
 * @file       eCUByteUnStuffer_prv.h
 *
 * @brief      Byte Unstuffer utils private definition
 *
 * @author     Lorenzo Rosin
 *
 **********************************************************************************************************************/

#ifndef ECUBYTEUNSTUFFER_PRV_H
#define ECUBYTEUNSTUFFER_PRV_H



#ifdef __cplusplus
extern "C" {
#endif



/***********************************************************************************************************************
 *      PRIVATE TYPEDEFS
 **********************************************************************************************************************/
typedef enum
{
    BUNSTF_SM_PRV_NEEDSOF = 0,
    BUNSTF_SM_PRV_NEEDRAWDATA,
    BUNSTF_SM_PRV_NEEDNEGATEDATA,
    BUNSTF_SM_PRV_UNSTUFFEND,
}e_eCU_BUNSTF_sm_prv;



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ECUBYTEUNSTUFFER_PRV_H */

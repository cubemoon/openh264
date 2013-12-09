/*!
 * \copy
 *     Copyright (c)  2009-2013, Cisco Systems
 *     All rights reserved.
 *
 *     Redistribution and use in source and binary forms, with or without
 *     modification, are permitted provided that the following conditions
 *     are met:
 *
 *        * Redistributions of source code must retain the above copyright
 *          notice, this list of conditions and the following disclaimer.
 *
 *        * Redistributions in binary form must reproduce the above copyright
 *          notice, this list of conditions and the following disclaimer in
 *          the documentation and/or other materials provided with the
 *          distribution.
 *
 *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *     "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *     LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *     FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *     COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *     INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *     BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *     CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *     LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *     ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *     POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * \file	error_code.h
 *
 * \brief	Error codes used in Wels decoder side
 *
 * \date	3/4/2009 Created
 *
 *************************************************************************************
 */
#ifndef WELS_ERROR_CODE_H__
#define WELS_ERROR_CODE_H__

namespace WelsDec {

typedef enum TagWelsErr
{
	ERR_NONE				= 0,
	ERR_INVALID_PARAMETERS	= 1,
	ERR_MALLOC_FAILED		= 2,
	ERR_API_FAILED			= 3,
	
	ERR_BOUND				= 31,
}EWelsErr;

/*
 * Specified error format:
 * ERR_NO = (ERR_LEVEL_FROM (HIGH WORD) << 16) | (ERR_INFO_FROM (LOW WORD))
 *
 */
#define GENERATE_ERROR_NO(iErrLevel, iErrInfo)	((iErrLevel << 16) | (iErrInfo & 0xFFFF))


/* ERR_LEVEL */
//-----------------------------------------------------------------------------------------------------------
enum{
	ERR_LEVEL_ACCESS_UNIT = 1,
	ERR_LEVEL_NAL_UNIT_HEADER,
	ERR_LEVEL_PREFIX_NAL,
	ERR_LEVEL_PARAM_SETS,
	ERR_LEVEL_SLICE_HEADER,
	ERR_LEVEL_SLICE_DATA,
	ERR_LEVEL_MB_DATA,
};

//-----------------------------------------------------------------------------------------------------------

/* More detailed error information, maximal value is 65535 */
//-----------------------------------------------------------------------------------------------------------
#define ERR_INFO_COMMON_BASE		1
#define ERR_INFO_SYNTAX_BASE		1001
#define ERR_INFO_LOGIC_BASE		10001
enum{
	/* Error from common system level: 1-1000 */	
	ERR_INFO_OUT_OF_MEMORY		= ERR_INFO_COMMON_BASE,
	ERR_INFO_INVALID_ACCESS,
	ERR_INFO_INVALID_PTR,
	ERR_INFO_INVALID_PARAM,
	ERR_INFO_FILE_NO_FOUND,
	ERR_INFO_PATH_NO_FOUND,
	ERR_INFO_ACCESS_DENIED,
	ERR_INFO_NOT_READY,
	ERR_INFO_WRITE_FAULT,
	ERR_INFO_READ_FAULT,	
	/* Error from H.264 syntax elements parser: 1001-10000 */
	ERR_INFO_NO_PREFIX_CODE		= ERR_INFO_SYNTAX_BASE,	// No start prefix code indication
	ERR_INFO_NO_PARAM_SETS, 					// No SPS and/ PPS before sequence header
	ERR_INFO_PARAM_SETS_NOT_INTEGRATED,			// Parameters sets (sps/pps) are not integrated at all before to decode VCL nal
	ERR_INFO_SPS_ID_OVERFLOW,
	ERR_INFO_PPS_ID_OVERFLOW,
	ERR_INFO_INVALID_PROFILE_IDC, 
	ERR_INFO_UNMATCHED_LEVEL_IDC, 
	ERR_INFO_INVALID_POC_TYPE,
	ERR_INFO_REF_COUNT_OVERFLOW,
	ERR_INFO_CROPPING_NO_SUPPORTED,
	ERR_INFO_INVALID_SLICEGROUP,
	ERR_INFO_INVALID_SLICEGROUP_MAP_TYPE,
	ERR_INFO_INVALID_FRAME_NUM,
	ERR_INFO_FMO_INIT_FAIL,
	ERR_INFO_SLICE_TYPE_OVERFLOW,
	ERR_INFO_INVALID_QP,
	ERR_INFO_INVALID_DBLOCKING_IDC,
	ERR_INFO_INVALID_MB_TYPE,
	ERR_INFO_INVALID_SUB_MB_TYPE,
	ERR_INFO_UNAVAILABLE_TOP_BLOCK_FOR_INTRA,
	ERR_INFO_UNAVAILABLE_LEFT_BLOCK_FOR_INTRA,
	ERR_INFO_INVALID_REF_INDEX,
	ERR_INFO_INVALID_CBP,
	ERR_INFO_DQUANT_OUT_OF_RANGE,
	ERR_INFO_CAVLC_INVALID_PREFIX,
	ERR_INFO_CAVLC_INVALID_TOTAL_COEFF,
	ERR_INFO_CAVLC_INVALID_ZERO_LEFT,
	ERR_INFO_MV_OUT_OF_RANGE,

	ERR_INFO_INVALID_I4x4_PRED_MODE, 
	ERR_INFO_INVALID_I16x16_PRED_MODE,
	ERR_INFO_INVALID_I_CHROMA_PRED_MODE,

    ERR_INFO_UNSUPPORTED_NON_BASELINE,
    ERR_INFO_UNSUPPORTED_FMOTYPE,
    ERR_INFO_UNSUPPORTED_MBAFF,
    ERR_INFO_UNSUPPORTED_ILP,
    ERR_INFO_UNSUPPORTED_CABAC_EL,
    ERR_INFO_UNSUPPORTED_SPSI,
    ERR_INFO_UNSUPPORTED_MGS,
    ERR_INFO_UNSUPPORTED_BIPRED,
    ERR_INFO_UNSUPPORTED_WP,

    ERR_INFO_FRAMES_LOST,
	ERR_INFO_DEPENDENCY_SPATIAL_LAYER_LOST,
	ERR_INFO_DEPENDENCY_QUALIT_LAYER_LOST,
	ERR_INFO_REFERENCE_PIC_LOST,
	ERR_INFO_INVALID_REORDERING,
	ERR_INFO_INVALID_MARKING,

	ERR_INFO_FMO_NOT_SUPPORTED_IN_BASE_LAYER,
	ERR_INFO_INVALID_ESS,
	ERR_INFO_INVALID_SLICE_TYPE,
	ERR_INFO_INVALID_REF_MARKING,
	ERR_INFO_INVALID_REF_REORDERING,
	
	/* Error from corresponding logic, 10001-65535 */
	ERR_INFO_NO_IDR_PIC		= ERR_INFO_LOGIC_BASE,	// NO IDR picture available before sequence header
	ERR_INFO_EC_NO_NEIGHBOUR_MBS,
	ERR_INFO_EC_UNEXPECTED_MB_TYPE,
	ERR_INFO_EC_NO_ENOUGH_NEIGHBOUR_MBS,
	//for LTR
	ERR_INFO_INVALID_MMCO_OPCODE_BASE,
	ERR_INFO_INVALID_MMCO_SHORT2UNUSED,
	EER_INFO_INVALID_MMCO_LONG2UNUSED,
	ERR_INFO_INVALID_MMCO_SHOART2LONG,
	ERR_INFO_INVALID_MMCO_REF_NUM_OVERFLOW,
	ERR_INFO_INVALID_MMCO_REF_NUM_NOT_ENOUGH,
	ERR_INFO_INVALID_MMCO_LONG_TERM_IDX_EXCEED_MAX,
};
//-----------------------------------------------------------------------------------------------------------

} // namespace WelsDec

#endif//WELS_ERROR_CODE_H__


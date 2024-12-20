//----------------------------------------------------------------------------
//
// Astrometa Co., Ltd. - Software Development Kit
// Copyright (c) 2009-2024, Astrometa Co., Ltd.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//

#ifndef _SPEC_ISO_13818_
#define _SPEC_ISO_13818_

#include <mux/mux_define.h>

/**
 * @ingroup mprop_iso
 * ISO Channel Properties
 */
typedef struct _mux_spec_iso_channel{
	uint16_t transport_stream_id;	/** PAT Table transport id */
	uint16_t recv;
}mux_spec_iso_channel;

typedef mux_spec_iso_channel* Pmux_spec_iso_channel;

/**
 * @ingroup mprop_iso
 * ISO Program Properties
 */
typedef struct _mux_spec_iso_program
{
	uint16_t program_number;		/* PMT Table program number*/
	uint16_t recv;
}mux_spec_iso_program;

typedef mux_spec_iso_program* Pmux_spec_iso_program;

static const mux_spec_iso_channel default_mux_spec_iso_channel = { 1,0, };
static const mux_spec_iso_program default_mux_spec_iso_program = { 1,0, };

#endif

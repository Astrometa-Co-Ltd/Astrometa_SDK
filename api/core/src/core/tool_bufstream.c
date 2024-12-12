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

#include <core/tools/tool_bufstream.h>

void putbuf_buf(Pbufstream pbuf, uint8_t* pbufdata, int32_t len)
{
	memcpy(&pbuf->buf[pbuf->pos], pbufdata, len);
	pbuf->pos += len;
}

void getbuf_buf(Pbufstream pbuf, uint8_t* pbufdata, int32_t len)
{
	memcpy(pbufdata, &pbuf->buf[pbuf->pos], len);
	pbuf->pos += len;
}

uint8_t* setbuf_offset(Pbufstream pbuf, int32_t pos)
{
	pbuf->pos = pos;
	return getbuf_ptr(pbuf);
}

void putbuf_uint32_t(Pbufstream pbuf, uint32_t val)
{
	putbuf_byte(pbuf, (uint8_t)(val >> 24));
	putbuf_byte(pbuf, (uint8_t)(val >> 16));
	putbuf_byte(pbuf, (uint8_t)(val >> 8));
	putbuf_byte(pbuf, (uint8_t)val);
}

uint32_t getbuf_uint32_t(Pbufstream pbuf)
{
	uint32_t val = (getbuf_byte(pbuf) << 24) | (getbuf_byte(pbuf) << 16) | (getbuf_byte(pbuf) << 8) | (getbuf_byte(pbuf));
	return val;
}

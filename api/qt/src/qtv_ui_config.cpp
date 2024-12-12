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

#include <ui/base/qtv_ui_config.h>
#include "./internal/qinternal_properties.h"

/* qtvUIConfigMuxChannel */

qtvUIConfigMuxChannel::qtvUIConfigMuxChannel(qtvServiceBase* service) :
	m_service(service),
	qtvUIConfigBase(qui_config_muxchannel)
{

}

qtvMuxChannel* qtvUIConfigMuxChannel::getChannel()
{
	if (m_service->_mode() == qservice_usbmuxer)
	{
		qtvServiceUSBMuxer* usbmuxer = qobject_cast<qtvServiceUSBMuxer*>(m_service);
		if (usbmuxer)
		{
			qtvUSBMuxerChannel* channel = NULL;
			if (is_vatek_success(usbmuxer->getChannel(&channel)))
				return channel;
		}
	}
	return NULL;
}

/* qtvUIConfigCodec */

qtvUIConfigCodec::qtvUIConfigCodec(qtv_ui_config_mode mode,QList<qtvCodecFactory*>* codecs) :
	qtvUIConfigBase(mode),
	m_codecs(codecs),
	m_properties(NULL)
{

}

qtvUIConfigCodec::~qtvUIConfigCodec()
{
	if (m_properties)
		delete m_properties;
}

/* qtvUIConfigProperties */

qtvUIConfigProperties::qtvUIConfigProperties(qtv_ui_config_mode mode, qtvPropertyCollection* properties) :
	m_properties(properties),
	qtvUIConfigBase(mode)
{

}

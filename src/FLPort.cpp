/*
 * FLPort.cpp
 *
 *  Created on: 31.10.2015
 *      Author: dehnhardt
 */

#include "FLPort.h"

namespace flaarlib {

FLPort::FLPort(FLModule * module, unsigned int m_numberOfChannels) :
		m_parent(module), m_numberOfChannels(m_numberOfChannels) {
}

FLPort::~FLPort() {
	// TODO Auto-generated destructor stub
}

} /* namespace flaarlib */

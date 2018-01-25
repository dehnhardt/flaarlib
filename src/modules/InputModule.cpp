/*
 * InputModule.cpp
 *
 *  Created on: 29.01.2016
 *      Author: dehnhardt
 */

#include "InputModule.h"

namespace flaarlib {

InputModule::InputModule(std::string moduleName, int numberOfOutputChannels) :
		FLModule(moduleName) {
	m_numberOfOutputChannels = numberOfOutputChannels;
	m_numberOfOutputPorts = 0;
	Flaarlib::instance()->addInputModule(this);
}

InputModule::~InputModule() {
	// TODO Auto-generated destructor stub
}

int InputModule::internal_process(__attribute__((unused))  jack_nframes_t nframes,
		__attribute__((unused)) void* arg) {
	return (0);
}

bool InputModule::internal_connectOutput(__attribute__((unused))  FLModule* next) {
	return (true);
}

} /* namespace flaarlib */


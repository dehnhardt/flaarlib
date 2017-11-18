/*
 * ThroughModule.cpp
 *
 *  Created on: 29.01.2016
 *      Author: dehnhardt
 */

#include "ThroughModule.h"

namespace flaarlib {

ThroughModule::ThroughModule(std::string moduleName, int numberOfInputChannels,
		int numberOfOutputChannels) :
		FLModule(moduleName) {
	m_numberOfInputChannels = numberOfInputChannels;
	m_numberOfOutputChannels = numberOfOutputChannels;
	m_numberOfInputPorts = 0;
	m_numberOfOutputPorts = 0;
}

ThroughModule::~ThroughModule() {
	// TODO Auto-generated destructor stub
}

int ThroughModule::internal_process(jack_nframes_t nframes, void* arg) {
	return (0);
}

bool ThroughModule::internal_connectOutput(FLModule* next) {
	return (true);
}

} /* namespace flaarlib */


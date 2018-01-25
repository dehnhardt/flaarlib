/*
 * FLModul.cpp
 *
 *  Created on: 31.10.2015
 *      Author: dehnhardt
 */

#include "FLModule.h"
#include "exceptions/Exceptions.h"
#include <boost/uuid/random_generator.hpp>
#include <sstream>

#include "logging/FLLog.h"

namespace flaarlib {

FLModule::FLModule(std::string moduleName) :
		m_numberOfInputChannels(-1), m_numberOfOutputChannels(-1), m_moduleName(
				moduleName), m_numberOfInputPorts(-1), m_numberOfOutputPorts(
				-1), m_processedInputs(-1) {

	boost::uuids::random_generator gen;
	m_moduleUUID = gen();
	FLLog::info("FLModule \"%s\" initialized", moduleName.c_str());
}

FLModule::~FLModule() {
	m_inputPorts.clear();
	m_outputPorts.clear();
}

int FLModule::connectOutput(FLModule* next) {
	if (m_numberOfOutputPorts == -1) {
		throw new ConfigurationExecption(
				ConfigurationExceptionType::NO_OUTPUT_ALLOWED_IN_SOURCE_MODULE);
	}
	if( next->m_numberOfInputPorts == -1 ){
		throw new ConfigurationExecption(
				ConfigurationExceptionType::NO_INPUT_ALLOWED_IN_TARGET_MODULE);
	}
	FLLog::debug("connect output");
	if (next->m_numberOfInputChannels != m_numberOfOutputChannels)
		FLLog::debug("Number of input channels of next module (%d) does not"
				"match number of output channels (%d)",
				next->m_numberOfInputChannels, m_numberOfOutputChannels);
	if (m_outputPorts[m_moduleName] != 0) {
		FLLog::debug(
				"The output of module %s is already connected to input of module %s",
				getModuleName().c_str(), next->getModuleName().c_str());
	}
	//TODO implement exceptions
	FLPort *p = createOutputPort(next->getModuleName());
	this->m_outputPorts[next->getModuleName()] = p;
	next->m_inputPorts[getModuleName()] = p;
	return 0;
}

int FLModule::inputConnected() {
	//TODO implement
	return 0;
}

int FLModule::process(jack_nframes_t nframes, void * arg) {
	int result_;
	m_processedInputs++;
	//only process the data until all input ports have been processed
	if (m_processedInputs > m_numberOfInputPorts)
		return -1;

	m_processedInputs = 0;
	result_ = internal_process(nframes, arg);
	//TODO call the process-method of all out-ports
	return result_;
}

FLPort* FLModule::craeteInputPort(std::string connectedModuleName) {
	FLPort *p = new FLPort(this);
	p->setNumberOfChannels(m_numberOfInputChannels);
	m_inputPorts[connectedModuleName] = p;
	m_numberOfInputPorts++;
	return p;
}

FLPort* FLModule::createOutputPort(std::string connectedModuleName) {
	FLPort *p = new FLPort(this);
	p->setNumberOfChannels(m_numberOfOutputChannels);
	m_outputPorts[connectedModuleName] = p;
	m_numberOfInputPorts++;
	return p;
}

} /* namespace flaarlib */

void flaarlib::FLModule::createMapping() {
	// TODO
}

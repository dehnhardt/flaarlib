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

namespace flaarlib
{

FLModule::FLModule(std::string moduleName) :
	m_numberOfInputChannels(-1), m_numberOfOutputChannels(-1), m_numberOfInputPorts(
			-1), m_numberOfOutputPorts(-1), m_moduleName(moduleName), m_processedInputs(
					-1)
{

	boost::uuids::random_generator gen;
	m_moduleUUID = gen();
	Flaarlib::instance()->addModule(this);
	FLLog::info("FLModule \"%s\" initialized", moduleName.c_str());
}

FLModule::~FLModule()
{
	m_inputPorts.clear();
	m_outputPorts.clear();
}

int FLModule::connectOutput(FLModule *next)
{
	// Modules already connected
	if (m_outputPorts[next->getModuleName()] != 0)
	{
		FLLog::debug(
				"The output of module %s is already connected to input of module %s",
				getModuleName().c_str(), next->getModuleName().c_str());
		return (0);
	}
	if (m_numberOfOutputPorts == -1)
	{
		throw new ConfigurationExecption(
				ConfigurationExceptionType::NO_OUTPUT_ALLOWED_IN_SOURCE_MODULE);
	}
	if (next->m_numberOfInputPorts == -1)
	{
		throw new ConfigurationExecption(
				ConfigurationExceptionType::NO_INPUT_ALLOWED_IN_TARGET_MODULE);
	}
	if (next->m_numberOfInputChannels < m_numberOfOutputChannels)
		throw new ConfigurationExecption(
				ConfigurationExceptionType::LESS_INPUT_CHANNELS);
	if (next->m_numberOfInputChannels > m_numberOfOutputChannels)
		throw new ConfigurationExecption(
				ConfigurationExceptionType::MORE_INPUT_CHANNELS);
	FLPort *p = createOutputPort(next);
	// this->m_outputPorts[next->getModuleName()] = p;
	next->m_inputPorts[getModuleName()] = p;
	// call callback in following module
	next->inputConnected(this);
	return (0);
}

int FLModule::inputConnected(FLModule *previous)
{
	//TODO implement
	FLLog::debug("%s: Input connected to %s", getModuleName().c_str(),
				 previous->getModuleName().c_str());
	return (0);
}

int FLModule::process(jack_nframes_t nframes, void *arg)
{
	int result_;
	m_processedInputs++;
	//only process the data until all input ports have been processed
	if (m_processedInputs > m_numberOfInputPorts)
		return (-1);

	m_processedInputs = 0;
	result_ = internal_process(nframes, arg);
	//TODO call the process-method of all out-ports
	return (result_);
}

FLPort *FLModule::createOutputPort(FLModule *connectedModule)
{
	FLPort *p = new FLPort(connectedModule);
	p->setNumberOfChannels(m_numberOfOutputChannels);
	m_outputPorts[connectedModule->getModuleName()] = p;
	m_numberOfOutputPorts++;
	return (p);
}

MODULE_INFO *FLModule::moduleInfo()
{
	if( !m_pModuleInfo )
	{
		m_pModuleInfo = new MODULE_INFO();
		m_pModuleInfo->type = getModuleType();
		m_pModuleInfo->functionalname = getModuleFuctionalName();
		m_pModuleInfo->description = getModuleDescription();
	}
	return  m_pModuleInfo;
}

} /* namespace flaarlib */

void flaarlib::FLModule::createMapping()
{
	// TODO
}

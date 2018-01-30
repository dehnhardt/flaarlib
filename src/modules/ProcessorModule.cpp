/*
 * ThroughModule.cpp
 *
 *  Created on: 29.01.2016
 *      Author: dehnhardt
 */

#include "FLProcessorModule.h"

namespace flaarlib
{

FLProcessorModule::FLProcessorModule(std::string moduleName, int numberOfInputChannels,
									 int numberOfOutputChannels) :
	FLModule(moduleName)
{
	m_numberOfInputChannels = numberOfInputChannels;
	m_numberOfOutputChannels = numberOfOutputChannels;
	m_numberOfInputPorts = 0;
	m_numberOfOutputPorts = 0;
}

FLProcessorModule::~FLProcessorModule()
{
	// TODO Auto-generated destructor stub
}

int FLProcessorModule::internal_process(
		__attribute__((unused))   jack_nframes_t nframes,
		__attribute__((unused)) void *arg)
{
	return (0);
}

bool FLProcessorModule::internal_connectOutput(
		__attribute__((unused))  FLModule *next)
{
	return (true);
}

} /* namespace flaarlib */


/*
 * OutputModule.cpp
 *
 *  Created on: 29.01.2016
 *      Author: dehnhardt
 */

#include "FLOutputModule.h"

namespace flaarlib
{

FLOutputModule::FLOutputModule(std::string moduleName, int numberOfInputChannels) :
	FLModule(moduleName)
{
	m_numberOfInputChannels = numberOfInputChannels;
	m_numberOfInputPorts = 0;
}

FLOutputModule::~FLOutputModule()
{
	// TODO Auto-generated destructor stub
}

int FLOutputModule::internal_process(__attribute__((unused))  jack_nframes_t nframes,
									 __attribute__((unused)) void *arg)
{
	return (0);
}

bool FLOutputModule::internal_connectOutput(
		__attribute__((unused))  FLModule *next)
{
	return (true);
}

} /* namespace flaarlib */


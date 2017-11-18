/*
 * Flaarlib.cpp
 *
 *  Created on: 04.11.2015
 *      Author: dehnhardt
 */

#include "logging/FLLog.h"

#include "Flaarlib.h"
#include "FLModule.h"
#include "modules/InputModule.h"
#include "exceptions/Exceptions.h"

#include <vector>

namespace flaarlib {

FLAARLIB_API FLLogger * FLLog::fllogger_ = 0;

Flaarlib::Flaarlib() {
	FLLog::info("Init FLLib");
}

Flaarlib::~Flaarlib() {
}

/**
 * Initialize the g3 logging library as a fast async logging facility
 */
void Flaarlib::initializeLogging() {
}

void Flaarlib::addInputModule(InputModule* inputModule) {
	m_inputModules[inputModule->getModuleName()] = inputModule;
}

void Flaarlib::addModule(FLModule* module) {
	if (m_modules[module->getModuleName()] != 0)
		throw new ConfigurationExecption(
				ConfigurationExceptionType::NAME_NOT_UNIQUE, "ABC", "DEF");
	m_modules[module->getModuleName()] = module;
}

void Flaarlib::loopDetection() {
	//for(m_inputModules)
}

Flaarlib* Flaarlib::_instance = 0;

} /* namespace flaarlib */


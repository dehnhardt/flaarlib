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
#include "helper/LoopDetector.h"

#include <vector>
#include <algorithm>

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
	string moduleName = module->getModuleName();
	if (!m_modules.push_back_unique(moduleName))
		throw new ConfigurationExecption(
				ConfigurationExceptionType::NAME_NOT_UNIQUE, "ABC", "DEF");
}

void Flaarlib::loopDetection() {
	map<string, InputModule*>::iterator it;
	try {
		for (it = m_inputModules.begin(); it != m_inputModules.end(); ++it) {
			vector<string> moduleNames;
			FLModule *m = it->second;
			UniqueVector<string> v;
			new LoopDetector(m, v);
		}
		m_configurationValid = true;
	} catch (ConfigurationExecption *e) {
		FLLog::error(e->getMessage());
	}
}

Flaarlib* Flaarlib::_instance = 0;

} /* namespace flaarlib */


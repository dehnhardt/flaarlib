/*
 * LoopDetector.cpp
 *
 *  Created on: 19.11.2017
 *      Author: dehnhardt
 */

#include "LoopDetector.h"
#include "../exceptions/Exceptions.h"
#include "../logging/FLLog.h"

#include <map>
#include <sstream>

namespace flaarlib {

LoopDetector::LoopDetector(FLModule *m, UniqueVector<std::string> v) :
		m_module(m) {
	m_Unique = UniqueVector<std::string>(v);
	m_Unique.push_back_unique(m_module->getModuleName());
	loop();
}

LoopDetector::~LoopDetector() {
	// TODO Auto-generated destructor stub
}

void LoopDetector::loop() {
	while (m_module != 0) {
		int numberOfOutputPorts = m_module->getNumberOfOutputPorts();
		if (numberOfOutputPorts > 0) {
			std::map<std::string, FLPort *> outputPorts =
					m_module->getOutputPorts();
			std::map<std::string, FLPort*>::iterator it;
			int i = 0;
			for (it = outputPorts.begin(); it != outputPorts.end(); ++it, ++i) {
				FLPort *p = it->second;
				FLModule *m = p->getModule();
				std::string name = m->getModuleName();
				if (i == 0) {
					if (!m_Unique.push_back_unique(name)) {
						FLLog::error("Loop in ModulePath: %s/%s",
								constructPath().c_str(), name.c_str());
						throw new ConfigurationExecption(
								ConfigurationExceptionType::SIGNAL_LOOP);
					}
					m_module = m;
				} else {
					new LoopDetector(m, m_Unique);
				}
			}
		} else
			break;
	}
	FLLog::debug("ModulePath: %s", constructPath().c_str());
}

string LoopDetector::constructPath() {
	UniqueVector<std::string>::iterator it;
	stringstream out;
	for (it = m_Unique.begin(); it != m_Unique.end(); ++it) {
		out << "/" << (*it);
	}
	return (out.str());
}

} /* namespace flaarlib */

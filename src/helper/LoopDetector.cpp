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

namespace flaarlib
{

LoopDetector::LoopDetector(FLModule *m, UniqueVector<std::string> v) :
	m_pModule(m)
{
	m_Unique = UniqueVector<std::string>(v);
	m_Unique.push_back_unique(m_pModule->getModuleUuid());
	loop();
}

LoopDetector::~LoopDetector()
{
	// TODO Auto-generated destructor stub
}

void LoopDetector::loop()
{
	while (m_pModule != 0)
	{
		int numberOfOutputPorts = m_pModule->getNumberOfOutputPorts();
		if (numberOfOutputPorts > 0)
		{
			std::vector<std::map<std::string, FLPort *>> outputPorts =
							m_pModule->getOutputPorts();
			for( auto outputPort : outputPorts )
			{
				int i = 0;
				for( auto portConnection : outputPort )
				{
					FLPort *p = portConnection.second;
					FLModule *m = p->getModule();
					std::string uuid = m->getModuleUuid();
					if (i == 0)
					{
						if (!m_Unique.push_back_unique(uuid))
						{
							FLLog::error("Loop in ModulePath: %s/%s",
										 constructPath().c_str(), uuid.c_str());
							throw new ConfigurationExecption(
									ConfigurationExceptionType::SIGNAL_LOOP);
						}
						m_pModule = m;
					}
					else
						new LoopDetector(m, m_Unique);

				}
			}
		}
		else
			break;
	}
	FLLog::debug("ModulePath: %s", constructPath().c_str());
}

string LoopDetector::constructPath()
{
	UniqueVector<std::string>::iterator it;
	stringstream out;
	for (it = m_Unique.begin(); it != m_Unique.end(); ++it)
		out << "/" << (*it);
	return (out.str());
}

} /* namespace flaarlib */

/*
 * Flaarlib.cpp
 *
 *  Created on: 04.11.2015
 *      Author: dehnhardt
 */

#include "logging/FLLog.h"

#include "Flaarlib.h"
#include "FLModule.h"
#include "modules/FLInputModule.h"
#include "exceptions/Exceptions.h"
#include "helper/LoopDetector.h"
#include "FLRepository.h"
#include "modules/FLAudioFileInputModule.h"
#include "modules/FLMIDIFileInputModule.h"
#include "modules/FLAudioFileOutputModule.h"
#include "modules/FLVolumeControl.h"

#include <vector>
#include <algorithm>


namespace flaarlib
{

FLAARLIB_API FLLogger *FLLog::fllogger_ = 0;

Flaarlib::Flaarlib()
{
	FLLog::debug("Init FLLib");
}

Flaarlib::~Flaarlib()
{
}

/**
 * Initialize the g3 logging library as a fast async logging facility
 */
void Flaarlib::initializeLogging()
{
}

bool Flaarlib::createRepository()
{
	m_pRepository = new FLRepository();
	// don't use uuid here as we don't want to register a module twice
	m_pRepository->registerModule( new FLAudioFileInputModule("r_AudioFileInputModule", -1));
	m_pRepository->registerModule( new FLMIDIFileInputModule("r_MIDIFileInputModule"));
	m_pRepository->registerModule( new FLAudioFileOutputModule("r_AudioFileOutputModule", -1));
	m_pRepository->registerModule( new FLVolumeControl("r_VolumeControl", -1, -1));
	return true;
}

void Flaarlib::addInputModule(FLInputModule *inputModule)
{
	m_inputModules[inputModule->getModuleUuid()] = inputModule;
}

bool Flaarlib::removeModule(std::string uuid)
{
	for( UniqueVector<std::string>::iterator it = m_modules.begin(); it < m_modules.end(); ++it)
	{
		if( *it == uuid )
		{
			m_modules.erase(it);
			return true;
		}
	}
	return false;
}

bool Flaarlib::init()
{
	bool ret = true;
	ret &= createRepository();
	return(ret);
}

void Flaarlib::addModule(FLModule *module)
{
	string moduleUuid = module->getModuleUuid();
	if (!m_modules.push_back_unique(moduleUuid))
		throw new ConfigurationExecption(
				ConfigurationExceptionType::NAME_NOT_UNIQUE, "ABC", "DEF");
}

void Flaarlib::loopDetection()
{
	map<string, FLInputModule *>::iterator it;
	try
	{
		for (it = m_inputModules.begin(); it != m_inputModules.end(); ++it)
		{
			vector<string> moduleNames;
			FLModule *m = it->second;
			UniqueVector<string> v;
			new LoopDetector(m, v);
		}
		m_configurationValid = true;
	}
	catch (ConfigurationExecption *e)
	{
		FLLog::error(e->getMessage());
	}
}

Flaarlib *Flaarlib::_instance = 0;

} /* namespace flaarlib */


#include "FLRepository.h"
#include "logging/FLLog.h"

namespace flaarlib
{

FLRepository::FLRepository()
{

}

void FLRepository::registerModule(FLModule *module)
{
	MODULE_INFO *mi = module->moduleInfo();
	std::map<std::string, MODULE_INFO *> m = m_RepositoryMap[mi->type];
	m.emplace(std::pair<std::string, MODULE_INFO *>(mi->functionalname, mi));
	m_RepositoryMap[mi->type] = m;
	FLLog::debug("Add Module %s to repository", mi->functionalname.c_str());
}

bool FLRepository::removeModule(std::string uuid)
{
	FLLog::debug("aboot to Remove %s", uuid.c_str());
	for( auto repositoryMap : m_RepositoryMap )
	{
		if( repositoryMap.second.find(uuid) != repositoryMap.second.end() )
		{
			if( repositoryMap.second.erase(uuid) == 1)
			{
				FLLog::debug("Removed %s", uuid.c_str());
				return true;
			}
			else
				FLLog::error("%s not found", uuid.c_str());
		}
	}
	return false;
}
}


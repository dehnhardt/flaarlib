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

}

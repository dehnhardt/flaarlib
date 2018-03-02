#ifndef FLREPOSITORY_H
#define FLREPOSITORY_H

#include "FLModuleDefs.h"
#include "FLModule.h"

#include <map>
#include <string>

namespace flaarlib
{

class FLAARLIB_API FLRepository
{
public:
	FLRepository();
	void registerModule( FLModule *pModule );
	void removeModule( std::string uuid );

public: // getters
	std::map<MODULE_TYPE,std::map<std::string,MODULE_INFO *>> FLRepositoryMap()
	{
		return m_RepositoryMap;
	}


private: // members
	std::map<MODULE_TYPE,std::map<std::string,MODULE_INFO *>> m_RepositoryMap;

};

}
#endif // FLREPOSITORY_H

#ifndef FLMODULEDEFS_H
#define FLMODULEDEFS_H

#include <string>

namespace flaarlib
{

enum MODULE_TYPE
{
	INPUT = 1,
	OUTPUT = 2,
	PROCESSOR = 3
};

struct MODULE_INFO
{
	MODULE_TYPE type;
	std::string functionalname;
	std::string description;
};

}
#endif // FLMODULEDEFS_H

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

enum DATA_TYPE
{
	UNKNOWN = 0,
	AUDIO = 1,
	MIDI = 2,
	OSC = 4,
	ALL = 255
};

struct MODULE_INFO
{
	MODULE_TYPE type;
	DATA_TYPE dataType;
	std::string functionalname;
	std::string description;
};

}
#endif // FLMODULEDEFS_H

#ifndef MODULES_FLMIDIFILEINPUTMODULE_H
#define MODULES_FLMIDIFILEINPUTMODULE_H

#include "FLInputModule.h"

namespace flaarlib
{

class FLAARLIB_API FLMIDIFileInputModule : public FLInputModule
{

public:
	FLMIDIFileInputModule(std::string moduleUuid);

protected: //repository methods
	virtual DATA_TYPE getModuleDataType() override
	{
		return DATA_TYPE::MIDI;
	}

	virtual std::string getModuleFuctionalName() override
	{
		return "MIDIfile Input";
	}

	virtual std::string getModuleDescription() override
	{
		return "Reads from a file with MIDI data";
	}

};


}


#endif // MODULES_FLMIDIFILEINPUTMODULE_H

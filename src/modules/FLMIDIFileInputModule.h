#ifndef MODULES_FLMIDIFILEINPUTMODULE_H
#define MODULES_FLMIDIFILEINPUTMODULE_H

#include "FLInputModule.h"

namespace flaarlib
{

class FLMIDIFileInputModule : public FLInputModule
{

public:
	FLMIDIFileInputModule(std::string moduleName);

protected: //repository methods
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
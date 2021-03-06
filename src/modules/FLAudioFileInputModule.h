#ifndef MODULES_FLAUDIOFILEINPUTMODULE_H
#define MODULES_FLAUDIOFILEINPUTMODULE_H

#include "FLInputModule.h"

namespace flaarlib
{


class FLAARLIB_API FLAudioFileInputModule : public FLInputModule
{
public:
	FLAudioFileInputModule(std::string moduleUuid, int numberOfOutputChannels);

protected: //repository methods

	virtual DATA_TYPE getModuleDataType() override
	{
		return DATA_TYPE::AUDIO;
	}

	virtual std::string getModuleFuctionalName() override
	{
		return "Audiofile Input";
	}

	virtual std::string getModuleDescription() override
	{
		return "Reads from a file with audio Data";
	}

};

}

#endif // MODULES_FLAUDIOFILEINPUTMODULE_H

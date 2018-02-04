#ifndef MODULES_FLAUDIOFILEOUTPUTMODULE_H
#define MODULES_FLAUDIOFILEOUTPUTMODULE_H

#include "FLOutputModule.h"

namespace flaarlib
{

class FLAARLIB_API FLAudioFileOutputModule : public FLOutputModule
{
public:
	FLAudioFileOutputModule(std::string moduleName, int numberOfInputChannels);

protected: //repository methods
	virtual DATA_TYPE getModuleDataType() override
	{
		return DATA_TYPE::AUDIO;
	}

	virtual std::string getModuleFuctionalName() override
	{
		return "Audiofile Output";
	}

	virtual std::string getModuleDescription() override
	{
		return "Writes audio data to a file";
	}

};

}

#endif // MODULES_FLAUDIOFILEOUTPUTMODULE_H

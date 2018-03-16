#ifndef MODULES_FLVOLUMECONTROL_H
#define MODULES_FLVOLUMECONTROL_H

#include "FLProcessorModule.h"

namespace flaarlib
{

class FLAARLIB_API FLVolumeControl : public FLProcessorModule
{
public:
	FLVolumeControl(std::string moduleUuid, int numberOfInputChannels,
					int numberOfOutputChannels);

protected: //repository methods

	virtual DATA_TYPE getModuleDataType() override
	{
		return DATA_TYPE::ALL;
	}

	virtual std::string getModuleFuctionalName() override
	{
		return "Volume Control";
	}

	virtual std::string getModuleDescription() override
	{
		return "Controls the volume of all channels";
	}

};

}

#endif // MODULES_FLVOLUMECONTROL_H

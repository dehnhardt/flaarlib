#include "FLVolumeControl.h"

namespace flaarlib
{

FLVolumeControl::FLVolumeControl(std::string moduleUuid, int numberOfInputChannels, int numberOfOutputChannels)
	: FLProcessorModule(moduleUuid, numberOfInputChannels, numberOfOutputChannels )
{

}

}

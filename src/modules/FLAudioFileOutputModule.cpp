#include "FLAudioFileOutputModule.h"

namespace flaarlib
{

FLAudioFileOutputModule::FLAudioFileOutputModule(std::string moduleUuid, int numberOfInputChannels)  :
	FLOutputModule(moduleUuid, numberOfInputChannels) {}

}

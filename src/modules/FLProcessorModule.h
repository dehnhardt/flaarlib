/*
 * ThroughModule.h
 *
 *  Created on: 29.01.2016
 *      Author: dehnhardt
 */

#ifndef MODULES_FLPROCESSORMODULE_H_
#define MODULES_FLPROCESSORMODULE_H_

#include "../FLModule.h"
#include <string>

namespace flaarlib
{

class FLAARLIB_API FLProcessorModule: public FLModule
{

public:
	FLProcessorModule(std::string moduleUuid, int numberOfInputChannels,
					  int numberOfOutputChannels);
	virtual ~FLProcessorModule();

	/**
	 * method for processing the data
	 */
	virtual int internal_process(jack_nframes_t nframes, void *arg ) override;

	/**
	 * method to overwrite when module has specific need when connecting
	 */
	virtual bool internal_connectOutput( FLModule *next) override;

protected: //repository methods
	MODULE_TYPE getModuleType() override
	{
		return MODULE_TYPE::PROCESSOR;
	}


};

} /* namespace flaarlib */

#endif /* MODULES_FLPROCESSORMODULE_H_ */

/*
 * OutputModule.h
 *
 *  Created on: 29.01.2016
 *      Author: dehnhardt
 */

#ifndef MODULES_FLOUTPUTMODULE_H_
#define MODULES_FLOUTPUTMODULE_H_

#include "../FLModule.h"
#include <string>

namespace flaarlib
{

class FLAARLIB_API FLOutputModule: public FLModule
{

public:
	FLOutputModule(std::string moduleName, int numberOfInputChannels);
	virtual ~FLOutputModule();

	/**
	 * method for processing the data
	 */
	virtual int internal_process(jack_nframes_t nframes, void *arg) override;

	/**
	 * method to overwrite when module has specific need when connecting
	 */
	virtual bool internal_connectOutput(FLModule *next) override;

protected: //repository methods
	MODULE_TYPE getModuleType() override
	{
		return MODULE_TYPE::OUTPUT;
	}


};

} /* namespace flaarlib */

#endif /* MODULES_FLOUTPUTMODULE_H_ */

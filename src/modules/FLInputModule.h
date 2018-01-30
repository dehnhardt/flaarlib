/*
 * InputModule.h
 *
 *  Created on: 29.01.2016
 *      Author: dehnhardt
 */

#ifndef MODULES_FLINPUTMODULE_H_
#define MODULES_FLINPUTMODULE_H_

#include "../FLModule.h"
#include <string>

namespace flaarlib
{

class FLAARLIB_API FLInputModule : public FLModule
{

public:
	FLInputModule(const std::string moduleName, const int numberOfOutputChannels);
	virtual ~FLInputModule();

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
		return MODULE_TYPE::INPUT;
	}

};

} /* namespace flaarlib */

#endif /* MODULES_FLINPUTMODULE_H_ */

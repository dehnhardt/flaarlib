/*
 * ThroughModule.h
 *
 *  Created on: 29.01.2016
 *      Author: dehnhardt
 */

#ifndef MODULES_THROUGHMODULE_H_
#define MODULES_THROUGHMODULE_H_

#include "../FLModule.h"
#include <string>

namespace flaarlib {

class FLAARLIB_API ThroughModule: public FLModule {

public:
	ThroughModule(std::string moduleName, int numberOfInputChannels,
			int numberOfOutputChannels);
	virtual ~ThroughModule();

	/**
	 * method for processing the data
	 */
	virtual int internal_process(jack_nframes_t nframes, void *arg );

	/**
	 * method to overwrite when module has specific need when connecting
	 */
	virtual bool internal_connectOutput( FLModule * next);

};

} /* namespace flaarlib */

#endif /* MODULES_INPUTMODULE_H_ */

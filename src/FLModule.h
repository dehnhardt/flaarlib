/*
 * FLModul.h
 *
 *  Created on: 31.10.2015
 *      Author: dehnhardt
 */

#ifndef FLMODULE_H_
#define FLMODULE_H_

#include "Flaarlib.h"
#include "FLPort.h"

#include <jack/jack.h>
#include <map>
#include <string>
#include <boost/uuid/uuid.hpp>

namespace flaarlib {

/**
 * base class of all modules in the library
 * This class can have zero to n input channels
 * When there are zero input channels, this module is an external input (file, jack...)
 * This class can be assigned one to n input ports with exactly [input channels] channels
 * This class can have zero to n output channels
 * When there are zero output channels, this module is an external output (file, jack...)
 * This class can be assigned one to n output ports with exactly [output channels] channels
 * The input ports are mixed up channel be channel without further modification
 * The output ports are split channel by channel without further modification
 *
 * Inputs             Processing         Outputs
 * _____               ________             ______
 *      |1---o-------1|         |1--o-----1|
 * Port1|    |        |         |   |      |Port 1
 * _____|2------o     |         |   |  o--2|______
 * _____     |  |     |         |   |  |    ______
 *      |1---o  |     |         |   o--|--1|
 * Port2|       |     |         |      |   |Port 2
 * _____|2------o----2|_________|2-----o--2|______
 *
 *
 * Inputs              Processing          Outputs
 * _____               _________            ______
 *      |1--o--------1|         |1--o-----1|
 * Port1|2--|--o      |         |   |      |Port 1
 * _____|3--|--|--o   |         |   |  o--2|______
 * _____    |  o--|--2|         |   |  |    ______
 *      |1--|  |  |   |         |   o-----1|
 * Port2|2-----o  |   |         |      |   |Port 2
 * _____|3--------o--3|_________|2-----o--2|______
 *
 *
 */
class FLAARLIB_API FLModule {

public:
	/**
	 * default contructor
	 * @param moduleName type name of the module
	 */

	FLModule(std::string moduleName);
	/**
	 * default destrucur
	 */
	virtual ~FLModule();

	/**
	 * connects this modules output to an input of another module
	 */
	int connectOutput(FLModule * next);

	/**
	 * callback method when another module connects its output
	 * to this modules input
	 */
	int inputConnected(FLModule * previous);

	/**
	 * wrapper method for processing the data
	 */
	int process(jack_nframes_t nframes, void *arg);

	/**
	 * queries the name of this module
	 * @return the name of this module
	 */
	std::string getModuleName() {
		return (this->m_moduleName);
	}

	/**
	 * Queries the number of input channels of this module
	 * @return number of input channels for this module
	 */
	int getNumberOfInputChannels() const {
		return (m_numberOfInputChannels);
	}

	/**
	 * queries how many input ports are connected to this module
	 * @return number of connected input ports
	 */
	int getNumberOfInputPorts() const {
		return (m_numberOfInputPorts);
	}

	/**
	 * queries the number of output channels of this module
	 * @return number of output channels
	 */
	int getNumberOfOutputChannels() const {
		return (m_numberOfOutputChannels);
	}

	/**
	 * queries how many output ports are connected to this module
	 * @return the number of output ports connected to this module
	 */
	int getNumberOfOutputPorts() const {
		return (m_numberOfOutputPorts);
	}

protected:
	/**
	 * method for processing the data
	 */
	virtual int internal_process(jack_nframes_t nframes, void *arg) = 0;

	/**
	 * method to overwrite when module has specific need when connecting
	 */
	virtual bool internal_connectOutput(FLModule * next) = 0;

	/**
	 * the number of input channels of this module and all ports
	 */
	int m_numberOfInputChannels = -1;

	/**
	 * the number of output channels of this module and all ports
	 */
	int m_numberOfOutputChannels = -1;

	/**
	 * number of current input ports
	 */
	int m_numberOfInputPorts = 0;

	/**
	 * number of current output ports
	 */
	int m_numberOfOutputPorts = 0;

private:

	/**
	 * creates an input-port when another module connects
	 */
	FLPort* craeteInputPort(std::string connectedModuleName);

	/**
	 * creates an output port when connecting to another module
	 */
	FLPort* createOutputPort(std::string connectedModuleName);

	/**
	 * creates the mapping from all ports from this module
	 * to the next module.
	 */
	void createMapping();

	/**
	 * the name of this module
	 */
	std::string m_moduleName;

	/**
	 * a uuid for this module
	 */
	boost::uuids::uuid m_moduleUUID;

	/**
	 * all inputPorts
	 */
	std::map<std::string, FLPort*> m_inputPorts;

	/**
	 * all outpuPorts
	 */
	std::map<std::string, FLPort*> m_outputPorts;

	/**
	 * number of already processed input ports
	 */
	int m_processedInputs;

};

} /* namespace flaarlib */

#endif /* FLMODULE_H_ */

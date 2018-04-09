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
#include "FLModuleDefs.h"

#include <jack/jack.h>
#include <map>
#include <string>
#include <boost/uuid/uuid.hpp>

namespace flaarlib
{

struct MODULE_INFO;


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



class FLAARLIB_API FLModule
{

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
	 * connects this modules first output port to the first input port
	 * of another module
	 * @param next the module connected to
	 */
	int connectOutput(FLModule *next);

	/**
	 * connects this modules output to the firt input port of another module
	 * @param outputPortNo the port number wich is connected to another module
	 * @param next the module connected to
	 */
	int connectOutput(int outputPortNo, FLModule *next);

	/**
	 * connects this modules output to an input of another module
	 * @param outputPortNo the port number wich is connected to another module
	 * @param next the module connected to
	 */
	int connectOutput(int outputPortNo, FLModule *next, int inputPortNo );

	/**
	 * callback method when another module connects its output
	 * to this modules first input port
	 * @param previous tho module, this modules input port is connected to
	 */
	int inputConnected(FLModule *previous);

	/**
	 * callback method when another module connects its output
	 * to this modules input
	 * @param previous tho module, this modules input port is connected to
	 * @param inputPortNo the number of this modules input port which is connected
	 */
	int inputConnected(int inputPortNo, FLModule *previous);

	/**
	 * wrapper method for processing the data
	 */
	int process(jack_nframes_t nframes, void *arg);


public: //getter

	/**
	 * queries the name of this module
	 * @return the name of this module
	 */
	std::string getModuleName()
	{
		return (this->m_moduleName);
	}

	/**
	 * queries the uuid of this module
	 * @return the uuid of this module as std::string
	 */
	std::string getModuleUuid()
	{
		return (this->m_moduleUuid);
	}

	/**
	 * Queries the number of input channels of this module
	 * @return number of input channels for this module
	 */
	int getNumberOfInputChannels() const
	{
		return (m_numberOfInputChannels);
	}

	/**
	 * queries how many input ports are connected to this module
	 * @return number of connected input ports
	 */
	int numberOfInputPorts() const
	{
		return (m_inputPorts.size());
	}

	/**
	 * queries the number of output channels of this module
	 * @return number of output channels
	 */
	int getNumberOfOutputChannels() const
	{
		return (m_numberOfOutputChannels);
	}

	/**
	 * queries how many output ports are connected to this module
	 * @return the number of output ports connected to this module
	 */
	int getNumberOfOutputPorts() const
	{
		return (m_numberOfOutputPorts);
	}

	std::vector<std::map<std::string, FLPort *>> getOutputPorts()
	{
		return (m_outputPorts);
	}

	MODULE_INFO *moduleInfo();

public: //setter

	void setNumberOfInputPorts(int numberOfInputPorts);

protected:
	/**
	 * method for processing the data
	 */
	virtual int internal_process(__attribute__((unused))  jack_nframes_t nframes,
								 __attribute__((unused)) void *arg)
	{
		return (0);
	}


	/**
	 * method to overwrite when module has specific need when connecting
	 */
	virtual bool internal_connectOutput(__attribute__((unused))  FLModule *next)
	{
		return (true);
	}
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

private: // Methods

	/**
	 * creates an output port when connecting to another module
	 */
	FLPort *createOutputPort(int outputModuleNo, FLModule *connectedModule);

	/**
	 * creates an output port when connecting to another module
	 */
	FLPort *createOutputPort(FLModule *connectedModule);

	/**
	 * creates the mapping from all ports from this module
	 * to the next module.
	 */
	void createMapping();

protected: // pure virtual methods to fill the info struct
	virtual MODULE_TYPE getModuleType() = 0;
	virtual DATA_TYPE getModuleDataType() = 0;
	virtual std::string getModuleFuctionalName() = 0;
	virtual std::string getModuleDescription() = 0;


private: //Members

	/**
	 * a uuid for this module
	 */
	std::string m_moduleUuid;

	/**
	 * the name of this module
	 */
	std::string m_moduleName;

	/**
	 * all inputPorts
	 */
	std::vector<std::map<std::string, FLPort *>> m_inputPorts;

	/**
	 * all outpuPorts
	 */
	std::vector<std::map<std::string, FLPort *>> m_outputPorts;

	/**
	 * number of already processed input ports
	 */
	int m_processedInputs;

	/**
	 * @brief m_ModuleInfo
	 * srtuct with module information
	 */
	MODULE_INFO *m_pModuleInfo = 0;
};


} /* namespace flaarlib */

#endif /* FLMODULE_H_ */

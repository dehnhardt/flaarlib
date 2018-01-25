/*
 * FLPort.h
 *
 *  Created on: 31.10.2015
 *      Author: dehnhardt
 */

#ifndef FLPORT_H_
#define FLPORT_H_

#include "Flaarlib.h"

namespace flaarlib {

class FLModule;

class FLAARLIB_API FLPort {
public:

	/**
	 * default constructor
	 */
	FLPort( FLModule *flModule, unsigned int numberOfChannels = 1);

	/**
	 * default destructor
	 */
	virtual ~FLPort();

	/**
	 * get the number of channels for this port
	 * @return number of channels for this port
	 */
	int getNumberOfChannels() const {
		return (m_numberOfChannels);
	}

	/**
	 * set the number of channels for this port
	 * @param numberOfChannels
	 */
	void setNumberOfChannels(int numberOfChannels = 1) {
		m_numberOfChannels = numberOfChannels;
	}

	FLModule * getModule() {
		return (m_parent);
	}

private:

	/**
	 * Number of channels for this port.
	 * Usually one (mono) or two (stereo)
	 */
	FLModule * m_parent = 0;

	int m_numberOfChannels = 1;

};

} /* namespace flaarlib */

#endif /* FLPORT_H_ */

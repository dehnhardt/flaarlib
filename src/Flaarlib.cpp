/*
 * Flaarlib.cpp
 *
 *  Created on: 04.11.2015
 *      Author: dehnhardt
 */

#include "logging/FLLog.h"

#include "Flaarlib.h"
#include "FLModule.h"

#include <vector>

namespace flaarlib {

FLAARLIB_API FLLogger * FLLog::fllogger_ = 0;

Flaarlib::Flaarlib() {
	FLLog::info("Init FLLib");
}

Flaarlib::~Flaarlib() {
	// TODO Auto-generated destructor stub
}

/**
 * Initialize the g3 logging library as a fast async logging facility
 */
void Flaarlib::initializeLogging() {
}

} /* namespace flaarlib */


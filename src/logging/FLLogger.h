/*
 * Logger.h
 *
 *  Created on: 28.11.2015
 *      Author: dehnhardt
 */

#ifndef LOGGING_FLLOGGER_H_
#define LOGGING_FLLOGGER_H_

#include <string>

namespace flaarlib {

class FLLogger {
public:
	FLLogger(){};
	virtual ~FLLogger(){};
    virtual void log (const std::string& message) = 0;
    virtual void info (const std::string& message) = 0;
    virtual void debug (const std::string& message) = 0;
    virtual void error (const std::string& message) = 0;
};

}

#endif /* LOGGING_FLLOGGER_H_ */

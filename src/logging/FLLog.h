/*
 * FLLog.h
 *
 *  Created on: 29.11.2015
 *      Author: dehnhardt
 */

#ifndef LOGGING_FLLOG_H_
#define LOGGING_FLLOG_H_

#include <stdarg.h>
#include "../Flaarlib.h"
#include "FLLogger.h"

#define MAX_FORMATTED_STRING 1024


namespace flaarlib {


class FLAARLIB_API FLLog {
private:
	static FLLogger* fllogger_;

public:

	static void registerLogger(FLLogger * logger) {
		fllogger_ = logger;
	}

	static void log(const std::string& message, ...) {
		if (fllogger_ != 0){
			va_list argptr;
			va_start(argptr, message);
			fllogger_->log(format_string(message, argptr));
			va_end(argptr);
		}
	}
	static void info(const std::string& message, ...) {
		if (fllogger_ != 0){
			va_list argptr;
			va_start(argptr, message);
			fllogger_->info(format_string(message, argptr));
			va_end(argptr);
		}
	}
	static void debug(const std::string& message, ...) {
		if (fllogger_ != 0){
			va_list argptr;
			va_start(argptr, message);
			fllogger_->debug(format_string(message, argptr));
			va_end(argptr);
		}
	}
	static void error(const std::string& message, ...) {
		if (fllogger_ != 0){
			va_list argptr;
			va_start(argptr, message);
			fllogger_->error(format_string(message, argptr));
			va_end(argptr);
		}
	}
private:
	static std::string format_string(std::string fmt, va_list argptr){
		char buf[MAX_FORMATTED_STRING];
 		vsnprintf( buf, MAX_FORMATTED_STRING, fmt.c_str(), argptr );
		return(buf);
	}
	static std::string format_string(__attribute__((unused)) va_list argptr ){
		char buf[MAX_FORMATTED_STRING];
		return(buf);
	}
};


} /* namespace flaarlib */
#endif /* LOGGING_FLLOG_H_ */

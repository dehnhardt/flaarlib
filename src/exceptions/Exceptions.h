#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <vector>

using namespace std;

typedef enum {
	NO_OUTPUT_ALLOWED_IN_SOURCE_MODULE,
	NO_INPUT_ALLOWED_IN_TARGET_MODULE,
	NO_READABLE_PORT,
	NO_WRITABLE_PORT,
	LESS_INPUT_CHANNELS,
	MORE_INPUT_CHANNELS,
	SIGNAL_LOOP,
	NAME_NOT_UNIQUE
} ConfigurationExceptionType;

class FLAARLIB_API ConfigurationExecption : public exception {

public:

	static ConfigurationExceptionType EXCEPTION_TYPE;

	ConfigurationExecption( ConfigurationExceptionType configExceptionType ) throw(): m_exceptionNr( configExceptionType) {
		addMessages();
	}

	ConfigurationExecption( ConfigurationExceptionType configExceptionType, string parameters... ) throw(): m_exceptionNr( configExceptionType) {
		string s = parameters;
		addMessages();
	}

	~ConfigurationExecption() throw() {

	}

	void addMessages() {
		exceptionNames[ConfigurationExceptionType::NO_OUTPUT_ALLOWED_IN_SOURCE_MODULE] = "no output ports allowed in source module";
		exceptionNames[ConfigurationExceptionType::NO_INPUT_ALLOWED_IN_TARGET_MODULE] = "no input ports allowed in target module";
		exceptionNames[ConfigurationExceptionType::NO_READABLE_PORT] = "readable port expected";
		exceptionNames[ConfigurationExceptionType::NO_WRITABLE_PORT] = "writable port expected";
		exceptionNames[ConfigurationExceptionType::LESS_INPUT_CHANNELS] = "less input channels in target module than outputs channels in source module";
		exceptionNames[ConfigurationExceptionType::MORE_INPUT_CHANNELS] = "more input channels in target module than outputs channels in source module";
		exceptionNames[ConfigurationExceptionType::NAME_NOT_UNIQUE] = "The name of the module is not unique";
		exceptionNames[ConfigurationExceptionType::SIGNAL_LOOP] = "loop detected in signal chain";
	}

	const string getMessage() {
		string text( "Configuration Exception: ");
		text += exceptionNames[m_exceptionNr];
		return(text);
	}

private:
	ConfigurationExceptionType m_exceptionNr;
	map<ConfigurationExceptionType,string> exceptionNames;

	virtual const char* what() throw() {
		return (getMessage().c_str());
	}

};

#endif // EXCEPTIONS_H

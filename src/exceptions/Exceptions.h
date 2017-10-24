#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <vector>

using namespace std;

typedef enum{
	NO_OUTPUT_ALLOWED_IN_SOURCE_MODULE,
	NO_INPUT_ALLOWED_IN_TARGET_MODULE,
	NO_READABLE_PORT,
	NO_WRITABLE_PORT,
	SIGNAL_LOOP
}  ConfigurationExceptionType;

class FLAARLIB_API ConfigurationExecption : public exception{

public:

	static ConfigurationExceptionType EXCEPTION_TYPE;

	ConfigurationExecption( ConfigurationExceptionType configExceptionType ) throw(): m_exceptionNr( configExceptionType){

        exceptionNames[ConfigurationExceptionType::NO_OUTPUT_ALLOWED_IN_SOURCE_MODULE] = "no output ports allowd in source module configured";
        exceptionNames[ConfigurationExceptionType::NO_OUTPUT_ALLOWED_IN_SOURCE_MODULE] = "no input ports allowd in target module configured";
        exceptionNames[ConfigurationExceptionType::NO_READABLE_PORT] = "readable port expected";
        exceptionNames[ConfigurationExceptionType::NO_WRITABLE_PORT] = "writable port expected";
        exceptionNames[ConfigurationExceptionType::SIGNAL_LOOP] = "loop detected in signal chain";
    }

    ~ConfigurationExecption() throw(){

    }

private:
    ConfigurationExceptionType m_exceptionNr;
    map<ConfigurationExceptionType,string> exceptionNames;

    virtual const char* what() throw(){
        string text( "The following exception occured: ");
        text += exceptionNames[m_exceptionNr];
        return text.c_str();
    }
};

#endif // EXCEPTIONS_H

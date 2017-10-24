/*
 * Flaarlib.h
 *
 *  Created on: 04.11.2015
 *      Author: dehnhardt
 */

// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
  #define FLAARLIB_HELPER_DLL_IMPORT __declspec(dllimport)
  #define FLAARLIB_HELPER_DLL_EXPORT __declspec(dllexport)
  #define FLAARLIB_HELPER_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define FLAARLIB_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define FLAARLIB_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
    #define FLAARLIB_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define FLAARLIB_HELPER_DLL_IMPORT
    #define FLAARLIB_HELPER_DLL_EXPORT
    #define FLAARLIB_HELPER_DLL_LOCAL
  #endif
#endif

// Now we use the generic helper definitions above to define FLAARLIB_API and FLAARLIB_LOCAL.
// FLAARLIB_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// FLAARLIB_LOCAL is used for non-api symbols.

#ifdef FLAARLIB_DLL // defined if FOX is compiled as a DLL
  #ifdef FLAARLIB_DLL_EXPORTS // defined if we are building the FLAARLIB DLL (instead of using it)
    #define FLAARLIB_API FLAARLIB_HELPER_DLL_EXPORT
  #else
    #define FLAARLIB_API FLAARLIB_HELPER_DLL_IMPORT
  #endif // FLAARLIB_DLL_EXPORTS
  #define FLAARLIB_LOCAL FLAARLIB_HELPER_DLL_LOCAL
#else // FLAARLIB_DLL is not defined: this means FLAARLIB is a static lib.
  #define FLAARLIB_API
  #define FLAARLIB_LOCAL
#endif // FLAARLIB_DLL

#ifndef FLAARLIB_H_
#define FLAARLIB_H_


namespace flaarlib {

class FLAARLIB_API Flaarlib {
public:
	Flaarlib();
	virtual ~Flaarlib();

private:
	void initializeLogging();
};

bool ininialize();

} /* namespace flaarlib */




#endif /* FLAARLIB_H_ */

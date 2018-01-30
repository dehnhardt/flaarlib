/*
 * LoopDetector.h
 *
 *  Created on: 19.11.2017
 *      Author: dehnhardt
 */

#ifndef HELPER_LOOPDETECTOR_H_
#define HELPER_LOOPDETECTOR_H_

#include "UniqueVector.hpp"
#include "../FLModule.h"

#include <string>

namespace flaarlib
{

using namespace std;

class LoopDetector
{
public:
	LoopDetector(FLModule *m, UniqueVector<string> v);
	virtual ~LoopDetector();

private:
	FLModule *m_pModule;
	UniqueVector<string> m_Unique;

	void loop();
	string constructPath();

};

} /* namespace flaarlib */

#endif /* HELPER_LOOPDETECTOR_H_ */

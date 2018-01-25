# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

TARGET = flaarlib
CONFIG += c++14

TEMPLATE = lib

HEADERS = \
   src/exceptions/Exceptions.h \
   src/helper/LoopDetector.h \
   src/helper/UniqueVector.hpp \
   src/logging/FLLog.h \
   src/logging/FLLogger.h \
   src/modules/InputModule.h \
   src/modules/OutputModule.h \
   src/modules/ThroughModule.h \
   src/osc/oscpkt.hh \
   src/osc/udp.hh \
   src/Flaarlib.h \
   src/FLModule.h \
   src/FLPort.h

SOURCES = \
   src/helper/LoopDetector.cpp \
   src/helper/LoopDetector_test.cpp \
   src/modules/InputModule.cpp \
   src/modules/OutputModule.cpp \
   src/modules/ThroughModule.cpp \
   src/Flaarlib.cpp \
   src/FLModule.cpp \
   src/FLPort.cpp \
   tests/modules/InputModule_test.cpp \
   tests/Flaarlib_test.cpp \
   tests/FLModul_test.cpp \
   tests/FLPort_test.cpp

INCLUDEPATH = \
    $$PWD/src \
    $$PWD/src/exceptions \
    $$PWD/src/helper \
    $$PWD/src/logging \
    $$PWD/src/modules

DISTFILES += \
	.astylerc

#DEFINES = 


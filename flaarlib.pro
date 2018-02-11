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
   src/Flaarlib.h \
   src/FLModule.h \
   src/FLPort.h \
    src/FLRepository.h \
    src/modules/FLInputModule.h \
    src/modules/FLOutputModule.h \
    src/modules/FLAudioFileInputModule.h \
    src/modules/FLAudioFileOutputModule.h \
    src/modules/FLProcessorModule.h \
    src/modules/FLVolumeControl.h \
    src/modules/FLMIDIFileInputModule.h \
    src/FLModuleDefs.h

SOURCES = \
   src/helper/LoopDetector.cpp \
   src/helper/LoopDetector_test.cpp \
   src/Flaarlib.cpp \
   src/FLModule.cpp \
   src/FLPort.cpp \
   tests/modules/InputModule_test.cpp \
   tests/Flaarlib_test.cpp \
   tests/FLModul_test.cpp \
   tests/FLPort_test.cpp \
    src/FLRepository.cpp \
    src/modules/FLMIDIFileInputModule.cpp \
    src/modules/FLAudioFileInputModule.cpp \
    src/modules/FLAudioFileOutputModule.cpp \
    src/modules/FLInputModule.cpp \
    src/modules/FLOutputModule.cpp \
    src/modules/FLProcessorModule.cpp \
    src/modules/FLVolumeControl.cpp

INCLUDEPATH = \
    $$PWD/src \
    $$PWD/src/exceptions \
    $$PWD/src/helper \
    $$PWD/src/logging \
    $$PWD/src/modules

DISTFILES += \
        .astylerc

unix {
 target.path = /usr/lib
 INSTALLS += target
}

#DEFINES =


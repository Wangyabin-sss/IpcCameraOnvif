TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ./samples/remoteDiscovery/remoteDiscovery.cpp \
        ./samples/ptzBinding/ptzBinding.cpp \
        ./samples/mediaBinding/mediaBinding.cpp \
        ./samples/deviceBinding/deviceBinding.cpp

HEADERS += \
           ./samples/common/common.h

INCLUDEPATH += \
                ./samples/common  \
                ./res  \
                ./include/custom \
                ./include \
                ./include/plugin \
                ./include/soapProxy \





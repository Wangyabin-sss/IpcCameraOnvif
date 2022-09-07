TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ./samples/main.c \
        ./src/server_interface.c \
	   	./src/soapC.c \
	   	./src/soapServer.c \
	   	./src/stdsoap2.c \
	   	./src/wsddC.c \
	   	./src/wsddServer.c

HEADERS += ./include/common.h

INCLUDEPATH += ./include 

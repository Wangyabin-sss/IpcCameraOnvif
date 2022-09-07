#!/bin/bash

g++ -o devicebinding -Wall -DWITH_OPENSSL -DWITH_DOM -DWITH_ZLIB \
  -I. -I ../include/plugin -I ../include/custom -I ../include -I ../include/soapProxy -I ../samples/common \
  ../samples/deviceBinding/deviceBinding.cpp \
  ../src/soapC.cpp \
  ../src/wsddClient.cpp \
  ../src/stdsoap2.cpp \
  ../src/dom.cpp \
  ../src/soapProxy/soapAdvancedSecurityServiceBindingProxy.cpp \
  ../src/soapProxy/soapDeviceBindingProxy.cpp \
  ../src/soapProxy/soapDeviceIOBindingProxy.cpp \
  ../src/soapProxy/soapImagingBindingProxy.cpp \
  ../src/soapProxy/soapMediaBindingProxy.cpp \
  ../src/soapProxy/soapPTZBindingProxy.cpp \
  ../src/soapProxy/soapPullPointSubscriptionBindingProxy.cpp \
  ../src/soapProxy/soapRemoteDiscoveryBindingProxy.cpp \
  ../src/plugin/smdevp.c \
  ../src/plugin/mecevp.c \
  ../src/plugin/wsaapi.c \
  ../src/plugin/wsseapi.c \
  ../src/custom/struct_timeval.c \
  ../src/custom/duration.c \
  -lcrypto -lssl -lz



#  ../src/plugin/wsddapi.c \
#  ../src/wsddServer.cpp \

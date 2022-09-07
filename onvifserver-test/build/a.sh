#!/bin/bash

gcc -o ipcamera -Wall -DWITH_OPENSSL -DWITH_DOM -DWITH_ZLIB \
  -I ../include \
  ../samples/main.c \
  ../src/server_interface.c \
  ../src/soapC.c \
  ../src/soapServer.c \
  ../src/stdsoap2.c \
  ../src/wsaapi.c \
  ../src/duration.c \
  ../src/struct_timeval.c \
  -lcrypto -lssl -lz


  #../src/wsddC.c \
  #../src/wsddServer.c \


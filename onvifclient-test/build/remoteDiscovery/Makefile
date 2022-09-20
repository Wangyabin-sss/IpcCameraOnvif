CC = g++
CXX = g++
INCLUDEPATH = -I../../include/plugin \
            -I../../include/custom \
            -I../../include \
            -I../../include/soapProxy \
            -I../../samples/common \
            -I../../samples/mediatest

CFLAGES = -Wall -DWITH_OPENSSL -DWITH_DOM -DWITH_ZLIB
CXXFLAGES = -Wall -DWITH_OPENSSL -DWITH_DOM -DWITH_ZLIB
LINKLIB = -lcrypto -lssl -lz
objs = soapC.o \
       wsddClient.o \
       stdsoap2.o \
       dom.o \
       soapAdvancedSecurityServiceBindingProxy.o \
       soapDeviceBindingProxy.o \
       soapDeviceIOBindingProxy.o \
       soapImagingBindingProxy.o \
       soapMediaBindingProxy.o \
       soapPTZBindingProxy.o \
       soapPullPointSubscriptionBindingProxy.o \
       soapRemoteDiscoveryBindingProxy.o \
       smdevp.o \
       mecevp.o \
       wsaapi.o \
       wsseapi.o \
       struct_timeval.o \
       duration.o

objs1 = $(objs) remoteDiscovery.o
target = remoteDiscovery

$(target):$(objs1)
	$(CXX) $(objs1) -o $@ $(LINKLIB)

clean:
	rm *.o
	rm $(target)


soapC.o:../../src/soapC.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
wsddClient.o:../../src/wsddClient.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
stdsoap2.o:../../src/stdsoap2.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
dom.o:../../src/dom.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
soapAdvancedSecurityServiceBindingProxy.o:../../src/soapProxy/soapAdvancedSecurityServiceBindingProxy.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
soapDeviceBindingProxy.o:../../src/soapProxy/soapDeviceBindingProxy.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
soapDeviceIOBindingProxy.o:../../src/soapProxy/soapDeviceIOBindingProxy.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
soapImagingBindingProxy.o:../../src/soapProxy/soapImagingBindingProxy.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
soapMediaBindingProxy.o:../../src/soapProxy/soapMediaBindingProxy.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
soapPTZBindingProxy.o:../../src/soapProxy/soapPTZBindingProxy.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
soapPullPointSubscriptionBindingProxy.o:../../src/soapProxy/soapPullPointSubscriptionBindingProxy.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
soapRemoteDiscoveryBindingProxy.o:../../src/soapProxy/soapRemoteDiscoveryBindingProxy.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)
smdevp.o:../../src/plugin/smdevp.c
	$(CC) -c $< -o $@ $(CFLAGES) $(INCLUDEPATH)
mecevp.o:../../src/plugin/mecevp.c
	$(CC) -c $< -o $@ $(CFLAGES) $(INCLUDEPATH)
wsaapi.o:../../src/plugin/wsaapi.c
	$(CC) -c $< -o $@ $(CFLAGES) $(INCLUDEPATH)
wsseapi.o:../../src/plugin/wsseapi.c
	$(CC) -c $< -o $@ $(CFLAGES) $(INCLUDEPATH)
struct_timeval.o:../../src/custom/struct_timeval.c
	$(CC) -c $< -o $@ $(CFLAGES) $(INCLUDEPATH)
duration.o:../../src/custom/duration.c
	$(CC) -c $< -o $@ $(CFLAGES) $(INCLUDEPATH)


remoteDiscovery.o:../../samples/remoteDiscovery/remoteDiscovery.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGES) $(INCLUDEPATH)







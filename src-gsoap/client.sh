#!/bin/bash


case $1 in
	"h")
		wsdl2h -O4 -P -s -x -t public/typemap.dat -o client/onvif.h \
		http://www.onvif.org/onvif/ver10/device/wsdl/devicemgmt.wsdl \
  http://www.onvif.org/onvif/ver10/events/wsdl/event.wsdl \
  http://www.onvif.org/onvif/ver10/deviceio.wsdl \
  http://www.onvif.org/onvif/ver20/imaging/wsdl/imaging.wsdl \
  http://www.onvif.org/onvif/ver10/media/wsdl/media.wsdl \
  http://www.onvif.org/onvif/ver20/ptz/wsdl/ptz.wsdl \
  http://www.onvif.org/onvif/ver10/network/wsdl/remotediscovery.wsdl \
  http://www.onvif.org/ver10/advancedsecurity/wsdl/advancedsecurity.wsdl

		echo "修改onvif.h:"
		echo "#import \"wsdd5.h\"   // wsdd10 = <http://schemas.xmlsoap.org/ws/2005/04/discovery>"
  		echo "#import \"xop.h\" // xop = <http://www.w3.org/2004/08/xop/include>"
  		echo "#import \"wsa5.h\"    // wsa5 = <http://www.w3.org/2005/08/addressing>"
  		echo "#import \"wsse.h\""

		;;
	"cpp")
		soapcpp2 -2 -C -d client -I ../gsoap-2.8/gsoap/import -I ../gsoap-2.8/gsoap -j -x client/onvif.h
		soapcpp2 -a -x -d client -L -pwsdd -I ../gsoap-2.8/gsoap/import ../gsoap-2.8/gsoap/import/wsdd5.h
		;;
esac


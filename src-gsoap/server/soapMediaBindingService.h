/* soapMediaBindingService.h
   Generated by gSOAP 2.8.122 for server/onvif.h

gSOAP XML Web services tools
Copyright (C) 2000-2021, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#ifndef soapMediaBindingService_H
#define soapMediaBindingService_H
#include "soapH.h"

    class SOAP_CMAC MediaBindingService {
      public:
        /// Context to manage service IO and data
        struct soap *soap;
        /// flag indicating that this context is owned by this service and should be deleted by the destructor
        bool soap_own;
        /// Variables globally declared in server/onvif.h, if any
        /// Construct a service with new managing context
        MediaBindingService();
        /// Copy constructor
        MediaBindingService(const MediaBindingService&);
        /// Construct service given a shared managing context
        MediaBindingService(struct soap*);
        /// Constructor taking input+output mode flags for the new managing context
        MediaBindingService(soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        MediaBindingService(soap_mode imode, soap_mode omode);
        /// Destructor deletes deserialized data and its managing context, when the context was allocated by the constructor
        virtual ~MediaBindingService();
        /// Delete all deserialized data (with soap_destroy() and soap_end())
        virtual void destroy();
        /// Delete all deserialized data and reset to defaults
        virtual void reset();
        /// Initializer used by constructors
        virtual void MediaBindingService_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual MediaBindingService *copy() SOAP_PURE_VIRTUAL_COPY;
        /// Copy assignment
        MediaBindingService& operator=(const MediaBindingService&);
        /// Close connection (normally automatic)
        virtual int soap_close_socket();
        /// Force close connection (can kill a thread blocked on IO)
        virtual int soap_force_close_socket();
        /// Return sender-related fault to sender
        virtual int soap_senderfault(const char *string, const char *detailXML);
        /// Return sender-related fault with SOAP 1.2 subcode to sender
        virtual int soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML);
        /// Return receiver-related fault to sender
        virtual int soap_receiverfault(const char *string, const char *detailXML);
        /// Return receiver-related fault with SOAP 1.2 subcode to sender
        virtual int soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML);
        /// Print fault
        virtual void soap_print_fault(FILE*);
    #ifndef WITH_LEAN
    #ifndef WITH_COMPAT
        /// Print fault to stream
        virtual void soap_stream_fault(std::ostream&);
    #endif
        /// Write fault to buffer
        virtual char *soap_sprint_fault(char *buf, size_t len);
    #endif
        /// Disables and removes SOAP Header from message by setting soap->header = NULL
        virtual void soap_noheader();
        /// Add SOAP Header to message
        virtual void soap_header(char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance, struct wsdd__AppSequenceType *wsdd__AppSequence, struct _wsse__Security *wsse__Security);
        /// Get SOAP Header structure (i.e. soap->header, which is NULL when absent)
        virtual ::SOAP_ENV__Header *soap_header();
    #ifndef WITH_NOIO
        /// Run simple single-thread (iterative, non-SSL) service on port until a connection error occurs (returns SOAP_OK or error code), use this->bind_flag = SO_REUSEADDR to rebind for immediate rerun
        virtual int run(int port, int backlog = 1);
    #if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
        /// Run simple single-thread SSL service on port until a connection error occurs (returns SOAP_OK or error code), use this->bind_flag = SO_REUSEADDR to rebind for immediate rerun
        virtual int ssl_run(int port, int backlog = 1);
    #endif
        /// Bind service to port (returns master socket or SOAP_INVALID_SOCKET upon error)
        virtual SOAP_SOCKET bind(const char *host, int port, int backlog);
        /// Accept next request (returns socket or SOAP_INVALID_SOCKET upon error)
        virtual SOAP_SOCKET accept();
    #if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
        /// When SSL is used, after accept() should perform and accept SSL handshake
        virtual int ssl_accept();
    #endif
    #endif
        /// After accept() serve the pending request (returns SOAP_OK or error code)
        virtual int serve();
        /// Used by serve() to dispatch a pending request (returns SOAP_OK or error code)
        virtual int dispatch();
        virtual int dispatch(struct soap *soap);
        //
        // Service operations are listed below: you should define these
        // Note: compile with -DWITH_PURE_VIRTUAL to declare pure virtual methods
        //
        /// Web service operation 'GetServiceCapabilities' implementation, should return SOAP_OK or error code
        virtual int GetServiceCapabilities(_trt__GetServiceCapabilities *trt__GetServiceCapabilities, _trt__GetServiceCapabilitiesResponse &trt__GetServiceCapabilitiesResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetVideoSources' implementation, should return SOAP_OK or error code
        virtual int GetVideoSources(_trt__GetVideoSources *trt__GetVideoSources, _trt__GetVideoSourcesResponse &trt__GetVideoSourcesResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioSources' implementation, should return SOAP_OK or error code
        virtual int GetAudioSources(_trt__GetAudioSources *trt__GetAudioSources, _trt__GetAudioSourcesResponse &trt__GetAudioSourcesResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioOutputs' implementation, should return SOAP_OK or error code
        virtual int GetAudioOutputs(_trt__GetAudioOutputs *trt__GetAudioOutputs, _trt__GetAudioOutputsResponse &trt__GetAudioOutputsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'CreateProfile' implementation, should return SOAP_OK or error code
        virtual int CreateProfile(_trt__CreateProfile *trt__CreateProfile, _trt__CreateProfileResponse &trt__CreateProfileResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetProfile' implementation, should return SOAP_OK or error code
        virtual int GetProfile(_trt__GetProfile *trt__GetProfile, _trt__GetProfileResponse &trt__GetProfileResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetProfiles' implementation, should return SOAP_OK or error code
        virtual int GetProfiles(_trt__GetProfiles *trt__GetProfiles, _trt__GetProfilesResponse &trt__GetProfilesResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'AddVideoEncoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int AddVideoEncoderConfiguration(_trt__AddVideoEncoderConfiguration *trt__AddVideoEncoderConfiguration, _trt__AddVideoEncoderConfigurationResponse &trt__AddVideoEncoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'AddVideoSourceConfiguration' implementation, should return SOAP_OK or error code
        virtual int AddVideoSourceConfiguration(_trt__AddVideoSourceConfiguration *trt__AddVideoSourceConfiguration, _trt__AddVideoSourceConfigurationResponse &trt__AddVideoSourceConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'AddAudioEncoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int AddAudioEncoderConfiguration(_trt__AddAudioEncoderConfiguration *trt__AddAudioEncoderConfiguration, _trt__AddAudioEncoderConfigurationResponse &trt__AddAudioEncoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'AddAudioSourceConfiguration' implementation, should return SOAP_OK or error code
        virtual int AddAudioSourceConfiguration(_trt__AddAudioSourceConfiguration *trt__AddAudioSourceConfiguration, _trt__AddAudioSourceConfigurationResponse &trt__AddAudioSourceConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'AddPTZConfiguration' implementation, should return SOAP_OK or error code
        virtual int AddPTZConfiguration(_trt__AddPTZConfiguration *trt__AddPTZConfiguration, _trt__AddPTZConfigurationResponse &trt__AddPTZConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'AddVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code
        virtual int AddVideoAnalyticsConfiguration(_trt__AddVideoAnalyticsConfiguration *trt__AddVideoAnalyticsConfiguration, _trt__AddVideoAnalyticsConfigurationResponse &trt__AddVideoAnalyticsConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'AddMetadataConfiguration' implementation, should return SOAP_OK or error code
        virtual int AddMetadataConfiguration(_trt__AddMetadataConfiguration *trt__AddMetadataConfiguration, _trt__AddMetadataConfigurationResponse &trt__AddMetadataConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'AddAudioOutputConfiguration' implementation, should return SOAP_OK or error code
        virtual int AddAudioOutputConfiguration(_trt__AddAudioOutputConfiguration *trt__AddAudioOutputConfiguration, _trt__AddAudioOutputConfigurationResponse &trt__AddAudioOutputConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'AddAudioDecoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int AddAudioDecoderConfiguration(_trt__AddAudioDecoderConfiguration *trt__AddAudioDecoderConfiguration, _trt__AddAudioDecoderConfigurationResponse &trt__AddAudioDecoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'RemoveVideoEncoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int RemoveVideoEncoderConfiguration(_trt__RemoveVideoEncoderConfiguration *trt__RemoveVideoEncoderConfiguration, _trt__RemoveVideoEncoderConfigurationResponse &trt__RemoveVideoEncoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'RemoveVideoSourceConfiguration' implementation, should return SOAP_OK or error code
        virtual int RemoveVideoSourceConfiguration(_trt__RemoveVideoSourceConfiguration *trt__RemoveVideoSourceConfiguration, _trt__RemoveVideoSourceConfigurationResponse &trt__RemoveVideoSourceConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'RemoveAudioEncoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int RemoveAudioEncoderConfiguration(_trt__RemoveAudioEncoderConfiguration *trt__RemoveAudioEncoderConfiguration, _trt__RemoveAudioEncoderConfigurationResponse &trt__RemoveAudioEncoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'RemoveAudioSourceConfiguration' implementation, should return SOAP_OK or error code
        virtual int RemoveAudioSourceConfiguration(_trt__RemoveAudioSourceConfiguration *trt__RemoveAudioSourceConfiguration, _trt__RemoveAudioSourceConfigurationResponse &trt__RemoveAudioSourceConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'RemovePTZConfiguration' implementation, should return SOAP_OK or error code
        virtual int RemovePTZConfiguration(_trt__RemovePTZConfiguration *trt__RemovePTZConfiguration, _trt__RemovePTZConfigurationResponse &trt__RemovePTZConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'RemoveVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code
        virtual int RemoveVideoAnalyticsConfiguration(_trt__RemoveVideoAnalyticsConfiguration *trt__RemoveVideoAnalyticsConfiguration, _trt__RemoveVideoAnalyticsConfigurationResponse &trt__RemoveVideoAnalyticsConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'RemoveMetadataConfiguration' implementation, should return SOAP_OK or error code
        virtual int RemoveMetadataConfiguration(_trt__RemoveMetadataConfiguration *trt__RemoveMetadataConfiguration, _trt__RemoveMetadataConfigurationResponse &trt__RemoveMetadataConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'RemoveAudioOutputConfiguration' implementation, should return SOAP_OK or error code
        virtual int RemoveAudioOutputConfiguration(_trt__RemoveAudioOutputConfiguration *trt__RemoveAudioOutputConfiguration, _trt__RemoveAudioOutputConfigurationResponse &trt__RemoveAudioOutputConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'RemoveAudioDecoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int RemoveAudioDecoderConfiguration(_trt__RemoveAudioDecoderConfiguration *trt__RemoveAudioDecoderConfiguration, _trt__RemoveAudioDecoderConfigurationResponse &trt__RemoveAudioDecoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'DeleteProfile' implementation, should return SOAP_OK or error code
        virtual int DeleteProfile(_trt__DeleteProfile *trt__DeleteProfile, _trt__DeleteProfileResponse &trt__DeleteProfileResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetVideoSourceConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetVideoSourceConfigurations(_trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, _trt__GetVideoSourceConfigurationsResponse &trt__GetVideoSourceConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetVideoEncoderConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetVideoEncoderConfigurations(_trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, _trt__GetVideoEncoderConfigurationsResponse &trt__GetVideoEncoderConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioSourceConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetAudioSourceConfigurations(_trt__GetAudioSourceConfigurations *trt__GetAudioSourceConfigurations, _trt__GetAudioSourceConfigurationsResponse &trt__GetAudioSourceConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioEncoderConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetAudioEncoderConfigurations(_trt__GetAudioEncoderConfigurations *trt__GetAudioEncoderConfigurations, _trt__GetAudioEncoderConfigurationsResponse &trt__GetAudioEncoderConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetVideoAnalyticsConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetVideoAnalyticsConfigurations(_trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, _trt__GetVideoAnalyticsConfigurationsResponse &trt__GetVideoAnalyticsConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetMetadataConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetMetadataConfigurations(_trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, _trt__GetMetadataConfigurationsResponse &trt__GetMetadataConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioOutputConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetAudioOutputConfigurations(_trt__GetAudioOutputConfigurations *trt__GetAudioOutputConfigurations, _trt__GetAudioOutputConfigurationsResponse &trt__GetAudioOutputConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioDecoderConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetAudioDecoderConfigurations(_trt__GetAudioDecoderConfigurations *trt__GetAudioDecoderConfigurations, _trt__GetAudioDecoderConfigurationsResponse &trt__GetAudioDecoderConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetVideoSourceConfiguration' implementation, should return SOAP_OK or error code
        virtual int GetVideoSourceConfiguration(_trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, _trt__GetVideoSourceConfigurationResponse &trt__GetVideoSourceConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetVideoEncoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int GetVideoEncoderConfiguration(_trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, _trt__GetVideoEncoderConfigurationResponse &trt__GetVideoEncoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioSourceConfiguration' implementation, should return SOAP_OK or error code
        virtual int GetAudioSourceConfiguration(_trt__GetAudioSourceConfiguration *trt__GetAudioSourceConfiguration, _trt__GetAudioSourceConfigurationResponse &trt__GetAudioSourceConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioEncoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int GetAudioEncoderConfiguration(_trt__GetAudioEncoderConfiguration *trt__GetAudioEncoderConfiguration, _trt__GetAudioEncoderConfigurationResponse &trt__GetAudioEncoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code
        virtual int GetVideoAnalyticsConfiguration(_trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, _trt__GetVideoAnalyticsConfigurationResponse &trt__GetVideoAnalyticsConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetMetadataConfiguration' implementation, should return SOAP_OK or error code
        virtual int GetMetadataConfiguration(_trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, _trt__GetMetadataConfigurationResponse &trt__GetMetadataConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioOutputConfiguration' implementation, should return SOAP_OK or error code
        virtual int GetAudioOutputConfiguration(_trt__GetAudioOutputConfiguration *trt__GetAudioOutputConfiguration, _trt__GetAudioOutputConfigurationResponse &trt__GetAudioOutputConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioDecoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int GetAudioDecoderConfiguration(_trt__GetAudioDecoderConfiguration *trt__GetAudioDecoderConfiguration, _trt__GetAudioDecoderConfigurationResponse &trt__GetAudioDecoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetCompatibleVideoEncoderConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetCompatibleVideoEncoderConfigurations(_trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, _trt__GetCompatibleVideoEncoderConfigurationsResponse &trt__GetCompatibleVideoEncoderConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetCompatibleVideoSourceConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetCompatibleVideoSourceConfigurations(_trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, _trt__GetCompatibleVideoSourceConfigurationsResponse &trt__GetCompatibleVideoSourceConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetCompatibleAudioEncoderConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetCompatibleAudioEncoderConfigurations(_trt__GetCompatibleAudioEncoderConfigurations *trt__GetCompatibleAudioEncoderConfigurations, _trt__GetCompatibleAudioEncoderConfigurationsResponse &trt__GetCompatibleAudioEncoderConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetCompatibleAudioSourceConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetCompatibleAudioSourceConfigurations(_trt__GetCompatibleAudioSourceConfigurations *trt__GetCompatibleAudioSourceConfigurations, _trt__GetCompatibleAudioSourceConfigurationsResponse &trt__GetCompatibleAudioSourceConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetCompatibleVideoAnalyticsConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetCompatibleVideoAnalyticsConfigurations(_trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, _trt__GetCompatibleVideoAnalyticsConfigurationsResponse &trt__GetCompatibleVideoAnalyticsConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetCompatibleMetadataConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetCompatibleMetadataConfigurations(_trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, _trt__GetCompatibleMetadataConfigurationsResponse &trt__GetCompatibleMetadataConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetCompatibleAudioOutputConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetCompatibleAudioOutputConfigurations(_trt__GetCompatibleAudioOutputConfigurations *trt__GetCompatibleAudioOutputConfigurations, _trt__GetCompatibleAudioOutputConfigurationsResponse &trt__GetCompatibleAudioOutputConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetCompatibleAudioDecoderConfigurations' implementation, should return SOAP_OK or error code
        virtual int GetCompatibleAudioDecoderConfigurations(_trt__GetCompatibleAudioDecoderConfigurations *trt__GetCompatibleAudioDecoderConfigurations, _trt__GetCompatibleAudioDecoderConfigurationsResponse &trt__GetCompatibleAudioDecoderConfigurationsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetVideoSourceConfiguration' implementation, should return SOAP_OK or error code
        virtual int SetVideoSourceConfiguration(_trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, _trt__SetVideoSourceConfigurationResponse &trt__SetVideoSourceConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetVideoEncoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int SetVideoEncoderConfiguration(_trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, _trt__SetVideoEncoderConfigurationResponse &trt__SetVideoEncoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetAudioSourceConfiguration' implementation, should return SOAP_OK or error code
        virtual int SetAudioSourceConfiguration(_trt__SetAudioSourceConfiguration *trt__SetAudioSourceConfiguration, _trt__SetAudioSourceConfigurationResponse &trt__SetAudioSourceConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetAudioEncoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int SetAudioEncoderConfiguration(_trt__SetAudioEncoderConfiguration *trt__SetAudioEncoderConfiguration, _trt__SetAudioEncoderConfigurationResponse &trt__SetAudioEncoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code
        virtual int SetVideoAnalyticsConfiguration(_trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, _trt__SetVideoAnalyticsConfigurationResponse &trt__SetVideoAnalyticsConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetMetadataConfiguration' implementation, should return SOAP_OK or error code
        virtual int SetMetadataConfiguration(_trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, _trt__SetMetadataConfigurationResponse &trt__SetMetadataConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetAudioOutputConfiguration' implementation, should return SOAP_OK or error code
        virtual int SetAudioOutputConfiguration(_trt__SetAudioOutputConfiguration *trt__SetAudioOutputConfiguration, _trt__SetAudioOutputConfigurationResponse &trt__SetAudioOutputConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetAudioDecoderConfiguration' implementation, should return SOAP_OK or error code
        virtual int SetAudioDecoderConfiguration(_trt__SetAudioDecoderConfiguration *trt__SetAudioDecoderConfiguration, _trt__SetAudioDecoderConfigurationResponse &trt__SetAudioDecoderConfigurationResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetVideoSourceConfigurationOptions' implementation, should return SOAP_OK or error code
        virtual int GetVideoSourceConfigurationOptions(_trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, _trt__GetVideoSourceConfigurationOptionsResponse &trt__GetVideoSourceConfigurationOptionsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetVideoEncoderConfigurationOptions' implementation, should return SOAP_OK or error code
        virtual int GetVideoEncoderConfigurationOptions(_trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, _trt__GetVideoEncoderConfigurationOptionsResponse &trt__GetVideoEncoderConfigurationOptionsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioSourceConfigurationOptions' implementation, should return SOAP_OK or error code
        virtual int GetAudioSourceConfigurationOptions(_trt__GetAudioSourceConfigurationOptions *trt__GetAudioSourceConfigurationOptions, _trt__GetAudioSourceConfigurationOptionsResponse &trt__GetAudioSourceConfigurationOptionsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioEncoderConfigurationOptions' implementation, should return SOAP_OK or error code
        virtual int GetAudioEncoderConfigurationOptions(_trt__GetAudioEncoderConfigurationOptions *trt__GetAudioEncoderConfigurationOptions, _trt__GetAudioEncoderConfigurationOptionsResponse &trt__GetAudioEncoderConfigurationOptionsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetMetadataConfigurationOptions' implementation, should return SOAP_OK or error code
        virtual int GetMetadataConfigurationOptions(_trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, _trt__GetMetadataConfigurationOptionsResponse &trt__GetMetadataConfigurationOptionsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioOutputConfigurationOptions' implementation, should return SOAP_OK or error code
        virtual int GetAudioOutputConfigurationOptions(_trt__GetAudioOutputConfigurationOptions *trt__GetAudioOutputConfigurationOptions, _trt__GetAudioOutputConfigurationOptionsResponse &trt__GetAudioOutputConfigurationOptionsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetAudioDecoderConfigurationOptions' implementation, should return SOAP_OK or error code
        virtual int GetAudioDecoderConfigurationOptions(_trt__GetAudioDecoderConfigurationOptions *trt__GetAudioDecoderConfigurationOptions, _trt__GetAudioDecoderConfigurationOptionsResponse &trt__GetAudioDecoderConfigurationOptionsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetGuaranteedNumberOfVideoEncoderInstances' implementation, should return SOAP_OK or error code
        virtual int GetGuaranteedNumberOfVideoEncoderInstances(_trt__GetGuaranteedNumberOfVideoEncoderInstances *trt__GetGuaranteedNumberOfVideoEncoderInstances, _trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse &trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetStreamUri' implementation, should return SOAP_OK or error code
        virtual int GetStreamUri(_trt__GetStreamUri *trt__GetStreamUri, _trt__GetStreamUriResponse &trt__GetStreamUriResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'StartMulticastStreaming' implementation, should return SOAP_OK or error code
        virtual int StartMulticastStreaming(_trt__StartMulticastStreaming *trt__StartMulticastStreaming, _trt__StartMulticastStreamingResponse &trt__StartMulticastStreamingResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'StopMulticastStreaming' implementation, should return SOAP_OK or error code
        virtual int StopMulticastStreaming(_trt__StopMulticastStreaming *trt__StopMulticastStreaming, _trt__StopMulticastStreamingResponse &trt__StopMulticastStreamingResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetSynchronizationPoint' implementation, should return SOAP_OK or error code
        virtual int SetSynchronizationPoint(_trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, _trt__SetSynchronizationPointResponse &trt__SetSynchronizationPointResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetSnapshotUri' implementation, should return SOAP_OK or error code
        virtual int GetSnapshotUri(_trt__GetSnapshotUri *trt__GetSnapshotUri, _trt__GetSnapshotUriResponse &trt__GetSnapshotUriResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetVideoSourceModes' implementation, should return SOAP_OK or error code
        virtual int GetVideoSourceModes(_trt__GetVideoSourceModes *trt__GetVideoSourceModes, _trt__GetVideoSourceModesResponse &trt__GetVideoSourceModesResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetVideoSourceMode' implementation, should return SOAP_OK or error code
        virtual int SetVideoSourceMode(_trt__SetVideoSourceMode *trt__SetVideoSourceMode, _trt__SetVideoSourceModeResponse &trt__SetVideoSourceModeResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetOSDs' implementation, should return SOAP_OK or error code
        virtual int GetOSDs(_trt__GetOSDs *trt__GetOSDs, _trt__GetOSDsResponse &trt__GetOSDsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetOSD' implementation, should return SOAP_OK or error code
        virtual int GetOSD(_trt__GetOSD *trt__GetOSD, _trt__GetOSDResponse &trt__GetOSDResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'GetOSDOptions' implementation, should return SOAP_OK or error code
        virtual int GetOSDOptions(_trt__GetOSDOptions *trt__GetOSDOptions, _trt__GetOSDOptionsResponse &trt__GetOSDOptionsResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'SetOSD' implementation, should return SOAP_OK or error code
        virtual int SetOSD(_trt__SetOSD *trt__SetOSD, _trt__SetOSDResponse &trt__SetOSDResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'CreateOSD' implementation, should return SOAP_OK or error code
        virtual int CreateOSD(_trt__CreateOSD *trt__CreateOSD, _trt__CreateOSDResponse &trt__CreateOSDResponse) SOAP_PURE_VIRTUAL;
        //
        /// Web service operation 'DeleteOSD' implementation, should return SOAP_OK or error code
        virtual int DeleteOSD(_trt__DeleteOSD *trt__DeleteOSD, _trt__DeleteOSDResponse &trt__DeleteOSDResponse) SOAP_PURE_VIRTUAL;
    };
#endif
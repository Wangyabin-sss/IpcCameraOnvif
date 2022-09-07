#include "mediaonvif.h"

OnvifMedia::OnvifMedia(std::string usern,std::string pwd,std::string ip)
{
    username = usern;
    password = pwd;
    hostname = std::string("http://"+ip+"/onvif/Media");

    soap = soap_new();
    mediaBindingProxy.soap_endpoint = hostname.c_str();
}

OnvifMedia::~OnvifMedia(void)
{
    if (soap != nullptr) {
        soap_destroy(soap);
        soap_end(soap);
        soap_free(soap);
    }
}

void OnvifMedia::getProfiles(void)
{
    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(mediaBindingProxy.soap, nullptr, username.c_str(), password.c_str())) {
        std::cerr << "Error: soap_wsse_add_UsernameTokenDigest" << std::endl;
        soap_stream_fault(mediaBindingProxy.soap, std::cerr);
        return;
    }

    _trt__GetProfiles *GetProfiles = soap_new__trt__GetProfiles(soap);
    _trt__GetProfilesResponse *GetProfilesResponse = soap_new__trt__GetProfilesResponse(soap);

    std::cout << "Profile name" << "         " << "Profile token" << std::endl;
    if (SOAP_OK == mediaBindingProxy.GetProfiles(GetProfiles, *GetProfilesResponse))
    {
        for (int i=0;i<GetProfilesResponse->__sizeProfiles;i++) {
            tt__Profile *Profile = GetProfilesResponse->Profiles[i];
            std::cout << Profile->Name << "         " << Profile->token << std::endl;
            profiles.emplace_back(std::pair<std::string, std::string>(Profile->Name, Profile->token));
        }
    } else {
        std::cerr <<"Error: getProfiles" << std::endl;
        soap_stream_fault(mediaBindingProxy.soap, std::cerr);
    }

}


void OnvifMedia::getSnapshotUri(std::string profileToken,std::string &snapshoturi)
{
    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(mediaBindingProxy.soap, nullptr, username.c_str(), password.c_str())) {
        std::cerr << "Error: soap_wsse_add_UsernameTokenDigest" << std::endl;
        soap_stream_fault(mediaBindingProxy.soap, std::cerr);
        return;
    }

    char profile[profileToken.size()];
    strcpy(profile,profileToken.c_str());

    _trt__GetSnapshotUri *GetSnapshotUri = soap_new__trt__GetSnapshotUri(soap);
    GetSnapshotUri->ProfileToken = profile;
    _trt__GetSnapshotUriResponse *GetSnapshotUriResponse = soap_new__trt__GetSnapshotUriResponse(soap);

    if (SOAP_OK == mediaBindingProxy.GetSnapshotUri(GetSnapshotUri, *GetSnapshotUriResponse)) {
        std::cout << "SnapshotUri: " << GetSnapshotUriResponse->MediaUri->Uri << std::endl;
        snapshoturi =std::string(GetSnapshotUriResponse->MediaUri->Uri);
    } else {
        std::cerr <<"Error: getSnapshotUri" << std::endl;
        soap_stream_fault(mediaBindingProxy.soap, std::cerr);
    }

}


void OnvifMedia::getStreamUri(std::string profileToken,std::string &streamuri)
{
    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(mediaBindingProxy.soap, nullptr, username.c_str(), password.c_str())) {
        std::cerr << "Error: soap_wsse_add_UsernameTokenDigest" << std::endl;
        soap_stream_fault(mediaBindingProxy.soap, std::cerr);
        return;
    }

    char profile[profileToken.size()];
    strcpy(profile,profileToken.c_str());

    _trt__GetStreamUri *GetStreamUri = soap_new__trt__GetStreamUri(soap);
    GetStreamUri->ProfileToken = profile;
    _trt__GetStreamUriResponse *GetStreamUriResponse = soap_new__trt__GetStreamUriResponse(soap);

    if (SOAP_OK == mediaBindingProxy.GetStreamUri(GetStreamUri, *GetStreamUriResponse)) {
        std::cout << "StreamUri: " << GetStreamUriResponse->MediaUri->Uri << std::endl;
        streamuri = std::string(GetStreamUriResponse->MediaUri->Uri);
    } else {
        std::cerr <<"Error: getStreamUri" << std::endl;
        soap_stream_fault(mediaBindingProxy.soap, std::cerr);
    }

}


//rtsp://192.168.3.101:554/Streaming/Channels/101?transportmode=unicast&profile=Profile_1
//rtsp://admin:wsn2022-3-9@192.168.3.101:554/Streaming/Channels/101?transportmode=unicast&profile=Profile_1
void OnvifMedia::uriadd_key(std::string &uri)
{
    int in = uri.find("://")+3;
    std::string key(username+":"+password+"@");
    uri.insert(in, key);
}







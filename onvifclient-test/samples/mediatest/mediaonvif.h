#ifndef _MEDIAONVIF_H
#define _MEDIAONVIF_H


#include <iostream>
#include <string>
#include <vector>
#include <stdsoap2.h>
#include "wsseapi.h"
#include "soapMediaBindingProxy.h"

class OnvifMedia
{
public:
    OnvifMedia(std::string usern,std::string pwd,std::string ip);
    ~OnvifMedia(void);

    void getProfiles(void);
    void getSnapshotUri(std::string profileToken,std::string &snapshoturi);
    void getStreamUri(std::string profileToken,std::string &streamuri);
    void uriadd_key(std::string &uri);
    //                 Profile-name   Profile-token
    std::vector<std::pair<std::string, std::string>> profiles;

private:
    std::string username;
    std::string password;
    std::string hostname;
    MediaBindingProxy mediaBindingProxy;
    struct soap* soap;
};



#endif

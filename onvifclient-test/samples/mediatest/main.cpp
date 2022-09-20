#include "mediaonvif.h"

int main()
{
    OnvifMedia omedia("admin","wsn20-3-9","192.168.3.101");
    std::string uri;

    omedia.getProfiles();

    if(!omedia.profiles.empty())
    {
        omedia.getSnapshotUri(omedia.profiles[0].second, uri);
        omedia.getStreamUri(omedia.profiles[0].second, uri);
        omedia.uriadd_key(uri);
    }

    if(uri.empty())
        std::cout<<"NULL"<<std::endl;
    else
        std::cout<<uri<<std::endl;


    while (1) {
        sleep(5);
    }

    return 0;
}

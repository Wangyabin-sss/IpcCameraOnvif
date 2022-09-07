#include "mediaonvif.h"

int main()
{
    OnvifMedia omedia("admin","wsn2022-3-9","192.168.3.101");
    std::string uri;

    omedia.getProfiles();

    omedia.getSnapshotUri(omedia.profiles[0].second, uri);
    omedia.getStreamUri(omedia.profiles[0].second, uri);
    omedia.uriadd_key(uri);

    std::cout<<uri<<std::endl;

    return 0;
}

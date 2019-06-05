
#ifndef _WIFI_STUB_
#define _WIFI_STUB_

#include <string>
using namespace std;

class WiFi {
    int callCount = 0;

    void* returnData = nullptr;

    
    void* mock(){
        ++callCount;
        return returnData;
    }
    public:

    void setReturnValue(void* data){
        returnData = data;
    }

    int getCallCount(){
        return callCount;
    }

    
    void resetCallCount(){
        callCount = 0;
    }
    int scanNetworks(){
        return *static_cast<int*>(mock());
    }
    int encryptionType(int){
        return *static_cast<int*>(mock());
    }
    void begin(char*, char*){
        callCount++;
    }
    char* SSID(int){
        return static_cast<char*>(mock());
    }

};
#endif
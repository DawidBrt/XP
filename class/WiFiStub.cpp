
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
        //use  this to set return value for next called method
        returnData = data;
    }

    int getCallCount(){
        //check how many time class has been called
        return callCount;
    }

    
    void resetCallCount(){
        //reset call count
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
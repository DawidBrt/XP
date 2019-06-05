#ifndef _TEST_THIS
    #include <ESP8266WiFi.h>
#endif

class Connector {
    private:  
        void wifiOpen(int wifiId);
        void homeWifi(int wifiId);
        bool homeWiFi = false;
        char* homeSSID = nullptr;
        char* homePass = nullptr;


    public:
        bool homeWiFiPresent();
        void inspectNetworks();
        Connector(char* homeSSID, char* homePass);

    
};

Connector::Connector(char* homeSSID, char* homePass){
    this -> homeSSID = homeSSID;
    this -> homePass = homePass;
}

void Connector::wifiOpen(int wiFiId){

      if(WiFi.encryptionType(wiFiId) == ENC_TYPE_NONE){
          //action on open
      }
}
void Connector::homeWifi(int id){

    if(WiFi.SSID(id) == this -> homeSSID){
        ///action on home
        this -> homeWiFi = true;
    }
}

bool Connector::homeWiFiPresent(){
    return homeWiFi;
}


void Connector::inspectNetworks(){
    int numberOfNetworks = WiFi.scanNetworks();
    for(int i =0; i<numberOfNetworks; i++){
        wifiOpen(i);
        homeWifi(i);
    }
}

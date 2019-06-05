#include <ESP8266WiFi.h>
#include "FS.h" // do zapisywania plików
#include "class/PrepareResponse.cpp"

const char* homeSsid = "TestWIFIesp";
const char* homePassword = "12345678";
WiFiServer server(80);
bool homeWifiPresent = false;

void setup() {
    Serial.println("odpaliło się");
    Serial.begin(115200);
    delay(10);
    bool result = SPIFFS.begin();

    File log = SPIFFS.open("/log.txt", "r");
    if (!log) {
        Serial.println("Plik nie istnieje, zostanie teraz stworzony");

        // open the file in write mode
        File log = SPIFFS.open("/log.txt", "w");
        if (!log) {
            Serial.println("Nie udało się stworzyć pliku");
        }
    }
    log.close();
}


void loop() {

    File log = SPIFFS.open("/log.txt", "w");
//bool homeWifiPresent = false;

    int numberOfNetworks = WiFi.scanNetworks();
    for(int i =0; i<numberOfNetworks; i++){
        log.print("Network name: ");
        log.println(WiFi.SSID(i));
        log.print("Signal strength: ");
        log.println(WiFi.RSSI(i));
        if(WiFi.encryptionType(i) == ENC_TYPE_NONE){
            log.println("network is not secured with password");
        }
        log.println("-----------------------");
        if(WiFi.SSID(i) == homeSsid){
            homeWifiPresent = true;
            Serial.println("homewifipresent");
        }
    }

    if(homeWifiPresent == true){
        WiFi.begin(homeSsid, homePassword);
        server.begin();
        // Print the IP address
        Serial.println(WiFi.localIP());
        // Check if a client has connected
        WiFiClient client = server.available();

        // Read the first line of the request
        String req = client.readStringUntil('\r');
        Serial.println(req);
        client.flush();

        if (req.indexOf("/logs") != -1){
            client.flush();

            // Prepare the response
            PrepareResponse prepareResponse;
            while(log.available()) {
                prepareResponse.expandLog(log.readStringUntil('n'));
            }
            String s = prepareResponse.createResponse();

            // Send the response to the client
            client.print(s);
            delay(10000);
            Serial.println("Client disonnected");
        } else {
            Serial.println("invalid request");
            client.stop();
        }
        //delay co ile ma czytać te sieci jest do przemyślenia
        delay(7000);
        homeWifiPresent = false;
        log.close();
    }
}

#include <string>

using namespace std;

class PrepareResponse {
    string log;
public:
    void expandLog (string);
    string createResponse ();
};

void PrepareResponse::expandLog(string lineToAdd) {
    log = log + "\r\n" + lineToAdd + "<br>";
}

string PrepareResponse::createResponse() {

    if (log.length() < 1) {
        return "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nNo logs available<br>\r\n</html>\n";
    }

    string response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>";
    response += log;
    response += "\r\n</html>\n";
    return response;
}
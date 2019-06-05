#define CATCH_CONFIG_MAIN

#include <string>
#include "catch.hpp"
#include "../class/PrepareResponse.cpp"

using namespace std;

TEST_CASE("CreateResponseSimpleString", "[create_response_simple]") {

    PrepareResponse prepareResponse;
    string expected = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nTest Response<br>\r\n</html>\n";

    prepareResponse.expandLog("Test Response");
    string request = prepareResponse.createResponse();

    REQUIRE(request == expected);
}

TEST_CASE("CreateResponseExpandString", "[create_response_expand]") {

    PrepareResponse prepareResponse;
    string expected = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nFirst log<br>\r\nSecond log<br>\r\n</html>\n";

    prepareResponse.expandLog("First log");
    prepareResponse.expandLog("Second log");
    string request = prepareResponse.createResponse();

    REQUIRE(request == expected);
}

TEST_CASE("CreateResponseEmptyLog", "[create_empty_response]") {
    PrepareResponse prepareResponse;
    string expected = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nNo logs available<br>\r\n</html>\n";

    string request = prepareResponse.createResponse();

    REQUIRE(request == expected);
}

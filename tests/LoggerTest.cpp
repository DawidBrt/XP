
#define CATCH_CONFIG_MAIN 
#include <string>
#include "catch.hpp"
#include "../class/Logger.cpp"

using namespace std;


TEST_CASE("CreateLogSipmpleNotSecured", "[create_log_simple_not_secured]") {
    Logger logger;
    
    string expected = "Network name: test_name\nSignal strength: 20\nNot secured with password";
    string actual = logger.createLog("test_name", "20", false);
    REQUIRE(expected == actual);
}




TEST_CASE("CreateLogSipmpleSecured", "[create_log_simple_secured]") {
    Logger logger;
    
    string expected = "Network name: test_name\nSignal strength: 20\nSecured";
    string actual = logger.createLog("test_name", "20", true);
    REQUIRE(expected == actual);
}

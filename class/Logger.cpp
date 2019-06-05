#include <string>
using namespace std;
class Logger {
public:
    string createLog (string, string, bool);
};

string Logger::createLog(string name, string strength, bool secured)  {
    string log = "Network name: " + name + "\nSignal strength: " + strength;
    if (secured) {
        log += "\nNot secured with password";
    } else {
        log += "\nSecured";
    }
    return log;
}

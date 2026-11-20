#include <iostream>
#include <string>
using namespace std;

class Logger {
    Logger() {}                         // only ONE instance ever
                                         // private constructor
public:
    Logger(const Logger&) = delete;      // no copies
    void operator=(const Logger&) = delete;

    static Logger& get() {               // thread-safe since C++11
        static Logger instance;          // created once, on first call
        return instance;
    }

    void log(const string &m) {
        cout << "[LOG] " << m << endl;
    }
};

int main() {
    Logger::get().log("system up");
    Logger::get().log("same single instance");
    return 0;
}
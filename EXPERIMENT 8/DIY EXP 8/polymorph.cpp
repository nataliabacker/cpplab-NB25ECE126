#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(string msg) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(string msg) override { cout << "[Console] " << msg << endl; }
};

class FileLogger : public Logger {
    ofstream file;
public:
    FileLogger(const string& name) { file.open(name, ios::app); }
    void write(string msg) override { file << "[File] " << msg << endl; }
    ~FileLogger() { file.close(); }
};

int main() {
    Logger* logger = nullptr;
    int choice;
    cout << "1. Console  2. File\nChoose logger: ";
    cin >> choice;

    if (choice == 1) logger = new ConsoleLogger();
    else             logger = new FileLogger("log.txt");

    logger->write("Hello, polymorphism!");
    delete logger;

    // Switch at run time
    cout << "Switching to the other logger...\n";
    logger = (choice == 1) ? static_cast<Logger*>(new FileLogger("log.txt"))
                           : static_cast<Logger*>(new ConsoleLogger());
    logger->write("Switched at run time.");
    delete logger;
    return 0;
}
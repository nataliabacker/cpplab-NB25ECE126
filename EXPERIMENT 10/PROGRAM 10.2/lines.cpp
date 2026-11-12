//Program 10.2 – Append a log + count lines (with exception)

#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

void appendLog(const string &file, const string &entry) {
    ofstream log(file, ios::app);                 // do not erase old data
    if (!log) throw runtime_error("log open failed: " + file);
    log << entry << "\n";
}

int main() {
    try {
        appendLog("run.log", "TEST started");
        appendLog("run.log", "TEST passed");

        ifstream in("run.log");
        if (!in) throw runtime_error("cannot read run.log");
        string line; int lines = 0;
        while (getline(in, line)) ++lines;         // count whole lines
        cout << "run.log now has " << lines << " line(s)\n";
    }
    catch (const exception &e) { cerr << "I/O error: " << e.what() << endl; }
    return 0;
}
//Program 10.3 – Parsing CSV-like records with stringstream

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ofstream out("marks.csv");
    out << "Asha,91\nRavi,78\nMeera,88\n";       // CSV-like records
    out.close();

    ifstream in("marks.csv");
    if (!in) { cerr << "open failed\n"; return 1; }

    string line;
    while (getline(in, line)) {                  // one record per line
        stringstream ss(line);                   // treat the line as a stream
        string name, marks;
        getline(ss, name, ',');                  // split on comma
        getline(ss, marks, ',');
        cout << name << " => " << marks << endl;
    }
    return 0;
}
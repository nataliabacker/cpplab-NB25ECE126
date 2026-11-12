
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    if (!fin) {
        cout << "Input file not found!";
        return 1;
    }

    if (!fout) {
        cout << "Output file cannot be created!";
        return 1;
    }

    string line;
    int lineNo = 1;

    while (getline(fin, line)) {
        fout << lineNo << ". " << line << endl;
        lineNo++;
    }

    cout << "File copied successfully with line numbers.";

    fin.close();
    fout.close();

    return 0;
}

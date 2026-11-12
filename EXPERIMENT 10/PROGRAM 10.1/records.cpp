//Program 10.1 – Write then read structured records
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // --- WRITE three student records ---
    ofstream out("students.txt");
    if (!out) { cerr << "cannot open for write\n"; return 1; }
    out << "Asha 91\n" << "Ravi 78\n" << "Meera 88\n";
    out.close();

    // --- READ them back and compute average ---
    ifstream in("students.txt");
    if (!in) { cerr << "cannot open for read\n"; return 1; }
    string name; int marks, total = 0, count = 0;
    while (in >> name >> marks) {             // stops at end-of-file
        cout << name << " scored " << marks << endl;
        total += marks; ++count;

    if (count) cout << "Average = " << (double)total / count << endl;
    return 0;
}
}
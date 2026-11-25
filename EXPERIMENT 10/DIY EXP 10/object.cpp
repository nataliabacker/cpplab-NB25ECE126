
#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    Student s[100];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    // Writing records into file
    ofstream fout("students.txt");

    for (int i = 0; i < n; i++) {
        cout << "Enter name and marks: ";
        cin >> s[i].name >> s[i].marks;

        fout << s[i].name << " " << s[i].marks << endl;
    }

    fout.close();

    // Reading records from file
    ifstream fin("students.txt");

    for (int i = 0; i < n; i++) {
        fin >> s[i].name >> s[i].marks;
    }

    fin.close();

    // Finding topper
    int topper = 0;

    for (int i = 1; i < n; i++) {
        if (s[i].marks > s[topper].marks) {
            topper = i;
        }
    }

    cout << "\nTopper: " << s[topper].name;
    cout << "\nMarks: " << s[topper].marks;

    return 0;
}

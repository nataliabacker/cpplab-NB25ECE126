
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
    int n = 0;

    ifstream fin("students.txt");

    if (!fin) {
        cout << "File not found!";
        return 1;
    }

    // Read records into array of objects
    while (n < 100 && fin >> s[n].name >> s[n].marks) {
        n++;
    }

    fin.close();

    if (n == 0) {
        cout << "No student records found.";
        return 0;
    }

    // Find topper
    int topper = 0;

    for (int i = 1; i < n; i++) {
        if (s[i].marks > s[topper].marks) {
            topper = i;
        }
    }

    // Display all student records
    cout << "Student Records:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Name: " << s[i].name
             << ", Marks: " << s[i].marks << endl;
    }

    // Display topper
    cout << "\nTopper Details:" << endl;
    cout << "Name: " << s[topper].name << endl;
    cout << "Marks: " << s[topper].marks << endl;

    return 0;
}

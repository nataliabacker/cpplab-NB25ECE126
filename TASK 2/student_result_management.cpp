#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <string>
using namespace std;

// Base class
class Student {
protected:
    int rollNo;
    string name;

public:
    // Constructor
    Student(int r, string n) {
        rollNo = r;
        name = n;
    }

    // Virtual function
    virtual void displayDetails() {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
    }

    // Pure virtual function
    virtual void displayMarks() = 0;

    // Virtual destructor
    virtual ~Student() {}
};

// Derived class
class Result : public Student {
private:
    float math, english, science;

public:
    // Parameterized constructor
    Result(int r, string n, float a, float b, float c)
        : Student(r, n) {
        math = a;
        english = b;
        science = c;
    }

    // Calculate total marks
    float getTotal() const {
        return math + english + science;
    }

    // Calculate grade
    string getGrade() const {
        float total = getTotal();

        if (total > 250)
            return "A";
        else if (total >= 205)
            return "B";
        else if (total >= 160)
            return "C";
        else if (total >= 105)
            return "D";
        else
            return "FAIL";
    }

    // Display marks and result
    void displayMarks() override {
        cout << "\nMath: " << math;
        cout << "\nEnglish: " << english;
        cout << "\nScience: " << science;
        cout << "\nTotal Marks: " << getTotal();
        cout << "\nGrade: " << getGrade();
        cout << "\n";
    }

    // Save details to file
    void saveToFile(ofstream& file) const {
        file << rollNo << " " << name << " "
             << math << " " << english << " "
             << science << endl;
    }
};

// TEMPLATE FUNCTION
template <typename T>
void displayStudentCount(const vector<T>& students) {
    cout << "\nTotal Number of Students: "
         << students.size() << endl;
}

int main() {
    int n, roll;
    string name;
    float math, english, science;

    // STL vector
    vector<Result> students;

    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of students!";
        return 0;
    }

    // Taking student details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Student "
             << i + 1 << endl;

        cout << "Roll Number: ";
        cin >> roll;

        cout << "Name: ";
        cin >> name;

        try {
            cout << "Enter Math marks: ";
            cin >> math;

            cout << "Enter English marks: ";
            cin >> english;

            cout << "Enter Science marks: ";
            cin >> science;

            if (!cin) {
                throw invalid_argument("Invalid input!");
            }

            if (math < 0 || math > 100 ||
                english < 0 || english > 100 ||
                science < 0 || science > 100) {

                throw invalid_argument(
                    "Invalid marks! Enter marks between 0 and 100."
                );
            }

            students.emplace_back(
                roll, name, math, english, science
            );
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            i--;
        }
    }

    // Display student details
    cout << "\n===== STUDENT RESULTS =====\n";

    for (int i = 0; i < students.size(); i++) {
        Student* ptr = &students[i];

        ptr->displayDetails();
        ptr->displayMarks();
    }

    // TEMPLATE FUNCTION CALL
    displayStudentCount(students);

    // STL ALGORITHM AND LAMBDA EXPRESSION
    float threshold;

    cout << "\nEnter minimum total marks to identify students: ";
    cin >> threshold;

    int countAbove = count_if(
        students.begin(), students.end(),
        [threshold](const Result& s) {
            return s.getTotal() > threshold;
        }
    );

    cout << "\nNumber of students scoring above "
         << threshold << ": " << countAbove << endl;

    // Display students scoring above specified marks
    cout << "\n===== STUDENTS ABOVE SPECIFIED MARKS =====\n";

    for_each(students.begin(), students.end(),
        [threshold](const Result& s) {
            if (s.getTotal() > threshold) {
                cout << "\nRoll Number: " << s.getTotal();
                cout << "\nTotal Marks: " << s.getTotal();
                cout << "\nGrade: " << s.getGrade() << endl;
            }
        }
    );

    // File handling - storing records
    ofstream outFile("students.txt");

    if (outFile.is_open()) {
        for (int i = 0; i < students.size(); i++) {
            students[i].saveToFile(outFile);
        }

        outFile.close();
        cout << "\nRecords saved successfully!";
    }
    else {
        cout << "\nUnable to open file!";
        return 1;
    }

    // File handling - retrieving records
    cout << "\n\n===== RECORDS RETRIEVED =====\n";

    ifstream inFile("students.txt");

    int r;
    string nm;
    float m, e, s;

    if (inFile.is_open()) {

        while (inFile >> r >> nm >> m >> e >> s) {

            Result temp(r, nm, m, e, s);

            temp.displayDetails();
            temp.displayMarks();
        }

        inFile.close();
    }
    else {
        cout << "Unable to open file!";
    }

    return 0;
}
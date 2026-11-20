
#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

    static int count;

public:

    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
        count++;
    }

    ~Student() {
        count--;
    }

    void display() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }

    void display(string message) {
        cout << "\n" << message;
        display();
    }

    static void showCount() {
        cout << "\nTotal Students: " << count << endl;
    }

    friend void compare(Student s1, Student s2);

    bool operator>(Student s) {
        return marks > s.marks;
    }
};

int Student::count = 0;

void compare(Student s1, Student s2) {
    if (s1.marks > s2.marks)
        cout << s1.name << " has higher marks.";
    else if (s2.marks > s1.marks)
        cout << s2.name << " has higher marks.";
    else
        cout << "Both have equal marks.";
}

int main() {
    int n, roll;
    string name;
    float marks;

    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of students.";
        return 0;
    }

    Student** s = new Student*[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Student " << i + 1 << endl;

        cout << "Roll Number: ";
        cin >> roll;

        cout << "Name: ";
        cin >> name;

        cout << "Marks: ";
        cin >> marks;

        s[i] = new Student(roll, name, marks);
    }

    cout << "\n--- Student Details ---\n";

    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1;
        s[i]->display();
    }

    s[0]->display("First Student Information:");

    Student::showCount();

    if (n >= 2) {
        compare(*s[0], *s[1]);
    }

    int topper = 0;

    for (int i = 1; i < n; i++) {
        if (*s[i] > *s[topper]) {
            topper = i;
        }
    }

    cout << "Topper: Student " << topper + 1;
    s[topper]->display();

    for (int i = 0; i < n; i++) {
        delete s[i];
    }

    delete[] s;

    return 0;
}
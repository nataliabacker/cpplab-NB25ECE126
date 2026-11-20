
#include <iostream>
#include <memory>
using namespace std;

class Student
{
public:
    int marks;
    Student(int m)
    {
        marks = m;
    }
    void display()
    {
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    // Creating object using unique_ptr
    unique_ptr<Student> s = make_unique<Student>(95);
    cout << "Student Details:" << endl;
    s->display();
    return 0;
}

#include <iostream>
using namespace std;

class Base {
public:
    ~Base() { cout << "Base destructor\n"; }          // NOT virtual
};

class Derived : public Base {
    int* data;
public:
    Derived() { data = new int[100]; }
    ~Derived() { delete[] data; cout << "Derived destructor\n"; }
};

int main() {
    Base* p = new Derived();
    delete p;    // only ~Base() runs, so data is never freed
    return 0;
}
#include <iostream>
#include <memory>          // smart pointers
#include <string>
using namespace std;

struct Shape {                                      // abstract base
    virtual double area() const = 0;
    virtual ~Shape() {}
};

struct Circle : Shape {
    double r;
    Circle(double r):r(r){}
    double area() const override { return 3.14159*r*r; }
};

struct Square : Shape {
    double s;
    Square(double s):s(s){}
    double area() const override { return s*s; }
};

// Factory: returns a base pointer to the requested derived object
unique_ptr<Shape> makeShape(const string &kind) {
    if (kind == "circle") return make_unique<Circle>(2.0);
    return make_unique<Square>(3.0);
}

int main() {
    auto a = makeShape("circle");    // unique_ptr owns it
    auto b = makeShape("square");
    cout << "area a = " << a->area() << ", area b = " << b->area() << endl;
    return 0;                        // memory freed automatically (no delete)
}
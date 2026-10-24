
#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(string c) {
        color = c;
        cout << "Shape constructor called" << endl;
    }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon(string c, int s) : Shape(c) {
        sides = s;
        cout << "Polygon constructor called" << endl;
    }
};

class Rectangle : public Polygon {
    int width;

public:
    Rectangle(string c, int s, int w) : Polygon(c, s) {
        width = w;
        cout << "Rectangle constructor called" << endl;
    }

    void display() {
        cout << "Color: " << color << endl;
        cout << "Number of sides: " << sides << endl;
        cout << "Width: " << width << endl;
    }
};

int main() {
    Rectangle r("Blue", 4, 10);

    cout << "\nRectangle Details:" << endl;
    r.display();

    return 0;
}

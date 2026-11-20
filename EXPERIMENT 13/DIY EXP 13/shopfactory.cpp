#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape
{
    float r;

public:
    Circle(float x)
    {
        r = x;
    }

    void area()
    {
        cout << "Area of Circle: " << 3.14 * r * r << endl;
    }
};

class Rectangle : public Shape
{
    float l, b;

public:
    Rectangle(float x, float y)
    {
        l = x;
        b = y;
    }

    void area()
    {
        cout << "Area of Rectangle: " << l * b << endl;
    }
};

class Triangle : public Shape
{
    float b, h;

public:
    Triangle(float x, float y)
    {
        b = x;
        h = y;
    }

    void area()
    {
        cout << "Area of Triangle: " << 0.5 * b * h << endl;
    }
};

int main()
{
    vector<unique_ptr<Shape>> shapes;
    string name;

    do
    {
        cout << "\nEnter shape (Circle/Rectangle/Triangle/Exit): ";
        cin >> name;

        if(name == "Circle")
        {
            float r;
            cout << "Enter radius: ";
            cin >> r;

            shapes.push_back(make_unique<Circle>(r));
        }

        else if(name == "Rectangle")
        {
            float l, b;
            cout << "Enter length and breadth: ";
            cin >> l >> b;

            shapes.push_back(make_unique<Rectangle>(l, b));
        }

        else if(name == "Triangle")
        {
            float b, h;
            cout << "Enter base and height: ";
            cin >> b >> h;

            shapes.push_back(make_unique<Triangle>(b, h));
        }

        else if(name != "Exit")
        {
            cout << "Invalid shape!" << endl;
        }

    } while(name != "Exit");

    cout << "\nShape Areas:\n";

    for(auto &s : shapes)
    {
        s->area();
    }

    return 0;
}

#include <iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    void setData(float r, float i)
    {
        real = r;
        imag = i;
    }

    void display()
    {
        cout << real;

        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";

        cout << endl;
    }
};

int main()
{
    Complex c[3];

    c[0].setData(2, 3);
    c[1].setData(4, -2);
    c[2].setData(5, 6);

    cout << "Complex numbers:" << endl;

    for (int i = 0; i < 3; i++)
    {
        c[i].display();
    }

    return 0;
}
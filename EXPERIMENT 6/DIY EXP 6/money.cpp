
#include <iostream>
using namespace std;

class Money {
    int rupees, paise;

public:
    Money(int r = 0, int p = 0) {
        rupees = r + p / 100;
        paise = p % 100;
    }

    Money operator+(const Money& m) {
        return Money(rupees + m.rupees,
                     paise + m.paise);
    }

    Money operator-(const Money& m) {
        int r = rupees - m.rupees;
        int p = paise - m.paise;

        if (p < 0) {
            r--;
            p += 100;
        }

        return Money(r, p);
    }

    void display() {
        cout << rupees << " rupees and "
             << paise << " paise" << endl;
    }
};

int main() {
    Money m1(10, 75);
    Money m2(5, 50);

    Money sum = m1 + m2;
    Money diff = m1 - m2;

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    return 0;
}

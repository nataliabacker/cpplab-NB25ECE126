
#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction {
    int numerator, denominator;

    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    void simplify() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int g = gcd(numerator, denominator);

        if (g != 0) {
            numerator /= g;
            denominator /= g;
        }
    }

public:
    Fraction(int n = 0, int d = 1) {
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }

        numerator = n;
        denominator = d;
        simplify();
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        in >> f.numerator >> f.denominator;

        if (f.denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }

        f.simplify();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main() {
    Fraction f;

    cout << "Enter numerator and denominator: ";
    try {
        cin >> f;
        cout << "Simplified fraction: " << f << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

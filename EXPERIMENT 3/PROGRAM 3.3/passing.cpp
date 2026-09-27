#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    // takes an object BY REFERENCE, RETURNS a new object by value
    Point add(const Point &p) const { return Point(x + p.x, y + p.y); }
    // 'this' points to the calling object; returning *this enables chaining
    Point& setX(int v) { this->x = v; return *this; }
    Point& setY(int v) { this->y = v; return *this; }
    void show() const { cout << "(" << x << "," << y << ")\n"; }
};

void shift(Point &p)     { p.setX(99); }   // by reference: changes original
void tryShift(Point p)   { p.setX(-1); }   // by value: works on a copy

int main() {
    Point a(1, 2), b(3, 4);
    Point c = a.add(b);             // returning an object -> (4,6)
    c.show();
    Point d; d.setX(7).setY(8);     // chaining through 'this' -> (7,8)
    d.show();
    shift(a); a.show();             // (99,2) original changed
    tryShift(b); b.show();           // (3,4) original unchanged
    return 0;
}
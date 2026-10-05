#include <iostream>
using namespace std;

class Time {
    int hh, mm;

public:
    Time(int h, int m) {
        hh = h;
        mm = m;
    }

    friend Time laterOf(Time t1, Time t2);

    void display() {
        cout << hh << ":";

        if (mm < 10)
            cout << "0";

        cout << mm << endl;
    }
};

Time laterOf(Time t1, Time t2) {
    int time1 = t1.hh * 60 + t1.mm;
    int time2 = t2.hh * 60 + t2.mm;

    if (time1 > time2)
        return t1;
    else
        return t2;
}

int main() {
    Time t1(10, 30);
    Time t2(12, 45);

    Time later = laterOf(t1, t2);

    cout << "Later time: ";
    later.display();

    return 0;
}
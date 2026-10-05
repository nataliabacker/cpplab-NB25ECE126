#include <iostream>
using namespace std;

class Counter {
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter() {
        totalCreated++;
        currentlyAlive++;
    }

    ~Counter() {
        currentlyAlive--;
    }

    static void report() {
        cout << "Total objects ever created: " << totalCreated << endl;
        cout << "Objects currently alive: " << currentlyAlive << endl;
    }
};

int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    Counter c1;
    Counter c2;

    Counter::report();

    {
        Counter c3;
        Counter c4;

        Counter::report();
    }

    Counter::report();

    return 0;
}
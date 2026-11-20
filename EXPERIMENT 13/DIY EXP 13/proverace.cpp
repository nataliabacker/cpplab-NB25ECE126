#include <iostream>
#include <thread>
using namespace std;

long counter = 0;

void addSafe(int times) {
    for (int i = 0; i < times; ++i) {
        ++counter;  
    }
}

int main() {
    for (int run = 1; run <= 5; run++) {
        counter = 0;

        thread t1(addSafe, 100000);
        thread t2(addSafe, 100000);

        t1.join();
        t2.join();

        cout << "Run " << run
             << ": counter = " << counter
             << " (expected 200000)" << endl;
    }

    return 0;
}
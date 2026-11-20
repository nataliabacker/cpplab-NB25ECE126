#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

long counter = 0;
mutex m;

void addSafe(int times) {
    for (int i = 0; i < times; ++i) {
        lock_guard<mutex> lk(m);    // locks here, unlocks at scope end
        ++counter;                  // protected critical section
    }
}

int main() {
    thread t1(addSafe, 100000);     // two threads run in parallel
    thread t2(addSafe, 100000);
    t1.join(); t2.join();          // wait for both
    cout << "counter = " << counter << " (expected 200000)\n";
    return 0;
}
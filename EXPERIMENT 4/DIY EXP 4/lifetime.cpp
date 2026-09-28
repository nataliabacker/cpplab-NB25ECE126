#include <iostream>
using namespace std;

class Tracer {
    int id;

public:
    Tracer(int i) {
        id = i;
        cout << "Tracer " << id << " created\n";
    }

    ~Tracer() {
        cout << "Tracer " << id << " destroyed\n";
    }
};

int main() {

    for (int i = 1; i <= 5; i++) {

        Tracer *t = new Tracer(i);

        cout << "Tracer " << i << " is being used\n";

        delete t;
    }

    return 0;
}
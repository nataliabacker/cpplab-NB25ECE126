#include <iostream>
using namespace std;

class Counter
{
private:
    int count;

public:
    Counter()
    {
        count = 0;
    }

    void increment()
    {
        count++;
    }

    void reset()
    {
        count = 0;
    }

    int get()
    {
        return count;
    }
};

int main()
{
    Counter c[3];

    c[0].increment();
    c[0].increment();

    c[1].increment();
    c[1].increment();
    c[1].increment();

    c[2].increment();

    cout << "Counter 1 = " << c[0].get() << endl;
    cout << "Counter 2 = " << c[1].get() << endl;
    cout << "Counter 3 = " << c[2].get() << endl;

    c[1].reset();

    cout << "After resetting Counter 2:" << endl;
    cout << "Counter 2 = " << c[1].get() << endl;

    return 0;
}
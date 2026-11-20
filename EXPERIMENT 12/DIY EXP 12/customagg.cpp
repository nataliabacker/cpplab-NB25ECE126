
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> v = {2, 3, 4, 5, 6};

    // Product of all elements
    int product = accumulate(v.begin(), v.end(), 1,
        [](int a, int b)
        {
            return a * b;
        });

    // Sum of even elements
    int evenSum = accumulate(v.begin(), v.end(), 0,
        [](int a, int b)
        {
            if(b % 2 == 0)
                return a + b;
            else
                return a;
        });

    cout << "Product of elements: " << product << endl;
    cout << "Sum of even elements: " << evenSum << endl;

    return 0;
}

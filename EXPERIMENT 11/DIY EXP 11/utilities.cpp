#include <iostream>
using namespace std;

// Function to swap two values
template <class T>
void swapVals(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Function to find maximum value
template <class T>
T findMax(T arr[], int n)
{
    T max = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

int main()
{
    int a = 10, b = 20;

    cout << "Before swapping: " << a << " " << b << endl;
    swapVals(a, b);
    cout << "After swapping: " << a << " " << b << endl;

    int arr[] = {10, 30, 20, 50, 40};
    cout << "Maximum integer: " << findMax(arr, 5) << endl;

    double x = 2.5, y = 4.5;
    swapVals(x, y);

    cout << "After swapping doubles: " << x << " " << y << endl;

    double arr2[] = {2.5, 5.5, 1.5, 8.5};
    cout << "Maximum double: " << findMax(arr2, 4);

    return 0;
}

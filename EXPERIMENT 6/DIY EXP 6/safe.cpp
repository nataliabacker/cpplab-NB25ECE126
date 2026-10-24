
#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
    int* arr;
    int size;

public:
    SafeArray(int n) {
        size = n;
        arr = new int[size]();
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Array index out of range");
        }

        return arr[index];
    }

    ~SafeArray() {
        delete[] arr;
    }
};

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size" << endl;
        return 0;
    }

    SafeArray a(n);

    try {
        cout << "Enter " << n << " elements:" << endl;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << "Array elements: ";

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;

        int index;
        cout << "Enter index to access: ";
        cin >> index;

        cout << "Element: " << a[index] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

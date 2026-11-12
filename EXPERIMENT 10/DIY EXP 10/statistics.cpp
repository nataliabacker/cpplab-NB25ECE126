
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("nums.txt");

    if (!fin) {
        cout << "File not found!";
        return 1;
    }

    int num, count = 0;
    int sum = 0, min, max;

    while (fin >> num) {
        if (count == 0) {
            min = max = num;
        }

        if (num < min)
            min = num;

        if (num > max)
            max = num;

        sum += num;
        count++;
    }

    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    if (count > 0) {
        cout << "Minimum = " << min << endl;
        cout << "Maximum = " << max << endl;
    }
    else {
        cout << "No numbers in file.";
    }

    fin.close();
    return 0;
}

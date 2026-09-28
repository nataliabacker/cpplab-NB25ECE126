#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int size;

public:
    // Constructor
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    // Push
    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;
    }

    // Pop
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Popped: " << arr[top--] << endl;
    }

    // Display
    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack: ";

        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";

        cout << endl;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
        cout << "Stack memory released.\n";
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();

    s.display();

    return 0;
}
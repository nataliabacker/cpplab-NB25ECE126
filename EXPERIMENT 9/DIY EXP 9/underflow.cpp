
#include <iostream>
#include <exception>
using namespace std;

class StackOverflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Overflow!";
    }
};

class StackUnderflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Underflow!";
    }
};

class Stack {
private:
    int arr[3];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 2) {
            throw StackOverflow();
        }

        arr[++top] = value;
        cout << value << " pushed into stack" << endl;
    }

    void pop() {
        if (top == -1) {
            throw StackUnderflow();
        }

        cout << arr[top--] << " popped from stack" << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);  // Overflow
    }
    catch (StackOverflow &e) {
        cout << "Exception: " << e.what() << endl;
    }

    try {
        s.pop();
        s.pop();
        s.pop();
        s.pop();  // Underflow
    }
    catch (StackUnderflow &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

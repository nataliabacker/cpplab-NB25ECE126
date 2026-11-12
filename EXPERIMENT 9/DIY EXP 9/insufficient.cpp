#include <iostream>
#include <exception>
using namespace std;

class InsufficientFunds : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient balance!";
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance -= amount;
        cout << "Withdrawal successful: " << amount << endl;
    }

    void display() {
        cout << "Current balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(5000);

    try {
        acc.display();
        acc.withdraw(6000);
    }
    catch (InsufficientFunds &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

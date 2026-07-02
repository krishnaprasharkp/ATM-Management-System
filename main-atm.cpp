#include <iostream>
#include <vector>
using namespace std;

class ATM {
private:
    int pin;
    double balance;
    vector<string> statement;

public:
    ATM() {
        pin = 1234;
        balance = 5000;
    }

    bool login() {
        int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            cout << "Login successful!\n";
            return true;
        } else {
            cout << "Invalid PIN!\n";
            return false;
        }
    }

    void checkBalance() {
        cout << "Current Balance: Rs. " << balance << endl;
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            statement.push_back("Deposited Rs. " + to_string(amount));
            cout << "Amount deposited successfully!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > 0 && amount <= balance) {
            balance -= amount;
            statement.push_back("Withdrawn Rs. " + to_string(amount));
            cout << "Amount withdrawn successfully!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void miniStatement() {
        if (statement.empty()) {
            cout << "No transactions yet.\n";
            return;
        }

        cout << "\nMini Statement:\n";
        for (string s : statement) {
            cout << s << endl;
        }
    }
};

int main() {
    ATM user;
    int choice;

    if (!user.login()) {
        return 0;
    }

    do {
        cout << "\n===== ATM Management System =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Mini Statement\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                user.checkBalance();
                break;

            case 2:
                user.deposit();
                break;

            case 3:
                user.withdraw();
                break;

            case 4:
                user.miniStatement();
                break;

            case 5:
                cout << "Thank you for using ATM!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

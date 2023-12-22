// Bank Account
#include <iostream>

using namespace std;

class Account {

private:
    double balance;

public:
    Account() {
        balance = 0; 
    }

    Account(double initialDeposit) {
        balance = initialDeposit;
    }


    double getBalance() {
        return balance;
    }

    double deposit(double amount) {
        try {
            if (amount <= 0) {
                throw amount; 
            }
            else {
                balance += amount; 
                return balance;
            }
        }
        catch (double amount) { 
            cout << "Invalid deposit." << endl;
            cout << "The available balance is ";
            return balance;
        }
    }

    double withdraw(double amount) {
        try {
            if ((amount > balance) || (amount < 0)) { 
                throw amount;
            }
            else {
                balance -= amount; 
                return balance;
            }

        }
        catch (double amount) { 
            cout << "Insufficient amount. " << endl;
            cout << "The available balance is ";
            return balance;
        }
    }
};


int main() {

    Account ram; 
    cout << ram.deposit(600) << endl; 
    cout << ram.withdraw(250) << endl; 
    cout << ram.withdraw(321) << endl; 
    cout << ram.deposit(-1) << endl; 

    cout << "Balance of ram is : " << ram.getBalance(); 


    return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h>
#include <list>

using namespace std;

#ifndef BANKING_SYSTEM_USER_H
#define BANKING_SYSTEM_USER_H


class User {


private:

    string name;
    long phoneNumber;
    long accountNumber;
    double balance;
    int accountAge;
    list<string> transactionHistory;

public:

    void registerUser() {

        // set name
        string fName;
        string lName;

        cout << "First name: ";
        cin >> fName;
        fName[0] = toupper(fName[0]);
        cout << "Last name: ";
        cin >> lName;
        lName[0] = toupper(lName[0]);
        name = fName + " " + lName;

        // phone number
        long phone = 0;

        cout << "Phone number: ";
        cin >> phone;
        while (cin.fail() || phone < 1000000000 || phone > 9999999999) {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "error: invalid input received..." << endl;
            cout << "Phone number: ";
            cin >> phone;
        }

        phoneNumber = phone;


        // set account number
        accountNumber = rand() % 20000000 + 10000001;

        // set default account balance
        balance = 0;

        // set account age
        accountAge = 0;

        transactionHistory.emplace_back("test1");

    }

    // TRANSACTIONS
    void history() {
        transactionHistory.emplace_back("test");

        cout << endl << "---=== TRANSACTION HISTORY ===---" << endl;
        for (auto &i : transactionHistory) {
            cout << i << endl;
        }
    }


    void userInfo() {
        cout << endl;
        cout << "retrieving user information..." << endl;
        sleep(2);
        cout << endl << "---=== ACCOUNT INFO ===---" << endl;
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }


    void deposit() {
        double amount;
        cout << "Deposit amount (enter 0 to cancel): $";
        cin >> amount;
        if (amount == 0) {
            cout << "deposit cancelled..." << endl;
            return;
        }
        balance += amount;
        transactionHistory.emplace_back("Credited: $" + to_string(amount));
    }

    void withdraw() {
        double amount;
        cout << "Withdraw amount (enter 0 to cancel): $";
        cin >> amount;
        if (amount == 0) {
            cout << "withdraw cancelled..." << endl;
            return;
        }
        if (amount > balance) {
            cout << "error: insufficient funds..." << endl;
            return;
        }
        balance -= amount;
        transactionHistory.emplace_back("Debit: $" + to_string(amount));
    }




};


#endif //BANKING_SYSTEM_USER_H

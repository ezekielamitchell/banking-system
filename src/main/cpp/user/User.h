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
    string phoneNumber;
    long accountNumber;
    double balance;
//    int accountAge;
    list<string> transactionHistory;

public:

    void registerUser() {

        // set name
        string fName;
        string lName;

        // new transaction history
        transactionHistory.clear();

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
            cin.ignore(1000, '\n');
            cout << "error: invalid input received..." << endl;
            cout << "Phone number: ";
            cin >> phone;
        }


        phoneNumber = to_string(phone).substr(0, 3)
                + '-'
                + to_string(phone).substr(3, 3)
                + '-'
                + to_string(phone).substr(6, 4);


        // set account number
        accountNumber = rand() % 20000000 + 10000001;

        // set default account balance
        balance = 0;

        // set account age
//        accountAge = 0;

    }

    // TRANSACTIONS
    void history() {

        cout << endl << "---=== TRANSACTION HISTORY ===---" << endl;
        for (auto &i: transactionHistory) {
            cout << i << endl;
        }
    }


    // USER INFO
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


    // DEPOSIT
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

    // WITHDRAW
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

    void displayMenu() {

        cout << endl << "*---=== Bank of Endr ===---*" << endl;
        cout << "Menu:" << endl;
        cout << "1. New Account Registration" << endl;
        cout << "2. Display Account Information" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Transaction History" << endl;
        cout << "6. Exit" << endl;
        cout << endl << "enter option number: ";

        // user choice
        int choice;
        cin >> choice;
        while (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "error: invalid input received..." << endl;
            cout << endl << "enter option number: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                registerUser();
                displayMenu();
            case 2:
                userInfo();
                displayMenu();
            case 3:
                deposit();
                displayMenu();
            case 4:
                withdraw();
                displayMenu();
            case 5:
                history();
                displayMenu();
            case 6:
                cout << "logging out..." << endl;
                sleep(2);
                cout << "goodbye";
                return;
        }
    }
};


#endif //BANKING_SYSTEM_USER_H

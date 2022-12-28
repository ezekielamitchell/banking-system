#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h>
#include <list>
#include <algorithm>
#include <vector>
#include "/Users/house/code/proj/banking-system/src/main/cpp/menu/Menu.cpp"

using namespace std;

#ifndef BANKING_SYSTEM_USER_H
#define BANKING_SYSTEM_USER_H



class User {

private:
    double balance{0};
    list<string> transactionHistory;

public:

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
        cout << "Balance: $" << balance << endl;
        cout << "Account Number: " << account.accountNumber << endl;
        cout << "First Name: " << account.fName << endl;
        cout << "Last Name: " << account.lName << endl;
        cout << "Username: " << account.userName << endl;
        cout << "Password: " << account.password << endl;

        // account info
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
        cout << "User Menu:" << endl;
        cout << "1) Display Account Information" << endl;
        cout << "2) Deposit" << endl;
        cout << "3) Withdraw" << endl;
        cout << "4) Transaction History" << endl;
        cout << "5) Log Out" << endl;
        cout << "6) Exit" << endl;
        cout << endl << "enter option number: ";

        // user choice
        int choice;
        cin >> choice;
        while (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input received; please enter between choices 1-6" <<endl;
            cin >> choice;
        }

        bool loggedIn{true};
        while (loggedIn) {
            switch (choice) {
                case 1:
                    userInfo();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    history();
                    break;
                case 5:
                    cout << "logging out..." << endl;
                    sleep(1);
                    cout << "logging out.." << endl;
                    sleep(1);
                    cout << "logging out." << endl;
                    sleep(1);
                    loggedIn = false;
                    break;
                case 6:
                    cout << "Exiting systems...";
                    exit(0);
            }
            if (loggedIn) {
                displayMenu();
            } else {
                break;
            }
        }

        while (true) {
            switch (menu()) {
                case 1:
                    users.push_back(registerAccount());
                    break;
                case 2:
                    if (login()) {
                        // display user menu
                        displayMenu();
                    } else {
                        continue;
                    }
                    break;
                case 3:
                    cout << "Exiting systems...";
                    exit(0);
            }
        }
    }
};


#endif //BANKING_SYSTEM_USER_H

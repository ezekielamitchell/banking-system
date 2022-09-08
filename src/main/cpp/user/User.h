#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef BANKING_SYSTEM_USER_H
#define BANKING_SYSTEM_USER_H


class User {

private:

    string name;
    long phoneNumber;
    long accountNumber;
    double balance;
    double accountAge;

public:

    void registerUser() {

        // set name
        string fName;
        string lName;

        cout << "First name: ";
        cin >> fName;
        cout << "Last name: ";
        cin >> lName;
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

    }

    void userInfo() {
        cout << endl << "---=== ACCOUNT INFO ===---" << endl;
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }


};


#endif //BANKING_SYSTEM_USER_H

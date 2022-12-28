#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

struct Account {
    string accountNumber;
    string fName;
    string lName;
    string userName;
    string password;
};

Account account; // active account
vector<Account> users;

int menu() {

    int input;

    cout << "*----- Menu -----*" << endl;
    cout << "1) Register" << endl;
    cout << "2) Log In" << endl;
    cout << "3) exit" << endl;
    cout << "enter option: ";
    cin >> input;

    // invalid user input
    if (std::cin.fail() || !(input == 1 || input == 2 || input == 3)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input; please enter 1, 2, or 0" <<endl;
    }

    return input;
}

Account registerAccount() {
    Account user;

    // Read the first name
    cout << "First name: ";
    cin.ignore(1, '\n');
    getline(cin, user.fName);


    // Read the last name
    cout << "Last name: ";
    getline(cin, user.lName);

    cout << "Username: ";
    bool usernameExists = true;
    while (usernameExists) {
        cin >> user.userName;
        usernameExists = false;
        for (Account& i : users) {
            if (user.userName == i.userName) {
                usernameExists = true;
                cout << "Username already exists. Enter a new username: ";
                break;
            }
        }
    }

    cout << "Password (min 8 characters):  ";
    cin >> user.password;
    while (user.password.length() < 8) {
        cout << "Password must be at least 6 characters. Try again." << endl;
        cin >> user.password;
    }

    user.accountNumber = to_string(users.size() + 1000);
    users.push_back(user);
    return user;
}

void accountInfo(Account& user) {
    // print user info
    cout << "Account Number: " << user.accountNumber << endl;
    cout << "First Name: " << user.fName << endl;
    cout << "Last Name: " << user.lName << endl;
    cout << "Username: " << user.userName << endl;
    cout << "Password: " << user.password << endl;
}

bool login() {
    string username;
    string password;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;
    cin.ignore(1, '\n');

    // check if user exist in users vector
    for (Account& user : users) {
        if (user.userName == username && user.password == password) {
            account = user;
            cout << "Login successful!" << endl;
            return true;
        }
    }

    cout << "Login failed. Account name or password is incorrect." << endl;
    return false;
}



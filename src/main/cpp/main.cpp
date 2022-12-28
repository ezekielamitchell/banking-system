#include "/Users/house/code/proj/banking-system/src/main/cpp/user/User.h"

int main() {

    while (true) {
        switch (menu()) {
            case 1:
                users.push_back(registerAccount());
                break;
            case 2:
                if (login()) {
                    // display user menu
                    User user;
                    user.displayMenu();
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

//todo: display account info

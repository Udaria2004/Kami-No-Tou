#include "bits/stdc++.h"
#include "main_menu.h"
#include "rules.h"

using namespace std;

int main_menu() {
    cout << "0. Rules" << endl
         << "1. New Game" << endl
         << "2. Load Game" << endl
         << "3. Exit" << endl
         << "Enter your choice: ";
    int x;
    cin >> x;
    while (true) {
        switch (x) {
            case 0:
                print_rules();
                break;
            case 1:
                cout << "Transporting you to another world" << endl;
                return x;
            case 2:
                cout << "Wake up!" << endl;
                cout << "You still have not completed your mission!" << endl;
                return x;
            case 3:
                cout << "Exiting" << endl;
                exit(1);
            default :
                cout << "Invalid choice!" << endl;
        }
    }
}
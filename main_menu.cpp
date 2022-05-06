#include "bits/stdc++.h"
#include "main_menu.h"
#include "utility.h"
#include "player.h"
#include "rules.h"
#include "chapter1.h"
#include "prologue.h"

using namespace std;

int input_choice() {
    cout << "1. Rules" << endl
         << "2. Play" << endl
         << "3. Exit" << endl
         << "Enter your choice: ";
    int x;
    cin >> x;
    while (true) {
        switch (x) {
            case 1:
                return x;
            case 2:
                cout << "Transporting you to another world" << endl;
                slow_print("Please wait...", 200);
                print_intro();
                return x;
            case 3:
                cout << "Exiting" << endl;
                exit(1);
            default :
                cout << "Invalid choice!" << endl;
        }
    }
}

void main_menu() {
    player p1;
    int location1 = 0;
    int choice = input_choice();
    if (choice == 0)
        print_rules();
    else if (choice == 1) {
        p1.init();
        prologue();
        chap1(location1);
        cout << endl << "You can now go to your house to restore health";
        cout << "Do you want to take a look at the quests?" << endl;
    }
}
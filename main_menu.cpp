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
         << "3. Exit" << endl;
    string x;
    while (true) {
        cout << "Enter your choice: " << flush;
        cin >> x;
        if (x == "1" || x == "2" || x == "3")
            return stoi(x);
        else
            cout << "Invalid input!\n" << endl;
    }
}

void main_menu() {
    player p1;
    int choice = input_choice();
    if (choice == 1)
        print_rules();
    else if (choice == 2) {
        cout << "\nTransporting you to another world" << endl;
        slow_print("Please wait...", 100);
        print_intro();
        p1.init();
        prologue(p1);
        cout << endl << "You can now go to your house to restore health";
        cout << "Do you want to take a look at the quests?" << endl;
    } else if (choice == 3) {
        slow_print("Hope you had fun!", 100);
        exit(1);
    }
}
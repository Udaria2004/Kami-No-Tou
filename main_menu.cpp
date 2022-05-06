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
    char x;
    while (true) {
        cout << "Enter your choice: " << flush;
        cin >> x;
        if (x == '1' || x == '2' || x == '3')
            return x - '0';
        else
            cout << "Invalid input!\n" << endl;
    }
}

void main_menu() {
    player p1;
    int location_p1 = 0;
    int choice = input_choice();
    if (choice == 1)
        print_rules();
    else if (choice == 2) {
        cout << "\nTransporting you to another world" << endl;
        slow_print("Please wait...", 200);
        print_intro();
        p1.init();
        cout << endl;
        p1.print_stats();
        pause();
        prologue();
        chap1(location_p1);
        cout << endl << "You can now go to your house to restore health";
        cout << "Do you want to take a look at the quests?" << endl;
    } else if (choice == 3) {
        slow_print("Hope you had fun!", 200);
        exit(1);
    }
}
#include "bits/stdc++.h"
#include "main_menu.h"
#include "utility.h"
#include "player.h"
#include "rules.h"
#include "prologue.h"

using namespace std;

int input_choice() {                              // Input Choices
    cout << "1. Rules" << endl
         << "2. Play" << endl
         << "3. Exit" << endl;
    string x;
    while (true) {
        cout << "Enter your choice: " << flush;
        cin >> x;
        if (x == "1" || x == "2" || x == "3")
            return stoi(x);                             //Loop until correct input
        else
            cout << "Invalid input!\n" << endl;
    }
}

void main_menu() {
    while (true) {             // Loop the main menu of the game
        player p1;                       // class Player with data structure of the player stats
        print_intro();                 // Game Beginning  
        int choice = input_choice();  
        if (choice == 1)
            print_rules();                   //Prints rule of the game
        else if (choice == 2) {
            cout << "\nTransporting you to another world" << endl;    //New Game
            slow_print("Please wait...", 100);
            print_intro();                                //Prints the title of game
            p1.init();                                       // Character Creation
            prologue(p1);                                    
        } else if (choice == 3) {
            slow_print("Hope you had fun!", 100);        // Exit the game
            cout << endl;
            exit(1);
        }
    }
}

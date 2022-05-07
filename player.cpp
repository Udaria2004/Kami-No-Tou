#include "player.h"
#include "utility.h"
#include <bits/stdc++.h>

using namespace std;

void player::print_stats() const {   // Display character stats
    cout << name << ", your stats are as follows:" << endl
         << "HP: " << player_stat.hp << endl
         << "MP: " << player_stat.mp << endl
         << "Potions: " << player_stat.potion << endl;
}

void player::print_character_art() {   //display character art
    cout << "Hola amigo!" << endl;
    print_file("ascii_art/character.txt");
    cout << endl;
}

void player::init() {       //character creation
    print_character_art();
    get_name();
    get_char_type();
    print_stats();
    cin.ignore();
    prog_pause();
}

void player::get_name() {  
    cout << endl << "What is thy nameth?: " << flush;
    cin >> name;
    cout << endl << "Welcome " << name << ", son of " << name << "oth" << endl;
    cout << "Thy journey begins anew" << endl << endl;
}

void player::get_char_type() {
    cout << "Please choose your character type:" << endl;
    cout << "1. Warrior | 2. Mage | 3. Farmer" << endl;
    string x;
    while (true) {
        cout << endl << "Choice: ";
        cin >> x;
        if (x == "1" || x == "2" || x == "3") {
            c_type = stoi(x);
            assign_stats(c_type);
            break;
        } else
            cout << endl << "Think you are special eh? Try again." << endl;
    }
    cout << endl;
}

void player::get_location(bool print_locs) {                    //location to which player wants to go
    vector<string> loc = {"House", "Woods", "Guild", "Tower"};
    string temp;
    while (true) {
        if (print_locs) {
            cout << endl << endl;
            print_file("ascii_art/location.txt");
            cout << endl << endl;
            cout << "Current Location: " << loc[location] << endl << endl;
        }
        cout << endl << "Where to? " << flush;
        cin >> temp;

        if (temp == to_string(location))
            cout << endl << "You are already there!" << endl;
        else if (temp == "0" || temp == "1" || temp == "2" || temp == "3") {
            location = stoi(temp);
            break;
        } else
            cout << endl << "Want to reach Mars huh?" << endl;
    }
}

void player::assign_stats(int type) {  //dynamic player creation
    if (type == 1) {
        char_type = "Warrior";
        player_stat = {100, 50, 5, 1, 6};
    } else if (type == 2) {
        char_type = "Mage";
        player_stat = {100, 100, 5, 1, 5};
    } else if (type == 3) {
        char_type = "Farmer";
        player_stat = {100, 50, 10, 1, 5};
    }
}

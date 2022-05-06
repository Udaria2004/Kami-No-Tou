#include "player.h"
#include "utility.h"
#include <bits/stdc++.h>

using namespace std;

void player::print_stats() {
    cout << name << ", your stats are as follows:" << endl
         << "HP: " << player_stat.hp << endl
         << "MP: " << player_stat.mp << endl
         << "Luck:" << player_stat.luck << endl
         << "Potions: " << player_stat.potion << endl
         << "Damage: " << player_stat.damage << endl;
}

void player::print_character_art() {
    cout << "Hola!" << endl;
    print_file("ascii_art/character.txt");
    cout << endl;
}

void player::init() {
    print_character_art();
    get_name();
    get_char_type();
}

void player::get_name() {
    cout << "What is thy nameth?: " << flush;
    cin >> name;
    cout << "Welcome " << name << ", son of Agaroth" << endl;
    cout << "Thy journey begins anew" << endl << endl;
}

void player::get_char_type() {
    cout << "Please choose your character type:" << endl;
    cout << "1. Warrior  |  2. Mage  | 3. Farmer   " << endl;
    char x;
    while (true) {
        cout << "Choice: ";
        cin >> x;
        if (x == '1' || x == '2' || x == '3') {
            assign_stats(x - '0');
            break;
        } else
            cout << "Think you are special eh? Try again." << endl;
    }
}

void player::assign_stats(int type) {
    if (type == 1) {
        char_type = "Warrior";
        player_stat = {100, 50, 5, 0, 26};
    } else if (type == 2) {
        char_type = "Mage";
        player_stat = {75, 100, 5, 0, 28};
    } else if (type == 3) {
        char_type = "Farmer";
        player_stat = {80, 50, 10, 0, 24};
    }
}
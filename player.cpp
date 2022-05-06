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
    print_file("ascii_art/character.txt");
}

void player::init() {
    print_character_art();
    get_name();
    get_char_type();
}

void player::get_name() {
    cout << "What is thy nameth?: ";
    getline(cin >> ws, name);
    cout << "Welcome " << name << ", son of Agaroth" << endl;
    cout << "Thy journey begins anew" << endl << endl;
}

void player::get_char_type() {
    cout << "Please choose your character type" << endl;
    cout << " 1. Warrior  |  2. Mage  | 3. Farmer   " << endl;
    int x;
    cin >> x;
    while (x > 3 || x < 1) {
        cout << "Wrong choice!\nPlease try again!" << endl;
        cin >> x;
        if (x == 1 || x == 2 || x == 3) {
            assign_stats(x);
            break;
        }
    }
}

void player::assign_stats(int type) {
    if (type == 1)
        player_stat = {100, 50, 5, 0, 26};
    if (type == 2)
        player_stat = {75, 100, 5, 0, 28};
    if (type == 3)
        player_stat = {80, 50, 10, 0, 24};
}
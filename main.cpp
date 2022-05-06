// Kami No Tou.cpp : This file contains the 'main' function. Program execution begins and ends here.

#include <iostream>
#include "utility.h"
#include "mainmenu.h"
#include "char_creation.h"
#include "classcreate.h"
#include "prolouge.h"
#include "chapter1.h"

using namespace std;

struct stats {
    int hp = 100;
    int mp = 50;
    int lck = 5;
    int potion = 0;
    int dmg = 20;
};

int statsdisp(stats mc) {
    cout << "HP: " << mc.hp << " MP: " << mc.mp << " Potions: " << mc.potion << endl;
    return 0;
}

int main() {
    stats mc;
    string name;
    string location[4] = {"House", "Woods", "Guild", "Tower"};
    int location1 = 0;
    print_intro();
    int charactertype = 0;
    int choice = mainmenu();
    if (choice == 1) {
        character();
        cout << "What is thy nameth (Your name?)" << endl;

        getline(cin >> ws, name);
        cout << endl;

        cout << "Welcome " << name << ", son of Agaroth" << endl;
        cout << "Thy journey begins anew" << endl << endl;

        charactertype = classtype();
        if (charactertype == 1)
            mc = {100, 50, 5, 0, 26};
        if (charactertype == 2)
            mc = {75, 100, 5, 0, 28};
        if (charactertype == 3)
            mc = {80, 50, 10, 0, 24};
        prolouge();
        chap1(location1);
        cout << endl << "You can now go to your house to restore health";
        cout << "Do you want to take a look at the quests?" << endl;

    }
}
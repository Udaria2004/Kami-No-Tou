#include "bits/stdc++.h"
#include "utility.h"
#include "player.h"

using namespace std;

int fight(player p1, int edmg, int ct) {
    print_file("ascii_art/goblin.txt"); //use the file opening function
    cout << endl;
    cout << endl << "Enemy Health: " << p1.player_stat.hp << endl << endl;
    int choice = 1; // Choice of fighting, 1 ,2 ,3 ,4
    int flag = 0;
    while (p1.player_stat.hp > 0) //if health is more than 0 keep the fight going
    {
        if (flag > 0) // already showed before hence not to show again the first time. appears next time
            cout << endl << "Enemy Health: " << p1.player_stat.hp << endl << endl;
        flag = flag + 1;
        cout << "Your turn: " << endl;
        p1.print_stats();
        cout << "1. Attack" << endl << "2. Magic" << endl << "3. Items" << endl << "4. Surrender" << endl;
        cin >> choice;
        while (choice > 4 || choice < 1) //loop for re input wrong choice
        {
            cout << endl << "Wrong choice, please input again: ";
            cin >> choice;
            if (choice == 1 || choice == 2 || choice == 3 || choice == 4) break;
        }
        if (choice == 1) //damage of attack 1
        {
            int random = rand() % 10;
            p1.player_stat.hp = p1.player_stat.hp - (p1.player_stat.damage * random);
            cout << endl << "Your attack did " << (p1.player_stat.damage * random) << " damage!" << endl;
        }
        if (choice == 2) // Restore health
        {
            int choice2;
            bool flag1 = true;
            if (p1.player_stat.mp > 20) {
                cout << endl << "1. Restore Health (MP: -25): ";
                cin >> choice2;
                while (choice2 != 1) {
                    cout << endl << "Wrong Choice, input again: ";
                    cin >> choice2;
                    if (choice2 == 1)
                        break;
                }
                cout << endl << endl;
                if (choice2 == 1) {
                    if (p1.player_stat.mp > 24) {
                        p1.player_stat.mp = p1.player_stat.mp - 25;
                        while (p1.player_stat.hp != 100)
                            p1.player_stat.hp = p1.player_stat.hp + 25;
                        if (p1.player_stat.hp > 100)
                            p1.player_stat.hp = 100;
                    }
                }
            } else cout << "Not enough Mana" << endl;
        }
        char potion_choice;
        if (choice == 3) // use potion to restore health
        {
            if (p1.player_stat.potion > 0) {
                cout << "Use potion? ";
                cin >> potion_choice;
                potion_choice = toupper(potion_choice);
                if (potion_choice == 'Y') {
                    p1.player_stat.potion = p1.player_stat.potion - 1;
                    cout << "Restored Health and MP" << endl;
                    p1.player_stat.hp = 100;
                    if (ct == 1) p1.player_stat.mp = 50;
                    if (ct == 2) p1.player_stat.mp = 100;
                    if (ct == 3) p1.player_stat.mp = 50;
                }

            } else cout << "You do not have enough potions";

        }
        if (choice == 4) // surrender
        {
            cout << "You surrendered!" << endl;
            cout << "The goblin killed you and had a satisfying meal" << endl;
            cout << "Game Over" << endl;
            exit(1);
        }
        if (p1.player_stat.hp > 0) {
            cout << endl << "Goblin's turn" << endl;
            int losthp = (rand() % 10 * 2);
            p1.player_stat.hp = p1.player_stat.hp - losthp;
            cout << "Goblin attacks you" << endl << "HP lost: " << losthp << endl;
        }
        if (p1.player_stat.hp < 1)
            cout << "You beat the goblin!" << endl;
    }
    return 0;
}
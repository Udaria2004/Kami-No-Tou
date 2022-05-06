#include "bits/stdc++.h"
#include "utility.h"
#include "player.h"

using namespace std;

int fight(player p1, int ehp) {
    print_intro();
    print_file("ascii_art/goblin.txt"); //use the file opening function
    cout << endl;
    int choice = 1; // Choice of fighting, 1 ,2 ,3 ,4
    while (true) //if health is more than 0 keep the fight going
    {
        cout << endl << "Enemy Health: " << ehp << endl << endl;
        p1.print_stats();
        cout << "Your turn (1. Attack | 2. Magic | 3. Items | 4. Surrender): ";
        cin >> choice;
        while (choice > 4 || choice < 1) //loop for re input wrong choice
        {
            cout << endl << "Wrong choice, please input again: ";
            cin >> choice;
            if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
                break;
        }
        if (choice == 1) //damage of attack 1
        {
            int random = rand() % 5;
            ehp = ehp - (p1.player_stat.damage * random);
            cout << endl << "Your attack did " << (p1.player_stat.damage * random) << " damage!" << endl;
        } else if (choice == 2) // Restore health
        {
            int choice2;
            if (p1.player_stat.mp > 20) {
                cout << endl << "1. Restore Health (MP: -25): ";
                while (true) {
                    cin >> choice2;
                    if (choice2 == 1)
                        break;
                    cout << endl << "Wrong Choice, input again: ";
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
        } else if (choice == 3) // use potion to restore health
        {
            char potion_choice;
            if (p1.player_stat.potion > 0) {
                cout << "Use potion? ";
                cin >> potion_choice;
                potion_choice = toupper(potion_choice);
                if (potion_choice == 'Y') {
                    p1.player_stat.potion--;
                    cout << "Restored Health and MP" << endl;
                    p1.player_stat.hp = 100;
                    if (p1.c_type == 1)
                        p1.player_stat.mp = 50;
                    else if (p1.c_type == 2)
                        p1.player_stat.mp = 100;
                    else if (p1.c_type == 3)
                        p1.player_stat.mp = 50;
                }

            } else cout << "You do not have enough potions" << endl;

        } else if (choice == 4) // surrender
        {
            cout << "You surrendered!" << endl;
            cout << "The goblin killed you and had a satisfying meal" << endl;
            cout << "Game Over" << endl;
            exit(1);
        }
        if (ehp > 0) {
            cout << endl << "Goblin's turn" << endl;
            int lost_hp = (rand() % 10 * 4);
            p1.player_stat.hp -= lost_hp;
            cout << "Goblin attacks you" << endl << "HP lost: " << lost_hp << endl;
        }
        if (ehp <= 0) {
            cout << "You beat the goblin!" << endl;
            break;
        }
    }
    return 0;
}
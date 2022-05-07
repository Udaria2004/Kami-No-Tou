#include "bits/stdc++.h"
#include "utility.h"
#include "player.h"

using namespace std;

int fight(player p1, int ehp) {
    int flag = 4;
    int damag;
    int edmg;
    print_intro();
    if (ehp == 60) {
        edmg = 2;
        flag = 0;
    }
    if (ehp == 100) {
        edmg = 4;
        flag = 1;
    }
    cout << endl;
    int choice = 1; // Choice of fighting, 1 ,2 ,3 ,4
    while (true) //if health is more than 0 keep the fight going
    {
        int flagMana = 0;
        int flagpotion = 0;
        int flagattack = 0;
        if (flag == 0)print_file("ascii_art/goblin.txt"); //use the file opening function
        if (flag == 1)print_file("ascii_art/ogre.txt");
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
            damag = (p1.player_stat.damage * random);
            ehp = ehp - damag;
            flagattack = 1;
        } else if (choice == 2) // Restore health
        {
            int choice2;
            if (p1.player_stat.mp > 20) {
                cout << endl << "1. Restore Health and Mana? (MP: -25): ";
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
            } else
                flagMana = 1;
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
            } else
                flagpotion = 1;
        } else if (choice == 4) // surrender
        {
            cout << endl << "You surrendered!" << endl;
            cout << "The monster killed you and had a satisfying meal" << endl;
            cout << endl << "Game Over" << endl;
            exit(1);
        }
        if (ehp > 0) {
            clear_screen();
            if (flagpotion == 1) cout << "You do not have enough potions" << endl;
            if (flagMana == 1) cout << "You do not have enough Mana" << endl;
            if (flagattack == 1) cout << endl << "Your attack did " << damag << " damage!" << endl;
            if (flag == 0) cout << "Goblin's turn" << endl;
            if (flag == 1) cout << "Ogre's turn" << endl;
            int lost_hp = (rand() % 10 * edmg);
            p1.player_stat.hp -= lost_hp;
            if (flag == 0) cout << "Goblin attacks you" << endl << "HP lost: " << lost_hp << endl;
            if (flag == 1) cout << "Ogre attacks you" << endl << "HP lost: " << lost_hp << endl;
            print_line_break();
        }
        if (p1.player_stat.hp < 1) {
            clear_screen();
            cout << "You fell unconscious and the monster had a nice meal with your body" << endl << "Game Over"
                 << endl;
            exit(1);
        }
        if (ehp <= 0) {
            clear_screen();
            cout << "You beat the monster!" << endl;
            break;
        }
    }
    return 0;
}

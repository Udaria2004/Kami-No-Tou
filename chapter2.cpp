#include "chapter2.h"
#include "utility.h"
#include "guild.h"

void house(player &p1) {
    print_line_break();
    cout << "Health Restored" << endl;
    p1.player_stat.mp = 100;
    if (p1.c_type == 1)
        p1.player_stat.mp = 50;
    if (p1.c_type == 2)
        p1.player_stat.mp = 100;
    if (p1.c_type == 3)
        p1.player_stat.mp = 50;
    print_line_break();
}

void woods(player &p1) // Fight Goblin
{
    print_line_break();
    char ch = 'H'; //input for yes or no
    int flag = 0; // flag for death of goblin
    int choice2 = 1; // choice for option 2
    string line;
    srand(time(NULL)); // random funp1.c_typeion
    int x = rand() % 11; // Multiply the damage by whatever numbers come under 10
    int escape = rand() % 2; // 50% chance
    if (x > 5) {
        cout << "A goblin appears!" << endl;
        cout << "Would you rather!" << endl << endl << "Y. Fight or N. Escape ";
        cin >> ch;
        ch = toupper(ch);
        if (ch == 'Y') {
            int ehp = 60; //Health
            int edamage = 2; //Damage of Goblin
            slow_print_file("story/chap2_2.txt", 50);
            cout << endl << "Enemy Health: " << ehp << endl << endl;
            int choice = 1; // Choice of fighting, 1 ,2 ,3 ,4
            int flag = 0;
            while (ehp > 0) //if health is more than 0 keep the fight going
            {
                if (flag > 0) // already showed before hence not to show again the first time. appears next time
                    cout << endl << "Enemy Health: " << ehp << endl << endl;
                flag = flag + 1;
                cout << "Your turn: " << endl;
                p1.print_stats(); // use display stat funp1.c_typeion
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
                    ehp = ehp - (p1.player_stat.damage * random);
                    cout << endl << "Your attack did " << (p1.player_stat.damage * random) << " damage!" << endl;
                }
                if (choice == 2) // Restore health
                {
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
                        if (choice2 == 1)
                            if (p1.player_stat.mp > 24) {
                                p1.player_stat.mp = p1.player_stat.mp - 25;
                                while (p1.player_stat.hp != 100)
                                    p1.player_stat.hp = p1.player_stat.hp + 25;
                                if (p1.player_stat.hp > 100)
                                    p1.player_stat.hp = 100;
                            }
                    } else cout << "Not enough Mana" << endl;
                }
                char potionchoice;
                if (choice == 3) // use potion to restore health
                {
                    if (p1.player_stat.potion > 0) {
                        cout << "Use potion? ";
                        cin >> potionchoice;
                        potionchoice = toupper(potionchoice);
                        if (potionchoice == 'Y') {
                            p1.player_stat.potion = p1.player_stat.potion - 1;
                            cout << "Restored Health and MP" << endl;
                            p1.player_stat.hp = 100;
                            if (p1.c_type == 1) p1.player_stat.mp = 50;
                            if (p1.c_type == 2) p1.player_stat.mp = 100;
                            if (p1.c_type == 3) p1.player_stat.mp = 50;
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
                if (ehp > 0) {
                    cout << endl << "Goblin's turn" << endl;
                    int losthp = (rand() % 10 * 2);
                    p1.player_stat.hp = p1.player_stat.hp - losthp;
                    cout << "Goblin attacks you" << endl << "HP lost: " << losthp << endl;
                }
                if (ehp < 1)
                    cout << "You beat the goblin!" << endl;
            }
        } else // if u decided to run away, 2 options
        {
            if (escape == 1) {
                cout << "Escape successful" << endl << "You lost 0 hp!" << endl;
                flag = 1;
            } else {
                cout << "Escape failed" << endl;
                cout << "You lost 50 hp" << endl;
                p1.player_stat.hp = p1.player_stat.hp - 50;
                ifstream fin;
            }
        }
    } else //if no monsters found
    {
        cout << "No monsters found" << endl;
        cout << "Would you like to search for items?" << endl;
        cin >> ch;
        ch = toupper(ch);
        if (ch == 'Y') {
            if (x > 4) {
                cout << "You found a potion" << endl;
                p1.player_stat.potion++;
            } else {
                cout << "Sorry, you found nothing :(" << endl;
                flag = 1;
            }
        } else
            cout << "Returning home" << endl;
    }
    if (flag == 1) //flag for defeating goblin
        cout << "Returning home" << endl;
    print_line_break();
}

void chap2(player &p1) {
    print_intro();
    slow_print("Chapter 2", 100);
    cout << endl << endl;
    slow_print_file("story/chap2_1.txt", 50);
    cout << endl;
    pause();
    while (true) {
        p1.get_location();
        if (p1.location == 0) //house
            house(p1);
        if (p1.location == 1) //forest
            woods(p1);
        if (p1.location == 2) //guild
        {
            if (!p1.guild_quest)
                guild(p1);
            else
                cout << "You already accepted the quest!" << endl;
        }
    }
}
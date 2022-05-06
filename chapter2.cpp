#include "chapter2.h"
#include "utility.h"

void print_chapter() {
    print_intro();
    slow_print("Chapter 2", 100);
    cout << endl << endl;
    slow_print_file("story/chap2_1.txt", 50);
    cout << endl;
    pause();
}

int house(stats &mc, int ct) {
    print_line_break();
    cout << "Health Restored" << endl;
    mc.hp = 100;
    if (ct == 1) mc.mp = 50;
    if (ct == 2) mc.mp = 100;
    if (ct == 3) mc.mp = 50;
    print_line_break();
    return 0;
}

int woods(stats &mc, int ct) // FIght Goblin
{
    print_line_break();
    char ch = 'H'; //input for yes or no
    int flag = 0; // flag for death of goblin
    int choice2 = 1; // choice for option 2
    string line;
    srand(time(NULL)); // random function
    int x = rand() % 11; // Multiply the damage by whatever numbers come under 10
    int escape = rand() % 2; // 50% chance
    if (x > 5) {
        cout << "A goblin appears!" << endl;
        cout << "Would you rather!" << endl << endl << "Y. Fight or N. Escape ";
        cin >> ch;
        ch = toupper(ch);
        if (ch == 'Y') {
            int ehp = 60; //Health
            int edmg = 2; //Damage of Goblin
            slow_print_file("story/chap2_2.txt", 50);
            cout << endl << "Enemy Health: " << ehp << endl << endl;
            int choice = 1; // Choice of fighting, 1 ,2 ,3 ,4
            int flag = 0;
            while (ehp > 0) //if health is more than 0 keep the fight going
            {
                if (flag > 0) // already showed before hence not to show again the first time. appears next time
                {
                    cout << endl << "Enemy Health: " << ehp << endl << endl;
                }
                flag = flag + 1;
                cout << "Your turn: " << endl;
                statsdisp(mc); // use display stat function
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
                    ehp = ehp - (mc.dmg * random);
                    cout << endl << "Your attack did " << (mc.dmg * random) << " damage!" << endl;
                }
                if (choice == 2) // Restore health
                {
                    bool flag1 = true;
                    if (mc.mp > 20) {
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
                            if (mc.mp > 24) {
                                mc.mp = mc.mp - 25;
                                while (mc.hp != 100) {
                                    mc.hp = mc.hp + 25;
                                }
                                if (mc.hp > 100) {
                                    mc.hp = 100;
                                }
                            }

                        }
                    } else cout << "Not enough Mana" << endl;
                }
                char potionchoice;
                if (choice == 3) // use potion to restore health
                {
                    if (mc.potion > 0) {
                        cout << "Use potion? ";
                        cin >> potionchoice;
                        potionchoice = toupper(potionchoice);
                        if (potionchoice == 'Y') {
                            mc.potion = mc.potion - 1;
                            cout << "Restored Health and MP" << endl;
                            mc.hp = 100;
                            if (ct == 1) mc.mp = 50;
                            if (ct == 2) mc.mp = 100;
                            if (ct == 3) mc.mp = 50;
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
                    mc.hp = mc.hp - losthp;
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
                mc.hp = mc.hp - 50;
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
                mc.potion++;
            } else {
                cout << "Sorry, you found nothing :(" << endl;
                flag = 1;
            }
        } else
            cout << "Returning home" << endl;
    }
    if (flag == 1) //flag for defeating goblin
        cout << "Returning home" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    return 0;
}

void chap2(player &p1) {
    print_chapter();
    p1.get_location();

}
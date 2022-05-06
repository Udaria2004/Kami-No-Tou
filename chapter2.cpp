#include "chapter2.h"
#include "utility.h"
#include "guild.h"
#include "fight.h"
#include "chapter3.h"

void house(player &p1) {
    print_line_break();
    cout << "Welcome home!\nHealth Restored" << endl;
    p1.player_stat.mp = 100;
    if (p1.c_type == 1)
        p1.player_stat.mp = 50;
    if (p1.c_type == 2)
        p1.player_stat.mp = 100;
    if (p1.c_type == 3)
        p1.player_stat.mp = 50;
}

void woods(player &p1) // Fight Goblin
{
    print_line_break();
    char ch = 'H'; //input for yes or no
    int ehp = 60; //Health
    int edamage = 2; //Damage of Goblin
    string line;
    srand(time(NULL)); // random funp1.c_typeion
    int x = rand() % 10; // Multiply the damage by whatever numbers come under 10
    if (x > 5) {
        cout << "A goblin appears!" << endl;
        cout << "Would you rather!" << endl << endl << "Fight (Y) or Escape: ";
        cin >> ch;
        ch = toupper(ch);
        if (ch == 'Y') {
            print_intro();
            slow_print_file("story/chap2_2.txt", 50);
            pause();
            fight(p1, ehp, edamage);
        } else {
            cout << "Returning home" << endl;
            p1.location = 0;
        }
    } else //if no monsters found
    {
        cout << "No monsters found" << endl;
        cout << "Would you like to search for items? ";
        cin >> ch;
        cout << endl << endl;
        ch = toupper(ch);
        if (ch == 'Y') {
            if (x > 4) {
                cout << "You found a potion" << endl;
                p1.player_stat.potion++;
            } else {
                cout << "Sorry, you found nothing :(" << endl;
            }
        }
        cout << "Returning home" << endl;
        p1.location = 0;
    }
}

void chap2(player &p1) {
    print_intro();
    slow_print("Chapter 2", 100);
    cout << endl << endl;
    slow_print_file("story/chap2_1.txt", 50);
    pause();
    while (true) {
        print_intro();
        p1.get_location(true);
        if (p1.location == 0)
            house(p1);
        else if (p1.location == 1)
            woods(p1);
        else if (p1.location == 2) {
            if (!p1.guild_quest)
                guild(p1);
            else
                cout << "You already accepted the quest!" << endl;
        } else if (p1.location == 3) {
            chap3(p1);
            break;
        }
        pause();
    }
}
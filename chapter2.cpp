#include "chapter2.h"
#include "utility.h"
#include "guild.h"
#include "fight.h"
#include "chapter3.h"

void house(player &p1) {   //House :- Restore health of player
    print_intro();
    cout.flush();
    print_file("ascii_art/house.txt");
    cout << "\n\nWelcome home!\nHealth and Mana Restored" << flush << endl;
    p1.player_stat.mp = 100;
    if (p1.c_type == 1)
        p1.player_stat.mp = 50;
    if (p1.c_type == 2)
        p1.player_stat.mp = 100;
    if (p1.c_type == 3)
        p1.player_stat.mp = 50;
    cin.ignore();
    prog_pause();
    print_intro();
}

void woods(player &p1) // Fight Goblin
{
    print_intro();
    print_file("ascii_art/forest.txt");
    cout << endl << endl;
    char ch = 'H'; //input for yes or no
    int ehp = 60; //Health of enemy
    string line;
    srand(time(NULL)); // random funp1.c_typeion
    int escape = rand() % 2;        // Random escape encouter
    int x = rand() % 10; // Random chance of fighting monster
    if (x > 3) {
        cout << "A goblin appears!" << endl;
        cout << "Would you rather!" << endl << endl << "Fight (Y) or Escape: ";
        cin >> ch;
        ch = toupper(ch);
        if (ch == 'Y') {
            print_intro();
            fight(p1, ehp);  //Fight Simulation
            cout << "Returning home" << endl;
            p1.location = 0;
        } else {
            if (escape == 1)
                cout << "\nEscape successful!" << endl << "You lost 0 hp!" << endl;
            else {
                cout << "\nYou escaped but not without major injuries :(" << endl;
                cout << "You lost 50hp!" << endl;
                p1.player_stat.hp = p1.player_stat.hp - 50;
            }
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
        cout << "Escaped successfully" << endl << "Returning home" << endl;
        p1.location = 0;
    }
    cin.ignore();
    prog_pause();
    print_intro();         //Game Formatting
}

void chap2(player &p1) {
    slow_print("Chapter 2", 100);
    cout << endl << endl;
    slow_print_file("story/chap2_1.txt", 50);
    prog_pause();
    print_intro();
    while (true) {             //loop the location so player can go to different locations
        p1.get_location(true);
        if (p1.location == 0) {
            house(p1);
        } else if (p1.location == 1) {
            woods(p1);
        } else if (p1.location == 2) {
            if (!p1.guild_quest)
                guild(p1);
            else
                cout << "You already accepted the quest!" << endl;
        } else if (p1.location == 3) {
            if (!p1.guild_quest) {
                p1.location = 0;
                cout << "\nHead back to the Guild to accept the quest!\nReturning home" << endl;
            } else {
                chap3(p1);
                break;
            }
            cin.ignore();
            prog_pause();
        }
    }
}

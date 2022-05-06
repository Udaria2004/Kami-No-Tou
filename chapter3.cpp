#include "bits/stdc++.h"
#include "utility.h"
#include "player.h"
#include "fight.h"

using namespace std;

void chap3(player &p1) {
    print_intro();
    slow_print("Chapter 3", 100);
    cout << endl << endl;
    slow_print_file("story/chap3_1.txt", 50);
    pause();
    srand(time(NULL));
    int x = rand() % 11; // Multiply the damage by whatever numbers come under 10
    int chance = rand() % 3;
    int ehp = 100;
    int edmg = 3;
    char ch;
    do {
        if (x > 5) {
            print_intro();
            cout << "While climbing, an ogre appears!" << endl;
            cout << "Would you rather!" << endl << endl << "Fight (Y) or Escape: ";
            cin >> ch;
            ch = toupper(ch);
            if (ch == 'Y') {
                fight(p1, ehp, edmg); //fight the goblin
            } else // if u decided to run away, 2 options
            {
                int escape = rand() % 2; // 50% chance
                if (escape == 1) {
                    cout << "Escape successful" << endl << "You lost 0 hp!" << endl;
                } else {
                    cout << "Escape failed" << endl;
                    cout << "You lost 25 hp" << endl;
                    p1.player_stat.hp = p1.player_stat.hp - 25;
                }
            }
        }
    } while (chance-- > 0);
    cout << "Finally after defeating the minions, you reached the top of the tower." << endl;
    cout << "You regretted not exercising enough to increase your stamina. "
            "You were sure you lost around 50 pounds or somewhere around that much" << endl;
    cout << "Masked Man: Welcome to my humble abode, " << p1.name
         << ". I have been waiting for you, for quite some time now." << endl << "How is " << p1.name << "oth doing?";
    cout << "How do you know my name?? Who told you about my mother??" << endl
         << "ANSWER ME! OR I SHALL STRIKE YOU DOWN WHERE YOU STAND!!! " << endl;
    cout << "Masked Man: Muahhahahaahah, you must complete my minigame before you have your way with me. "
            "MUAHAHAHAHA *leaves to a secret room*" << endl;
    cout << "You must complete the minigame to defeat the evil maniac!" << endl;

}
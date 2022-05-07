#include "bits/stdc++.h"
#include "utility.h"
#include "player.h"
#include "fight.h"
#include <unistd.h>

#define test_chance 5

using namespace std;

void test1() {                                  //Minigame #1
    print_intro();
    slow_print("\nTest 1\n", 100);
    slow_print_file("story/test1.txt", 50);  
    int ans, count = 1;;
    while (count++ < test_chance) {
        cout << endl << "Answer: ";
        cin >> ans;
        if (ans == 141) {
            count = -1;
            break;
        }
        cout << endl << "alas be careful! only " << test_chance - count << " chances remaining" << endl;
    }
    if (count == -1)
        cout << endl << "Congratulations thee hath passed the first testeth" << endl;
    else {
        cout << endl << "You came so far. Better luck next time!" << endl;
        exit(1);
    }
    prog_pause();
}

void test2() {                                     //Minigame #2
    print_intro();
    slow_print("\nTest 2\n", 100);
    slow_print_file("story/test2.txt", 50);
    int ans, count = 1;;
    while (count++ < test_chance) {
        cout << endl << "Answer: ";
        cin >> ans;
        if (ans == 24) {
            count = -1;
            break;
        }
        cout << endl << "Alas be careful! Only " << test_chance - count << " chances remaining" << endl;
    }
    if (count == -1)
        cout << endl << "Congratulations thee hath passed the second testeth" << endl;
    else {
        cout << endl << "You came so far. Better luck next time!" << endl;
        exit(1);
    }
    prog_pause();
}

void chap3(player &p1) {
    print_intro();
    slow_print("Chapter 3", 100);         //Chapter 3
    cout << endl << endl;
    slow_print_file("story/chap3_1.txt", 50);
    int flag = 0;
    srand(time(NULL));
    int x = rand() % 11; // Random damage multiplier 
    int chance = rand() % 4; // Random encouter with monster
    int ehp = 100;  // enemy health
    char ch;
    do {
        if (x > 2) {
            flag = 1;
            cout << "\nWhile climbing, an ogre appears!" << endl;
            cout << "Would you rather!" << endl << endl << "Fight (Y) or Escape: ";
            cin >> ch;
            ch = toupper(ch);
            if (ch == 'Y') {
                fight(p1, ehp); //fight the goblin
            } else // if u decided to run away, 2 options
            {
                int escape = rand() % 2; // 50% chance
                if (escape == 1) {
                    cout << "Escape successful" << endl << "You lost 0 hp!" << endl;
                } else {
                    cout << "Escape failed" << endl;
                    cout << "You lost 25 hp" << endl;
                    p1.player_stat.hp = p1.player_stat.hp - 25;
                    if (p1.player_stat.hp <= 0) {
                        cout << "Sad life. You died. Game over\n";
                        exit(1);
                    }
                }
            }

        }
    } while (chance-- > 0);
    prog_pause();
    print_intro();
    slow_print("\nEpilogue\n", 100);  
    if (flag == 1) cout << "Finally after defeating the minions, you reached the top of the tower." << endl;
    else
        cout
                << "You were lucky that you did not meet any monsters while ascending the tower. You finally reached the top but....."
                << endl;
    cout << "You regretted not exercising enough to increase your stamina. "
            "You were sure you lost around 50 pounds or somewhere around that much\n \n" << endl;
    print_file("ascii_art/masked_man.txt");
    cout << "Masked Man: Welcome to my humble abode, " << p1.name
         << ". I have been waiting for you, for quite some time now." << endl << "How is " << p1.name << "oth doing?\n";
    cout << "\nHow do you know my name?? Who told you about my mother??" << endl
         << "ANSWER ME! OR I SHALL STRIKE YOU DOWN WHERE YOU STAND!!!\n" << endl;
    cout << "Masked Man: Muahhahahaahah, you must complete my tests before you have your way with me. "
            "MUAHAHAHAHA *leaves to a secret room*" << endl;
    cout << "\nYou must complete the tests to defeat the evil maniac!" << endl << endl;
    prog_pause();
    clear_screen();
    test1();
    test2();
    print_intro();
    slow_print_file("story/chap3_2.txt", 50);
    print_file("ascii_art/unmasked_man.txt");
    prog_pause();
}
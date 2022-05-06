#include "bits/stdc++.h"
#include "utility.h"
#include "player.h"
#include "fight.h"

using namespace std;

void chap3(player &p1) {
    print_intro();
    slow_print("Chapter 2", 100);
    cout << endl << endl;
    slow_print_file("story/chap2_1.txt", 50);
    cout << endl;
    pause();
    srand(time(NULL));
    int x = rand() % 11; // Multiply the damage by whatever numbers come under 10
    int escape = rand() % 2; // 50% chance
    int chance = 3;
    int ehp = 100;
    int edmg = 3;
    char ch;
    cout << "You say goodbye to your loved ones as you head out for your quest." << endl;
    cout << "You wonder who is this mad man thinking of taking over the world, while you walk towards the destination."
         << endl;
    cout << "Most adventurers would have taken a horse. But you did not... more like you couldn't afford one." << endl;
    cout
            << "But you were hopeful that you would get a huge sum from this quest and would get promoted to a higher rank."
            << endl;
    cout << "After a long ass journey which seemed like forever, you got to the outskirts of the premises." << endl;
    cout
            << "Slowly, but surely, you made your finally made it to the Tower. It was massive beyond anything you had seen."
            << endl;
    cout
            << "The entrance was barricaded by 2 large doors. Honestly, it seemed like orges live here. You weren't sure if you should step inside or not"
            << endl;
    cout << "Mustering your courage, you make your way toward the girnomous doors and open it." << endl;
    cout
            << "Upon entering, you observed that a rather pungent odour was coming from deep inside the tower. You also noticed that there were stairs leading up. Obviously the villian would be at the top"
            << endl;
    cout << "You start climbing stairs. " << endl;
    do {
        chance--;
        if (x > 5) {
            cout << " While climbing, an orge appears!" << endl;
            cout << "Would you rather!" << endl << endl << "Y. Fight or N. Escape ";
            cin >> ch;
            ch = toupper(ch);
            if (ch == 'Y') {
                fight(p1, ehp, edmg); //fight the goblin
            } else // if u decided to run away, 2 options
            {
                if (escape == 1) {
                    cout << "Escape successful" << endl << "You lost 0 hp!" << endl;
                } else {
                    cout << "Escape failed" << endl;
                    cout << "You lost 25 hp" << endl;
                    p1.player_stat.hp = p1.player_stat.hp - 25;
                }
            }
        }

    } while (chance > 0);

    cout << "Finally after defeating the minions, you reached the top of the tower." << endl;
    cout
            << "You regretted not exercising enough to increase your stamina. You were sure you lost around 50 pounds or somewhere around that much"
            << endl;
    cout << "Masked Man: Welcome to my humble abode, " << p1.name
         << ". I have been waiting for you, for quite some time now." << endl << "How is " << p1.name << "oth doing?";
    cout << "How do you know my name?? Who told you about my mother??" << endl
         << "ANSWER ME! OR I SHALL STRIKE YOU DOWN WHERE YOU STAND!!! " << endl;
    cout
            << "Masked Man: Muahhahahaahah, you must complete my minigame before you have your way with me. MUAHAHAHAHA *leaves to a secret room*"
            << endl;
    cout << "You must complete the minigame to defeat the evil maniac!" << endl;

}
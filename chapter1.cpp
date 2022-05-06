#include "bits/stdc++.h"
#include "chapter1.h"
#include "utility.h"
#include "player.h"
#include "chapter2.h"

using namespace std;

void chap1(player &p1) {
    print_intro();
    slow_print("Chapter 1", 100);
    cout << endl << endl;
    slow_print_file("story/chap1_1.txt", 50);
    pause();
    print_intro();
    p1.get_location(true);
    while (p1.location != 2) {
        p1.location = 0;
        cout << "You were supposed to go the guild first!" << endl;
        p1.get_location(false);
    }
    print_intro();
    slow_print("You arrive at the guild and are greeted by the guilds manager\n\n", 50);
    print_file("ascii_art/guild.txt");
    cout << "\nWelcome, are you here to sign to become an adventurer?\n";
    cout << endl << "Hint: Press Y for positive interactions and N for negative interactions" << endl;
    char ch = 'Y';
    cin >> ch;
    ch = toupper(ch);
    cout << endl;
    switch (ch) {
        case 'Y':
            cout << "Ah you came just on time" << endl;
            break;
        case 'N':
            cout << "I swear, I heard the blacksmiths tell me that you bought weapons recently because you couldn't "
                    "wait to become an adventurer" << endl;
            break;
        default :
            cout << "Huh, what was that?" << endl;
    }
    pause();
    print_intro();
    cout << endl << "Well, anyways here is your certificate" << endl << endl;
    print_file("ascii_art/certificate.txt");
    cout << endl;
    slow_print_file("story/chap1_2.txt", 50);
    pause();
    chap2(p1);
}
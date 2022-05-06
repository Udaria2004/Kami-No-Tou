#include "bits/stdc++.h"
#include "chapter1.h"
#include "utility.h"
#include "player.h"
#include "chapter2.h"

using namespace std;

void print_chapter() {
    print_intro();
    slow_print("Chapter 1", 100);
    cout << endl << endl;
    slow_print_file("story/chap1_1.txt", 50);
    cout << endl;
    pause();
}

void chap1(player &p1) {
    print_chapter();
    p1.get_location();
    while (p1.location != 2) {
        cout << "You were supposed to go the guild first!" << endl;
        p1.get_location();
    }
    print_intro();
    slow_print("You arrive at the guild and are greeted by the guilds manager\n", 50);
    print_file("ascii_art/guild.txt");
    slow_print("Welcome, are you here to sign to become an adventurer?\n", 50);
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
            cout << "I swear i heard the blacksmiths tell me that you bought weapons recently because you couldn't "
                    "wait to become an adventurer" << endl;
            break;
        default :
            cout << "Huh, what was that?" << endl;
    }
    pause();
    cout << endl << "Well, anyways here is your certificate" << endl << endl;
    print_file("ascii_art/certificate.txt");
    cout << endl;
    slow_print_file("story/chap1_2.txt", 50);
    pause();
    chap2(p1);
}
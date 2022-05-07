#include "bits/stdc++.h"
#include "chapter1.h"
#include "utility.h"
#include "player.h"
#include <unistd.h>
#include "chapter2.h"

using namespace std;

void chap1(player &p1) {                                 
    print_intro();
    slow_print("Chapter 1", 100);
    cout << endl << endl;
    slow_print_file("story/chap1_1.txt", 50);             //File input/output
    prog_pause();
    print_intro();
    p1.get_location(true);
    while (p1.location != 2) {
        p1.location = 0;
        cout << endl << "You were supposed to go the guild first!" << endl;
        p1.get_location(false);
    }
    print_intro();
    slow_print("You arrive at the guild and are greeted by the guilds manager\n\n", 50);
    print_file("ascii_art/guild.txt");
    slow_print("\nWelcome, are you here to sign to become an adventurer?\n", 50);
    cout << endl << "Hint: Press Y for positive interactions and N for negative interactions" << endl;
    char ch = 'a';
    cin >> ch;
    ch = toupper(ch);
    cout << endl;
    switch (ch) {
        case 'Y':
            slow_print("\nAh you came just on time\n\n", 50);
            break;
        case 'N':
            slow_print(
                    "\nI swear, I heard the blacksmiths tell me that you bought weapons recently because you couldn't wait to become an adventurer\n\n",
                    50);
            break;
        default :
            cout << "Huh, what was that?" << endl;
    }
    slow_print("Well, anyways here is your certificate\n\n", 50);
    print_file("ascii_art/certificate.txt");
    slow_print("\nCongratulations! You are a noobie ranked adventurer!", 50);
    cin.ignore();
    prog_pause();
    print_intro();
    chap2(p1);  // Lead to chapter two
}

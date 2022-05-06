#include "bits/stdc++.h"
#include "chapter1.h"
#include "utility.h"

using namespace std;

void chap1(int &location1) {
    vector<string> location = {"House", "Woods", "Guild", "Tower"};
    print_line_break();
    print_file("ascii_art/location.txt");
    print_line_break();
    cout << "Current Location: " << location[location1] << endl;
    cout << endl;
    cout << "Where to? " << flush;
    cin >> location1;
    cout << endl;
    while (location1 != 2) {
        if (location1 == 0)
            cout << "You are already at home" << endl;
        else
            cout << endl << "You were supposed to go the guild!" << endl;
        cin >> location1;
        if (location1 == 2) break;
    }
    cout << endl;
    cout << "-----------------------------------------------------------------------------" << endl << endl;
    cout << "You arrive at the guild and are greeted by the guilds manager" << endl;
    print_file("ascii_art/guild.txt");
    cout << endl << "Welcome, are you here to sign to become an adventurer?" << endl;
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
            cout
                    << "I swear i heard the blacksmiths tell me that you bought weapons recently because you couldn't wait to become an adventurer"
                    << endl;
            break;
        default :
            cout << "Huh, what was that?" << endl;
    }
    for (double i = 0; i < 999999000; i++) {
    }
    cout << endl << "Well, anyways here is your certificate" << endl;
    print_file("ascii_art/certificate.txt");
    cout << endl;
    cout << "I suggest that you start practicing at the woods before taking any quests.";
    cout << endl << "You can now go to your house to restore health or go to the forest to practice!";
    cout << endl << "If you want to take a quest, you can go talk to me again later" << endl;
    cout << "Thank you for taking your time at the adventurers guild. We hope you the very best. Au Revoir!" << endl;
    cout << endl << "End of conversation" << endl
         << "-----------------------------------------------------------------------------" << endl;
    cout << "Enter c to continue...." << endl << endl;
    char c = 'a';
    cin >> c;
    while (c != 'c') {
        cout << "Did you mean to press 'c'" << endl;
        cin >> c;
        if (c == 'c') break;
    }
    if (c == 'c') {
        cout << endl << "-----------------------------------------------------------------------------" << endl;
    }
}
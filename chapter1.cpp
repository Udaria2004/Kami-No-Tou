#include "chapter1.h"
#include "utility.h"
#include "bits/stdc++.h"

using namespace std;

int chap1(int &location1) {
    string location[4] = {"House", "Woods", "Guild", "Tower"};
    print_file("ascii_art/location.txt");
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Current Location:" << location[location1] << endl;
    cout << endl;
    cout << "Move to which location" << endl;
    cin >> location1;
    while (location1 != 2) {
        cout << "You were supposed to go the guild!" << endl;
        cin >> location1;
        if (location1 == 2) break;
    }
    cout << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "You arrive at the guild and are greeted by the guilds manager" << endl;
    print_file("ascii_art/guild.txt");
    cout << endl << "Welcome, are you here to sign to become an adventurer?" << endl;
    cout << "Yes or No" << endl;
    cout << "Hint: Press Y for positive interactions and N for negative interactions" << endl;
    char ch = 'Y';
    cin >> ch;
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
            cout << "Huh what was that?" << endl;
    }
    cout << "Well, anyways here is your certificate" << endl;
    print_file("ascii_art/certificate.txt");
    cout << endl;
    cout << endl;
    cout << "I suggest that you start practicing at the woods before taking any quests.";
    cout << endl << "End of conversations" << endl
         << "-----------------------------------------------------------------------------" << endl;
    cout << endl << "Where do you want to go" << endl;
    print_file("ascii_art/locations.txt");
    cout << endl;
    cin >> location1;
    return 0;
}
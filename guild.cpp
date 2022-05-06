#include "prologue.h"
#include "utility.h"
#include "bits/stdc++.h"

using namespace std;

void guild(player &p1) {
    print_intro();
    print_file("ascii_art/guild.txt");
    cout << endl << "Welcome back!" << endl << "Do you want to accept the quest? ";
    char ch;
    cin >> ch;
    ch = toupper(ch);
    if (ch == 'Y') {
        slow_print_file("story/guild.txt", 50);
        p1.guild_quest = true;
    } else
        cout << "You can come back another time";
}
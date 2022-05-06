#include "utility.h"
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void print_intro() {
    clear_screen();
    print_file("ascii_art/intro.txt");
}

void clear_screen() {
    cout << "\033[2J\033[1;1H";
}

void slow_print(const string &text, int speed) {
    for (auto i: text) {
        cout << i;
        cout.flush();
        usleep(speed * 1000);
    }
}

void print_line_break() {
    cout << string(100, '-') << endl;
}

void pause() {
    cout << "Press Enter to Continue";
    cin.ignore();
}

void print_file(const string &path) {
    ifstream fin;
    fin.open(path);
    if (fin.fail()) {
        cout << "Error in opening the file" << endl;
        exit(1);
    }
    string line;
    while (getline(fin, line))
        cout << line << endl;
    fin.close();
}
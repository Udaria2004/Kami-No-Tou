#include "utility.h"
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void print_intro() {
    clear_screen();
    print_file("ascii_art/intro.txt");
}

void clear_screen() {
    cout << "\x1B[3J\x1B[H";
}

void slow_print(const string &text, int speed) {
    for (auto i: text) {
        cout << i;
        cout.flush();
        usleep(speed);
    }
}

void line_break() {
    cout << string(100, '-') << endl;
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
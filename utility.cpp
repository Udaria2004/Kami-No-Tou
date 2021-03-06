#include "utility.h"
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void print_intro() {  //prints introduction
    clear_screen();
    print_file("ascii_art/intro.txt");
    cout << endl;
}

void clear_screen() {                  //formatting the screen output
    cout << "\033[2J\033[1;1H";
}

void slow_print(const string &text, int speed) {   //formatting screen output
    for (auto i: text) {
        cout << i;
        cout.flush();
        usleep(speed * 800);
    }
}

void print_line_break() {
    cout << endl << string(80, '-') << endl;
}

void prog_pause() {
    cout << flush << "\nPress Enter to Continue";
    cin.sync();                                                          //pause the program
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void print_file(const string &path) {
    ifstream fin;
    fin.open(path);
    if (fin.fail()) {
        cout << "Error in opening the file" << endl;                    // print the file
        exit(1);
    }
    string line;
    while (getline(fin, line))
        cout << line << endl;
    fin.close();
}

void slow_print_file(const string &path, int speed) {
    ifstream fin;
    fin.open(path);
    if (fin.fail()) {
        cout << "Error in opening the file" << endl;
        exit(1);
    }
    string line;
    while (getline(fin, line)) {
        slow_print(line, speed);
        cout << endl;
    }
    fin.close();
}

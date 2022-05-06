#include "utility.h"
#include <bits/stdc++.h>

using namespace std;

void print_intro() {
    clear_screen();
    ifstream fin;
    fin.open("intro.txt");
    if (fin.fail()) {
        cout << "Error in opening the file" << endl;
        exit(1);
    }
    string line;
    string read;
    while (getline(fin, line))
        cout << line << endl;
    fin.close();
}

void clear_screen() {
    system("clear");
}
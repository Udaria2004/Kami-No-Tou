#include "prologue.h"
#include "utility.h"
#include "chapter1.h"
#include <iostream>

using namespace std;

void prologue(player &p1) {
    print_intro();
    slow_print("Prologue", 100);
    cout << endl << endl;
    slow_print_file("story/prologue.txt", 50);
    prog_pause();
    chap1(p1);  //Leads to chapter 1
}

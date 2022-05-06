#include "prologue.h"
#include "utility.h"
#include "chapter1.h"

using namespace std;

void prologue(player &p1) {
    print_intro();
    slow_print("Prologue", 100);
    cout << endl << endl;
    slow_print_file("story/prologue.txt", 50);
    pause();
    chap1(p1);
}
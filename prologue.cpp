#include "prologue.h"
#include "utility.h"

using namespace std;

void prologue() {
    print_intro();
    slow_print("Prologue", 200);
    cout << endl << endl;
    slow_print_file("story/prologue.txt", 50);
    cout << endl;
}
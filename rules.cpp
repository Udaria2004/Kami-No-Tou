#include "rules.h"
#include "utility.h"
#include "main_menu.h"

using namespace std;

void print_rules() {
    print_intro();
    slow_print("Rules", 400);
    cout << "Thee wanteth to knoweth m're about the game, I seeth" << endl;
    cout << endl;
    pause();
    print_intro();
    main_menu();
}
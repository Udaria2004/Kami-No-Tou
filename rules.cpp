#include "rules.h"
#include "utility.h"
#include "main_menu.h"

using namespace std;

void print_rules() {
    print_intro();
    slow_print("Thee wanteth to knoweth m're about the game, I seeth", 200);
    cout << endl;
    print_file("story/rules.txt");
    pause();
    print_intro();
    main_menu();
}
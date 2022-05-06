#include "utility.h"
#include "main_menu.h"
#include "player.h"

using namespace std;

int main() {
    cout << "\e[8;30;130t";
    print_intro();
    main_menu();
}
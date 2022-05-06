#include <iostream>
#include "utility.h"
#include "main_menu.h"
#include "prologue.h"
#include "chapter1.h"
#include "player.h"

using namespace std;

int main() {
    player p1;
    string location[4] = {"House", "Woods", "Guild", "Tower"};
    int location1 = 0;
    print_intro();
    int choice = main_menu();
    if (choice == 1) {
        p1.init();
        prolouge();
        chap1(location1);
        cout << endl << "You can now go to your house to restore health";
        cout << "Do you want to take a look at the quests?" << endl;
    }
}
#include <iostream>
#include "mainmenu.h"
using namespace std;

int mainmenu()
{
	cout << "1. New Game" << endl;
	cout << "2. Load Game" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter your choice" << endl;
	int x;
	cin >> x;
	cout << endl;
	switch (x)
	{
		case 1:
			cout << "Transporting you to another world" << endl;
			break;
		case 2:
			cout << "Wake up!" << endl;
			cout << "You still have not completed your mission!" << endl;
			break;
		case 3:
			cout << "Exiting" << endl;
			exit(1);
			break;
		default :
			cout << "Wrong Choice! Please open up the game again" << endl;
	}
	return x;

}
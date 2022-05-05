#include <iostream>
#include "classcreate.h"
using namespace std;

int classtype()
{
	cout << "Please choose your character type" << endl;
	cout << " 1. Warrior  |  2. Mage  | 3. Farmer   " << endl;
	int x = 0;
	cin >> x;
	while (x > 3 || x < 1)
	{
		cout << "wrong choice!" << endl;
		cout << "Please try again!" << endl;
		cin >> x;
		if (x == 1 || x == 2 || x == 3)
			break;
	}
	cout << endl;
	return x;

}

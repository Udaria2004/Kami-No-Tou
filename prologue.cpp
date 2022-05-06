#include <iostream>
#include "prologue.h"
#include <fstream>
#include <string>
using namespace std;

int prolouge() 
{
	ifstream fin;
	fin.open("prolouge.txt");

	if (fin.fail())
	{
		cout << "Error in opening the file" << endl;
		exit(1);
	}

	string line;
	string read;
	while (getline(fin, line))
	{
		cout << line << endl;
	}
	fin.close();
	return 0;
}
#include <iostream>
#include "ccreation.h";
#include <fstream>;
#include <string>;
using namespace std;

int character()
{
	ifstream fin;
	fin.open("character.txt");
	if (fin.fail())
	{
		cout << "Error in opening the file" << endl;
		exit(1);
	}
	string line;
	while (getline(fin, line))
	{
		cout << line << endl;
	}
	fin.close();
	return 0;
}
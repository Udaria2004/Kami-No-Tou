// Intromenu.cpp

#include <iostream>
#include "Intro.h"
#include <string>
#include <fstream>
using namespace std;

int intro()
{
	ifstream fin;
	fin.open("intro.txt");

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
	cout << "                                          " << endl;
	fin.open("intro2.txt");
	while (getline(fin, line))
	{
		cout << line << endl;
	}
	fin.close();
	cout << "                                          " << endl;
	fin.open("intro3.txt");
	while (getline(fin, line))
	{
		cout << line << endl;
	}
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	fin.close();
	return 0;
}
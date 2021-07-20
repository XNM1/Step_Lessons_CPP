// Lesson15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
    /*std::map<int, int> d{ {1,2}, {3,4}, {5,6} };
	for (auto el : d)
	{
		cout << el.first << " " << el.second << endl;
	}*/

	//cout << std::hex;
	//cout << 12;
	cout << std::setw(30) << std::right << "hello" << endl;
	cout << std::setw(30) << std::left << "world" << endl;
	cout << std::setw(30) << std::internal << "j" << std::cout.fill('0') << endl;
	string str;
	char s[20];
	std::getline(cin, str, '\n');
	
}

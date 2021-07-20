// Lesson14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tuple>
#include <string>
#include <array>

using std::cout;
using std::endl;
using std::cin;

template<int size>
void show(std::array<int, size>& arr) {
	for (auto e : arr)
	{
		cout << e << endl;
	}
}

int main()
{
	std::array<int, 4> arr = { 12,13,14,15 };

	show<arr.size()>(arr);
	//auto a = std::make_tuple<int, double, char>( 1, 12.5, 'k' );
	//int a1; 
	//double a2; 
	//char a3;
	//std::tie(a1, a2, a3) = a;
	////std::tuple<int&, double&, char&>{a1, a2, a3} = a;
	//cout << a2 << endl;
	//int n1 = 11, n2 = 9;
	//int min, max;
	//std::tie(max, min) = min_max(n1, n2);
	//cout << min << endl;
}

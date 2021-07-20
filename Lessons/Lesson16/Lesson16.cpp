// Lesson16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>

using std::cout;
using std::endl;

void show(int* begin, int* end) {
	for (auto* ptr = begin; ptr != end; ptr++)
	{
		cout << *ptr << endl;
	}
}

//class iter {
//private:
//	int* ptr;
//public:
//	iter(int &arr) {
//		ptr = &arr;
//	}
//	iter& operator++() {
//		ptr++;
//		return *this;
//	}
//	iter& operator--() {
//		ptr--;
//		return *this;
//	}
//};
//
//class array {
//private:
//	int arr[10];
//	iter begin{ arr[0] };
//	iter end{ arr[9] };
//public:
//	iter& begin() {
//		return begin;
//	}
//	iter& end() {
//		return end;
//	}
//};

int main()
{
    /*int arr[] = { 1,2,3,4,0 };
	int* end = arr + (sizeof(arr) / sizeof(arr[0]));
	show(arr, end);*/
	std::vector<int> v{ 1,2,3,4 };
	std::list<int> l{ 5,6,7,8 };
	std::map<int, int> m{ {1,2}, {3,4}, {5,6} };

	/*auto begin = v.crbegin();
	auto end = v.crend();
	auto it = end;
	while (it != begin)
	{
		cout << *it << endl;
		it--;
	}*/
	/*for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->second << endl;
	}*/

	/*for (auto e : v)
	{
		cout << e << endl;
	}*/
}

// VectorTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"

int main()
{
	Vector<double> v;
	for (int i = 0; i < 70; i++)
	{
		v.push_back(i);
		std::cout << "El: " << v.get_element(i) << std::endl;
		std::cout << "Size: " << v.get_size() << std::endl;
		std::cout << "Capacity: " << v.get_capacity() << std::endl;
	}
	std::cout << "_--------------------------_" << std::endl;
	for (int i = 69; i >= 0; i--)
	{
		std::cout << "El: " << v.get_element(i) << std::endl;
		std::cout << "Size: " << v.get_size() << std::endl;
		std::cout << "Capacity: " << v.get_capacity() << std::endl;
		v.pop_back();
	}
}

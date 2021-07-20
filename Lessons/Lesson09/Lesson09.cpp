// Lesson09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename T1, typename T2>
int sum(T1 a, T2 b) {
    return a + b;
}

int main()
{
    std::cout << sum(2.88, 5) << std::endl;
    //std::cout << sum<int, double, double>(2.88, 5) << std::endl;
	//std::cout << pow(2, 3) << std::endl;
}

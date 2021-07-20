// Проект
//

#include <iostream>
#include <math.h>

using namespace std;

template<class T1, class T2>
class Base {
public:
	T1 value1;
	T2 value2;
	Base(T1 v1, T2 v2) : value1{ v1 }, value2{ v2 } {}
};

template<class T1, class T2, class T3, class T4>
class Child : public Base<T1, T2> {
public:
	T3 value3;
	T4 value4;
	Child(T1 v1, T2 v2, T3 v3, T4 v4) : Base<T1, T2>{ v1, v2 }, value3{ v3 }, value4{ v4 } {}
};

template<class T1, class T2, class T3, class T4, class T5, class T6>
class Child2 : public Child<T1, T2, T3, T4> {
public:
	T5 value5;
	T6 value6;
	Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) : Child<T1, T2, T3, T4>{ v1, v2, v3, v4 }, value5{ v5 }, value6{ v6 } {}
};

int main()
{
	Child2<int, int, int, int, int, int> c{1,2,3,4,5,6};
	std::cout << c.value5 << std::endl;
}
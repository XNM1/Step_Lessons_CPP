// Lesson04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Int
{
public:
	Int();
	Int(int);
	~Int();

	void setI(int _i) {
		i = _i;
	}

	int getI() {
		return i;
	}

	Int* sum(int s) {
		i += s;
		return this;
	}
public:
	int i;
};

Int::Int(int i) : i{ i } {}
Int::Int() : i{ 0 }{}

Int::~Int()
{
}

int main()
{
	Int i1{ 3 };
	i1.setI(7);

	Int* i2 = new Int{ 2 };
	cout << i2->sum(10)->sum(20)->sum(5)->sum(4)->getI() << endl;
	setI(&i1, 7);
}

void setI(Int* _this, int _i) {
	_this->i = _i;
}
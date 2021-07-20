// Lesson05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class User
{
public:
	User(int, int, int, const char*);
	User(const User&);
	~User();
	int age;
	int weight;
	int heigh;
	char* name;
	static int getCount() {
		return count;
	}
private:
	static int count;
};

User::User(int _age, int _weight, int _heigh, const char* _name) : age{ _age }, weight{ _weight }, heigh{ _heigh }, name{new char[strlen(_name) + 1]} {
	strcpy_s(name, strlen(_name) + 1, _name);
	++count;
}
User::User(const User& user) : User{ user.age, user.weight, user.heigh, user.name } {}
User::~User() {}

int User::count{ 0 };

int main()
{
	User u1{ 28, 100, 200, "AAAA" };
	User u2{ u1 };
	u1.name[2] = '3';
	cout << "Name U1: " << u1.name << endl;
	cout << "Name U2: " << u2.name << endl;
	cout << "Weight U1: " << u1.weight << endl;
	cout << "Weight U2: " << u2.weight << endl;
	cout << "Count users: " << u1.getCount() << endl;
}
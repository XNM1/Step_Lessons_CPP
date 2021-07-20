// Lesson06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//class User
//{
//public:
//	User(int, int, const char*);
//	~User();
//private:
//	int age;
//	int countContacts;
//	char* name;
//public:
//	int getAge() const {
//		return age;
//	}
//	int getCountContacts() const {
//		return countContacts;
//	}
//	void incAge() {
//		age++;
//	}
//	void setAge(const int _age) {
//		age = _age;
//	}
//	const char* getName() const {
//		return name;
//	}
//	char* getName() {
//		return name;
//	}
//};
//
//User::User(int _age, int _countContacts, const char* _name) : age{ _age }, countContacts{ _countContacts }, name{ new char[strlen(_name) + 1] }
//{
//	strcpy_s(name, strlen(_name) + 1, _name);
//}
//
//User::~User()
//{}

//class Int {
//public:
//	int x;
//	Int(int _x) : x{_x} {
//		std::cout << "Ctor works" << std::endl;
//	}
//	Int(const Int& copy) : x{copy.x} {
//		std::cout << "Copy works" << std::endl;
//	}
//	int getX() const {
//		return x;
//	}
//};
//
//class Array {
//public:
//	int size;
//	explicit Array(int _size) : size{ _size } {}
//};
//
//Array& inc(Array i) {
//	return i;
//}

template<typename T>
class Vector
{
private:
	int capacity;
	int size;
	int rate;
	T* arr;
private:
	void check_capacity() {
		if (capacity < size + 3) {
			reserve();
		}
		else if (capacity - (rate+20) > size) {
			shrink_to_fit();
		}
	}
	void reserve() {
		capacity += rate;
		reall();
	}
	void shrink_to_fit() {
		capacity = size < capacity - rate ? capacity - rate : capacity;
		reall();
	}
	void reall() {
		T* old = new T[size];
		copy(old, arr);
		delete[] arr;
		arr = new T[capacity];
		copy(arr, old);
		delete[] old;
	}
	void copy(T new_array[], T old_array[]) {
		for (int i = 0; i < size; ++i) {
			new_array[i] = old_array[i];
		}
	}
public:
	int get_capacity() const {
		return capacity;
	}

	int get_size() const {
		return size;
	}

	T get_element(int i) const {
		if (i < size)
		{
			return arr[i];
		}
		return NULL;
	}

	void push_back(T i) {
		size++;
		check_capacity();
		arr[size - 1] = i;
	}

	T pop_back() {
		size--;
		check_capacity();
		T tmp = arr[size];
		arr[size] = NULL;
		return tmp;
	}

	Vector() : size{ 0 }, rate{ 15 }
	{
		capacity = rate;
		arr = new T[capacity];
	}

	Vector(int _size) : size{ 0 }, rate{ 15 }
	{
		capacity = _size + rate;
		arr = new T[capacity];
	}

	Vector(int _size, const T _arr[]) : Vector{ _size }
	{
		size = _size;
		for (int i = 0; i < size; i++)
		{
			arr[i] = _arr[i];
		}
	}

	Vector(const Vector& vector) : capacity{ vector.capacity }, size{ vector.size }, rate{ vector.rate }, arr{ new T[vector.capacity] }  {
		copy(arr, vector.arr);
	}

	~Vector() {
		delete[] arr;
	}
};

int main()
{
	/*const User u1{ 12, 500, "AAAA" };
	User u2{ u1 };
	u2.getName()[2] = '2';
	std::cout << u1.getName() << std::endl;
	std::cout << u2.getName() << std::endl;*/
	/*Array i = inc(23);
	std::cout << i.size << std::endl;*/
	Vector<double> v;
	for (int i = 0; i < 70; i++)
	{
		v.push_back(i);
		std::cout << "El: " << v.get_element(i) << std::endl;
		std::cout << "Size: " << v.get_size() << std::endl;
		std::cout << "Capacity: " << v.get_capacity() << std::endl;
	}
	std::cout << "_--------------------------_" << std::endl;
	for (int i = 69; i >=0; i--)
	{
		std::cout << "El: " << v.get_element(i) << std::endl;
		std::cout << "Size: " << v.get_size() << std::endl;
		std::cout << "Capacity: " << v.get_capacity() << std::endl;
		v.pop_back();
	}
}

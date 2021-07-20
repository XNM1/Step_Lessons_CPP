#pragma once


//#include <iostream>
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
		else if (capacity - (rate + 20) > size) {
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
		T* new_arr = new T[capacity];
		copy(new_arr, arr);
		delete[] arr;
		arr = new_arr;
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

	int get_size() const;

	T get_element(int i) const {
		if (i < size)
		{
			return arr[i];
		}
		return 0;
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
		arr[size] = 0;
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

//#include "Vector.inl"
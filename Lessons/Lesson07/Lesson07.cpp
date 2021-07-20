// Lesson07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class String_ {
private:
	char* str;
	int length;
	static int countD;
public:
	String_(const char* str)
	{
		length = strlen(str) + 1;
		this->str = new char[length];
		strcpy_s(this->str, length, str);
	}

	String_() = default;

	String_(const char* str, int length) = delete;

	String_(const String_& copy)
	{
		length = copy.getLength();
		this->str = new char[length];
		strcpy_s(this->str, length, copy);
		std::cout << "copy constructor" << std::endl;
	}

	String_(String_&& copy) noexcept
	{
		length = copy.getLength();
		this->str = copy.str;
		copy.str = nullptr;
		std::cout << "move constructor" << std::endl;
	}

	String_& operator=(String_&& copy) noexcept {
		if (&copy == this)
			return *this;
		delete[] str;
		length = copy.getLength();
		this->str = copy.str;
		copy.str = nullptr;
		std::cout << "move =" << std::endl;
	}

	String_& operator=(const String_& copy) {
		if (&copy == this)
			return *this;
		delete[] str;
		length = copy.getLength();
		this->str = new char[length];
		strcpy_s(this->str, length, copy);
		std::cout << "copy =" << std::endl;
	}

	int getLength() const {
		return length;
	}

	char* operator()() const {
		return str;
	}

	int operator()(int i) {
		return length;
	}

	bool operator==(const String_& str2) {
		return cmp(true, str2);
	}

	bool operator!=(const String_& str2) {
		return cmp(false, str2);
	}

	bool cmp(bool isTrue, const String_& str2) {
		if (length != str2.getLength())
			return !isTrue;
		for (size_t i = 0; i < length; i++)
		{
			if (str[i] != str2[i])
				return !isTrue;
		}
		return isTrue;
	}

	String_& operator()(const char* str2) {
		delete[] str;
		length = strlen(str2) + 1;
		this->str = new char[length];
		strcpy_s(this->str, length, str2);
		return *this;
	}

	String_ operator+(const String_& str2) {
		int l = getLength() + str2.getLength() - 2;
		char* str3 = new char[l + 1];
		for (int i = 0; i < getLength() - 1; i++)
		{
			str3[i] = this->str[i];
		}
		for (int i = getLength() - 1, j = 0; i < l; i++, j++)
		{
			str3[i] = str2[j];
		}
		str3[l] = '\0';
		String_ s{ str3 };
		delete[] str3;
		return s;
	}

	char& operator[](int i) const {
		if (i < length)
			return str[i];
	}

	String_& operator--() {
		char* old_str = new char[length];
		strcpy_s(old_str, length, str);
		length--;
		delete[] this->str;
		this->str = new char[length];
		for (int i = 0; i < length; i++)
		{
			str[i] = old_str[i];
		}
		str[length - 1] = '\0';
		delete[] old_str;
		return *this;
	}

	String_ operator--(int i) {
		char* old_str = new char[length];
		strcpy_s(old_str, length, str);
		length--;
		delete[] this->str;
		this->str = new char[length];
		for (int i = 0; i < length; i++)
		{
			str[i] = old_str[i];
		}
		str[length - 1] = '\0';
		String_ s{ old_str };
		delete[] old_str;
		return s;
	}

	String_& operator=(const char* str) {
		length = strlen(str) + 1;
		this->str = new char[length];
		strcpy_s(this->str, length, str);
		return *this;
	}

	operator char* () const {
		return str;
	}

	~String_()
	{
		delete[] str;
	}

	static void* operator new(size_t l) {
		void* p = malloc(l);
		countD++;
		//std::cout << b << std::endl;
		return p;
	}

	static void* operator new[](size_t l) {
		void* p = malloc(l);
		return p;
	}

	static void operator delete(void* p) {
		free(p);
		countD--;
		//std::cout << b << std::endl;
	}

	static void operator delete[](void* p) {
		free(p);
	}
};

int String_::countD{ 0 };

class Number {
public:
	int i;
	Number(int i_)
	{
		i = i_;
	}

	operator int() {
		return i;
	}
};

class Int {
public:
	int i;
	Int(int i_)
	{
		i = i_;
	}

	operator Number() {
		return Number(i);
	}
};

String_ copy(const String_ str)
{
	return std::move(String_(str));
}

int main()
{
	//String_ str1 = "hello" ;
	//String_ str2 = "world" ;
	//String_ str4 = "again" ;
	//String_ str3 = str1 + str2 + str4;
 //   std::cout << str3-- << std::endl;
	//std::cout << str3(1) << std::endl;

	//std::cout << str3("123321") << std::endl;
	//std::cout << str3() << std::endl;

	//Int a = 12;
	//Number i = Number(a);
	//std::cout << i << std::endl;

	//String_* str1 = new String_{ "hello" };
	//String_ str2 = String_{ *str1 };
	//std::cout << str2 << std::endl;
	//std::cout << str1 << std::endl;

	const String_ str1{ "hello" };
	//delete str1;
	//String_ str2{ std::move(*str1) };
//	str1 = new String_{ std::move(str2) };
	std::cout << str1.getLength() << std::endl;
	//std::cout << *str1 << std::endl;
}

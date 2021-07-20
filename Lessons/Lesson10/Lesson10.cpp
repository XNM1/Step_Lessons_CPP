// Lesson10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>
#include <stdarg.h>

template<typename T>
auto sum(T ptr) {
    return ptr;
}

template<typename T, typename... T2>
auto sum(T ptr, T2... ptr2) {
    return ptr + sum(ptr2...);
}

template<typename T>
class SmartPointerCount {
private:
    T* ptr;
    int count{ 0 };
public:
    SmartPointerCount(T* ptr = nullptr) : ptr{ ptr } {}
    SmartPointerCount(const SmartPointerCount& copy) { this->ptr = copy.ptr; count++; }
    T& operator=(const SmartPointerCount& copy) { this->ptr = copy.ptr; count++; return *this; }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    ~SmartPointerCount()
    {
        if (count == 0 && this->ptr != nullptr) {
            delete ptr;
            std::cout << "D Pointer" << std::endl;
        }
        else
            count--;
    }
};

class Int
{
public:
    Int(int i) : i{ i } {}
    int getI() { return i; }
    void setI(int i) { this->i = i; }
private:
    int i;
};


class Singelton {
private:
    static Singelton* ins;
    char* conn;
protected:
    Singelton() {}
public:
    char* get_conn() const { return conn; };
    void set_conn(const char* s) { this->conn = new char[strlen(s) + 1]; strcpy_s(this->conn, strlen(s) + 1, s); }
    static Singelton* get_instance();
};

Singelton* Singelton::ins{ nullptr };

Singelton* Singelton::get_instance() {
    if (ins == nullptr)
        ins = new Singelton();
    return ins;
}

class Singelton2 {
private:
    char* conn;
protected:
    Singelton2() {}
public:
    char* get_conn() const { return conn; };
    void set_conn(const char* s) { this->conn = new char[strlen(s) + 1]; strcpy_s(this->conn, strlen(s) + 1, s); }
    static Singelton2* get_instance();
};

Singelton2* Singelton2::get_instance() {
    static Singelton2 ins;
    return &ins;
}



int main()
{
    Singelton2* s = Singelton2::get_instance();
    s->set_conn("10.6.6.3");
    std::cout << s->get_conn() << std::endl;
    SmartPointerCount<int> i1{ new int{21} };
    SmartPointerCount<Int> i2{ new Int{53} };
    Int* i3 = new Int{ 72 };
    SmartPointerCount<Int> i4 = i2;
    std::cout << *i1 << std::endl;
    std::cout << i2->getI() << std::endl;
    std::cout << i3->getI() << std::endl;
    std::cout << sum(4.4, 2., 7, 10, 11) << std::endl;
}
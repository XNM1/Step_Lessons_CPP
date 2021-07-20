// Lesson12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <stdexcept>

using std::cout;
using std::endl;

class user_exception : public std::exception {
    virtual const char* what() const noexcept override {
        return "user error";
    }
};

class user_age_exception : public user_exception {
    virtual const char* what() const noexcept override {
        return "user age error";
    }
};

class age_high_exception : public user_age_exception {
    virtual const char* what() const noexcept override {
        return "user age hight error";
    }
};

class age_negative_exception : public user_age_exception {
    virtual const char* what() const noexcept override {
        return "user age negative error";
    }
};

int div_by(int a, int b) {
    if (b == 0) {
        throw -23;
    }
    return a / b;
}

class User {
public:
    char* name;
    int age;
public:
    User(int age)
    {
        setAge(age);
        name = new char[12];
    }
    void setAge(int value) {
        if (age < 0)
            throw age_negative_exception{};
        else if (age > 140)
            throw age_high_exception{};
        else
            age = value;
    }
    int getAge() const {
        return age;
    }
    ~User()
    {
        delete[] name;
        std::cout << "~ User" << std::endl;
    }
};

const double PI = 3.1415;

namespace MyMath {
    const double PI = 4.1415;
}

namespace MyMath2 {
    const double PI = 5.1514;
}

int main()
{
    /*int b;
    std::cin >> b;
    std::cout << div_by(4, b) << std::endl;
    std::cout << "hello";*/
   /* User u{ 22 };
    setAge(u, 49);
    std::cout << u.age << std::endl;*/
    //try
    //{
    //    /*User* u = new User{ 22 };
    //    u->setAge(-2);
    //    std::cout << u->age << std::endl;*/
    //    User u{ 22 };
    //    u.setAge(-2);
    //    std::cout << u.age << std::endl;
    //    /*int a;
    //    std::cin >> a;
    //    int arr[3] = { 1,2,3 };
    //    if (a > 3)
    //        throw 12;
    //    arr[a] = 12;
    //    std::cout << arr[a];*/
    //    //div_by(2, 0);
    //}
    //catch (const age_high_exception&) {
    //    std::cout << "age high error" << std::endl;
    //}
    //catch (const age_negative_exception&) {
    //    std::cout << "age negative error" << std::endl;
    //}
    //catch (...)
    //{
    //    std::cout << "error" << std::endl;
    //}
    //cout << PI << endl;
    const char* a = "a";
    int b = reinterpret_cast<int>(a);
    cout << b << endl;
}
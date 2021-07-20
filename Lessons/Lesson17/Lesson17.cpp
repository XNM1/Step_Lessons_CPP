// Lesson17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::function;
using std::vector;

void show(int str) {
    cout << str << endl;
}

struct Show
{
    void operator()(int str) {
        cout << str << endl;
    }
};

int counter() {
    int count = 0;
    return ++count;
}

struct Counter
{
private:
    int count{ 0 };
public:
    int operator()() {
        return ++count;
    }
};

int main()
{
    ///*function<void(string)> s = show;
    //s("hello");
    //Show s2;
    //s2("world");*/
    //int i{0};
    //auto s = [i](auto str) mutable {
    //    cout << "C: " << ++i << "; " << str << endl;
    //    //cout << str << endl;
    //};
    //i = 2;
    //s("hello");
    //s("hello");
    //s("hello");
    //s(2);
    //s('a');
    //s(2.1);
    std::array<int, 8> v{ 7,7,3,1,2,9,4,3 };
    int arr[] = { 5,5,78,34,8,2,6,3 };
    auto begin = std::begin(arr);
    auto end = std::end(arr);
    std::sort(begin, end, std::less<int>());
    std::for_each(begin, end, [](int i) { cout << i << endl; });
}

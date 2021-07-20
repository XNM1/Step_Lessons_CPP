// Lesson01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

using namespace std;

class Student {
    private:
        int marks[3];
        int count;

    public:
        char* name;

    public:
        Student(int mark) {
            count = 0;
            setMark(mark);
        }

        int getAvr() {
            int sum = 0;
            for (int i = 0; i < 3; i++)
            {
                sum += marks[i];
            }
            return sum / 3;
        }
        void setMark(int mark) {
            if (mark > 0 && mark <= 12) {
                marks[count] = mark;
            }
            if (count < 3) {
                count++;
            }
        }
        int getMark(int n) {
            if (n >= 0 && n < 3) {
                return marks[n];
            }
            return -1;
        }

        ~Student() {
            delete[] name;
        }
};

int main()
{
    setlocale(LC_ALL, "");
    Student *student = new Student(10);
    strcpy_s(student->name, "Alex");
    student->setMark(10);
    student->setMark(11);
    cout << student->name << ":" << student->getAvr() << endl;
    delete student;
    _getch();
    return 0;
}

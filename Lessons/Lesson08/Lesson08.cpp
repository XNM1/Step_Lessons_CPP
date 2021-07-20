// Lesson08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Point;
class Point3D;
class Point4D;

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    friend int sum(const Point&);
    friend int diff(const Point&);

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
    //friend bool operator==(const Point&, const Point&);
    friend Point4D;
    friend bool operator==(const Point& p1, const Point3D& p2);

    friend std::ostream& operator<<(std::ostream&, const Point&);
    friend std::istream& operator>>(std::istream&, Point&);
};
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "X: " << p.x << "; Y: " << p.y << std::endl;
    return os;
}
std::istream& operator>>(std::istream& is, Point& p) {
    std::cout << "Set X:\t";
    is >> p.x;
    std::cout << "Set Y:\t";
    is >> p.y;
    return is;
}

class Point3D {
private:
    int x;
    int y;
    int z;
public:
    Point3D(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    friend bool operator==(const Point& p1, const Point3D& p2);
};

class Point4D {
private:
    Point p{0,0};
    int x;
    int y;
    int z;
    int i;
public:
    Point4D(int x, int y, int z, int i)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->i = i;
        p.x;
    }
    bool operator==(const Point& p2) {
        return this->x == p2.x && this->y == p2.y;
    }
};

int sum(const Point& p) {
    return p.x + p.y;
}

int diff(const Point& p) {
    return p.x - p.y;
}

bool operator==(const Point& p1, const Point& p2) {
    return p1.getX() == p2.getX() && p1.getY() == p2.getY();
}

bool operator==(const Point& p1, const Point3D& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}


int main()
{
    Point p1{ 12, 545 };
    Point3D p2{ 12, 55, 15 };
    Point4D p3{ 12, 55, 15, 22 };
    std::cout << int(p1 == p2) << std::endl;
    std::cout << int(p3 == p1) << std::endl;
    std::cin >> p1;
    std::cout << p1 << std::endl;
}
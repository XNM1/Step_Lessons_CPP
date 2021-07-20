// Lesson2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Point3D.h"

using namespace std;

int main()
{
    Point3D* point = new Point3D("point1");
    point->setName("point2");
    cout << "Name: " << point->getName() << ", X: " << point->getX() << ", Y: " << point->getY() << ", Z: " << (*point).getZ();
    delete point;
}

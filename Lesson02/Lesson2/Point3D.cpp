#include <iostream>
#include "Point3D.h"


void Point3D::setName(const char* name_) {
	int l = strlen(name_) + 1;
	if (name != nullptr) {
		delete[] name;
	}
	name = new char[l];
	for (int i = 0; i < l; i++)
	{
		name[i] = name_[i];
	}
}
void Point3D::setX(int x_) {
	x = x_;
}
void Point3D::setY(int y_) {
	y = y_;
}
void Point3D::setZ(int z_) {
	z = z_;
}

const char* Point3D::getName() {
	return name;
}
int Point3D::getX() {
	return x;
}

int Point3D::getY() {
	return y;
}

int Point3D::getZ() {
	return z;
}

void Point3D::move(int x_, int y_, int z_) {
	name = nullptr;
	x += x_;
	y += y_;
	z += z_;
}

Point3D::Point3D() {
	name = nullptr;
	x = 0;
	y = 0;
	z = 0;
}

Point3D::Point3D(const char* name_) {
	setName(name_);
	x = 0;
	y = 0;
	z = 0;
}

Point3D::Point3D(int x_, int y_, int z_) {
	x = x_;
	y = y_;
	z = z_;
}
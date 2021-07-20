#pragma once
class Point3D
{
private:
	char* name;
public:
	void setName(const char*);
	const char* getName();

private:
	int x;
public:
	void setX(int);
	int getX();

private:
	int y;
public:
	void setY(int);
	int getY();

private:
	int z;
public:
	void setZ(int);
	int getZ();

public:
	Point3D(int, int, int);
	Point3D();
	Point3D(const char*);
	~Point3D() {
		delete[] name;
	}

public:
	void move(int, int, int);
};


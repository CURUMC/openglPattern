#pragma once

#include <math.h>
#include <iostream>
class  Point3	//Vector3
{


public:
	float x, y, z;
	Point3();
	Point3(const float&, const float&, const float&);
	Point3(const Point3&);
	~Point3();

	Point3 operator+(const Point3&);
	Point3 operator+(const int&);
	Point3 operator*(const float&);

	Point3 operator*(const Point3&);
	Point3 operator-(const Point3&);


	Point3& operator=(const Point3&&);

	Point3& operator=(const Point3&);


	Point3 operator+=(const Point3& rhs)
	{
		this->x = (this->x + rhs.x);
		this->y = (this->y + rhs.y);
		this->z = (this->z + rhs.z);
		return *this;
	}
	Point3 operator/=(const float& rhs)
	{
		this->x = (this->x / rhs);
		this->y = (this->y / rhs);
		this->z = (this->z / rhs);
		return *this;
	}

	const float& length() { return static_cast<float>(sqrt(x*x + y*y + z*z)); }

	const float  normalize()
	{
		float le = length();
		*this /= le;
		return le;

	}


	void SetPoint3(const float& a, const float& b, const float& c);
/*
	void DrawPoint3(HDC hdc) {

		GetPoint2().DrawPoint(hdc);
	}

	void DrawPoint3(HDC hdc, const Point3& uV, const Point3& pPos) {

		GetPoint2(uV, pPos).DrawPoint(hdc);
	}
*/
	// ¿ÜÀû
	Point3 cross(const Point3& other)
	{
		
		return Point3(other.z*y-z*other.y,z*other.x-x*other.z,x*other.y-y*other.x);
	}
	const float inner(const Point3& other) {
		return x*other.x + y*other.y + z*other.z;
	}


	void  Reflection(const Point3& q) {
		Point3 n = q;
		n.normalize();
		Point3 P{ x,y,z };
		P = P + n*((P*-1).inner(n))*2;

		*this = P;
	}

};


std::ostream& operator<<(std::ostream& os, const Point3& dt);
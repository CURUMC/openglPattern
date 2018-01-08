#pragma once
#include <math.h>
struct Point 
{
	float x, y;
	Point();
	Point(float, float);
	Point(double, double);
	Point(int, int);
	Point(const Point&);

	Point operator+(const Point&);
	Point operator+(const int&);
	Point operator+(const float&);
	Point operator-(const float&);
	Point operator-(const Point&);
	void SetPoint(const float a, const float b);



	Point operator*(const int&a) {
		return Point(x * a, y *a);
	}
	Point operator*(const float&a) {
		return Point(x * a, y *a);
	}


	Point operator*(const float&a)const {
		return Point(x * a, y *a);
	}

	Point& operator=(const Point&&);

	Point& operator=(const Point&);

	Point operator+=(const Point& rhs)
	{
		this->x = (this->x + rhs.x);
		this->y = (this->y + rhs.y);
		return *this;
	}

	Point operator-=(const Point& rhs)
	{
		this->x = (this->x - rhs.x);
		this->y = (this->y - rhs.y);
		return *this;
	}

	Point operator/=(const float& rhs)
	{
		this->x = (this->x / rhs);
		this->y = (this->y / rhs);
		return *this;
	}
	Point operator*=(const float& rhs)
	{
		this->x = (this->x * rhs);
		this->y = (this->y * rhs);
		return *this;
	}

	Point operator*=(const Point& rhs)
	{
		this->x = (this->x * rhs.x);
		this->y = (this->y * rhs.y);
		return *this;
	}

	const float& length() { return static_cast<float>(sqrt(x*x + y*y )); }

	const float  normalize()
	{

		float le = length();
		if (le == 0) { return le; }
		
		*this /= le;
		return le;

	}
	const float distance(Point q) const {
		return (q - *this).length();
	}

	const float inner(const Point& other) {
		return x*other.x + y*other.y;
	}

	void  Reflection(const Point& q) {
		Point n = q;
		n.normalize();
		Point P{ x,y };
		P=P + n*((P*-1).inner(n));

		*this = P;
	}
	
	void rotation(const Point& pivot,const float& radian)
	{
		Point temp = *this;
		temp = temp - pivot;
		x = temp.x*cos(radian) - temp.y*sin(radian);
		y = temp.y*cos(radian) + temp.x*sin(radian);
		x += pivot.x;
		y += pivot.y;

	}




};
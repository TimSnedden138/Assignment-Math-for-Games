#include "vec2.h"
#include<cmath>
vec2::vec2()
{
	x = 0;// setting x to zero
	y = 0;// setting y to zero
}

vec2::vec2(float x, float y)
{
	this->x = x;// setting this x to x
	this->y = y;// setting this y to y
}
float vec2::magnitude() const
{
	return sqrt(x*x + y * y);
}

float vec2::dot(const vec2 & rhs) const
{
	return x * rhs.x + y * rhs.y;
}

vec2 & vec2::normalize()
{
	float mag = sqrt(x * x + y * y);
	vec2 magedValues;

	magedValues.x = x / mag;
	magedValues.y = y / mag;

	return magedValues;
}

vec2 vec2::getNormalized() const
{
	vec2 normalValues;

	normalValues.x = x;
	normalValues.y = y;

	normalValues.x /= magnitude();
	normalValues.y /= magnitude();

	return vec2(normalValues);
}

vec2 & vec2::scale(const vec2 & rhs)
{
	return *this = { x * rhs.x,y * rhs.y };
}

vec2 vec2::getScaled(const vec2 & rhs) const
{
	return vec2(x * rhs.x, y * rhs.y);
}

vec2 vec2::getPerpCW() const
{
	return vec2(x, -y);//returning the negative y and positive x
}

vec2 vec2::getPerpCCW() const
{
	return vec2(-x, y);//returning the negative x and positive y
}

float vec2::angleBetween(const vec2 & rhs) const
{
	return std::acos(dot(rhs) / magnitude() * rhs.magnitude());
}

vec2 vec2::operator+(const vec2 & rhs) const
{
	return vec2(x + rhs.x, y + rhs.y);
}

vec2 vec2::operator-(const vec2 & rhs) const
{
	return vec2(x - rhs.x, y - rhs.y);
}

vec2 vec2::operator*(const float rhs) const
{
	return vec2(x*rhs, y*rhs);
}

vec2 vec2::operator/(const float rhs) const
{
	return vec2(x / rhs, y / rhs);
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	vec2 red;
	red.x = x + rhs.x;
	red.y = y + rhs.x;
	return red;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{
	vec2 one;
	one.x = x - rhs.x;
	one.y = y - rhs.x;
	return one;
}

vec2 & vec2::operator*=(const float rhs)
{
	vec2 one;
	one.x = x * rhs;
	one.y = y * rhs;
	return one;
}

vec2 & vec2::operator/=(const float rhs)
{
	vec2 one;
	one.x = x / rhs;
	one.y = y / rhs;
	return one;
}

bool vec2::operator==(const vec2 & rhs) const
{
	// checking to see if the two values are equal
	if (x && y == rhs.x && rhs.y) {
		return true;
	}
	return false;
}

bool vec2::operator!=(const vec2 & rhs) const
{
	vec2 one;
	//checking to if the two values are not equal
	if (one.x && one.y != rhs.x && rhs.y) {
		return true;
	}
	return false;
}
vec2 vec2::operator-() const
{
	return vec2(-x, -y);
}
vec2::operator float*()
{
	return &x;
}

vec2::operator const float*() const
{
	return &x;
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	vec2 multiValues;
	multiValues.x = lhs * rhs.x;
	multiValues.y = lhs * rhs.y;
	return vec2(multiValues);
}

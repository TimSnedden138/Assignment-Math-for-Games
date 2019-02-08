#include "vec2.h"
#include<cmath>
#include <cfloat>
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
	*this = getNormalized();
	return *this;
}
vec2 vec2::getNormalized() const
{
	vec2 normalValues;

	normalValues.x = x;
	normalValues.y = y;

	normalValues /= magnitude();

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
	*this = *this + rhs;
	return *this;
}
vec2 & vec2::operator-=(const vec2 & rhs)
{
	*this = *this - rhs;
	return *this;
}
vec2 & vec2::operator*=(const float rhs)
{
	this->x = this->x * rhs;
	this->y = this->y * rhs;
	return *this;
}
vec2 & vec2::operator/=(const float rhs)
{
	this->x = this->x / rhs;
	this->y = this->y / rhs;
	return *this;
}
bool vec2::operator==(const vec2 & rhs) const
{
	float threshold = FLT_EPSILON * 100;
	if ((abs(x - rhs.x) <= threshold) && (abs(y - rhs.y) <= threshold))
	{
		return true;
	}
	return false;
}
bool vec2::operator!=(const vec2 & rhs) const
{
	float threshold = FLT_EPSILON * 100;
	if ((abs(x - rhs.x) <= threshold) && (abs(y - rhs.y) <= threshold))
	{
		return false;
	}
	return true;
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
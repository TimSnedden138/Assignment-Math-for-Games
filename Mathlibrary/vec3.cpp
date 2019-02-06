#include "vec3.h"
#include<cmath>
vec3::vec3()
{
	x = 0;// setting x to zero
	y = 0;// setting y to zero
	z = 0;// setting z to zero
}

vec3::vec3(float x, float y, float z)
{
	this->x = x;// setting this x to x
	this->y = y;// setting this y to y
	this->z = z;// setting this z to z
}

float vec3::magnitude() const
{
	return sqrt(x*x + y * y + z * z);
}

float vec3::dot(const vec3 & rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

vec3 vec3::cross(const vec3 & rhs) const
{
	return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x };
}

vec3 & vec3::normalize()
{
	float mag = sqrt(x * x + y * y + z * z);
	vec3 magedValues;

	magedValues.x = x / mag;
	magedValues.y = y / mag;
	magedValues.z = z / mag;

	return(magedValues);
}

vec3 vec3::getNormalised() const
{
	vec3 normalValues;

	normalValues.x = x;
	normalValues.y = y;
	normalValues.z = z;

	normalValues.x /= magnitude();
	normalValues.y /= magnitude();
	normalValues.z /= magnitude();

	return normalValues;
}

vec3 & vec3::scale(const vec3 & rhs)
{
	return *this = { x * rhs.x,y * rhs.y,z * rhs.z };
}

vec3 vec3::getScaled(const vec3 & rhs) const
{
	return vec3(x * rhs.x, y * rhs.y, z * rhs.z);
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	return vec3(x + rhs.x, y + rhs.y, z + rhs.z);
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	return vec3(x - rhs.x, y - rhs.y, z - rhs.z);
}

vec3 vec3::operator*(const float rhs) const
{
	return vec3(x * rhs, y * rhs, z * rhs);
}

vec3 vec3::operator/(const float rhs) const
{
	return vec3(x / rhs, y / rhs, z / rhs);
}

vec3 & vec3::operator+=(const vec3 & rhs)
{
	vec3 one;
	one.x = x + rhs.x;
	one.y = y + rhs.y;
	one.z = z + rhs.z;
	return one;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	vec3 one;
	one.x = x - rhs.x;
	one.y = y - rhs.y;
	one.z = z - rhs.z;
	return one;
}

vec3 & vec3::operator*=(const float rhs)
{
	vec3 one;
	one.x = x * rhs;
	one.y = y * rhs;
	one.z = z * rhs;
	return one;
}

vec3 & vec3::operator/=(const float rhs)
{
	vec3 one;
	one.x = x / rhs;
	one.y = y / rhs;
	one.z = z / rhs;
	return one;
}

bool vec3::operator==(const vec3 & rhs) const
{
	// checking to see if the three values are equal
	if (x && y && z == rhs.x && rhs.y&&rhs.z) {
		return true;
	}
	return false;
}

bool vec3::operator!=(const vec3 & rhs) const
{
	// checking to see if the three values are not equal
	if (x && y&&z != rhs.x && rhs.y&&rhs.z) {
		return true;
	}
	return false;
}

vec3 vec3::operator-() const
{
	return vec3(-x, -y, -z);
}

vec3::operator float*()
{
	return &x;
}

vec3::operator const float*() const
{
	return &x;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 multiValues;
	multiValues.x = lhs * rhs.x;
	multiValues.y = lhs * rhs.y;
	multiValues.z = lhs * rhs.z;
	return vec3(multiValues);
}
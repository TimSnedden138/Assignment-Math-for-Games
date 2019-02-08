#include"vec3.h"
#include<cmath>
#include<cfloat>
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
	*this = getNormalized();
	return *this;
}
vec3 vec3::getNormalized() const
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
	*this = *this + rhs;
	return *this;
}
vec3 & vec3::operator-=(const vec3 & rhs)
{
	*this = *this - rhs;
	return *this;
}
vec3 & vec3::operator*=(const float rhs)
{
	this->x = this->x * rhs;
	this->y = this->y * rhs;
	this->z = this->z * rhs;
	return *this;
}
vec3 & vec3::operator/=(const float rhs)
{
	this->x = this->x / rhs;
	this->y = this->y / rhs;
	this->z = this->z / rhs;
	return *this;
}
bool vec3::operator==(const vec3 & rhs) const
{
	float threshold = FLT_EPSILON * 100;
	if ((abs(x - rhs.x) <= threshold) && (abs(y - rhs.y) <= threshold) && (abs(z - rhs.z) <= threshold))
	{
		return true;
	}
	return false;
}
bool vec3::operator!=(const vec3 & rhs) const
{
	float threshold = FLT_EPSILON * 100;
	if ((abs(x - rhs.x) <= threshold) && (abs(y - rhs.y) <= threshold) && (abs(z - rhs.z) <= threshold))
	{
		return false;
	}
	return true;
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
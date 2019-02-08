#include"vec4.h"
#include<cmath>
#include<cfloat>
vec4::vec4()
{
	x = 0;// setting x to zero
	y = 0;// setting y to zero
	z = 0;// setting z to zero
	w = 0;// setting w to zero
}

vec4::vec4(float x, float y, float z, float w)
{
	this->x = x;// setting this x to x
	this->y = y;// setting this y to y
	this->z = z;// setting this z to z
	this->w = z;// setting this w to w
}

float vec4::magnitude() const
{
	return sqrt(x*x + y * y + z * z + w * w);
}

float vec4::dot(const vec4 & rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;

}

vec4 vec4::cross(const vec4 & rhs) const
{
	return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x,0 };
}

vec4 & vec4::normalize()
{
	*this = getNormalized();
	return *this;
}

vec4 vec4::getNormalized() const
{
	vec4 normalValues;

	normalValues.x = x;
	normalValues.y = y;
	normalValues.z = z;
	normalValues.w = w;

	normalValues.x /= magnitude();
	normalValues.y /= magnitude();
	normalValues.w /= magnitude();
	normalValues.z /= magnitude();

	return normalValues;
}
vec4 & vec4::scale(const vec4 & rhs)
{
	return *this = { x * rhs.x,y * rhs.y,z * rhs.z,w * rhs.w };
}
vec4 vec4::getScaled(const vec4 & rhs) const
{
	return vec4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
}

vec4 vec4::operator+(const vec4 & rhs) const
{
	return vec4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);

}

vec4 vec4::operator-(const vec4 & rhs) const
{
	return vec4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

vec4 vec4::operator*(const float rhs) const
{
	return vec4(x * rhs, y * rhs, z * rhs, w*rhs);
}

vec4 vec4::operator/(const float rhs) const
{
	return vec4(x / rhs, y / rhs, z / rhs, w / rhs);
}

vec4 & vec4::operator+=(const vec4 & rhs)
{
	*this = *this + rhs;
	return *this;
}

vec4 & vec4::operator-=(const vec4 & rhs)
{
	*this = *this - rhs;
	return *this;
}

vec4 & vec4::operator*=(const float rhs)
{
	this->x = this->x * rhs;
	this->y = this->y * rhs;
	this->z = this->z * rhs;
	this->w = this->w * rhs;
	return *this;
}

vec4 & vec4::operator/=(const float rhs)
{
	this->x = this->x / rhs;
	this->y = this->y / rhs;
	this->z = this->z / rhs;
	this->w = this->w / rhs;
	return *this;
}

vec4 operator*(const float lhs, const vec4 & rhs)
{
	vec4 multiValues;
	multiValues.x = lhs * rhs.x;
	multiValues.y = lhs * rhs.y;
	multiValues.z = lhs * rhs.z;
	multiValues.w = lhs * rhs.w;
	return vec4(multiValues);
}

bool vec4::operator==(const vec4 & rhs) const
{
	float threshold = FLT_EPSILON * 100;
	if ((abs(x - rhs.x) <= threshold) && (abs(y - rhs.y) <= threshold) && (abs(z - rhs.z) <= threshold) && (abs(w - rhs.w) <= threshold))
	{
		return true;
	}
	return false;
}

bool vec4::operator!=(const vec4 & rhs) const
{
	float threshold = FLT_EPSILON * 100;
	if ((abs(x - rhs.x) <= threshold) && (abs(y - rhs.y) <= threshold) && (abs(z - rhs.z) <= threshold) && (abs(w - rhs.w) <= threshold))
	{
		return false;
	}
	return true;
}

vec4 vec4::operator-() const
{
	return vec4(-x, -y, -z, -w);
}

vec4::operator float*()
{
	return &x;
}

vec4::operator const float*() const
{
	return &x;
}

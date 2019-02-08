#include "mat3.h"
#include<cmath>
mat3::mat3()
{
}

mat3::mat3(float * ptr)
{
	for (int i = 0; i < 9; i++) {
		ptr[i] = m[i];
	}
}

mat3::mat3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	this->m1 = m1;
	this->m2 = m2;
	this->m3 = m3;
	this->m4 = m4;
	this->m5 = m5;
	this->m6 = m6;
	this->m7 = m7;
	this->m8 = m8;
	this->m9 = m9;
}

mat3 mat3::identity()
{
	return mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

mat3 mat3::translation(float x, float y)
{
	mat3 translating;
	translating = translating.identity();
	translating.xAxis.z = x;
	translating.yAxis.z = y;
	return mat3(translating);
}

mat3 mat3::translation(const vec2 & vec)
{
	mat3 translating;
	translating = translating.translation(vec.x, vec.y);
	return mat3(translating);
}

mat3 mat3::rotation(float rot)
{
	mat3 rotation;
	math_help::DEG_TO_RAD(rot);
	rotation.m[0] = cos(rot);
	rotation.m[3] = sin(rot);
	rotation.m[1] = -cos(rot);
	rotation.m[4] = -sin(rot);
	return rotation;
}

mat3 mat3::scale(float xScale, float yScale)
{
	mat3 scaled;
	scaled.xAxis.x = xScale;;
	scaled.yAxis.y = yScale;
	return mat3(scaled);
}

mat3 mat3::scale(const vec2 & vec)
{
	mat3 scaled;
	scaled.xAxis.x = scaled.xAxis.x + vec.x;
	scaled.yAxis.y = scaled.yAxis.y + vec.y;
	return mat3(scaled);
}
void mat3::set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	m1 = this->m1;
	m2 = this->m2;
	m3 = this->m3;
	m4 = this->m4;
	m5 = this->m5;
	m6 = this->m6;
	m7 = this->m7;
	m8 = this->m8;
	m9 = this->m9;
}

void mat3::set(float * ptr)
{
	for (int i = 0; i < 9; i++) {
		m[i] = ptr[i];
	}
}

void mat3::transpose()
{
	float stored1 = m3;
	float stored2 = m6;
	float stored3 = m9;
	stored1 = m1;
	stored2 = m4;
	stored3 = m7;

}

mat3 mat3::getTranspose() const
{
	mat3 transposed;
	for (int i = 0; i < 9; i++)
	{
		transposed.m[i] = m[i];
	}
	return transposed;
}

mat3::operator float*()
{
	return m;
}

mat3::operator const float*() const
{
	return m;
}

vec3 & mat3::operator[](const int index)
{
	return axis[index];
}

const vec3 & mat3::operator[](const int index) const
{
	return axis[index];
}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 multiplacation;
	multiplacation.xAxis.x = xAxis.x * rhs.xAxis.x;
	multiplacation.xAxis.y = xAxis.y * rhs.xAxis.y;
	multiplacation.xAxis.z = xAxis.z * rhs.xAxis.z;
	multiplacation.yAxis.x = yAxis.x * rhs.yAxis.x;
	multiplacation.yAxis.y = yAxis.y * rhs.yAxis.y;
	multiplacation.yAxis.z = yAxis.z * rhs.yAxis.z;
	multiplacation.zAxis.x = zAxis.x * rhs.zAxis.x;
	multiplacation.zAxis.y = zAxis.y * rhs.zAxis.y;
	multiplacation.zAxis.z = zAxis.z * rhs.zAxis.z;
	return multiplacation;
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	*this = *this * rhs;
	return *this;
}

vec3 mat3::operator*(const vec3 & rhs) const
{
	mat3 oldVal;
	vec3 newVal;
	newVal.x = oldVal.xAxis.dot(rhs);
	newVal.y = oldVal.yAxis.dot(rhs);
	newVal.z = oldVal.zAxis.dot(rhs);
	return newVal;
}

vec2 mat3::operator*(const vec2 & rhs) const
{
	mat3 matrix;
	vec2 vector;
	vec3 convert;
	convert.x = rhs.x;
	convert.y = rhs.y;
	matrix = getTranspose();
	vector.x = matrix.xAxis.dot(convert);
	vector.y = matrix.yAxis.dot(convert);
	return vector;
}

bool mat3::operator==(const mat3 & rhs) const
{
	for (int i = 0; i < 9; i++) {

		if (m[i] == rhs.m[i]) {
			return true;
		}
	}
	return false;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	for (int i = 0; i < 9; i++) {

		if (m[i] != rhs.m[i]) {
			return true;
		}
	}
	return false;
}

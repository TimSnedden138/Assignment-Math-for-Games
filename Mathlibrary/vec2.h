#pragma once
struct vec2
{
public:
	float x, y;

	vec2();
	vec2(float x, float y);

	float magnitude() const;
	float dot(const vec2 &rhs) const;

	vec2 &normalize();
	vec2 getNormalized() const;

	vec2 &scale(const vec2 &rhs);
	vec2 getScaled(const vec2 &rhs) const;

	vec2 getPerpCW() const;
	vec2 getPerpCCW() const;

	float angleBetween(const vec2 &rhs) const;

	vec2 operator+(const vec2 &rhs) const;
	vec2 operator-(const vec2 &rhs) const;
	vec2 operator*(const float rhs) const;
	friend vec2 operator*(const float lhs, const vec2 &rhs);
	vec2 operator/(const float rhs) const;

	vec2 &operator+=(const vec2 &rhs);
	vec2 &operator-=(const vec2 &rhs);
	vec2 &operator*=(const float rhs);
	vec2 &operator/=(const float rhs);

	bool operator==(const vec2 &rhs) const;
	bool operator!=(const vec2 &rhs) const;

	vec2 operator-() const;

	operator float *();
	operator const float *() const;
};

vec2 operator*(const float lhs, const vec2 &rhs);
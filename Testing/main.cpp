#include<iostream>
#include"mathUtil.h"
#include"vec2.h"
#include"vec3.h"
#include"vec4.h"
#include"mat3.h"
int main()
{
	vec2 af = { 4.999999f,7.f };
	vec2 bf = {5.0f,7.f };
	vec2 ai = { 5,7 };
	vec2 bi = {5,7 };
	bool eqf = af == bf;
	bool eqi = ai == bi;
	vec2 naf = { 3.999999f,7.f };
	vec2 nbf = {5.0f,7.f };
	vec2 nai = { 20,7 };
	vec2 nbi = {5,7 };
	bool neqf = naf != nbf;
	bool neqi = nai != nbi;
	vec2 aim = { 5,7 };
	aim *= 2;
	vec2 aid = { 5,7 };
	aid /= 2;
	std::cout <<"Min: " << math_help::min(4, 5) << std::endl;
	std::cout <<"Max: " << math_help::max(5, 4) << std::endl;
	std::cout <<"Sum: "<<math_help::sum(20,499) << std::endl;
	std::cout <<"Absolute ahead of 0: " << math_help::abs(42) << std::endl;
	std::cout <<"Absolute behind 0: " << math_help::abs(-42) << std::endl;
	std::cout <<"Pow " << math_help::pow(4, 12) << std::endl;
	std::cout <<"Deg to Rad: " << math_help::DEG_TO_RAD(1.5708) << std::endl;
	std::cout <<"Rad to Deg: " << math_help::RAD_TO_DEG(90) << std::endl;
	std::cout <<"Is power of two "<<math_help::isPowerOfTwo(5) << std::endl;
	std::cout <<"Next power of two "<<math_help::nextPowerOfTwo(4) << std::endl;
	std::cout << "Equals with ints: " << eqi << std::endl;
	std::cout << "Equals with floats: " << eqf << std::endl;	
	std::cout << "Not equals with ints: " << neqi << std::endl;
	std::cout << "Not equals with floats: " << neqf << std::endl;
	mat3 left(2.0f,-1.0f,5.0f,1.0f,3.0f, 7.0f, 0.0f, 4.0f, 9.0f);
	mat3 right(1.0f, 2.0f, 9.0f, 3.0f, 4.0f, 8.0f,6.0f,4.0f,0.0f);
	mat3 combined = left * right;

	return 0;
}
#include<iostream>
#include"mathUtil.h"
#include"vec2.h"
#include"vec3.h"
#include"vec4.h"
int main()
{
	vec2 af = { 4.999999f,7.f };
	vec2 bf = {5.0f,7.f };
	vec2 naf = { 3.999999f,7.f };
	vec2 nbf = {5.0f,7.f };
	vec2 ai = { 5,7 };
	vec2 bi = {5,7 };
	bool eqf = af == bf;
	bool eqi = ai == bi;
	vec2 nai = { 20,7 };
	vec2 nbi = {5,7 };
	bool neqf = naf != nbf;
	bool neqi = nai != nbi;
	ai *= 2;
	ai.normalize();
	std::cout <<"Min: " << math_help::min(4, 5) << std::endl;
	std::cout <<"Max: " << math_help::max(5, 4) << std::endl;
	std::cout <<"Sum: "<<math_help::sum(20324,4999) << std::endl;
	std::cout <<"Absolute ahead of 0: " << math_help::abs(42) << std::endl;
	std::cout <<"Absolute behind 0: " << math_help::abs(-42) << std::endl;
	std::cout <<"Base 4 Power 6: " << math_help::pow(4, 6) << std::endl;
	std::cout <<"Base 4 Power 1: " << math_help::pow(4, 1) << std::endl;
	std::cout <<"Is power of two "<<math_help::isPowerOfTwo(5) << std::endl;
	std::cout <<"Next power of two "<<math_help::nextPowerOfTwo(4) << std::endl;
	std::cout << "Equals with ints: " << eqi << std::endl;
	std::cout << "Equals with floats: " << eqf << std::endl;	
	std::cout << "Not equals with ints: " << neqi << std::endl;
	std::cout << "Not equals with floats: " << neqf << std::endl;
	return 0;
}
#include "mathUtil.h"
#include<iostream>
int math_help::sum(int a, int b)
{
	int c;// value after adding
	c = a + b;//addition
	return c;//returning the value after the addition
}

int math_help::min(int a, int b)
{
	if (a < b)
	{
		return a;//returns a if a is less than b
	}
	else if (b < a)
	{
		return b;//returns b if b is less than a
	}
}

int math_help::max(int a, int b)
{
	if (a > b)
	{
		return a;//returns a if a is more than b
	}
	else if (b > a)
	{
		return b;//returns b if b is more than a
	}
}

int math_help::clamp(int value, int min, int max)
{
	if (value > min  && value < max)// checking to see if the value is in between the min and max 
	{
		return value;//returns the vale if true
	}
	else
		return 0;
}

const double math_help::DEG_TO_RAD(float rad)
{
	double radCon = (rad / (3.14159265359 / 180));// getting the degree of the rad
	return radCon;
}

const double math_help::RAD_TO_DEG(float deg)
{

	double degCon = (deg * (3.14159265359 / 180));//getting the rad of the deg
	return degCon;
}

int math_help::abs(int val)
{
	if (val < 0)//checking to see if the value is less than zero
	{
		return -val;//if that comes out true then it will return the negative verison of the value
	}
	return val;//if that comes out fase then it will return the value
}
int math_help::pow(int base, int power)
{
	int powVal = base; //get starting base
	if (power == 0)//checking to see if base is equal to zero 
	{
		return 0;
	}
	if (power == 1) // checking to see if base is equal to one
	{
		return base;
	}
	for (int i = 0; i < power; i++)//multiply the base by it self til it reaches the pow
	{
		powVal *= base;
	}
	return powVal;
}
bool math_help::isPowerOfTwo(int val)
{
	if (val == 0) {// checking to see if the value is not zero
		return false;
	}
	while (val != 1)//running a while loop til the value is not 1
	{
		//checking to see if the value is not a power of two
		if (val % 2 != 0) {
			return false;
		}
		val /= 2;

	}
	//return true if it passes both checks
	return true;
}

int math_help::nextPowerOfTwo(int val)
{
	if (isPowerOfTwo(val) == true)//checking to see if it passes the is power of two check
	{
		//if that returns true then it multiplies the value by 2
		return val * 2;
	}
	//if that returns false then this one will return false
	return val;
}

float math_help::moveTowards(float current, float target, float maxDelta)
{
	if (current == target)//checking to see if the current is equal to the target at the start
	{
		return current;
	}
	if (current < target)//checking to see if the current is less than the target
	{
		current += maxDelta;//adding the current from the max delta
		if (current == target)
		{
			return current;
		}
	}
	if (current > target)//checking to see if the current is more than the target
	{
		current -= maxDelta;//subtracting the current from the max delta
		if (current == target)
		{
			return current;
		}
	}
}

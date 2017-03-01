


#include "tokenize.h"
#include <iostream>



int evaluate(const char expr[]);
int sum(const char expr[], int &pos);
int multi(const char expr[], int &pos);
int factor(const char expr[], int &pos);

int evaluate(const char expr[])
{
	int pos=0;
	findFirstToken(expr, pos);
	int result = 0;
	result = sum(expr, pos);
	return result;
}

int sum(const char expr[], int &pos)
{

	int result = multi(expr, pos);
	while (expr[pos] == '+' || expr[pos] == '-')
	{
		if (expr[pos] == '+')
		{
			advance(expr, pos);
			result = result + multi(expr, pos);
		}
		else if (expr[pos] == '-')
		{
			advance(expr, pos);
			result = result - multi(expr, pos);
		}
	}
	return result;
}

int multi(const char expr[], int &pos)
{

	int result = factor(expr, pos);
	while (expr[pos] == '*' || expr[pos] == '/' || expr[pos] == '%')
	{
		if (expr[pos] == '*')
		{
			advance(expr, pos);
			result = result * factor(expr, pos);
		}
		else if (expr[pos] == '/')
		{
			advance(expr, pos);
			result = result / factor(expr, pos);
		}
		else if (expr[pos] == '%')
		{
			advance(expr, pos);
			result = result % factor(expr, pos);
		}
	}
	return result;
}

int factor(const char expr[], int &pos)
{
	int result = 0;
	if (currentIsInteger(expr, pos) == true)
	{
		result = integerValue(expr, pos);
		advance(expr, pos);
	}
	else
	{



		advance(expr, pos);
		result = sum(expr, pos);
		advance(expr, pos);
	}
	return result;
}






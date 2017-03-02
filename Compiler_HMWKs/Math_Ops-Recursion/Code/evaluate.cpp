// Simple expession Evaluation Implementation file
// This describes the functionality for evaluating very simple
// arithmetic expessions.  Given a string consisting of operators
// and operands, it will evaluate that expession and return its value.
//
// The expessions may consist of the following:
// -- single-digit integer values
// -- simple arithmetic operators ( +, -, *, /, % )
// -- matched parentheses for grouping

// This implementation consists of a set of mutually-recursive 
// functions. which will track the structure of the expession.
//
// A sum expession is the sum or difference of one or more products.
// A product expession is the product or quotient of one or more factors.
// A factor may be a number or a parenthesized sum expession.





#include "tokenize.h"
#include <iostream>
int evaluate(const char exp[]);
void Next(const char exp[], int &pos, char &token);
int solve(const char exp[], int &pos);
int sequencer(const char exp[], int &pos, char &token);
bool multDivisionMod(char token);
int ArithmaticofDOOM(int x, char operationGuy, int y);



//Pre-condition: Given a string of single digit numbers and operations
//Post-condition: the answer to the equation, using proper order of 
//	operations
int evaluate(const char exp[])
{
	int pos = -1;
	return solve(exp, pos);
}


//starts the sequence of events and is pushed through by the sequencer 
int solve(const char exp[], int &pos)
{
	int sum = 0;
	char token = NULL;
	Next(exp, pos, token);
	
	sum = sequencer(exp, pos, token);
	Next(exp, pos, token);
		while (token != '\0'&& token != ')')
		{
			char operationGuy = token;

			
			Next(exp, pos, token);
			
				sum = ArithmaticofDOOM(sum, operationGuy,sequencer(exp, pos, token));
				Next(exp, pos, token);
		
		}
		
			return sum;

}//multiplies and divides till adition or subtraction begins
int sequencer(const char exp[], int &pos, char &token)
{
	int sum=0;
	if (isdigit(token))
	{
		
		sum = integerValue(exp,pos);
	}
	else 
		sum = solve(exp, pos);
	Next(exp, pos, token);
	while (multDivisionMod(token)) //does multiple terms
	{
		char operationGuy = token;
	
			Next(exp, pos, token);

	\
			
			if (token == '(')
				sum = ArithmaticofDOOM(sum, operationGuy, solve(exp, pos));
			else
				sum = ArithmaticofDOOM(sum, operationGuy, integerValue(exp, pos));

			Next(exp, pos, token);

		}
	pos--;
	while (exp[pos] == ' ')
	{
		pos--;
	}
	return sum;
}




// acually calculates x and y with the operator in the middle
	int ArithmaticofDOOM(int x, char operationGuy, int y)
	{
	


		if (operationGuy == '+')
		{
			return x + y;
		}
		if (operationGuy == '-')
		{
			return x - y;
		}
		if (operationGuy == '*')
		{
			return x * y;
		}
		if (operationGuy == '/')
		{
			return x / y;
		}
		if (operationGuy == '%')
		{
			return x % y;
		}

	}


	//makes sure token is not NULL +- or )
	bool multDivisionMod(char token)
	{
		if (token == '-')
			return false;
		else if(token == '+')
			return false;
		
		else if(token == ')')
			return false;
		else if(token == '\0')
			return false;
		
			return true;
	}



	// advances the position and assigns token with the current position of the array
void Next(const char exp[], int &pos, char &token)
{
	advance(exp, pos);
	token = currentToken(exp, pos);
}
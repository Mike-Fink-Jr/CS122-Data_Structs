// Simple Expression Evaluation 
// This program will evaluate simple arithmetic expressions
// represented as a linked-list of tokens.  Keyboard input
// will be accepted into a string, which will be converted
// into that linked list.
//
// If the first symbol in the input string is an operator,
// then the value of the previous expression will be taken
// as an implicit first operand.
//
// The expressions may consist of the following:
// -- integer values (which may have multiple digits)
// -- simple arithmetic operators ( +, -, *, /, % )
// -- matched parentheses for grouping

// This implementation consists of a set of mutually-recursive 
// functions. which will track the structure of the expression.
//
// A sum expression is the sum or difference of one or more products.
// A product expression is the product or quotient of one or more factors.
// A factor may be a number or a parenthesized sum expression.

#include <iostream>
using namespace std;
#include "tokenList.h"


int evaluate(const char expr[]);
int sum(ListIterator &itty);
int multi(ListIterator &itty);
int factor(ListIterator &itty);

int evaluate(const char expr[])
{
	TokenList list(expr);
	ListIterator itty = list.begin();

	int result = 0;
	result = sum(itty);
	return result;
}

int sum(ListIterator &itty)
{

	int result = multi(itty);
	while (itty.tokenChar() == '+' || itty.tokenChar() == '-')
	{
		if (itty.tokenChar() == '+')
		{
			itty.advance();
			result = result + multi(itty);
		}
		else if (itty.tokenChar() == '-')
		{
			itty.advance();
			result = result - multi(itty);
		}
	}
	return result;
}

int multi(ListIterator &itty)
{

	int result = factor(itty);
	while (itty.tokenChar() == '*' || itty.tokenChar() == '/' || itty.tokenChar() == '%')
	{
		if (itty.tokenChar() == '*')
		{
			itty.advance();
			result = result * factor(itty);
		}
		else if (itty.tokenChar() == '/')
		{
			itty.advance();
			result = result / factor(itty);
		}
		else if (itty.tokenChar() == '%')
		{
			itty.advance();
			result = result % factor(itty);
		}
	}
	return result;
}

int factor(ListIterator &itty)
{
	int result = 0;
	if (itty.currentIsInteger() == true)
	{
		result = itty.integerValue();
		itty.advance();
	}
	else
	{
		itty.advance();
		result = sum(itty);
		itty.advance();
	}
	return result;
}
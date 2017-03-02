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
#include "vartree.h"

int evaluate(const char expr[], VarTree &tree);
int sum(ListIterator &itty, VarTree &tree);
int multi(ListIterator &itty, VarTree &tree);
int factor(ListIterator &itty, VarTree &tree);
int assignment(ListIterator&itty, VarTree &tree, int);


int evaluate(const char expr[], VarTree &tree)
{
	TokenList list(expr);
	ListIterator itty = list.begin();
	if ((int)itty.tokenChar() == 32)
	itty.advance();
	int result = 0;
	result = sum(itty,tree);
	return result;
}

int sum(ListIterator &itty, VarTree &tree)
{

	int result = multi(itty,tree);
	while (itty.tokenChar() == '+' || itty.tokenChar() == '-')
	{
		if (itty.tokenChar() == '+')
		{
			itty.advance();
			result = result + multi(itty, tree);
		}
		else if (itty.tokenChar() == '-')
		{
			itty.advance();
			result = result - multi(itty, tree);
		}
	}
	return result;
}

int multi(ListIterator &itty, VarTree &tree)
{

	int result = factor(itty,tree);
	while (itty.tokenChar() == '*' || itty.tokenChar() == '/' || itty.tokenChar() == '%')
	{
		if (itty.tokenChar() == '*')
		{
			itty.advance();
			result = result * factor(itty, tree);
		}
		else if (itty.tokenChar() == '/')
		{
			itty.advance();
			result = result / factor(itty, tree );
		}
		else if (itty.tokenChar() == '%')
		{
			itty.advance();
			result = result % factor(itty, tree);
		}
	}
	return result;
}

int factor(ListIterator &itty, VarTree &tree)
{
	int result = 0;
	int Char = (int)itty.tokenChar();
	if (Char > 64 && Char < 89 || Char>96 && Char < 123)// checks all letter chars
	{
		result=assignment(itty,tree, Char);
		
	}
	else if (itty.currentIsInteger() == true)
	{
		result = itty.integerValue();
		itty.advance();
	}
	else
	{
		itty.advance();
		result = sum(itty, tree);
		itty.advance();
	}
	return result;
}

int assignment(ListIterator&itty, VarTree &tree, int Char)
{
	string name = "";
	int value = 0;
	while (Char > 64 && Char < 89 || Char>96 && Char < 123) // checks all letter chars
	{
		name += itty.tokenChar();
		itty.advance();
		Char = (int)itty.tokenChar();
	}
	if (Char == 61)//61 ASCII is '='
	{
		itty.advance();
	
		value = sum(itty, tree);
			
			tree.assign(name, value);
		

	}
		
		
		return	tree.lookup(name);

		

}

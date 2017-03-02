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
#include "tokenlist.h"
#include "exprtree.h"
#include "funmap.h"
using namespace std;



int evaluate(const char expr[], VarTree &var, FunctionDef &fun);
ExprNode* relation(ListIterator &itty, VarTree &var, FunctionDef &fun);
ExprNode* sum(ListIterator &itty, VarTree &var, FunctionDef &fun);
ExprNode* multi(ListIterator &itty, VarTree &var, FunctionDef &fun);
ExprNode* factor(ListIterator &itty, VarTree &var, FunctionDef &fun);
ExprNode* assignment(ListIterator&itty, VarTree &var, FunctionDef &fun, int Char);
ExprNode* condit(ListIterator &itty, VarTree &var, FunctionDef &fun);
void define(ListIterator& itty, VarTree&var, FunctionDef &fun, char Char);


int evaluate(const char expr[], VarTree &var, FunctionDef &fun)
{
	TokenList list(expr);
	ListIterator itty = list.begin();

	ExprNode* result = NULL;
	result = condit(itty, var, fun);
	if (result != NULL)
		//return result->;
		return result->evaluate(var, fun);
	else
		return 0;
}

ExprNode* condit(ListIterator &itty, VarTree &var, FunctionDef &fun)
{
	ExprNode*  itch = NULL, *itchTrue, *itchFalse;   // im itchin to be done
	itch = relation(itty, var, fun);
	while (itty.tokenChar() == '?')
	{
		itty.advance();
		itchTrue = relation(itty, var, fun);
		while (itty.tokenChar() != ':')
		{
			itty.advance();
		}
		itty.advance();
		itchFalse = relation(itty, var, fun);

		itch = new Conditional(itch, itchTrue, itchFalse);
	/*	if (itch->evaluate(var, fun) == 1)
		{
			return relation(itty, var, fun);
		}
		else{
			while (itty.tokenChar() != ':')
			{
				itty.advance();
			}
			itty.advance();
			return relation(itty, var, fun);
		}*/

	}return itch;
}

ExprNode* relation(ListIterator &itty, VarTree &var, FunctionDef &fun)
{

	ExprNode* result = sum(itty, var, fun);

	if (itty.tokenChar() == '>' || itty.tokenChar() == '<')
	{
		if (itty.tokenChar() == '>') //6 <= 5 ? 2+3 : 3*2
		{
			itty.advance();
			if (itty.tokenChar() == '=')
			{
				itty.advance();
				result = new Operation(result, "@", sum(itty, var, fun));   // '@'== '>='
			}
			else

			{
				//			result = result + multi(itty, tree);
				result = new Operation(result, ">", sum(itty, var, fun));
			}
		}


		else if (itty.tokenChar() == '<')
		{
			itty.advance();
			if (itty.tokenChar() == '=')
			{
				itty.advance();
				result = new Operation(result, "#", sum(itty, var, fun));   // '#'== '<='
			}
			else

			{

				//result = result - multi(itty, tree);
				result = new Operation(result, "<", sum(itty, var, fun));
			}
		}

	}
	else if (itty.tokenChar() == '!')
	{
		itty.advance();
		if (itty.tokenChar() == '=')
			itty.advance();
		result = new Operation(result, "!", sum(itty, var, fun)); //   '!' == '!='

	}
	else if (itty.tokenChar() == '=')
	{
		itty.advance();
		if (itty.tokenChar() == '=') //checks to make sure it isnt a assignment '='== '=='
		{
			itty.advance();
			result = new Operation(result, "=", sum(itty, var, fun));
		}
	}

	return result;
}



ExprNode* sum(ListIterator &itty, VarTree &var, FunctionDef &fun)
{

	ExprNode* result = multi(itty, var, fun);
	while (itty.tokenChar() == '+' || itty.tokenChar() == '-')
	{
		if (itty.tokenChar() == '+') //6 < 5 ? 2 : 3
		{
			itty.advance();
			//			result = result + multi(itty, tree);
			result = new Operation(result, "+", multi(itty, var, fun));
		}
		else if (itty.tokenChar() == '-')
		{
			itty.advance();
			//result = result - multi(itty, tree);
			result = new Operation(result, "-", multi(itty, var, fun));
		}
	}
	return result;
}

ExprNode* multi(ListIterator &itty, VarTree &var, FunctionDef &fun)
{

	ExprNode* result = factor(itty, var, fun);
	while (itty.tokenChar() == '*' || itty.tokenChar() == '/' || itty.tokenChar() == '%')
	{
		if (itty.tokenChar() == '*')
		{
			itty.advance();
			//result = result * factor(itty, tree);
			result = new Operation(result, "*", factor(itty, var, fun));
		}
		else if (itty.tokenChar() == '/')
		{
			itty.advance();
			//result = result / factor(itty, tree);
			result = new Operation(result, "/", factor(itty, var, fun));
		}
		else if (itty.tokenChar() == '%')
		{
			itty.advance();
			//result = result % factor(itty, tree);
			result = new Operation(result, "%", factor(itty, var, fun));
		}
	}
	return result;
}

ExprNode* factor(ListIterator &itty, VarTree &var, FunctionDef &fun)
{
	ExprNode* result = NULL;
	int Char = (int)itty.tokenChar();
	if (Char > 64 && Char < 89 || Char>96 && Char < 123)// checks all letter chars
	{
		result = assignment(itty, var,fun , Char);

	}
	else if (itty.currentIsInteger())
	{
		//	result = itty.integerValue();
		result = new Value(itty.integerValue());
		itty.advance();
	}
	else if (itty.tokenChar() == '-')
	{
		itty.advance();
		result = new Operation(new Value(0), "-", condit(itty, var, fun));
	}
	else
	{
		itty.advance();
		result = sum(itty, var, fun);
		itty.advance();
	}
	return result;
}

ExprNode* assignment(ListIterator&itty, VarTree &var, FunctionDef &fun, int Char)
{
	string name = "";
	ExprNode* arr[10];
	ExprNode* value = NULL;
	while (Char > 64 && Char < 89 || Char>96 && Char < 123) // checks all letter chars
	{
		name += itty.tokenChar();
		itty.advance();
		Char = (int)itty.tokenChar();

		if (name == "deffn")
		{
			define(itty, var, fun, Char);


			return NULL;

		}

		if (Char == '(') // means its a function call
		{
			itty.advance();//skips the '('
			//cout << "Char: " << Char << endl;
			for (int x = 0; x < 10 && Char != 41; x++)
			{
				arr[x] = condit(itty, var, fun);
				Char = itty.tokenChar();
				//cout << "Char: " << Char << endl;
			}
			return new function(name, arr);
		}



		if (Char == 61)//61 ASCII is '='
		{
			itty.advance();

			value = relation(itty, var, fun);

			var.assign(name, value->evaluate(var, fun));

			return new Value(var.lookup(name));
		}

	}
		value= new Variable(name);
		return value;



	
}
void define(ListIterator& itty, VarTree&var, FunctionDef &fun, char Char)
{
	FunDef whatchamadingy;


	//itty.advance();
	string name = "";


	while (Char > 64 && Char < 89 || Char>96 && Char < 123) // checks all letter chars
	{
		name += Char;
		itty.advance();
		Char = (int)itty.tokenChar();
	}
	whatchamadingy.name = name;
	itty.advance();
	Char = (int)itty.tokenChar();




	for (int x = 0; x < 10 && Char != ')'; x++)
	{

		name = "";
		while (Char > 64 && Char < 89 || Char>96 && Char < 123) // checks all letter chars
		{
			name += itty.tokenChar();
			itty.advance();
			Char = (int)itty.tokenChar();
		} 
		whatchamadingy.parameter[x] = name;

	}
	
	itty.advance();
	itty.advance();
	whatchamadingy.functionBody = condit(itty, var, fun);
	fun[whatchamadingy.name]=whatchamadingy;
	
}
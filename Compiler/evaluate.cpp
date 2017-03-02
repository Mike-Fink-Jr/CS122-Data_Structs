// Simple Expression Evaluation Implementation file
// This describes the functionality for evaluating very simple
// arithmetic expressions.  Given a string consisting of opers
// and operands, it will evaluate that expression and return its value.
//
// The expressions may consist of the following:
// -- single-digit integer values
// -- simple arithmetic opers ( +, -, *, /, % )
// -- matched parentheses for grouping

// This implementation consists of a set of mutually-recursive 
// functions. which will track the structure of the expression.
//
// A sum expression is the sum or difference of one or more products.
// A product expression is the product or quotient of one or more factors.
// A factor may be a number or a parenthesized sum expression.

#include <iostream>
using namespace std;
#include "tokenlist.h"
#include "exprtree.h"
#include "funmap.h"

void defineFunction(ListIterator &, FunctionDef &);
ExprNode* evaluateFunction(ListIterator &iter, FunctionDef &);
ExprNode* condit(ListIterator &iter, FunctionDef &funs);
ExprNode* Assignment(ListIterator & iter, FunctionDef &funs);
ExprNode* Sum( ListIterator & , FunctionDef &funs);	// prototypes all here
ExprNode* multi(ListIterator &, FunctionDef &funs);// since they are mutually
ExprNode* Factor(ListIterator &, FunctionDef &funs);	// recursive

// Evaluate
// Begins to tokenize the string, and then recursively evaluates it.
int evaluate( const char str[], VarTree &v , FunctionDef &funs)
{
    TokenList tl (str);
    ListIterator iter = tl.begin();

    ExprNode *node = Assignment( iter , funs);
	
	if(node->toString() != "3x1td3ffn")
	{
		return node->evaluate(v, funs);
	}
	else
		return 0;
}


void defineFunction(ListIterator &iter, FunctionDef &funs)
{
	FunDef fun;
	char oper;
	
	fun.name = iter.tokenText();
	iter.advance();

	oper = iter.tokenChar();
	for(int i = 0; i < 10 && (oper == '(' || oper == ','); i++)
	{
		iter.advance();
		fun.parameter[i] = Factor(iter, funs)->toString();
		oper = iter.tokenChar();
	}
	while(oper == ')' || oper == '=')
	{		
		iter.advance();
		oper = iter.tokenChar();
	}
	fun.functionBody = Assignment(iter, funs);
	fun.locals = new VarTree();
	funs[fun.name] = fun;
}

ExprNode* evaluateFunction(ListIterator & iter, FunctionDef &funs)
{

	char oper;
	ExprNode* parameter[10];
	ExprNode* node;
	string text;

	
	text = iter.tokenText();
	iter.advance();

	if(text == "deffn")
	{
		defineFunction(iter, funs);
		node = new Variable("3x1td3ffn");
	}
	else //evaluating a function or variable
	{
		string name = text;
		oper = iter.tokenChar();
		if(oper == '(')
		{
			for(int i = 0; i < 10 && (oper == '(' || oper == ','); i++)
			{
				iter.advance();
				parameter[i] = Assignment(iter, funs);
				oper = iter.tokenChar();
			}
		
			node = new Function(name, parameter);
			iter.advance();
		}
		else
		{
			node = new Variable(name);
		}
	}
	return node;
		
}

// Evaluate Assigments
// Evaluates an assignment expression and stores it in a variTree.
ExprNode* Assignment(ListIterator & iter, FunctionDef &funs)
{

	string oper;
	ExprNode* node;

	node = condit(iter, funs);
	if(node->toString() != "3x1td3ffn")
	{
		oper = iter.tokenText();
		while( oper.length() == 1 && oper[0] == '=' && node->toString() != "deffn")
		{
			
			iter.advance();
			if(oper[0] == '=')
				node = new Operation(node, "=", condit(iter, funs));
		
			oper = iter.tokenText();
		}
	}
	return node;
}

ExprNode* condit(ListIterator &iter, FunctionDef &funs)
{

	string oper;
	char opera;
	ExprNode* node, *rightTest, *trueCase, *falseCase;
	
	node = Sum(iter, funs);
	if(node->toString() != "3x1td3ffn")
	{
		oper = iter.tokenText();
		while(oper.length() == 2 && !(iter.tokenChar() > 'A' && iter.tokenChar() < 'Z' || iter.tokenChar() > 'a' && iter.tokenChar() < 'z') || oper[0] == '<' || oper[0] == '>')
		{
			iter.advance();
			if(iter.tokenChar() == '=')
				iter.advance(); //to get around the =
			rightTest = Sum(iter, funs);
			opera = iter.tokenChar();
			if(opera == '?')
			{
				iter.advance();
				trueCase = Sum(iter, funs);
				opera = iter.tokenChar();
				if(opera == ':')
				{
					iter.advance();
					falseCase = Sum(iter, funs);
					
					node = new Conditional(new Operation(node, oper, rightTest), trueCase, falseCase);
				}
				
			}
			else
			{
				iter.advance();		// get past the operator
    			if (oper[0] == '<')		// addition
					node = new Operation(node, "<", rightTest);
				else if (oper[0] == '>')
					node = new Operation(node, ">", rightTest);
			}
			oper = iter.tokenText();
		}
	}
	return node;
	
	
}


// EvaluateSum
// Evaluates a sum expression: the sum or difference of one or more products
// There may be the possibility of a leading - that would be implicitly
// subtracting the first product from zero.
ExprNode* Sum( ListIterator &iter , FunctionDef &funs)
{
	ExprNode* node;
    char oper;				// possible operation

	oper = iter.tokenChar();
    if (oper == '-')			// if negative
    {
		iter.advance();		//     go past the negative sign
		node = new Operation (new Value(0), "-", multi( iter, funs ));//and negate it
    }
    else
		node = multi( iter , funs);

	if(node->toString() != "3x1td3ffn")
	{
    	oper = iter.tokenChar();	// check for an addition operator
    	while (oper == '+' || oper == '-')
    	{
			iter.advance();		// get past the operator
    		if (oper == '+')		// addition
				node = new Operation(node, "+", multi(iter, funs));
			else				// subtraction
				node = new Operation(node, "-", multi(iter, funs));
			oper = iter.tokenChar();
    	}
	}
    return node;
}

// EvaluateProduct
// Evaluates a product expression: the product or quotient of factors
ExprNode* multi( ListIterator &iter , FunctionDef &funs)
{
	ExprNode* node;
    char oper;				// possible operation


    oper = iter.tokenChar();	// check for multiplication operator
	if (oper == '-')			// if negative
    {
		iter.advance();		//     go past the negative sign
		node = new Operation (new Value(0), "-", Factor( iter, funs ));	//	and negate it
    }
	else
	{
	    node = Factor( iter , funs);
	}

//	cout << "nodeProd: " << node->toString() << endl;
	if(node->toString() != "3x1td3ffn")
	{
//	cout << "not null" << endl;
		oper = iter.tokenChar();
	   	while (oper == '*' || oper == '/' || oper == '%')
    	{
			iter.advance();		// get past the operator
    		if (oper == '*')		// multiplication
				node = new Operation(node, "*", Factor(iter, funs));
    		else if (oper == '/')		// division
				node = new Operation(node, "/", Factor(iter, funs));
			else if (oper == '%')		// remainder
				node = new Operation(node, "%", Factor(iter, funs));
			oper = iter.tokenChar();
    	}
	}
//	else
//		cout << "Null node" << endl;
    return node;
}

// Evaluate Factor
// A factor may either be a single-digit number 
// or a parenthsized expression.
ExprNode* Factor( ListIterator &iter, FunctionDef &funs)
{
	ExprNode* node;

    if (iter.currentIsInteger())
    {
		node = new Value(iter.integerValue());
		iter.advance();		// get past the digit
    }
	else if(iter.tokenChar() >= 'A' && iter.tokenChar() <= 'Z' || iter.tokenChar() >= 'a' && iter.tokenChar() <= 'z')
	{

		node = evaluateFunction(iter, funs);
	}
    else
    {
		iter.advance();		// go past assumed (
		node = Assignment( iter, funs );
		iter.advance();		// go past assumed )
    }
    return node;
}
 

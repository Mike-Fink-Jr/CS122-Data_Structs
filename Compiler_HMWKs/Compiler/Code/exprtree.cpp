// Expression Tree Implementation File
// These functions manage an expression tree that describes
// arithmetic expressions using integer variables and values.
// Some functions construct a tree from a character string that
// represents the expression, and then the tree can be traversed
// and evaluated.
#include <iostream>
#include <sstream>
using namespace std;
#include "exprtree.h"
#include "tokenlist.h"

// Outputting any tree node will simply output its string version
ostream& operator<<( ostream &stream, const ExprNode &e )
{
    return stream << e.toString();
}

// A Value is just an integer value -- easy to evaluate
// Unfortunately, the string class does not have a constructor for it
string Value::toString() const
{
    ostringstream convert;	// output string stream
    convert << value;		// 'output' into the stream
    return convert.str();	// and extract its string equivalent
}

int Value::evaluate( VarTree &v , FunctionDef &f) const
{
    return value;
}

//  A variable is just an alphabetic string -- easy to display
//  To evaluate, would need to look it up in the data structure
string Variable::toString() const
{
    return name;
}

int Variable::evaluate( VarTree &v , FunctionDef &f) const
{
    return v.lookup( name );
}

string Operation::toString() const
{
	return oper;
}

int Operation::evaluate( VarTree &v, FunctionDef &f) const
{
	int lVal, rVal;
	if(oper.length() == 1)
	{
		if(oper[0] != '=')
		{
			lVal = left->evaluate(v, f);
			rVal = right->evaluate(v, f);
			switch(oper[0])
			{
			case '+':
				return lVal + rVal;
				break;
			case '-':
				return lVal - rVal;
				break;
			case '*':
				return lVal * rVal;
				break;
			case '/':
				return lVal / rVal;
				break;
			case '%':
				return lVal % rVal;
				break;
			case '<':
				return lVal < rVal;
				break;
			case '>':
				return lVal > rVal;
				break;		
			}
		}
		else
		{
			rVal = right->evaluate(v, f);
			v.assign(left->toString(), rVal);
			return rVal;
		}
	}
	else //we have a conditional expression!
	{
		lVal = left->evaluate(v, f);
		rVal = right->evaluate(v, f);
		switch(oper[0])
		{
			case '!':
				return lVal != rVal;
				break;
			case '<':
				return lVal <= rVal;
				break;
			case '>':
				return lVal >= rVal;
				break;
			case '=':
				return lVal == rVal;
				break;
		}
	}
}

string Conditional::toString() const
{
	ostringstream convert;	
    convert << test->toString() << " ? " << trueCase->toString() << " : " << falseCase->toString();		
    return convert.str();	
}

int Conditional::evaluate( VarTree &v, FunctionDef &f) const
{
	bool t = test->evaluate(v, f);
	if(t)
	{
		return trueCase->evaluate(v, f);
	}
	else
	{
		return falseCase->evaluate(v, f);
	}
}

string Function::toString() const
{
	return name;
}

int Function::evaluate(VarTree &v, FunctionDef &f) const
{
	FunDef fun = f[name];
	for(int i =0; i < 10 && fun.parameter[i] != ""; i++)
	{
		fun.locals->assign(fun.parameter[i], parameter[i]->evaluate(v,f));
	}
	return fun.functionBody->evaluate(*(fun.locals), f);
}


// Expression Tree Implementation File
// These functions manage an expression tree that describes
// arithmetic expressions using integer variables and values.
// Some functions construct a tree from a character string that
// represents the expression, and then the tree can be traversed
// and evaluated.
#include <iostream>
#include <sstream>

#include "exprtree.h"
#include "tokenlist.h"
using namespace std;
// Outputting any tree node will simply output its string version
ostream& operator<<(ostream &stream, const ExprNode &e)
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

int Value::evaluate(VarTree &v, FunctionDef &D)  const
{
	return value;
}

//  A variable is just an alphabetic string -- easy to display
//  TO evaluate, would need to look it up in the data structure
string Variable::toString() const
{
	return name;
}

int Variable::evaluate(VarTree &v, FunctionDef &D) const
{
	return v.lookup(name);
}

string Operation::toString() const
{
	ostringstream convert;	// output string stream
	convert << left->toString() << " " << oper << " " << right->toString();		// 'output' into the stream
	return convert.str();	// and extract its string equivalent
}

int Operation::evaluate(VarTree &v, FunctionDef &D) const
{
	if (oper[0] == '>')
		if (left->evaluate(v, D) > right->evaluate(v, D))
			return 1;
		else return 0;

	else if (oper[0] == '<')
		if (left->evaluate(v, D) < right->evaluate(v, D))
			return 1;
		else return 0;

	else if (oper[0] == '@')
		if (left->evaluate(v, D) >= right->evaluate(v, D))
			return 1;
		else return 0;

	else if (oper[0] == '#')
		if (left->evaluate(v, D) <= right->evaluate(v, D))
			return 1;
		else return 0;


	else if (oper[0] == '!')
		if (left->evaluate(v, D) != right->evaluate(v, D))
			return 1;
		else return 0;

	else if (oper[0] == '=')
		if (left->evaluate(v,D) == right->evaluate(v, D))
			return 1;
		else return 0;






	else if (oper[0] == '+')
		return left->evaluate(v, D) + right->evaluate(v, D);

	else if (oper[0] == '-')
		return left->evaluate(v, D) - right->evaluate(v, D);

	else if (oper[0] == '*')
		return left->evaluate(v,D ) * right->evaluate(v,D);

	else if (oper[0] == '/')
		return left->evaluate(v,D) / right->evaluate(v,D);

	else if (oper[0] == '%')
		return left->evaluate(v, D) % right->evaluate(v, D);

	return -1;
}

string Conditional::toString()const
{
	return test->toString();
}

int Conditional::evaluate(VarTree &v, FunctionDef &D)const
{
	if (test->evaluate(v, D))
		return trueCase->evaluate(v, D);
	else
		return falseCase->evaluate(v, D);
}

string function::toString() const
{
	return s;	
}

int function::evaluate(VarTree &v, FunctionDef &D) const
{
	FunDef temp = D[s];
	temp.locals = new VarTree();
	for (int x=0; x < 10 && temp.parameter[x] != ""; x++)
	{
		temp.locals->assign(temp.parameter[x], n[x]->evaluate(v, D));
	}
	return temp.functionBody->evaluate(*(temp.locals), D);



}
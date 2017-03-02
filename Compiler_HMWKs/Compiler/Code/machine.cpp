// Machine Implementation File
// This implementation represents a simple machine that can evaluate
// arithmetic expressions.  In addition to the expected arithmetic
// operations, it includes relational operations and branching
// for the conditional operator, and simple support for function calls.
//
// The machine is expected to have a pre-allocated stack space
// for named variables and an arbitrarily long list of temporary
// registers, both represented by integer arrays here (to hold values).
// The machine also has a separate memory area holding all of the
// instructions defined below.

#include <iostream>
#include <sstream>
using namespace std;

#include "machine.h"

ostream& operator<<( ostream &stream, const Instruction &i )
{
    return stream << i.toString();
}

string Print::toString() const
{
	ostringstream convert;
	convert << valueTemp;
	return convert.str(); 
}

void Print::execute(int[]  , int[]  , int&, int&) const
{
	//mehhhh
}

string Compute::toString() const
{
	ostringstream convert;	
	convert << argA << " " << oper << " " << argB;		
	return convert.str();	
}

void Add::execute(int[]  , int[]  , int&, int&) const
{
	cout << "add " << (argA + argB) << endl;
}

void Subtract::execute(int[]  , int[]  , int&, int&) const
{
	
cout << "subtract " << (argA - argB) << endl;
}

void Multiply::execute(int[]  , int[]  , int&, int&) const
{
	
cout << "multiply " << (argA * argB) << endl;
}

void Divide::execute(int[]  , int[]  , int&, int&) const
{
	
cout << "divide " << (argA / argB) << endl;
}

void Modulus::execute(int[]  , int[]  , int&, int&) const
{
	
cout << "modulous " << (argA % argB) << endl;
}

void Value::execute(int[], int[], int&, int&) const
{
	cout << "value " << (argA) << endl;
}

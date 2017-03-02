#include <iostream>

#include "evaluate.h"
using namespace std;
int main()
{
	char userInput[80];
	VarTree vars;		// initially empty tree
	FunctionDef funs;
	cout << "deffn sqr(x) = x*x" << endl;
	evaluate("deffn sqr(x) = x*x", vars, funs);
	cout << "sqr(5): " << evaluate("sqr(5)", vars, funs) << endl;

	cout << "\n\ndeffn abs(x) = x > 0 ? x : -x" << endl;
	evaluate("deffn abs(x) = x > 0 ? x : -x", vars, funs);
	cout << "Three = abs(0-3): " << evaluate("Three =  abs(0-3) ", vars, funs) << endl;
	
	cout << "\n\ndeffn fact(n) = n <= 1 ? 1 : n * fact(n-1)" << endl;
	evaluate("deffn fact(n) = n <= 1 ? 1 : n * fact(n-1)", vars, funs);
	cout << "Fact(3): " << evaluate("fact(3)", vars, funs) << endl;

	cout << endl << "Try one yourself:  ";
	cin.getline(userInput, 80);
	cout << userInput << " = " << evaluate(userInput, vars, funs) << endl;
	cout << endl << "Try another:  ";

	cin.getline(userInput, 80);
	cout << userInput << " = " << evaluate(userInput, vars, funs) << endl;
}
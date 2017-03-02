




#include "compile.h"
#include "tokenlist.h"
using namespace std;


int compileSum( ListIterator &iter, Instruction *prog[], int &pBegin, int &pEnd);
int compileProduct( ListIterator &iter, Instruction *prog[], int &pBegin, int &pEnd);
int compileFactor( ListIterator &iter, Instruction *prog[], int &pBegin, int &pEnd);

// Compile
// Compile the given expression into a machine code, with 
// the given variables defined
// New variables may be defined when this function is called
// Parameters:
//	expr	(input char array)	expression to evaluate
//	vars	(modified VarTree)	variables to work with
//	funs	(modified FunctionDef)	functions to define or call
//	prog	(modified Inst array)	program code being generated
//	pBegin	(output integer)	first instruction not in a function
//	pEnd	(output integer)	program end (first unused spot)
void compile( const char expr[], VarTree &vars, FunctionDef &funs, Instruction *prog[], int &pBegin, int &pEnd )
{
	
	TokenList tl (expr);
    ListIterator iter = tl.begin();

	compileSum(iter, prog, pBegin, pEnd);
	pBegin = 0;
	



//	for(int i = pBegin; i < pEnd; i++)	
	//	prog[i].execute(/*arguments*/); 
	
}



//this all needs to go in here to evaluate simple addition and subtraction, but not sure what it should be doing yet, other than generating instructions for me to evaluate at the end.
//since it's recursive, things should get added to the instruction list in the correct order so that I just have to execute every statement in the prog array in order at the end.

// EvaluateSum
// Evaluates a sum expression: the sum or difference of one or more products
// There may be the possibility of a leading - that would be implicitly
// subtracting the first product from zero.
int compileSum( ListIterator &iter, Instruction *prog[], int &pBegin, int &pEnd)
{

    int val;				// value of sum so far
    char oper;				// possible operation

	oper = iter.tokenChar();

		val = compileProduct( iter , prog, pBegin, pEnd);


    	oper = iter.tokenChar();	
    	while (oper == '+' || oper == '-')
    	{
			iter.advance();		
    		if (oper == '+')		
				prog[pEnd] = new Add(0, val, compileProduct(iter, prog, pBegin, pEnd));
			else				
				prog[pEnd] = new Subtract(0, val, compileProduct(iter, prog, pBegin, pEnd));
			oper = iter.tokenChar();
			val = pEnd; 
			pEnd++; 
    	}
    return  val;
}

// EvaluateProduct
// Evaluates a product expression: the product or quotient of factors
int compileProduct( ListIterator &iter ,  Instruction *prog[], int &pBegin, int &pEnd)
{
    int val;				// value of sum so far
    char oper;				// possible operation


  oper = iter.tokenChar();
 
		;val = compileFactor( iter , prog, pBegin, pEnd);

		oper = iter.tokenChar();
	   	while (oper == '*' || oper == '/' || oper == '%')
    	{
			iter.advance();		
    		if (oper == '*')		
				prog[pEnd] = new Multiply(0, val, compileFactor(iter, prog, pBegin, pEnd));
    		else if (oper == '/')		
				prog[pEnd] = new Divide(0, val, compileFactor(iter, prog, pBegin, pEnd));
			else if (oper == '%')		
				prog[pEnd] = new Modulus(0, val, compileFactor(iter, prog, pBegin, pEnd));
			oper = iter.tokenChar();
			val = pEnd; 
			pEnd++;
    	}
    return val;
}

// Evaluate Factor
// A factor may either be a single-digit number 
// or a parenthsized expression.
int compileFactor( ListIterator &iter,  Instruction *prog[], int &pBegin, int &pEnd)
{
    char next;
    int val;				// value of the factor
    if (iter.currentIsInteger())
    {

		val = iter.integerValue();
		iter.advance();		
    }
	else if(iter.tokenChar() >= 'A' && iter.tokenChar() <= 'Z' || iter.tokenChar() >= 'a' && iter.tokenChar() <= 'z')
	{

//		node = new Variable(iter.tokenText());
		
	}
    else
    {
		iter.advance();		
		val = compileSum( iter, prog, pBegin, pEnd);
		iter.advance();		
    }
    return val;
}

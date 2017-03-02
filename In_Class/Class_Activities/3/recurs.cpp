// This program file consists of several simple recursive functions
// that can be transformed into iterative functions (loops).
// One could conceivably start with a loop implementation,
// but the point of this exercise is to demonstrate a process
// that can be applied to many functions originally conceived recursively.
#include <iostream>
using namespace std;

// The initially-recursive functions to work with today
void reverseInput();
double power( double, int );
double powerExpr();

int main()
{
    cout << "Input no more than 10 integers, ending with 0:" << endl;
    reverseInput();
    cout << endl;		// to end output line

    cout << "2 ^ 15 = " << power( 2, 15) << endl;
    cout << "0.1 ^ 3 = " << power( 0.1, 3) << endl;
    cout << "10 ^ -3 = " << power( 10, -3) << endl;

    cout << "Input two integer exponentiation expressions." << endl;
    cout << "These will use ^ for exponent and end with ;" << endl;
    cout << "For example, '2^2^3;' evaluates to 2^8, or 256" << endl;
    cout << powerExpr() << endl;
    cout << powerExpr() << endl;

    return 0;
}

//  reverseInput:
//  accepts a series of integer inputs and displays them in reverse order
//  Parameters:		None!
//  Pre-condition:	all inputs are integer values
//  			there are no more than 10 inputs, ending with 0
void reverseInput()
{
    int value;
    cin >> value;		// examine next input
    if (value != 0)		// non zero, get more input
    {
	reverseInput();	
	cout << " " << value;
    }
    else
	cout << "Reversed data: ";
}

//  power:
//  a quicker way to exponentiate to an integer power
//  this implementation supports negative exponents
//  Parameters:
//  	base	 (input double)		value to exponentiate
//  	exponent (input integer)	exponent to use
//  Pre-condition:
//  	if exponent is negative, base is non=zero
double power( double base, int exponent )
{
    if (exponent == 0)			// 0'th power
	return 1;
    else if (exponent < 1)		// negative exponent - reciprocate
        return 1 / power ( base, -exponent );
    else if (exponent % 2 == 0)		// even exponent is a square
	return power( base*base, exponent / 2 );
    else
	return base * power ( base*base, exponent / 2 );
}

//  powerExpr:
//  evaluates an expression that includes one or more
//  exponentiation operations, using the ^ symbol for exponent.
//  Unlike most operators, this operation is right-associative.
//  That is, the expression 2 ^ 3 ^ 2 computes 2 ^ 9, not 8 ^ 2
//
//  Parameters:		None!		(input stream)
//  Pre-condition:      Input consists of nothing but integers and ^
//			in a valid syntax, followed by ;
double powerExpr()
{
    int value;		// value from input
    char oper;		// input operator, if any

    cin >> value;	// get the value
    if ( cin >> oper && oper == '^' )	
	return power( value, static_cast<int>( powerExpr() ) );
    else
	return value;
}

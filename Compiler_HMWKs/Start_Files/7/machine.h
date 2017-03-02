// A simple RISC machine
// This structure represents a simple machine that can evaluate
// arithmetic expressions.  In addition to the expected arithmetic
// operations, it includes relational operations and branching
// for the conditional operator, and simple support for function calls.
//
// The machine is expected to have a pre-allocated stack space
// for named variables and an arbitrarily long list of temporary
// registers, both represented by integer arrays here (to hold values).
// The machine also has a separate memory area holding all of the
// instructions defined below.
//
// Most of these instructions are also immutable -- once constructed,
// they cannot be changed -- only displayed and executed.

#include <iostream>
using namespace std;

class Instruction
{
   protected:
	int valueTemp;		// register computed or tested
				// additional fields defined later
	Instruction( int temp )
	{
	    valueTemp = temp;
	}
   public:
	friend ostream& operator<<( ostream&, const Instruction & );
	virtual string toString() const { } // facilitates << operator
	virtual void execute( int [], int [], int &, int &  ) const { }
};

// here follow all the derived classes defining additional
// memory variables as necessary, and declaring the two functions
// above that will actually be implemented in "machine.cpp"

// one simple example is given here:
class Print: public Instruction
{
   public:
	string toString() const;
	void execute( int [], int [], int &, int & ) const;
	Print( int temp ) : Instruction(temp) { }
};

// also, as was pointed out in the assignment description,
// all of the arithmetic instructions are very simple and can
// be made children of a more general class (not defined here yet)
// All that is declared here is a new override to the execute method,
// and a constructor that simply calls the constructor for Compute,
// passing along all three relevant registers and the addition symbol.

class Add: public Compute
{
   public:
	void execute( int [], int [], int &, int & ) const;
	Add( int result, int argA, int argB ) : 
		Compute(result, argA, argB, "+" ) { }
	};

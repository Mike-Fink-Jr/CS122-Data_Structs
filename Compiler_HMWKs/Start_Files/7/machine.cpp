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

//  Here follow implementations of toString() and execute()
//  for all of the derived classes of the Instruction.

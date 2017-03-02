// Tokenize Implementation file
// This is a very crude tokenizer for use in an expression parser.
// At the moment, it is simply a collection of functions that
// that will later be encapsulated into an object-oriented class.
// It has only a very rudimentary behavior at this time.
//
// This tokenizer will begin with a character string representing
// an expression, and will identify and return tokens as requested.
// These tokens may be separated by space characters within the string.
// It has the following limitations:
// --- only integers and operators are supported (no names)
// --- all tokens must be exactly one character, including integers

// The standard C library has some useful functions for us
#include <string.h>
#include <ctype.h>

// nextToken
// Identifies the next non-space character in the given string
// Parameters:
//      expr    (input string)          expression to examine
//      pos     (modified integer)      position to begin looking at
//      token   (output char)		the actual non-space character
// Post-condition:  token == expr[pos] && token is not a space
void nextToken( const char expr[], int &pos, char &token )
{



}

// advance
// advance to after the end of the next token (as defined above)
// Parameters:
//      expr    (input string)          expression to examine
//      pos     (modified integer)      position to consider
// Pre-condition:
//      There is at least one token remaining;   if not,
//      this will stop at the end of the string
// NOTE: If expr[pos] is non-space, this will advance exactly one position
//
// advance to the following token in the string (if any)
void advance( const char expr[], int &pos )
{




}

// identify whether token is an integer or operator
// Parameter:		character to examine
// Returns:		boolean, depending on the question
bool isInteger( char c )
{
    return isdigit( c );
}

// identify the value of an integer token
// Parameter:		character to examine
// Returns:		the numeric value of the digit
// Pre-condition: the character actually is indeed a numeric digit
int integerValue( char c )
{
    return c - '0';
}

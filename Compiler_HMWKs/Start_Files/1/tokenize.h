// Tokenize Header file
// This is a very crude tokenizer for use in an expression parser.
// At the moment, it is simply a collection of functions that
// will later be encapsulated into an object-oriented class.
// It has only a very rudimentary behavior at this time.
//
// This tokenizer will begin with a character string representing
// an expression, and will identify and return tokens as requested.
// These tokens may be separated by space characters within the string.
// It has the following limitations:
// --- only integers and operators are supported (no names)
// --- all tokens must be exactly one character, including integers

// nextToken
// Identifies the next non-space character in the given string
// Parameters:
// 	expr	(input string)		expression to examine
// 	pos	(modifiedinteger)	position to begin looking at
// 	token   (output char)		the actual token
// Post-Condition:  token == expr[pos] && token is not a space
// NOTE:  This function returns a null character (0) if none remain
void nextToken( const char expr[], int &pos, char &token );

// advance
// advance to after the end of the next token (as defined above)
// Parameters:
// 	expr	(input string)		expression to examine
// 	pos	(modified integer)	position to consider
// Pre-condition:
// 	There is at least one token remaining;   if not,
// 	this will stop at the end of the string
// NOTE: If expr[pos] is non-space, this will advance exactly one position
void advance( const char expr[], int &pos );

// identify whether given token is an integer
// Parameter:		character to examine
// Returns:		boolean, true if an integer, false if note
bool isInteger( char );

// identify the value of a numeric digit
// Parameter:		character to examine
// Returns:		an integer value between 0 to 9
// Pre-condition: The parameter is assumed to actually be a digit
int  integerValue( char );

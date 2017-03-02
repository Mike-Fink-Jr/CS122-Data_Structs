// Token List Implementation file
//
// This tokenizer will scan a character string representing
// an expression, and will return a list of tokens.
// --- only integers and operators are supported (no names)

// The standard C library has some useful functions for us
#include <string.h>
#include <ctype.h>

// And to get the definition of a token:
#include "tokenlist.h"

//  output operation
//  Display all of the tokens in the list
ostream& operator<<( ostream &stream, TokenList &t )
{
    ListElement *curr;
    for (curr = t.head; curr != NULL; curr = curr->next)
    {
	stream << " " << curr->token;
    }
    return stream;
}

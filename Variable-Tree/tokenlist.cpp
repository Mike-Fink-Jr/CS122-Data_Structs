// Token List Implementation file
// Not a true linked list; just support for iterators
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
#include "tokenlist.h"

//  output operation
//  Display all of the tokens in the list
//  Parameters:
//  	stream	(modified output stream)	where to output to
//	t	(input reference to TokenList)	what to output
//  Returns:
//  	output stream, for use by additional << operators
ostream& operator<<(ostream &stream, TokenList &t)
{
	for (ListIterator iter = t.begin(); iter != t.end(); iter.advance())
	{
		if (iter.currentIsInteger())		// output a number
			stream << iter.integerValue() << " ";
		else					// output a character
			stream << iter.tokenChar() << " ";
	}
	return stream;
}

//  begin
//  Creates an iterator to refer to the beginning of the data
//  HINT:  This does the same thing as "findFirstToken"
ListIterator TokenList::begin()
{
	int pos = 0;

	//  to be completed

	return ListIterator(this, &data[pos]);
}

//  end
//  Creates an iterator to refer to the end of the data
//  The end is indicated by a null character in the array.
ListIterator TokenList::end()
{
	return ListIterator(this, &data[strlen(data)]);
}

//  advance
//  moves the iterator to the next token
//  (indicated by a non-space character)
//  NOTE:  The current token could have been a number with multiple digits
void ListIterator::advance()
{

	if (currentIsInteger())
	{
		curr++;

		while (currentIsInteger())
			curr++;
		while (*curr == ' ')
			curr++;
	}
	else
	{
		curr++;
		while (*curr == ' ')
			curr++;
	}
	// to be completed

}

void ListIterator::retreat()
{
	curr--;
	while (*curr == ' ');
	curr--;



	if (currentIsInteger())
	{

		while (*this != list->begin() && currentIsInteger())
			curr--;


		if (*this != list->begin())
			curr++;
		// Extra Credit option
	}
}
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
ostream& operator<<( ostream &stream, TokenList &t )
{
    for (ListIterator iter = t.begin(); iter != t.end(); iter.advance() )
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
	for( ; data[pos] == ' '; pos++);
	return ListIterator( this, &data[pos] );
}

//  end
//  Creates an iterator to refer to the end of the data
//  The end is indicated by a null character in the array.
ListIterator TokenList::end()
{
	int pos = 0;
	for( ; data[pos] != '\0'; pos++);
	return ListIterator( this, &data[strlen(data)] );
}

//  advance
//  moves the iterator to the next token
//  (indicated by a non-space character)
//  NOTE:  The current token could have been a number with multiple digits
void ListIterator::advance()	
{
	
	int pos = 0;
	for( ; &list->data[pos] != curr; pos++);
	pos++;		
	if(*curr <= '9' && *curr >= '0')
		for( ; list->data[pos] == ' ' || (list->data[pos] <= '9' && list->data[pos] >= '0'); pos++);//skips spaces and numbers
	else if((*curr >= 'A' && *curr <= 'Z' || *curr >= 'a' && *curr <= 'z') || *curr == '!' || (*curr >= '<' && *curr <= '?'))
	{
		for( ;/* list->data[pos] == ' ' ||*/ (list->data[pos] >= 'A' && list->data[pos] <= 'Z' || list->data[pos] >= 'a' && list->data[pos] <= 'z') || list->data[pos] == '!' || (list->data[pos] >= '<' && list->data[pos] <= '?' && list->data[pos] != '='); pos++);//skip only letters
		for(; list->data[pos] == ' '; pos++);	//then skip only spaces
	}
	else
		for( ; list->data[pos] == ' '; pos++); //only skips spaces
	curr = &list->data[pos];
//	cout << "curr: " << *curr << endl;
}

void ListIterator::retreat()
{

	int pos = 0;
	for( ; list->data[pos] != '\0'; pos++);
	for( ; &list->data[pos] != curr; pos--);
	pos--;		
	if(*curr <= '9' && *curr >= '0')
		for( ; list->data[pos] == ' ' || (list->data[pos] <= '9' && list->data[pos] >= '0'); pos--);//skips spaces and numbers
	else
		for( ; list->data[pos] == ' '; pos--); //only skips spaces
	curr = &list->data[pos];
}


//1920: this shouldn't advance.  That should be left to the advance function.
//this should only return a string, leaving the iterator in the same place.
//advance, when called from evaluate, should then advance the iterator past 
//the string.
//1924: this should work, but now I need to change the advance function to 
//skip over all of this junk.
string ListIterator::tokenText()
{
	std::string str = "";
	
	int pos = 0;
	for( ; &list->data[pos] != curr; pos++);
	str += list->data[pos];
	while((list->data[pos+1] >= 'A' && list->data[pos+1] <= 'Z' || list->data[pos+1] >= 'a' && list->data[pos+1] <= 'z') || list->data[pos+1] == '!' || (list->data[pos+1] >= '<' && list->data[pos+1] <= '?'))
	{
		pos++;
		str += list->data[pos];
	}
//	cout << "str: " << str << endl;;
	return str;
}




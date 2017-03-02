// A program that inserts and removes from linked lists
// for practice in maintaining these lists.
// A more complete program would worry more about
// allocation and deallocation; this one simply maintains links.
#include <iostream>
using namespace std;

#include "linked.h"

int main()
{
    int initialData[] = { 2, 3, 5, 6 };
    SingleList sample(initialData, 4);
    ListIterator iter = sample.begin();

    // print the list as it appears
    sample.print();

    // locate the 5, and then insert a 4 before the 5
    iter = sample.find(5);
    sample.insert( iter, 4 );
    sample.print();			// check 4 insertion

    // insert a 1 at the beginning and 8 at the end
  
  

    sample.print();			// check 1 and 8 insertions

    // display all even values


    // duplicate all even values



    sample.print();			// check effect of duplication

    // remove all even values



    sample.print();			// check effect of removal
}

//  prints the contents of a single-linked list
void SingleList::print()
{
    ListIterator l = begin();
    while (false)				// condition must change!
    {
	cout << l.value() << " ";		// display this one
	l.advance();				// move on to the next
    }
    cout << endl;
}

ListIterator SingleList::find( int value )
{
    ListIterator l = begin();
    while (false)				// condition must change!
	l.advance();				// keep looking
    return l;
}

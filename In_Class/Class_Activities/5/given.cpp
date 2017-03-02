// Some of the methods for a linked class tutorial
// that are being given for free, to reducec lutter
// in the file to be used for an actual grade.

#include <iostream>
using namespace std;
#include "linked.h"

//  Creates a single linked list from an array
SingleList::SingleList( int values[], int size )
{
    SingleNode *curr;

    head = new SingleNode(values[0]);
    curr = head;
    for (int i=1; i<size; i++)
	curr = curr->next = new SingleNode(values[i]);
    tail = curr;   
}

//  Creates an iterator to refer to the beginning of the list
ListIterator SingleList::begin()
{
    return ListIterator( this, head, NULL );
}

//  Creates an iterator to refer after the end of the list
//  (The tail node is followed by a NULL pointer)
ListIterator SingleList::end()
{
    return ListIterator( this, NULL, tail );
}

//  inserts a new element into single-linked list
//  Parameters:
//  	pos	 (modified iterator)	where to insert new value
//  	newValue (input integer)	new value to insert
//  The new value may be at the beginning or the end
//  or somewhere in between (precisely at pos)
//  Returns:		an iterator referring to new insertion
//  Pre-condition:	pos is actually assocated with this list
ListIterator SingleList::insert( ListIterator pos, int newValue )
{
    SingleNode *newNode = new SingleNode( newValue );
    newNode->next = pos.curr;			// new node precedes current
    if (pos.prev == NULL)			// if adding to front
	head = newNode;				//    update head
    else					// else link to
	pos.prev->next = newNode;		//    predecessor
    if (pos.curr == NULL)			// if adding to end
        tail = newNode;				//    update tail
    return ListIterator( this, newNode, pos.prev );
}

//  removes an element from a single-linked list
//  Parameter:
//  	pos	(modified iterator)	which value to remove
//  Returns:		an iterator referring past removed element
//  Pre-condition:	pos is actually associated with this list
//  			and refers to an actual element (not end() )
ListIterator SingleList::erase( ListIterator pos )
{
    SingleNode *removal = pos.curr;
    SingleNode *successor = pos.curr->next;
    if (pos.curr == tail)		// if removing last node
	tail = pos.prev;		//    back up
    if (pos.prev == NULL)		// if removing from head
	head = successor;		//    advance that
    else				// else
	pos.prev->next = successor;	//    relink predecessor
    delete removal;
    return ListIterator( this, successor, pos.prev );
}


// A program that inserts and removes from linked lists
// for practice in maintaining these lists.
// A more complete program would worry more about
// allocation and deallocation; this one simply maintains links.
#include <iostream>
using namespace std;

#include "linked.h"

int main()
{
    SingleList sing( 2, 4 );
    DoubleList doub( 2, 4 );

    cout << "Single List:  insert 3, then 1, then 5" << endl;
    sing.print();
    sing.insert(3);
    sing.print();
    sing.insert(1);
    sing.print();
    sing.insert(5);
    sing.print();

    return 0;				// temporary stopping point

    cout << "Double List:  insert 3, then 1, then 5" << endl;
    doub.print();
    doub.insert(3);
    doub.print();
    doub.insert(1);
    doub.print();
    doub.insert(5);
    doub.print();

    return 0;				// temporary stopping point

    cout << "Double List:  remove 3, then 1, then 5" << endl;
    doub.remove(3);
    doub.print();
    doub.remove(1);
    doub.print();
    doub.remove(5);
    doub.print();

    return 0;				// temporary stopping point

    cout << "Single List:  remove 3, then 1, then 5" << endl;
    sing.remove(3);
    sing.print();
    sing.remove(1);
    sing.print();
    sing.remove(5);
    sing.print();
}

//  Creates a single linked list with two values
//  Pre-condition:		value1 < value2
SingleList::SingleList( int value1, int value2)
{
    head = new SingleNode(value1);
    tail = new SingleNode(value2);
    head->next = tail;		// head followed by tail
}

//  prints the contents of a single-linked list
void SingleList::print()
{
    cout << "Printing from " << head->value << " to " << tail->value << ": ";
    for (SingleNode *node = head; node != NULL; node = node->next )
	cout << node->value << " ";
    cout << endl;
}

//  inserts a new element into a sorted single-linked list
//  Pre-condition:	list is already sorted in increasing order
void SingleList::insert( int newValue )
{
    SingleNode *newNode = new SingleNode(newValue);
    SingleNode *scan;

    if ( false )				// condition needs a change
    {


    }
    else
    {
	scan = head;
	while ( false )				// condition needs a change
	    scan = scan->next;
	newNode->next = scan->next;		// insert after scanned node
	scan->next = newNode;
    }

}

//  removes an element from a sorted single-linked list
void SingleList::remove( int value )
{
    SingleNode *removal;   
    SingleNode *scan;




}

//  Creates a double linked list with two values
//  Pre-condition:		value1 < value2
DoubleList::DoubleList( int value1, int value2)
{
    head = new DoubleNode(value1);
    tail = new DoubleNode(value2);
    head->next = tail;		// head followed by tail
    tail->prev = head;		// tail preceded by head
}

//  prints the contents of a double-linked list
void DoubleList::print()
{
    cout << "Printing from " << head->value << " to " << tail->value << ": ";
    for (DoubleNode *node = head; node != NULL; node = node->next )
	cout << node->value << " ";
    cout << endl;
    cout << "Reverse from " << tail->value << " to " << head->value << ": ";
    for (DoubleNode *node = tail; node != NULL; node = node->prev )
	cout << node->value << " ";
    cout << endl;
}

//  inserts a new element into a sorted double-linked list
//  Pre-condition:	list is already sorted in increasing order
void DoubleList::insert( int newValue )
{
    DoubleNode *newNode = new DoubleNode(newValue);
    DoubleNode *scan;



}

//  removes an element from a sorted double-linked list
void DoubleList::remove( int value )
{
    DoubleNode *removal;   
    DoubleNode *scan;

    scan = head;
    while (scan != NULL && scan->value < value )
        scan = scan->next;
    if (scan != NULL && scan->value == value )
    {
        removal = scan;

	// fix the links here

        delete removal;
    }
}

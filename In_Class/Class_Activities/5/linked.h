//  A simple header file describing linked lists
//  and their functionality.  
#include <iostream>

class ListIterator;

class SingleNode
{
    friend class SingleList;	// can be maintained by this object
    friend class ListIterator;	// can be maintained by this object
    private:
	int value;		// value here
	SingleNode *next;	// and what comes next
    public:
	SingleNode(int v)
	{
	    value = v;
	    next = NULL;
	}
};

class SingleList
{
    private:
	SingleNode *head, *tail;	// where list begins and ends
    public:
	SingleList( int[], int );	// today initialize with an array
	ListIterator begin();
	ListIterator end();
	ListIterator find(int);
	void print();
        ListIterator insert( ListIterator pos, int value );
	ListIterator erase( ListIterator );
};


class ListIterator
{
    friend class SingleList;		// only way to create this iterator
    private:
	SingleList *list;		// what list we refer to
	SingleNode *curr;		// pointer to pointer to current node
	SingleNode *prev;		// required for changing links!
	ListIterator( SingleList *l, SingleNode *c, SingleNode *p ) :
		list(l), curr(c), prev(p)	{ }
    public:
	int value()			// get a value here
	{
	    return curr->value;
	}
	void advance()
	{
	    if (curr != NULL)
	    {
		prev = curr;
		curr = curr->next;
	    }
	}
	int operator !=( const ListIterator &other )
	{
	    return list != other.list || curr != other.curr;
	}
};


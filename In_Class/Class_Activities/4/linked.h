//  A simple header file describing linked lists
//  and their functionality.  
class SingleNode
{
    friend class SingleList;	// can be maintained by this object
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
	SingleList( int, int );		// today start with two values
	void print();			// display to screen
	void insert( int );		// insert this value
	void remove( int );		// remove this value
};

class DoubleNode
{
    friend class DoubleList;	// can be maintained by this object
    private:
	int value;		// value here
	DoubleNode *next;	// and what comes next
	DoubleNode *prev;	// and what comes before
    public:
	DoubleNode(int v)
	{
	    value = v;
	    next = NULL;
	    prev = NULL;
	}
};

class DoubleList
{
    private:
	DoubleNode *head, *tail;	// where list begins and ends
    public:
	DoubleList( int, int );		// today start with 2 values
	void print();			// display to screen
	void insert( int );		// insert this value
	void remove( int );		// remove this value
};


//  NOTE:  This code is intended to be copied to the end
//  of an existing "tokenlist.h" file, since it will be used
//  in many of the same contexts.
//
//  This ListIterator is here to facilitate sequential access
//  to a linked list by those parts of the program that are not
//  given full access to the list itself.   It is initialized
//  in its constructor, and then proceeds to the end of the list.
//
//  For this to succeed, TokenList must declare this class as a friend.
//  and TokenList will have these two extra methods declared as well.
//  (The }; you see below is the end of the TokenList class definition)

	// and now some support for the List Iterator
	ListIterator begin();
	ListIterator end();
};

class ListIterator
{
    friend class TokenList;	// let that class create iterators
    private:
	TokenList *list;	// which list
	ListElement **curr;	// pointer to pointer to current node
	ListIterator( TokenList *l, ListElement **le )
	{
	    list = l;
	    curr = le;
	}
    public:
	Token& token() const
	{
	    return (*curr)->token;
	}
	bool ended() const
	{
	    return (*curr == NULL);	// list ends with NULL
	}
	void advance()
	{
	    if (*curr != NULL)
	    	curr = &(*curr)->next;
	}
	int operator !=( const ListIterator &other ) const
	{
	    return list != other.list || curr != other.curr;
	}
};
	


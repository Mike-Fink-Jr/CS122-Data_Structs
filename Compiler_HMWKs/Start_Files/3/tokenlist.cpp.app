// Here follow a couple extra functions to add into
// the TokenList implementation file to support iterators.

//  Creates an iterator to refer to the beginning of the list
ListIterator TokenList::begin()
{
    return ListIterator( this, &head );
}

//  Creates an iterator to refer after the end of the list
ListIterator TokenList::end()
{
    return ListIterator( this, &tail->next );
}


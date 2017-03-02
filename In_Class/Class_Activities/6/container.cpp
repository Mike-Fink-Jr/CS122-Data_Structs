// Containers Implementation file
// An abstraction of containers in the more literal sense.
// This solution uses inheritance to share common behaviors
// and derived classes for modifying behaviors
#include "container.h"

// transferTo
// transfers one item to a new container,
// updating the data structures as necessary.
// This is a private method for Container class only,
// which updates the other private data structures.
// The public interface is through the other methods.
void Container::transferTo( Container *dest )
{
   heldBy->contents.remove( this );	// not in that container
   heldBy->filled -= size;		// less space occupied there
   dest->contents.push_front( this );	// but in that one
   dest->filled += size;		// more space occupied here
   heldBy = dest;			// update containing location
}

// isInside
// Is this thing inside the one defined in the argument?
bool Container::isInside( Container *other ) const
{
   return heldBy == other || (heldBy != NULL && heldBy->isInside( other ));
}

// insert
// try to put the specified thing into this container
// Parameters:
// 	thing 	(modified Container)	item to insert
bool Container::insert( Container *thing )
{
   bool success = false;
   if ( capacity == 0 )
	cout << "The " << name << " is not a container! " << endl;
   else if ( thing == this )
	cout << "The " << name << " cannot be placed inside itself." << endl;
   else
   {
	cout << "Putting " << thing->getName() << " into " << name << endl;
	thing->transferTo( this );
	success = true;
    }
    return success;
}

// remove
// try to remove an item from a container
// Parameters:
// 	thing 	(modified Container)	item to insert
// 	room	(modified Container)	where to place item afterwards
bool Container::remove( Container *thing, Container *room )
{
   bool success = false;
   if ( thing->getHolder() != this )
	cout << "The " << thing->getName() << " is not inside the " << name << endl;
   else
   {
	cout << "Getting " << thing->getName() << " out of " << name << endl;
	thing->transferTo( room );
	success = true;
    }
    return success;
}

//  These methods will be overridden to support new features
//  An empty bag takes very little space, since it can be flattened
//  But the volume of the bag increases as things are placed inside it.
bool Bag::insert( Container *thing )
{
    bool success = Container::insert( thing );
    if (success)
	;
    return success;
}

bool Bag::remove( Container *thing, Container *room )
{
    bool success = Container::remove( thing, room );
    if (success)
	;
    return success;
}

//  A chest can only be unlocked if there is a key available
//  (in this case, the key must be in the room )
bool Chest::remove( Container *thing, Container *room )
{
    bool success = false;
    if ( true )
         success = Container::remove( thing, room );
    else
	cout << "The key to this chest is missing." << endl;
    return success;
}


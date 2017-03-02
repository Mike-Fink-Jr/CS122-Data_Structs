// Variable Tree Implementation File
// This is a simple binary search tree associating variables
// with integer values.
#include <iostream>
#include <string>
using namespace std;

#include "vartree.h"

//  recursiveSearch
//  A recursive tree-traversal function to search for a variable.
//  If the variable does not exist, it is created with a value of 0.
//  Parameters:
//  	node	(modified TreeNode ptr)	tree to insert into
//  	name	(input string)		name of variable
//  NOTE: node May be a null pointer, indicating an empty tree
//  Post-condition:
//      node points at a node with the given name,
//      even if it had to be created to do so
void VarTree::recursiveSearch( TreeNode *&node, string name )
{
	if(node == NULL)
	{
		node = new TreeNode(name, 0);
	}
	else if(node->name < name) //should create a node
	{
		if( node->left == NULL)
		{		
			node->left = new TreeNode(name, 0);
			node = node->left;
			howbig++;
		}
		else
		{	
			node = node->left;
			return recursiveSearch(node, name);
		}
	}
	else if(node->name > name)
	{
		if( node->right == NULL)
		{
			node->right = new TreeNode(name, 0);
			node= node->right;
			howbig++;
		}
		else
		{
			node= node->right;
			return recursiveSearch(node->right, name);
			
		}
	}
	//if neither of those statements are true, the node name equals the name
	//we are looking for and the method will return that node.
	
}

//  lookup
//  Searches for a variable to get its value
//  If the variable does not yet exist, it is created with value 0.
//  Parameters:
//  	name	(input char array)	name of variable
//  Returns:				value of variable
int VarTree::lookup( string name )
{
    TreeNode *node = root;
    recursiveSearch( node, name );
    return node->value;
}

//  assign
//  Assigns a value to a variable.
//  If the variable does not yet exist, it is created.
//  Parameters:
//  	name	(input string)		name of variable
//  	value	(input integer)		value to assign
void VarTree::assign( string name, int value )
{
	if(root == NULL)
	{
		root = new TreeNode(name, value);
		howbig++;
	}
	else
	{
    	TreeNode *node = root;
    	recursiveSearch( node, name );
    	node->value = value;
	}
}

/*
//  EXTRA CREDIT:  Implement the following, without any loops
ostream& operator<<( ostream& stream, VarTree &vt )
{
	return stream << vt.getRoot() << endl;
}

ostream& operator<<( ostream& stream, TreeNode &tn)
{

    if (tn.getLeft() != NULL && tn.getRight() != NULL)
    {
		return stream << *(tn.getLeft()) << tn.getName() << ":" << tn.getValue() << " " << *(tn.getRight());
    }
	else if(tn.getLeft() == NULL && tn.getRight() != NULL)
	{
		return stream << tn.getName() << ":" << tn.getValue() << " " << *(tn.getRight());
	}
	else if(tn.getRight() == NULL && tn.getLeft() != NULL)
	{
		return stream << *(tn.getLeft()) << tn.getName() << ":" << tn.getValue();
	}
	else
	{
		return stream << tn.getName() << ":" << tn.getValue();
	}
}*/
















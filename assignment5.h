/***********************************************************
 CSCI 340 - Assignment 5 - Spring 2018
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: 
 Date Due: March 05, 2018
 
 Purpose: 
 ************************************************************/
#ifndef ASSIGNMENT5
#define ASSIGNMENT5

class binTree;
class BST;

class Node {
    // Give binTree access
    friend class binTree;

    // Method prototypes
    public:

    // Data members 
    private:
        // Variable to store node's value
        // Variable to store node's left child
        // Variable to store node's right child
};

class binTree {
    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;

    private:
        void insert( Node*&, int );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
		void inorder( Node*, void(*)(int) );
		void preorder( Node*, void(*)(int) );
		void postorder( Node*, void(*)(int) );
};


/***************************************************************
  
 Name: insert

 Use: This function is used to insert a node with the data value 
 x in a binary (sub-)tree at root r, applying the following 
 technique: if the tree is empty, then the new node will be 
 the root of the tree with the value x; otherwise, x is inserted 
 in the left or right sub-tree of r, depending on the sub-trees’
 sizes. If the size of the right sub-tree is less than the size 
 of the left sub-tree, x is inserted in the right sub-tree; 
 otherwise x is inserted in the left sub-tree. 
 
 Parameters: 
 
 Returns: None. 

 ***************************************************************/
void binTree::insert( Node*& r, int x )
{
	if ( r.empty() )
	{
		// node will be root of tree with value x
	}
	else
	{
		// x is inserted in the left or right sub-tree of r
		// depending on the sub tree's sizes.

		// if right sub tree less than size of left sub tree, x is inserted into the left subtree
		if ( r.right < r.left )
		{
			r.left = x;
		}
		else
		{
			r.right = x;
		}
	}
}


/***************************************************************
  
 Name: size

 Use: This function returns the number of nodes in the tree 
 rooted at r. If the tree is empty, the size is 0. 
 
 Parameters: 
 
 Returns: 

 ***************************************************************/
unsigned binTree::size( Node* r ) const;
{
	if (r.empty())
	{
		return 0;
	}
	else
	{
		return r.size();
	}
}


/***************************************************************
  
 Name: height

 Use: This function returns the height of the tree rooted at r. 
 If the tree is empty, the size is -1. 
 
 Parameters: 
 
 Returns: 

 ***************************************************************/
unsigned binTree::height( Node* r ) const;
{
	if (r.empty())
	{
		return -1;
	}
	else
	{
		return r.height();
	}
}


/***************************************************************
  
 Name: inorder

 Use: This function traverse the tree rooted at r. p is the 
 “visit” operation on each node. To visit r, simply invoke p(r->data). 

 Parameters: 
 
 Returns: 

 ***************************************************************/
void inorder( Node* r, void(* p)(int) );
{
	if (!r.empty())
	{
		inorder(r.left);
		cout << r.key << endl;
		inorder(r.right);
	}
}


/***************************************************************
  
 Name: preorder

 Use:  

 Parameters: 
 
 Returns: 

 ***************************************************************/
void preorder( Node* r, void(* p)(int) );
{
	if (!r.empty())
	{
		cout << r.key << endl;
		inorder(r.left);
		inorder(r.right);
	}
}


/***************************************************************
  
 Name: postorder

 Use:  

 Parameters: 
 
 Returns: 

 ***************************************************************/
void postorder( Node* r, void(* p)(int) );
{
	if (!r.empty())
	{
		inorder(r.left);
		inorder(r.right);
		cout << r.key << endl;
	}
}


#endif

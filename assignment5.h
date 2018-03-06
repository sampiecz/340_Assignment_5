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
        // Constructor what upppp
        Node(); 
        // Variable to store node's data
        int data;
        // Variable to store node's left child
        Node* left;
        // Variable to store node's right child
        Node* right;
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

// Constructor life
Node::Node()
{
}

// Constructor life
binTree::binTree()
{
}

/***************************************************************
  
 Name: 

 Use:  

 Parameters: 
 
 Returns: 

 ***************************************************************/
void binTree::insert(int val)
{
    insert(root, val);
}

/***************************************************************
  
 Name: 

 Use:  

 Parameters: 
 
 Returns: 

 ***************************************************************/
unsigned binTree::height() const
{
    return height(root);
}

/***************************************************************
  
 Name: 

 Use:  

 Parameters: 
 
 Returns: 

 ***************************************************************/
unsigned binTree::size() const
{
    return size(root);
}

/***************************************************************
  
 Name: 

 Use:  

 Parameters: 
 
 Returns: 

 ***************************************************************/
void binTree::inorder( void(* val)(int) )
{
    inorder(root, val);
}

/***************************************************************
  
 Name: 

 Use:  

 Parameters: 
 
 Returns: 

 ***************************************************************/
void binTree::preorder( void(* val)(int) )
{
    preorder(root, val);
}

/***************************************************************
  
 Name: 

 Use:  

 Parameters: 
 
 Returns: 

 ***************************************************************/
void binTree::postorder( void(* val)(int) )
{
    postorder(root, val);
}

/***************************************************************
  
 Name: insert

 Use: This function is used to insert a node with the data data 
 x in a binary (sub-)tree at root r, applying the following 
 technique: if the tree is empty, then the new node will be 
 the root of the tree with the data x; otherwise, x is inserted 
 in the left or->right sub-tree of r, depending on the sub-trees’
 sizes. If the size of the right sub-tree is less than the size 
 of the left sub-tree, x is inserted in the right sub-tree; 
 otherwise x is inserted in the left sub-tree. 
 
 Parameters: 
 
 Returns: None. 

 ***************************************************************/
void binTree::insert( Node*& r, int val )
{
	if ( r->data == NULL)
	{
		// node will be root of tree with data x
        r= new Node;
        r->data = val;
        r->left = nullptr;
        r->right = nullptr;
	}
	else
	{
		// x is inserted in the left or->right sub-tree of r
		// depending on the sub tree's sizes.

		// if right sub tree less than size of left sub tree, x is inserted into the left subtree
		if ( r->right < r->left )
		{
			insert(r->left, val);
		}
		else
		{
			insert(r->right, val);
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
unsigned binTree::size( Node* r ) const
{
	if (r->data == NULL)
	{
		return 0;
	}
	else
	{
        size(r->data);
	}
}


/***************************************************************
  
 Name: height

 Use: This function returns the height of the tree rooted at r. 
 If the tree is empty, the size is -1. 
 
 Parameters: 
 
 Returns: 

 ***************************************************************/
unsigned binTree::height( Node* r ) const
{
	if (r == NULL)
	{
		return -1;
	}
	else
	{
        height(r->data);
	}
}


/***************************************************************
  
 Name: inorder

 Use: This function traverse the tree rooted at r. p is the 
 “visit” operation on each node. To visit r, simply invoke p(r->data). 

 Parameters: 
 
 Returns: 

 ***************************************************************/
void inorder( Node* r, void(* p)(int) )
{
	if (r != NULL)
	{
		inorder(r->left, p);
        p(r->data);
		inorder(r->right, p);
	}
}


/***************************************************************
  
 Name: preorder

 Use:  

 Parameters: 
 
 Returns: 

 ***************************************************************/
void preorder( Node* r, void(* p)(int) )
{
	if (r != NULL)
	{
        p(r->data);
		inorder(r->left, p);
		inorder(r->right, p);
	}
}


/***************************************************************
  
 Name: postorder

 Use:  

 Parameters: 
 
 Returns: 

 ***************************************************************/
void postorder( Node* r, void(* p)(int) )
{
	if (r != NULL)
	{
		inorder(r->left, p);
		inorder(r->right, p);
        p(r->data);
	}
}


#endif

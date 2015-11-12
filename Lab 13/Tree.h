// Definition of class template Tree.
#ifndef TREE_H
#define TREE_H

#include <iostream> 
using std::cout; 

#include <new>
#include "TreeNode.h"

template< typename NODETYPE >
class Tree 
{
 public:
  Tree();
  void insertNode( const NODETYPE & );
  void preOrderTraversal() const;
  void inOrderTraversal() const;
  void postOrderTraversal() const;
  int getDepth() const;
  TreeNode< NODETYPE > *binaryTreeSearch( int ) const;
 protected:
  TreeNode< NODETYPE > *rootPtr;
 private:
  // utility functions
  void insertNodeHelper( TreeNode< NODETYPE > **, const NODETYPE & );
  void preOrderHelper( TreeNode< NODETYPE > * ) const;
  void inOrderHelper( TreeNode< NODETYPE > * ) const;
  void postOrderHelper( TreeNode< NODETYPE > * ) const;
  void determineDepth( TreeNode< NODETYPE > *, int *, int * ) const;
  TreeNode< NODETYPE > 
    *binarySearchHelper( TreeNode< NODETYPE > *, int ) const;
}; // end class Tree

// constructor
template< typename NODETYPE >
Tree< NODETYPE >::Tree() 
{ 
  rootPtr = 0; 
} // end Tree constructor

// begin inserting node into Tree
template< typename NODETYPE >
void Tree< NODETYPE >::insertNode( const NODETYPE &value )
{ 
  insertNodeHelper( &rootPtr, value ); 
} // end function insertNode

// This function receives a pointer to a pointer so the
// pointer can be modified.
template< typename NODETYPE >
void Tree< NODETYPE >::insertNodeHelper( TreeNode< NODETYPE > **ptr,
					 const NODETYPE &value )
{
  if ( *ptr == 0 ) // tree is empty
    *ptr = new TreeNode< NODETYPE >( value );
  else // tree is not empty
    {  
      // data to insert is less than data in current node
      if ( value < ( *ptr )->data )
	insertNodeHelper( &( ( *ptr )->leftPtr ), value );
 
      else if ( value > (*ptr)->data )
	insertNodeHelper( &( ( *ptr )->rightPtr ), value );

    } // end else
} // end function insertNodeHelper

// begin preorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::preOrderTraversal() const 
{ 
  preOrderHelper( rootPtr ); 
} // end function preOrderTraversal

// utility function to perform preorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::preOrderHelper( TreeNode< NODETYPE > *ptr ) const
{
  if ( ptr != 0 ) 
    {
      cout << ptr->data << ' '; // process node
      preOrderHelper(ptr->leftPtr); // go to left subtree
      preOrderHelper(ptr->rightPtr); // go to right subtree

    } // end if
} // end function preOrderHelper

// begin inorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::inOrderTraversal() const 
{ 
  inOrderHelper( rootPtr ); 
} // end function inOrderTraversal

// utility function to perform inorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::inOrderHelper( TreeNode< NODETYPE > *ptr ) const
{
  if ( ptr != 0 ) 
    {

      inOrderHelper(ptr->leftPtr); // go to left subtree
      cout << ptr->data << ' '; // process node
      inOrderHelper(ptr->rightPtr); // go to right subtree

    } // end if
} // end function inOrderHelper

// begin postorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::postOrderTraversal() const 
{ 
  postOrderHelper( rootPtr ); 
} // end function postOrderTraversal

// utility function to perform postorder traversal
template< typename NODETYPE >
void Tree< NODETYPE >::postOrderHelper( TreeNode< NODETYPE > *ptr ) const
{
  if ( ptr != 0 ) 
    {
      postOrderHelper(ptr->leftPtr); // go to left subtree
      postOrderHelper(ptr->rightPtr);// go to right subtree
      cout << ptr->data << ' '; // process node

    } // end if
} // end postOrderHelper

// get the depth of the tree
template< typename NODETYPE >
int Tree< NODETYPE >::getDepth() const
{
  int totalDepth = 0;
  int currentDepth = 0;

  determineDepth( rootPtr, &totalDepth, &currentDepth );
  return totalDepth;
} // end function getDepth

// calculate the depth of the tree
template< typename NODETYPE >
void Tree< NODETYPE >::determineDepth( TreeNode< NODETYPE > *ptr,
				       int *totPtr, int *currPtr ) const
{   
  if ( ptr != 0 ) // until ptr points to 0
    {
      ( *currPtr )++;

      if ( (*currPtr) > (*totPtr))
	(*totPtr) = (*currPtr);

      determineDepth(ptr->leftPtr, totPtr, currPtr);
      determineDepth(ptr->rightPtr, totPtr, currPtr);

      ( *currPtr )--;
    } // end if
} // end function determineDepth

// begin binary search
template< typename NODETYPE >
TreeNode< NODETYPE > *Tree< NODETYPE >::binaryTreeSearch( int val ) const
{ 
  return binarySearchHelper( rootPtr, val ); 
} // end function binaryTreeSearch

// do a binary search on the Tree
template< typename NODETYPE >
TreeNode< NODETYPE > *Tree< NODETYPE >::binarySearchHelper( 
							   TreeNode< NODETYPE > *ptr, int value ) const
{
  // if value is not found
  if ( ptr == 0 )
    return 0;

  cout << "Comparing " << value << " to " << ptr->getData();

  if ( value == ptr->getData() ) {
    cout << "; search complete\n";
    return ptr;
  }

  else if ( value < ptr->getData() ) {
    cout << "; smaller, walk left\n";
    return binarySearchHelper (ptr->leftPtr, value);
  }

  else if ( value > ptr->getData() ) {
    cout << "; larger, walk right\n";
    return binarySearchHelper (ptr->rightPtr, value);
  }

  return 0;

} // end function binarySearchHelper

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"

void _insert( b_node* subroot, b_node* new )
{
  new->parent = subroot;

  int comparison = ( new->id < subroot->id );
  b_node* next = comparison ? subroot->left : subroot->right;

  if ( next )
    _insert( next, new );
  else
  {
    if (comparison)
      subroot->left = new;
    else
      subroot->right = new;
  }
}

b_node* bn_insert( b_node* new, b_node* root )
{
  if ( !root ) // If there is no root, our new node is the new root.
    return new;

  // If there was a root, traverse the tree and insert the node in the right spot.
  _insert( root, new );

  // Return the location of the current root.
  return root;
}

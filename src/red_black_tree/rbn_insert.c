#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"
#include "balance_tree/balance_tree.h"

b_node* rbn_insert( b_node* new, b_node* root )
{
  // Insert the new node as normal.
  root = bn_insert( new, root );

  // Red black part begins, we need to ensure the tree is balanced.
  root = balance_tree( new, root );

  // Return the location of the current root
  return root;
}

//____________________________________

/*
b_node* new_bnode,
* parent_bnode,
* binary_root = (root) ? root->node : NULL;

// Rebalance the tree
// If we were not provided a root, assume the new node is the root.
rb_node* rb_root = ( root ) ? root : rbn;
rb_root = balance_tree( rbn->node, rb_root );
*/

#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"
#include "balance_tree/balance_tree.h"

rb_node* initialize_rbnode( b_node* new_bnode );

rb_node* insert_rbnode( int value, void* data, rb_node* root)
{
  return _insert_rbnode( value, data, root, NULL);
}

rb_node* _insert_rbnode( int value, void* data, rb_node* root, b_node** ret_loc )
{
  b_node* new_bnode,
        * parent_bnode,
        * binary_root = (root) ? root->node : NULL;

  // At the b_root level, insert the new node. Save where the new node went.
  _insert_bnode( value, data, binary_root, &new_bnode );

  // Create a new rb_node
  rb_node* rbn = initialize_rbnode( new_bnode );

  rb_node* rb_root = ( root ) ? root : rbn;

  // Rebalance the tree
  rb_root = balance_tree( rbn->node, rb_root );

  // If ret_loc was provided, give it the location of the new b_node
  if ( ret_loc )
    *ret_loc = rbn->node;

  // always return the rb_node that stores the root b_node
  return rb_root;
}

//____________________________________

rb_node* initialize_rbnode( b_node* new_bnode )
{
  rb_node* rbn = malloc( sizeof( rb_node ) );
  rbn->node = new_bnode;
  rbn->color = RED;

  // Save the new bnodes' data in the rbn.
  // Overwrite the new bnodes' data with the new rbn.
  rbn->data = new_bnode->data;
  rbn->node->data = rbn;
  return rbn;
}

#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"
#include "balance_tree/balance_tree.h"

rb_node* insert_rbnode( int value, rb_node* root )
{
  static Data_node* rbnode_list = NULL;
  b_node* new_bnode,
        * parent_bnode,
        * binary_root = (root) ? root->node : NULL;

  // At the b_root level, insert the new node. Save where the new node went.
  _insert_bnode( value, binary_root, &new_bnode );

  // Create a new rb_node
  rb_node* rbn = malloc( sizeof( rb_node ) );
  rbn->node = new_bnode;
  rbn->color = RED;
  append_node( rbn, 0, rbnode_list );

  // Rebalance the tree
  //balance_tree( new_bnode, binary_root, rbnode_list );

  // always return the rb_node that stores the root b_node
  return ( root ) ? root : rbn;
}

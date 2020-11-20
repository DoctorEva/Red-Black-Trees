#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"
#include "../linked_list/linked_list.h"

Data_node* program_rbnodes = NULL;

b_node* locate_parent( b_node* target, b_node* root );

rb_node* insert_rbnode( int value, rb_node* root)
{

  b_node* new_bnode,
        * parent_bnode,
        * binary_root = (root) ? root->node : NULL;

  // At the b_root level, insert the new node. Save where the new node went.
  _insert_bnode( value, binary_root, &new_bnode );

  // Create a new rb_node
  rb_node* rbn = malloc( sizeof( rb_node ) );
  rbn->node = new_bnode;
  rbn->color = BLACK;

  program_rbnodes = append_node( rbn, 0, program_rbnodes );

  // always return the rb_node that stores the root b_node
  return ( root ) ? root : rbn;
}

//______________________________________________________

b_node* locate_parent( b_node* target, b_node* root )
{
  if( !root )
    return NULL;

  int leftmatch = ( target == root->left );
  int rightmatch = ( target == root->right );
  if ( leftmatch || rightmatch )
    return root;

  b_node* leftSearch = locate_parent( target, root->left );
  b_node* rightSearch = locate_parent( target, root->right );

  return ( leftSearch ) ? leftSearch : rightSearch;
}

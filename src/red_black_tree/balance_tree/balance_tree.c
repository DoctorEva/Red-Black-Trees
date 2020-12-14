#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

int _db = 0; // debug prints.

rb_node* check_root( rb_node* rbroot );

rb_node* balance_tree( b_node* node, rb_node* rbroot )
{
  node_family f = identify_family( node );

  // Case 1: Black if x is root.
  if ( !f.parent )
  {
    if( _db) puts( "case 1: root colored to black." );
    // recolour to black.
    f.self->color = BLACK;
    return rbroot;
  }

  // Case 2: X's parent is not black and x is not root.
  // Assume null nodes are colored black.
  paint parent_color = f.parent->color;
  paint uncle_color = ( f.uncle ) ? f.uncle->color : BLACK;
  if ( parent_color == BLACK  )
  {
    if( _db) puts( "OK: already balanced." );
    return rbroot;
  }

  if ( uncle_color == RED ) // Grandparent MUST be black.
  {
    if( _db) puts( "case 2a: uncle is red, grandpa is black. Recolor and Recurse with grandpa." );
    f.parent->color = BLACK;
    f.uncle->color = BLACK;
    f.grandparent->color = RED;
    return balance_tree( f.grandparent->node, rbroot );
  }

  // Uncle is black. Parent is red ( Note, this implies there MUST be a grandparent )
  make_rotations( f );

  // After rotation, make sure to return the new root node if there is one.
  return check_root( rbroot );
}

//____________________________________

rb_node* check_root( rb_node* rbroot )
{
  b_node* root = locate_parent( rbroot->node );

  if ( root )
    return (rb_node*) root->data;

  return rbroot;
}

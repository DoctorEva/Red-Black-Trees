#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

int _db = 0; // debug prints.


b_node* balance_tree( b_node* new, b_node* root )
{
  node_family f = identify_family( new );
  rb_node* self = rbn(f.self);
  rb_node* parent = rbn(f.parent);
  rb_node* grandparent = rbn(f.grandparent);
  rb_node* greatgrandparent = rbn(f.greatgrandparent);
  rb_node* uncle = rbn(f.uncle);

  // Case 1: Black if x is root.
  if ( !parent )
  {
    if( _db) puts( "case 1: root colored to black." );
    // recolour to black.
    self->color = BLACK;
    return root;
  }

  // Case 2: X's parent is not black and x is not root.
  // Assume null nodes are colored black.
  paint parent_color = parent->color;
  paint uncle_color  = uncle ? uncle->color : BLACK;
  if ( parent_color == BLACK  )
  {
    if( _db) puts( "OK: already balanced." );
    return root;
  }

  if ( uncle_color == RED ) // Grandparent MUST be black.
  {
    if( _db) puts( "case 2a: uncle is red, grandpa is black. Recolor and Recurse with grandpa." );
    parent->color = BLACK;
    uncle->color = BLACK;
    grandparent->color = RED;
    return balance_tree( f.grandparent, root );
  }

  // Uncle is black. Parent is red ( Note, this implies there MUST be a grandparent )
  make_rotations( f );

  // After rotation, make sure to return the new root node if there is one.
  b_node* newroot = locate_parent( root );
  return newroot ? newroot : root;
}

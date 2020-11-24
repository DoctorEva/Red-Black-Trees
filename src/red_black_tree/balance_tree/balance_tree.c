#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

side getSide( b_node* node, b_node* parent )
{
  if      ( parent->left == node ) return LEFT;
  else if ( parent->right == node ) return RIGHT;
  else
  {
    puts( "balance_tree.c: Error, not a child of parent." );
    exit(1);
  }
}

rb_node* check_root( node_family f, rb_node* rbroot );

rb_node* balance_tree( b_node* node, rb_node* rbroot, Data_node* rbnode_list )
{
  node_family f = identify_family( node, rbroot->node, rbnode_list );

  // Case 1: Black if x is root.
  if ( !f.parent )
  {
    //puts( "case 1: root colored to black." );
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
    //puts( "OK: already balanced." );
    return rbroot;
  }

  if ( uncle_color == RED ) // Grandparent MUST be black.
  {
    //puts( "case 2a: uncle is red, grandpa is black. Recolor and Recurse with grandpa." );
    f.parent->color = BLACK;
    f.uncle->color = BLACK;
    f.grandparent->color = RED;
    return balance_tree( f.grandparent->node, rbroot, rbnode_list );
  }

  // Uncle is black. Parent is red ( Note, this implies there MUST be a grandparent )
  side parent_side = getSide( f.parent->node, f.grandparent->node );
  side self_side   = getSide( f.self->node, f.parent->node );
   if      ( parent_side == LEFT && self_side == LEFT )   { LL_rotate(f); }
   else if ( parent_side == LEFT && self_side == RIGHT )  { LR_rotate(f); }
   else if ( parent_side == RIGHT && self_side == RIGHT ) { RR_rotate(f); }
   else if ( parent_side == RIGHT && self_side == LEFT )  { RL_rotate(f); }

   // After rotation, make sure to return the new root node if there is one.
   return check_root( f, rbroot );
}

//____________________________________

rb_node* check_root( node_family f, rb_node* rbroot )
{
  b_node* old_root = rbroot->node;
  rb_node* candidates[5];
  candidates[0] = f.self;
  candidates[1] = f.parent;
  candidates[2] = f.grandparent;
  candidates[3] = f.greatgrandparent;
  candidates[4] = f.uncle;

  int i;
  for ( i = 0; i<5; i++ )
  {
    if ( !candidates[i] ) continue;
    b_node* x = candidates[i]->node;
    if ( x->left == old_root || x->right == old_root )
    {
      //printf( "<ROOT changed to %p %d>\n", candidates[i], x->value );
      return candidates[i];
    }
  }
  return rbroot;
}

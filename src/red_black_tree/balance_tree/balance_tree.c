#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

side getSide( b_node* node, b_node* parent )
{
  return ( parent->left == node ) ? LEFT : RIGHT;
}

void balance_tree( b_node* node, b_node* root, Data_node* rbnode_list )
{
  node_family f = identify_family( node, root, rbnode_list );

  // Case 1: Black if x is root.
  if ( !f.parent )
  {
    puts( "root colored to black." );
    // recolour to black.
    f.self->color = BLACK;
    return;
  }

  // Case 2: X's parent is not black and x is not root.
  // Assume null nodes are colored black.
  paint parent_color = f.parent->color;
  paint uncle_color = ( f.uncle ) ? f.uncle->color : BLACK;
  if ( parent_color == BLACK  )
    return;

  if ( uncle_color == RED ) // Grandparent MUST be black.
  {
    puts( "uncle is red, recoloring and recursing" );
    f.parent->color = BLACK;
    f.uncle->color = BLACK;
    f.grandparent->color = RED;
    return balance_tree( f.grandparent->node, root, rbnode_list );
  }

  // Uncle is black. Parent is red ( Note, this implies there MUST be a grandparent )
  side parent_side = getSide( f.parent->node, f.grandparent->node );
  side self_side   = getSide( f.self->node, f.parent->node );
  // if      ( parent_side == LEFT && self_side == LEFT )   { LL_rotate(f); puts( "LL rotate" ); }
  // else if ( parent_side == LEFT && self_side == RIGHT )  { LR_rotate(f); puts( "LR rotate" ); }
  // else if ( parent_side == RIGHT && self_side == RIGHT ) { RR_rotate(f); puts( "RR rotate" ); }
  // else if ( parent_side == RIGHT && self_side == LEFT )  { RL_rotate(f); puts( "RL rotate" ); }

}

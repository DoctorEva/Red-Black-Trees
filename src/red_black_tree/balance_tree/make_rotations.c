#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

void reestablish_parents( node_family f );
void test_validity( node_family f );

void make_rotations( node_family f )
{
  if ( !( f.self && f.parent && f.grandparent ) )
  {
    puts( "make_rotations is missing required nodes!" );
    exit( 1 );
  }

  side parent_side = getSide( f.parent, f.grandparent );
  side self_side   = getSide( f.self, f.parent );
  if      ( parent_side == LEFT && self_side == LEFT )   { LL_rotate(f); }
  else if ( parent_side == LEFT && self_side == RIGHT )  { LR_rotate(f); }
  else if ( parent_side == RIGHT && self_side == RIGHT ) { RR_rotate(f); }
  else if ( parent_side == RIGHT && self_side == LEFT )  { RL_rotate(f); }

  reestablish_parents( f );
}

//____________________________________

void new_parent( b_node* bnode )
{
  if ( !bnode ) return;

  b_node *l = bnode->left,
         *r = bnode->right;

  if ( l ) l->parent = bnode;
  if ( r ) r->parent = bnode;
}

void reestablish_parents( node_family f )
{
  // There must be a new root if there was no greatgrandparent.
  // Therefore, set self and parent nodes' parents to NULL, as potential new roots.
  if( !f.greatgrandparent )
  {
    f.self->parent = NULL;
    f.parent->parent = NULL;
  }

  new_parent( f.self );
  new_parent( f.parent );
  new_parent( f.grandparent );
  new_parent( f.greatgrandparent );
  new_parent( f.uncle );
}

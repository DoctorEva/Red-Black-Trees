#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

#define GP  grandparent
#define GGP greatgrandparent

void rbnode_colorSwap( rb_node* a, rb_node* b );
node_family family_swap_parent_and_X( node_family f );

void LL_rotate( node_family f )
{
  b_node* gp = (f.GP) ? f.GP->node : NULL;
  b_node* ggp = (f.GGP) ? f.GGP->node : NULL;
  // right rotate the grandparent
  right_rotate( gp, ggp );

  // swap the colors of grandpa and parent.
  rbnode_colorSwap( f.GP, f.parent );
}

void LR_rotate( node_family f )
{
  b_node* p = (f.parent) ? f.parent->node : NULL;
  b_node* gp = (f.GP) ? f.GP->node : NULL;
  left_rotate( p, gp );

  f = family_swap_parent_and_X( f );
  LL_rotate( f );
}

void RR_rotate( node_family f )
{
  b_node* gp = (f.GP) ? f.GP->node : NULL;
  b_node* ggp = (f.GGP) ? f.GGP->node : NULL;
  left_rotate( gp, ggp );

  rbnode_colorSwap( f.GP, f.parent );
}

void RL_rotate( node_family f )
{
  b_node* p = (f.parent) ? f.parent->node : NULL;
  b_node* gp = (f.GP) ? f.GP->node : NULL;
  right_rotate( p, gp );

  f = family_swap_parent_and_X( f );
  RR_rotate( f );
}

//___________________________________________________________

void rbnode_colorSwap( rb_node* a, rb_node* b )
{
  if ( !a || !b )
  {
    puts("rbnode_colorSwap cannot be given null values. Stop.");
    exit(1);
  }

  paint temp = a->color;
  a->color = b->color;
  b->color = temp;
}

node_family family_swap_parent_and_X( node_family f )
{
  rb_node* temp = f.self;
  f.self = f.parent;
  f.parent = temp;
  return f;
}

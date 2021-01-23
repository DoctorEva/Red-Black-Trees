#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

#define GP  grandparent
#define GGP greatgrandparent

void rbnode_colorSwap( b_node* a, b_node* b );
node_family family_swap_parent_and_X( node_family f );

void LL_rotate( node_family f )
{
  b_node* gp = f.GP;
  b_node* ggp = f.GGP;
  // right rotate the grandparent
  right_rotate( gp, ggp );

  // swap the colors of grandpa and parent.
  rbnode_colorSwap( f.GP, f.parent );
}

void LR_rotate( node_family f )
{
  b_node* p = f.parent;
  b_node* gp = f.GP;
  left_rotate( p, gp );

  f = family_swap_parent_and_X( f );
  LL_rotate( f );
}

void RR_rotate( node_family f )
{
  b_node* gp = f.GP;
  b_node* ggp = f.GGP;
  left_rotate( gp, ggp );

  rbnode_colorSwap( f.GP, f.parent );
}

void RL_rotate( node_family f )
{
  b_node* p = f.parent;
  b_node* gp = f.GP;
  right_rotate( p, gp );

  f = family_swap_parent_and_X( f );
  RR_rotate( f );
}

//___________________________________________________________

void rbnode_colorSwap( b_node* a, b_node* b )
{
  if ( !a || !b )
  {
    puts("rbnode_colorSwap cannot be given null values. Stop.");
    exit(1);
  }

  rb_node* A = rbn(a);
  rb_node* B = rbn(b);
  paint temp = A->color;
  A->color = B->color;
  B->color = temp;
}

node_family family_swap_parent_and_X( node_family f )
{
  b_node* temp = f.self;
  f.self = f.parent;
  f.parent = temp;
  return f;
}

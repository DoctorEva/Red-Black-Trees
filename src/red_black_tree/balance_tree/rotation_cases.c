#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

void rbnode_colorSwap( rb_node* a, rb_node* b );
node_family family_swap_parent_and_X( node_family f );
void handle_subrootChange( rb_node* ancestor, rb_node* decendent, rb_node* newDecendent );

void LL_rotate( node_family f )
{
  // right rotate the grandparent
  right_rotate( f.grandparent->node );
  handle_subrootChange( f.greatgrandparent, f.grandparent, f.parent );

  // swap the colors.
  rbnode_colorSwap( f.grandparent, f.parent );
}

void LR_rotate( node_family f )
{
  left_rotate( f.parent->node );
  handle_subrootChange( f.grandparent, f.parent, f.self );

  f = family_swap_parent_and_X( f );
  LL_rotate( f );
}

void RR_rotate( node_family f )
{
  left_rotate( f.grandparent->node );
  handle_subrootChange( f.greatgrandparent, f.grandparent, f.parent );

  rbnode_colorSwap( f.grandparent, f.parent );
}

void RL_rotate( node_family f )
{
  // right rotate the parent
  right_rotate( f.parent->node );
  handle_subrootChange( f.grandparent, f.parent, f.self );

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

void handle_subrootChange( rb_node* ancestor, rb_node* decendent, rb_node* newDecendent )
{
  if ( !ancestor ) return;

  side s = getSide( ancestor->node, decendent->node );
  if ( s == LEFT )
    ancestor->node->left  = newDecendent->node;
  else
    ancestor->node->right = newDecendent->node;

}

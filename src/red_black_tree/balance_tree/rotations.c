#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

void reattach_pivot( b_node* pivot, b_node* pivot_parent, b_node* pivot_child );

void right_rotate( b_node* pivot, b_node* pivot_parent )
{
  // Grab binary nodes
  b_node *p       = pivot;
  b_node *p_child = pivot->left;

  if ( !p_child || !p )
  {
    puts( "right rotate was unable to find necessary nodes!" );
    exit(1);
  }

  // right rotate
  b_node* pr = p->right;
  b_node* pc_l = p_child->left;
  b_node* pc_r = p_child->right;
  p_child->left = pc_r;
  p_child->right = p;
  p->left = pc_l;
  p->right = pr;

  // Reattach pivot parent.
  reattach_pivot( p, pivot_parent, p_child );
}

void left_rotate( b_node* pivot, b_node* pivot_parent )
{
  // Grab binary nodes
  b_node *p       = pivot;
  b_node *p_child = pivot->right;

  if ( !p_child || !p )
  {
    puts( "left rotate was unable to find necessary nodes!" );
    exit(1);
  }

  // left rotate
  b_node* pl = p->left;
  b_node* pc_l = p_child->left;
  b_node* pc_r = p_child->right;
  p_child->left = pc_r;
  p_child->right = p;
  p->left = pc_l;
  p->right = pc_r;

  // Reattach pivot parent.
  reattach_pivot( p, pivot_parent, p_child );
}

//____________________________________

void reattach_pivot( b_node* pivot, b_node* pivot_parent, b_node* pivot_child )
{
  if ( !pivot_parent ) return;
  side s = getSide( pivot, pivot_parent );
  if ( s == LEFT ) pivot_parent->left  = pivot_child;
  else             pivot_parent->right = pivot_child;
}

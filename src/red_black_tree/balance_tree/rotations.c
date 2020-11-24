#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

void reattach_pivot( b_node* pivot, b_node* pivot_parent, b_node* pivot_child );

void right_rotate( b_node* pivot )
{
  // Grab binary nodes
  b_node *p        = pivot;
  b_node *p_child  = pivot->left;
  b_node *p_parent = locate_parent( p );

  if ( !p_child || !p )
  {
    puts( "right rotate was unable to find necessary nodes!" );
    exit(1);
  }

  // right rotate
  //b_node* pr = p->right;          // alpha
  //b_node* pc_l = p_child->left;   // lambda
  b_node* pc_r = p_child->right;  // beta
  //p_child->left = pc_l;
  p_child->right = p;
  p->left = pc_r;
  //p->right = pr;

  // Reattach pivot parent.
  reattach_pivot( p, p_parent, p_child );
  p->parent = p_child;
  p_child->parent = p_parent;
}

void left_rotate( b_node* pivot )
{
  // Grab binary nodes
  b_node *p        = pivot;
  b_node *p_child  = pivot->right;
  b_node *p_parent = locate_parent( p );

  if ( !p_child || !p )
  {
    puts( "left rotate was unable to find necessary nodes!" );
    exit(1);
  }

  // left rotate
  //b_node* pl = p->left;           // alpha
  b_node* pc_l = p_child->left;   // beta
  //b_node* pc_r = p_child->right;  // lambda
  p_child->left = p;
  // p_child->right = pc_r;
  // p->left = pl;
  p->right = pc_l;

  // Reattach pivot parent to pivot child.
  reattach_pivot( p, p_parent, p_child );
  p->parent = p_child;
  p_child->parent = p_parent;
}

//____________________________________

void reattach_pivot( b_node* pivot, b_node* pivot_parent, b_node* pivot_child )
{
  if ( !pivot_parent ) return;
  side s = getSide( pivot );
  if ( s == LEFT ) pivot_parent->left  = pivot_child;
  else             pivot_parent->right = pivot_child;
}

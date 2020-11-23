#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

void right_rotate( b_node* pivot )
{
  // Grab binary nodes
  b_node *p       = pivot,
         *p_child = pivot->left;

  // rotate
  p->left = p_child->right;
  p_child->right = p;

}

void left_rotate( b_node* pivot )
{
  // Grab binary nodes
  b_node *p       = pivot,
         *p_child = pivot->right;

  // rotate
  b_node* swap_temp = p->left;
  p->right = p_child->right;
  p->left  = p_child->left;
  p_child->right = swap_temp;
  p_child->left  = p;

}

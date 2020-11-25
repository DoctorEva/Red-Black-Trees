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

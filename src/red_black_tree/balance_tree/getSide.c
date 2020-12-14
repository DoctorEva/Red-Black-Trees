#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

side getSide( b_node* node, b_node* parent )
{
  if      ( parent->left == node ) return LEFT;
  else if ( parent->right == node ) return RIGHT;
  else
  {
    puts( "getSide.c: Error, not a child of parent." );
    printf( "node:   s:%p p:%p\n", node, node->parent );
    printf( "parent: s:%p l:%p r:%p\n", parent, parent->left, parent->right );
    exit(1);
  }
}

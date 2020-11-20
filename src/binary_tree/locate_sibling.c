#include <stdlib.h>
#include <stdio.h>

#include "binary_tree.h"

b_node* locate_sibling( b_node* target, b_node* root )
{
  if( !root || !target )
    return NULL;

  b_node* parent = locate_parent( target, root );
  if ( !parent )
    return NULL;

  return ( parent->left == target ) ? parent->right : parent->left;
}

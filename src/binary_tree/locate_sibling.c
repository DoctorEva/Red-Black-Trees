#include <stdlib.h>
#include <stdio.h>

#include "binary_tree.h"

b_node* locate_sibling( b_node* target )
{
  if( !target )
    return NULL;

  b_node* parent = locate_parent( target );
  if ( !parent )
    return NULL;

  return ( parent->left == target ) ? parent->right : parent->left;
}

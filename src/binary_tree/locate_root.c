#include <stdlib.h>
#include <stdio.h>

#include "binary_tree.h"

b_node* locate_root( b_node* target )
{
  if ( !target ) return NULL;

  while( target->parent != NULL )
  {
    target = target->parent;
  }
  return target;
}

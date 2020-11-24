#include <stdlib.h>
#include <stdio.h>

#include "binary_tree.h"

b_node* locate_parent( b_node* target )
{
  if ( !target ) return NULL;
  return target->parent;
}

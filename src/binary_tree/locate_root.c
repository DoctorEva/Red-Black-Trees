#include <stdlib.h>
#include <stdio.h>

#include "binary_tree.h"

b_node* locate_root( b_node* target )
{
  if( !target )
    return NULL;

  b_node* parent = locate_parent( target );

  return ( parent ) ? locate_root( parent ) : target;

}

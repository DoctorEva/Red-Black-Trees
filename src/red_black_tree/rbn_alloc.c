#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"

// [b_node] [ rb_node ] [ data ... size]

b_node* rbn_alloc( int id, void* src, size_t size )
{
  b_node* bnode = bn_alloc( id, src, sizeof( rb_node ) + size );

  rb_node* rbnode = rbn( bnode );
  rbnode->color = RED;
  return bnode;
}

rb_node* rbn( b_node* bnode )
{
  return (rb_node*) bn_DataPtr( bnode );
}

void* rbn_DataPtr( b_node* bn )
{
  if ( !bn )
    return NULL;

  return bn_DataPtr( bn ) + sizeof( rb_node );
}

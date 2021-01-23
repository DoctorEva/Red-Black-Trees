#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"

// [b_node] [ data ...size]

b_node* bn_alloc( int id, void* src, size_t size )
{
  b_node* node = malloc( sizeof( b_node ) + size );
  if ( !node )
  {
    fprintf( stderr, "Failed to allocate space in bn_alloc! Quitting.\n" );
    exit(1);
  }
  node->id     = id;
  node->size   = size;
  node->left   = NULL;
  node->right  = NULL;
  node->parent = NULL;

  if( src )
    memcpy( bn_DataPtr( node ), src, size );
  return node;
}

void* bn_DataPtr( b_node* bn )
{
  if( !bn )
    return NULL;
  void* start = (void*) bn;
  return ( start + sizeof( b_node ) );
}

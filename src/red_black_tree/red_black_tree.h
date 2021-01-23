#ifndef SUZUHA_H
#define SUZUHA_H

#include "../binary_tree/binary_tree.h"

typedef enum _paint{ RED, BLACK } paint;

typedef struct _redBlackTreeNode
{
  paint color;
} rb_node;

b_node*  rbn_alloc( int id, void* src, size_t size );
void*    rbn_DataPtr( b_node* bn );
rb_node* rbn( b_node* rbn );

b_node* rbn_insert( b_node* new, b_node* root );

#endif

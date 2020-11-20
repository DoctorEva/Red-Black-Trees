#ifndef SUZUHA_H
#define SUZUHA_H

#include "../binary_tree/binary_tree.h"

typedef enum _paint{ RED, BLACK } paint;

typedef struct _redBlackTreeNode
{
  b_node* node;
  paint color;
  
} rb_node;

rb_node* insert_rbnode( int value, rb_node* root);

#endif

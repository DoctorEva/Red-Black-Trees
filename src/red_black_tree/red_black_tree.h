#ifndef SUZUHA_H
#define SUZUHA_H

#include "../binary_tree/binary_tree.h"

typedef enum _paint{ RED, BLACK } paint;

typedef struct _redBlackTreeNode
{
  b_node* node;
  void* data;
  paint color;

} rb_node;

rb_node* insert_rbnode( int value, void* data, rb_node* root);
rb_node* _insert_rbnode( int value, void* data, rb_node* root, b_node** ret_loc );

#endif

#ifndef SUZUHA_H
#define SUZUHA_H

#include "../binary_tree/binary_tree.h"
#include "../linked_list/linked_list.h"

typedef enum _paint{ RED, BLACK } paint;

typedef struct _redBlackTreeNode
{
  b_node* node;
  paint color;

} rb_node;

rb_node* insert_rbnode( int value, rb_node* root);
rb_node* lookup_rbnode( b_node* target, Data_node* rbnode_list );


#endif

#ifndef BIN_H
#define BIN_H
#include <stddef.h>

typedef struct _binaryTreeNode
{
  int id;
  size_t size;
  struct _binaryTreeNode* left;
  struct _binaryTreeNode* right;
  struct _binaryTreeNode* parent;

} b_node;


b_node* bn_alloc( int id, void* src, size_t size );
void*   bn_DataPtr( b_node* bn );

b_node* bn_insert( b_node* new, b_node* root );

// traversals.c
void print_inorder( b_node* root );
void print_preorder( b_node* root );
void print_postorder( b_node* root );

int tree_depth( b_node* root );
void tree_trace( b_node* root );

b_node* locate_parent( b_node* target );
b_node* locate_sibling( b_node* target );

#endif

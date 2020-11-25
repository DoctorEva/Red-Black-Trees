#ifndef BIN_H
#define BIN_H

typedef struct _binaryTreeNode
{
  int value;
  void* data;

  struct _binaryTreeNode* left;
  struct _binaryTreeNode* right;

} b_node;

b_node* insert_bnode( int value, void* data, b_node* root );
b_node* _insert_bnode( int value, void* data, b_node* root, b_node** ret_loc );

// traversals.c
// NOTE: these are only the depth first traversals
void print_inorder( b_node* root );
void print_preorder( b_node* root );
void print_postorder( b_node* root );

int tree_depth( b_node* root );
void tree_trace( b_node* root );

b_node* locate_parent( b_node* target, b_node* root );
b_node* locate_sibling( b_node* target, b_node* root );
b_node* locate_root( b_node* target );

#endif

#ifndef BIN_H
#define BIN_H

typedef struct _binaryTreeNode
{
  int value;

  struct _binaryTreeNode* left;
  struct _binaryTreeNode* right;

} b_node;

b_node* insert_bnode( int value, b_node* root );

void print_inorder( b_node* root );
void print_preorder( b_node* root );
void print_postorder( b_node* root );

int tree_depth( b_node* root );

#endif

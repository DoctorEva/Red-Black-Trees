#include <stdlib.h>
#include <stdio.h>

#include "binary_tree.h"

void print_inorder( b_node* root )
{
  if ( !root ) return;

  print_inorder( root->left );
  printf( "| %d ", root->value );
  print_inorder( root->right );
}

void print_preorder( b_node* root )
{
  if ( !root ) return;

  printf( "| %d ", root->value );
  print_preorder( root->left );
  print_preorder( root->right );
}

void print_postorder( b_node* root )
{
  if ( !root ) return;

  print_postorder( root->left );
  print_postorder( root->right );
  printf( "| %d ", root->value );
}

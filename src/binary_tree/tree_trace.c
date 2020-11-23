#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "binary_tree.h"

void _tree_trace( b_node* root, int depth )
{
  if ( !root ) return;

  int self = root->value;
  char left_txt[6], right_txt[6];

  if ( root->left ) sprintf( left_txt, "%5d", root->left->value );
  else              strcpy( left_txt, "<nil>" );

  if ( root->right ) sprintf( right_txt, "%5d", root->right->value );
  else               strcpy( right_txt, "<nil>" );

  printf( "lv%d node:%6d |  l:%s  r:%s\n", depth, self, left_txt, right_txt );
  _tree_trace( root->left, depth+1 );
  _tree_trace( root->right, depth+1 );
}

void tree_trace( b_node* root )
{
  _tree_trace( root, 0 );
}

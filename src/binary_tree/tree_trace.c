#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "binary_tree.h"

void _tree_trace( b_node* root, int depth )
{
  if ( !root ) return;

  char left_txt[10], right_txt[10], parent_txt[10];

  if ( root->left ) sprintf( left_txt, "%5d", root->left->value );
  else              strcpy( left_txt, "<nil>" );

  if ( root->right ) sprintf( right_txt, "%5d", root->right->value );
  else               strcpy( right_txt, "<nil>" );

  if ( root->parent ) sprintf( parent_txt, "%5d", root->parent->value );
  else                strcpy( parent_txt, "<nil>" );

  printf( "lv%3d node:%6d |  l:%s  r:%s  p:%s\n", depth, root->value, left_txt, right_txt, parent_txt );
  _tree_trace( root->left, depth+1 );
  _tree_trace( root->right, depth+1 );
}

void tree_trace( b_node* root )
{
  _tree_trace( root, 0 );
}

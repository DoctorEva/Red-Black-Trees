#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

int max( int a, int b ) { return ( a > b ) ? a : b; }

int tree_depth( b_node* root )
{
  if ( !root )
    return 0;

  int left_depth  = 1 + tree_depth( root->left );
  int right_depth = 1 + tree_depth( root->right );

  return max( left_depth, right_depth );
}

//_____________________________________________________________

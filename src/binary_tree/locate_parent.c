#include <stdlib.h>
#include <stdio.h>

#include "binary_tree.h"

b_node* locate_parent( b_node* target, b_node* root )
{
  if( !root || !target )
    return NULL;

  int leftmatch = ( target == root->left );
  int rightmatch = ( target == root->right );
  if ( leftmatch || rightmatch )
    return root;

  b_node* leftSearch = locate_parent( target, root->left );
  if ( leftSearch ) return leftSearch;
  else              return locate_parent( target, root->right );
}

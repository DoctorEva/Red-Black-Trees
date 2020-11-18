#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

b_node* initialize_bnode( int value );

b_node* insert_bnode( int value, b_node* root )
{
  // If the root was null, create a new node and return.
  b_node* new_node = initialize_bnode( value );
  if( !root )
    return new_node;

  // If there was a root, traverse the tree and insert a new one.
  b_node* cur_node = root;

  while( 1 )
  {
    int go_left = ( value < cur_node->value );

    b_node* next_node = go_left ? cur_node->left : cur_node->right;

    if( !next_node )
    {
      if ( go_left ) cur_node->left = new_node;
      else           cur_node->right = new_node;

      printf("Inserted %d on the %s of node %d\n",
        value, go_left ? "left":"right", cur_node->value);
      return root;
    }

    cur_node = next_node;
  }

}

//_____________________________________________________________

b_node* initialize_bnode( int value )
{
  b_node* node = malloc( sizeof( b_node ) );
  node->value = value;
  node->left  = NULL;
  node->right = NULL;

  return node;
}

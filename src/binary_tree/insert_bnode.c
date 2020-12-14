#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

b_node* initialize_bnode( int value, void* data );

b_node* _insert_bnode( int value, void* data, b_node* root, b_node** ret_loc )
{
  // If the root was null, create a new node and return.
  b_node* new_node = initialize_bnode( value, data );
  if ( ret_loc )
    *ret_loc = new_node;
  if ( !root )
    return new_node;

  // If there was a root, traverse the tree and insert a new one.
  b_node* cur_node = root;

  while( 1 )
  {
    int go_left = ( value < cur_node->value );
    b_node* next_node = go_left ? cur_node->left : cur_node->right;

    if( !next_node )
    {
      // printf("Inserted %d on the %s of node %d\n", value, go_left ? "left":"right", cur_node->value);
      new_node->parent = cur_node;
      if ( go_left ) cur_node->left = new_node;
      else           cur_node->right = new_node;
      return root;
    }
    cur_node = next_node;
  }

}

b_node* insert_bnode( int value, void* data, b_node* root )
{
  return _insert_bnode( value, data, root, NULL );
}
//_____________________________________________________________

b_node* initialize_bnode( int value, void* data )
{
  b_node* node = malloc( sizeof( b_node ) );
  node->value = value;
  node->data = data;
  node->left  = NULL;
  node->right = NULL;
  node->parent = NULL;

  return node;
}

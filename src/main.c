// Written by Eva
// Created Nov 18 2020 11:22

#include <stdio.h>
#include <string.h>
#include "binary_tree/binary_tree.h"
#include "red_black_tree/red_black_tree.h"

#include "random_int.h"

void dump_tree( b_node* b_root );

int main( int argc, char** argv )
{
  b_node* b_root = NULL;
  b_node* rb_root = NULL;

  puts("MAIN > To demonstrate our binary tree, we are going to repeatedly insert randomly generated numbers into two trees.");
  puts("MAIN > One of these trees will be balanced as a red-black tree. The other will stay a simple binary tree.");

  for(int x = 0, r, max = 30000; x < max; x++, r = random_int( -200, 200 ) )
  {
    void* ptr = (void*) &r;
    size_t size = sizeof( int );

    b_node* new_bn = bn_alloc( x, ptr, size );
    b_node* new_rbn = rbn_alloc( x, ptr, size );

    b_root = bn_insert( new_bn, b_root );
    rb_root = rbn_insert( new_rbn, rb_root );

    printf( "progress: %4d / %4d\r", x+1, max );
  }

  puts( "\n=== BINARY TREE DUMP ===");
  dump_tree( b_root );

  puts( "\n=== RED BLACK TREE DUMP ===");
  dump_tree( rb_root );

  puts( "\nTree trace on binary tree" );
  //tree_trace( b_root );

  puts( "\nTree trace on red black tree" );
  //tree_trace( rb_root->node );

  return 0;
}

//____________________________________________________________
void dump_tree( b_node* b_root )
{
  if( !b_root )
    return;

  printf("Depth of tree: %d\n", tree_depth( b_root ));

  puts( "\nInorder traversal" );
  //print_inorder( b_root );

  puts( "\n\nPreorder traversal" );
  //print_preorder( b_root );

  puts( "\n\nPostorder traversal" );
  //print_postorder( b_root );
  puts("");
}

// Written by Eva
// Created Nov 18 2020 11:22

#include <stdio.h>
#include "binary_tree/binary_tree.h"

#include "random_int.h"

void dump_tree( b_node* b_root );

int main( int argc, char** argv )
{
  b_node* b_root = NULL;
  b_node* rb_tree = NULL;

  puts("MAIN > To demonstrate our binary tree, we are going to repeatedly insert randomly generated numbers into two trees.");
  puts("MAIN > One of these trees will be balanced as a red-black tree. The other will stay a simple binary tree.");

  for(int x = 0; x < 100; x++)
  {
    b_root = insert_bnode( random_int( -1000, 1000 ), b_root );
  }

  puts( "\n=== BINARY TREE DUMP ===");
  dump_tree( b_root );

  puts( "\n=== RED BLACK TREE DUMP ===");
  puts( "Coming soon...")''

  return 0;
}

//____________________________________________________________
void dump_tree( b_node* b_root )
{
  if( !b_root )
    exit(1);

  printf("Depth of tree: %d\n", tree_depth( b_root ));

  puts( "\nInorder traversal" );
  print_inorder( b_root );

  puts( "\n\nPreorder traversal" );
  print_preorder( b_root );

  puts( "\n\nPostorder traversal" );
  print_postorder( b_root );
  puts("");
}

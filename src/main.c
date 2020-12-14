// Written by Eva
// Created Nov 18 2020 11:22

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "binary_tree/binary_tree.h"
#include "red_black_tree/red_black_tree.h"

#include "random_int.h"

void dump_tree( b_node* b_root );

int main( int argc, char** argv )
{
  b_node* b_root = NULL;
  rb_node* rb_root = NULL;

  puts("MAIN > To demonstrate our binary tree, we are going to repeatedly insert randomly generated numbers into two trees.");
  puts("MAIN > One of these trees will be balanced as a red-black tree. The other will stay a simple binary tree.");

  double time_b_tree = 0;
  double time_rb_tree = 0;
  for(int x = 0, max = 1000000; x < max; x++)
  {
    clock_t start, end;
    int r = random_int( -100000, 100000 );

    start = clock();
    b_root  = insert_bnode( r, NULL, b_root );
    end = clock();
    time_b_tree += ((double) end - start ) / CLOCKS_PER_SEC;

    start = clock();
    rb_root = insert_rbnode( r, NULL, rb_root );
    end = clock();
    time_rb_tree += ((double) end - start ) / CLOCKS_PER_SEC;

    printf( "progress: %4d / %4d\r", x+1, max );
  }
  puts( "\n<Time taken>" );
  printf(" B-tree time: %f s\n", time_b_tree );
  printf("rb-tree time: %f s\n", time_rb_tree );

  puts( "\n=== BINARY TREE DUMP ===");
  //dump_tree( b_root );

  puts( "\n=== RED BLACK TREE DUMP ===");
  //dump_tree( rb_root->node );

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

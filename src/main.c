// Written by Eva
// Created Nov 18 2020 11:22

#include <stdio.h>
#include "binary_tree/binary_tree.h"

#include "random_int.h"

int main( int argc, char** argv )
{
  b_node* b_root = NULL;


  puts("MAIN > To demonstrate our binary tree, we are going to repeatedly insert randomly generated numbers into two trees.");
  puts("MAIN > One of these trees will be balanced as a red-black tree. The other will stay a simple binary tree.");

  for(int x = 0; x < 100; x++)
  {
    b_root = insert_bnode( random_int( -1000, 1000 ), b_root );
  }


  return 0;
}

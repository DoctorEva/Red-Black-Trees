// Written by Eva
// Created Nov 18 2020 11:22

#include <stdio.h>
#include <string.h>
#include "binary_tree/binary_tree.h"
#include "red_black_tree/red_black_tree.h"

#include "random_int.h"

void dump_tree( b_node* b_root );
void tree_trace( b_node* root, int depth );
void trace_path_example( b_node* b_root );

int main( int argc, char** argv )
{
  b_node* b_root = NULL;
  rb_node* rb_root = NULL;

  puts("MAIN > To demonstrate our binary tree, we are going to repeatedly insert randomly generated numbers into two trees.");
  puts("MAIN > One of these trees will be balanced as a red-black tree. The other will stay a simple binary tree.");

  for(int x = 0; x < 20; x++)
  {
    int r = random_int( -1000, 1000 );
    b_root  = insert_bnode( r , b_root );
    rb_root = insert_rbnode( r, rb_root );
  }

  puts( "\n=== BINARY TREE DUMP ===");
  dump_tree( b_root );

  puts( "\n=== RED BLACK TREE DUMP ===");
  dump_tree( rb_root->node );

  puts( "\nLets insert a new node '0' and trace where it ended up!");
  //trace_path_example( b_root );

  puts( "\nTree trace on binary tree" );
  tree_trace( b_root, 0 );

  puts( "\nTree trace on red black tree" );
  tree_trace( rb_root->node, 0 );


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

void tree_trace( b_node* root, int depth )
{
  if ( !root ) return;

  int self = root->value;
  char left_txt[10], right_txt[10];

  if ( root->left ) sprintf( left_txt, "%d", root->left->value );
  else              strcpy( left_txt, "<nil>" );

  if ( root->right ) sprintf( right_txt, "%d", root->right->value );
  else               strcpy( right_txt, "<nil>" );

  printf( "lv%d node:%d | l:%s \tr:%s\n", depth, self, left_txt, right_txt );
  tree_trace( root->left, depth+1 );
  tree_trace( root->right, depth+1 );
}

void trace_path_example( b_node* b_root )
{
  b_node* new;
  _insert_bnode( 0, b_root, &new );
  b_node* parent = locate_parent( new, b_root );
  b_node* sibling = locate_sibling( new, b_root );
  while( parent )
  {
    char sibling_txt[10];
    if ( sibling ) sprintf( sibling_txt, "%d", sibling->value );
    else           strcpy( sibling_txt, "<nil>" );
    printf("%d\tparent: %d\tsibling: %s\n", new->value, parent->value, sibling_txt);
    new = parent;
    parent = locate_parent( new, b_root );
    sibling = locate_sibling( new, b_root );
  }
}

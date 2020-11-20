#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"
#include "../linked_list/linked_list.h"

Data_node* program_rbnodes = NULL;

typedef struct _node_family
{
  b_node* self;
  b_node* parent;
  b_node* grandfather;
  b_node* sibling;
  b_node* uncle;
} node_family;

rb_node* lookup_rbnode( b_node* target );

rb_node* insert_rbnode( int value, rb_node* root)
{

  b_node* new_bnode,
        * parent_bnode,
        * binary_root = (root) ? root->node : NULL;

  // At the b_root level, insert the new node. Save where the new node went.
  _insert_bnode( value, binary_root, &new_bnode );

  // Create a new rb_node
  rb_node* rbn = malloc( sizeof( rb_node ) );
  rbn->node = new_bnode;
  rbn->color = BLACK;

  program_rbnodes = append_node( rbn, 0, program_rbnodes );

  // always return the rb_node that stores the root b_node
  return ( root ) ? root : rbn;
}

//______________________________________________________

rb_node* lookup_rbnode( b_node* target )
{
  Data_node* list = list_front( program_rbnodes );
  rb_node* cur_node = (rb_node*) list->value_ptr;

  while ( list && !(cur_node->node == target) )
  {
    list = list->next;
    cur_node = (rb_node*) list->value_ptr;
  }

  return cur_node;
}

void balance_tree( b_node* node, b_node* root )
{

}

node_family identify_family( b_node* node, b_node* root )
{
  node_family fam;
  fam.self = node;

  fam.parent      = locate_parent( fam.self, root );
  fam.grandfather = locate_parent( fam.parent, root );

  fam.sibling = locate_sibling( fam.self, root );
  fam.uncle   = locate_sibling( fam.parent, root );

  return fam;
}

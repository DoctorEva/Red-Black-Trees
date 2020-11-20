#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"

rb_node* lookup_rbnode( b_node* target, Data_node* rbnode_list )
{
  if ( !target )
    return NULL;

  Data_node* list = list_front( rbnode_list );
  rb_node* cur_node = (rb_node*) list->value_ptr;

  while ( list && !(cur_node->node == target) )
  {
    list = list->next;
    cur_node = (rb_node*) list->value_ptr;
  }

  return cur_node;
}

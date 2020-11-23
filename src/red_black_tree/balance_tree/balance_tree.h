#ifndef AMANE_H
#define AMANE_H

#include "../red_black_tree.h"

typedef enum _side{ LEFT, RIGHT } side;

typedef struct _node_family
{
  rb_node* self;
  rb_node* parent;
  rb_node* grandparent;
  rb_node* greatgrandparent;
  rb_node* uncle;
} node_family;

void balance_tree( b_node* node, b_node* root, Data_node* rbnode_list );

// Balance tree helpers.
node_family identify_family( b_node* node, b_node* root, Data_node* rbnode_list );
side getSide( b_node* node, b_node* parent );

// rotations.c
void right_rotate( b_node* pivot );
void left_rotate( b_node* pivot );

// rotation_cases.c
void LL_rotate( node_family f );
void LR_rotate( node_family f );
void RR_rotate( node_family f );
void RL_rotate( node_family f );


#endif

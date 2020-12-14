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

rb_node* balance_tree( b_node* node, rb_node* rbroot );

// Balance tree helpers.
node_family identify_family( b_node* node );
side getSide( b_node* node, b_node* parent );

// rotations.c
void right_rotate( b_node* pivot, b_node* pivot_parent );
void left_rotate( b_node* pivot, b_node* pivot_parent );

void make_rotations( node_family f );
// rotation_cases.c
void LL_rotate( node_family f );
void LR_rotate( node_family f );
void RR_rotate( node_family f );
void RL_rotate( node_family f );


#endif

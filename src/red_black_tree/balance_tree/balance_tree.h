#ifndef AMANE_H
#define AMANE_H

#include "../red_black_tree.h"

typedef enum _side{ LEFT, RIGHT } side;

typedef struct _node_family
{
  b_node* self;
  b_node* parent;
  b_node* grandparent;
  b_node* greatgrandparent;
  b_node* uncle;
} node_family;

b_node* balance_tree( b_node* new, b_node* root );

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

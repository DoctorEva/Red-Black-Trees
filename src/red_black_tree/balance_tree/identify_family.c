#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

node_family identify_family( b_node* node, b_node* root, Data_node* rbnode_list )
{
  node_family fam;
  b_node *self = node,
         *parent      = locate_parent( self, root ),
         *grandparent = locate_parent( parent, root ),
         *sibling = locate_sibling( self, root ),
         *uncle   = locate_sibling( parent, root );

  fam.self        = lookup_rbnode( self,        rbnode_list );
  fam.parent      = lookup_rbnode( parent,      rbnode_list );
  fam.grandparent = lookup_rbnode( grandparent, rbnode_list );
  fam.sibling     = lookup_rbnode( sibling,     rbnode_list );
  fam.uncle       = lookup_rbnode( uncle,       rbnode_list );
  return fam;
}

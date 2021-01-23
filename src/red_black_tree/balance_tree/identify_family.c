#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

node_family identify_family( b_node* node )
{
  b_node *self             = node,
         *parent           = locate_parent( self ),
         *grandparent      = locate_parent( parent ),
         *greatgrandparent = locate_parent( grandparent ),
         *uncle            = locate_sibling( parent );

  node_family fam = { self, parent, grandparent, greatgrandparent, uncle };
  return fam;
}

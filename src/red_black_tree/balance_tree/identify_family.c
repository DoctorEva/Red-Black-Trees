#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

void dump_family( node_family f );

rb_node* grab_rb( b_node* node )
{
  return ( node ) ? (rb_node*) node->data : NULL;
}

node_family identify_family( b_node* node, b_node* root )
{
  node_family fam;
  b_node *self             = node,
         *parent           = locate_parent( self, root ),
         *grandparent      = locate_parent( parent, root ),
         *greatgrandparent = locate_parent( grandparent, root ),
         *uncle            = locate_sibling( parent, root );

  fam.self             = grab_rb( self );
  fam.parent           = grab_rb( parent );
  fam.grandparent      = grab_rb( grandparent );
  fam.greatgrandparent = grab_rb( greatgrandparent );
  fam.uncle            = grab_rb( uncle );
  //dump_family( fam );
  return fam;
}

//____________________________________

char* ctxt[] = { "RED", "BLACK" };

void dump_family( node_family f )
{
  if (f.self)             printf( "\tX  : %p %4d %s\n", f.self,             f.self->node->value,             ctxt[f.self->color] );
  if (f.parent)           printf( "\tP  : %p %4d %s\n", f.parent,           f.parent->node->value,           ctxt[f.parent->color] );
  if (f.grandparent)      printf( "\tGP : %p %4d %s\n", f.grandparent,      f.grandparent->node->value,      ctxt[f.grandparent->color] );
  if (f.greatgrandparent) printf( "\tGGP: %p %4d %s\n", f.greatgrandparent, f.greatgrandparent->node->value, ctxt[f.greatgrandparent->color] );
  if (f.uncle)            printf( "\tU  : %p %4d %s\n", f.uncle,            f.uncle->node->value,            ctxt[f.uncle->color] );
}

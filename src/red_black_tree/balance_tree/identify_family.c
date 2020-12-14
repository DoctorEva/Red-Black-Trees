#include  <stdio.h>
#include <stdlib.h>

#include "balance_tree.h"

void dump_family_map( node_family f );
void test_validity( node_family f );

rb_node* grab_rb( b_node* node )
{
  return ( node ) ? (rb_node*) node->data : NULL;
}

node_family identify_family( b_node* node )
{
  node_family fam;
  b_node *self             = node,
         *parent           = locate_parent( self ),
         *grandparent      = locate_parent( parent ),
         *greatgrandparent = locate_parent( grandparent ),
         *uncle            = locate_sibling( parent );

  fam.self             = grab_rb( self );
  fam.parent           = grab_rb( parent );
  fam.grandparent      = grab_rb( grandparent );
  fam.greatgrandparent = grab_rb( greatgrandparent );
  fam.uncle            = grab_rb( uncle );

  //dump_family_map( fam );
  //test_validity( fam );
  return fam;
}

//____________________________________

void dump_family_map( node_family f )
{
  b_node* n[] = {
    (f.self)             ? f.self->node : NULL,
    (f.parent)           ? f.parent->node : NULL,
    (f.grandparent)      ? f.grandparent->node : NULL,
    (f.greatgrandparent) ? f.greatgrandparent->node : NULL,
    (f.uncle)            ? f.uncle->node : NULL
  };
  char* msg[] = {
    "X  ", "P  ", "GP ", "GGP", "U  ", "nil"
  };

  for( int i = 0; i < 5; i++ )
  {
    if ( !n[i] )
      continue;

    char* txt[4] = { "***", "***", "***", "***" };
    for( int a = 0; a < 5; a++ )
    {

      if ( n[i]         == n[a] ) txt[0] = (n[i] )         ? msg[a] : msg[5] ;
      if ( n[i]->left   == n[a] ) txt[1] = (n[i]->left )   ? msg[a] : msg[5] ;
      if ( n[i]->right  == n[a] ) txt[2] = (n[i]->right )  ? msg[a] : msg[5] ;
      if ( n[i]->parent == n[a] ) txt[3] = (n[i]->parent ) ? msg[a] : msg[5] ;
    }
    printf( "\t%s %p : l: %s r: %s p: %s\n", txt[0], n[i], txt[1], txt[2], txt[3] );
  }
}

void test_validity( node_family f )
{
  b_node *s   = (f.self)             ? f.self->node : NULL,
         *p   = (f.parent)           ? f.parent->node : NULL,
         *gp  = (f.grandparent)      ? f.grandparent->node : NULL,
         *gpp = (f.greatgrandparent) ? f.greatgrandparent->node : NULL,
         *u   = (f.uncle)            ? f.uncle->node : NULL;

  int err = 0;
  char* msg[] = {
    "self does not point to parent",
    "parent does not point to self",
    "p does not point to gp",
    "gp does not point to p",
    "gp does not point to gpp",
    "gpp does not point to gp",
    "u does not point to gp",
    "gp does not point to u",
    "u and p do not point to the same gp"
  };
  if ( s && p && s->parent != p)       err += 1 >> 0;
  if ( p && gp && p->parent != gp)     err += 1 >> 2;
  if ( gp && gpp && gp->parent != gpp) err += 1 >> 4;
  if ( u && gp && u->parent != gp)     err += 1 >> 6;

  if ( s && p && p->left != s && p->right != s )          err += 1 >> 1;
  if ( p && gp && gp->left != p && gp->right != p )       err += 1 >> 3;
  if ( u && gp && gp->left != u && gp->right != u )       err += 1 >> 7;
  if ( gp && gpp && gpp->left != gp && gpp->right != gp ) err += 1 >> 5;

  if ( u && p && u->parent != p->parent ) err += 1 >> 8;

  if ( err )
  {
    for( int i = 0; i <= 7; i++ )
    {
      if ( err & 1>>i )
        printf( "%s\n", msg[i] );
    }

    exit( 1 );
  }
}

#ifndef KURISU_H
#define KURISU_H

#include <time.h>
#include <stdlib.h>

int random_int( int min, int max )
{
  static int __didnt_init = 1;
  if( __didnt_init )
  {
    srand( time(0) );
    __didnt_init = 0;
  }

  int delta = abs( max - min );
  int random = rand() % delta;
  return min + random;
}

#endif

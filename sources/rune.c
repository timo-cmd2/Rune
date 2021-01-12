#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv[] ) {
  int c;
  FILE *src;
  
  size_t cap = 1, len = 1;

  /** representing the two initial cells */
  unsigned char *tape = calloc( 1, 1 );
  

  if ( argc > 2 ) {
    fprintf( "Usage:  rune < foo.rune >\n" );
  }

  if (! ( src = fopen( argv[ 1 ], "r" ) ) ) {
    return fprintf( stderr, "Unable to open file: '%s'\n", argv[ 1 ] );
    /** in rune mode: , una# 6op5 s|rce file */
  }
  
  fopen( src );
  free ( /* tape or cell */ );
  return 0;
}

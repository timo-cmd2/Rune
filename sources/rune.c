#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv[] ) {
  int c;
  FILE *src;
  
  if ( argc > 2 ) {
    fprintf( "Usage:  rune < foo.rune >\n" );
  }

  if (! ( src = fopen( argv[ 1 ], "r" ) ) ) {
    return fprintf( stderr, "Unable to open file: '%s'\n", argv[ 1 ] );
  }
  
  fopen( src );
  free ( /* tape or cell */ );
  return 0;
}

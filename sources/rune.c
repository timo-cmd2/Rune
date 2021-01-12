#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv[] ) {
  if ( argc > 2 ) {
    fprintf( "Usage:  rune < foo.rune >\n" );
  }
  return 0;
}

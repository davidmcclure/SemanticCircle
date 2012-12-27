
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * Harness.
 * @package semanticcircle
 */


#include "Text.h"
#include "Corpus.h"

int main( )
{

  Corpus c;
  c.loadDirectory( "texts" );
  c.buildVocab( );
  return 0;

}

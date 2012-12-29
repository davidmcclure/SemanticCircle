
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * Harness.
 * @package semanticcircle
 */


#include "Text.h"
#include "Corpus.h"
#include "Circle.h"
#include "Loop.h"

void printLoop( Loop* loop );

int main( )
{

  Corpus corpus;
  corpus.loadFile( "texts/test.txt" );
  corpus.buildLinks( );

  Loop loop( corpus.vocab );

  return 0;

}

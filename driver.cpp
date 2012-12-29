
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * Harness.
 * @package semanticcircle
 */


#include "Text.h"
#include "Corpus.h"
#include "Circle.h"
#include "Loop.h"
#include "Modeller.h"

void printLoop( Loop* loop );

int main( )
{

  Corpus corpus;
  corpus.loadFile( "texts/article.txt" );
  corpus.buildLinks( );

  Modeller model( &corpus );
  model.model( 100 );

  return 0;

}

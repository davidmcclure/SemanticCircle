
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
#include <cstdio>
#include <iostream>


void printLoop( Loop* loop );


int main( )
{

  Corpus corpus;
  corpus.loadFile( "texts/winters_tale.txt" );
  corpus.buildLinks( );
  Modeller model( &corpus );

  cout << model.totalLinkSum( );
  model.model( 50 );
  printLoop( model.loop );

  return 0;

}


/*
 * Print the list.
 */
void printLoop( Loop* loop )
{
  for( int i=0; i<loop->words.size( ); i++ )
  {
    cout << loop->words[i] << endl;
  }
}

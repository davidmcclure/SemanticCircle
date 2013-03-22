
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
using namespace std;

int main( )
{

  Corpus corpus;
  corpus.loadFile( "texts/micro.txt" );
  corpus.buildLinks( );
  Modeller model( &corpus );

  double s1 = model.totalLinkSum( );
  model.swap( 1000000 );
  double s2 = model.totalLinkSum( );
  model.print( );
  cout << s1 << endl;
  cout << s2 << endl;

  return 0;

}

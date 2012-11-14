/* vim: set expandtab tabstop=2 shiftwidth=2 softtabstop=2; */

/**
 * A collection of texts.
 *
 * @package     semanticcircle
 * @license     http://www.apache.org/licenses/LICENSE-2.0.html
 */


#include <string>
#include <fstream>
#include <sstream>
#include <streambuf>
#include <iostream>
#include "Text.h"
#include "Corpus.h"
using namespace std;


/*
 * Load an individual text file.
 *
 * @param const string: The filepath.
 * @return void.
 */
void Corpus::loadFile( string path )
{

  // Load file.
  ifstream file( path.c_str( ) );
  stringstream buffer;
  buffer << file.rdbuf( );

  // Create text.
  Text* t = new Text( buffer.str( ) );
  texts.push_back( t );

}


/*
 * Load all text files in a directory.
 *
 * @param const string: The directory path.
 * @return void.
 */
void Corpus::loadDirectory( const string path )
{

}

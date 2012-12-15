
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
#include <algorithm>
#include <dirent.h>
#include <boost/foreach.hpp>
#include <boost/unordered_set.hpp>
#include "Text.h"
#include "Corpus.h"
using namespace std;


/*
 * Load an individual text file.
 *
 * @param const string: The filepath.
 * @return void.
 */
void Corpus::loadFile( const string path )
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

  // Open the directory.
  DIR* dir = opendir( path.c_str( ) );
  struct dirent *entry;

  // Walk the directory.
  while( (entry = readdir(dir)) != NULL )
  {
    const string f = path + "/" + entry->d_name;
    loadFile( f );
  }

}


/*
 * Compute the unique vocabulary.
 *
 * @return void.
 */
void Corpus::buildVocab( )
{

  // Set of seen tokens.
  unordered_set<string> seen;

  // Walk texts:
  BOOST_FOREACH( Text* text, texts )
  {

    // Walk tokens:
    BOOST_FOREACH( const string t, *(text->tokens) )
    {

      // Add to vocab if unseen.
      if( seen.find( t ) == seen.end( ) )
      {
        vocab.push_back( t );
        seen.insert(t);
      }

    }

  }

  cout << vocab.size( ) << endl;
  cout << seen.size( ) << endl;

}

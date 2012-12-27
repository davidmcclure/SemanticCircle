
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * A collection of texts.
 * @package semanticcircle
 */


#include <string>
#include <fstream>
#include <sstream>
#include <streambuf>
#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include "Text.h"
#include "Corpus.h"

using namespace std;
using namespace boost;


/*
 * Load an individual text file.
 * @param const string: The filepath.
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
 * @param const string: The directory path.
 */
void Corpus::loadDirectory( const string path )
{

  // Open the directory.
  DIR* dir = opendir( path.c_str( ) );
  struct dirent *entry;

  // Create texts.
  while( (entry = readdir(dir)) != NULL )
  {
    const string f = path + "/" + entry->d_name;
    loadFile( f );
  }

}


/*
 * Track word adjacencies and frequencies.
 */
void Corpus::buildVocab( )
{

  // Walk texts.
  BOOST_FOREACH( Text* text, texts )
  {

    // Get text length.
    int len = text->words.size( );

    // Zipper triplets.
    for( int i=1; i<len-1; i++ )
    {
      vocab[text->words[i]][text->words[i-1]]++;
      vocab[text->words[i]][text->words[i+1]]++;
    }

  }

}

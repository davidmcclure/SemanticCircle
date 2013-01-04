
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * A collection of texts.
 * @package semanticcircle
 */


#include <string>
#include <fstream>
#include <sstream>
#include <streambuf>
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
 * Compute unique vocabulary and hash of word adjacencies.
 */
void Corpus::buildLinks( )
{

  set<string> seen;

  // Walk texts.
  BOOST_FOREACH( Text* text, texts )
  {

    // Add to corpus vector.
    words.insert( words.end( ), text->words.begin( ),
        text->words.end( ) );

    // Get text length.
    int len = text->words.size( );

    // First/last.
    if( len > 0 )
    {

      // Increment link counters.
      links[text->words[0]][text->words[1]]++;
      links[text->words[len-1]][text->words[len-2]]++;

      // Add to unique vocabulary.
      seen.insert( text->words[0] );
      seen.insert( text->words[len-1] );

      // Increment word counters.
      counts[text->words[0]]++;
      counts[text->words[len-1]]++;

    }

    // Interior words.
    for( int i=1; i<len-1; i++ )
    {

      // Increment link counters.
      links[text->words[i]][text->words[i-1]]++;
      links[text->words[i]][text->words[i+1]]++;

      // Add to unique vocabulary.
      seen.insert( text->words[i] );

      // Increment word counters.
      counts[text->words[i]]++;

    }

  }

  // Push vocab to vector.
  set<string>::iterator itr = seen.begin( );
  for( itr; itr != seen.end( ); ++itr )
  {
    vocab.push_back( *itr );
  }

  // Shuffle vocab.
  random_shuffle( vocab.begin( ), vocab.end( ) );

}

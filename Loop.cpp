
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * A vector that can loop elements forward and backward.
 * @package semanticcircle
 */


#include <iostream>
#include "Loop.h"

using namespace std;


/*
 * Store words vector, initialize offsets map.
 * @param vector<string> words: The vector of words.
 */
Loop::Loop( vector<string> words ) : words( words )
{

  // Store size.
  size = words.size( );

  // Initialize offsets map.
  for( int i=0; i<size; i++ )
  {
    offsets[words[i]] = i;
  }

}


/*
 * Push a word foward in the list.
 * @param const string word: The word to increment.
 */
void Loop::increment( const string word )
{

  int offset = offsets[word];

  // If not last.
  if( offset != size-1 )
  {

    // Switch in vector.
    string next = words[offset+1];
    words[offset+1] = word;
    words[offset] = next;

    // Update offsets map.
    offsets[word] = offset+1;
    offsets[next] = offset;

  }

  else
  {
    // Switch in vector.
    string first = words[0];
    words[0] = word;
    words[size-1] = first;

    // Update offsets map.
    offsets[word] = 0;
    offsets[first] = size-1;

  }

}


/*
 * Push a word backward in the list.
 * @param const string word: The word to decrement.
 */
void Loop::decrement( const string word )
{

  int offset = offsets[word];

  // If not first.
  if( offset != 0 )
  {

    // Switch in vector.
    string prev = words[offset-1];
    words[offset-1] = word;
    words[offset] = prev;

    // Update offsets map.
    offsets[word] = offset-1;
    offsets[prev] = offset;

  }

  else
  {
    // Switch in vector.
    string last = words[size-1];
    words[size-1] = word;
    words[0] = last;

    // Update offsets map.
    offsets[word] = size-1;
    offsets[last] = 0;

  }

}


/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * An individual text.
 * @package semanticcircle
 */


#include <string>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>
#include "Text.h"

using namespace std;
using namespace boost;


/*
 * Set text, tokenize.
 * @param string: The source stream.
 */
Text::Text( string text )
{
  tokenize( text );
}

/*
 * Tokenize the source string.
 * @param string: The source stream.
 */
void Text::tokenize( string text )
{

  // Lowercase the stream.
  algorithm::to_lower(text);

  // Tokenize.
  char_separator<char> sep( " ():;,!?./\"*-" );
  tokens = new tokenizer< char_separator<char> >( text, sep );

  // Push tokens into vector.
  BOOST_FOREACH( const string& t, *tokens )
  {
    words.push_back( t );
  }

}


/* vim: set expandtab tabstop=2 shiftwidth=2 softtabstop=2; */

/**
 * A text in a corpus.
 *
 * @package     semanticcircle
 * @license     http://www.apache.org/licenses/LICENSE-2.0.html
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
 *
 * @param string: The source stream.
 * @return void.
 */
Text::Text( string text )
{
  tokenize( text );
}

/*
 * Tokenize the source string.
 *
 * @param string: The source stream.
 * @return void.
 */
void Text::tokenize( string text )
{

  // Lowercase the stream.
  algorithm::to_lower(text);

  // Tokenize.
  char_separator<char> sep( " ():;,!?./\"*-" );
  tokens = new tokenizer< char_separator<char> >( text, sep );

}

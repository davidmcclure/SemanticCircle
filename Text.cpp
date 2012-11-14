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
Text::Text( string text ) : text( text )
{
  tokenize( );
}

/*
 * Tokenize the source string.
 *
 * @return void.
 */
void Text::tokenize( )
{
  char_separator<char> sep( " ():;,!?./\"*" );
  tokens = new tokenizer< char_separator<char> >( text, sep );
}

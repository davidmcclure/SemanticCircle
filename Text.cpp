

#include <string>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include "Text.h"
using namespace std;
using namespace boost;


Text::Text( string * text ) : text( text )
{
  tokenize( );
}


void Text::tokenize( )
{

  // Get separator, tokenize.
  char_separator<char> sep( " ():;,!?./\"*" );
  tokenizer< char_separator<char> > tokens( *text, sep );

  // Print tokens.
  BOOST_FOREACH( const string& t, tokens )
  {
    cout << t << endl;
  }

}

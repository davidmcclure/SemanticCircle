
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * An individual text.
 * @package semanticcircle
 */


#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;


class Text
{

  public:

    Text( string text );
    tokenizer< char_separator<char> > *tokens;
    vector<string> words;

  private:

    void tokenize( string text );

};


#endif

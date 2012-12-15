
/* vim: set expandtab tabstop=2 shiftwidth=2 softtabstop=2; */

/**
 * A text in a corpus.
 *
 * @package     semanticcircle
 * @license     http://www.apache.org/licenses/LICENSE-2.0.html
 */


#ifndef TEXT_H
#define TEXT_H

#include <set>
#include <string>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;


class Text
{

  public:

    Text( string text );
    tokenizer< char_separator<char> > * tokens;

  private:

    void tokenize( string text );

};


#endif

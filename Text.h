/* vim: set expandtab tabstop=2 shiftwidth=2 softtabstop=2; */

/**
 * A text in a corpus.
 *
 * @package     semanticcircle
 * @license     http://www.apache.org/licenses/LICENSE-2.0.html
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

    /*
     * Set text, tokenize.
     *
     * @param string: The source stream.
     * @return void.
     */
    Text( string text );

  private:

    /*
     * Tokenize the source string.
     *
     * @return void.
     */
    void tokenize( );

    /*
     * The token vector.
     */
    tokenizer< char_separator<char> > * tokens;

    /*
     * The source text stream.
     */
    string text;

};


#endif

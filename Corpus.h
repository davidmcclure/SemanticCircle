
/* vim: set expandtab tabstop=2 shiftwidth=2 softtabstop=2; */

/**
 * A collection of texts.
 *
 * @package     semanticcircle
 * @license     http://www.apache.org/licenses/LICENSE-2.0.html
 */


#ifndef CORPUS_H
#define CORPUS_H

#include <vector>
#include "Text.h"
using namespace std;


class Corpus
{

  public:

    void loadFile( const string path );
    void loadDirectory( const string path );
    void buildVocab( );

  private:

    vector<Text*> texts;
    vector<string> vocab;

};


#endif

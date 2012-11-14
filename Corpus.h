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

    /*
     * Load an individual text file.
     *
     * @param const string: The filepath.
     * @return void.
     */
    void loadFile( const string path );

    /*
     * Load all text files in a directory.
     *
     * @param const string: The directory path.
     * @return void.
     */
    void loadDirectory( const string path );

  private:

    /*
     * Vector of pointers to texts.
     */
    vector<Text*> texts;

};


#endif

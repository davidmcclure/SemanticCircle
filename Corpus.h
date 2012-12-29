
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * A collection of texts.
 * @package semanticcircle
 */


#ifndef CORPUS_H
#define CORPUS_H

#include <boost/unordered_map.hpp>
#include "Text.h"

using namespace std;

typedef unordered_map<string, unordered_map<string, int> >
  link_hash;


class Corpus
{

  public:

    friend class Circle;

    void loadFile( const string path );
    void loadDirectory( const string path );
    void buildLinks( );

    vector<Text*> texts;
    vector<string> words;
    vector<string> vocab;
    link_hash links;

};


#endif


/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * A collection of texts.
 * @package semanticcircle
 */


#ifndef CORPUS_H
#define CORPUS_H

#include <vector>
#include <boost/unordered_map.hpp>
#include "Text.h"

using namespace std;

typedef unordered_map<string, unordered_map<string, int> >
  vocabHash;


class Corpus
{

  public:

    void loadFile( const string path );
    void loadDirectory( const string path );
    void buildVocab( );

  private:

    vector<Text*> texts;
    vocabHash vocab;

};


#endif

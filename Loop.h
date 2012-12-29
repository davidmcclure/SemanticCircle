
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * A vector that can loop elements forward and backward.
 * @package semanticcircle
 */


#ifndef LOOP_H
#define LOOP_H

#include <boost/unordered_map.hpp>
#include <vector>

using namespace std;
using namespace boost;


class Loop
{

  public:

    Loop( vector<string> words );

    unordered_map<string, int> offsets;
    vector<string> words;

    void increment( const string word );
    void decrement( const string word );

  private:

    int size;

};


#endif


/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * A circle, centered around the origin.
 * @package semanticcircle
 */


#ifndef CIRCLE_H
#define CIRCLE_H

#include <vector>
#include "Corpus.h"

using namespace std;


class Circle
{

  public:

    Circle( int count );
    vector< vector<double> > points;

  private:

    int count;
    void generate( );

};


#endif

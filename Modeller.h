
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * Sematic circle modeller.
 * @package semanticcircle
 */


#ifndef MODELLER_H
#define MODELLER_H

#include "Circle.h"
#include "Corpus.h"
#include "Loop.h"

using namespace std;


class Modeller
{

  public:

    Modeller( Corpus* corpus );

    Corpus* corpus;
    Circle* circle;
    Loop* loop;

    double linkSum( string word );
    double averageLinkLength( string word );
    double totalLinkSum( );
    void model( int itr );
    void swap( int itr );
    void print( );

};


double _d(vector<double> p1, vector<double> p2);
int _r(int min, int max);


#endif

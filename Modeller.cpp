
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * Sematic circle modeller.
 * @package semanticcircle
 */


#include "math.h"
#include "Modeller.h"

using namespace std;


/*
 * Store the corpus reference, create circle and loop.
 * @param Corpus* corpus: The corpus pointer.
 */
Modeller::Modeller( Corpus* corpus ) : corpus( corpus )
{
  circle = new Circle( corpus->vocab.size( ) );
  loop = new Loop( corpus->vocab );
}


/*
 * For some given word, compute the sum of the link segments
 * for all adjacent words.
 * @param string word: The word.
 * @return double sum: The link sum.
 */
double Modeller::sumWordLinks( string word )
{

  double sum = 0;

  // Get base point.
  vector<double> p1 = circle->points[loop->offsets[word]];
  vector<double> p2;

  // Get iterator for word links.
  unordered_map<string, int>::iterator itr =
    corpus->links[word].begin( );

  // Walk links.
  for( itr; itr != corpus->links[word].end( ); ++itr )
  {
    p2 = circle->points[loop->offsets[itr->first]];
    sum += itr->second * _d( p1, p2 );
  }

  return sum;

}


/*
 * Compute the total sum of the connector line.
 * @return double sum: The link sum.
 */
double Modeller::totalLinkSum( )
{

  double sum = 0;

  // Walk words.
  for( int i=0; i<corpus->words.size( )-1; i++ )
  {

    // Get points.
    vector<double> p1 = circle->points[
      loop->offsets[corpus->words[i]]];
    vector<double> p2 = circle->points[
      loop->offsets[corpus->words[i+1]]];

    // Add distance.
    sum += _d( p1, p2 );

  }

}


/*
 * Model the circle.
 * @param int itr: The number of iterations.
 */
void Modeller::model( int itr )
{

  for( int i=0; i<itr; i++ )
  {

    // Walk unique words.
    vector<string>::iterator itr = corpus->vocab.begin( );
    for( itr; itr != corpus->vocab.end( ); ++itr )
    {

      // Wiggle to get spin direction.
      double curr = sumWordLinks( *itr );
      loop->increment( *itr );
      double next = sumWordLinks( *itr );
      loop->decrement( *itr );
      loop->decrement( *itr );
      double prev = sumWordLinks( *itr );
      loop->increment( *itr );

      // Word is optimally positioned.
      if( curr < next && curr < prev )
      {
        continue;
      }

      // Spin forward
      else if( next < prev )
      {
        for( int j=0; j<corpus->vocab.size( ); j++ )
        {
          loop->increment( *itr );
          double val = sumWordLinks( *itr );
          if( val > curr ) break;
          curr = val;
        }
      }

      // Spin backward
      else if( prev < next )
      {
        for( int j=0; j<corpus->vocab.size( ); j++ )
        {
          loop->decrement( *itr );
          double val = sumWordLinks( *itr );
          if( val > curr ) break;
          curr = val;
        }

      }

    }

    cout << totalLinkSum( ) << endl;

  }

}


/*
 * Compute the linear distance between two points.
 * @param vector<double> p1: The first point.
 * @param vector<double> p2: The second point.
 */
double _d(vector<double> p1, vector<double> p2)
{
  double dx = p1[0] - p2[0];
  double dy = p1[1] - p2[1];
  return sqrt( pow( dx,2 ) + pow( dy,2 ) );
}

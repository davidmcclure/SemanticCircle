
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * Sematic circle modeller.
 * @package semanticcircle
 */


#include "math.h"
#include "Modeller.h"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>

boost::mt19937 gen;


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
 * Compute the sum of the link segments for a word.
 * @param string word: The word.
 * @return double sum: The link sum.
 */
double Modeller::linkSum( string word )
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
 * Compute the word count divided by the total link length.
 * @param string word: The word.
 * @return double len: The average length.
 */
double Modeller::averageLinkLength( string word )
{
  return linkSum( word ) / corpus->counts[word];
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
      double curr = linkSum( *itr );
      loop->increment( *itr );
      double next = linkSum( *itr );
      loop->decrement( *itr );
      loop->decrement( *itr );
      double prev = linkSum( *itr );
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
          double val = linkSum( *itr );
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
          double val = linkSum( *itr );
          if( val > curr ) break;
          curr = val;
        }

      }

    }

  }

}


/*
 * Model the circle via randow swapping.
 * @param int itr: The number of iterations.
 */
void Modeller::swap( int itr )
{

  // Cache loop size.
  int size = loop->words.size( )-1;

  // Get starting length.
  double curr = totalLinkSum( );

  for( int i=0; i<itr; i++ )
  {

    // Get random indices.
    int i1 = _r( 0, size );
    int i2 = _r( 0, size );

    // Get starting sums.
    double sum1a = linkSum( loop->words[i1] );
    double sum2a = linkSum( loop->words[i2] );

    // Swap, recompute.
    loop->swap( i1, i2 );
    double sum1b = linkSum( loop->words[i2] );
    double sum2b = linkSum( loop->words[i1] );

    // Unswap if larger.
    if( !((sum1b-sum1a)+(sum2b-sum2a)<0) )
    {
      loop->swap( i1, i2 );
    }

  }

}


/*
 * Print the circle.
 */
void Modeller::print( )
{
  for( int i=0; i<loop->words.size( ); i++ )
  {
    cout << loop->words[i] << " ";
    cout << circle->points[i][0] << " ";
    cout << circle->points[i][1] << endl;
  }
}


/*
 * Compute the linear distance between two points.
 * @param vector<double> p1: The first point.
 * @param vector<double> p2: The second point.
 */
double _d( vector<double> p1, vector<double> p2 )
{
  double dx = p1[0] - p2[0];
  double dy = p1[1] - p2[1];
  return sqrt( pow( dx,2 ) + pow( dy,2 ) );
}


/*
 * Generate a random number in a range.
 * @param int min: The low boundary.
 * @param int max: The high boundary.
 * @return int: The number.
 */
int _r( int min, int max )
{
  boost::uniform_int<> dist( min, max );
  boost::variate_generator<
    boost::mt19937&, boost::uniform_int<> > die( gen, dist );
  return die( );
}

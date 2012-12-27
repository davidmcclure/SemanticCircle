
/* vim: set tabstop=2 shiftwidth=2 softtabstop=2 cc=64; */

/**
 * A circle, centered around the origin.
 * @package semanticcircle
 */


#include "math.h"
#include <iostream>
#include "Circle.h"

using namespace std;


/*
 * Generate the circle.
 * @param int count: The number of points.
 */
Circle::Circle( int count ) : count( count )
{
  generate( );
}


/*
 * Generate the circle.
 * @param int count: The number of points.
 */
void Circle::generate( )
{

  // Compute degree interval.
  double interval = 360 / (double) count;

  for( int i=0; i<count; i++ )
  {

    // Construct x/y coords.
    double angle = ( interval*i ) * ( M_PI/180 );
    double x = count * cos( angle );
    double y = count * sin( angle );

    // Create point.
    vector<double> pt;
    pt.push_back( x );
    pt.push_back( y );

    // Add point.
    points.push_back( pt );

  }

}

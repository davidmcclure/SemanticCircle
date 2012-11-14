/* vim: set expandtab tabstop=2 shiftwidth=2 softtabstop=2; */

/**
 * Harness.
 *
 * @package     semanticcircle
 * @license     http://www.apache.org/licenses/LICENSE-2.0.html
 */


#include "Text.h"
#include "Corpus.h"

int main( )
{

  // unordered_map<int, unordered_map<int, int> > test1;
  // unordered_map<int, int> test2;
  // test2[4] = 5;
  // test1[2] = test2;
  // cout << test1[2][4];

  Corpus c;
  c.loadFile( "tolstoy/war-and-peace.txt" );
  return 0;
}



#ifndef TEXT_H
#define TEXT_H

#include <string>
using namespace std;


class Text
{

  public:

    Text( string * text );

  private:

    void tokenize( );
    string * text;

};


#endif

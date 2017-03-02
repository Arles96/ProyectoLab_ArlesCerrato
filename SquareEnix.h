#ifndef SQUAREENIX_H_
#define SQUAREENIX_H_

#include "Videojuegos.h"

class SquareEnix : public Videojuegos
{
private:
  string square_enix = "Square Enix";

public:

  //Constructores
  SquareEnix();
  SquareEnix(string,int,Consola*,int,string,string,int,double);

  //getter
  string getSquare_enix();
  
};

#endif

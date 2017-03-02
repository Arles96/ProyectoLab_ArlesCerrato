#ifndef SEGA_H_
#define SEGA_H_

#include "Videojuegos.h"

class Sega : public Videojuegos
{
private:
  string sega = "Sega";

public:

  //Constructores
  Sega();
  Sega(string,int,Consola*,int,string,string,int,double);

  //getter
  string getSega();
};

#endif

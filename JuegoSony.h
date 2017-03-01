#ifndef JUEGOSONY_H_
#define JUEGOSONY_H_

#include "Videojuegos"

class JuegoSony : public Videojuegos
{
private:
  string sony = "Sony";

public:

  //Destructores
  JuegoSony();
  JuegoSony(string, int, Consola*, int,string,string,int,double);

  //getter
  string getSony();
};

#endif

#ifndef KONAMI_H_
#define KONAMI_H_

#include "Videojuegos.h"

class Konami : public Videojuegos
{
private:
  string konami = "Konami";

public:

  //Constructores
  Konami();
  Konami(string,int,Consola*,int,string,string,int,double);

  //getter
  string getKonami();
};

#endif

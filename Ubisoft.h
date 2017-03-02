#ifndef UBISOFT_H_
#define UBISOFT_H_

#include "Videojuegos.h"

class Ubisoft : public Videojuegos
{
private:
  string ubisoft = "Ubisoft";

public:

  //Constructores
  Ubisoft();
  Ubisoft(string,int,Consola*,int,string,string,int,double);

  //getter
  string getUbisoft();
};

#endif

#ifndef BANDAI_H_
#define BANDAI_H_

#include "Videojuegos.h"

class Bandai : public Videojuegos
{
private:
  string bandai = "Bandai";

public:

  //Constructores
  Bandai();
  Bandai(string, int, Consola*, int, string,string,int,double);

  //getter
  string getBandai();
  
};

#endif

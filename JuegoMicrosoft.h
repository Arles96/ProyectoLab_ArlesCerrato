#ifndef JUEGOMICROSOFT_H_
#define JUEGOMICROSOFT_H_

#include "Videojuegos.h"

class JuegoMicrosoft : public Videojuegos
{
private:
  string microsoft = "Microsoft";

public:

  //Constructores
  JuegoMicrosoft();
  JuegoMicrosoft(string, int, Consola*, int, string, string, int, double);

  //getter
  string getMicrosoft();
};

#endif

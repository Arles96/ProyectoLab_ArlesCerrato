#ifndef MICROSOFT_H_
#define MICROSOFT_H_
#pragma

#include <string>
#include "Consola.h"

using namespace std;

class Microsoft : public Consola
{
public:

  //Constructores
  Microsoft();
  Microsoft(int, string, string, int, double);

  //Destructor
  ~Microsoft();
};

#endif

#ifndef MICROSOFT_H_
#define MICROSOFT_H_

#include <string>
#include "Consola.h"

using namespace std;

class Microsoft : public Consola
{
private:
  string tipo;
public:

  //Constructores
  Microsoft();
  Microsoft(int, string, string, int, double, string);

  //Destructor
  ~Microsoft();

  //Setter
  void setTipo(string);

  //getter
  string getTipo();
};

#endif

#ifndef VENDEDOR_H_
#define VENDEDOR_H_

#include <string>
#include <ctime>
#include <sstream>
#include "Usuario.h"

using namespace std;

class Vendedor : public Usuario
{
private:
  string hora_inicio;
  string hora_final;
public:

  //Constructores
  Vendedor();
  Vendedor(string);

  //Destructor
  ~Vendedor();

  //Setter
  void setHora_inicial();
  void setHora_final();

  //getter
  string getHora_inicial();
  string getHora_final();

};

#endif

#pragma once

#include "Usuario.h"
#include <string>

using namespace std;

class Administrador : public Usuario
{
private:
  string contrasena;

public:

  //Constructores
  Administrador();
  Administrador(string,string);

  //Destructor
  ~Administrador();

  //setter
  void setContrasena(string);

  //Getter
  string getContrasena();

};

#ifndef USUARIO_H_
#define USUARIO_H_
#pragma

#include <string>

using namespace std;

class Usuario
{
protected:
  string nombre;

public:

  //Constructores
  Usuario();
  Usuario(string);

  //Destructor
  ~Usuario();

  //setter
  void setNombre(string);

  //Getter
  string getNombre();
};

#endif

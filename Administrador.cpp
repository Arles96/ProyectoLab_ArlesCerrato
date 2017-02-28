#include "Administrador.h"

Administrador::Administrador()
{

}

Administrador::Administrador(string name, string password): Usuario(name)
{
  contrasena = password;
}

Administrador::~Administrador()
{

}

void Administrador::setContrasena(string password)
{
  contrasena = password;
}

string Administrador::getContrasena()
{
  return contrasena;
}


int main ()
{
  return 0;
}

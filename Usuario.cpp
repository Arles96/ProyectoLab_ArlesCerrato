#include "Usuario.h"

Usuario::Usuario()
{

}

Usuario::Usuario(string name)
{
  nombre = name;
}

Usuario::~Usuario()
{

}

void Usuario::setNombre(string n)
{
  nombre = n;
}

string Usuario::getNombre()
{
  return nombre;
}

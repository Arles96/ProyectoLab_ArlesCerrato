#include "Sony.h"

Sony::Sony()
{

}

Sony::Sony(int pAno,string pModelo, string pEstado, int pSerie, double pPrecio, string tipo)
:Consola(pAno,pModelo,pEstado,pSerie,pPrecio)
{
  this->tipo = tipo;
}

Sony::~Sony()
{

}

void Sony::setTipo(string tipo)
{
  this->tipo = tipo;
}

string Sony::getTipo()
{
  return tipo;
}

#include "Consola.h"

Nintendo::Nintendo()
{

}

Nintendo::Nintendo(int pAno,string pModelo, string pEstado, int pSerie, double pPrecio, string tipo)
:Consola(pAno,pModelo,pEstado,pSerie,pPrecio)
{
  this->tipo = tipo;
}

Nintendo::~Nintendo()
{

}

void Nintendo::setTipo(string tipo)
{
  this->tipo = tipo;
}

string Nintendo::getTipo()
{
  return tipo;
}

#include "Consola.h"

using namespace std;

Consola::Consola()
{

}

Consola::Consola(int ano, string modelo, string estado, int serie, double precio)
{
  this->ano = ano;
  this->modelo = modelo;
  this->estado = estado;
  this->serie = serie;
  this->precio = precio;
}

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

Consola::~Consola()
{

}

void Consola::setAno(int ano)
{
  this->ano = ano;
}

void Consola::setModelo(string modelo)
{
  this->modelo = modelo;
}

void Consola::setEstado(string estado)
{
  this->estado = estado;
}

void Consola::setSerie(int serie)
{
  this->serie = serie;
}

void Consola::setPrecio(double precio)
{
  this->precio = precio;
}

int Consola::getAno()
{
  return ano;
}

string Consola::getModelo()
{
  return modelo;
}

string Consola::getEstado()
{
  return estado;
}

int Consola::getSerie(){
  return serie;
}

double Consola::getPrecio()
{
  return precio;
}

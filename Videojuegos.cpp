#include "Videojuegos.h"

Videojuegos::Videojuegos()
{

}

Videojuegos::Videojuegos(string nombre, int ano, string consola, int numero_jugadores, string genero, string estado, int serie, double precio)
{
  this->nombre = nombre;
  this->ano = ano;
  this->consola = consola;
  this->numero_jugadores = numero_jugadores;
  this->genero = genero;
  this->estado = estado;
  this->serie = serie;
  this->precio = precio;
}

Videojuegos::~Videojuegos()
{
  
}

string Videojuegos::getNombre()
{
  return nombre;
}

int Videojuegos::getAno()
{
  return ano;
}

string Videojuegos::getConsola()
{
  return consola;
}

int Videojuegos::getNumero_jugadores()
{
  return numero_jugadores;
}

string Videojuegos::getGenero()
{
  return genero;
}

string Videojuegos::getEstado()
{
  return estado;
}

int Videojuegos::getSerie()
{
  return serie;
}

double Videojuegos::getPrecio()
{
  return precio;
}

void Videojuegos::setNombre(string nombre)
{
  this->nombre = nombre;
}

void Videojuegos::setAno(int ano)
{
  this->ano = ano;
}

void Videojuegos::setConsola(string consola)
{
  this->consola = consola;
}

void Videojuegos::setNumero_jugadores(int numero_jugadores)
{
  this->numero_jugadores = numero_jugadores;
}

void Videojuegos::setGenero(string genero)
{
  this->genero = genero;
}

void Videojuegos::setEstado(string estado)
{
  this->estado = estado;
}
void Videojuegos::setSerie(int serie)
{
  this->serie = serie;
}

void Videojuegos::setPrecio(double precio)
{
  this->precio = precio;
}

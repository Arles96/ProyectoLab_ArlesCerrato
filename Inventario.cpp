#include "Inventario.h"

Inventario::Inventario()
{

}

Inventario::~Inventario()
{
  //Eliminando memoria del vector de consolas
  for (int i=0; i<consolas.size(); i++){
    delete consolas[i];
  }
  consolas.clear();

  //Eliminando memoria del vector de Videojuegos
  for(int i = 0; i<videojuegos.size(); i++){
    delete videojuegos[i];
  }
  videojuegos.clear();
}

vector<Consola*> Inventario::getConsolas()
{
  return consolas;
}

vector<Videojuegos*> Inventario::getVideojuegos()
{
  return videojuegos;
}

void Inventario::setConsolas(vector<Consola*> consolas)
{
  this->consolas = consolas;
}

void Inventario::setVideojuegos(vector<Videojuegos*> videojuegos)
{
  this->videojuegos = videojuegos;
}

void Inventario::addConsola(Consola* consola)
{
  consolas.push_back(consola);
}

void Inventario::addVideojuego(Videojuegos* videojuego)
{
  videojuegos.push_back(videojuego);
}

int Inventario::sizeConsola()
{
  return consolas.size();
}

int Inventario::sizeVideojuego()
{
  return videojuegos.size();
}

Consola* Inventario::getConsola(int i)
{
  return consolas[i];
}

Videojuegos* Inventario::getVideojuego(int i)
{
  return videojuegos[i];
}

void Inventario::removeConsola(int i)
{
  consolas.erase(consolas.begin()+1);
}

void Inventario::removeVideojuego(int i)
{
  videojuegos.erase(videojuegos.begin()+1);
}

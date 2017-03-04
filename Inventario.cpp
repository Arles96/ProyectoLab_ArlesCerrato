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

#ifndef INVENTARIO_H_
#define INVENTARIO_H_

#include "Consola.h"
#include "Videojuegos.h"
#include <vector>
/*Clase de control del Inventario de la empresa de Videojuegos*/
using namespace std;

class Inventario
{
private:
  vector<Consola*> consolas;
  vector<Videojuegos*> videojuegos;

public:

  //Constructor
  Inventario();

  //Destructor
  ~Inventario();

  //getter
  vector<Consola*> getConsolas();
  vector<Videojuegos*> getVideojuegos();

  //setter
  void setConsolas(vector<Consola*>);
  void setVideojuegos(vector<Videojuegos*>);

  //agregar Consola y Videojuegos
  void addConsola(Consola*);
  void addVideojuego(Videojuegos*);

  //retorne los size de consola y videojuegos
  int sizeConsola();
  int sizeVideojuego();

  //retorne la consola y videojuego
  Consola* getConsola(int);
  Videojuegos* getVideojuego(int);

  //Eliminar un consola o videojuego en el vector correspondiente
  void removeConsola(int);
  void removeVideojuego(int);

};

#endif

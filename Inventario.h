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
  int contador_microsoft;
  int contador_sony;
  int contador_nintendo;

public:

  //Constructor
  Inventario();

  //Destructor
  ~Inventario();

  //getter
  vector<Consola*> getConsolas();
  vector<Videojuegos*> getVideojuegos();
  int getContador_microsoft();
  int getContador_sony();
  int getContador_nintendo();

  //setter
  void setConsolas(vector<Consola*>);
  void setVideojuegos(vector<Videojuegos*>);
  void setContador_microsoft(int);
  void setContador_sony(int);
  void setContador_nintendo(int);

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

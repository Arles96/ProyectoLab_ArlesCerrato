#ifndef INVENTARIO_H_
#define INVENTARIO_H_

#include "Consola.h"
#include "Videojuegos.h"
#include <vector>

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
};

#endif

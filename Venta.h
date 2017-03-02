#ifndef VENTA_H_
#define VENTA_H_

#include <vector>
#include <string>
#include "Vendedor.h"
#include "Consola.h"
#include "Videojuegos.h"

using namespace std;

class Venta
{
private:
  string nombre_cliente;
  vector<Consola*> consolas;
  vector<Videojuegos*> videojuegos;
  string hora_finalizacion;
  Vendedor* usuario;
  double subtotal;

public:
  
};

#endif

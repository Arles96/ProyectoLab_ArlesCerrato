#ifndef VENTA_H_
#define VENTA_H_
#pragma

#include <vector>
#include <string>
#include <sstream>
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

  //Constructores
  Venta();
  Venta(string,string,Vendedor*, double);
  Venta(string, string, Vendedor*);
  Venta(string, Vendedor*,double);
  Venta(string,Vendedor*);

  //Destructor
  ~Venta();

  //getter
  string getNombre_cliente();
  Consola* getConsola(int);
  int getConsolaSize();
  Videojuegos* getVideojuego(int);
  int getVideojuegoSize();
  string getHora_finalizacion();
  Vendedor* getUsuario();
  double getSubtotal();

  //Setter
  void setNombre_cliente(string);
  void setConsolas(vector<Consola*>);
  void addConsola(Consola*);
  void addVideojuego(Videojuegos*);
  void setVideojuegos(vector<Videojuegos*>);
  void setHora_finalizacion();
  void setSubtotal(double);

};

#endif

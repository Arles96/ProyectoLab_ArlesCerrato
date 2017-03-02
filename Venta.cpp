#include "Venta.h"

Venta::Venta()
{

}

Venta::Venta(string nombre_cliente, string hora_finalizacion, Vendedor* usuario, double subtotal)
{
  this->nombre_cliente = nombre_cliente;
  this->hora_finalizacion = hora_finalizacion;
  this->usuario = usuario;
  this->subtotal = subtotal;
}

Venta::Venta(string nombre_cliente, string hora_finalizacion, Vendedor* usuario)
{
  this->nombre_cliente = nombre_cliente;
  this->hora_finalizacion = hora_finalizacion;
  this->usuario = usuario;
}

Venta::Venta(string nombre_cliente, Vendedor* usuario, double subtotal)
{
  this->nombre_cliente = nombre_cliente;
  this->usuario = usuario;
  this->subtotal = subtotal;
}

Venta::Venta(string nombre_cliente, Vendedor* usuario)
{
  this->nombre_cliente = nombre_cliente;
  this->usuario = usuario;
}

string Venta::getNombre_cliente()
{
  return nombre_cliente;
}

Consola* Venta::getConsola(int i)
{
  return consolas[i];
}

int Venta::getConsolaSize()
{
  return consolas.size();
}

Videojuegos* Venta::getVideojuego(int i)
{
  return videojuegos[i];
}

int Venta::getVideojuegoSize()
{
  return videojuegos.size();
}

string Venta::getHora_finalizacion()
{
  return hora_finalizacion;
}

Vendedor* Venta::getUsuario()
{
  return usuario;
}

double Venta::getSubtotal()
{
  return subtotal;
}

void Venta::setNombre_cliente(string nombre_cliente)
{
  this->nombre_cliente = nombre_cliente;
}

void Venta::setConsolas(vector<Consola*> consolas)
{
  this->consolas = consolas;
}

void Venta::addConsola(Consola* consola)
{
  consolas.push_back(consola);
}

void Venta::addVideojuego(Videojuegos* videojuego)
{
  videojuegos.push_back(videojuego);
}

void Venta::setVideojuegos(vector<Videojuegos*> videojuegos)
{
  this->videojuegos = videojuegos;
}

void Venta::setHora_finalizacion()
{
  time_t now = time(0);

  //Puntero de time
  tm* time = localtime(&now);

  //variable donde se almacenara la hora
  stringstream stm;
  stm << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
  hora_finalizacion = stm.str();
}

void Venta::setSubtotal(double subtotal)
{
  this->subtotal = subtotal;
}

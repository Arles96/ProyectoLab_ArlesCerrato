#include "Vendedor.h"

using namespace std;

Vendedor::Vendedor()
{

}

Vendedor::Vendedor(string name) : Usuario(name){

}

Vendedor::~Vendedor()
{

}

//Funcion que obtendra la hora inicial del sistema
void Vendedor::setHora_inicial()
{
  //Variable para el control de la hora
  time_t now = time(0);

  //Puntero de time
  tm* time = localtime(&now);

  //variable donde se almacenara la hora
  stringstream stm;
  stm << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
  hora_inicio = stm.str();
}

//Funcion que obtendra la hora final del sistema
void Vendedor::setHora_final()
{
  //Variable para el control de la hora
  time_t now = time(0);

  //Puntero de time
  tm* time = localtime(&now);

  //variable donde se almacenara la hora
  stringstream stm;
  stm << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
  hora_final = stm.str();
}

string Vendedor::getHora_inicial(){
  return hora_inicio;
}

string Vendedor::getHora_final(){
  return hora_final;
}

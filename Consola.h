#ifndef CONSOLA_H_
#define CONSOLA_H_
#pragma

#include <string>

using namespace std;

class Consola
{
protected:
  int ano;
  string modelo;
  string estado;
  int serie;
  double precio;
public:

  //Constructores
  Consola();
  Consola(int, string, string, int, double);

  //Destructor
  ~Consola();

  //Setter
  void setAno(int);
  void setModelo(string);
  void setEstado(string);
  void setSerie(int);
  void setPrecio(double);

  //getter
  int getAno();
  string getModelo();
  string getEstado();
  int getSerie();
  double getPrecio();
};

#endif

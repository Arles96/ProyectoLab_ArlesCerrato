#ifndef VIDEOJUEGOS_H_
#define VIDEOJUEGOS_H_
#pragma

#include <string>

using namespace std;

class Videojuegos
{
protected:
  string nombre;
  int ano;
  string consola;
  int numero_jugadores;
  string genero;
  string estado;
  int serie;
  double precio;
public:

  //Constructores
  Videojuegos();
  Videojuegos(string, int, string, int, string,string,int,double);

  //Destructores
  ~Videojuegos();

  //getter
  string getNombre();
  int getAno();
  string getConsola();
  int getNumero_jugadores();
  string getGenero();
  string getEstado();
  int getSerie();
  double getPrecio();

  //Setter
  void setNombre(string);
  void setAno(int);
  void setConsola(string);
  void setNumero_jugadores(int);
  void setGenero(string);
  void setEstado(string);
  void setSerie(int);
  void setPrecio(double);

};

#endif

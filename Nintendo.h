#ifndef NINTENDO_H_
#define NINTENDO_H_

#include "Consola.h"
#include <string>

using namespace std;

class Nintendo : public Consola
{
private:
  string tipo;
public:

  //Constructores
  Nintendo();
  Nintendo(int,string,string,int,double,string);

  //Destructor
  ~Nintendo();

  //Setter
  void setTipo(string);

  //getter
  string getTipo();
};

#endif

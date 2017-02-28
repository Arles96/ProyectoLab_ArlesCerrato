#ifndef SONY_H_
#define SONY_H_

#include <string>
#include "Consola.h"

using namespace std;

class Sony : public Consola
{
private:
  string tipo;
public:

  //Constructores
  Sony();
  Sony(int,string,string,int,double,string);

  //Destructor
  ~Sony();

  //Setter
  void setTipo(string);

  //getter
  string getTipo();

};

#endif

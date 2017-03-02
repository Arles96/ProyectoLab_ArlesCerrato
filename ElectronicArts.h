#ifndef ELECTRONICARTS_H_
#define ELECTRONICARTS_H_

#include "Videojuegos.h"

class ElectronicArts : public Videojuegos
{
private:
  string electornic_arts = "Electronic Arts";

public:

  //Constructores
  ElectronicArts();
  ElectronicArts(string,int,Consola*,int,string,string,int,double);

  //getter
  string getElectronic_arts();
};

#endif

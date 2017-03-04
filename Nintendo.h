#ifndef NINTENDO_H_
#define NINTENDO_H_
#pragma

#include "Consola.h"
#include <string>

using namespace std;

class Nintendo : public Consola
{
public:

  //Constructores
  Nintendo();
  Nintendo(int,string,string,int,double);

  //Destructor
  ~Nintendo();
};

#endif

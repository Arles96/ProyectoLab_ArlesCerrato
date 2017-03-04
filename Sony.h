#ifndef SONY_H_
#define SONY_H_
#pragma

#include <string>
#include "Consola.h"

using namespace std;

class Sony : public Consola
{
public:

  //Constructores
  Sony();
  Sony(int,string,string,int,double);

  //Destructor
  ~Sony();

};

#endif

#ifndef JUEGONINTENDO_H_
#define JUEGONINTENDO_H_

class JuegoNintendo : public Videojuegos
{
private:
  string nintendo = "Nintendo";
public:

  //Constructores
  JuegoNintendo();
  JuegoNintendo(string,int,Consola*,int,string,string,int,double);

  //getter
  string getNintendo();

};

#endif

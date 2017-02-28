include "Microsoft.h"

using namespace std;

Microsoft::Microsoft()
{

}

Microsoft::Microsoft(int pAno, string pModelo, string pEstado, int pSerie, double pPrecio, string tipo)
  : Consola(pAno,pModelo,pEstado,pSerie,pPrecio)
{
      this->tipo = tipo;
}

Microsoft::~Microsoft()
{

}

void Microsoft::setTipo(string tipo)
{
  this->tipo = tipo;
}

string Microsoft::getTipo()
{
  return tipo;
}

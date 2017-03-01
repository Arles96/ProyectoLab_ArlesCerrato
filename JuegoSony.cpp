#include "JuegoSony.h"

JuegoSony::JuegoSony()
{

}

JuegoSony::JuegoSony(string pNombre, int pAno, Consola* pConsola, int pNumero_jugadores, string pGenero,
string pEstado, int pSerie, double pPrecio) : Videojuegos(pNombre,pAno,pConsola,pNumero_jugadores, pGenero, pEstado, pSerie, pPrecio)
{

}

string JuegoSony::getSony()
{
  return sony;
}

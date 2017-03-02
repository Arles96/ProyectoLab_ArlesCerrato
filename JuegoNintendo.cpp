#include "JuegoNintendo.h"

JuegoNintendo::JuegoNintendo()
{

}

JuegoNintendo::JuegoNintendo(string pNombre, int pAno, Consola* pConsola, int pNumero_jugadores, string pGenero,
string pEstado, int pSerie, double pPrecio) : Videojuegos(pNombre,pAno,pConsola,pNumero_jugadores, pGenero, pEstado, pSerie, pPrecio)
{

}

string JuegoNintendo::getNintendo()
{
  return nintendo;
}

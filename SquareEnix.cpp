#include "SquareEnix.h"

SquareEnix::SquareEnix()
{

}

SquareEnix::SquareEnix(string pNombre, int pAno, Consola* pConsola, int pNumero_jugadores, string pGenero,
string pEstado, int pSerie, double pPrecio) : Videojuegos(pNombre,pAno,pConsola,pNumero_jugadores, pGenero, pEstado, pSerie, pPrecio)
{

}

string SquareEnix::getSquare_enix()
{
  return square_enix;
}

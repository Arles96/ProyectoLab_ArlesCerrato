#include "ElectronicArts.h"

ElectronicArts::ElectronicArts()
{

}

ElectronicArts::ElectronicArts(string pNombre, int pAno, Consola* pConsola, int pNumero_jugadores, string pGenero,
string pEstado, int pSerie, double pPrecio) : Videojuegos(pNombre,pAno,pConsola,pNumero_jugadores, pGenero, pEstado, pSerie, pPrecio)
{

}

string ElectronicArts::getElectronic_arts()
{
  return electornic_arts;
}

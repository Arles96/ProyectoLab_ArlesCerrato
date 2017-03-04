#include <vector>
#include <iostream>
#include <fstream>
#include "Administrador.h"
#include "Bandai.h"
#include "Consola.h"
#include "ElectronicArts.h"
#include "JuegoMicrosoft.h"
#include "JuegoNintendo.h"
#include "JuegoSony.h"
#include "Konami.h"
#include "Microsoft.h"
#include "Nintendo.h"
#include "Sega.h"
#include "Sony.h"
#include "SquareEnix.h"
#include "Ubisoft.h"
#include "Usuario.h"
#include "Vendedor.h"
#include "Venta.h"
#include "Videojuegos.h"
#include "Inventario.h"

using namespace std;

//Seleccion de modelo de Microsoft
string modeloMicrosoft();

//Seleccion de modelo de Sony
string modeloSony();

//Seleccion de modelo Nintendo
string modeloNintendo();

//Funcion grafica que dice el inicio del programa

int main()
{
  //Leyendo la base de datos
  ifstream entrada;
  Inventario* inventario = new Inventario();
  entrada.read(reinterpret_cast<char*>(&inventario), sizeof (Inventario));
  entrada.close();
  //Respuesta de Usuario
  string respuesta = "s";
  while (respuesta=="s"){

  }

  return 0;
}

string modeloMicrosoft()
{
  string opcion;
  while (true){
    cout<< endl << "MENU DE MODELOS DE MICROSOFT" << endl << endl;
    cout<< "1.- xbox" << endl;
    cout<< "2.- xbox 360" << endl;
    cout<< "3.- xbox One" << endl;
    cout<< endl << "Ingrese una opcion: ";
    cin>>opcion;
    if(opcion=="1"){
      return "xbox";
    }else if (opcion=="2"){
      return "xbox 360";
    }else if (opcion=="3"){
      return "xbox One";
    }
  }
}

string modeloSony()
{
  string opcion;
  while (true){
    cout << endl << "MENU DE MODELOS DE SONY" << endl << endl;
    cout << "1.- Play Station 1" << endl;
    cout << "2.- Play Station 2" << endl;
    cout << "3.- Play Station 3" << endl;
    cout << "4.- Play Station 4" << endl;
    cout << "5.- PSP" << endl;
    cout << "6.- PS Vita" << endl;
    cout << endl << "Ingrese una opcion: ";
    cin>>opcion;
    if (opcion=="1"){
      return "Play Station 1";
    }else if (opcion=="2"){
      return "Play Station 2";
    }else if (opcion=="3"){
      return "Play Station 3";
    }else if (opcion=="4"){
      return "Play Station 4";
    }else if (opcion=="5"){
      return "PSP";
    }else if (opcion=="6"){
      return "PS Vita";
    }
  }
}

string modeloNintendo()
{
  string opcion;
  while (true){
    cout << endl << "MENU DE MODELOS DE NINTENDO" << endl << endl;
    cout << "1.- Nintendo Entertainment System" << endl;
    cout << "2.- Super Nintendo Entertainment System" << endl;
    cout << "3.- Nintendo 64" << endl;
    cout << "4.- Nintendo Gamecube" << endl;
    cout << "5.- Nintendo Wii" << endl;
    cout << "6.- Nintendo Wii U" << endl;
    cout << "7.- Nintendo Switch" << endl;
    cout << "8.- Gameboy" << endl;
    cout << "9.- Gameboy Colors" << endl;
    cout << "10.-Gameboy Advance" << endl;
    cout << "11.-Nintendo DS" << endl;
    cout << "12.-Nintendo DSi" << endl;
    cout << "13.-Nintendo 3DS" << endl;
    cout << "14.-Nintendo New 3DS" << endl;
    cout << endl << "Ingrese una opcion: ";
    cin>>opcion;
    if (opcion=="1"){
      return "Nintendo Entertainment System";
    }else if (opcion=="2"){
      return "Super Nintendo Entertainment System";
    }else if (opcion=="3"){
      return "Nintendo 64";
    }else if (opcion=="4"){
      return "Nintendo Gamecube";
    }else if (opcion=="5"){
      return "Nintendo Wii";
    }else if (opcion=="6"){
      return "Nintendo Wii U";
    }else if (opcion=="7"){
      return "Nintendo Switch";
    }else if (opcion=="8"){
      return "Gameboy";
    }else if (opcion=="9"){
      return "Gameboy Colors";
    }else if (opcion=="10"){
      return "Gameboy Advance";
    }else if (opcion=="11"){
      return "Nintendo DS";
    }else if (opcion=="12"){
      return "Nintendo DSi";
    }else if (opcion=="13"){
      return "Nintendo 3DS";
    }else if (opcion=="14"){
      return "Nintendo New 3DS";
    }
  }
}

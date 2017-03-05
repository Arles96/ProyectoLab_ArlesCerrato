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

//Funcion de consolas para los videojuegos
string consolaVideojuego();

//Funcion grafica que dice el inicio del programa
void inicioPrograma();

//Funciones de control de serie
int ingresoSerie();
int validacionSerie(Inventario*);

int main()
{
  //Leyendo la base de datos
  ifstream entrada;
  Inventario* inventario = new Inventario();
  entrada.read(reinterpret_cast<char*>(&inventario), sizeof (Inventario));
  entrada.close();

  //Cuenta del Administrador
  Administrador* administrador = new Administrador("Assassins", "dragon90");

  //Respuesta de Usuario
  string respuesta = "s";
  while (respuesta=="s"){
    inicioPrograma();
    string menu_principal;
    cout <<"MENU PRINCIPAL" << endl << endl;
    cout <<"1.- Cuenta administrador" << endl;
    cout <<"2.- Cuenta Vendedor" << endl << endl;
    cout <<"Igrese una opcion: ";
    cin>>menu_principal;
    cout << endl;//salto de linea para mayor orden

    //CUENTA ADMINISTRADOR
    if (menu_principal=="1"){
      bool autenticacion;
      string nombre, contrasena;
      cout << "CUENTA ADMINISTRADOR" << endl << endl;
      cin.ignore(256,'\n');
      cout << "Ingrese nombre: ";
      getline(cin,nombre);
      cin.ignore(256,'\n');
      cout << " Ingrese password: ";
      getline(cin,contrasena);
      cin.ignore(256,'\n');
      if (nombre==administrador->getNombre() && contrasena==administrador->getContrasena()){
        autenticacion = true;
      }else {
        autenticacion=false;
      }
      cout << endl;//salto de linea
      if (autenticacion==true){//si la autenticacion fue correcta
        string menu_administrador;
        cout << "MENU PRINCIPAL DE ADMINISTRADOR" << endl << endl;
        cout << "1.- Agregar" << endl;
        cout << "2.- Listar" << endl;
        cout << "3.- Modificar" << endl;
        cout << "4.- Eliminar" << endl;
        cout << "Presiona una letra u otro numero para cancelar" << endl << endl;
        cout << "Ingrese una opcion: " << endl;
        cin>>menu_administrador;
        cout << endl;//salto de linea
        if (menu_administrador=="1"){//Agregar
          string opcion_agregar;
          cout << "MENU DE AGREGAR" << endl << endl;
          cout << "1.- Consolas" << endl;
          cout << "2.- Videojuegos" << endl;
          cout << "presione una letra u otro numero para cancelar" << endl << endl;
          cout << "Ingrese una opcion: ";
          cin >> opcion_agregar;
          cout << endl; //salto de linea
          if (opcion_agregar=="1"){//Menu de consolas
            string opcion_consola;
            cout << "MENU DE CONSOLAS " << endl << endl;
            cout << "1.- Microsoft" << endl;
            cout << "2.- Sony" << endl;
            cout << "3.- Nintendo" << endl;
            cout << "Presione una letra u otro numero para cancelar" << endl << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion_consola;
            cout << endl; // salto de linea
            cin.ignore(256,'\n');
            int ano, serie;
            string modelo, estado;
            double precio;
            if(opcion_consola=="1"){//Opcion de Microsoft
              cout << "AGREGANDO CONSOLA DE MICROSOFT" << endl << endl;
              cout << "Ingrese el año de la consola: ";
              cin>>ano;
              modelo = modeloMicrosoft();
              cin.ignore(256,'\n');
              cout << "Ingrese el estado de la consola: ";
              getline(cin,estado);
              cout << "Ingrese el precio de la consola: ";
              cin>>precio;
              inventario->addConsola(new Microsoft(ano,modelo,estado,serie,precio));
              cout << "Se a agregado una consola al inventario" << endl;
            }else if (opcion_consola=="2"){//Opcion de Sony
              cout << "AGREGANDO CONSOLA DE SONY" << endl << endl;
              cout << "Ingrese el año de la consola: ";
              cin>>ano;
              modelo = modeloSony();
              cin.ignore(256,'\n');
              cout << "Ingrese el estado de la consola: ";
              getline(cin,estado);
              cout << "Ingrese el precio de la consola: ";
              cin>>precio;
              inventario->addConsola(new Sony(ano,modelo,estado,serie,precio));
              cout << "Se ha agregado una consola al inventario" << endl;
            }else if (opcion_consola=="3"){//Opcion de Nintendo
              cout << "AGREGANDO CONSOLAS DE NINTENDO" << endl << endl;
              cout << "Ingrese el año de la consola: ";
              cin>>ano;
              modelo = modeloSony();
              cin.ignore(256,'\n');
              cout << "Ingrese el estado de la consola: ";
              getline(cin,estado);
              cout << "Ingrese el precio de la consola: ";
              cin>>precio;
              inventario->addConsola(new Nintendo(ano,modelo,estado,serie,precio));
              cout << "Se ha agregado una consola al inventario" << endl;
            }else {
              cout << "Se ha cancelado" << endl;
            }
          }else if (opcion_agregar=="2"){//Opcion de videojuegos
            string opcion_videojuego;
            cout << "MENU DE VIDEOJUEGOS" << endl << endl;
            cout << "1.- Juegos Microsoft" << endl;
            cout << "2.- juegos Sony" << endl;
            cout << "3.- Juegos Nintendo" << endl;
            cout << "4.- Bandai" << endl;
            cout << "5.- Konami" << endl;
            cout << "6.- Square Enix" << endl;
            cout << "7.- Electronic Arts" << endl;
            cout << "8.- Sega" << endl;
            cout << "9.- Ubisoft" << endl;
            cout << "Presione una letra u otro numero para cancelar" << endl << endl;
            cout << "Ingrese una opcion: ";
            cin>>opcion_videojuego;
            cout << endl;//salto de linea
            string nombre, consola, genero, estado;
            int ano, numero_jugadores, serie;
            double precio;
            if (opcion_videojuego=="1"){//opcion videojuego de Microsoft
              cout << "AGREGANDO VIDEOJUEGO DE MICROSOFT" << endl << endl;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el año del juego: ";
              cin>>ano;

            }
          }
        }
      }
    }
    cout <<"Desea continuar: ";
    cin>>respuesta;
  }
  //ELiminando espacio en memoria
  delete inventario;
  delete administrador;
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

string consolaVideojuego()
{
  while (true){
     string opcion_consola;
     cout << endl << "MENU DE CONSOLAS PARA VIDEOJUEGO" << endl;
     cout << "1.- Microsoft" << endl;
     cout << "2.- Sony" << endl;
     cout << "3.- Nintendo" << endl << endl;
     cout << "Ingrese una opcion: ";
     cout << endl;//salto de linea
     cin>>opcion_consola;
     if (opcion_consola=="1"){//Opcion Microsoft
       string opcion_microsoft;
       cout << "MENU CONSOLAS MICROSOFT" << endl << endl;
       cout << "1.- xbox" << endl;
       cout << "2.- xbox 360" << endl;
       cout << "3.- xbox One" << endl << endl;
       cout << "Ingrese una opcion: ";
       cin>>opcion_microsoft;
       if (opcion_microsoft=="1"){
         return "xbox";
       }else if (opcion_microsoft=="2"){
         return "xbox 360";
       }else if (opcion_microsoft=="3"){
         return "xbox One";
       }else{
         cout << "Ocurrio un error";
       }
     }else if (opcion_consola=="2"){
       string opcion_sony;
       cout << "MENU DE CONSOLAS SONY" << endl << endl;
       cout << "1.- Play Station 1" << endl;
       cout << "2.- Play Station 2" << endl;
       cout << "3.- Play Station 3" << endl;
       cout << "4.- Play Station 4" << endl;
       cout << "5.- PSP" << endl;
       cout << "6.- PS Vita" << endl;
       cout << endl << "Ingrese una opcion: ";
       cin>>opcion_sony;
       if (opcion_sony=="1"){
         return "Play Station 1";
       }else if (opcion_sony=="2"){
         return "Play Station 2";
       }else if (opcion_sony=="3"){
         return "Play Station 3";
       }else if (opcion_sony=="4"){
         return "Play Station 4";
       }else if (opcion_sony=="5"){
         return "PSP";
       }else if (opcion_sony=="6"){
         return "PS Vita";
       }else {
         cout << "Ocurrio un error en la opcion" << endl;
       }
     }else if (opcion_consola=="3"){//Opcion Nintendo
       string opcion_nintendo;
       cout << "MENU DE CONSOLAS NINTENDO" << endl << endl;
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
       cin >>opcion_nintendo;
       if (opcion_nintendo=="1"){
         return "Nintendo Entertainment System";
       }else if (opcion_nintendo=="2"){
         return "Super Nintendo Entertainment System";
       }else if (opcion_nintendo=="3"){
         return "Nintendo 64";
       }else if (opcion_nintendo=="4"){
         return "Nintendo Gamecube";
       }else if (opcion_nintendo=="5"){
         return "Nintendo Wii";
       }else if (opcion_nintendo=="6"){
         return "Nintendo Wii U";
       }else if (opcion_nintendo=="7"){
         return "Nintendo Switch";
       }else if (opcion_nintendo=="8"){
         return "Gameboy";
       }else if (opcion_nintendo=="9"){
         return "Gameboy Colors";
       }else if (opcion_nintendo=="10"){
         return "Gameboy Advance";
       }else if (opcion_nintendo=="11"){
         return "Nintendo DS";
       }else if (opcion_nintendo=="12"){
         return "Nintendo DSi";
       }else if (opcion_nintendo=="13"){
         return "Nintendo 3DS";
       }else if (opcion_nintendo=="14"){
         return "Nintendo new 3DS";
       }else {
         cout << "Ocurrio un error" << endl;
       }
     }else {
       cout << "Ocurrio un error" << endl;
     }
  }
}

void inicioPrograma()
{
  cout <<"***************************************" << endl;
  cout <<"*********BIENVENIDO A GAMEHUB**********" << endl;
  cout <<"*************OBSERVACIONES*************" << endl;
  cout <<"*1. Para continuar presione la letra s*" << endl;
  cout <<"*2. Para salir presione cualquier letra" << endl;
  cout <<"***************************************" << endl;
  cout << endl;
}

int ingresoSerie()
{
  int serie;
  cout << "Ingrese el numero de serie de 4 digitos: ";
  cin>>serie;
  while (serie<1000 || serie>9999){
    cout << "Error en el numero de serie" << endl;
    cout << "Ingrese el numero de serie de 4 digitos: ";
    cin>>serie;
  }
  return serie;
}

int validacionSerie (Inventario* inventario)
{
  int serie;
  serie = ingresoSerie();
  //verificacion de los numeros de series de las consolas
  for (int i=0; i<inventario->sizeConsola();i++){
    if (serie == inventario->getConsola(i)->getSerie()){
      serie = ingresoSerie();
      i--;
    }
  }
  //verificacion de los numeros de series de los Videojuegos
  for (int i=0; i<inventario->sizeVideojuego(); i++){
    if (serie == inventario->getVideojuego(i)->getSerie()){
      serie = ingresoSerie();
      i--;
    }
  }
  return serie;
}

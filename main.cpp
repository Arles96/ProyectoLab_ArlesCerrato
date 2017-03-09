#include <vector>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <sstream>
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

//Funciones para imprimir en un archivo de texto
void imprimirVenta (Venta*, int);
void imprimirVendedor(vector<Venta*>);

int main()
{
  //Leyendo la base de datos
  ifstream entrada ("BaseDatos.dat", ios::in | ios::binary);
  Inventario* inventario = new Inventario();
  entrada.read(reinterpret_cast<char*>(&inventario), sizeof (Inventario));
  entrada.close();

  //Contadores de las consolas de microsoft, sony y Nintendo
  int contador_microsoft = inventario->getContador_microsoft();
  int contador_sony = inventario->getContador_sony();
  int contador_nintendo = inventario->getContador_nintendo();

  //Cuenta del Administrador
  Administrador* administrador = new Administrador("Assassins", "dragon90");

  //Respuesta de Usuario
  string respuesta = "s";
  inicioPrograma();
  while (respuesta=="s"){
    string menu_principal;
    cout <<"MENU PRINCIPAL" << endl << endl;
    cout <<"1.- Cuenta administrador" << endl;
    cout <<"2.- Cuenta Vendedor" << endl << endl;
    cout <<"Ingrese una opcion: ";
    cin>>menu_principal;
    cout << endl;//salto de linea para mayor orden
    if (menu_principal=="1"){//CUENTA ADMINISTRADOR
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
        string respuesta_administrador = "s";
        while (respuesta_administrador=="s"){//inicio de respuesta de administrador
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
              int ano, serie, cantidad;
              string modelo, estado;
              double precio;
              if(opcion_consola=="1"){//Opcion de Microsoft
                cout << "AGREGANDO CONSOLA DE MICROSOFT" << endl << endl;
                cout << "Ingrese la cantidad de consolas Microsoft: ";
                cin>>cantidad;
                while (cantidad<1){
                  cout << "Error en la cantidad" << endl;
                  cout << "Ingrese la cantidad de consolas Microsoft: ";
                  cin>>cantidad;
                }
                contador_microsoft += cantidad;
                cout << "Ingrese el año de la consola: ";
                cin>>ano;
                modelo = modeloMicrosoft();
                cin.ignore(256,'\n');
                cout << "Ingrese el estado de la consola: ";
                getline(cin,estado);
                cout << "Ingrese el precio de la consola: ";
                cin>>precio;
                for (int i=0; i<cantidad; i++){
                  serie = validacionSerie(inventario);
                  inventario->addConsola(new Microsoft(ano,modelo,estado,serie,precio));
                }
                cout << "Se ha agregado consolas microsoft al inventario" << endl;
              }//fin opcion de microsoft
              else if (opcion_consola=="2"){//Opcion de Sony
                cout << "AGREGANDO CONSOLA DE SONY" << endl << endl;
                cout << "Ingrese la cantidad de consola Sony: ";
                cin>>cantidad;
                while (cantidad<1){
                  cout << "Error en la cantidad" << endl;
                  cout << "Ingrese la cantidad de consolas de Sony: ";
                  cin>>cantidad;
                }
                contador_sony += cantidad;
                cout << "Ingrese el año de la consola: ";
                cin>>ano;
                modelo = modeloSony();
                cin.ignore(256,'\n');
                cout << "Ingrese el estado de la consola: ";
                getline(cin,estado);
                cout << "Ingrese el precio de la consola: ";
                cin>>precio;
                for (int i=0; i<cantidad; i++){
                  serie = validacionSerie(inventario);
                  inventario->addConsola(new Sony(ano,modelo,estado,serie,precio));
                }
                cout << "Se ha agregado consolas de sony al inventario" << endl;
              }//fin de la opcion de sony
              else if (opcion_consola=="3"){//Opcion de Nintendo
                cout << "AGREGANDO CONSOLAS DE NINTENDO" << endl << endl;
                cout << "Ingrese la cantidad de consolas nintendo: ";
                cin>>cantidad;
                while (cantidad<1){
                  cout << "Error en la cantidad" << endl;
                  cout << "Ingrese la cantidad de consolas nintendo: ";
                  cin >> cantidad;
                }
                contador_nintendo += cantidad;
                cout << "Ingrese el año de la consola: ";
                cin>>ano;
                modelo = modeloSony();
                cin.ignore(256,'\n');
                cout << "Ingrese el estado de la consola: ";
                getline(cin,estado);
                cout << "Ingrese el precio de la consola: ";
                cin>>precio;
                for (int i=0; i<cantidad; i++){
                  serie = validacionSerie(inventario);
                  inventario->addConsola(new Nintendo(ano,modelo,estado,serie,precio));
                }
                cout << "Se ha agregado consolas nintendo al inventario" << endl;
              }// fin de la opcion de nintendo
              else {//Parte de cancelado de opciones de consolas
                cout << "Se ha cancelado" << endl;
              }
            }//fin de la opcion de la opcion de agregar consolas
            else if (opcion_agregar=="2"){//Opcion de videojuegos
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
              if (opcion_videojuego=="1"){//opcion de videojuego de microsoft
                cout << "AGREGANDO VIDEOJUEGO DE MICROSOFT" << endl << endl;
                cin.ignore(256,'\n');
                cout << "Ingrese el nombre del juego: ";
                getline(cin,nombre);
                cin.ignore(256,'\n');
                cout << "Ingrese el estado del juego: ";
                getline(cin,estado);
                consola = consolaVideojuego();
                cin.ignore(256,'\n');
                cout << "Ingrese el genero del juego: ";
                getline(cin,genero);
                cout << "Ingrese el año del juego: ";
                cin>>ano;
                cout << "Ingrese el numero de jugadores: ";
                cin>>numero_jugadores;
                cout << "Ingrese el precio del juego: ";
                cin>>precio;
                serie = validacionSerie(inventario);
                inventario->addVideojuego(new JuegoMicrosoft(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
                cout << "Se ha agregado un juego de microsoft al inventario" << endl;
              }//fin de la opcion de microsoft
              else if (opcion_videojuego=="2"){//opcion de videojuego de sony
                cout << "AGREGANDO VIDEOJUEGOS DE SONY" << endl << endl;
                cin.ignore(256,'\n');
                cout << "Ingrese el nombre del juego: ";
                getline(cin,nombre);
                cin.ignore(256,'\n');
                cout << "Ingrese el estado del juego: ";
                getline(cin,estado);
                consola = consolaVideojuego();
                cin.ignore(256,'\n');
                cout << "Ingrese el genero del juego: ";
                getline(cin,genero);
                cout << "Ingrese el año del juego: ";
                cin>>ano;
                cout << "Ingrese el numero de jugadores: ";
                cin>>numero_jugadores;
                cout << "Ingrese el precio del juego: ";
                cin>>precio;
                serie = validacionSerie(inventario);
                inventario->addVideojuego(new JuegoSony(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
                cout << "Se ha agregado un juego de sony al inventario" << endl;
              }//fin de la opcion de videojuego de sony
              else if (opcion_videojuego=="3"){//opcion de videojuego de nintendo
                cout << "AGREGANDO VIDEOJUEGOS DE NINTENDO" << endl << endl;
                cin.ignore(256,'\n');
                cout << "Ingrese el nombre del juego: ";
                getline(cin,nombre);
                cin.ignore(256,'\n');
                cout << "Ingrese el estado del juego: ";
                getline(cin,estado);
                consola = consolaVideojuego();
                cin.ignore(256,'\n');
                cout << "Ingrese el genero del juego: ";
                getline(cin,genero);
                cout << "Ingrese el año del juego: ";
                cin>>ano;
                cout << "Ingrese el numero de jugadores: ";
                cin>>numero_jugadores;
                cout << "Ingrese el precio del juego: ";
                cin>>precio;
                serie = validacionSerie(inventario);
                inventario->addVideojuego(new JuegoNintendo(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
                cout << "Se ha agregado un juego de nintedo al inventario" << endl;
              }//fin de la opcion de videojuego de nintendo
              else if (opcion_videojuego=="4"){//opcion de videojuego de bandai
                cout << "AGREGANDO VIDEOJUEGOS DE BANDAI" << endl << endl;
                cin.ignore(256,'\n');
                cout << "Ingrese el nombre del juego: ";
                getline(cin,nombre);
                cin.ignore(256,'\n');
                cout << "Ingrese el estado del juego: ";
                getline(cin,estado);
                consola = consolaVideojuego();
                cin.ignore(256,'\n');
                cout << "Ingrese el genero del juego: ";
                getline(cin,genero);
                cout << "Ingrese el año del juego: ";
                cin>>ano;
                cout << "Ingrese el numero de jugadores: ";
                cin>>numero_jugadores;
                cout << "Ingrese el precio del juego: ";
                cin>>precio;
                serie = validacionSerie(inventario);
                inventario->addVideojuego(new Bandai(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
                cout << "Se ha agregado un juego de konami al inventario" << endl;
              }//fin de la opcion de videojueg de bandai
              else if (opcion_videojuego=="5"){//opcion de videojuegos de konami
                cout << "AGREGANDO VIDEOJUEGOS DE KONAMI" << endl << endl;
                cin.ignore(256,'\n');
                cout << "Ingrese el nombre del juego: ";
                getline(cin,nombre);
                cin.ignore(256,'\n');
                cout << "Ingrese el estado del juego: ";
                getline(cin,estado);
                consola = consolaVideojuego();
                cin.ignore(256,'\n');
                cout << "Ingrese el genero del juego: ";
                getline(cin,genero);
                cout << "Ingrese el año del juego: ";
                cin>>ano;
                cout << "Ingrese el numero de jugadores: ";
                cin>>numero_jugadores;
                cout << "Ingrese el precio del juego: ";
                cin>>precio;
                serie = validacionSerie(inventario);
                inventario->addVideojuego(new Konami(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
                cout << "Se ha agregado un juego de konami al inventario" << endl;
              }//fin de la opcion de videojuego de konami
              else if (opcion_videojuego=="6"){//opcion de videojuego de square enix
                cout << "AGREGANDO VIDEOJUEGOS DE SQUARE ENIX" << endl << endl;
                cin.ignore(256,'\n');
                cout << "Ingrese el nombre del juego: ";
                getline(cin,nombre);
                cin.ignore(256,'\n');
                cout << "Ingrese el estado del juego: ";
                getline(cin,estado);
                consola = consolaVideojuego();
                cin.ignore(256,'\n');
                cout << "Ingrese el genero del juego: ";
                getline(cin,genero);
                cout << "Ingrese el año del juego: ";
                cin>>ano;
                cout << "Ingrese el numero de jugadores: ";
                cin>>numero_jugadores;
                cout << "Ingrese el precio del juego: ";
                cin>>precio;
                serie = validacionSerie(inventario);
                inventario->addVideojuego(new SquareEnix(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
                cout << "Se ha agregado un juego de square enix al inventario" << endl;
              }//fin de la opcion de videojuego de square enix
              else if (opcion_videojuego=="7"){//opcion de videojuego de electronic arts
                cout << "AGREGANDO VIDEOJUEGOS DE ELECTRONIC ARTS" << endl << endl;
                cin.ignore(256,'\n');
                cout << "Ingrese el nombre del juego: ";
                getline(cin,nombre);
                cin.ignore(256,'\n');
                cout << "Ingrese el estado del juego: ";
                getline(cin,estado);
                consola = consolaVideojuego();
                cin.ignore(256,'\n');
                cout << "Ingrese el genero del juego: ";
                getline(cin,genero);
                cout << "Ingrese el año del juego: ";
                cin>>ano;
                cout << "Ingrese el numero de jugadores: ";
                cin>>numero_jugadores;
                cout << "Ingrese el precio del juego: ";
                cin>>precio;
                serie = validacionSerie(inventario);
                inventario->addVideojuego(new ElectronicArts(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
                cout << "Se ha agregado un juego de electronic arts al inventario" << endl;
              }//fin de la opcion de videojuego de electronic arts
              else if (opcion_videojuego=="8"){//opcion de videojuego de sega
                cout << "AGREGANDO VIDEOJUEGOS DE SEGA" << endl << endl;
                cin.ignore(256,'\n');
                cout << "Ingrese el nombre del juego: ";
                getline(cin,nombre);
                cin.ignore(256,'\n');
                cout << "Ingrese el estado del juego: ";
                getline(cin,estado);
                consola = consolaVideojuego();
                cin.ignore(256,'\n');
                cout << "Ingrese el genero del juego: ";
                getline(cin,genero);
                cout << "Ingrese el año del juego: ";
                cin>>ano;
                cout << "Ingrese el numero de jugadores: ";
                cin>>numero_jugadores;
                cout << "Ingrese el precio del juego: ";
                cin>>precio;
                serie = validacionSerie(inventario);
                inventario->addVideojuego(new Sega(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
                cout << "Se ha agregado un juego de sega al inventario" << endl;
              }//fin de la opcion de videojuego de sega
              else if (opcion_videojuego=="9"){//opcion de videojuego de Ubisoft
                cout << "AGREGANDO VIDEOJUEGOS DE UBISOFT" << endl << endl;
                cin.ignore(256,'\n');
                cout << "Ingrese el nombre del juego: ";
                getline(cin,nombre);
                cin.ignore(256,'\n');
                cout << "Ingrese el estado del juego: ";
                getline(cin,estado);
                consola = consolaVideojuego();
                cin.ignore(256,'\n');
                cout << "Ingrese el genero del juego: ";
                getline(cin,genero);
                cout << "Ingrese el año del juego: ";
                cin>>ano;
                cout << "Ingrese el numero de jugadores: ";
                cin>>numero_jugadores;
                cout << "Ingrese el precio del juego: ";
                cin>>precio;
                serie = validacionSerie(inventario);
                inventario->addVideojuego(new Ubisoft(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
                cout << "Se ha agregado un juego de ubisoft al inventario" << endl;
              }//fin de la opcion de videojuego de ubisoft
              else{
                cout << "Se ha cancelado" << endl;
              }
            }//fin de agregar videojuegos
            else {
              cout << "Se ha cancelado" << endl;
            }
          }//fin de agregar
          else if (menu_administrador=="2"){//opcion de Listar
            string opcion_listar;
            cout << "MENU DE LISTAR" << endl << endl;
            cout << "1.- Consolas" << endl;
            cout << "2.- videojuegos" << endl;
            cout << "3.- Presione una letra u otro numero para cancelar" << endl << endl;
            cout << "Ingrese una opcion: ";
            cin>> opcion_listar;
            cout << endl;//salto de linea
            if (opcion_listar=="1"){//opcion de listar Consolas
              cout << "LISTANDO CONSOLAS " << endl << endl;
              cout << "No.\t" << "Serie\t" << "Modelo\t" << "Estado\t" << "Año\t" << "Precio\t" << endl << endl;
              for (int i=0; i < inventario->sizeConsola(); i++){
                cout << i << "\t" << inventario->getConsola(i)->getSerie() << "\t" <<
                  inventario->getConsola(i)->getModelo() << "\t" << inventario->getConsola(i)->getEstado() << "\t" <<
                  inventario->getConsola(i)->getAno() << "\t" << inventario->getConsola(i)->getPrecio() << endl;
              }
              cout << endl;//salto de linea
            }//fin de la opcion de listar consola
            else if (opcion_listar=="2"){//opcion de listar videojuegos
              cout << "LISTANDO VIDEOJUEGOS" << endl << endl;
              for (int i=0; i < inventario->sizeVideojuego(); i++){
                cout << i << "\t" << inventario->getVideojuego(i)->getSerie() << "\t" <<
                  inventario->getVideojuego(i)->getNombre() << "\t" << inventario->getVideojuego(i)->getEstado()
                  << "\t" << inventario->getVideojuego(i)->getGenero() << "\t" <<
                  inventario->getVideojuego(i)->getPrecio() << endl;
              }
              cout << endl;//salto de linea
            }//fin de la opcion de listar consola
            else {
              cout << "se ha cancelado" << endl;
            }
          }//fin de la opcion de Listar
          else if (menu_administrador=="3"){//opcion Modificar
            string opcion_modificar;
            cout << "MENU DE MODIFICAR " << endl << endl;
            cout << "1.- Consolas " << endl;
            cout << "2.- Videojuegos" << endl;
            cout << "Presiona una letra u otro numero para cancelar" << endl << endl;
            cout << "Ingrese una opcion: ";
            cin>>opcion_modificar;
            cout << endl; //salto de linea
            int posicion;
            if (opcion_modificar=="1"){//Opcion modificar de consola
              cout << "MODIFICANDO CONSOLA" << endl << endl ;
              cout << "Ingrese la posiciona modificar: ";
              cin>>posicion;
              while (posicion<0 || posicion>inventario->sizeConsola()-1){
                cout << "Error en la posicion" << endl ;
                cout << "Ingrese una posicion a modificar: ";
                cin>>posicion;
              }
              cout << endl;//salto de linea
              int ano, serie;
              string modelo, estado;
              double precio;
              cout << "Ingrese el año de la consola: ";
              cin>>ano;
              cin.ignore(256,'\n');
              cout << "Ingrese el estado de la consola: ";
              getline(cin,estado);
              modelo = consolaVideojuego();//TODO: diferenciar que tipo de consola es
              cout << "Ingrese el precio de la consola: ";
              cin>>precio;
              serie = validacionSerie(inventario);
              inventario->getConsola(posicion)->setAno(ano);
              inventario->getConsola(posicion)->setEstado(estado);
              inventario->getConsola(posicion)->setModelo(modelo);
              inventario->getConsola(posicion)->setPrecio(precio);
              inventario->getConsola(posicion)->setSerie(serie);
              cout << "Se ha modificado la consola" << endl;
            }//fin de la opcion modificar de la consola
            else if (opcion_modificar=="2"){//opcion de modificar un videojuego
              cout << "MODIFICANDO VIDEOJUEGO" << endl << endl;
              cout << "Ingrese la posicion a modificar: ";
              cin>>posicion;
              while (posicion<0 || posicion>inventario->sizeVideojuego()-1){
                cout << "Error en la posicion" << endl;
                cout << "Ingrese una posicion: ";
                cin>>posicion;
              }
              cout << endl;//saldo de linea
              string nombre, consola, estado, genero;
              int ano, serie, numero_jugadores;
              double precio;
              cout << "Ingrese el año del juego: ";
              cin>>ano;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el estado del videojuego: ";
              getline(cin,estado);
              cin.ignore(256,'\n');
              cout << "Ingrese el genero del juego: ";
              getline(cin,genero);
              cin.ignore(256,'\n');
              consola = consolaVideojuego();
              cout << "Ingrese el numero de jugadores del juego: ";
              cin>>numero_jugadores;
              serie = validacionSerie(inventario);
              inventario->getVideojuego(posicion)->setAno(ano);
              inventario->getVideojuego(posicion)->setNombre(nombre);
              inventario->getVideojuego(posicion)->setEstado(estado);
              inventario->getVideojuego(posicion)->setGenero(genero);
              inventario->getVideojuego(posicion)->setNumero_jugadores(numero_jugadores);
              inventario->getVideojuego(posicion)->setSerie(serie);
              cout << "Se ha modificado el videojuego" << endl;
            }//fin de la opcion de modificar videojuego
            else {
              cout << "Se ha cancelado" << endl;
            }
          }//fin de la opcion de Modificar
          else if (menu_administrador=="4"){//Opcion de eliminar
            string opcion_eliminar;
            cout << "MENU DE ELIMINAR " << endl << endl;
            cout << "1.- Consola" << endl;
            cout << "2.- videojuego" << endl;
            cout << "Presione una letra u otro numero para salir" << endl << endl;
            cout << "Ingrese una opcion: ";
            cin>>opcion_eliminar;
            cout << endl;//salto de linea
            int posicion;
            if (opcion_eliminar=="1"){//Opcion de eliminar de Consola
              cout << "ELIMINANDO CONSOLA" << endl << endl;//TODO: diferenciar que tipo de consola es?
              cout << "Ingrese una posicion para eliminar consola: ";
              cin>>posicion;
              cout << endl;//salto de linea
              inventario->removeConsola(posicion);
              cout << "Se ha eliminado una consola" << endl;
            }//fin de la opcion de eliminar consola
            else if (opcion_eliminar=="2"){//opcion de eliminar de videojuego
              cout << "ELIMINANDO VIDEOJUEGO" << endl << endl;
              cout << "Ingrese una posicion para eliminar videojuego: ";
              cin>>posicion;
              while (posicion<0 || posicion>inventario->sizeVideojuego()-1){
                cout << "Error en la posicion" << endl;
                cout << "Ingrese una posicion: ";
                cin>>posicion;
              }
              cout << endl;// salto de linea
              inventario->removeVideojuego(posicion);
              cout << "Se ha eliminado un videojuego";
            }//fin de la opcion de eliminar videojuego
          }// fin de la opcion de eliminar
          else {
            cout << "Ha cancelado " << endl;
            break;
          }
          cout << endl;//salto de linea
          cout << "Desea continuar en la cuenta administrador: ";
          cin>>respuesta_administrador;
          cout << endl;//salto de linea
        }//fin de la respuesta del administrador
      }//fin de la autenticacion correcta
      else {//cuando la autenticacion es falsa
        cout << "Usuario y contraseña incorrecta" << endl;
      }//fin de la autenticacion falsa
    }//fin de cuenta principal de administrador
    else if (menu_principal=="2"){//Menu principal de Usuario de Vendedor
      string nombre;
      cout << "MENU DE VENDEDOR " << endl << endl;
      cin.ignore(256,'\n');
      cout << "Ingrese el nombre: ";
      getline(cin,nombre);
      Vendedor* vendedor = new Vendedor(nombre);
      vendedor->setHora_inicial();
      string respuesta_vendedor="s";
      while (respuesta_vendedor=="s"){//respuesta de vendedor
        cout << "MENU PRINCIPAL DE VENDEDOR" << endl << endl;
        string opcion_vendedor;
        int contador_articulos = 0;
        double dinero = 0;
        vector <Venta*> ventas_vendedor;//lista de ventas que realiza el vendedor
        cout << "1.- Agregar al inventario" << endl;
        cout << "2.- Realizar Venta" << endl;
        cout << "Presione una letra u otro numero para cancelar" << endl << endl;
        cout << "Ingrese una opcion: ";
        cin>>opcion_vendedor;
        cout << endl;//salto de linea
        if (opcion_vendedor=="1") {//Opcion de agregar al inventario
          string opcion_agregar;
          cout << "MENU PRINCIPAL DE AGREGAR " << endl << endl;
          cout << "1.- Consola " << endl;
          cout << "2.- Videojuegos" << endl;
          cout << "Presione una letra u otro numero para cancelar" << endl << endl;
          cin>>opcion_agregar;
          cout << endl;//salto de linea
          if (opcion_agregar=="1") {//opcion de agregar consolas de vendedor
            string opcion_consola;
            cout << "MENU DE CONSOLAS " << endl << endl;
            cout << "1.- Microsoft" << endl;
            cout << "2.- Sony " << endl;
            cout << "3.- Nintendo " << endl ;
            cout << "Presione una letra u otro numero para cancelar" << endl << endl;
            cout << "Ingrese una opcion: ";
            cin>>opcion_consola;
            cout << endl;//salto de
            int ano,serie, cantidad;
            string estado,modelo;
            double precio;
            if (opcion_consola=="1") {//opcion de agregar Microsoft
              cout << "AGREGANDO CONSOLA MICROSOFT" << endl << endl;
              cout << "Ingrese la cantidad de consolas: ";
              cin>>cantidad;
              contador_microsoft += cantidad;
              cout << "Ingrese el año de las consolas o consola: ";
              cin>>ano;
              cin.ignore(256,'\n');
              cout << "Ingrese el estado de las consolas o consola: ";
              getline(cin,estado);
              modelo = modeloMicrosoft();
              cout << "Ingrese el precio de las consolas o consola: ";
              cin>>precio;
              for (int i=0; i<cantidad; i++){
                serie = validacionSerie(inventario);
                inventario->addConsola(new Microsoft(ano,modelo,estado,serie,precio));
              }
              cout << "Se han agregado las consolas al inventario" << endl;
            }// fin de la opcion de agregar Microsoft
            else if (opcion_consola=="2") {//Opcion agregar consola sony
              cout << "AGREGANDO CONSOLA SONY" << endl << endl;
              cout << "Ingrese la cantidad de consolas sony: ";
              cin>>cantidad;
              contador_sony += cantidad;
              cout << "Ingrese el año de las consolas o consola: ";
              cin>>ano;
              cin.ignore(256,'\n');
              cout << "Ingrese el estado de las consolas o consola: ";
              getline(cin,estado);
              modelo = modeloSony();
              cout << "Ingrese el precio de las consolas o consola: ";
              cin>>precio;
              for (int i=0; i< cantidad; i++){
                serie = validacionSerie(inventario);
                inventario->addConsola(new Sony(ano,modelo,estado,serie,precio));
              }
              cout << "Se han agregado las consolas sony al inventario" << endl;
            }// fin de la opcion agregar consola sony
            else if (opcion_consola=="3") {//opcion de agregar consola nintendo
              cout << "AGREGANDO CONSOLA NINTENDO" << endl << endl;
              cout << "Ingrese la cantidad de consolas nintendo: ";
              cin>>cantidad;
              contador_nintendo += cantidad;
              cout << "Ingrese el año de las consolas o consola: ";
              cin>>ano;
              cin.ignore(256,'\n');
              cout << "Ingrese el estado de las consolas o consola: ";
              getline(cin,estado);
              modelo = modeloNintendo();
              cout << "Ingrese el precio  de las consolas o consola: ";
              cin>>precio;
              for (int i=0; i< cantidad; i++){
                serie = validacionSerie(inventario);
                inventario->addConsola(new Nintendo(ano,modelo,estado,serie,precio));
              }
              cout << "Se han agregado consolas nintendo al inventario" << endl;
            }// fin de la opcion de agregar consola nintendo
            else {
              cout << "Se ha cancelado" << endl;
            }
          }//fin de la opcion de agregar consolas
          else if (opcion_agregar=="2") {//opcion de agregar videojuegos
            string opcion_videojuego;
            cout << "MENU DE VIDEOJUEGOS" << endl << endl;
            cout << "1.- Juegos de microsoft" << endl;
            cout << "2.- Juego de sony" << endl;
            cout << "3.- Juego de Nintendo" << endl;
            cout << "4.- Bandai" << endl;
            cout << "5.- Konami" << endl;
            cout << "6.- Square Enix" << endl;
            cout << "7.- Electronic Arts" << endl;
            cout << "8.- Sega" << endl;
            cout << "9.- Ubisoft" << endl;
            cout << "Presione una letra u otro numero para cancelar" << endl << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion_videojuego;
            cout << endl; //salto de linea
            string nombre,estado, genero, consola;
            int ano,numero_jugadores,serie;
            double precio;
            if (opcion_videojuego=="1") {//Opcion de agregar juego de microsoft
              cout << "AGREGANDO JUEGO DE MICROSOFT" << endl << endl;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el estado del juego: ";
              getline(cin,estado);
              consola = consolaVideojuego();
              cin.ignore(256,'\n');
              cout << "Ingrese el genero del juego: ";
              getline(cin,genero);
              cout << "Ingrese el año del juego: ";
              cin>>ano;
              cout << "Ingrese el numero de jugadores: ";
              cin>>numero_jugadores;
              cout << "Ingrese el precio del juego: ";
              cin>>precio;
              serie = validacionSerie(inventario);
              inventario->addVideojuego(new JuegoMicrosoft(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
              cout << "Se ha agregado el juego de microsoft al inventario" << endl;
            }// fin de la opcion de juego microsoft
            else if (opcion_videojuego=="2") {//Opcion de agregar juego de sony
              cout << "AGREGANDO JUEGO DE SONY" << endl << endl;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el estado del juego: ";
              getline(cin,estado);
              cin.ignore(256,'\n');
              cout << "Ingrese el genero del juego: ";
              getline(cin,genero);
              cout << "Ingrese el año del juego: ";
              cin>>ano;
              cout << "Ingrese el numero de jugadores: ";
              cin>>numero_jugadores;
              cout << "Ingrese el precio del juego: ";
              cin>>precio;
              serie = validacionSerie(inventario);
              inventario->addVideojuego(new JuegoSony(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
              cout << "Se ha agregado el juego de sony " << endl;
            }//fin de la opcion de agregar juego de sony
            else if (opcion_videojuego=="3") {//opcion de agregar videojuegos de nintendo
              cout << "AGREGANDO JUEGO DE NINTENDO" << endl << endl;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el estado del juego: ";
              getline(cin,estado);
              cin.ignore(256,'\n');
              cout << "Ingrese el genero del juego: ";
              getline(cin,genero);
              cout << "Ingrese el año del juego: ";
              cin>>ano;
              cout << "Ingrese el numero de jugadores: ";
              cin>>numero_jugadores;
              cout << "Ingrese el precio del juego: ";
              cin>>precio;
              serie = validacionSerie(inventario);
              inventario->addVideojuego(new JuegoNintendo(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
              cout << "Se ha agregado un juego de nintendo" << endl;
            }//fin de la opcion de agregar videojuegos de nintendo
            else if (opcion_videojuego=="4"){//OPcion de agregar videojuego de bandai
              cout << "AGREGANDO VIDEOJUEGOS DE BANDAI" << endl << endl;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el estado del juego: ";
              getline(cin,estado);
              cin.ignore(256,'\n');
              cout << "Ingrese el genero del juego: ";
              getline(cin,genero);
              cout << "Ingrese el año del juego: ";
              cin>>ano;
              cout << "Ingrese el numero de jugadores: ";
              cin>>numero_jugadores;
              cout << "Ingrese el precio del juego: ";
              cin>>precio;
              serie = validacionSerie(inventario);
              inventario->addVideojuego(new Bandai(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
              cout << "Se ha agregado un juego de Bandai" << endl;
            }//fin de la opcion de agregar videojuegos de Bandai
            else if (opcion_videojuego=="5") {//opcion de agregar videojuego de konami
              cout << "AGREGANDO VIDEOJUEGO DE KONAMI" << endl << endl;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el estado del juego: ";
              getline(cin,estado);
              cin.ignore(256,'\n');
              cout << "Ingrese el genero del juego: ";
              getline(cin,genero);
              cout << "Ingrese el año del juego: ";
              cin>>ano;
              cout << "Ingrese el numero de jugadores: ";
              cin>>numero_jugadores;
              cout << "Ingrese el precio del juego: ";
              cin>>precio;
              serie = validacionSerie(inventario);
              inventario->addVideojuego(new Konami(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
              cout << "Se ha agregado un juego de konami" << endl;
            }//fin de la opcion de agregar juego de konami
            else if (opcion_videojuego=="6") {//opcion de agregar videojuego de square enix
              cout << "AGREGANDO JUEGO DE SQUARE ENIX" << endl << endl;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el estado del juego: ";
              getline(cin,estado);
              cin.ignore(256,'\n');
              cout << "Ingrese el genero del juego: ";
              getline(cin,genero);
              cout << "Ingrese el año del juego: ";
              cin>>ano;
              cout << "Ingrese el numero de jugadores: ";
              cin>>numero_jugadores;
              cout << "Ingrese el precio del juego: ";
              cin>>precio;
              serie = validacionSerie(inventario);
              inventario->addVideojuego(new SquareEnix(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
              cout << "Se ha agregado un juego de square enix" << endl;
            }// fin de la opcion de agregar cideojuego de square enix
            else if (opcion_videojuego=="7") {//Opcion de agregar videojuego de electronic arts
              cout << "AGREGANDO EL VIDEOJUEGO DE ELECTRONIC ARTS" << endl << endl;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el estado del juego: ";
              getline(cin,estado);
              cin.ignore(256,'\n');
              cout << "Ingrese el genero del juego: ";
              getline(cin,genero);
              cout << "Ingrese el año del juego: ";
              cin>>ano;
              cout << "Ingrese el numero de jugadores: ";
              cin>>numero_jugadores;
              cout << "Ingrese el precio del juego: ";
              cin>>precio;
              serie = validacionSerie(inventario);
              inventario->addVideojuego(new ElectronicArts(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
              cout << "Se ha agregado un juego de electronic arts al inventario" << endl;
            }//fin de la opcion de agregar videojuegos de electronic arts
            else if (opcion_videojuego=="8") {//opcion de agregar videojuego de sega
              cout << "AGREGANDO JUEGO DE SEGA" << endl << endl;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el estado del juego: ";
              getline(cin,estado);
              cin.ignore(256,'\n');
              cout << "Ingrese el genero del juego: ";
              getline(cin,genero);
              cout << "Ingrese el año del juego: ";
              cin>>ano;
              cout << "Ingrese el numero de jugadores: ";
              cin>>numero_jugadores;
              cout << "Ingrese el precio del juego: ";
              cin>>precio;
              serie = validacionSerie(inventario);
              inventario->addVideojuego(new Sega(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
              cout << "Se ha agregado un juego de sega al inventario" << endl;
            }//fin de la opcion de agregar videojuego de sega
            else if (opcion_videojuego=="9") {//Opcion de agregar videojuego de Ubisoft
              cout << "AGREGANDO VIDEOJUEGO DE UBISOFT" << endl << endl;
              cin.ignore(256,'\n');
              cout << "Ingrese el nombre del juego: ";
              getline(cin,nombre);
              cin.ignore(256,'\n');
              cout << "Ingrese el estado del juego: ";
              getline(cin,estado);
              cin.ignore(256,'\n');
              cout << "Ingrese el genero del juego: ";
              getline(cin,genero);
              cout << "Ingrese el año del juego: ";
              cin>>ano;
              cout << "Ingrese el numero de jugadores: ";
              cin>>numero_jugadores;
              cout << "Ingrese el precio del juego: ";
              cin>>precio;
              serie = validacionSerie(inventario);
              inventario->addVideojuego(new Ubisoft(nombre,ano,consola,numero_jugadores,genero,estado,serie,precio));
              cout << "Se ha agregado una juego de ubisoft en el inventario" << endl;
            }//fin de la opcion de agregar videjuego de Ubisoft
            else {//opcion de agregar videjuego cancelado
              cout << "Se ha cancelado" << endl;
            }
          }//fin de la opcion de agregar videojuegos
          else {//opcion de agregar cancelado
            cout << "Se ha cancelado" << endl ;
          }
        }//fin de la opcion de agregar al inventario
        else if (opcion_vendedor=="2") {//opcion de realizar venta
          cout << "REALIZANDO VENTA " << endl << endl;
          string cliente;
          cin.ignore(256,'\n');
          cout << "Ingrese el nombre del cliente: ";
          getline(cin,cliente);
          Venta* venta = new Venta (cliente,vendedor);
          int contador_venta=0;
          double subtotal = 0;
          string respuesta_venta="s";
          while (respuesta_venta=="s"){//Respuesta de continuar venta
            string opcion_venta;
            cout << "MENU DE VENTAS " << endl << endl;
            cout << "1.- Agregar articulo a la venta" << endl;
            cout << "2.- Listar" << endl;
            cout << "Presione una letra u otro numero para cerrar" << endl << endl;
            cout << "Ingrese una opcion: ";
            if (opcion_venta=="1") {//opcion de agregar articulo a la venta
              cout << "AGREGANDO ARTICULO" << endl << endl;
              int serie;
              serie = ingresoSerie();
              Consola* c;//variable temporal de Consola
              Videojuegos* v;//variable temporal de Videojuego
              bool verificar_consola = false;
              bool verificar_juego = false;
              int posiciones_consolas;
              int posiciones_juegos;
              for (int i=0; i < inventario->sizeConsola(); i++){
                if (serie==inventario->getConsola(i)->getSerie()){
                  verificar_consola=true;
                  c = inventario->getConsola(i);
                  posiciones_consolas=i;
                  subtotal += inventario->getConsola(i)->getPrecio();
                  break;
                }
              }
              if (verificar_consola==true) {//inicio de la verificacion de consola
                if (typeid(*c)==typeid(Microsoft)){
                  contador_microsoft--;
                }else if (typeid(*c)==typeid(Sony)) {
                  contador_sony--;
                }else if (typeid(*c)==typeid(Nintendo)) {
                  contador_nintendo--;
                }
                contador_venta++;
                contador_articulos++;
                venta->addConsola(c);
                inventario->removeConsola(posiciones_consolas);
                cout << "Se ha agregado una consola " << typeid(*c).name() << endl;
              }//fin de la verificacion de consola
              else {//verificacion de videojuegos
                for (int i=0; i < inventario->sizeVideojuego(); i++){
                  if (serie==inventario->getVideojuego(i)->getSerie()){
                    verificar_juego==true;
                    v = inventario->getVideojuego(i);
                    posiciones_juegos = i;
                    subtotal += inventario->getVideojuego(i)->getPrecio();
                    break;
                  }
                }
                if (verificar_juego==true) {//inicio de verificacion de videjuego
                  venta->addVideojuego(v);
                  contador_venta++;
                  contador_articulos++;
                  inventario->removeVideojuego(posiciones_juegos);
                  cout << "Se ha agregado un videojuedo de la empresa de " << typeid(*v).name() << endl;
                }//fin  de la verificacion de videojuego
                else {
                  cout << "Error en el numero de serie" << endl;
                }
              }//fin de la verificacion de videojuegos
              delete c;//eliminando la referencia de memoria de variable temporal de consola
              delete v;//eliminando la referencia de memoria de variable temporal de videojuego
            }//fin de la opcion de agregar articulo a la venta
            else if (opcion_venta=="2") {//Listando articulos
              string opcion_listar;
              cout << "MENU DE LISTAR ARTICULOS" << endl << endl;
              cout << "1.- Consolas" << endl;
              cout << "2.- videojuegos" << endl;
              cout << "Presione una letra u otro numero para cancelar" << endl << endl;
              cout << "Ingrese una opcion: ";
              cin>>opcion_listar;
              if (opcion_listar=="1") {//opcion de listar Consolas
                cout << "LISTA DE CONSOLAS" << endl << endl;
                cout << "No.\t" << "Serie'\t" << "Modelo\t" << endl << endl;
                for (int i=0; i < inventario->sizeConsola(); i++){
                  cout << i << "\t" << inventario->getConsola(i)->getSerie() << "\t" <<
                    inventario->getConsola(i)->getModelo() << endl;
                }
                cout << endl;
              }//fin de la opcion de listar Consolas
              else if (opcion_listar=="2") {//opcion de listar videojuegos
                cout << "LISTANDO VIDEOJUEGOS" << endl << endl;
                cout << "No.\t" << "Serie\t" << "Nombre\t" << endl << endl;
                for (int i=0; i < inventario->sizeVideojuego(); i++){
                  cout << i << "\t" << inventario->getVideojuego(i)->getSerie() << "\t" <<
                    inventario->getVideojuego(i)->getNombre() << endl;
                }
                cout << endl;
              }//fin de la opcion de listar videojuegos
              else{//cancelacion de listar
                cout << "Se ha cancelado" << endl;
              }
            }//fin de la opcion de listar en la venta
            else {
              cout << "Se ha cerrado la venta" << endl;
              break;
            }
            cout << endl;//salto de linea
            cout << "Desea continuar en la venta: ";
            cin>>respuesta_vendedor;
          }//fin respuesta de la venta
          venta->setSubtotal(subtotal);
          venta->setHora_finalizacion();
          ventas_vendedor.push_back(venta);
          delete venta;
        }//fin de la opcion de realizar venta
        cout << endl;//salto de linea
        cout << "Desea continuar con usuario vendedor: ";
        cin>>respuesta_vendedor;
      }//fin de respuesta de vendedor
    }//fin de de menu principal del usuario vendedor
    cout <<"Desea continuar: ";
    cin>>respuesta;
    cout << endl; // salto de linea
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

void imprimirVenta(Venta* venta, int contador)
{
  ofstream  salida;
  stringstream stm;
  string fichero;
  stm << "./log_ventas/" << venta->getHora_finalizacion() << ".log";
  fichero = stm.str();
  salida.open(fichero.c_str());
  salida << "         GAMEHUB         " << endl;
  salida << venta->getHora_finalizacion() << endl;
  salida << "Vendedor: " << venta->getUsuario()->getNombre() << endl;
  salida << "Cliente: " << venta->getNombre_cliente() << endl;
  salida << "Cantidad de articulos " << contador  << end;
  for (int i=0; i < venta->getConsolaSize(); i++){
    salida << venta->getConsola(i)->getModelo() << "    L." << venta->getConsola(i)->getPrecio() << endl;
  }
  for (int i=0; i < venta->getVideojuegoSize(); i++){
    salida << venta->getVideojuego(i)->getNombre() << "     L." << venta->getVideojuego(i)->getPrecio() << endl;
  }
  salida << "Subtotal: " << venta->getSubtotal() << endl;
  double impuesto = venta->getSubtotal()*0.15;
  salida << "Impuesto: " << impuesto << endl;
  double total = venta->getSubtotal() + impuesto;
  salida << "Total: " << total << endl;
}

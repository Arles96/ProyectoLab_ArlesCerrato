main:

main.o:	Administrador.h Consola.h Usuario.h Vendedor.h Venta.h main.cpp
	g++ -c main.cpp

Administrador.o:	Usuario.h Administrador.h Administrador.cpp
	g++ -c Administrador.cpp

Consola.o:	Consola.h Consola.cpp
	g++ -c Consola.cpp

Usuario.o:	Usuario.h Usuario.cpp
	g++ -c Usuario.cpp

Vendedor.o:	Usuario.h Vendedor.h Vendedor.cpp
	g++ -c Vendedor.cpp

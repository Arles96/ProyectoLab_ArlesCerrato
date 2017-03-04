Empresa:	Consola.o Usuario.o Videojuegos.o Administrador.o Bandai.o ElectronicArts.o JuegoMicrosoft.o JuegoNintendo.o JuegoSony.o Konami.o Microsoft.o Nintendo.o Sega.o Sony.o SquareEnix.o Ubisoft.o Vendedor.o Venta.o main.o Inventario.o
	g++ Consola.o Usuario.o Videojuegos.o Administrador.o Bandai.o ElectronicArts.o JuegoMicrosoft.o JuegoNintendo.o JuegoSony.o Konami.o Microsoft.o Nintendo.o Sega.o Sony.o SquareEnix.o Ubisoft.o Vendedor.o Venta.o main.o Inventario.o -o Empresa

main.o:	main.cpp Administrador.h Bandai.h Consola.h ElectronicArts.h JuegoMicrosoft.h JuegoNintendo.h JuegoSony.h Konami.h Microsoft.h Nintendo.h Sega.h Sony.h SquareEnix.h Ubisoft.h Usuario.h Vendedor.h Venta.h Videojuegos.h
	g++ -c main.cpp

Consola.o:	Consola.cpp Consola.h
	g++ -c Consola.cpp

Usuario.o:	Usuario.cpp Usuario.h
	g++ -c Usuario.cpp

Videojuegos.o:	Videojuegos.cpp Videojuegos.h
	g++ -c Videojuegos.cpp

Administrador.o:	Administrador.cpp Administrador.h Usuario.h
	g++ -c Administrador.cpp

Bandai.o:	Bandai.cpp Bandai.h Videojuegos.h
	g++ -c Bandai.cpp

ElectronicArts.o:	ElectronicArts.cpp ElectronicArts.h Videojuegos.h
	g++ -c ElectronicArts.cpp

JuegoMicrosoft.o:	JuegoMicrosoft.cpp JuegoMicrosoft.h Videojuegos.h
	g++ -c JuegoMicrosoft.cpp

JuegoNintendo.o: JuegoNintendo.cpp JuegoNintendo.h Videojuegos.h
	g++ -c JuegoNintendo.cpp

JuegoSony.o: JuegoSony.cpp JuegoSony.h Videojuegos.h
	g++ -c JuegoSony.cpp

Konami.o: Konami.cpp Konami.h Videojuegos.h
	g++ -c Konami.cpp

Microsoft.o:	Microsoft.cpp Microsoft.h Consola.h
	g++ -c Microsoft.cpp

Nintendo.o: Nintendo.cpp Nintendo.h Consola.h
	g++ -c Nintendo.cpp

Sega.o:	Sega.cpp Sega.h Videojuegos.h
	g++ -c Sega.cpp

Sony.o:	Sony.cpp Sony.h Consola.h
	g++ -c Sony.cpp

SquareEnix.o:	SquareEnix.cpp SquareEnix.h Videojuegos.h
	g++ -c SquareEnix.cpp

Ubisoft.o: Ubisoft.cpp Ubisoft.h Videojuegos.h
	g++ -c Ubisoft.cpp

Vendedor.o: Vendedor.cpp Vendedor.h Usuario.h
	g++ -c Vendedor.cpp

Venta.o: Venta.cpp Venta.h Vendedor.h Consola.h Videojuegos.h
	g++ -c Venta.cpp

Inventario.o: Consola.h Videojuegos.h Inventario.h Inventario.cpp
	g++ -c Inventario.cpp

Clean:
	rm *.o Empresa

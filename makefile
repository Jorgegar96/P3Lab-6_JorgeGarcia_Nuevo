temp:	main.o Jugador.o Item.o Obstaculo.o Bomba.o V.o Normal.o Espina.o Escenario.o Invisible.o
		g++ main.o Jugador.o Item.o Obstaculo.o Bomba.o V.o Normal.o Espina.o Escenario.o Invisible.o -o temp
main.o:	main.cpp 
		g++ -c main.cpp Jugador.h Item.h Obstaculo.h Bomba.h Normal.h Espina.h Escenario.h Invisible.h
Jugador.o:	Jugador.cpp Jugador.h Item.h
		g++ -c Jugador.cpp 
Item.o:	Item.cpp Item.h
		g++ -c Item.cpp
Obstaculo.o:	Obstaculo.cpp Obstaculo.h Item.h
		g++ -c Obstaculo.cpp
Bomba.o:	Bomba.cpp Bomba.h Item.h
		g++ -c Bomba.cpp
V.o:	V.cpp V.h Bomba.h Jugador.h Obstaculo.h
		g++ -c V.cpp
Normal.o:	Normal.cpp Normal.h Bomba.h Jugador.h Obstaculo.h
		g++ -c Normal.cpp
Espina.o:	Espina.cpp Espina.h Bomba.h Jugador.h Obstaculo.h
		g++ -c Espina.cpp
Escenario.o:	Escenario.cpp Escenario.h Item.h Jugador.h Obstaculo.h Bomba.h
		g++ -c Escenario.cpp
Invisible.o:	Invisible.cpp Invisible.h Jugador.h Item.h Obstaculo.h Bomba.h
		g++ -c Invisible.cpp

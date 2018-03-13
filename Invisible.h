#include "Escenario.h"
#include "Jugador.h"
#include "Item.h"
#include "Obstaculo.h"
#include "Bomba.h"
#include <vector>
#include <iostream>
#include <string>

#ifndef INVISIBLE_H
#define INVISIBLE_H

class Invisible: public Escenario{
	private:
		Jugador* jugador;
		Jugador** BOTS;

	public:
		Invisible(string);
		void llenarMapa();
		void imprimirMapa();

};

#endif

#include <string>
#include "Item.h"
#ifndef JUGADOR_H
#define	JUGADOR_H

using namespace std;

class Jugador: public Item{

	private: 
		string name;
		bool vivo;
		string tipo;
		int vidas;
		bool movido;

	public:
		Jugador(int, int, char);
		Jugador(string, int, int, char);
		string getName();
		bool isVivo();
		void setMuerte();
		string getTipo();
		void perderVida();
		int getVidas();
		bool moved();
		void cambioEstado();
		~Jugador();
};

#endif

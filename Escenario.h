#include <string>
#include <vector>
#include "Item.h"
#ifndef ESCENARIO_H
#define ESCENARIO_H
using namespace std;

class Escenario{
	private:
		string name;
		vector<Item*> bombas;
		int random;
		int cont_bomb;

	public:
		Escenario(string);
		virtual string getName();
		Item*** getMapa();
		vector<Item*> getBombas();
		void reducirConteo();
		void explosion(Item*);
		void addBomb(Item*);
		void moverBots(char, bool, int);
		bool movVal(int, int, int, int);
		Item*** map;
		void resetEstado();
		bool jugadorPrincipal();
};

#endif

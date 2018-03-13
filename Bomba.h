#ifndef BOMBA_H
#define BOMBA_H
#include "Item.h"
class Bomba: public Item{

	private: 
		int turno_explotar;
		bool exploded;
		bool puesta;

	public:
		Bomba(int, int, char);
		virtual int getTurno();
		void reduceTurno();
		bool getEstado();
		void Explotar();
		bool getPuesta();
		void poner();
		~Bomba();
};

#endif

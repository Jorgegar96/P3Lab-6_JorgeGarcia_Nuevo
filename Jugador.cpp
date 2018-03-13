#include <string>
#include "Jugador.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

Jugador:: Jugador(int coord_x, int coord_y, char letra): Item(coord_x, coord_y, letra){
	tipo = "BOT";
	vivo = true;
	name = "Player";
	srand(time(NULL));

	vidas = rand() % 3 + 1;
}

Jugador:: Jugador(string name, int coord_x, int coord_y, char letra): Item(coord_x, coord_y, letra){
	this->name = name;
	tipo = "Human";
	vivo = true;
	srand(time(NULL));
	vidas = rand() % 3 + 1;
}

string Jugador:: getName(){
	return name;
}

string Jugador:: getTipo(){
	return tipo;
}

bool Jugador:: isVivo(){
	return vivo;
}

void Jugador:: setMuerte(){
	vivo = false;
}

void Jugador:: perderVida(){
	vidas--;
	if (vidas == 0){
		setMuerte();
	}
}

int Jugador:: getVidas(){
	return vidas;
}

void Jugador:: cambioEstado(){
	if (movido){
		movido = false;
	}else{
		movido = true;
	}
}
bool Jugador:: moved(){
	return movido;
}

Jugador:: ~Jugador(){

}

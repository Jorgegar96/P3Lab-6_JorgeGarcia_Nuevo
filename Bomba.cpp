#include "Bomba.h"

Bomba:: Bomba(int coord_x, int coord_y, char letra): Item(coord_x, coord_y, letra){
	turno_explotar = 3;
	/*if(this->letra == 'b'){
		letra = static_cast<char>(turno_explotar);
	}*/
}

void Bomba:: reduceTurno(){
	turno_explotar--;
	/*if(this->letra == 'b'){
		this->letra = static_cast<char>(turno_explotar);
	}*/	
}

void Bomba:: Explotar(){
	exploded = true;
}

bool Bomba:: getEstado(){
	return exploded;
}

int Bomba:: getTurno(){
	return turno_explotar;
}

bool Bomba:: getPuesta(){
	return puesta;
}	

void Bomba:: poner(){
	puesta = true;
}

Bomba:: ~Bomba(){

}

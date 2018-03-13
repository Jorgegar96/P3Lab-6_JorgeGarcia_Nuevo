#include "V.h"
#include "Jugador.h"
#include "Obstaculo.h"
#include <typeinfo>

V::V(int coord_x, int coord_y, char letra): Bomba(coord_x, coord_y, letra){

}

void V:: explosion(Item*** mapa){
	int recorrido = 0;
	Jugador* jugador;
	for(int i=1; i <= 20; i++){
		if (recorrido == 0){
			if(this->getX() + i < 11 && this->getY()+i < 13){
				if (typeid(*mapa[this->getX()+i][this->getY()+i]) == typeid(Jugador)){
					jugador = dynamic_cast<Jugador*>(mapa[this->getX()+i][this->getY()+i]);
					jugador->perderVida();
				}
			}
		}else if (recorrido == 1){
			if(this->getX() -i >= 0 && this->getY()+i < 13){
				if (typeid(*mapa[this->getX()-i][this->getY()+i]) == typeid(Jugador)){
					dynamic_cast<Jugador*>(mapa[this->getX()-i][this->getY()+i]);
					jugador->perderVida();
				}
			}
		}else if (recorrido == 2){
			if (this->getX() +i < 11 &&  this->getY()-i >= 0){
				if (typeid(*mapa[this->getX()-i][this->getY()+i]) == typeid(Jugador)){
					dynamic_cast<Jugador*>(mapa[this->getX()-i][this->getY()+i]);
					jugador->perderVida();
				}
			}
		}else if (recorrido == 3){
			if (this->getX() -i >= 0 && this->getY()-i >= 0){
				if (typeid(*mapa[this->getX()-i][this->getY()-i]) == typeid(Jugador)){
					dynamic_cast<Jugador*>(mapa[this->getX()-i][this->getY()-i]);
				}
			}
		}
		if (i == 20){
			recorrido++;
		}
	}	
}

V::~V(){

}

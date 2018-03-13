#include "Espina.h"
#include "Jugador.h"
#include "Obstaculo.h"
#include <typeinfo>
Espina:: Espina(int coord_x, int coord_y, char letra): Bomba(coord_x, coord_y, letra){
	
}

void Espina:: explosion(Item*** mapa){
	int recorrido = 0;
	Jugador* jugador;
	for(int i=1; i <= 13; i++){
		if (recorrido == 0){
			if(this->getX() + i < 11){
				if (typeid(*mapa[this->getX()+i][this->getY()]) == typeid(Obstaculo) ){
					i = 1;
					recorrido++;
				}else{
					if (typeid(*mapa[this->getX()+i][this->getY()]) == typeid(Jugador)){
						jugador = dynamic_cast<Jugador*>(mapa[this->getX()+i][this->getY()]);
						jugador->perderVida();
					}
				}
			}
		}else if (recorrido == 1){
			if(this->getX() -i >= 0){
				if (typeid(*mapa[this->getX()-i][this->getY()]) == typeid(Obstaculo) ){
					i = 1;
					recorrido++;
				}else{
					if (typeid(*mapa[this->getX()-i][this->getY()]) == typeid(Jugador)){
						dynamic_cast<Jugador*>(mapa[this->getX()-i][this->getY()]);
						jugador->perderVida();
					}
				}
			}
		}else if (recorrido == 2){
			if (this->getY() -i >= 0){
				if (typeid(*mapa[this->getX()][this->getY()-i]) == typeid(Obstaculo) ){
					i = 1;
					recorrido++;
				}else{
					if (typeid(*mapa[this->getX()][this->getY()-i]) == typeid(Jugador)){
						dynamic_cast<Jugador*>(mapa[this->getX()][this->getY()-i]);
						jugador->perderVida();
					}
				}
			}
		}else if (recorrido == 3){
			if (this->getY() +i < 13){
				if (typeid(*mapa[this->getX()+i][this->getY()+i]) == typeid(Obstaculo) ){
					i = 1;
					recorrido++;
				}else{
					if (typeid(*mapa[this->getX()][this->getY()+i]) == typeid(Jugador)){
						dynamic_cast<Jugador*>(mapa[this->getX()][this->getY()+i]);
					}
				}
			}
		}
		if (i == 12){
			recorrido++;
		}
	}	
}

Espina:: ~Espina(){

}

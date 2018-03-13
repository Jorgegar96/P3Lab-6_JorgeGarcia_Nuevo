#include "Normal.h"
#include <time.h>
#include <stdlib.h>
#include <typeinfo>
#include "Jugador.h"
#include "Obstaculo.h"
#include <iostream>
Normal:: Normal(int coord_x, int coord_y, char letra): Bomba(coord_x, coord_y, letra){
	srand(time(NULL));
	alcance = rand() % 4 + 1;
	alcance = 5;
}

int Normal:: getAlcance(){
	return alcance;
}

void Normal:: explosion(Item*** mapa){
	int recorrido = 0;
	Jugador* jugador;
	for(int i=1; i <= alcance; i++){
		if (recorrido == 0){
			if(this->getX() + i < 11){
				if (typeid(*mapa[this->getX()+i][this->getY()]) == typeid(Obstaculo) ){
					i = 1;
					cout<<"se encontro un obstaculo"<<endl;
					recorrido++;
				}else{
					if (typeid(*mapa[this->getX()+i][this->getY()]) == typeid(Jugador)){
						jugador = dynamic_cast<Jugador*>(mapa[this->getX()+i][this->getY()]);
						jugador->perderVida();
						if (!jugador->isVivo()){
							delete mapa[getX()+i][getY()];
							mapa[getX()+i][getY()] = new Item(getX()+i, getY(), ' ');
						}
						cout<<"el jugador perdio una vida"<<endl;
					}else if(typeid(*mapa[this->getX()+i][this->getY()]) == typeid(Normal)){
						if(!dynamic_cast<Normal*>(mapa[this->getX()+i][this->getY()])->getEstado()){
							(dynamic_cast<Normal*>(mapa[this->getX()+i][this->getY()]))->Explotar();
							(dynamic_cast<Normal*>(mapa[this->getX()+i][this->getY()]))->explosion(mapa);
						}
					}else{
						cout<<"Item";
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
						jugador = dynamic_cast<Jugador*>(mapa[this->getX()-i][this->getY()]);
						jugador->perderVida();
						cout<<"El jugador prdio una vida"<<endl;
						if (!jugador->isVivo()){
							delete mapa[getX()-i][getY()];
							mapa[getX()-i][getY()] = new Item(getX()-i, getY(), ' ');
						}
					}else if(typeid(*mapa[this->getX()-i][this->getY()]) == typeid(Normal)){
						if(!dynamic_cast<Normal*>(mapa[this->getX()-i][this->getY()])->getEstado()){
							(dynamic_cast<Normal*>(mapa[this->getX()-i][this->getY()]))->Explotar();
							(dynamic_cast<Normal*>(mapa[this->getX()-i][this->getY()]))->explosion(mapa);
						}
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
						jugador = dynamic_cast<Jugador*>(mapa[this->getX()][this->getY()-i]);
						jugador->perderVida();
						cout<<"El jugador perdio vida"<<endl;
						if (!jugador->isVivo()){
							delete mapa[getX()][getY()-i];
							mapa[getX()][getY()-i] = new Item(getX(), getY()-i, ' ');
						}
					}else if(typeid(*mapa[this->getX()][this->getY()-i]) == typeid(Normal)){
						if(!dynamic_cast<Normal*>(mapa[this->getX()][this->getY()]-i)->getEstado()){
							(dynamic_cast<Normal*>(mapa[this->getX()][this->getY()]-i))->Explotar();
							(dynamic_cast<Normal*>(mapa[this->getX()][this->getY()]-i))->explosion(mapa);
						}
					}
				}
			}
		}else if (recorrido == 3){
			if (this->getY() +i < 13){
				if (typeid(*mapa[this->getX()+i][this->getY()+i]) == typeid(Obstaculo) ){
					
					recorrido++;
				}else{
					if (typeid(*mapa[this->getX()][this->getY()+i]) == typeid(Jugador)){
						jugador = dynamic_cast<Jugador*>(mapa[this->getX()][this->getY()+i]);
						jugador->perderVida();
						cout<<"el jugador perdio una vida"<<endl;
						if (!jugador->isVivo()){
							delete mapa[getX()][getY()+i];
							mapa[getX()][getY()+i] = new Item(getX(), getY()+i, ' ');
						}
					}else if(typeid(*mapa[this->getX()+i][this->getY()]) == typeid(Normal)){
						if(!dynamic_cast<Normal*>(mapa[this->getX()][this->getY()]+i)->getEstado()){
							(dynamic_cast<Normal*>(mapa[this->getX()][this->getY()]+i))->Explotar();
							(dynamic_cast<Normal*>(mapa[this->getX()][this->getY()]+i))->explosion(mapa);
						}
					}
				}
			}
		}
		if (i == alcance){
			recorrido++;
		}
	}	
	
}

Normal:: ~Normal(){

}

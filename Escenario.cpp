#include "Escenario.h"
#include <string>
#include <vector>
#include "Item.h"
#include <time.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Obstaculo.h"
#include "Bomba.h"
#include "iostream"
#include "typeinfo"
#include "Normal.h"
#include "Espina.h"
#include "V.h"
using namespace std;

Escenario:: Escenario(string name){
	srand(time(NULL));
	this->name = name;
	cont_bomb = 0;	
}

string Escenario:: getName(){
	return name;
}

Item*** Escenario:: getMapa(){
	return map;
}

vector<Item*> Escenario:: getBombas(){
	return bombas;
}	

void Escenario:: reducirConteo(){
	/*for (int i=0; i < bombas.size(); i++){
		bombas.at(i)->reduceTurno();
		if (bombas.at(i)->getTurno() == 0){
			explosion(bombas.at(i));
			delete bombas.at(i);
			bombas.at(i) = NULL;
			bombas.erase(bombas.begin() + i);
		}
	}*/
}

void Escenario:: explosion(Item* bomb){
	//if (dynamic_cast<>)
}

void Escenario:: addBomb(Item* bomb){
	bombas.push_back(bomb);
}


bool Escenario:: movVal(int pos_x, int pos_y, int delta_x, int delta_y){
	if(pos_x + delta_x > 10 || pos_x + delta_x < 0 || pos_y + delta_y > 12 || pos_y + delta_y < 0){
		return false;
	}/*else if(typeid(*map[pos_x+delta_x][pos_y+delta_x]) == typeid(Obstaculo)){
		cout<<"Hay un obstaculo"<<endl;
		return false;
	}*/else if(typeid(*map[pos_x+delta_x][pos_y+delta_y]) != typeid(Item)) {
		cout<<"Casilla no vacia"<<endl;
		return false;
	}else{
		return true;
	}
	cout<<"el mov es valido"<<endl;
	return true;
}
							
void Escenario:: resetEstado(){
	Jugador* jugador;
	for (int i=0; i < 11; i++){
		for (int j=0; j < 13; j++){
			if (typeid(*map[i][j]) == typeid(Jugador)){
				jugador = dynamic_cast<Jugador*>(map[i][j]);
				jugador->cambioEstado();
			}
		}
	}
}

void Escenario:: moverBots(char direccion, bool invisible, int tipo /*1 = normal, 2 = espina, 3 = V*/){
	cout<<"Se ingresó al método para mover "<<endl;
	Jugador* jugador;
	int delta_x = 0;
	int delta_y = 0;
	for(int i=0; i < bombas.size(); i++){
		if(typeid(*map[bombas.at(i)->getX()][bombas.at(i)->getY()]) == typeid(Item)){
				delete map[bombas.at(i)->getX()][bombas.at(i)->getY()];
				map[bombas.at(i)->getX()][bombas.at(i)->getY()] = bombas.at(i);
				
				bombas.erase(bombas.begin()+i);
				i--;
		}
	}	
	for(int i=0; i < 11; i++){
		for(int j=0; j < 13; j++){
			if(typeid(*map[i][j]) == typeid(Jugador) && !((jugador = dynamic_cast<Jugador*>(map[i][j]))->moved()) ){
				//cout<<"Se encontró un jugador"<<endl;
				if(map[i][j]->getLetra()=='j'){
					//cout<<"Su caracter es j"<<endl;
					bool mov_val = false;
					jugador = dynamic_cast<Jugador*>(map[i][j]);
					jugador->cambioEstado();
					//while(!mov_val){
						switch (direccion){
							case 'w':
								if (movVal(i, j, -1, 0)){
									delete map[i-1][j];
									map[i-1][j] = map[i][j];
									map[i][j] = new Item(i, j, ' ');
									mov_val = true;
								}
								break;
							case 'a':
								if (movVal(i, j, 0, -1)){
									delete map[i][j-1];
									map[i][j-1] = map[i][j];
									map[i][j] = new Item(i, j, ' ');
									mov_val = true;
								}
								break;
							case 's':
								//cout<<"quiere moverse hacia abajo"<<endl;
								if (movVal(i, j, 1, 0)){
									delete map[i+1][j];
									map[i+1][j] = map[i][j];
									map[i][j] = new Item(i, j, ' ');
									mov_val = true;
									//cout<<"Se movio hacia abajo"<<endl;
								}
								break;
							case 'd':
								if(movVal(i, j, 0, 1)){
									delete map[i][j+1];
									map[i][j+1] = map[i][j];
									map[i][j] = new Item(i, j, ' ');
									mov_val = true;
								}
								break;
						}
						if (direccion == 'b'){

							if(invisible == true){
								switch(tipo){
									case 1:
										if (cont_bomb % 2 == 0){
											bombas.push_back(new Normal(i, j, 'b'));
										}else{
											bombas.push_back(new Normal(i, j, ' '));
										}
										break;
									case 2:
										if(cont_bomb % 2 == 0){
											bombas.push_back(new Espina(i, j, 'b'));
										}else{
											bombas.push_back(new Espina(i, j, ' '));
										}
										break;
									case 3:
										if(cont_bomb % 2 == 0){
											bombas.push_back(new V(i, j, 'b'));
										}else{
											bombas.push_back(new V(i, j, ' '));
										}
										break;
								}
								cont_bomb++;
							}else{

							}
						}	
						/*for(int x=0; x<11; x++){
							for(int y=0; y<13; y++){
								cout<<this->getMapa()[x][y]->getLetra();
							}
								cout<<endl;
						}*/
					//}			
				}else if (map[i][j]->getLetra()=='a'){
					//cout<<"Su letra es a"<<endl;
					if(bombas.size()>0){
						for (int i=0;i < bombas.size(); i++){
							//if()
						}
					}
					//srand(time(NULL));
					bool mov_val = false;
					int cont =0;
					delta_x =0;
					delta_y =0;
					bool arriba = false;
					bool abajo = false;
					bool izq = false;
					bool der = false;
					while (!mov_val){
						random = rand() % 5 + 0;
						cont++;
						//cout<<random;
						if(cont % 50 == 0){
						//	cout<<endl;
						}
						//num = 1;
						//cout<<"Se asigno un movimiento"<<endl;
						switch (random){
							case 0:
								arriba = true;
								if(movVal(i, j, -1, 0)){
									//delete map[i-1][j];
									map[i-1][j] = NULL;
									map[i-1][j] = map[i][j];
									map[i][j] = new Item(i, j, ' ');
									mov_val = true;
									delta_x = -1;
								}
								break;
							case 1:
								abajo = true;
								if(movVal(i, j, 1, 0)){
									//delete map[i+1][j];
									map[i+1][j] = NULL;
									//cout<<"Se borro la casilla"<<endl;
									map[i+1][j] = map[i][j];
									//cout<<"Se hizo el cambio"<<endl;
									map[i][j] = new Item(i, j, ' ');
									//cout<<"Se reasigno la casilla"<<endl;
									mov_val = true;
									delta_x = 1;
								}
								break;
							case 2:
								der = true;
								if(movVal(i, j, 0, 1)){
									//delete map[i][j+1];
									map[i][j+1] = NULL;
									map[i][j+1] = map[i][j];
									map[i][j] = new Item(i, j, ' ');
									mov_val = true;
									delta_y = 1;
								}
								break;
							case 3:
								izq = true;
								if(movVal(i, j, 0, -1)){
									//delete map[i][j-1];
									map[i][j-1] = NULL;
									map[i][j-1] = map[i][j];
									map[i][j] = new Item(i, j, ' ');
									mov_val = true;
									delta_y = -1;
								}
								break;
						}
						if (random == 5){
							mov_val = true;
							if(invisible == true){
								switch(tipo){
									case 1:
										if (cont_bomb % 2 == 0){
											bombas.push_back(new Normal(i, j, 'b'));
										}else{
											bombas.push_back(new Normal(i, j, ' '));
										}
										break;
									case 2:
										if(cont_bomb % 2 == 0){
											bombas.push_back(new Espina(i, j, 'b'));
										}else{
											bombas.push_back(new Espina(i, j, ' '));
										}
										break;
									case 3:
										if(cont_bomb % 2 == 0){
											bombas.push_back(new V(i, j, 'b'));
										}else{
											bombas.push_back(new V(i, j, ' '));
										}
										break;
								}
								cont_bomb ++;
							}else{

							}
						}
						//cout<<"qwert"<<endl;
						if(arriba && abajo && izq && der){
							mov_val = true;
						}
						/*if (mov_val == true){
							for(int x=0; x<11; x++){
								for(int y=0; y<13; y++){
									cout<<this->getMapa()[x][y]->getLetra();
								}
								cout<<endl;
							}
						}*/
					}
					jugador = dynamic_cast<Jugador*>(map[i+delta_x][j+delta_y]);
					//cout<<"Se hizo el casteo"<<endl;
					jugador->cambioEstado();
					//cout<<"Se cambió el estado"<<endl;
				}
			}else if (dynamic_cast<Normal*>(map[i][j]) != NULL){
				cout<<"123"<<endl;
				if((dynamic_cast<Normal*>(map[i][j]))->getTurno() > 0){
					cout<<"reduciendo turno"<<endl;
					(dynamic_cast<Normal*>(map[i][j]))->reduceTurno();
				}else{
					cout<<"explotando"<<endl;
					(dynamic_cast<Normal*>(map[i][j]))->Explotar();
					(dynamic_cast<Normal*>(map[i][j])->explosion(map));
					delete map[i][j];
					map[i][j] = new Item(i, j, ' ');
				}
			}else if (typeid(*map[i][j]) == typeid(Espina)){
				if((dynamic_cast<Espina*>(map[i][j]))->getTurno() > 0){
					(dynamic_cast<Espina*>(map[i][j]))->reduceTurno();
				}else{
					(dynamic_cast<Espina*>(map[i][j]))->Explotar();
					(dynamic_cast<Espina*>(map[i][j])->explosion(map));
				}
			} else if (typeid(*map[i][j]) == typeid(V)){
				if((dynamic_cast<V*>(map[i][j]))->getTurno() > 0){
					(dynamic_cast<V*>(map[i][j]))->reduceTurno();
				}else{
					(dynamic_cast<V*>(map[i][j]))->Explotar();
					(dynamic_cast<V*>(map[i][j])->explosion(map));
				}
			}
		}
	}
	resetEstado();	
}



bool Escenario:: jugadorPrincipal(){
	for(int i=0; i < 11; i++){
		for(int j=0; j < 13; j++){
			if (typeid(*map[i][j]) == typeid(Jugador) && map[i][j]->getLetra() == 'j'){
				return true;
			}
		}
	}
	return false;
}

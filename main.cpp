#include <iostream>
#include <string>
#include "Escenario.h"
#include "Jugador.h"
#include "Item.h"
#include "Obstaculo.h"
#include "Bomba.h"
#include "Normal.h"
#include "Espina.h"
#include "V.h"
#include "Invisible.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <chrono>
#include <time.h>
#include <stdlib.h>
#include <thread>
using namespace std;

char* movimiento(string);

int main(){
	//srand(time(NULL));
	cout<<"Ingrese el nombre del tablero";
	string nombre;
	cin>>nombre;
	cout<<"Escoga el tipo de escenario"<<endl;
	cout<<"1) Invisible"<<endl
	    <<"2) Tren"	<<endl;
	int op;
	cin>>op;
	Escenario* e;
	switch(op){
		case 1:
			e = new Invisible(nombre);
			break;
		case 2:
			//Escenario* e = new Tren();
			break;
	}
	cout<<"Tipo de bomba"<<endl;
	cout<<"1)Normal"<<endl
		<<"2) Espina"<<endl
		<<"3) V"<<endl;
	cin>>op;
	switch(op){
		case 1:
			op = 1;
			break;
		case 2:
			op = 2;
			break;
		case 3:
			op = 3;
			break;
	}
	string mov = "0";
	while (mov != "e"){
		dynamic_cast<Invisible*>(e)->imprimirMapa();
		cout<<"Ingrese un movimiento"<<endl;
		cin>>mov;
		if (mov == "e"){
			break;
		}
		cout<<"Se leyeron los caracteres"<<endl;
		char* movimientos = movimiento(mov);
		cout<<"Se asignaron los caracteres"<<endl;
		bool todos_validos = true;
		for(int i=0; i < mov.length();i++){
			if(movimientos[i] != 'w' && movimientos[i] != 'a' && movimientos[i] != 's' && movimientos[i] != 'd' && movimientos[i] != ' '
					&& movimientos[i] != 'b'){
				todos_validos = false;
				break;
			}
		}
		if (todos_validos){
			for (int i=0; i < mov.length(); i++){
				if (typeid(*e) == typeid(Invisible)){
					e->moverBots(movimientos[i], true, op);
					dynamic_cast<Invisible*>(e)->imprimirMapa();
				}
			}
		}else{
			cout<<"Se ingresaron caracteres inválidos!"<<endl;
		}
		if (!e->jugadorPrincipal()){
			mov = "e";	
		}
	}
	return 0;
}

char* movimiento(string mov){
	char* movimientos = new char[mov.length()-1];
	for (int i = 0; i < mov.length(); i++){
		movimientos[i] = mov[i];
	}
	return movimientos;
}

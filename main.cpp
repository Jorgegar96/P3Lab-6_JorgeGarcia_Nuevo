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
	Escenario* e = new Invisible(nombre);
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
					e->moverBots(movimientos[i], true, 1);
					dynamic_cast<Invisible*>(e)->imprimirMapa();
				}
			}
		}else{
			cout<<"Se ingresaron caracteres inválidos!"<<endl;
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

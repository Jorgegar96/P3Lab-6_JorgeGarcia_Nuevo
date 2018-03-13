#include "Escenario.h"
#include "Jugador.h"
#include "Item.h"
#include "Obstaculo.h"
#include "Bomba.h"
#include "Invisible.h"
#include <vector>
#include <iostream>
#include <string>

Invisible:: Invisible(string name): Escenario(name){
	llenarMapa();
}

void Invisible:: llenarMapa(){
	map = new Item**[11];
	for(int j=0; j < 11; j++){
		map[j] = new Item*[13];
		for(int i=0; i < 13; i++){
			if (i % 2 != 0 && j % 2 != 0){
				map[j][i] = new Obstaculo(j, i, 'o');
			} else if ( (i == 12 && j == 0) || (i==0 && j ==10) || (i==12 && j==10) || (i == 6 && j == 5)){
				map[j][i] = new Jugador(j, i, 'a');
			} else if ( i==0 && j == 0){
				cout<<"Ingrese el nombre deseado"<<endl;
				string nombre;
				cin >> nombre;
				map[j][i] = new Jugador(nombre, j, i, 'j');
			}else{
				map[j][i] = new Item(j, i, ' ');
			}
		}
	}
}

void Invisible:: imprimirMapa(){
		
	for(int x=0; x<11; x++){
		for(int y=0; y<13; y++){
			cout<<this->getMapa()[x][y]->getLetra();
		}
		cout<<endl;
	}
}

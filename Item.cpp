#include "Item.h"
#include <string>

using namespace std;

Item:: Item(int coord_x, int coord_y, char letra){
	this->coord_x = coord_x;
	this->coord_y = coord_y;
	this->letra = letra;
}

int Item:: getX(){
	return coord_x;
}

int Item::getY(){
	return coord_y;
}

void Item:: setX(int coord_x){
	this-> coord_x = coord_x;
}

void Item:: setY(int coord_y){
	this-> coord_y = coord_y;
}

char Item:: getLetra(){
	return letra;
}

Item:: ~Item(){

}

#include <string>
#include <vector>
#include "Bomba.h"
#ifndef ITEM_H
#define ITEM_H

class Item{

	private: 
		int coord_x;
		int coord_y;

	public:
		char letra;
		Item(int, int, char);
		int getX();
		int getY();
		virtual void setX(int);
		void setY(int);
		char getLetra();
		~Item();
};

#endif

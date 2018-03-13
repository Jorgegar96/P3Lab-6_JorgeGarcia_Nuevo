#include "Bomba.h"
#ifndef ESPINA_H
#define ESPINA_H

class Espina: public Bomba{

	private:
	
	public:
		Espina(int, int, char);
		void explosion(Item***);
		~Espina();
	
};

#endif

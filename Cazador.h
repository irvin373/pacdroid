#pragma once
#include "Fantasma.h"
class Cazador: public Fantasma
{
public:
	Cazador(void);
	void siguienteCasilla(char vec[4],SDL_Rect);
	~Cazador(void);
};


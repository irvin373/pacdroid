#pragma once
#include "Fantasma.h"
class Tonto: public Fantasma
{
public:
	Tonto(void);
	void siguienteCasilla(char vec[4],SDL_Rect);
	~Tonto(void);
};


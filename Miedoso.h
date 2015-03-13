#pragma once
#include "Fantasma.h"
class Miedoso: public Fantasma
{
public:
	Miedoso(void);
	void siguienteCasilla(char vec[4],SDL_Rect);
	~Miedoso(void);
};


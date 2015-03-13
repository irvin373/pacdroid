#pragma once
#include "Fantasma.h"
class Emboscador: public Fantasma
{
public:
	Emboscador(void);
	void siguienteCasilla(char vec[4],SDL_Rect);
	~Emboscador(void);
};
#pragma once
#include "Personaje.h"
class Fantasma: public Personaje
{
public:
	Fantasma(void);
	void dibujar(SDL_Surface *screen);
	void jugar(SDL_Surface *screen);
	int comer(SDL_Rect);
	virtual void siguienteCasilla(char vec[4],SDL_Rect)=0;
	~Fantasma(void);
};
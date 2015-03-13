#pragma once
#include "Personaje.h"
class Pacman: public Personaje
{
public:
	Pacman(void);
	void dibujar(SDL_Surface *screen);
	void leer();
	void setEstado(int);
	void jugar(SDL_Surface *screen);
	~Pacman(void);
private:
	SDL_Event evento;
};


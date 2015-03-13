#include "Fantasma.h"
#define miedo "miedoso.bmp"
Fantasma::Fantasma(void)
{
}

void Fantasma::dibujar(SDL_Surface *screen)
{
	SDL_BlitSurface(imagen, NULL, screen, &destino);
}

int Fantasma::comer(SDL_Rect temp)
{
	if(destino.x == temp.x && destino.y == temp.y)
	{
		if(estado == 1)
		{
			destino.x=40;
			destino.y=40;
			return 100;
		}
		else 
			return 1;
	}
	return 0;
}

void Fantasma::jugar(SDL_Surface *screen)
{
	dibujar(screen);
}


Fantasma::~Fantasma(void)
{
}

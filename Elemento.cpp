#include "Elemento.h"

Elemento::Elemento(void)
{
}

void Elemento::setvalor(char car)
{
	this->valor=car;
}

char Elemento::getvalor()
{
	return valor;
}

void Elemento::llenar( SDL_Surface *screen, SDL_Rect temp, char car )
{
	this->posicion=temp;
	this->valor=car;
	if(car=='-')
		elemento=SDL_LoadBMP("pared.bmp");
	if(car=='.')
		elemento=SDL_LoadBMP("fondo.bmp");
	if(car=='*')
		elemento=SDL_LoadBMP("mac.bmp");
	if(car=='$')
		elemento=SDL_LoadBMP("tux.bmp");
	SDL_BlitSurface(elemento, NULL, screen, &posicion);
}

void Elemento::mostrar(SDL_Surface *screen)
{
	SDL_BlitSurface(elemento, NULL, screen, &posicion);
}

Elemento::~Elemento(void)
{
}

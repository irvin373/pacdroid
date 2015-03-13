#include "Personaje.h"

Personaje::Personaje(void)
{
	this->estado=0;
}

SDL_Rect Personaje::getdestino()
{
	return destino;
}

void Personaje::setEstado(int temp)
{
	this->estado=temp;
}


void Personaje::setdestino(SDL_Rect temp)
{
	this->destino=temp;
}

void Personaje::control(SDL_Rect temp)
{
	if(temp.x == destino.x && temp.y==destino.y)
	{
		if(orientacion == 'u')
			moverAbajo();
		if(orientacion == 'd')
			moverArriba();
		if(orientacion == 'l')
			moverDerecha();
		if(orientacion == 'r')
			moverIzquierda();
		orientacion=' ';
	}
}

void Personaje::moverArriba()
{
	destino.y=destino.y-20;
}

void Personaje::moverAbajo()
{
	destino.y=destino.y+20;
}

void Personaje::moverDerecha()
{
	destino.x=destino.x+20;
}

void Personaje::moverIzquierda()
{
	destino.x=destino.x-20;
}

SDL_Surface* Personaje::getImagen()
{
	return imagen;
}

Personaje::~Personaje(void)
{
}

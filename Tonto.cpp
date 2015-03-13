#include "Tonto.h"
#define tonto "homero.bmp"

Tonto::Tonto(void)
{
	destino.x=40;
	destino.y=40;
	imagen=SDL_LoadBMP(tonto);
}

void Tonto::siguienteCasilla(char vec[4], SDL_Rect temp)
{
	int num=rand()%5;
	if(num == 1)
	{
		if( vec[0] != '-' )
			moverArriba();
	}
	if(num == 2)
	{
		if( vec[1] != '-' )
			moverAbajo();
	}
	if(num == 3)
	{
		if( vec[2] != '-' )
			moverIzquierda();
	}
	if(num > 3)
	{
		if( vec[3] != '-' )
			moverDerecha();
	}
}

Tonto::~Tonto(void)
{
}

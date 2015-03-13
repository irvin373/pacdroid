#include "Miedoso.h"
#define miedoso "kitti.bmp"
Miedoso::Miedoso(void)
{
	destino.x=20;
	destino.y=20;
	imagen=SDL_LoadBMP(miedoso);
}

void Miedoso::siguienteCasilla(char vec[4], SDL_Rect temp)
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
	if(destino.x == temp.x)
	{
		if(vec[2] == '-')
			moverDerecha();
		else
			moverIzquierda();
	}

	if(destino.y == temp.y)
	{
		if(vec[0] == '-')
			moverAbajo();
		else 
			moverArriba();
	}
}

Miedoso::~Miedoso(void)
{
}

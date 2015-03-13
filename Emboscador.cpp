#include "Emboscador.h"
#define emboscador "rasta.bmp"

Emboscador::Emboscador(void)
{
	destino.x=40;
	destino.y=40;
	imagen=SDL_LoadBMP(emboscador);
}

void Emboscador::siguienteCasilla(char vec[4], SDL_Rect temp)
{
	static int i=0;
	i++;
	if(i%3 == 0)
	{	
		if(destino.y>temp.y)
		{
			if(vec[0] != '-')
				moverArriba();
		}
		if(destino.y<temp.y)
		{
			if(vec[1] != '-')
				moverAbajo();
		}
		if(destino.x>temp.x)
		{
			if(vec[2] != '-')
				moverIzquierda();
		}
		if(destino.x<temp.x)
		{
			if(vec[3] != '-')
				moverDerecha();
		}
	}
}

Emboscador::~Emboscador(void)
{
}

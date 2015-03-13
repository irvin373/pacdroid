#include "Cazador.h"
#define cazador "billgates.bmp"
Cazador::Cazador(void)
{
	destino.x=40;
	destino.y=40;
	imagen=SDL_LoadBMP(cazador);
}

void Cazador::siguienteCasilla(char vec[4], SDL_Rect temp)
{
	static int i=0;
	i++;
	if(i%2 == 0)
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

Cazador::~Cazador(void)
{
}

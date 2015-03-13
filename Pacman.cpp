#include "Pacman.h"
#define ropen "RigthOpen.bmp"
#define dopen "DownOpen.bmp"
#define uopen "UpOpen.bmp"
#define lopen "LeftOpen.bmp"

Pacman::Pacman(void)
{
	this->orientacion=' ';
	imagen=SDL_LoadBMP(ropen);
	destino.y=280;
	destino.x=320;
}

void Pacman::dibujar(SDL_Surface *screen)
{
	if(orientacion == ' ')
		imagen=SDL_LoadBMP(ropen);
		
	if(orientacion == 'r')
		imagen=SDL_LoadBMP(ropen);
	
	if(orientacion == 'l')
		imagen=SDL_LoadBMP(lopen);

	if(orientacion == 'u')
		imagen=SDL_LoadBMP(uopen);
	
	if(orientacion == 'd')
		imagen=SDL_LoadBMP(dopen);
	if(estado ==1 )
		imagen=SDL_LoadBMP("poder.bmp");
	SDL_BlitSurface(imagen, NULL, screen, &destino);
}

void Pacman::leer()
{
	SDL_Init(SDL_INIT_JOYSTICK|SDL_INIT_VIDEO);
	SDL_JoystickOpen(0);
	
	if (SDL_PollEvent(&evento))
	{
		if( evento.type == SDL_JOYAXISMOTION )
		{
		if( evento.jaxis.which == 0 )
		{
			if( evento.jaxis.axis == 0 )
			{
				if( ( evento.jaxis.value > -8000 ) && ( evento.jaxis.value < 8000 ) )
				{	
				}
				else
				{
					if( evento.jaxis.value < 0 )
					{
						orientacion='l';
					}
					else
					{
						orientacion='r';    
					}
				} 
			} 
			if( evento.jaxis.axis == 1 )
			{
				if( ( evento.jaxis.value > -8000 ) && ( evento.jaxis.value < 8000 ) )
				{
				}
				else
				{
					if( evento.jaxis.value <= 0 )
					{
						orientacion='u';    
					}
					else
					{
						orientacion='d';    
					}
				}
			}
		}	
		}
	}
}

void Pacman::jugar(SDL_Surface *screen)
{	
	
	//leer();
	if (SDL_PollEvent(&evento))
	{
		if (evento.type == SDL_KEYDOWN)
		{     
			switch (evento.key.keysym.sym)  
			{
				case SDLK_UP: orientacion='u'; break;    
				case SDLK_DOWN:orientacion='d';break;  
				case SDLK_LEFT: orientacion='l';break;    
				case SDLK_RIGHT:orientacion='r';break;    
				//case SDLK_ESCAPE:  encendido=false ; break;
			}
		}
	}
	if(orientacion == 'u')
		moverArriba();
	if(orientacion == 'd')
		moverAbajo();
	if(orientacion == 'l')
		moverIzquierda();
	if(orientacion == 'r')
		moverDerecha();
	dibujar(screen);
}

Pacman::~Pacman(void)
{
}

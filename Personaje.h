#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <SDL\SDL.h>
using namespace std;

class Personaje
{
public:
	Personaje(void);
	virtual void dibujar(SDL_Surface *screen)=0;
	virtual void jugar(SDL_Surface *screen)=0;
	void control(SDL_Rect);
	void moverIzquierda();
	void moverDerecha();
	void moverArriba();
	void moverAbajo();
	SDL_Rect getdestino();
	void setdestino(SDL_Rect);
	void setEstado(int);
	SDL_Surface* getImagen();
	~Personaje(void);
protected:
	SDL_Surface *imagen;
	SDL_Rect destino;
	int estado;
	char orientacion;
};
#endif
#pragma once
#include <SDL\SDL.h>
class Elemento
{
public:
	Elemento(void);
	void setvalor(char);
	char getvalor();
	void mostrar(SDL_Surface *screen);
	void llenar(SDL_Surface *screen, SDL_Rect, char);
	~Elemento(void);
private:
	SDL_Surface *elemento;
	SDL_Rect posicion;
	char valor;
};
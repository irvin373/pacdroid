#pragma once
#include <iostream>
#include "Pacman.h"
#include "Tonto.h"
#include "Emboscador.h"
#include "Miedoso.h"
#include "Cazador.h"
#include "Elemento.h"
#include <fstream>
using namespace std;
class ElementosJuego
{
public:
	ElementosJuego(void);
	void cargar(SDL_Surface *screen);
	void mostrar();
	int getvidas();
	int getpuntuacion();
	void controlpacman();
	void controlfantasma(SDL_Rect);
	void fantasmainteligente(SDL_Rect);
	void jugar(SDL_Surface *screen);
	void dibujar(SDL_Surface *screen);
	~ElementosJuego(void);
private:
	int tiempo;
	int puntos;
	int vida;
	Elemento elementos[24][32];
	Personaje *pacman;
	Fantasma *fantasma[4];
};
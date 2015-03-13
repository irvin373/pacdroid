#include "ElementosJuego.h"
#define alto 24
#define ancho 32
#define ghost 4
#define Limpiar(screen) SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0))
ElementosJuego::ElementosJuego(void)
{
	this->tiempo=0;
	this->puntos=0;
	this->vida=1;
	pacman =new Pacman();
	fantasma[0]=new Tonto();
	fantasma[1]=new Cazador();
	fantasma[2]=new Emboscador();
	fantasma[3]=new Miedoso();
}

int ElementosJuego::getvidas()
{
	return vida;
}

int ElementosJuego::getpuntuacion()
{
	return puntos;
}

void ElementosJuego::cargar(SDL_Surface *screen)
{
	/*cargamos el mapa del juego que esta en un archivo de texto con la posivilidad 
	de crear un mapa nuevo o cargar cualquier tipo de mapa siempre y cuando este 
	entre 32x24 que son los limites de la pantalla*/
	static SDL_Rect destino;
	static char car;
	fstream archivo("mapa1.txt");
	for(int i=0; i<alto; i++)
	{
		for(int j=0; j<ancho; j++)
		{
			archivo>>car;
			destino.x=j*20;
			destino.y=i*20;
			if(car == '2')
			{
				fantasma[0]->setdestino(destino);
				car='.';
			}
			if(car == '3')
			{
				fantasma[1]->setdestino(destino);
				car='.';
			}
			if(car == '1')
			{
				fantasma[2]->setdestino(destino);
				car='.';
			}
			if(car == '4')
			{
				fantasma[3]->setdestino(destino);
				car='.';
			}
			elementos[i][j].llenar(screen,destino,car);
		}
	}
	archivo.close();
}

void ElementosJuego::dibujar(SDL_Surface *screen)
{
	static SDL_Rect destino;
	/*usamos una variable estatica ya que solo la usaremos para las cordenadas al 
	momento de dibujar y tendremos solo un dato por cada vez que se imprime*/
	for(int i=0; i<alto; i++)
	{
		for(int j=0; j<ancho; j++)
		{
			destino.x=j*20;
			destino.y=i*20;
			if(elementos[i][j].getvalor() =='.')
			{
				elementos[i][j].setvalor('.');
				elementos[i][j].llenar(screen,destino,'.');
			}
			elementos[i][j].mostrar(screen);
		}
	}
	/*asignamos los valores respecto al mapa cargado y adaptamos los datos
	referente a la pantalla en modo grafico*/
}

void ElementosJuego::controlfantasma(SDL_Rect temp)
{
	int x,y;
	int aux=0;
	char vec[4];
	for(int i=0; i<ghost; i++)
	{
		x=fantasma[i]->getdestino().x/20;
		y=fantasma[i]->getdestino().y/20;
		vec[0]=elementos[y-1][x].getvalor();
		vec[1]=elementos[y+1][x].getvalor();
		vec[2]=elementos[y][x-1].getvalor();
		vec[3]=elementos[y][x+1].getvalor();
		if( i == 2)
		{
			fantasma[i]->siguienteCasilla(vec,fantasma[1]->getdestino());
		}
		else
			fantasma[i]->siguienteCasilla(vec,temp);
		aux=fantasma[i]->comer(pacman->getdestino());
		puntos=puntos+aux;
		if(aux == 1)
			vida=0;
	}
}

void ElementosJuego::controlpacman()
{
	SDL_Rect temp;
	temp.x=pacman->getdestino().x/20;
	temp.y=pacman->getdestino().y/20;

	if(elementos[temp.y][temp.x].getvalor() == '*')
	{	
		elementos[temp.y][temp.x].setvalor('.');
		puntos=puntos+5;
	}
	if(elementos[temp.y][temp.x].getvalor() == '$')
	{
		elementos[temp.y][temp.x].setvalor('.');
		pacman->setEstado(1);
		for(int i=0 ; i<ghost; i++)
			fantasma[i]->setEstado(1);
		tiempo=0;
	}
	
	if(elementos[temp.y][temp.x].getvalor() == '-')
	{
		temp.x=temp.x*20;
		temp.y=temp.y*20;
		pacman->control(temp);
	}
}

void ElementosJuego::jugar(SDL_Surface *screen)
{
	static SDL_Rect temp;
	pacman->jugar(screen);
	controlpacman();
	controlfantasma(pacman->getdestino());

	fantasma[0]->jugar(screen);
	fantasma[1]->jugar(screen);
	fantasma[2]->jugar(screen);
	fantasma[3]->jugar(screen);
	SDL_Flip(screen);
	dibujar(screen);
	tiempo=tiempo+150;
	if( tiempo > 5000 )
	{
		pacman->setEstado(0);
		for(int i=0 ; i<ghost; i++)
			fantasma[i]->setEstado(0);
	}
	SDL_Delay(100);
}

ElementosJuego::~ElementosJuego(void)
{
}

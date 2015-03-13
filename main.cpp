/*#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif

int main ( int argc, char** argv )
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    // load an image
    SDL_Surface* bmp = SDL_LoadBMP("cb.bmp");
    if (!bmp)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = (screen->w - bmp->w) / 2;
    dstrect.y = (screen->h - bmp->h) / 2;

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // draw bitmap
        SDL_BlitSurface(bmp, 0, screen, &dstrect);

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(screen);
    } // end main loop

    // free loaded bitmap
    SDL_FreeSurface(bmp);

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
*/

#include "ElementosJuego.h"

void vacio(char mapa[24][32])
{
	for(int i=0; i<24; i++)
		for(int j=0; j<32; i++)
			mapa[i][j]=' ';
}

void cargarmapa(char mapa[24][32])
{
	int num,x,y,vel,mapas;
	fstream archivo("mapas.txt");
	archivo>>num;
	cin>>mapas;
	for(int c=0; c<mapas; c++)
	{
		archivo>>x;
		archivo>>y;
		archivo>>vel;
		for(int i=0; i<x; x++)
		{
			for(int j=0; j<y; j++)
			{
				archivo>>mapa[i][j];
			}
		}
	}
	archivo.close();
}

void mostrar(char mapa[24][32])
{
	for(int i=0; i<24; i++)
	{
		for(int j=0; j<32; j++)
		{
			cout<<mapa[i][j];
		}
		cout<<endl;
	}
}

void terminar(SDL_Surface *screen)
{
	SDL_Surface *imagen = SDL_LoadBMP("end.bmp");
	SDL_Rect destino;
	destino.x=200;
	destino.y=200;
	SDL_BlitSurface(imagen, NULL, screen, &destino);
}

void salir(SDL_Surface *screen)
{
	SDL_Surface *imagen;
	imagen = SDL_LoadBMP("end.bmp");
	SDL_Rect destino;
	destino.x=200;
	destino.y=200;
	SDL_BlitSurface(imagen, NULL, screen, &destino);
	SDL_Flip(screen);
	SDL_Delay(3000);
}

void menu(SDL_Surface *screen)
{
	SDL_Surface *imagen;
	imagen = SDL_LoadBMP("menu.bmp");
	SDL_Rect destino;
	destino.x=90;
	destino.y=90;
	SDL_BlitSurface(imagen, NULL, screen, &destino);
	SDL_Flip(screen);
	SDL_Delay(3000);
}

int main (int argc, char ** argv)
{

	int i=1;
	int vida;
	ElementosJuego game;
	SDL_Surface *screen = SDL_SetVideoMode( 640, 480, 32, SDL_HWSURFACE );
	menu(screen);
	game.cargar(screen);
	game.dibujar(screen);
	while(i != 0)
	{
		game.jugar(screen);
		if(game.getvidas() == 0)
			i=0;
	}
	salir(screen);
	SDL_Quit();
	cout<<"su puntuacion fue de: "<<game.getpuntuacion()-1<<endl;
	system("pause");
	return 0;
}


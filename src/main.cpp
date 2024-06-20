/* Using SDL and standard IO and other prototypes in the header unit */
#include "maze.h"

/* Screen dimension constants */
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/**
 * main:
 * @argc:
 * @args:
 */
int main( int argc, char* args[] )
{
	/* The window we'll be rendering to */
	SDL_Window* window = NULL;
	
	/* The surface contained by the window */
	SDL_Surface* screenSurface = NULL;

	/* The image we will load and show on the screen */
	SDL_Surface *helloword = NULL;

	if (init() == false)
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if (!loadMedia())
		{
			printf( "Failed to load media!\n" );
		}
		else
        {
            //Apply the image
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
			//Update the surface
            SDL_UpdateWindowSurface( gWindow );
			//Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }
	}

	

	/* Free resources and close SDL */
    close();

    return 0;
}














/*Initialize SDL  */
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		/* Create window */
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			/* Get window surface */
			screenSurface = SDL_GetWindowSurface( window );

			/* Fill the surface white */
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			
			/* Update the surface */
			SDL_UpdateWindowSurface( window );

            /* Hack to get window to stay up */
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}
	}
	
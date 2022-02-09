#include "window.hpp"


//Initialize variables  constructor//
MainSDLWindow::MainSDLWindow()
{
     window   = NULL;
     renderer = NULL;
     
}

//Destructor//
MainSDLWindow::~MainSDLWindow()
{
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

//Create window and renderer// 
int MainSDLWindow::Init(const char* title, int Window_height, int Window_width){
    SDL_Init(SDL_INIT_VIDEO);
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }   
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Window_width, Window_height, SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE );
    if( window == 0 )
    {
        printf( "Window could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if( renderer == 0 )
    {
        printf( "Renderer could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }      
    return EXIT_SUCCESS;
}

SDL_Renderer * MainSDLWindow::GetRenderer(void)
{
    return renderer; 
}
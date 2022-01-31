#include "exercice1.hpp"
using namespace std;
#define MOVECASE 10
//Initialize variables  constructor//
MainSDLWindow::MainSDLWindow(){
     window   = NULL;
     renderer = NULL;
     
}
//Destructor//
MainSDLWindow::~MainSDLWindow(){
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
    
    SDL_Rect rectangle = {0,0,250,250};
    SDL_SetRenderDrawColor(renderer, 255,  255 , 255, 0);
    SDL_RenderDrawRect(renderer, &rectangle);
    SDL_RenderPresent(renderer);
    return EXIT_SUCCESS;
}

SDL_Renderer * MainSDLWindow::GetRenderer(void){
    
    return renderer; 
}
void keyboard()
{
const Uint8 *keystates = SDL_GetKeyboardState(NULL);

if (keystates[SDL_SCANCODE_UP])
{
    printf( "Yé souis oune tractoupel\n" );
}
if (keystates[SDL_SCANCODE_DOWN])
{
    printf( "Mais je SPAM A\n" );
}
if (keystates[SDL_SCANCODE_LEFT])
{
    printf( "On as pas cancel l'escaton!\n" );
}
if (keystates[SDL_SCANCODE_RIGHT])
{
    printf( "Duel de regard avec un cailloux\n" );
}
}

Uint32 frame_rate = 20 ;
int main(){
    MainSDLWindow win_s;
    bool quit = false ;
    SDL_Event e ;
    win_s.Init("title", 800, 800);
     //While application is running
     int frame_time_interval;
            while( !quit )
            {
                Uint32 frame_time_start = SDL_GetTicks();
                keyboard();
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
             
                }
                frame_time_interval = SDL_GetTicks() - frame_time_start;
                SDL_Delay(frame_rate-frame_time_interval);
            }
 return EXIT_SUCCESS;
}
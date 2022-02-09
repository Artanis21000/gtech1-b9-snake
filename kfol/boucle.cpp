#include "boucle.hpp"
#include "snake.hpp"
#include "constante.hpp"
#include "fruit.hpp"

using namespace std;

#define MOVECASE 10

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

int move(int dir)
{
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    int new_dir = dir;
    if (keystates[SDL_SCANCODE_UP])
    {
       new_dir = UP;
    }
    if (keystates[SDL_SCANCODE_DOWN])
    {
        new_dir = DOWN;
    }
    if (keystates[SDL_SCANCODE_LEFT])
    {
        new_dir = LEFT;
    }
    if (keystates[SDL_SCANCODE_RIGHT])
    {
       new_dir = RIGHT;
    }
    return (dir == -new_dir) ? dir : new_dir;
}

Uint32 frame_rate = 20 ;
int main()
{
    MainSDLWindow win_s;
    generateFruit();
    win_s.Init("title",800,800);
    SDL_Rect rectangle = {snakeX,snakeY,20,20};
    rectangle.w =32;
    rectangle.h =32;
    bool quit = false ;
    SDL_Event e ;
    int dir = DOWN;

    //While application is running
    int frame_time_interval;
    while( !quit )
    {
        Uint32 frame_time_start = SDL_GetTicks();
        dir = move(dir);
        switch(dir)
        {
        case UP:
            rectangle.y--;
            break;
        case DOWN:
            rectangle.y++;
            break;
        case LEFT:
            rectangle.x--;
            break;
        case RIGHT:
            rectangle.x++;
            break;        
        }

        SDL_SetRenderDrawColor(win_s.GetRenderer(), 0,  0 , 0, 255);
        SDL_RenderClear(win_s.GetRenderer());
        SDL_SetRenderDrawColor(win_s.GetRenderer(), 255,  255 , 255, 255);
        SDL_RenderFillRect(win_s.GetRenderer(),&rectangle);
        SDL_Rect fruit = {fruitX,fruitY,15,15};
        SDL_SetRenderDrawColor(win_s.GetRenderer(), 255,  0 , 0, 0);
        SDL_RenderFillRect (win_s.GetRenderer(), &fruit);

        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        SDL_RenderPresent(win_s.GetRenderer());
        frame_time_interval = SDL_GetTicks() - frame_time_start;
        if (frame_time_interval < frame_rate)
            SDL_Delay(frame_rate - frame_time_interval);    
    }
    return EXIT_SUCCESS;
}
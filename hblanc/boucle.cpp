#include "fruit.hpp"

using namespace std;

#define MOVECASE 10

//laisser cest le main
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
        SDL_SetRenderDrawColor(win_s.GetRenderer(), 255,  0 , 0, 255);
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
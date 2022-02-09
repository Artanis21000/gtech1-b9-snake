#include"window.hpp"
#include"move.hpp"
#include"snake.hpp"
#include"segment.hpp"
#include"fruit.hpp"
#include"eat.hpp"
using namespace std;
#define MOVECASE 10

int test_collide_fruit_head(int xf, int yf, int sizef, int xh, int yh, int sizeh) {
  return
    // X tests:                                                                                                                                   
    xf <= xh + sizeh && xf + sizef >= xh &&
    // Y tests:                                                                                                                                   
    yf <= yh + sizeh && yf + sizef >= yh;
}

//laisser cest le main
Uint32 frame_rate = 20 ;
int main()
{
    MainSDLWindow win_s;
    generateFruit();
    win_s.Init("title",640,640);
    SDL_Rect head = {400,400,20,20};
    head.w = 32;
    head.h = 32;
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
            head.y--;
            break;
        case DOWN:
            head.y++;
            break;
        case LEFT:
            head.x--;
            break;
        case RIGHT:
            head.x++;
            break;        
        }


        if (test_collide_fruit_head(xf, yf, 15, head.x, head.y, head.w))
        {
            quit = 1;
        }
  

        SDL_SetRenderDrawColor(win_s.GetRenderer(), 0,  0 , 0, 255);
        SDL_RenderClear(win_s.GetRenderer());
        SDL_SetRenderDrawColor(win_s.GetRenderer(), 255,  255 , 255, 255);
        SDL_RenderFillRect(win_s.GetRenderer(),&head);
        SDL_Rect fruit = {xf,yf,15,15};
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
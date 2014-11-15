
#include <iostream>
#include <cstdlib>
#include <SDL.h>


int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if(win == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
    if(ren == nullptr)
    {
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    SDL_Rect rect = {100, 100, 100, 100};
    SDL_Rect rect2 = {100, 150, 100, 100};
    SDL_SetRenderDrawBlendMode(ren, SDL_BlendMode::SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
    SDL_RenderFillRect(ren, &rect2);
    SDL_SetRenderDrawColor(ren, 255, 0, 255, 0x77);
    SDL_RenderFillRect(ren, &rect);
    SDL_RenderPresent(ren);
    
    system("pause");
    return 0;
}
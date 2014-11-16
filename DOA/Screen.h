#pragma once

#include <SDL.h>

class Screen
{
    SDL_Renderer* renderer;
public:
    Screen();
    ~Screen();

    void setRenderer(SDL_Renderer* renderer);
    void draw();
};


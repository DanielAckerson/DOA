#include "Screen.h"


Screen::Screen()
{
}


Screen::~Screen()
{
}


void Screen::setRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}


void Screen::draw()
{
    if(renderer != nullptr)
    {
        //draw things
    }
}
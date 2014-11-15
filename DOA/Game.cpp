#include "Game.h"
#include <iostream>
#include <exception>

Game::Game()
    :
    running(true)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        throw std::exception("Could not initialize SDL");
    }
    window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if(window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        throw std::exception("Could not create SDL window");
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr)
    {
        SDL_DestroyWindow(window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        throw std::exception("Could not create SDL renderer");
    }
    screen.setRenderer(renderer);
}


Game::~Game()
{
    saveGameState();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void Game::tick()
{

}


void Game::draw()
{

}



void Game::handleEvent(SDL_Event& event)
{
    switch(event.type)
    {
    case SDL_QUIT:
        stop();
    }
}


void Game::saveGameState()
{

}


void Game::stop()
{
    running = false;
}


bool Game::isRunning()
{
    return running;
}

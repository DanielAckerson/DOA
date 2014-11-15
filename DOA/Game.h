#pragma once

#include <SDL.h>
#include <memory>

#include "Screen.h"
#include "GameState.h"

class Game
{
    SDL_Window* window;
    SDL_Renderer* renderer;

    Screen screen;
    std::unique_ptr<GameState> gameState; //needs initialization

    bool running;

    //int fps;
    //int tps;

public:
    Game();
    ~Game();

    void tick();
    void draw();
    void handleEvent(SDL_Event& event);

    //void setTickPerSecond(int tps);
    //void getTicksPerSecond();
    //void getFramesPerSecond();
    void saveGameState();
    void stop();
    bool isRunning();
};


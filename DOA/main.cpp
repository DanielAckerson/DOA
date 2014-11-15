
#include <iostream>
#include <chrono>
#include <SDL.h>

#include "Game.h"


int main(int argc, char* argv[])
{
    Game game;
    SDL_Event event;
    
    {
        using namespace std::chrono;
        typedef high_resolution_clock HRClock;
        auto lastTime = HRClock::now();
        auto timer = lastTime;
        const double ns = 1000000000.0 / 60.0;
        double delta = 0;
        int frames = 0;
        int ticks = 0;
        while(game.isRunning())
        {
            auto now = HRClock::now();
            delta += duration_cast<nanoseconds>(now - lastTime).count() / ns;
            lastTime = now;
            
            while(SDL_PollEvent(&event))
            {
                game.handleEvent(event);
            }

            while(delta >= 1)
            {
                game.tick();
                ticks++;
                delta--;
            }
            game.draw();
            frames++;

            if(duration_cast<milliseconds>(HRClock::now() - timer).count() > 1000)
            {
                timer += milliseconds{1000};

                //game.SetFramesPerSecond(frames);
                //game.setTicksPerSecond(ticks);
                ticks = 0;
                frames = 0;
            }
        }
    }
    return 0;
}
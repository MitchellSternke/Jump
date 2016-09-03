#include <SDL2/SDL.h>

#include "Sdl2InputManager.hpp"

Sdl2InputManager::Sdl2InputManager() :
    shutdownReceivedFlag(false)
{
}

bool Sdl2InputManager::shutdownReceived() const
{
    return shutdownReceivedFlag;
}

void Sdl2InputManager::update()
{
    // Poll SDL events
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_ESCAPE:
                shutdownReceivedFlag = true;
                break;
            default:
                break;
            }
            break;

        case SDL_QUIT:
            shutdownReceivedFlag = true;
            break;

        default:
            break;
        }
    }
}

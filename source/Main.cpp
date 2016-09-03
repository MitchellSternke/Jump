#include <iostream>

#include <SDL2/SDL.h>

#include "input/sdl2/Sdl2InputManager.hpp"
#include "video/sdl2/Sdl2VideoManager.hpp"

#define WINDOW_RESOLUTION_X 640
#define WINDOW_RESOLUTION_Y 480
#define SCREEN_RESOLUTION_X 320
#define SCREEN_RESOLUTION_Y 240

static SDL_Window* window = NULL;

/**
 * Clean up al resources used by libraries.
 */
static void cleanup()
{
    SDL_Quit();
}

/**
 * Initialize all libraries for use.
 *
 * @return 0 for success, error codes otherwise.
 */
static int initialize()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Error: Failed to initialize SDL\nDetails:\n" << SDL_GetError() << std::endl;
        return -1;
    }

    // Create the main window
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    window = SDL_CreateWindow(
        "Jump",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_RESOLUTION_X,
        WINDOW_RESOLUTION_Y,
        SDL_WINDOW_OPENGL
    );
    if (window == NULL)
    {
        std::cout << "Error: Failed to create the SDL_Window\nDetails:\n" << SDL_GetError() << std::endl;
        return -1;
    }

    // Create the OpenGL context
    if (SDL_GL_CreateContext(window) == NULL)
    {
        std::cout << "Error: Failed to create the OpenGL context\nDetails:\n" << SDL_GetError() << std::endl;
        return -1;
    }

    // Success
    return 0;
}

/**
 * Program entry point.
 */
int main(int argc, char** argv)
{
    try
    {
        if (initialize() != 0)
        {
            std::cout << "Error: initialize() failed\n";
            cleanup();
            return -1;
        }
        else
        {
            Sdl2VideoManager videoManager(window, SCREEN_RESOLUTION_X, SCREEN_RESOLUTION_Y);
            Sdl2InputManager inputManager;
            while (!inputManager.shutdownReceived())
            {
                inputManager.update();
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Error: Unhandled exception caught in main():\n" << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Error: Unknown exception caught in main()\n";
    }

    cleanup();

    return 0;
}

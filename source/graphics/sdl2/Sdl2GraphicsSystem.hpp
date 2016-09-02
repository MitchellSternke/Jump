#ifndef SDL2GRAPHICSSYSTEM_HPP
#define SDL2GRAPHICSSYSTEM_HPP

#include <SDL2/SDL.h>

#include "../GraphicsSystem.hpp"

/**
 * Graphics system powered by SDL2/OpenGL.
 */
class Sdl2GraphicsSystem : public GraphicsSystem
{
public:
    /**
     * Constructor.
     *
     * @param window the window to render to.
     * @param virtualScreenWidth the width of the virtual screen, in pixels.
     * @param virtualScreenHeight the height of the virtual screen, in pixels.
     */
    Sdl2GraphicsSystem(SDL_Window* window, int virtualScreenWidth, int virtualScreenHeight);

    void clearScreen();
    void drawRectangle(int x, int y, int width, int height);
    void updateScreen();

private:
    SDL_Window* window;
    int screenWidth;
    int screenHeight;
};

#endif // SDL2GRAPHICSSYSTEM_HPP

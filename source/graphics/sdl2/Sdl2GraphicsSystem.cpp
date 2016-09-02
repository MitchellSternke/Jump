#include <SDL2/SDL_opengl.h>

#include "Sdl2GraphicsSystem.hpp"

Sdl2GraphicsSystem::Sdl2GraphicsSystem(SDL_Window* window, int virtualScreenWidth, int virtualScreenHeight) :
    window(window),
    screenWidth(virtualScreenWidth),
    screenHeight(virtualScreenHeight)
{
}

void Sdl2GraphicsSystem::clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, screenWidth, screenHeight, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Sdl2GraphicsSystem::drawRectangle(int x, int y, int width, int height)
{
    glColor3ub(0xff, 0xff, 0xff);
    glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x + width, y);
        glVertex2i(x + width, y + height);
        glVertex2i(x, y + height);
    glEnd();
}

void Sdl2GraphicsSystem::updateScreen()
{
    SDL_GL_SwapWindow(window);
}

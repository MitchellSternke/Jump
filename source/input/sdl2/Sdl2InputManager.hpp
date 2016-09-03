#ifndef SDL2INPUTMANAGER_HPP
#define SDL2INPUTMANAGER_HPP

#include "../InputManager.hpp"

/**
 * Input manager using SDL2.
 */
class Sdl2InputManager : public InputManager
{
public:
    Sdl2InputManager();

    bool shutdownReceived() const;
    void update();

private:
    bool shutdownReceivedFlag;
};

#endif // SDL2INPUTMANAGER_HPP

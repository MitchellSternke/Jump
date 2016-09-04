#include "InputListener.hpp"
#include "InputManager.hpp"

void InputManager::addListener(InputListener* listener)
{
    listeners.push_back(listener);
}

void InputManager::notifyButtonPress(InputButton buttonId)
{
    for (auto listener : listeners)
    {
        listener->onButtonPress(buttonId);
    }
}

void InputManager::removeListener(InputListener* listener)
{
    listeners.remove(listener);
}

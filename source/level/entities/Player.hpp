#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Entity.hpp"
#include "../../input/InputListener.hpp"

/**
 * A user-controlled player.
 */
class Player : public Entity, public InputListener
{
public:
    Player();

private:
    void onButtonPress(InputButton buttonId);
    void onUpdate();
};

#endif // PLAYER_HPP

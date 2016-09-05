#include "../../input/InputManager.hpp"

#include "Player.hpp"

Player::Player()
{
    setAccelerationY(0.5f);
}

void Player::onButtonPress(InputButton buttonId)
{
    if (buttonId == InputButton::A)
    {
        setVelocityY(-10.0f);
    }
}

void Player::onUpdate()
{
    InputManager& input = InputManager::getInstance();
    if (input.isButtonPressed(InputButton::LEFT))
    {
        setVelocityX(-3.0f);
    }
    else if (input.isButtonPressed(InputButton::RIGHT))
    {
        setVelocityX(3.0f);
    }
    else
    {
        setVelocityX(0.0f);
    }

}

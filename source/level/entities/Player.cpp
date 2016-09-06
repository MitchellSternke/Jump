#include <cmath>

#include "../../input/InputManager.hpp"

#include "Player.hpp"

Player::Player() :
    directionSign(1),
    maxAirVelocityX(MAX_WALKING_VELOCITY)
{
}

void Player::onButtonPress(InputButton buttonId)
{
    if (buttonId == InputButton::A)
    {
        // Jump if we are on the ground
        if (isOnGround())
        {
            float velocityX = std::fabs(getVelocityX());
            if (velocityX > JUMP_VELOCITY_THRESHOLD_3)
            {
                setVelocityY(-1 * JUMP_VELOCITY_3);
            }
            else if (velocityX > JUMP_VELOCITY_THRESHOLD_2)
            {
                setVelocityY(-1 * JUMP_VELOCITY_2);
            }
            else
            {
                setVelocityY(-1 * JUMP_VELOCITY_1);
            }
            setAccelerationY(JUMP_GRAVITY_1);
        }
    }
}

void Player::onUpdate()
{
    InputManager& input = InputManager::getInstance();

    // Determine which direction we are facing
    bool stopping = false;
    if (input.isButtonPressed(InputButton::LEFT))
    {
        directionSign = -1;
    }
    else if (input.isButtonPressed(InputButton::RIGHT))
    {
        directionSign = 1;
    }
    else
    {
        stopping = true;
    }

    if (isOnGround())
    {
        // Cap x velocity
        float maximumVelocityX = MAX_WALKING_VELOCITY;
        if (input.isButtonPressed(InputButton::B))
        {
            maximumVelocityX = MAX_RUNNING_VELOCITY;
        }
        if (std::fabs(getVelocityX()) > maximumVelocityX)
        {
            setVelocityX(maximumVelocityX * sgn(getVelocityX()));
        }

        // Store our momentum as the max velocity when we become airborne again
        maxAirVelocityX = maximumVelocityX;
    }
    else // In the air physics
    {
        // Cap x velocity
        if (std::fabs(getVelocityX() > maxAirVelocityX))
        {
            setVelocityX(maxAirVelocityX * sgn(getVelocityX()));
        }
    }

    // Determine x acceleration
    if (stopping)
    {
        if (std::fabs(getVelocityX()) > STOP_DECELERATION)
        {
            setAccelerationX(-1 * sgn(getVelocityX()) * STOP_DECELERATION);
        }
        else
        {
            setAccelerationX(0);
            setVelocityX(0);
        }
    }
    else if (directionSign != sgn(getVelocityX()))
    {
        setAccelerationX(directionSign * SKID_DECELERATION);
    }
    else
    {
        setAccelerationX(directionSign * RUN_ACCELERATION);
    }

    // Cap y velocity
    if (getVelocityY() > MAX_DOWNWARD_VELOCITY)
    {
        setVelocityY(MAX_DOWNWARD_VELOCITY);
    }

    // Determine gravity (y acceleration)
    if (input.isButtonPressed(InputButton::A) && getVelocityY() < JUMP_GRAVITY_THRESHOLD_2)
    {
        setAccelerationY(JUMP_GRAVITY_1);
    }
    else
    {
        setAccelerationY(JUMP_GRAVITY_2);
    }
}

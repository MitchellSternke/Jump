#include <cmath>

#include "Entity.hpp"
#include "Level.hpp"

Entity::Entity() :
    width(Level::TILE_SIZE),
    height(Level::TILE_SIZE),
    positionX(0.0f),
    positionY(0.0f),
    velocityX(0.0f),
    velocityY(0.0f),
    accelerationX(0.0f),
    accelerationY(0.0f)
{
}

int Entity::getBottom() const
{
    return getY() + height - 1;
}

int Entity::getCenterX() const
{
    return getX() + width / 2;
}

int Entity::getCenterY() const
{
    return getY() + height / 2;
}

int Entity::getLeft() const
{
    return getX();
}

int Entity::getRight() const
{
    return getX() + width - 1;
}

int Entity::getTop() const
{
    return getY();
}

int Entity::getX() const
{
    return static_cast<int>(std::floor(positionX));
}

int Entity::getY() const
{
    return static_cast<int>(std::floor(positionY));
}

void Entity::setAccelerationX(float ax)
{
    accelerationX = ax;
}

void Entity::setAccelerationY(float ay)
{
    accelerationY = ay;
}

void Entity::setVelocityX(float vx)
{
    velocityX = vx;
}

void Entity::setVelocityY(float vy)
{
    velocityY = vy;
}

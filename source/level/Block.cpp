#include <cmath>

#include "Block.hpp"
#include "Level.hpp"

Block::Block(Block::CollisionType collisionType) :
    collisionType(collisionType),
    width(1),
    height(1)
{
}

int Block::getBottom() const
{
    return getY() + getHeight() - 1;
}

int Block::getHeight() const
{
    return height * Level::TILE_SIZE;
}

int Block::getLeft() const
{
    return getX();
}

int Block::getRight() const
{
    return getX() + getWidth() - 1;
}

int Block::getTop() const
{
    return getY();
}

int Block::getWidth() const
{
    return width * Level::TILE_SIZE;
}

int Block::getX() const
{
    return positionX * Level::TILE_SIZE;
}

int Block::getY() const
{
    return positionY * Level::TILE_SIZE;
}

bool Block::hasBottomCollision(int x, int y) const
{
    return (collisionType == CollisionType::SOLID);
}

bool Block::hasLeftCollision(int x, int y) const
{
    return (collisionType == CollisionType::SOLID);
}

bool Block::hasRightCollision(int x, int y) const
{
    return (collisionType == CollisionType::SOLID);
}

bool Block::hasTopCollision(int x, int y) const
{
    switch (collisionType)
    {
    case CollisionType::PLATFORM:
        return (y == 0);
    case CollisionType::SLOPE_LEFT:
        {
            int h = static_cast<int>(std::floor(
                (static_cast<float>(height) / static_cast<float>(width)) *
                (x + 0.5f)
            ));
            return (y == h);
        }
    case CollisionType::SLOPE_RIGHT:
        {
            int h = static_cast<int>(std::floor(
                -1.0f * (static_cast<float>(height) / static_cast<float>(width)) *
                (x + 0.5f) + (height * Level::TILE_SIZE)
            ));
            return (y == h);
        }
    case CollisionType::SOLID:
        return true;

    default:
        return false;
    }
}

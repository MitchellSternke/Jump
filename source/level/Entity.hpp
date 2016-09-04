#ifndef ENTITY_HPP
#define ENTITY_HPP

/**
 * A dynamic, moving object in a Level.
 */
class Entity
{
    friend class Level;
public:
    Entity();
    virtual ~Entity() {}

    /**
     * Get the bottom y coordinate of the entity's bounding box, in pixels.
     */
    int getBottom() const;

    /**
     * Get the center x coordinate of the entity's bounding box, in pixels.
     */
    int getCenterX() const;

    /**
     * Get the center y coordinate of the entity's bounding box, in pixels.
     */
    int getCenterY() const;

    /**
     * Get the left x coordinate of the entity's bounding box, in pixels.
     */
    int getLeft() const;

    /**
     * Get the right x coordinate of the entity's bounding box, in pixels.
     */
    int getRight() const;

    /**
     * Get the top y coordinate of the entity's bounding box, in pixels.
     */
    int getTop() const;

    /**
     * Get the x position of the enity, in pixels.
     */
    int getX() const;

    /**
     * Get the y position of the entity, in pixels.
     */
    int getY() const;

    /**
     * Set the x acceleration of an entity.
     */
    void setAccelerationX(float ax);

    /**
     * Set the y acceleration of an entity.
     */
    void setAccelerationY(float ay);

    /**
     * Set the x velocity of an entity.
     */
    void setVelocityX(float vx);

    /**
     * Set the y velocity of an entity.
     */
    void setVelocityY(float vy);

protected:
    /**
     * Update event called every frame.
     */
    virtual void onUpdate() {}

private:
    int width;  /**< Width, in pixels. */
    int height; /**< Height, in pixels. */
    float positionX; /**< X position, in pixels. */
    float positionY; /**< Y position, in pixels. */
    float velocityX; /**< X velocity, in pixels/frame. */
    float velocityY; /**< Y velocity, in pixels/frame. */
    float accelerationX; /**< X acceleration, in pixels/frame/frame. */
    float accelerationY; /**< Y acceleration, in pixels/frame/frame. */
};

#endif // ENTITY_HPP

#ifndef VIDEOMANAGER_HPP
#define VIDEOMANAGER_HPP

/**
 * Interface for graphical routines.
 */
class VideoManager
{
public:
    virtual ~VideoManager() {}

    /**
     * Clear the screen.
     */
    virtual void clearScreen()=0;

    /**
     * Draw a solid rectangle.
     *
     * @param x the left coordinate.
     * @param y the top coordinate.
     * @param width the width of the rectangle.
     * @param height the height of the rectangle.
     */
    virtual void drawRectangle(int x, int y, int width, int height)=0;

    /**
     * Render any changes to the screen.
     */
    virtual void updateScreen()=0;
};

#endif // VIDEOMANAGER_HPP

#ifndef LEVELSTATE_HPP
#define LEVELSTATE_HPP

#include "../GameState.hpp"

class Level;

/**
 * Game state that manages playing levels of the game.
 */
class LevelState : public GameState
{
public:
    /**
     * Constructor.
     */
    LevelState();
    ~LevelState();

private:
    Level* level;

    void onRender(VideoManager& video) const;
    void onUpdate();
};

#endif // LEVELSTATE_HPP

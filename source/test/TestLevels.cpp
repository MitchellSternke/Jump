#include "../level/Block.hpp"
#include "../level/Layer.hpp"
#include "../level/Level.hpp"

#include "TestLevels.hpp"

Level* createTestLevel()
{
    Level* level = new Level();

    // Main layer
    Layer* mainLayer = new Layer(256, 15);
    for (int x = 0; x < 256; x++)
    {
        mainLayer->addBlock(x, 14, new Block(Block::CollisionType::SOLID));
    }
    mainLayer->addBlock(5, 13, new Block(Block::CollisionType::SLOPE_RIGHT));
    mainLayer->addBlock(6, 13, new Block(Block::CollisionType::SLOPE_LEFT));
    mainLayer->addBlock(9, 10, new Block(Block::CollisionType::SOLID));

    level->addLayer(mainLayer);

    return level;
}

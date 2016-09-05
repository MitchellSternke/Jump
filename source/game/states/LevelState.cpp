#include <cmath>

#include "../../input/InputManager.hpp"
#include "../../level/Block.hpp"
#include "../../level/Entity.hpp"
#include "../../level/Layer.hpp"
#include "../../level/Level.hpp"
#include "../../level/entities/Player.hpp"
#include "../../video/VideoManager.hpp"

#include "LevelState.hpp"

static Entity* entity;
static Layer* layer;
static Layer* layer2;
static Layer* layer3;
static Player* player;

LevelState::LevelState()
{
    level = new Level();
    layer = new Layer(40, 15);
    for (int x = 0; x < 40; x++)
    {
        layer->addBlock(x, 8, new Block(Block::CollisionType::PLATFORM));
    }
    Block* block = new Block(Block::CollisionType::SLOPE_RIGHT);
    block->setWidth(2);
    layer->addBlock(4, 7, block);
    block = new Block(Block::CollisionType::SLOPE_LEFT);
    block->setWidth(3);
    layer->addBlock(6, 7, block);
    layer->addBlock(0, 7, new Block(Block::CollisionType::SLOPE_LEFT));
    layer->addBlock(10, 7, new Block(Block::CollisionType::SLOPE_RIGHT));
    layer->addBlock(11, 6, new Block(Block::CollisionType::SLOPE_RIGHT));
    layer->addBlock(12, 6, new Block(Block::CollisionType::SLOPE_LEFT));
    layer->addBlock(13, 7, new Block(Block::CollisionType::SLOPE_LEFT));
    level->addLayer(layer);

    layer2 = new Layer(1, 15);
    for (int y = 0; y < 15; y++)
    {
        layer2->addBlock(0, y, new Block(Block::CollisionType::SOLID));
    }
    level->addLayer(layer2);
    layer2->setX(-100.0f);

    layer3 = new Layer(1, 15);
    for (int y = 0; y < 15; y++)
    {
        layer3->addBlock(0, y, new Block(Block::CollisionType::SOLID));
    }
    level->addLayer(layer3);
    layer3->setX(240.0f);

    entity = new Entity();
    entity->setAccelerationY(0.125f);
    //level->addEntity(entity);

    player = new Player();
    InputManager::getInstance().addListener(player);
    level->addEntity(player);
}

LevelState::~LevelState()
{
    delete level;
}

void LevelState::onRender(VideoManager& video) const
{
    level->render(video, 0, video.getScreenWidth(), 0, video.getScreenHeight());
}

void LevelState::onUpdate()
{
    static int counter = 0;

    counter++;
    layer->setVelocityX(std::cos(counter / 49.0f) * -2.0f);
    layer->setVelocityY(std::sin(counter / 15.0f));
    //layer2->setVelocityX(std::cos(counter / 60.0f) * 6.0f);
    //layer3->setVelocityX(std::sin(counter / 31.0f) * 2.0f);

    entity->setVelocityX(0.5f);

    level->update();
}

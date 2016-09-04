#include <cmath>

#include "../../level/Block.hpp"
#include "../../level/Entity.hpp"
#include "../../level/Layer.hpp"
#include "../../level/Level.hpp"
#include "../../video/VideoManager.hpp"

#include "LevelState.hpp"

static Entity* entity;
static Layer* layer;
static Layer* layer2;
static Layer* layer3;

LevelState::LevelState()
{
    level = new Level();
    layer = new Layer(20, 15);
    for (int x = 0; x < 20; x++)
    {
        layer->addBlock(x, 8, new Block(Block::CollisionType::SOLID));
    }
    layer->addBlock(10, 7, new Block(Block::CollisionType::SLOPE_RIGHT));
    layer->addBlock(11, 6, new Block(Block::CollisionType::SLOPE_RIGHT));
    level->addLayer(layer);

    layer2 = new Layer(1, 15);
    for (int y = 0; y < 15; y++)
    {
        layer2->addBlock(0, y, new Block(Block::CollisionType::SOLID));
    }
    level->addLayer(layer2);
    layer2->setX(-60.0f);

    layer3 = new Layer(1, 15);
    for (int y = 0; y < 15; y++)
    {
        layer3->addBlock(0, y, new Block(Block::CollisionType::SOLID));
    }
    level->addLayer(layer3);
    layer3->setX(160.0f);

    entity = new Entity();
    entity->setAccelerationY(0.125f);
    level->addEntity(entity);
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
    layer->setVelocityX(std::cos(counter++ / 45.0f) * 2.0f);
    layer->setVelocityY(std::sin(counter++ / 30.0f));
    layer2->setVelocityX(std::sin(counter++ / 60.0f) * 6.0f);
    layer3->setVelocityX(std::sin(counter++ / 120.0f) * 3.0f);

    entity->setVelocityX(0.5f);

    level->update();
}

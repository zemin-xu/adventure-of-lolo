//
//  GraphicController.cpp
//  SFML
//
//  Created by ZEMIN on 15/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "GraphicController.hpp"


GraphicController::GraphicController() 
{
    ReadTextureFile();
    // length and height of program here
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            // background
            Element backgroundUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureBG, 1, 1, false);
            background.push_back(backgroundUnit);
            
            // obstacles
            if(map.level[i][j] == 1)
            {
                Element obstacleUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureObstacle,1,1, true);
                obstacles.push_back(obstacleUnit);
            }
            
            // collectable
            if(map.level[i][j] == 2)
            {
                Collectable collectableUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureCollectable ,1,1, false);
                collectables.push_back(collectableUnit);
            }
            
            // player
            if(map.level[i][j] == 3)
            {
                player = Player(j * LENGTH_UNIT,i * LENGTH_UNIT,LENGTH_UNIT, HEIGHT_UNIT, &texturePlayer, ANIM_PLAYER_NUM_HORIZONTAL, ANIM_PLAYER_NUM_VERTICAL, true);
            }
            
            // movable
            if(map.level[i][j] == 4)
            {
                Movable movableUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureMovable ,1,1, true);
                movables.push_back(movableUnit);
            }
            
            // enemy
            if(map.level[i][j] == 5)
            {
                Enemy enemyUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureEnemy ,1,1, true);
                enemies.push_back(enemyUnit);
            }
            
            
        }
    }
   
    
    
}

void GraphicController::ReadTextureFile()
{
    if (!texturePlayer.loadFromFile("Sources/player.png"))
        return ;
    if (!textureEnemy.loadFromFile("Sources/player.png"))
        return ;
    if (!textureBG.loadFromFile("Sources/sable.jpg"))
        return ;
    if (!textureObstacle.loadFromFile("Sources/obstacle.png"))
        return ;
    if (!textureCollectable.loadFromFile("Sources/coin.png"))
        return ;
    if (!textureMovable.loadFromFile("Sources/obstacle.png"))
    return ;
}

void GraphicController::Update(const float deltaTime)
{
    player.Update(deltaTime, map, collectables, movables);
}



void GraphicController::Render(sf::RenderWindow &window)
{

    for (int i = 0; i < background.size(); i++)
    {
        background[i].Render(window);
    }
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i].Render(window);
    }
    for (int i = 0; i < collectables.size(); i++)
    {
        if (collectables[i].GetIsActive())
        {
            collectables[i].Render(window);
        }
    }
    for (int i = 0; i < movables.size(); i++)
    {
        movables[i].Render(window);
    }
   
    player.Render(window);
    
    // collision detect, from one to another,
    // from the active to the passive
    // when the active move, detect around,
    
    // player -> movable -> obs

    
}

InputController::InputController()
{
    
}

void InputController::UpdateInput(Player &player)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        player.state = Creature::Backward_M;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        player.state = Creature::Forward_M;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        player.state = Creature::Leftward_M;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        player.state = Creature::Rightward_M;
}

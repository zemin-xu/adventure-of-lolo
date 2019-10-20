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
    
    /* text init */
    title.setFont(font);
    title.setString("LOLO");
    title.setCharacterSize(24);
    title.setPosition(14.2f * LENGTH_UNIT, 2 * HEIGHT_UNIT);
    
    textLife.setFont(font);
    textLife.setCharacterSize(24);
    textLife.setPosition(15.2f * LENGTH_UNIT, 4.0f * HEIGHT_UNIT);

    textWeapon.setFont(font);
    textWeapon.setCharacterSize(24);
    textWeapon.setPosition(15.2f * LENGTH_UNIT, 5.5f * HEIGHT_UNIT);
    
    
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            // background
            if(j >= 1 && j < 14)
            {
                Element backgroundUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureBG, 1, 1, false);
                background.push_back(backgroundUnit);
            }
            
            // obstacles
            if(map.level[i][j] == 2)
            {
                Element obstacleUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureObstacle,1,1, true);
                obstacles.push_back(obstacleUnit);
            }
            
            // collectable
            if(map.level[i][j] == 3)
            {
                Collectable collectableUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureCollectable ,1,1, false);
                collectables.push_back(collectableUnit);
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
            
            player = Player(8 * LENGTH_UNIT,6 * LENGTH_UNIT,LENGTH_UNIT, HEIGHT_UNIT, &texturePlayer, ANIM_PLAYER_NUM_HORIZONTAL, ANIM_PLAYER_NUM_VERTICAL, true);
            
            uiLife = Element(14.0f * LENGTH_UNIT, 4 * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureUI, 1,1, true);
            uiWeapon = Element(14.0f * LENGTH_UNIT, 5.5f * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureUI, 1,1, true);
            
        }
    }
   
    
    
}

void GraphicController::ReadTextureFile()
{
    if (!font.loadFromFile("Sources/karma_future.ttf"))
    return ;
    
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
    if (!textureUI.loadFromFile("Sources/coin.png"))
    return ;
}

void GraphicController::Update(const float deltaTime)
{
    player.Update(deltaTime, map, collectables, movables);
    
    /* text update, will be placed in a condition when they change */
    textLife.setString(to_string(player.GetLifePoint()));
    textWeapon.setString(to_string(player.GetWeaponPoint()));
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
    
    uiLife.Render(window);
    uiWeapon.Render(window);
    
    window.draw(title);
    window.draw(textLife);
    window.draw(textWeapon);

    
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

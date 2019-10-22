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
                Element backgroundUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureBG, 1, 1, 11);
                
                background.push_back(backgroundUnit);
            }
            
            // obstacles
            if(map.level[i][j] / 10 == 2)
            {
                Element obstacleUnit;
                if (map.level[i][j] == 22)
                    obstacleUnit = Element(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureOuterWall,1,1, 22);
                else if (map.level[i][j] == 24)
                obstacleUnit = Element(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureClosedDoor,1,1, 24);
                else if (map.level[i][j] == 21)
                    obstacleUnit = Element(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureObstacle1,1,1, 21);
                else if (map.level[i][j] == 23)
                    obstacleUnit = Element(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureObstacle2,1,1, 23);
                obstacles.push_back(obstacleUnit);
                
            }
            
            
            // collectable
            if (map.level[i][j] / 10 == 3)
            {
                Collectable collectableUnit;
                if (map.level[i][j] == 31)
                    collectableUnit = Collectable(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureCollectable ,1,1, 31);
                cout << collectableUnit.kind << endl;
                collectables.push_back(collectableUnit);
            }
            
            // movable
            if(map.level[i][j] / 10 == 4)
            {
                Movable movableUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureMovable ,1,1, 41);
                
                movables.push_back(movableUnit);
                
            }
            
            // enemy
            if(map.level[i][j] == 51)
            {
                Enemy enemyUnit(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureEnemy ,ANIM_ENEMY1_NUM_HORIZONTAL, ANIM_ENEMY1_NUM_VERTICAL, 51);
                enemies.push_back(enemyUnit);
            }
            
            if(map.level[i][j] == 13)
                keyBox = Element(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureClosedKeyBox, 1, 1, 13);
            
            if(map.level[i][j] == 24)
                door = Element(j * LENGTH_UNIT, i * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureClosedDoor, 1, 1, 24);
            
            if(map.level[i][j] == 71)
                player = Player(8 * LENGTH_UNIT,6 * LENGTH_UNIT,LENGTH_UNIT, HEIGHT_UNIT, &texturePlayer, ANIM_PLAYER_NUM_HORIZONTAL, ANIM_PLAYER_NUM_VERTICAL, 71);
        }
    }
    
    uiLife = Element(14.0f * LENGTH_UNIT, 4 * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureUI, 1,1, 11);
    uiWeapon = Element(14.0f * LENGTH_UNIT, 5.5f * HEIGHT_UNIT, LENGTH_UNIT, HEIGHT_UNIT, &textureUI, 1,1, 11);
   
    
    
}

void GraphicController::ReadTextureFile()
{
    if (!font.loadFromFile("Sources/karma_future.ttf"))
    return ;
    
    if (!texturePlayer.loadFromFile("Sources/player.png"))
        return ;
    if (!textureEnemy.loadFromFile("Sources/enemy.png"))
        return ;
    if (!textureBG.loadFromFile("Sources/sable.jpg"))
        return ;
    if (!textureClosedKeyBox.loadFromFile("Sources/closed_key_box.png"))
    return ;
    if (!textureOuterWall.loadFromFile("Sources/outer_wall.jpg"))
        return ;
    if (!textureClosedDoor.loadFromFile("Sources/closed_door.png"))
    return ;
    if (!textureObstacle1.loadFromFile("Sources/obstacle1.png"))
        return ;
    if (!textureObstacle2.loadFromFile("Sources/obstacle2.png"))
        return ;
    if (!textureCollectable.loadFromFile("Sources/coin.png"))
        return ;
    if (!textureMovable.loadFromFile("Sources/movable.png"))
        return ;
    if (!textureUI.loadFromFile("Sources/coin.png"))
        return ;
}

void GraphicController::Update(const float deltaTime)
{
    player.Update(deltaTime, map, obstacles, collectables, movables);

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
    
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].Render(window);
    }
   
    
    keyBox.Render(window);
    door.Render(window);
    
    uiLife.Render(window);
    uiWeapon.Render(window);
    
    player.Render(window);
    
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

//
//  Level.cpp
//  SFML
//
//  Created by ZEMIN on 24/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

Level::Level()
{
    
}

Level::Level(int _currentLevel)
{
    ReadTextureFile();
    InitLevel(_currentLevel);
    playerLife = 5;
    playerWeapon = 0;
}

void Level::UpdateCurrentMap()
{
    currentMap.clear();
    heartLeft = 0;
    
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            coord a;
            a.x = j;
            a.y = i;
            if (currentLevel == 1)
                a.type = level1[i][j];
            else if (currentLevel == 2)
                a.type = level2[i][j];
            currentMap.push_back(a);
        }
    }
}

void Level::InitLevel(int level)
{
    currentLevel = level;
    heartLeft = 0;
    UpdateCurrentMap();
    
    background.clear();
    obstacles.clear();
    
    // the collectable vector and enemy vector should not be clear because it is clean already
    
    triggers.clear();
    
    /* text init */
    title.setFont(font);
    title.setString("LOLO");
    title.setCharacterSize(24);
    title.setPosition(14.2f * LIB::LENGTH_UNIT, 2 * LIB::HEIGHT_UNIT);
    
    textLife.setFont(font);
    textLife.setCharacterSize(24);
    textLife.setPosition(15.2f * LIB::LENGTH_UNIT, 4.0f * LIB::HEIGHT_UNIT);
    
    textWeapon.setFont(font);
    textWeapon.setCharacterSize(24);
    textWeapon.setPosition(15.2f * LIB::LENGTH_UNIT, 5.5f * LIB::HEIGHT_UNIT);
    
    uiLife = Element(14.0f * LIB::LENGTH_UNIT, 4 * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureUI, 1,1, 11);
    uiWeapon = Element(14.0f * LIB::LENGTH_UNIT, 5.5f * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureUI, 1,1, 11);
    
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            // background
            if(j >= 1 && j < 14)
            {
                Element backgroundUnit;
                if (currentMap[i * 16 + j].type == 12)
                    backgroundUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureBG2, 1, 1, 11);
                else
                    backgroundUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureBG, 1, 1, 11);
                background.push_back(backgroundUnit);
            }
            
            // obstacles
            if (currentMap[i * 16 + j].type / 10 == 2)
            {
                Element obstacleUnit;
                if (currentMap[i * 16 + j].type == 22)
                    obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureOuterWall,1,1, 22);
                else if (currentMap[i * 16 + j].type == 21)
                    obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureObstacle1,1,1, 21);
                else if (currentMap[i * 16 + j].type == 23)
                    obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureObstacle2,1,1, 23);
                else if (currentMap[i * 16 + j].type == 25)
                obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureObstacle3, 1, 1, 23);
                obstacles.push_back(obstacleUnit);
            }
            
            else if (currentMap[i * 16 + j].type / 10 == 3)
            {
                Collectable collectableUnit;
                if (currentMap[i * 16 + j].type == 31)
                {
                    collectableUnit = Collectable(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureCollectable ,1,1, 31);
                    heartLeft++;
               
                }
                
                collectables.push_back(collectableUnit);
            }
            
            
            // movable
            else if(currentMap[i * 16 + j].type == 41)
            {
                Movable movableUnit(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureMovable ,1,1, 41);
                movables.push_back(movableUnit);
            }
            
            // movable enemy
            else if(currentMap[i * 16 + j].type == 42)
            {
                MovableEnemy movableEnemyUnit(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureMovableEnemy, LIB::ANIM_ENEMY1_NUM_HORIZONTAL, LIB::ANIM_ENEMY1_NUM_VERTICAL, 42);
                
                movables.push_back(movableEnemyUnit);
            }
            
            
            
            // enemy
            else if(currentMap[i * 16 + j].type == 51)
            {
                Enemy enemyUnit(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureEnemy ,LIB::ANIM_ENEMY1_NUM_HORIZONTAL, LIB::ANIM_ENEMY1_NUM_VERTICAL, 51);
                enemies.push_back(enemyUnit);
            }
            
            
            else if(currentMap[i * 16 + j].type / 10 == 6)
            {
                Trigger triggerUnit;
                if (currentMap[i * 16 + j].type == 61)
                    triggerUnit = Trigger(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureClosedDoor ,1,1, 61);
                else if (currentMap[i * 16 + j].type == 62)
                    triggerUnit = Trigger(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureClosedKeyBox ,1,1, 62);
                
                triggers.push_back(triggerUnit);
            }
            
            else if(currentMap[i * 16 + j].type == 71)
                player = Player(j * LIB::LENGTH_UNIT, i * LIB::LENGTH_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &texturePlayer, LIB::ANIM_PLAYER_NUM_HORIZONTAL, LIB::ANIM_PLAYER_NUM_VERTICAL, 71);
            
            
            
        }
    }
}

void Level::ReadTextureFile()
{
    if (!font.loadFromFile("Sources/karma_future.ttf"))
        return ;
    if (!bgMusic.openFromFile("Sources/Sounds/ingame.ogg"))
    return ;
    if (!winMusic.openFromFile("Sources/Sounds/win.ogg"))
    return ;
    if (!loseMusic.openFromFile("Sources/Sounds/gameover.ogg"))
    return ;
    
    
    if (!texturePlayer.loadFromFile("Sources/player.png"))
        return ;
    if (!textureEnemy.loadFromFile("Sources/enemy.png"))
        return ;
    if (!textureMovableEnemy.loadFromFile("Sources/ghost.png"))
    return ;
    if (!textureBG.loadFromFile("Sources/sable.jpg"))
        return ;
    if (!textureBG2.loadFromFile("Sources/wood.jpg"))
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
    if (!textureObstacle3.loadFromFile("Sources/water.jpg"))
        return ;
    if (!textureCollectable.loadFromFile("Sources/coin.png"))
        return ;
    if (!textureMovable.loadFromFile("Sources/movable.png"))
        return ;
    if (!textureUI.loadFromFile("Sources/coin.png"))
        return ;
}

void Level::UpdateHeartLeft()
{
    heartLeft--;
    if (heartLeft <= 0)
        HeartCollected();
}

void Level::Render(sf::RenderWindow &window)
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
        collectables[i].Render(window);
    }
    for (int i = 0; i < movables.size(); i++)
    {
        movables[i].Render(window);
    }
    for (int i = 0; i < enemies.size(); i++)
    {
        window.draw(enemies[i].real);
        enemies[i].Render(window);
        
        
    }
    for (int i = 0; i < triggers.size(); i++)
    {
        triggers[i].Render(window);
    }
    window.draw(player.real);
    player.Render(window);
    
    
    uiLife.Render(window);
    uiWeapon.Render(window);
    
    window.draw(title);
    window.draw(textLife);
    window.draw(textWeapon);
    
}


void Level::Update(const float deltaTime)
{
    player.Update(deltaTime, obstacles, collectables, movables, triggers);
    
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].Update(deltaTime, obstacles, collectables, movables, triggers, &player);
    }
    
    /* equal to movable class's update function */
    for (int i = 0; i < movables.size(); i++)
    {
        // reset to be movable before checking each frame
        movables[i].canMove = true;
        
        /* eventual movable checking */
        if (movables[i].GetCurrentDir() != 0)
        {
            for (int j = 0; j < obstacles.size(); j++)
                if (movables[i].DetectCollision(&obstacles[j]))
                    movables[i].Collision(&obstacles[j]);
            for (int j = 0; j < movables.size(); j++)
                if (movables[i].DetectCollision(&movables[j]) && j != i)
                    movables[i].Collision(&movables[j]);
            for (int j = 0; j < collectables.size(); j++)
                if (movables[i].DetectCollision(&collectables[j]))
                    movables[i].Collision(&collectables[j]);
        }
        
        /* movable enemy update */
        if (movables[i].kind == 42)
        {
            MovableEnemy* p = (MovableEnemy*)&movables[i];
            p->Update(&player);
        }
    }
    
    /* update for collectable class */
    for (int i = 0; i < collectables.size(); i++)
    {
        if (collectables[i].GetIsCollided())
        {
            UpdateHeartLeft();
            collectables.erase(collectables.begin() + i);
        }
    }
    
    /* make door trigger active if the key is got */
    for (int i = 0; i < triggers.size(); i++)
    {
        // door
        if (triggers[i].GetTrigger() && triggers[i].kind == 62)
        {
            for (int j = 0; j< triggers.size(); j++)
            {
                if(triggers[j].kind == 61 && !triggers[j].GetIsTriggerActive())
                {
                    triggers[j].SetIsTriggerActive(true);
                    CleanLevelEnemy();
                }
            }
        }
        // door
        if (triggers[i].GetTrigger() && triggers[i].kind == 61)
        {
            if (currentLevel < MAX_LEVEL)
            {
                currentLevel++;
                InitLevel(currentLevel);
            }
            
        }
    }
    
    /* text update, will be placed in a condition when they change */
    textLife.setString(to_string(player.GetLifePoint()));
    textWeapon.setString(to_string(playerWeapon));
}

// when all the hearts are collected
void Level::HeartCollected()
{
    for(int i = 0; i < triggers.size(); i++)
        if (triggers[i].kind == 62)
        {
            triggers[i].shape.setFillColor(sf::Color::Red);
            triggers[i].SetIsTriggerActive(true);
        }
}

void Level::CleanLevelEnemy()
{
    enemies.clear();
    movables.clear();
}





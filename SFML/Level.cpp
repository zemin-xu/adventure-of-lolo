//
//  Level.cpp
//  SFML
//
//  Created by ZEMIN on 24/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.

// Level state :


#include "LIB.hpp"

Level::Level()
{
    
}

Level::Level(int _currentLevel)
{
    ReadTextureFile();
    InitLevel(_currentLevel);
    playerLife = 2;
    playerProjectileNum = 0;
    isEnemyAwake = false;
    hasWin = false;
    hasLost = false;
}

void Level::ReadTextureFile()
{
    if (!font.loadFromFile("Sources/karma_future.ttf"))
        return ;
    if (!texturePlayer.loadFromFile("Sources/player.png"))
        return ;
    if (!textureEnemyStaticSleep.loadFromFile("Sources/enemy_static_sleep.png"))
        return ;
    if (!textureEnemyStaticAwake.loadFromFile("Sources/enemy_static_awake.png"))
        return ;
    if (!textureEgg.loadFromFile("Sources/mushroom3.png"))
        return ;
    if (!textureObstacleEnemy.loadFromFile("Sources/ghost.png"))
        return ;
    if (!textureChasingEnemy.loadFromFile("Sources/enemy.png"))
        return ;
    if (!textureSimpleEnemy.loadFromFile("Sources/panda.png"))
    return ;
    if (!textureBackground.loadFromFile("Sources/background.png"))
        return ;
    if (!textureBG2.loadFromFile("Sources/bridge.png"))
        return ;
    if (!textureClosedKeyBox.loadFromFile("Sources/keybox_closed.png"))
        return ;
    if (!textureMiKeyBox.loadFromFile("Sources/mi_keybox.png"))
        return ;
    if (!textureOpenKeyBox.loadFromFile("Sources/fin_keybox.png"))
        return ;
    if (!textureOuterWall.loadFromFile("Sources/wall.png"))
        return ;
    if (!textureClosedDoor.loadFromFile("Sources/door_closed.png"))
        return ;
    if (!textureOpenDoor.loadFromFile("Sources/door_open.png"))
        return ;
    if (!textureObstacle1.loadFromFile("Sources/tree1.png"))
        return ;
    if (!textureObstacle2.loadFromFile("Sources/bad_flower.png"))
        return ;
    if (!textureObstacle3.loadFromFile("Sources/head.png"))
        return ;
    if (!textureCollectable.loadFromFile("Sources/mushroom1.png"))
        return ;
    if (!textureCollectable2.loadFromFile("Sources/mushroom2.png"))
        return ;
    if (!textureMovable.loadFromFile("Sources/movable.png"))
        return ;
    if (!textureUI.loadFromFile("Sources/mushroom2.png"))
        return ;
    if (!textureWin.loadFromFile("Sources/win_image.png"))
        return ;
    if (!textureLose.loadFromFile("Sources/lose_image.png"))
        return ;
}

// 16 and 12 here is the length and height of map
void Level::UpdateCurrentMap()
{
    currentMap.clear();
    
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
            else if (currentLevel == 3)
                a.type = level3[i][j];
            else if (currentLevel == 4)
            a.type = level4[i][j];
            else if (currentLevel == 5)
            a.type = level5[i][j];
            currentMap.push_back(a);
        }
    }
}

void Level::InitLevel(int level)
{
    currentLevel = level;
    heartLeft = 0;
    playerProjectileNum = 0;
    UpdateCurrentMap();
    isEnemyAwake = false;
    
    /* list clearing */
    if (eggs.size() > 0)
        eggs.clear();
    if (enemies.size() > 0)
        enemies.clear();
    if (collectables.size() > 0)
        collectables.clear();
    if (simpleEnemies.size()>0)
        simpleEnemies.clear();
    background.clear();
    obstacles.clear();
    movables.clear();
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
    
    imageWin.setTexture(textureWin);
    imageLose.setTexture(textureLose);
    
    uiLife = Element(14.0f * LIB::LENGTH_UNIT, 4 * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &texturePlayer, 4, 4, 11);
    uiWeapon = Element(14.0f * LIB::LENGTH_UNIT, 5.5f * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureUI, 1,1, 11);
    
    playerProjectile = Projectile(0,0, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureCollectable2, 1, 1, 32);
    
    // we will create several projectiles for enemies which is invisible when not using
    for (int i = 0; i < LIB::ENEMY_PROJECTILE_NUM; i++)
    {
        Projectile enemyProjectile = Projectile(0,0, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureEgg, 1, 1, 33);
        enemyProjectiles.push_back(enemyProjectile);
    }
    
    // The for-loop to create all the elements according to map
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            // background, a bit different to others, because it is created based on the value of i and j, not the value of 'kind' of the map
            if(j >= 1 && j < 14)
            {
                Element backgroundUnit;
                backgroundUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureBackground, 5, 1, 11);
                background.push_back(backgroundUnit);
                
                if (currentMap[i * 16 + j].type == 12)
                {
                    backgroundUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureBG2, 1, 1, 11);
                    background.push_back(backgroundUnit);
                }
            }
            
            // obstacles, including walls, closed door, etc.
            if (currentMap[i * 16 + j].type / 10 == 2 || currentMap[i * 16 + j].type == 61)
            {
                Element obstacleUnit;
                if (currentMap[i * 16 + j].type == 22)
                    obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureOuterWall, 3, 1, 22);
                else if (currentMap[i * 16 + j].type == 21)
                    obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureObstacle1,1,1, 21);
                else if (currentMap[i * 16 + j].type == 23)
                    obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureObstacle2,1,1, 23);
                else if (currentMap[i * 16 + j].type == 25)
                    obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureObstacle3, 3, 1, 25);
                else if (currentMap[i * 16 + j].type == 26)
                    obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureObstacleEnemy, LIB::ANIM_ENEMY1_NUM_HORIZONTAL, LIB::ANIM_ENEMY1_NUM_VERTICAL, 26);
                else if (currentMap[i * 16 + j].type == 27)
                    obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureEnemyStaticSleep , 1, 1, 27);
                else if (currentMap[i * 16 + j].type == 61)
                    obstacleUnit = Element(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureClosedDoor, 1, 1, 61);
                
                obstacles.push_back(obstacleUnit);
            }
            
            // collectables : hearts and projectiles
            else if (currentMap[i * 16 + j].type / 10 == 3)
            {
                Collectable collectableUnit;
                if (currentMap[i * 16 + j].type == 31)
                {
                    collectableUnit = Collectable(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureCollectable ,1,1, 31);
                    heartLeft++;
                }
                if (currentMap[i * 16 + j].type == 32)
                {
                    collectableUnit = Collectable(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureCollectable2, 1, 1, 32);
                }
                collectables.push_back(collectableUnit);
            }
            
            // movable
            else if(currentMap[i * 16 + j].type == 41)
            {
                Movable movableUnit(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureMovable ,1,1, 41);
                movables.push_back(movableUnit);
            }
            
            // enemy
            else if(currentMap[i * 16 + j].type / 10 == 5)
            {
                if (currentMap[i * 16 + j].type == 51)
                {
                    Enemy enemyUnit(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureChasingEnemy ,LIB::ANIM_ENEMY1_NUM_HORIZONTAL, LIB::ANIM_ENEMY1_NUM_VERTICAL, 51);
                    enemies.push_back(enemyUnit);
                }
                else if (currentMap[i * 16 + j].type == 52)
                {
                    SimpleEnemy enemyUnit(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureSimpleEnemy ,LIB::ANIM_ENEMY1_NUM_HORIZONTAL, LIB::ANIM_ENEMY1_NUM_VERTICAL, 52);
                    simpleEnemies.push_back(enemyUnit);
                }
            }
            
            // trigger, 61 for door, 62 for keybox
            if(currentMap[i * 16 + j].type / 10 == 6)
            {
                Trigger triggerUnit;
                
                if (currentMap[i * 16 + j].type == 61)
                    triggerUnit = Trigger(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureOpenDoor, 1, 1, 61);
                
                else if (currentMap[i * 16 + j].type == 62)
                {
                    triggerUnit = Trigger(j * LIB::LENGTH_UNIT, i * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureClosedKeyBox, 1, 1, 62);
                    triggerUnit.SetIsTriggerActive(false);
                }
                triggers.push_back(triggerUnit);
            }
            
            // player
            else if(currentMap[i * 16 + j].type == 71)
                player = Player(j * LIB::LENGTH_UNIT, i * LIB::LENGTH_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &texturePlayer, LIB::ANIM_PLAYER_NUM_HORIZONTAL, LIB::ANIM_PLAYER_NUM_VERTICAL, 71);
        }
    }
}

void Level::UpdateHeartLeft()
{
    heartLeft--;
    if (heartLeft <= 0)
        HeartCollected();
}

void Level::LoseLife()
{
    if(playerLife >= 1)
    {
        playerLife--;
        InitLevel(currentLevel);
    }
    else
        GameOver();
}

void Level::GameOver()
{
    hasLost = true;
}

void Level::GameWin()
{
    hasWin = true;
}

void Level::RestartGame()
{
    if(!hasLost && playerLife >= 1)
        playerLife--;
    else
    {
        playerLife = 2;
        hasLost = false;
    }
    InitLevel(currentLevel);
}

void Level::AwakenEnemy()
{
    for(int i = 0; i < obstacles.size(); i++)
    {
        if (obstacles[i].kind == 27)
        {
            StaticEnemy staticEnemyUnit(obstacles[i].centerX - LIB::LENGTH_UNIT / 2, obstacles[i].centerY - LIB::LENGTH_UNIT / 2, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureEnemyStaticAwake, LIB::ANIM_ENEMY1_NUM_HORIZONTAL, LIB::ANIM_ENEMY1_NUM_VERTICAL, 28);
            obstacles.push_back(staticEnemyUnit);
            obstacles.erase(obstacles.begin() + i);
        }
    }
}

void Level::UpdatePlayerProjectileNum()
{
    playerProjectileNum++;
}

// when all the hearts are collected
void Level::HeartCollected()
{
    for(int i = 0; i < triggers.size(); i++)
    {
        if (triggers[i].kind == 62)
        {
            triggers[i].shape.setTexture(&textureMiKeyBox);
            triggers[i].SetIsTriggerActive(true);
        }
    }
}

void Level::CleanLevelEnemy()
{
    enemies.clear();
    movables.clear();
    eggs.clear();
    simpleEnemies.clear();
    for (int i = 0; i < obstacles.size(); i++)
    {
        if (obstacles[i].kind == 26 || obstacles[i].kind == 28)
            obstacles.erase(obstacles.begin() + i);
    }
}


void Level::Update(const float deltaTime)
{
    player.Update(deltaTime, obstacles, collectables, movables, triggers, eggs, enemies, *this);
    
    playerProjectile.Update(deltaTime, obstacles, enemies, eggs, *this);
    
    for(int i = 0; i < enemyProjectiles.size(); i++)
    {
        enemyProjectiles[i].Update(deltaTime, obstacles, enemies, eggs, *this);
    }
    
    // check the moment to awaken the enemies in sleep
    if (heartLeft <= 1)
    {
        if (!isEnemyAwake)
        {
            AwakenEnemy();
            isEnemyAwake = true;
        }
        for (int i = 0; i < simpleEnemies.size(); i++)
        {
            simpleEnemies[i].Update(deltaTime, obstacles, collectables, movables, triggers, eggs, enemies, &player, *this);
        }
    }

    // update of enemies
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].Update(deltaTime, obstacles, collectables, movables, triggers, eggs, enemies, &player, *this);
    }
    
    // update of obstacle ememies and static enemies
    for (int i = 0; i < obstacles.size(); i++)
    {
        if (obstacles[i].kind == 26)
        {
            ObstacleEnemy* p = (ObstacleEnemy*)&obstacles[i];
            p->Update(&player, deltaTime);
        }
        else if (obstacles[i].kind == 28)
        {
            StaticEnemy* p = (StaticEnemy*)&obstacles[i];
            p->Update(&player, deltaTime, *this);
        }
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
    }
    
    // update for the obstacle enemies in egg state
    for (int i = 0; i < eggs.size(); i++)
    {
        // reset to be movable before checking each frame
        eggs[i].canMove = true;
        eggs[i].Update(&player, *this, deltaTime);
        if (eggs[i].GetEggTime() < 0)
        {
            if (eggs[i].GetEnemyKind() == 26)
            {
                Element obstacleUnit = Element(eggs[i].centerX - 0.5f * LIB::LENGTH_UNIT, eggs[i].centerY -  0.5f * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureObstacleEnemy, LIB::ANIM_ENEMY1_NUM_HORIZONTAL, LIB::ANIM_ENEMY1_NUM_VERTICAL, eggs[i].GetEnemyKind());
                obstacles.push_back(obstacleUnit);
            }
            else if (eggs[i].GetEnemyKind() == 27)
            {
                Element obstacleUnit = Element(eggs[i].centerX - 0.5f * LIB::LENGTH_UNIT, eggs[i].centerY -  0.5f * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureEnemyStaticSleep, 1, 1, eggs[i].GetEnemyKind());
                obstacles.push_back(obstacleUnit);
            }
            else if (eggs[i].GetEnemyKind() == 28)
            {
                StaticEnemy obstacleUnit = StaticEnemy(eggs[i].centerX - 0.5f * LIB::LENGTH_UNIT, eggs[i].centerY -  0.5f * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureEnemyStaticAwake, LIB::ANIM_ENEMY1_NUM_HORIZONTAL, LIB::ANIM_ENEMY1_NUM_VERTICAL, eggs[i].GetEnemyKind());
                obstacles.push_back(obstacleUnit);
            }
            else if (eggs[i].GetEnemyKind() == 51)
            {
                
                Enemy enemyUnit = Enemy(eggs[i].centerX - 0.5f * LIB::LENGTH_UNIT, eggs[i].centerY -  0.5f * LIB::HEIGHT_UNIT, LIB::LENGTH_UNIT, LIB::HEIGHT_UNIT, &textureChasingEnemy, LIB::ANIM_ENEMY1_NUM_HORIZONTAL, LIB::ANIM_ENEMY1_NUM_VERTICAL, eggs[i].GetEnemyKind());
                enemies.push_back(enemyUnit);
            }
            eggs.erase(eggs.begin() + i);
        }
        
        /* Possible movable checking, it happens when we push the eggs and it will perhaps collide with other obstacles */
             if (eggs[i].GetCurrentDir() != 0)
             {
                 for (int j = 0; j < obstacles.size(); j++)
                     if (eggs[i].DetectCollision(&obstacles[j]))
                         eggs[i].Collision(&obstacles[j]);
                 for (int j = 0; j < eggs.size(); j++)
                     if (eggs[i].DetectCollision(&eggs[j]) && j != i)
                         eggs[i].Collision(&eggs[j]);
                 for (int j = 0; j < collectables.size(); j++)
                     if (eggs[i].DetectCollision(&collectables[j]))
                         eggs[i].Collision(&collectables[j]);
             }
         }
        
        /* update for collectable class */
        for (int i = 0; i < collectables.size(); i++)
        {
            if (collectables[i].GetIsCollided())
            {
                if (collectables[i].kind == 31)
                {
                    UpdateHeartLeft();
                    collectables.erase(collectables.begin() + i);
                }
                else if (collectables[i].kind == 32)
                {
                    UpdatePlayerProjectileNum();
                    collectables.erase(collectables.begin() + i);
                }
            }
        }
        
        /* make door trigger active if the key is got */
        for (int i = 0; i < triggers.size(); i++)
        {
            // keybox
            if (triggers[i].GetTrigger() && triggers[i].kind == 62)
            {
                CleanLevelEnemy();
                // erase closed door
                for (int j = 0; j < obstacles.size(); j++)
                {
                    if(obstacles[j].kind == 61)
                        obstacles.erase(obstacles.begin() + j);
                }
                // show open door
                for (int j = 0; j < triggers.size(); j++)
                {
                    if(triggers[j].kind == 61)
                    {
                        triggers[j].SetIsTriggerActive(true);
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
                else
                    GameWin();
            }
        }

    /* text update */
    textLife.setString(to_string(playerLife));
    textWeapon.setString(to_string(playerProjectileNum));
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
        enemies[i].Render(window);
    }
    for (int i = 0; i < simpleEnemies.size(); i++)
    {
        simpleEnemies[i].Render(window);
    }
    
    for (int i = 0; i < eggs.size(); i++)
    {
        eggs[i].Render(window);
    }
    for (int i = 0; i < triggers.size(); i++)
    {
        if (triggers[i].GetIsTriggerActive())
            triggers[i].Render(window);
        if (triggers[i].kind == 62)
            triggers[i].Render(window);
    }
    for(int i = 0; i < enemyProjectiles.size(); i++)
    {
        if (enemyProjectiles[i].GetIsUsing())
            enemyProjectiles[i].Render(window);
    }
    
    if (playerProjectile.GetIsUsing())
        playerProjectile.Render(window);
    
    player.Render(window);
    
    uiLife.Render(window);
    uiWeapon.Render(window);
    
    window.draw(title);
    window.draw(textLife);
    window.draw(textWeapon);
    
    if (hasWin)
        window.draw(imageWin);
    if (hasLost)
        window.draw(imageLose);
}

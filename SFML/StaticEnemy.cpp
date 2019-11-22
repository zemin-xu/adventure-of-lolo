//
//  StaticEnemy.cpp
//  SFML
//
//  Created by ZEMIN on 22/11/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"


StaticEnemy::StaticEnemy()
{
    fireDelay = 1.0f;
    time = 0;
}

StaticEnemy::StaticEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind) : ObstacleEnemy(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{
    fireDelay = 1.0f;
    time = 0;
}

void StaticEnemy::Update(Element *player, const float deltaTime, Level & level)
{
    ObstacleEnemy::Update(player, deltaTime);
    //time += deltaTime;
    
    //if (time > fireDelay)
    //{
        if (abs(player->centerX - centerX) < (LIB::LENGTH_UNIT / 2) ||
        abs(player->centerY - centerY) < (LIB::HEIGHT_UNIT / 2))
        {
            Fire(level);
            //time = 0;
        }
   // }
    
}

void StaticEnemy::Fire(Level& level)
{
    for (int i = 0; i < level.enemyProjectiles.size(); i++)
    {
        if (!level.enemyProjectiles[i].GetIsUsing())
        {
            level.enemyProjectiles[i].SetIsUsing(true);
            level.enemyProjectiles[i].SetCurrentDir(GetCurrentDir());
            level.enemyProjectiles[i].real.setPosition(centerX, centerY);
            level.enemyProjectiles[i].canMove = true;
        }
    }
}

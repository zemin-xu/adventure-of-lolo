//
//  MovableEnemy.cpp
//  SFML
//
//  Created by ZEMIN on 25/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

MovableEnemy::MovableEnemy()
{
    
}

MovableEnemy::MovableEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind) : Movable(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{
    isInEgg = false;
}

void MovableEnemy::TurnTowardsPlayer(Element *player)
{
    if (centerY - player->centerY < 0)
        SetCurrentDir(1);
    else if (centerX - player->centerX > 0)
        SetCurrentDir(3);
    else if (centerX - player->centerX < 0)
        SetCurrentDir(4);
}

void MovableEnemy::Update(Element *player)
{
    TurnTowardsPlayer(player);
    UpdateIdleAnimation(1, 4, 4, 4, 2, 4, 3, 4);
}

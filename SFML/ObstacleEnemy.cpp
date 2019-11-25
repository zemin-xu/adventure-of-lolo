//
//  ObstacleEnemy.cpp
//  SFML
//
//  Created by ZEMIN on 27/10/2019.
//  Copyright © 2019 ZEMIN. All rights reserved.
//

#include "LIB.hpp"

ObstacleEnemy::ObstacleEnemy()
{

}

ObstacleEnemy::ObstacleEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int kind) : Element(x, y, length, height, texture, numHorizontal, numVertical, kind)
{

}

void ObstacleEnemy::TurnTowardsPlayer(Element *player)
{
    if (centerY - player->centerY < 0)
        SetCurrentDir(1);
    else if (centerX - player->centerX > 0)
        SetCurrentDir(3);
    else if (centerX - player->centerX < 0)
        SetCurrentDir(4);
}

void ObstacleEnemy::Update(Element *player, const float deltaTime)
{
    TurnTowardsPlayer(player);
    UpdateIdleAnimation(1, 4, 4, 4, 2, 4, 3, 4);
}

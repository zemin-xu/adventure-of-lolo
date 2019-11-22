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
    eggTime = 5.0f;
    enemyKind = 0;
}

MovableEnemy::MovableEnemy(int x, int y, int length, int height, sf::Texture *texture, int numHorizontal, int numVertical, int _kind, int _enemyKind) : Movable(x, y, length, height, texture, numHorizontal, numVertical, _kind)
{
    eggTime = 5.0f;
    enemyKind = _enemyKind;
}

void MovableEnemy::Update(Element *player, Level &level, const float deltaTime)
{
    eggTime-=deltaTime;
}
